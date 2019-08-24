//
//  Flights.cpp
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/19/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include <string>
#include <vector>
#include "Flights.h"
#include "Planes.h"
#include "CrewMembers.h"
#include <fstream>

using namespace std;
string flight_id, plane_id, pilot_id, copilot_id, member1_id, member2_id, member3_id, start_date, end_date, a_code, b_code, flight_status;
int number_passengers,letsedit;

//AddFlightToList asks user to input the flight details and add the flight to the list
void Flights::AddFlightToList(Planes thelist){
    //Planes thisplane;
    CrewMembers thismember;
    
    
    cout<<endl<<":::::ADD FLIGHT TO THE LIST::::"<<endl;
    cout<<"Please enter the flight id: "<<endl;
    cin>>flight_id;
againplaneid:
    cout<<"Please enter the plane id: "<<endl;
    cin>>plane_id;
    //checking if plane exists and if it is available;
    if(thelist.is_plane_ready_for_scheduling(plane_id)==false){
        cout<<"sorry this plane is not available for adding to flight please try again"<<endl;
        goto againplaneid;
    };
againpilotid:
    cout<<"Please enter the Pilot id:"<<endl;
    cin>>pilot_id;
    if(thelist.is_plane_ready_for_scheduling(pilot_id)==false){
        cout<<"sorry this pilot is not available for adding to the flight please try again"<<endl;
        goto againpilotid;
    }
againcopilot:
    cout<<"Please enter the copilot id:"<<endl;
    cin>>copilot_id;
    //checking if the copilot selected if available and is of specific type
    if (thismember.is_copilot_ready_for_scheduling(copilot_id)==false){
        cout<<"sorry this copilot is not available for adding to the flight please try again"<<endl;
        goto againcopilot;
    }
againmembers:
    cout<<"Please enter the 3 crew members id: "<<endl;
    cin>>member1_id;
    cin>>member2_id;
    cin>>member3_id;
    //checking if the cabin members are available and are of required type
    if((thismember.is_cabinmember_ready_for_scheduling(member1_id)==false)||(thismember.is_cabinmember_ready_for_scheduling(member2_id)==false)||(thismember.is_cabinmember_ready_for_scheduling(member3_id)==false)){
        cout<<"sorry the cabin members assigned are not available. please try different members:"<<endl;
        goto againmembers;
    }


    cout<<"Please enter the start date and time:"<<endl;
    cin>>start_date;
    cout<<"Please enter the end date and time:"<<endl;
    cin>>end_date;
    cout<<"Please enter the starting airport code:"<<endl;
    cin>>a_code;
    cout<<"Please enter the ending airport code:"<<endl;
    cin>>b_code;
    cout<<"Please enter the number of passengers:"<<endl;
    cin>>number_passengers;
    cout<<"Please enter the flight status (active/cancelled/compleated):"<<endl;
    cin>>flight_status;
    Flight myflight(flight_id, plane_id, pilot_id, copilot_id, member1_id, member2_id,member3_id, start_date, end_date, a_code,b_code, number_passengers, flight_status);
    flightlist.push_back(myflight);
    ofstream inFile;
    inFile.open("flights.txt", ios::app);
    inFile<<flight_id<< plane_id<< pilot_id<< copilot_id<< member1_id<< member2_id<<member3_id<< start_date<< end_date<< a_code<<b_code<< number_passengers<< flight_status;
    
    cout<<"Flight added successfully"<<endl;
    
   

    
  }

//this function asks the user to input the flight id, finds the flight and let you edit the details for the flight
void Flights::EditFlight(){
    cout<<"Please enter the flight id of the flight that you want to edit"<<endl;
    cin>>flight_id;
    for (unsigned int i=0;i<flightlist.size();i++){
        if (flightlist.at(i).GetFlightId()==flight_id){
            cout<<"Please enter what do you want to edit:\n 1.plane\n 2.pilot \n 3.copilot\n 4.cabin members \n 5.start date\n 6.end date\n 7.start airport code \n 8. end airport code\n 9. flight status "<<endl;
            cin>>letsedit;
            //if user wants to change the plane
            if(letsedit==1){
                cout<<"Please enter the tail number of the new plane you want to assign to the flight"<<endl;
                cin>>plane_id;
                flightlist.at(i).SetPlaneId(plane_id);
                cout<<"plane changed successfully"<<endl;}
           else if(letsedit==2){
                cout<<"please enter the new pilot id for the flight"<<endl;
                cin>>pilot_id;
                flightlist.at(i).SetPilotId(pilot_id);
                cout<<"pilot changed successfully"<<endl;}
           /*else if(letsedit==3){
                cout<<"Please enter the copilot id of the new co pilot"<<endl;
                cin>>copilot_id;
                flightlist.at(i).SetCoPilotId(copilot_id);
                cout<<"copilot changed successfully"<<endl;}//*/
            else if(letsedit==4){
                cout<<"Plese enter the 3 cabin mambers id that you want to assign for the flight:"<<endl;
                cin>>member1_id;
                cin>>member2_id;
                cin>>member3_id;
                flightlist.at(i).SetCabinMembersId(member1_id, member2_id, member3_id);
                cout<<"cabin members changed successfully!!"<<endl;}
           else if (letsedit==5){
                cout<<"Please enter the new start date for the flight:"<<endl;
                cin >> start_date;
                flightlist.at(i).SetStartDate(start_date);
                cout<<"start date changed successfully"<<endl;}
           else if (letsedit==6){
                cout<<"Please enter the new end date for the flight"<<endl;
                cin>>end_date;
                flightlist.at(i).SetEndDate(end_date);
                cout<<"end date changed successfully"<<endl;}
        else if (letsedit==7){
                cout<<"Please enter the new starting airport code"<<endl;
                cin>>a_code;
                flightlist.at(i).SetStartingAirportCode(a_code);
                cout<<"starting airport code changed successfully!!"<<endl;}
           else if (letsedit==8){
                cout<<"Please enter the new ending airport code for the flight"<<endl;
                cin>>b_code;
                flightlist.at(i).SetEndingAirportCode(b_code);
                cout<<"ending airport code changed successfully!!!"<<endl;}
            else if (letsedit==9){
                cout<<"Please enter the new status for the flight"<<endl;
                cin>>flight_status;
                flightlist.at(i).SetFlightStatus(flight_status);
                cout<<"Flight status changed successfully"<<endl;
                
            }
        }
    }
}

