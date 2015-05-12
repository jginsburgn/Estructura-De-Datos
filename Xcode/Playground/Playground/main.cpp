//
//  main.cpp
//  Playground
//
//  Created by Jonathan Ginsburg on 2/17/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include <vector>

class a{
private:
    std::string * info = new std::string();
public:
    
    a() {
        std::cout << "Calling constructor of a" << std::endl;
    };
    ~a() {
        std::cout << "Calling destructor of a" << std::endl;
        delete info;
    };
    a(a& source) {
        std::cout << "Calling copy method of a" << std::endl;
        *info = source.getInfo();
    };
    
    std::string getInfo() const {return *info;};
    void setInfo(std::string newInfo) {*info = newInfo;};
    
};

int main(int argc, const char * argv[]) {
    std::vector<a *> * as = new std::vector<a *>();
    a * first = new a();
    as->push_back(first);
    delete as;
    delete first;
    char * address = (char*)0x7fff5fbff838;
    while (true) {
        std::cout << *address;
        address = address+1;
    }
    return 0;
}
