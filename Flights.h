//
//  Flights.h
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/19/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#ifndef Flights_h
#define Flights_h
#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"
//#include
#include "Planes.h"
#include "CrewMembers.h"
using namespace std;

class Flights{
public:
    void AddFlightToList(Planes thelist);//member function to add a flight
    void EditFlight();  //member function to edit flight
    void DeleteFlight();//member function to delete a flight from the list
    void PrintAll(); //member function to print the list of the flights
    int FindFlight();//member function to find a flight
    void PrintDetailsofFlight();//member function to print the details of a flight
    void PrintListofFlightsofaCrewMember();//membet function to print the scheduled flights for a crew member
    void PrintListFlightofaPlane();//member function to print the scheduled flights for a plane
private:
    vector <Flight> flightlist; //vector to hold the list of flights
    
};

#endif /* Flights_h */
