//
//  FamilyTree.cpp
//  Tarea5.BinaryTrees.E4
//
//  Created by Jonathan Ginsburg on 4/21/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "FamilyTree.h"

//Destructor
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
    std::cout << *newMember << std::endl;
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
    Helper::print("4 for listing all existing members.");
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
    else if (criterion == 4){
        Helper::print("Showing all existing members:");
        if (familyMembers->size()==0) {
            Helper::print("No matches found.");
            return nullptr;
        }
        for (int i = 0; i < familyMembers->size(); ++i) {
            std::cout << i + 1 << " for:" << std::endl;
            std::cout << *(*familyMembers)[i] << std::endl;
        }
        int inputln;
        do {
            inputln = Helper::read<int>("Enter the number of the member you are looking for? (If it is not listed enter 0)");
        } while (inputln < 0 || inputln > familyMembers->size());
        if (inputln == 0) return nullptr;
        else return (*familyMembers)[inputln-1];
    }
    else{
        Helper::print("Invalid input.");
        return lookForMember();
    }
}

//Showing members
void FamilyTree::showAllMembers() const{
    for (int i = 0; i < familyMembers->size(); ++i) {
        std::cout << "Member number " << i + 1 << ":" << std::endl;
        std::cout << *(*familyMembers)[i] << std::endl;
    }
}

void FamilyTree::showAllLivingMembers() const{
    for (int i = 0; i < familyMembers->size(); ++i) {
        if ((*familyMembers)[i]->isAlive()) {
            std::cout << *(*familyMembers)[i] << std::endl;
        }
    }
}

void FamilyTree::showAllMembersThatDiedBefore(Date date) const{
    for (int i = 0; i < familyMembers->size(); ++i) {
        if ((*familyMembers)[i]->diedBeforeDate(date)) {
            std::cout << *(*familyMembers)[i] << std::endl;
        }
    }
}

