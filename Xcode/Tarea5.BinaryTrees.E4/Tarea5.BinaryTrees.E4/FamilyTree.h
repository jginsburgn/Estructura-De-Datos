//
//  FamilyTree.h
//  Tarea5.BinaryTrees.E4
//
//  Created by Jonathan Ginsburg on 4/21/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea5_BinaryTrees_E4__FamilyTree__
#define __Tarea5_BinaryTrees_E4__FamilyTree__

#include "FamilyMember.h"

class FamilyTree {
    
private:
    
    std::string * name = new std::string();
    std::vector<FamilyMember *> * familyMembers = new std::vector<FamilyMember *>();
    
public:
    
    //Constructor and Destructor
    FamilyTree() {*name = "No Name";};
    FamilyTree(std::string newName) {*name = newName;};
    ~FamilyTree();
    
    //Manipulating Family Members
    FamilyMember * makeMember();
    void removeMember(FamilyMember * member);
    
    //Accessing Family Members
    FamilyMember * getMember(int i) const;
    std::vector<FamilyMember *> getMembersBasedOnName(std::string name) const;
    std::vector<FamilyMember *> getMembersBasedOnLastName(std::string lastName) const;
    std::vector<FamilyMember *> getMembersBasedOnBirthday(Date date) const;
    std::vector<FamilyMember *> getMembersBasedOnDeathday(Date date) const;
    FamilyMember * lookForMember() const;
    
    //Showing members
    void showAllMembers() const;
    void showAllLivingMembers() const;
    void showAllMembersThatDiedBefore(Date date) const;
    
    //Editing member's traits
    void edit(FamilyMember * member);
};

#endif /* defined(__Tarea5_BinaryTrees_E4__FamilyTree__) */
