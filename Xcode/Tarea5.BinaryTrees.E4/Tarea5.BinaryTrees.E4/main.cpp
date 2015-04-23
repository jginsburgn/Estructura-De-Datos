//
//  main.cpp
//  Tarea5.BinaryTrees.E4
//
//  Created by Jonathan Ginsburg on 4/21/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "FamilyTree.h"

int main(int argc, const char * argv[]) {
    FamilyTree * familyTree = new FamilyTree("First family tree.");
    int choice = 1;
    while (choice != 0) {
        Helper::print("0 for exiting the program.");
        Helper::print("1 for adding a new member");
        Helper::print("2 for editing a member");
        Helper::print("3 for showing information about a member.");
        Helper::print("4 for showing all living members.");
        Helper::print("5 for showing all members that died before a date.");
        Helper::print("6 for showing all members.");
        choice = Helper::read<int>("Enter your choice:");
        if (choice == 1) {
            familyTree->makeMember();
            Helper::print("done.");
        }
        else if (choice == 2){
            Helper::print("Let's look for the member you want to edit");
            FamilyMember * memberToEdit = familyTree->lookForMember();
            if (!memberToEdit) {
                continue;
            }
            familyTree->edit(memberToEdit);
            Helper::print("done.");
        }
        else if (choice == 3){
            Helper::print("Choose the member you want to see information on:");
            FamilyMember * memberToShowInformation = familyTree->lookForMember();
            if (!memberToShowInformation) {
                Helper::print("No member was chosen");
                continue;
            }
            Helper::print("Chosen member:");
            std::cout << *memberToShowInformation << std::endl;
            Helper::print("0 for showing member's descendents.");
            Helper::print("1 for showing member's ascendents.");
            Helper::print("2 for showing member's brothers.");
            Helper::print("3 for showing member's cousins.");
            Helper::print("4 for showing member's children.");
            int b = Helper::read<int>("Enter your choice:");
            if (b==0) {
                memberToShowInformation->showDescendents();
            }
            else if (b==1){
                memberToShowInformation->showAscendents();
            }
            else if (b==2){
                memberToShowInformation->showBrothers();
            }
            else if (b==3){
                memberToShowInformation->showCousins();
            }
            else if (b==4){
                memberToShowInformation->showChildren();
            }
            else{
                Helper::print("Invalid option.");
                continue;
            }
        }
        else if (choice == 4){
            Helper::print("Showing all living members.");
            familyTree->showAllLivingMembers();
            Helper::print("Done showing all living members.");
        }
        else if (choice == 5){
            Helper::print("Showing all members that died before a date.");
            Date date;
            int asdf = Helper::read<int>("Enter day [1-31]:");
            date.setDay(asdf);
            asdf = Helper::read<int>("Enter month [1-12]:");
            date.setMonth(asdf);
            asdf = Helper::read<int>("Enter year:");
            date.setYear(asdf);
            familyTree->showAllMembersThatDiedBefore(date);
            Helper::print("Done showing all living members.");
        }
        else if (choice == 6){
            Helper::print("Showing all members:");
            familyTree->showAllMembers();
            Helper::print("Done showing all members.");
        }
    }
    Helper::print("Terminating program...");
    return 0;
}