//Editing member's traits
void FamilyTree::edit(FamilyMember * member){
    std::cout << "Editing information on " << member->getName() << " " << member->getLastName() << std::endl;
    Helper::print("0 for editing name.");
    Helper::print("1 for editing last name.");
    Helper::print("2 for editing parents.");
    Helper::print("3 for editing children.");
    Helper::print("4 for editing birth date.");
    Helper::print("5 for editing death date.");
    Helper::print("6 for cancelling edition.");
    Helper::print("7 for editing living status of a person.");
    int input = Helper::read<int>("Enter your option");
    if (input == 0) {
        Helper::print("Current name: ");
        Helper::print(member->getName());
        member->setName(Helper::readLine("Enter new name:"));
    }
    else if (input == 1) {
        Helper::print("Current last name: ");
        Helper::print(member->getLastName());
        member->setLastName(Helper::readLine("Enter new last name:"));
    }
    else if (input == 2) {
        Helper::print("0 for editing father information.");
        Helper::print("1 for editing mother information.");
        Helper::print("2 for cancelling edition.");
        int newInput = Helper::read<int>("Enter your choice");
        if (newInput == 0) {
            std::string prompt = "Let's begin by looking at existing members to assign as father of ";
            prompt.append(member->getName());
            prompt.append(":");
            Helper::print(prompt);
            FamilyMember * potentialParent = lookForMember();
            if (potentialParent) {
                Helper::print("Assigning father.");
                member->setFather(potentialParent);
                Helper::print("Done.");
            }
            else{
                prompt = "It seems that the father of ";
                prompt.append(member->getName());
                prompt.append(" is not listed.");
                Helper::print(prompt);
                prompt = "0 for adding a new member and assigning it as father of ";
                prompt.append(member->getName());
                prompt.append(".");
                Helper::print(prompt);
                Helper::print("1 for cancelling edition.");
                int a = Helper::read<int>("Enter your choice");
                if (a == 0) {
                    potentialParent = makeMember();
                    if (potentialParent) {
                        member->setFather(potentialParent);
                    }
                    else{
                        Helper::print("No new member was created. Cancelling edition operation.");
                        return;
                    }
                }
                else if (a==1){
                    Helper::print("Cancelling edition operation");
                    return;
                }
                else{
                    Helper::print("Invalid option");
                    edit(member);
                }
            }
        }
        else if (newInput == 1){
            std::string prompt = "Let's begin by looking at existing members to assign as mother of ";
            prompt.append(member->getName());
            prompt.append(":");
            Helper::print(prompt);
            FamilyMember * potentialParent = lookForMember();
            if (potentialParent) {
                Helper::print("Assigning mother.");
                member->setMother(potentialParent);
                Helper::print("Done.");
            }
            else{
                prompt = "It seems that the mother of ";
                prompt.append(member->getName());
                prompt.append(" is not listed.");
                Helper::print(prompt);
                prompt = "0 for adding a new member and assigning it as mother of ";
                prompt.append(member->getName());
                prompt.append(".");
                Helper::print(prompt);
                Helper::print("1 for cancelling edition.");
                int a = Helper::read<int>("Enter your choice");
                if (a == 0) {
                    potentialParent = makeMember();
                    if (potentialParent) {
                        member->setMother(potentialParent);
                    }
                    else{
                        Helper::print("No new member was created. Cancelling edition operation.");
                        return;
                    }
                }
                else if (a==1){
                    Helper::print("Cancelling edition operation.");
                    return;
                }
                else{
                    Helper::print("Invalid option");
                    edit(member);
                }
            }
        }
        else if (newInput == 2){
            Helper::print("Cancelling edition operation.");
            return;
        }
        else{
            Helper::print("Invalid option.");
            edit(member);
        }
    }
    else if (input == 3){
        Helper::print("0 for adding child.");
        Helper::print("1 for removing child.");
        Helper::print("2 for cancelling edition.");
        int newInput = Helper::read<int>("Enter your choice");
        if (newInput == 0) {
            std::string p = "Let's look for a member to add as a child of ";
            p.append(member->getName());
            p.append(".");
            Helper::print(p);
            FamilyMember * potentialChild = lookForMember();
            if (potentialChild) {
                Helper::print("Adding child");
                member->insertChild(potentialChild);
                Helper::print("Done.");
                return;
            }
            else{
                std::string p = "It looks like the child of ";
                p.append(member->getName());
                p.append(" is not listed. Let's add him.");
                Helper::print(p);
                potentialChild = makeMember();
                if (potentialChild) {
                    Helper::print("Adding child");
                    member->insertChild(potentialChild);
                    Helper::print("Done.");
                }
                else{
                    Helper::print("No child was created. Cancelling edition operation.");
                    return;
                }
            }
        }
        else if(newInput == 1){
            std::string p = "Let's look for a member to remove as a child of ";
            p.append(member->getName());
            p.append(".");
            Helper::print(p);
            FamilyMember * potentialChild = lookForMember();
            if (potentialChild) {
                Helper::print("Removing child");
                member->removeChild(potentialChild);
                Helper::print("Done.");
                return;
            }
            else{
                Helper::print("No child was removed. Cancelling edition operation.");
                return;
            }
        }
    }
    else if (input == 4) {
        Helper::print("Editing the birth date.");
        Date newDate;
        int asdf = Helper::read<int>("Enter the day of his birth [1-31]:");
        newDate.setDay(asdf);
        asdf = Helper::read<int>("Enter the month of his birth [1-12]:");
        newDate.setMonth(asdf);
        asdf = Helper::read<int>("Enter the year of his birth:");
        newDate.setYear(asdf);
        Helper::print("Setting new birth date.");
        member->setBirthday(newDate);
        Helper::print("Done.");
    }
    else if (input == 5){
        Helper::print("Editing the death date.");
        Date newDate;
        int asdf = Helper::read<int>("Enter the day of his death [1-31]:");
        newDate.setDay(asdf);
        asdf = Helper::read<int>("Enter the month of his death [1-12]:");
        newDate.setMonth(asdf);
        asdf = Helper::read<int>("Enter the year of his death:");
        newDate.setYear(asdf);
        Helper::print("Setting new death date and living status.");
        member->setDeathday(newDate);
        member->setLivingStatus(LSDeceased);
        Helper::print("Done.");
    }
    else if (input == 6){
        Helper::print("Cancelling operation");
        return;
    }
    else if (input == 7){
        Helper::print("The current living status of the member is:");
        LivingStatus currentStatus = member->getLivingStatus();
        if (currentStatus == LSAlive) {
            Helper::print("Alive.");
        }
        else if (currentStatus == LSDeceased){
            Helper::print("Deceased.");
        }
        else if (currentStatus == LSUnknown){
            Helper::print("Unknown.");
        }
        Helper::print("Editing living status of member.");
        Helper::print("0 for cancelling operation.");
        Helper::print("1 for setting living status as alive.");
        Helper::print("2 for setting living status as deceased.");
        Helper::print("3 for setting living status as unknown.");
        int asdf = Helper::read<int>("Enter your choice:");
        if (asdf == 0) {
            Helper::print("Cancelling operation.");
            return;
        }
        else if (asdf == 1){
            member->setLivingStatus(LSAlive);
        }
        else if (asdf == 2){
            member->setLivingStatus(LSDeceased);
        }
        else if (asdf == 3){
            member->setLivingStatus(LSUnknown);
        }
        else{
            Helper::print("Invalid choice.");
            edit(member);
        }
    }
    else{
        Helper::print("Invalid option.");
        edit(member);
    }
    if (Helper::read<char>("Continue editing member? (y/n)") == 'y') {
        edit(member);
    }
}







