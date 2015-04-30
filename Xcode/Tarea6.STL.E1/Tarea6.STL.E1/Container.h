//
//  Container.h
//  Tarea6.STL.E1
//
//  Created by Jonathan Ginsburg on 4/30/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Tarea6_STL_E1_Container_h
#define Tarea6_STL_E1_Container_h

#include "Product.h"
#include <vector>
#include "Helper.h"

class Container{
    
private:
    
    int number = 0;
    std::string brand = "No brand";
    std::vector<Product> products;
    
public:
    
    Container() {}
    Container(std::string newBrand, int newNumber){
        setBrand(newBrand);
        setNumber(newNumber);
    }
    
    std::string getBrand() const{
        return brand;
    }
    
    int getNumber() const {
        return number;
    }
    
    void setBrand(std::string newBrand) {
        brand = newBrand;
    }
    
    void setNumber(int newNumber) {
        number = newNumber;
    }
    
    Product getProductAt(int position) const {
        return products[position];
    }
    
    void addProduct(Product newProduct) {
        products.push_back(newProduct);
    }
    
    int getProducts() const{
        return (int)products.size();
    }
    
    void removeProductAt(int position){
        products.erase(products.begin() + position);
    }
    
    int getPrice() const{
        int price = 0;
        for (auto p : products) {
            price += p.getUnitPrice() * p.getQuantity();
        }
        return price;
    }
    
    friend std::ostream & operator << (std::ostream & os, const Container & container){
        os << "Container number " << Helper::intToString(container.getNumber()) << " of brand " << container.getBrand() << ":" << std::endl;
        for (int i = 0; i < container.getProducts(); ++i) {
            os << "\t\t\t" << container.getProductAt(i) << std::endl;
        }
        os << "\t\tPrice of container: " << container.getPrice() << std::endl;
        return os;
    }
};

#endif
