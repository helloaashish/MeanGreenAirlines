//
//  main.cpp
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/13/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//
/* Name: Aashish Pandey
 Course: CSCE 1040
 Instructor: Prof David Keathly
 Date: 11/13/2017
 Description: This Program creates a flight scheduling for crewmember and plane in mean green airlines. And also lets the user print and edit the different details of plane, crewmembers and flight.
 */

#include <iostream>
#include <string>
#include "Planes.h" //including the header files
#include "CrewMembers.h"
#include "Flights.h"

void PressEnterToContinue();
void PrintMenu(); //print the intital menu options
 void  PlaneMenu(); //print the menu options for working with plane
void CrewMemberMenu(); //prints the menu options for working with crew members
void FlightMenu();//prints the menu options for working with Flights

Planes planelist; //object for class Planes
CrewMembers crewlist;//object for class CrewMembers
Flights flightlist; // object for class Flights
int main() {
    string tail_number; //declaring and initialing the variables
    string crewmember_id;
    int MenuChoice=0;
    char PlaneOptions='g';
    char CrewOptions='g';
    char FlightOptions='g';
   
    // for inital display of my and department information at first of the output
    
    cout << "+---------------------------------------------------+"<<endl;
    cout << "|      Computer Science and Engineering             |"<<endl;
    cout << "|      CSCE 1040 - Computer Science                 |"<<endl;
    cout << "|Aashish Pandey  11225327 AashishPandey@my.unt.edu  |" << endl;
    cout << "+---------------------------------------------------+" << endl;
    
    // providing user the list of menu items and and asking what they want to do
    while (MenuChoice!=4) {
        PrintMenu(); //void function to pring the menu options
        cout <<"\n\nEnter your Choice ::::::::::  ";
        cin>>MenuChoice;
        switch (MenuChoice) {
            case 1:{
                while(PlaneOptions!='f'){
                    PlaneMenu();
                cout<<"\n\n Enter your choice:::::";
                cin>>PlaneOptions;
                    switch(PlaneOptions){
                        case 'a': {
                            planelist.AddPlaneToList();//adding plane to the list
                            PressEnterToContinue();
                            break;}
                            
                        case 'b':{
                            planelist.EditPlane(); //editing the details of plane
                            PressEnterToContinue();
                            break;
                        }
                        
                        case 'c':{
                            planelist.DeletePlane(); //deleting the plane from the list
                            PressEnterToContinue();
                            break;
                        }
                            
                        case 'd':{
                            planelist.PrintList(); //printing the list of plane
                            PressEnterToContinue();
                            break;}
                            
                        case 'e':{
                            planelist.PrintDetailsofPlane(); //printing details of a single plane
                            PressEnterToContinue();
                            break;}
                            
                        case 'f':{
                            break;
                        }
                    }}}
                
            case 2:{
                while(CrewOptions!='f'){
                    CrewMemberMenu();
                    cout<<"\n\n Enter your choice:::::";
                    cin>>CrewOptions;
                    switch(CrewOptions){
                        case 'a': {
                            crewlist.AddCrewMemberToList(); //adding crew member to the list
                            PressEnterToContinue();
                            break;}
                            
                        case 'b':{
                            crewlist.EditCrewMember(); //editing the details of a crew member
                            PressEnterToContinue();
                            break;
                        }
                            
                        case 'c':{
                            crewlist.DeleteCrewMember(); //deleting a crew member from the list
                            PressEnterToContinue();
                            break;
                        }
                            
                        case 'd':{
                            crewlist.PrintCrewList(); //printing the list of the crew members in collection
                            PressEnterToContinue();
                            break;}
                            
                        case 'e':{
                            crewlist.PrintDetailsofCrewMember(); //Printing the details of a crew member
                            PressEnterToContinue();
                            break;}
                            
                        case 'f':{
                            break; //go back
                        }
                    }}}
                
            case 3:{
                while(FlightOptions!='h'){
                    FlightMenu();
                    cout<<"\n\n Enter your choice:::::";
                    cin>>FlightOptions;
                    switch(FlightOptions){
                        case 'a': {
                            flightlist.AddFlightToList(planelist);//adding flight to list
                            PressEnterToContinue();
                            break;}
                            
                        case 'b':{
                            flightlist.EditFlight(); //editing the details of a flight
                            PressEnterToContinue();
                            break;
                        }
                            
                        case 'c':{
                            flightlist.EditFlight(); //deleting the flight from the list
                            PressEnterToContinue();
                            break;
                        }
                            
                        case 'd':{
                            flightlist.PrintAll(); //printing the list of plane
                            PressEnterToContinue();
                            break;}
                            
                        case 'e':{
                            flightlist.PrintDetailsofFlight(); //printing details of a single flight
                            PressEnterToContinue();
                            break;}
                            
                        case 'f':{
                            flightlist.PrintListFlightofaPlane(); //printing the list of flights for a plane
                            PressEnterToContinue();
                            break;
                        }
                        case 'g':{
                            //flightlist.PrintListofFlightsofaCrewMember();//printing the list of flights for a crew member
                            PressEnterToContinue();
                            break;
                        }
                            
                        case 'h':{
                            
                            break;
                        }
                            
                    }}}


                
                    break;}}
                
                
    return 0;
    }

//function for initial display of menu options
void PrintMenu(){
    cout<<endl<<"::::::Please choose the menu options::::::"<<endl;
    cout<<"1. Working with Plane"<<endl;
    cout<<"2. Working with Crew Members"<<endl;
    cout<<"3. Working with Flights"<<endl;
    cout<<"4. Quit"<<endl;
}

void PressEnterToContinue(){
    string x;
    cout<<"\n Press 1 to continue...\n"<<endl;
    cin>>x;}

//function for menu options for working with plane
void PlaneMenu(){
    cout<<endl<<":::::Please choose the options:::::"<<endl;
    cout<<"a. Add a Plane to the list"<<endl;
    cout<<"b. Edit a Plane"<<endl;
    cout<<"c. Delete a Plane"<<endl;
    cout<<"d. Print the List of Planes"<<endl;
    cout<<"e. Print the details of a Plane"<<endl;
    cout<<"f. GoBack"<<endl;}

//menu options for working with crew members
void CrewMemberMenu(){
    cout<<endl<<":::::Please choose the options:::::"<<endl;
    cout<<"a. Add a Crew Member to the list"<<endl;
    cout<<"b. Edit a Crew Member"<<endl;
    cout<<"c. Delete a Crew Member"<<endl;
    cout<<"d. Print the List of Crew Member"<<endl;
    cout<<"e. Print the details of a Crew Member"<<endl;
    cout<<"f. GoBack"<<endl;}

//menu options for working with flights
void FlightMenu(){
    cout<<endl<<":::::Please choose the options:::::"<<endl;
    cout<<"a. Add a Flight to the list"<<endl;
    cout<<"b. Edit a Flight "<<endl;
    cout<<"c. Delete a Flight "<<endl;
    cout<<"d. Print the List of Flights"<<endl;
    cout<<"e. Print the details of a Flight "<<endl;
    cout<<"f. Print all the flights of a plane"<<endl;
    cout<<"g. Print all the flights for a crew member"<<endl;
    cout<<"h. GoBack"<<endl;
    
}





