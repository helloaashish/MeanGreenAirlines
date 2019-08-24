//
//  Plane.h
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/13/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#ifndef Plane_h
#define Plane_h
#include<string>
using namespace std;

class Plane{
public:
    //default and parameterised constructor
    Plane();
    Plane(string plane_make, string plane_model, string plane_tailnumber,int plane_noseats, long plane_range,string plane_status);
    //mutators which sets the details for plane
    void SetMake( string plane_make);
    void SetModel(string plane_model);
    void SetTailNumber(string tail_number);
    void SetNoSeats(int plane_seats);
    void SetRange(long plane_range);
    void SetStatus(string plane_status);
    //accessors which returns the diffetent details of the plane
    string GetMake() const;
    string GetModel() const;
    string GetTailNumber() const;
    int GetNumberofSeats() const;
    long GetRange() const;
    string GetCurrentStatus() const;
    
private:
    //attributes for the class plane
    string make;
    string model;
    string tailNumber;
    int noSeats;
    long range;
    string currentStatus;
};

#endif /* Plane_h */
