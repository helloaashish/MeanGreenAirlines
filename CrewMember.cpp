//
//  CrewMember.cpp
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/13/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "CrewMember.h"
#include <string>

//default constructor
CrewMember::CrewMember(){
    memberName="none";
    memberId="none";
    memberType="none";
    memberStatus="none";}

//parametrixed constructor
CrewMember::CrewMember(string member_name, string member_id, string member_type, string member_status){
    memberName=member_name;
    memberId=member_id;
    memberType=member_type;
    memberStatus=member_status;}

//mutator, sets name
void CrewMember::SetName(string member_name){
    memberName=member_name;}

//mutator sets id number for crew member
void CrewMember::SetIdNumber(string member_id){
    memberId=member_id;}

//mutator sets type for crew member
void CrewMember::SetType( string member_type){
    memberType=member_type;}

//mutator sets the status oof crew member
void CrewMember::SetStatus(string member_status){
    memberStatus=member_status;}

//accssor returns the name for crew member
string CrewMember::GetName() const{
    return memberName;}

//accessor returns the id number of the crew member
string CrewMember::GetIdNumber() const{
    return memberId;}

//accessor returns the type for the crew member
string CrewMember::GetType() const{
    return memberType;}

//accessor returns the status of crew member
string CrewMember::GetStatus() const{
    return memberStatus;
}
