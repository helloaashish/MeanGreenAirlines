//
//  CrewMembers.h
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/15/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#ifndef CrewMembers_h
#define CrewMembers_h
#include<iostream>
#include <string>
#include <vector>
#include "CrewMember.h"
class CrewMembers{

public:
    void AddCrewMemberToList();//member function lets you add the crew member to the list
    void EditCrewMember();//member function lets you edit the details of a crew member
    void DeleteCrewMember();//member function lets you delete the member from the list
    int FindCrewMember();//member function finds the crew member from the list
    void PrintCrewList() const;//member function prints the list of all the crew member present in the list
    void PrintDetailsofCrewMember()const;//member functon prints all the details of a crew member
    bool is_pilot_ready_for_scheduling(string pilot_id);//checking if the selected pilot for flight is available
    bool is_copilot_ready_for_scheduling(string copilot_id);//checking if the selected copilot for flight is available
    bool is_cabinmember_ready_for_scheduling(string member_id);// checking if the crew members selected for flight are available
private:
    vector<CrewMember> crewlist; //vector that holds the list of crew member
};


#endif /* CrewMembers_h */
