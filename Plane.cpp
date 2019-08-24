//
//  Plane.cpp
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/13/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "Plane.h"
using namespace std;

//default constructor
Plane::Plane(){
    make="none";
    model="none";
    tailNumber ="none";
    noSeats=0;
    range=0;
    currentStatus="none";

}
//parameterized constructor
Plane::Plane(string plane_make, string plane_model, string plane_tailnumber, int plane_noseats,long plane_range, string plane_status){
    make=plane_make;
    model=plane_model;
    tailNumber=plane_tailnumber;
    noSeats=plane_noseats;
    range=plane_range;
    currentStatus=plane_status;}

//mutator, sets the make of plane
void Plane::SetMake( string plane_make){
    make=plane_make;}

//mutator, sets the model of the plane
void Plane::SetModel(string plane_model){
    model=plane_model;}

// mutator , sets the tail number of the plane
void Plane::SetTailNumber(string tail_number){
    tailNumber=tail_number;}

//mutator, sets the number of seates of plane
void Plane::SetNoSeats(int plane_seats){
    noSeats=plane_seats;}

//mutator , sets the range of the plane
void Plane::SetRange( long plane_range){
    range=plane_range;}

//mutator sets the status of the plane
void Plane::SetStatus(string plane_status){
    currentStatus=plane_status;}

//return the make of plane
string Plane::GetMake() const{
    return make;}

//return the model of plane
string Plane::GetModel() const{
    return model;}

//return the tail number of plane
string Plane::GetTailNumber() const{
    return tailNumber;}

//return the number of seats of plane
int Plane::GetNumberofSeats() const{
    return noSeats;}

//return the range of plane
long Plane::GetRange() const{
    return range;}

//return the status of plane
string Plane::GetCurrentStatus() const{
    return currentStatus;
}
