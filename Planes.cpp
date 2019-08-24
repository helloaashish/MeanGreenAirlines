//
//  Planes.cpp
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/14/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

#include "Planes.h"
#include "Plane.h"
using namespace std;

string   plane_make;
string plane_model;
string plane_tailnumber;
int plane_noseats;
long plane_range;
string plane_status;
string toedit;

//this function asks for the details of the plane and add the plane to the list of planes
void Planes::AddPlaneToList(){
    cout<<"------ADD PLANE TO THE LIST-----"<<endl;
    cout<<"Please enter the make: "<<endl;
    cin>>plane_make;
    cout<<"Please enter the model: "<<endl;
    cin>>plane_model;
again:
    //checking if the plane already exists in the list;
    cout<<"Please enter the tail number: "<<endl;
    cin>>plane_tailnumber;
    for (unsigned int i=0; i<PlaneList.size();i++){
        if(PlaneList.at(i).GetTailNumber()==plane_tailnumber){
            cout<<"Sorry!! Plane already exists"<<endl;
            goto again;
        }
    }
    cout<<"Please enter the number of seats: "<<endl;
    cin>>plane_noseats;
    cout<<"Please enter the range of plane: "<<endl;
    cin>>plane_range;
    cout<<"Please enter the plane status(in/out/repair): "<<endl;
    cin>>plane_status;
    Plane myplane(plane_make, plane_model, plane_tailnumber, plane_noseats, plane_range, plane_status);
    
    PlaneList.push_back(myplane);//adding plane to the list
    cout<<"Plane added successfully!!"<<endl;
    ofstream inFile;
    inFile.open("planes.txt", ios::app);
    inFile<<plane_make<<plane_model<<plane_tailnumber<<plane_noseats<<plane_range<<plane_status;
    inFile.close();
    }

//this function prints the tail number of all the planes that exist in the list
void Planes::PrintList() const{
    cout<<endl<<"------All Planes-----"<<endl;
    for (unsigned int i= 0; i<PlaneList.size(); i++){
        cout<<i+1<<". "<<PlaneList.at(i).GetTailNumber()<<endl;
    }}

//this function asks the tail number of a plane that the user want to edit and let user to edit the details of the plane
void Planes::EditPlane(){
    cout<<"::::::EDIT PLANE::::::"<<endl;
    cout<<"Plese enter the tail number of the plane you want to edit: "<<endl; //asking which plane to edit
    cin>>plane_tailnumber;
    for (unsigned int i=0; i<PlaneList.size(); i++){
        if (PlaneList.at(i).GetTailNumber()==plane_tailnumber){
            cout<<":::::Plane details::::"<<endl;
            cout<<setw(12)<<"MAKE: "<<PlaneList.at(i).GetMake()<<endl;
            cout <<setw(12)<<"MODEL: "<<PlaneList.at(i).GetModel()<<endl;
            cout <<setw(12)<<"NO. SEATS: "<<PlaneList.at(i).GetNumberofSeats()<<endl;
            cout <<setw(12)<<"RANGE: "<<PlaneList.at(i).GetRange()<<endl;
            cout <<setw(12)<<"STATUS: "<<PlaneList.at(i).GetCurrentStatus()<<endl;
            cout <<"Please enter what do you want to edit (make/model/seats/range/status)"<<endl;
            cin >>toedit;
            if(toedit=="make"){
                cout<<"Please enter the new make: "<<endl;
                cin>>plane_make;
                PlaneList.at(i).SetMake(plane_make);
                cout<<"Make changed successfully!!!"<<endl;
            }
            else if(toedit=="model"){
                cout<<"Please enter the new model: "<<endl;
                cin>>plane_model;
                PlaneList.at(i).SetModel(plane_model);
                cout<<"Model changed successfully!!!"<<endl;
                }
            else if (toedit=="seats"){
                cout<<"Please enter the number of seats available"<<endl;
                cin>>plane_noseats;
                PlaneList.at(i).SetNoSeats(plane_noseats);
                cout<<"Number of seats changed successfully"<<endl;
                }
            else if(toedit=="range"){
                cout<<"Please enter the new range for the plane"<<endl;
                cin>>plane_range;
                PlaneList.at(i).SetRange(plane_range);
                cout<<"Range for the plane changed successfully"<<endl;
                }
            else if (toedit=="status"){
                cout<<"Please enter the new status for the plane(in/out/repair)"<<endl;
                cin>>plane_status;
                PlaneList.at(i).SetStatus(plane_status);
                cout<<"Status of the plane changed successfully!!!"<<endl;
            }
        }
        else
            cout<<"Sorry...Plane not found!!"<<endl;
        
        }
    }

//this function asks the user to input the tail number of the plane to delete it from the list and then deletes the plane from the list
void Planes::DeletePlane(){
    cout<<":::::::DELETE PLANE:::::::"<<endl;
    cout<<"Please enter the tail number of the plane you want to delete: "<<endl;
    cin>>plane_tailnumber;
    for (unsigned int i =0; i< PlaneList.size(); i++){
        if(PlaneList.at(i).GetTailNumber()==plane_tailnumber){
            PlaneList.erase(PlaneList.begin()+i); //deleting the plane from the list
            cout<<"Plane deleted successfully!!"<<endl;
        }
            }
}

//this function asks user to input a tail number, finds the plane and prints all the details associated to the planes
void Planes::PrintDetailsofPlane() const{
    cout<<"::::PRINT DETAILS OF A PLANE::::"<<endl;
    cout<<"Please enter the tail number of the plane that you want to see the details of: "<<endl;
    cin>>plane_tailnumber;
    for (unsigned int i=0; i<PlaneList.size(); i++){
        if(PlaneList.at(i).GetTailNumber()==plane_tailnumber){
            cout<<"Make: "<<PlaneList.at(i).GetMake()<<endl;
             cout<<"Model: "<<PlaneList.at(i).GetModel()<<endl;
             cout<<"Tail Number: "<<PlaneList.at(i).GetTailNumber()<<endl;
             cout<<"Number of Seats: "<<PlaneList.at(i).GetNumberofSeats()<<endl;
             cout<<"Range: "<<PlaneList.at(i).GetRange()<<endl;
             cout<<"Status: "<<PlaneList.at(i).GetCurrentStatus()<<endl;
        }
    }
    
    }

//this function asks for a tail numbet of a plane then search for the plane in the list, and returns the index numbet of the plane and if it doesnot fing the plane in the list it returns -1
int Planes:: FindPlane(){
    cout<<"Please enter the tail number of the plane that you want to find: "<<endl;
    cin>>plane_tailnumber;
    
    for (unsigned int i=0; i<PlaneList.size(); i++){
        if (PlaneList.at(i).GetTailNumber()==plane_tailnumber){
            return i;}
    }
    return -1;
}

//checking if the  plane exists in the list and is available for scheduling the flight
bool Planes::is_plane_ready_for_scheduling(string planeid){
    for (unsigned int i=0;i<PlaneList.size();i++){
        if ((PlaneList.at(i).GetTailNumber()==planeid)&&(PlaneList.at(i).GetCurrentStatus()=="in"))
            return true;
            }
    return false;
}
    
    
    

