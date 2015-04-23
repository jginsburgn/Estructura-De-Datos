//
//  FamilyMember.h
//  Tarea5.BinaryTrees.E4
//
//  Created by Jonathan Ginsburg on 4/21/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea5_BinaryTrees_E4__FamilyMember__
#define __Tarea5_BinaryTrees_E4__FamilyMember__

#include <vector>
#include "Date.h"

enum Gender { GMale, GFemale, GUnknown };

enum LivingStatus { LSAlive, LSDeceased, LSUnknown };

class FamilyMember {
    
private:
    
    //Personal information
    std::string * name = new std::string();
    std::string * lastName = new std::string();
    Date * birthday = new Date();
    Date * deathday = new Date();
    Gender gender = GUnknown;
    LivingStatus livingStatus = LSUnknown;
    
    //Relatives
    FamilyMember * father = nullptr;
    FamilyMember * mother = nullptr;
    std::vector<FamilyMember *> * children = new std::vector<FamilyMember *>();
    
public:
    
    //Default Constructors
    FamilyMember();
    
    //Destructors
    ~FamilyMember();
    
    //Additional Constructors
    FamilyMember(std::string newName, std::string newLastName);
    
    //Getters    
        //Personal Information
    std::string getName() const {return *name;};
    std::string getLastName() const {return *lastName;};
    Date getBirthday() const {return *birthday;};
    Date getDeathday() const {return *deathday;};
    Gender getGender() const {return gender;};
    LivingStatus getLivingStatus() const {return livingStatus;};
    
        //Relatives
    FamilyMember * getFather() const {return father;};
    FamilyMember * getMother() const {return mother;};
    std::vector<FamilyMember *> * getChildren() const {return children;};
    
    //Setters
        //Personal Information
    void setName(std::string newName) {*name = newName;};
    void setLastName(std::string newLastName) {*lastName = newLastName;};
    void setBirthday(Date newBirthday) {*birthday = newBirthday;};
    void setDeathday(Date newDeathday) {this->setLivingStatus(LSDeceased); *deathday = newDeathday;};
    void setGender(Gender newGender) {gender = newGender;};
    void setLivingStatus(LivingStatus newLivingStatus) {livingStatus = newLivingStatus;};
    
        //Relatives
    void setFather(FamilyMember * newFather) {father = newFather; newFather->insertChild(this);};
    void setMother(FamilyMember * newMother) {mother = newMother; newMother->insertChild(this);};
    
    //Adding children
    bool insertChild(FamilyMember * child);
    
    //Removing Children
    bool removeChild(FamilyMember * child);
    
    //Removing Parent
    bool removeParent(FamilyMember * parent);
    
    //Showing information
    void showChildren() const;
    void showAscendents() const;
    void showDescendents() const;
    void showBrothers() const;
    void parentShowBrothersOf(const FamilyMember * thisChild) const;
    void showCousins() const;
    void showNephews() const;
    void showGrandchildrenExceptFor(const FamilyMember * thisSonsChildren) const;
    
    //Other methods
    bool isAlive() const;
    bool diedBeforeDate(Date date) const;
    
    friend std::ostream & operator<<(std::ostream & osd, FamilyMember & fm);
};

#endif /* defined(__Tarea5_BinaryTrees_E4__FamilyMember__) */
