//
//  CrewMembers.cpp
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/15/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "CrewMember.h"
#include "CrewMembers.h"
using namespace std;

string crewmember_id;
string crewmember_name;
string crewmember_type;
string crewmember_status;
string tooedit;

//this function asks for the detais of a crew member and then add the crew member to the list
void CrewMembers::AddCrewMemberToList(){
    cout<<":::::ADD CREW MEMBER TO LIST:::::"<<endl;
    cout<<"Please enter the crew member name:"<<endl;
    cin>>crewmember_name;
id:
    cout<<"Please enter the crew member id: "<<endl;
    cin>>crewmember_id;
    //checking if the crewmember already exists in the list
    for (unsigned int i= 0; i<crewlist.size(); i++){
        if (crewlist.at(i).GetIdNumber()==crewmember_id){
            cout<<"Sorry crewmember already exists please try different ID"<<endl;
            goto id;}
    }
    cout<<"Please enter the crew member type(pilot/copilot/cabin):"<<endl;
    cin >> crewmember_type;
    cout<<"Please enter the crew member status(available/leave/sick):"<<endl;
    cin>>crewmember_status;
    
    CrewMember mycrewmember(crewmember_name, crewmember_id, crewmember_type, crewmember_status);
    crewlist.push_back(mycrewmember);//adding to the list
    ofstream inFile;
    inFile.open("Crewmembers.txt", ios::app);
    inFile<<crewmember_id<<crewmember_name<<crewmember_type<<crewmember_status;
    inFile.close();
    cout<<"Crew Member added succcessfully!!!"<<endl;}

//this function asks for crewmember id and lets the user to change the details of that crew member
void CrewMembers::EditCrewMember(){
    cout<<":::::EDIT CREW MEMBER:::::"<<endl;
    cout<<"Please enter the ID of the crew member that you want to edit:"<<endl;
    cin>>crewmember_id;
    for(unsigned int i=0; i<crewlist.size(); i++){
        if ((crewlist.at(i).GetIdNumber()==crewmember_id)){
            cout<<"Name: "<<crewlist.at(i).GetName()<<endl;
            cout<<"ID Number: "<<crewlist.at(i).GetIdNumber()<<endl;
            cout<<"Type: "<<crewlist.at(i).GetType()<<endl;
            cout<<"Status: "<<crewlist.at(i).GetStatus()<<endl;
            
            cout<<"What do you want to edit (name/type/status)?"<<endl;
            cin>>tooedit;
            
            if(tooedit=="name"){
                cout<<"Please enter the new name: "<<endl;
                cin>>crewmember_name;
                crewlist.at(i).SetName(crewmember_name);
                cout<<"Name changed successfully!!"<<endl;}
            
            else if(tooedit=="type"){
                cout<<"Please enter the new type: "<<endl;
                cin>>crewmember_type;
                crewlist.at(i).SetType(crewmember_type);
                cout<<"Crew member type changed successfully!!"<<endl;}
            else if (tooedit=="status"){
                cout<<"Please enter the new status for the crew member: "<<endl;
                cin>>crewmember_status;
                crewlist.at(i).SetStatus(crewmember_status);
                cout<<"The status of crew member changed successfully!!!"<<endl;}
            
        }
        else
            cout<<"Sorry...Crew member not found"<<endl;
    }
}


//this function asks for crewmember id and then deletes the crew member from that list
void CrewMembers::DeleteCrewMember(){
    cout<<"::::DELETE CREW MEMBER::::"<<endl;
    cout<<"Please enter the Crew Member id that you want to delete: "<<endl;
    cin>>crewmember_id;
    for (unsigned int i= 0; i< crewlist.size(); i++){
        if (crewlist.at(i).GetIdNumber()==crewmember_id){
            crewlist.erase(crewlist.begin()+i);//deleting the crew member
            cout<<"Crew member deleted successfully"<<endl;}
    }}

//this function prints the list of all crew members
void CrewMembers::PrintCrewList() const{
    cout<<"::::::LIST OF ALL CREW MEMBERS::::::"<<endl;
    for (unsigned int i= 0; i<crewlist.size(); i++){
        cout<<i+1<<"."<<crewlist.at(i).GetIdNumber()<<endl;
    }}

//this function asks for a crewmember id, finds the crewmember from the list and print the details of the crew member
void CrewMembers::PrintDetailsofCrewMember()const{
    cout<<"::::::PRINT DETAILS OF A CREW MEMBER::::::"<<endl;
    cout<<"Please enter the ID of the crew member that you want to see the details: "<<endl;
    cin>>crewmember_id;
    for (unsigned int i = 0; i< crewlist.size(); i++){
        if (crewlist.at(i).GetIdNumber()==crewmember_id){
            cout<<"Name: "<<crewlist.at(i).GetName()<<endl;
            cout<<"ID Number: "<<crewlist.at(i).GetIdNumber()<<endl;
            cout<<"Type: "<<crewlist.at(i).GetType()<<endl;
            cout<<"Status: "<<crewlist.at(i).GetStatus()<<endl;}
    }
}

//this function finds the crew member and returns the index number, and returns -1 if not found
int CrewMembers:: FindCrewMember(){
    cout<<"Please enter ID of the Crew Member that you want to find: "<<endl;
    cin>>crewmember_id;
    
    for (unsigned int i=0; i<crewlist.size(); i++){
        if (crewlist.at(i).GetIdNumber()==crewmember_id){
            return i;}
    }
    return -1;
}

//checking if the pilot is added to the list and is available for the flight
bool CrewMembers:: is_pilot_ready_for_scheduling(string pilot_id){
    for (unsigned int i= 0; i<crewlist.size();i++){
        if ((crewlist.at(i).GetIdNumber()==pilot_id)&&(crewlist.at(i).GetType()=="pilot"))
            return true;
        }
    return false;
    }
            
//checking if the co-pilot is added to the list and is available for the flight
bool CrewMembers:: is_copilot_ready_for_scheduling(string pilot_id){
    for (unsigned int i= 0; i<crewlist.size();i++){
        if ((crewlist.at(i).GetIdNumber()==pilot_id)&&(crewlist.at(i).GetType()=="copilot"))
            return true;
    }
    return false;
}
//checking if the pilot is added to the list and is available for the flight
bool CrewMembers:: is_cabinmember_ready_for_scheduling(string member_id){
    for (unsigned int i= 0; i<crewlist.size();i++){
        if ((crewlist.at(i).GetIdNumber()==member_id)&&(crewlist.at(i).GetType()=="cabin"))
            return true;
    }
    return false;
}
