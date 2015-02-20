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
#include "GenericSort.h"
#define menuOptions 5

Customer* customers = new Customer[100];
Sale* sales = new Sale[100];
int lastCustomer = 0;
int lastSale = 0;

void showAllCustomers(){
    Helper::print("Showing all customers:");
    for (int i = 0; i < lastCustomer; ++i) {
        Helper::print("Customer number " + Helper::intToString(i + 1) + ":");
        customers[i].print();
    }
    Helper::print("Operation finished.");
}

Customer chooseCustomer(){
    showAllCustomers();
    return customers[Helper::read<int>("Which customer is buying? (enter the number of the customer)") - 1];
}

void addNewCarSale(){
    Car* car = new Car(Helper::read<int>("What is the code of the car?"), Helper::read<std::string>("What is the brand of the car?"), Helper::read<int>("What is the model of the car?"), Helper::read<int>("What is the mileage of the car?"));
    Sale sale = Sale(Helper::read<int>("What is the price of the car?"), car, chooseCustomer());
    sales[lastSale++] = sale;
}

void addNewVanSale() {
    Van* van = new Van(Helper::read<int>("What is the code of the van?"), Helper::read<std::string>("What is the brand of the van?"), Helper::read<int>("What is the model of the van?"), Helper::read<int>("What is the mileage of the van?"), Helper::read<std::string>("What is the traction of the van?"));
    Sale sale = Sale(Helper::read<int>("What is the price of the van?"), van, chooseCustomer());
    sales[lastSale++] = sale;
}

void addNewMotorcycleSale(){
    Motorcycle* motorcycle = new Motorcycle(Helper::read<int>("What is the code of the motorcycle?"), Helper::read<std::string>("What is the brand of the motorcycle?"), Helper::read<int>("What is the model of the motorcycle?"), Helper::read<int>("What is the mileage of the motorcycle?"), Helper::read<int>("What is the cylinder capacity of the motorcycle?"));
    Sale sale = Sale(Helper::read<int>("What is the price of the van?"), motorcycle, chooseCustomer());
    sales[lastSale++] = sale;
}

bool customerExists(Customer customer){
    for (int i = 0; i < lastCustomer; ++i) {
        if (customers[i].getIdNumber() == customer.getIdNumber()) {
            return true;
        }
    }
    return false;
}

void addNewSale(){
    Helper::print("Adding New Sale:");
    
    std::string options[3];
    options[0] = "1 for car.";
    options[1] = "2 for van.";
    options[2] = "3 for motorcycle.";

    switch (Helper::menu("adding new sale", options, 3)) {
        case 1:
            addNewCarSale();
            break;
        case 2:
            addNewVanSale();
            break;
        case 3:
            addNewMotorcycleSale();
            break;
        default:
            Helper::print("Option is not valid");
            break;
    }
    
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
    GenericSort<Sale>::insertionSort(sales, lastSale, GenericSort<Sale>::descending);
    Helper::print("Printing all sales:");
    for (int i = 0; i < lastSale; ++i) {
        sales[i].print();
    }
    Helper::print("Operation finished");
}

void searchCustomerTransactions(){
    Helper::print("Searching customer transactions");
    showAllCustomers();
    int customerNumber = Helper::read<int>("What is the number of the customer in question?") - 1;
    for (int i = 0; i < lastSale; ++i) {
        if (sales[i].getCustomer() == customers[customerNumber]) {
            sales[i].print();
        }
    }
    Helper::print("Operation finished");
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
