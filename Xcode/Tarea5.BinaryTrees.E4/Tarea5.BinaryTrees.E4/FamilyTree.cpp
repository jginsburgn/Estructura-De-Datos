//
//  FamilyTree.cpp
//  Tarea5.BinaryTrees.E4
//
//  Created by Jonathan Ginsburg on 4/21/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "FamilyTree.h"

FamilyTree::~FamilyTree(){
    delete name;
    for (int i = 0; i < familyMembers->size(); ++i) {
        delete (*familyMembers)[i];
    }
    delete familyMembers;
}

//Manipulating Family Members
FamilyMember * FamilyTree::makeMember(){
    FamilyMember * newMember = new FamilyMember();
    newMember->setName(Helper::readLine("Type the new member's name."));
    std::string prompt = "Type ";
    prompt.append(newMember->getName());
    prompt.append("'s last name");
    newMember->setLastName(Helper::readLine(prompt));
    prompt = "Do you have more information on ";
    prompt.append(newMember->getName());
    prompt.append(" ");
    prompt.append(newMember->getLastName());
    prompt.append("? Or do you want to edit his name? (y/n)");
    bool moreInfo = false;
    switch (Helper::read<char>(prompt)) {
        case 'y':
            moreInfo = true;
            break;
        case 'n':
            break;
        default:
            Helper::print("Invalid input.");
            Helper::print("Cancelling operation.");
            delete newMember;
            return nullptr;
            break;
    }
    if (moreInfo) edit(newMember);
    std::cout << "The following member will be added to the tree." << std::endl;
    std::cout << newMember << std::endl;
    switch (Helper::read<char>("Proceed? (y/n)")) {
        case 'y':
            familyMembers->push_back(newMember);
            Helper::print("Member was added.");
            return newMember;
            break;
        case 'n':
            delete newMember;
            Helper::print("Member was not added.");
            return nullptr;
            break;
        default:
            Helper::print("Invalid input.");
            Helper::print("Invalid input.");
            Helper::print("Cancelling operation.");
            delete newMember;
            return nullptr;
            break;
    }
}

void FamilyTree::removeMember(FamilyMember * member){
    
}

//Accessing Family Members
FamilyMember * FamilyTree::getMember(int i) const{
    return (*familyMembers)[i];
}

std::vector<FamilyMember *> FamilyTree::getMembersBasedOnName(std::string name) const{
    std::vector<FamilyMember *> matches;
    for (int i = 0; i < familyMembers->size(); ++i) {
        if ((*familyMembers)[i]->getName() == name) {
            matches.push_back((*familyMembers)[i]);
        }
    }
    return matches;
}

std::vector<FamilyMember *> FamilyTree::getMembersBasedOnLastName(std::string lastName) const{
    std::vector<FamilyMember *> matches;
    for (int i = 0; i < familyMembers->size(); ++i) {
        if ((*familyMembers)[i]->getLastName() == lastName) {
            matches.push_back((*familyMembers)[i]);
        }
    }
    return matches;
}

std::vector<FamilyMember *> FamilyTree::getMembersBasedOnBirthday(Date date) const{
    std::vector<FamilyMember *> matches;
    for (int i = 0; i < familyMembers->size(); ++i) {
        if ((*familyMembers)[i]->getBirthday() == date) {
            matches.push_back((*familyMembers)[i]);
        }
    }
    return matches;
}

std::vector<FamilyMember *> FamilyTree::getMembersBasedOnDeathday(Date date) const{
    std::vector<FamilyMember *> matches;
    for (int i = 0; i < familyMembers->size(); ++i) {
        if ((*familyMembers)[i]->getDeathday() == date) {
            matches.push_back((*familyMembers)[i]);
        }
    }
    return matches;
}

FamilyMember * FamilyTree::lookForMember() const{
    Helper::print("Looking for a member:");
    Helper::print("0 for looking by name.");
    Helper::print("1 for looking by last name.");
    Helper::print("2 for looking by birth date.");
    Helper::print("3 for looking by death date.");
    int criterion = Helper::read<int>("What criterion would you like to use?");
    if (criterion == 0) {
        std::vector<FamilyMember *> fm = getMembersBasedOnName(Helper::readLine("Enter name:"));
        Helper::print("Showing matches based on given name:");
        if (fm.size()==0) {
            Helper::print("No matches found.");
            return nullptr;
        }
        for (int i = 0; i < fm.size(); ++i) {
            std::cout << i + 1 << " for:" << std::endl;
            std::cout << *fm[i] << std::endl;
        }
        int input;
        do {
            input = Helper::read<int>("Enter the number of the member you are looking for? (If it is not listed enter 0)");
        } while (input < 0 || input > fm.size());
        if (input == 0) return nullptr;
        else return fm[input-1];
    }
    else if (criterion == 1){
        std::vector<FamilyMember *> fmln = getMembersBasedOnLastName(Helper::readLine("Enter last name:"));
        Helper::print("Showing matches based on given last name:");
        if (fmln.size()==0) {
            Helper::print("No matches found.");
            return nullptr;
        }
        for (int i = 0; i < fmln.size(); ++i) {
            std::cout << i + 1 << " for:" << std::endl;
            std::cout << *fmln[i] << std::endl;
        }
        int inputln;
        do {
            inputln = Helper::read<int>("Enter the number of the member you are looking for? (If it is not listed enter 0)");
        } while (inputln < 0 || inputln > fmln.size());
        if (inputln == 0) return nullptr;
        else return fmln[inputln-1];
    }
    else if (criterion == 2){
        Date * date = new Date;
        int input = Helper::read<int>("Enter birth day:");
        date->setDay(input);
        input = Helper::read<int>("Enter birth month:");
        date->setMonth(input);
        input = Helper::read<int>("Enter birth year:");
        date->setYear(input);
        std::vector<FamilyMember *> fmbd = getMembersBasedOnBirthday(*date);
        Helper::print("Showing matches based on given birth date:");
        if (fmbd.size()==0) {
            Helper::print("No matches found.");
            return nullptr;
        }
        for (int i = 0; i < fmbd.size(); ++i) {
            std::cout << i + 1 << " for:" << std::endl;
            std::cout << *fmbd[i] << std::endl;
        }
        int inputbd;
        do {
            inputbd = Helper::read<int>("Enter the number of the member you are looking for? (If it is not listed enter 0)");
        } while (inputbd < 0 || inputbd > fmbd.size());
        if (inputbd == 0) return nullptr;
        else return fmbd[inputbd-1];
    }
    else if (criterion == 3){
        Date * date = new Date();
        int input = Helper::read<int>("Enter death day:");
        date->setDay(input);
        input = Helper::read<int>("Enter death month:");
        date->setMonth(input);
        input = Helper::read<int>("Enter death year:");
        date->setYear(input);
        std::vector<FamilyMember *> fmbd = getMembersBasedOnBirthday(*date);
        Helper::print("Showing matches based on given death date:");
        if (fmbd.size()==0) {
            Helper::print("No matches found.");
            return nullptr;
        }
        for (int i = 0; i < fmbd.size(); ++i) {
            std::cout << i + 1 << " for:" << std::endl;
            std::cout << *fmbd[i] << std::endl;
        }
        int inputbd;
        do {
            inputbd = Helper::read<int>("Enter the number of the member you are looking for? (If it is not listed enter 0)");
        } while (inputbd < 0 || inputbd > fmbd.size());
        if (inputbd == 0) return nullptr;
        else return fmbd[inputbd-1];
    }
    else{
        Helper::print("Invalid input.");
        return lookForMember();
    }
}

//Editing member's traits
void FamilyTree::edit(FamilyMember * member){
    
}







