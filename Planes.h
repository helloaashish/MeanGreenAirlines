//
//  Planes.h
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/14/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#ifndef Planes_h
#define Planes_h
#include <string>
#include <iostream>
#include <vector>
#include "Plane.h"
using namespace std;

class Planes{
public:
    void AddPlaneToList();// member function lets you add a plane to the collection
    void EditPlane(); // member function lets you edit or change the details of a plane in collection
    void DeletePlane(); //member function lets you delete a plane from the collection
    int FindPlane(); //member function that finds the planes in the collection
    void PrintList() const; //member function thet print tha list of all the planes in collection
    void PrintDetailsofPlane()const; // member functio that print the details of a sjpecific plane in collection
    bool is_plane_ready_for_scheduling(string planeid);

private:
    vector <Plane> PlaneList; // vector that holds the list of plane
};


#endif /* Planes_h */
