//
//  FamilyMember.cpp
//  Tarea5.BinaryTrees.E4
//
//  Created by Jonathan Ginsburg on 4/21/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "FamilyMember.h"

//Default Constructors
FamilyMember::FamilyMember(){
    *name = "Unknown";
    *lastName = "Unknown";
}

//Destructors
FamilyMember::~FamilyMember(){
    if (father) {
        father->removeChild(this);
    }
    if (mother) {
        mother->removeChild(this);
    }
    for (int i = 0; i < children->size(); ++i) {
        (*children)[i]->removeParent(this);
    }
    delete name;
    delete lastName;
    delete birthday;
    delete deathday;
    delete children;
}

//Additional Constructors
FamilyMember::FamilyMember(std::string newName, std::string newLastName){
    *name = newName;
    *lastName = newLastName;
}

//Adding children
bool FamilyMember::insertChild(FamilyMember * child){
    if (gender == GUnknown) {
        std::cout << "Please set the gender of " << this->getName() << " " << this->getLastName() << std::endl;
        Helper::print("1 for male.");
        Helper::print("2 for female.");
        int input = Helper::read<int>("Enter your choice:");
        if (input == 1) {
            gender = GMale;
        }
        else if (input == 2){
            gender = GFemale;
        }
        else{
            Helper::print("Invalid choice.");
            return this->insertChild(child);
        }
    }
    if (gender == GMale) {
        if (child->getFather() == this) {
        }
        else {
            child->setFather(this);
        }
    }
    else if (gender == GFemale) {
        if (child->getMother() == this) {
        }
        else {
            child->setMother(this);
        }
    }
    else{
        if (child->getFather()) {
            if (child->getMother() == this) {
            }
            else {
                child->setMother(this);
            }
        }
        else {
            if (child->getFather() == this) {
            }
            else {
                child->setFather(this);
            }
        }
    }
    bool alreadyInList = false;
    for (int i = 0; i < children->size(); ++i) {
        if ((*children)[i] == child) {
            alreadyInList = true;
            break;
        }
    }
    if (!alreadyInList) children->push_back(child);
    return true;
}

//Removing Children
bool FamilyMember::removeChild(FamilyMember * child){
    for (int i = 0; i < children->size(); ++i) {
        if ((*children)[i] == child) {
            children->erase(children->begin()-1+i);
            child->removeParent(this);
        }
    }
    return false;
}

//Removing Parent
bool FamilyMember::removeParent(FamilyMember * parent){
    if (this->getFather() == parent) {
        this->setFather(nullptr);
    }
    if (this->getMother() == parent) {
        this->setMother(nullptr);
    }
    return true;
}

//Showing information
void FamilyMember::showChildren() const{
    std::cout << "Showing children of " << getName() << " " << getLastName() << ":" << std::endl;
    for (int i = 0; i < children->size(); ++i) {
        std::cout << *(*children)[i] << std::endl;
    }
    std::cout << "Done showing children of " << getName() << " " << getLastName() << "." << std::endl;
}

void FamilyMember::showAscendents() const{
    std::cout << "Showing ascendents of " << getName() << " " << getLastName() << ":" << std::endl;
    if (mother || father) {
        if (mother && father) {
            std::cout << "Father of " << getName() << " " << getLastName() << ":" << std::endl;
            std::cout << *father << std::endl;
            std::cout << "Mother of " << getName() << " " << getLastName() << ":" << std::endl;
            std::cout << *mother << std::endl;
            father->showAscendents();
            mother->showAscendents();
        }
        else if (mother){
            std::cout << "Mother of " << getName() << " " << getLastName() << ":" << std::endl;
            std::cout << *mother << std::endl;
            mother->showAscendents();
        }
        else{
            std::cout << "Father of " << getName() << " " << getLastName() << ":" << std::endl;
            std::cout << *father << std::endl;
            father->showAscendents();
        }
    }
    else std::cout << "No ascendents known." << std::endl;
    std::cout << "Done showing ascendents of " << getName() << " " << getLastName() << "." << std::endl;
}

void FamilyMember::showDescendents() const{
    std::cout << "Showing descendents of " << getName() << " " << getLastName() << ":" << std::endl;
    if (children->size() > 0) {
        for (int i = 0; i < children->size(); ++i) {
            std::cout << "Child number " << Helper::intToString(i+1) << " of " << getName() << " " << getLastName() << ":" << std::endl;
            std::cout << *(*children)[i] << std::endl;
            (*children)[i]->showDescendents();
        }
    }
    else std::cout << "No descendents known." << std::endl;
    std::cout << "Done showing descendents of " << getName() << " " << getLastName() << "." << std::endl;
}

