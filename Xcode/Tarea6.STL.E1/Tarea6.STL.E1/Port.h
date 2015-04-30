//
//  Port.h
//  Tarea6.STL.E1
//
//  Created by Jonathan Ginsburg on 4/30/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Tarea6_STL_E1_Port_h
#define Tarea6_STL_E1_Port_h

#include "Container.h"
#include <stack>

class Port{
    
private:
    
    int maximumArea = 0;
    int maximumStackedContainers = 0;
    std::string name = "No name";
    std::vector<std::stack<Container>> stacks;
    
public:
    
    Port() {}
    Port(std::string newName){
        setName(newName);
    }
    
    int getMaximumArea() const{
        return maximumArea;
    }
    
    int getMaximumStackedContainers() const {
        return maximumStackedContainers;
    }
    
    std::string getName() const {
        return name;
    }
    
    void setName(std::string newName) {
        name = newName;
    }
    
    void setMaximumArea(int newMaximumArea) {
        for (int i = 0; i < maximumArea; ++i) {
            std::stack<Container> newStack;
            stacks.push_back(newStack);
        }
        maximumArea = newMaximumArea;
    }
    
    void setMaximumStackedContainers(int newMaximumStackedContainers) {
        maximumStackedContainers = newMaximumStackedContainers;
    }
    
    std::stack<Container> getStackAt(int position) const{
        return stacks[position];
    }
    
    int getPriceOfStack(int stackNumber) const{
        int price = 0;
        std::stack<Container> stack = getStackAt(stackNumber);
        std::stack<Container> aux;
        for (int i = 0; i < stack.size(); ++i) {
            Container container = stack.top();
            price += container.getPrice();
            aux.push(container);
            stack.pop();
        }
//        for (int i = 0; i < aux.size(); ++i) {
//            Container container = aux.top();
//            stack.push(container);
//            
//        }
        return price;
    }
    
    int getPrice() const{
        int price = 0;
        for (int i = 0; i < stacks.size(); ++i) {
            price += getPriceOfStack(i);
        }
        return price;
    }
    
    void addContainer(Container container){
        for (int i = 0; i < maximumArea; ++i) {
            if (stacks.size() == 0){
                std::stack<Container> newStack;
                newStack.push(container);
                stacks.push_back(newStack);
                return;
            }
            else if (stacks.size() <= i){
                std::stack<Container> newStack;
                newStack.push(container);
                stacks.push_back(newStack);
                return;
            }
            else if (stacks[i].size() == 0) {
                stacks[i].push(container);
                return;
            }
            else if (stacks[i].size() < maximumStackedContainers){
                stacks[i].push(container);
                return;
            }
        }
        throw "No space to add container...";
    }
    
    friend std::ostream & operator << (std::ostream & os, const Port & port){
        int totalPrice = 0;
        os << "Printing port " << port.getName() << ":\n";
        for (int i = 0; i < port.stacks.size(); ++i) {
            int price = 0;
            os << "\t" << "Printing stack number " << i + 1 << ":\n";
                std::stack<Container> stack = port.getStackAt(i);
                while (!stack.empty()) {
                    os << "\t\t" << stack.top();
                    price += stack.top().getPrice();
                    stack.pop();
                }
            os << "\tPrice of stack: " << price << std::endl;
            totalPrice += price;
        }
        os << "Price of port: " << totalPrice << std::endl;
        return os;
    }
    
};

#endif
