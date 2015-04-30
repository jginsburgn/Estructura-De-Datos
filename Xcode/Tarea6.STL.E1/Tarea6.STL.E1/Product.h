//
//  Product.h
//  Tarea6.STL.E1
//
//  Created by Jonathan Ginsburg on 4/30/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Tarea6_STL_E1_Product_h
#define Tarea6_STL_E1_Product_h

#include <iostream>
#include <string>

class Product{
    
private:
    
    std::string name = "No name";
    int quantity = 0;
    int unitPrice = 0;
    
public:
    
    Product() {}
    
    Product(std::string newName, int newQuantity, int newUnitPrice) {
        setName(newName);
        setQuantity(newQuantity);
        setUnitPrice(newUnitPrice);
    }
    
    std::string getName() const {
        return name;
    }
    
    int getQuantity() const {
        return quantity;
    }
    
    int getUnitPrice() const {
        return unitPrice;
    }
    
    void setName(std::string newName) {
        name = newName;
    }
    
    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }
    
    void setUnitPrice(int newUnitPrice) {
        unitPrice = newUnitPrice;
    }
    
    friend std::ostream & operator << (std::ostream & os, const Product & product){
        os << product.getName() << "\t" << product.getQuantity() << "\t" << product.getUnitPrice();
        return os;
    }
};

#endif