//Delete flight askes for a flight id and delete that flight from the list
void Flights::DeleteFlight(){
    cout<<"::::DELETE FLIGHT::::"<<endl;
    cout<<"Please enter the flight id of the flight you want to delete: "<<endl;
    cin>>flight_id;
    unsigned long a= flightlist.size();
    for(unsigned int i= 0; i<flightlist.size();i++){
        if(flightlist.at(i).GetFlightId()==flight_id){
            flightlist.erase(flightlist.begin()+i);}
    }
    if (a!=flightlist.size())
        cout<<"Flight deleted successfully!!!"<<endl;
    }

//PrintAll prints the list of all flights
void Flights::PrintAll(){
    cout<<endl<<"::::List of all flights::::"<<endl;
    for (unsigned int i=0; i<flightlist.size(); i++){
        cout<<i+1<<". "<<flightlist.at(i).GetFlightId()<<endl;}
    }

//this function asks for a flight id and finds and returns the index number of the flight
int Flights::FindFlight(){
    cout<<"Please enter the flight id of the flight that you want to Find: "<<endl;
    cin>>flight_id;
    for(unsigned int i=0; i<flightlist.size(); i++){
        if(flightlist.at(i).GetFlightId()==flight_id){
            return i;
        }
    }
    return -1;
}

//this function asks user for a flight id and prints all the details associated to the flight
void Flights::PrintDetailsofFlight(){
    cout<<endl<<"::::PRINT DETAILS OF A FLIGHT::::"<<endl;
    cout<<"Please enter the flight id of the flight that you want to see the details: "<<endl;
    cin>>flight_id;
    for(unsigned int i=0; i<flightlist.size(); i++){
        if(flightlist.at(i).GetFlightId()==flight_id){
            cout<<"Flight ID: "<<flightlist.at(i).GetFlightId()<<endl;
            cout<<"Plane ID: "<<flightlist.at(i).GetPlaneId()<<endl;
            cout<<"Pilot ID: "<<flightlist.at(i).GetPilotId()<<endl;
            cout<<"CoPilot ID: "<<flightlist.at(i).GetCoPilotId()<<endl;
            cout<<"Cabin members: 1. "<<flightlist.at(i).GetCabinMember1Id()<<endl;
            cout<<"               2. "<<flightlist.at(i).GetCabinMember2Id()<<endl;
            cout<<"               3. "<<flightlist.at(i).GetCabinMember3Id()<<endl;
            cout<<"Start Date: "<<flightlist.at(i).GetStartDate()<<endl;
            cout<<"End Date: "<<flightlist.at(i).GetEndDate()<<endl;
            cout<<"Starting airport: "<<flightlist.at(i).GetSrartingAirportCode()<<endl;
            cout<<"Ending airport code: "<<flightlist.at(i).GetEndingAirportCode()<<endl;
            cout<<"Number of Passengers: "<<flightlist.at(i).GetNumberofPassengers()<<endl;
            cout<<"Flight status: "<<flightlist.at(i).GetFlightStatus()<<endl;
        }
    }
}

//this function asks for the crewmember id, and print all the scheduled flights for the crew member
void Flights::PrintListofFlightsofaCrewMember(){
    string member_id;
    cout<<"::::PRINT LIST OF FLIGHTS FOR A MEMBER::::"<<endl;
    cout<<"Please enter the id for a crew member that you want to see the flights for: "<<endl;
    cin>>member_id;
    for (unsigned int i=0; i<flightlist.size(); i++){
        if((flightlist.at(i).GetPilotId()==member_id)||(flightlist.at(i).GetCoPilotId()==member_id)||(flightlist.at(i).GetCabinMember1Id()==member_id)||(flightlist.at(i).GetCabinMember2Id()==member_id)||(flightlist.at(i).GetCabinMember3Id()==member_id))
            cout<<flightlist.at(i).GetFlightId()<<endl;
    }
}

//this function asks the user to input the tail number of a plane and then prints all the scheduled flights for the plane
void Flights::PrintListFlightofaPlane(){
    cout<<"::::LIST OF FLIGHTS FOR A PLANE::::"<<endl;
    cout<<"Please enter the tail number of a flight that you want to see the flights for: "<<endl;
    cin>>plane_id;
    int counter=1;
    for(unsigned int i=0; i<flightlist.size(); i++){
        if (flightlist.at(i).GetPlaneId()==plane_id){
            cout<<counter<<". "<< flightlist.at(i).GetFlightId()<<endl;
            counter++;
        }
    }}