void FamilyMember::showBrothers() const{
    std::cout << "Showing brothers of " << getName() << " " << getLastName() << ":" << std::endl;
    if (father || mother) {
        if (father && mother) {
            father->parentShowBrothersOf(this);
            mother->parentShowBrothersOf(this);
        }
        else if (mother){
            mother->parentShowBrothersOf(this);
        }
        else{
            father->parentShowBrothersOf(this);
        }
    }
    else std::cout << "No descendents known." << std::endl;
    std::cout << "Done showing brothers of " << getName() << " " << getLastName() << "." << std::endl;
}

void FamilyMember::parentShowBrothersOf(const FamilyMember * thisChild) const{
    std::string side = "";
    if (gender == GMale) {
        side = "howing paternal brothers of ";
    }
    else if (gender == GFemale){
        side = "howing maternal brothers of ";
    }
    else{
        side = "howing brothers of ";
    }
    std::cout << "S" << side << thisChild->getName() << " " << thisChild->getLastName() << ":" << std::endl;
    for (int i = 0; i < children->size(); ++i) {
        if (thisChild == (*children)[i]) {
            continue;
        }
        std::cout << *(*children)[i] << std::endl;
    }
    std::cout << "Done s" << side << thisChild->getName() << " " << thisChild->getLastName() << "." << std::endl;
}

void FamilyMember::showCousins() const{
    std::cout << "Showing cousins of " << getName() << " " << getLastName() << ":" << std::endl;
    if (mother || father) {
        if (mother && father) {
            father->showNephews();
            mother->showNephews();
        }
        else if (mother){
            mother->showNephews();
        }
        else{
            father->showNephews();
        }
    }
    else std::cout << "No cousins known." << std::endl;
    std::cout << "Done showing cousins of " << getName() << " " << getLastName() << "." << std::endl;
}

void FamilyMember::showNephews() const{
    if (mother || father) {
        if (mother && father) {
            father->showGrandchildrenExceptFor(this);
            mother->showGrandchildrenExceptFor(this);
        }
        else if (mother){
            mother->showGrandchildrenExceptFor(this);
        }
        else{
            father->showGrandchildrenExceptFor(this);
        }
    }
}

void FamilyMember::showGrandchildrenExceptFor(const FamilyMember * thisSonsChildren) const{
    for (int i = 0; i < children->size(); ++i) {
        if ((*children)[i] == thisSonsChildren) {
            continue;
        }
        (*children)[i]->showChildren();
    }
}

//Other methods
bool FamilyMember::isAlive() const{
    if (this->getLivingStatus() == LSAlive) {
        return true;
    }
    return false;
}

bool FamilyMember::diedBeforeDate(Date date) const{
    if (date < this->getDeathday()) {
        return true;
    }
    return false;
}

std::ostream & operator<<(std::ostream & osd, FamilyMember & fm){
    osd << "\n" << "---------*****---------" << std::endl;;
    osd << "Name: " << fm.getName() << std::endl;
    osd << "Last Name: " << fm.getLastName() << std::endl;
    if (!fm.getBirthday().isEmpty()) {
        osd << "Birthday: " << fm.getBirthday() << std::endl;
    }
    if (!fm.getDeathday().isEmpty()) {
        osd << "Deathday: " << fm.getDeathday() << std::endl;
    }
    std::string livings = "";
    if (fm.getLivingStatus() == LSAlive) {
        livings = "Alive";
    }
    else if (fm.getLivingStatus() == LSDeceased){
        livings = "Deceased";
    }
    else if (fm.getLivingStatus() == LSUnknown){
        livings = "Unknown";
    }
    osd << "Living status: " << livings << std::endl;
    if (fm.getFather()) {
        osd << "Father's full name: " << fm.getFather()->getName() << " " << fm.getFather()->getLastName() << std::endl;
    }
    if (fm.getMother()) {
        osd << "Mother's full name: " << fm.getMother()->getName() << " " << fm.getMother()->getLastName() << std::endl;
    }
    if (fm.getChildren()->size() != 0) {
        osd << "Children:\n" << "::::::::::::::::::::" << std::endl;
        for (int i = 0; i < fm.getChildren()->size(); ++i) {
            osd << "Child number " << i + 1 << "'s full name: " << (*fm.getChildren())[i]->getName() << " " << (*fm.getChildren())[i]->getLastName() << std::endl;
        }
        osd << "::::::::::::::::::::" << std::endl;
    }
    return osd;
}

















