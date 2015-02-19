//
//  main.cpp
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include "Vehicle.h"
#include "Car.h"
#include "Van.h"
#include "Motorcycle.h"
#include "Sale.h"
#include "Customer.h"
#define menuOptions 5

Customer* customers = new Customer[100];
Sale* sales = new Sale[100];
int lastCustomer = 0;
int lastSale = 0;

bool customerExists(Customer customer){
    for (int i = 0; i < lastCustomer; ++i) {
        if (customers[i].getIdNumber() == customer.getIdNumber()) {
            return true;
        }
    }
    return false;
}

void showAllCustomers(){
    Helper::print("Showing all customers:");
    for (int i = 0; i < lastCustomer; ++i) {
        Helper::print("Customer number " + Helper::intToString(i + 1));
        customers[i].print();
    }
    Helper::print("Operation finished.");
}

Customer chooseCustomer(){
    showAllCustomers();
    return customers[Helper::read<int>("Which customer is buying?") - 1];
}

void addNewSale(){
    Helper::print("Adding New Sale:");
    
    Sale sale;
    
    std::string options[3];
    options[0] = "1 for car.";
    options[1] = "2 for van.";
    options[2] = "3 for motorcycle.";

            Car* car = new Car(0, "", 0, 0);
            sale = Sale(0, car, chooseCustomer());


    Helper::print("Operation finished");
}

void addNewCustomer() {
    Helper::print("Adding a new customer:");
    Customer customer = Customer(Helper::read<std::string>("Enter the first name:"), Helper::read<std::string>("Enter the last name:"), Helper::read<int>("Enter de ID number:"));
    if (customerExists(customer)) {
        Helper::print("Customer Already Exists. Not Added.");
    }
    else{
        customers[lastCustomer++] = customer;
        Helper::print("Customer Added Correctly.");
    }
    Helper::print("Operation finished.");
}

void printAllSales() {
    
}

void searchCustomerTransactions(){
    
}

int main(int argc, const char * argv[]) {
    
    std::string options[menuOptions];
    options[0] = "1 for new customer.";
    options[1] = "2 for new sale.";
    options[2] = "3 for new printing all sales in descending order according to price.";
    options[3] = "4 for searching for a customer transactions.";
    options[4] = "5 for showing all customers.";
    
    while (true) {
        switch (Helper::menu("main", options, menuOptions)) {
            case 1:
                addNewCustomer();
                break;
            case 2:
                addNewSale();
                break;
            case 3:
                printAllSales();
                break;
            case 4:
                searchCustomerTransactions();
                break;
            case 5:
                showAllCustomers();
                break;
            default:
                Helper::print("Option is not valid. Try again.");
                break;
        }
    }
    return 0;
}
