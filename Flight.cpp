//
//  Flight.cpp
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/13/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include "Flight.h"
#include "Plane.h"
#include "CrewMember.h"
using namespace std;

//default constructor
Flight::Flight(){
   flightId="none";
    planeId="none";
    pilotId="none";
    copilotId="none";
    cabinmembersId[0]="none";
    cabinmembersId[1]="none";
    cabinmembersId[2]="none";
    startDate="none";
    endDate="none";
    aCode="none";
    bCode="none";
    numberofPassengers=0;
    flightStatus="none";}


//parameterized constructor
Flight::Flight(string flight_id, string plane_id, string pilot_id, string copilot_id, string member_1, string member_2,string member_3, string start_date, string end_date, string a_code, string b_code, int number_passengers, string flight_status){
    {
        flightId=flight_id;
        planeId=plane_id;
        pilotId=pilot_id;
        copilotId=copilot_id;
        cabinmembersId[0]=member_1;
        cabinmembersId[1]=member_2;
        cabinmembersId[2]=member_3;
        startDate=start_date;
        endDate=end_date;
        aCode=a_code;
        bCode=b_code;
        numberofPassengers=number_passengers;
        flightStatus=flight_status;}
    
}

//mutator sets flight id;
void Flight::SetFlightId(string flight_id){
    flightId=flight_id;}

//mutator sets plane id;
void Flight::SetPlaneId(string plane_id){
    planeId=plane_id;}

//mutator sets pilot id;
void Flight::SetPilotId(string pilot_id){
    pilotId=pilot_id;}

//mutator sets cabin members id;
void Flight::SetCabinMembersId(string member1_id, string member2_id, string member3_id){
    cabinmembersId[0]=member1_id;
    cabinmembersId[1]=member2_id;
    cabinmembersId[2]=member3_id;}

//mutator sets starting date
void Flight::SetStartDate(string start_date){
 startDate= start_date;}

//mutator sets the end date fof flight
void Flight::SetEndDate(string end_date){
endDate=end_date;}

//mutator sets the starting airport code
void Flight::SetStartingAirportCode(string airportcode_a){
    aCode=airportcode_a;}

//mutator sets the ending airport code
void Flight::SetEndingAirportCode(string airportcode_b){
    bCode=airportcode_b;}

//mutator sets the numbet of passengers
void Flight::SetNumberofPassengers(int passengers_number){
    numberofPassengers=passengers_number;}

//mutator sets the status of the flight
void Flight::SetFlightStatus(string flight_status){
    flightStatus=flight_status;}

//accessor returns the flight id
string Flight::GetFlightId() const{
    return flightId;}

//accesspr returns the plane id
string Flight::GetPlaneId() const{
    return planeId;}

//accessor returns the pilot id
string Flight::GetPilotId() const{
    return pilotId;}

//accessor returns the co pilot id
string Flight::GetCoPilotId() const{
    return copilotId;}

string Flight::GetCabinMember1Id(){
    return cabinmembersId[0];
}
string Flight::GetCabinMember2Id(){
    return cabinmembersId[1];
}
string Flight::GetCabinMember3Id(){
    return cabinmembersId[2];
}


//accessor returns the starting date
string Flight::GetStartDate() const{
return startDate;}

//accessor returns the end date
string Flight::GetEndDate() const{
return endDate;}

//accessor returns the starting airport code
string Flight::GetSrartingAirportCode() const{
    return aCode;}

//accessor returns the ending airport code
string Flight::GetEndingAirportCode() const{
    return bCode;}

//accessor returns the number of passengers
int Flight::GetNumberofPassengers() const{
    return numberofPassengers;}

//accessor returns the status of the flight
string Flight::GetFlightStatus() const{
    return flightStatus;}



