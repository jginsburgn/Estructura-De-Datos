//
//  main.cpp
//  Tarea6.STL.E1
//
//  Created by Jonathan Ginsburg on 4/28/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Port.h"
#include "Helper.h"

int main(int argc, const char * argv[]) {
    Port port("My port");
    port.setMaximumArea(Helper::read<int>("Enter the maximum area of stacks in the port:"));
    port.setMaximumStackedContainers(Helper::read<int>("Enter the maximum number of stacked containers per pile:"));
ui:
    Helper::print("0 for quitting.");
    Helper::print("1 for adding container");
    Helper::print("2 for showing port status");
    int input = Helper::read<int>("Enter your choice:");
    if (input == 0) {
        return 0;
    }
    else if (input == 1){
        Container newContainer;
        newContainer.setBrand(Helper::readLine("Enter the brand of the container:"));
        newContainer.setNumber(Helper::read<int>("Enter the number of the container:"));
        askagain:
        Helper::print("1 for adding a product to the container.");
        Helper::print("0 for terminating addition of products and receiving the current container in the port.");
        int subinput1 = Helper::read<int>("Enter your choice:");
        if (subinput1 == 1) {
            Product product;
            product.setName(Helper::readLine("Enter the name of the product:"));
            product.setQuantity(Helper::read<int>("Enter the quantity of units of product:"));
            product.setUnitPrice(Helper::read<int>("Enter the unit price of product:"));
            newContainer.addProduct(product);
            goto askagain;
        }
        else if (subinput1 == 0){
            try {
                port.addContainer(newContainer);
            } catch (const char * e) {
                Helper::print(e);
            }
            goto ui;
            
        }
        else goto askagain;
    }
    else if (input == 2){
        std::cout << port << std::endl;
        goto ui;
    }
    else{
        goto ui;
    }
}
