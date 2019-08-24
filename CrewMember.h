//
//  CrewMember.h
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/13/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#ifndef CrewMember_h
#define CrewMember_h
#include <string>
using namespace std;

class CrewMember{
public:
    //default and parameterized constructors
    CrewMember();
    CrewMember(string member_name, string member_id, string member_type, string member_status);
    //mutators which lets you set the details of the crew members
    void SetName(string member_name);
    void SetIdNumber(string member_id);
    void SetType( string member_type);
    void SetStatus(string member_status);
    //accessors tht lets you access the details of crew member
    string GetName() const;
    string GetIdNumber() const;
    string GetType() const;
    string GetStatus() const;
    
private:
    //attributes for class crewmember
    string memberName;
    string memberId;
    string memberType;
    string memberStatus;
};

#endif /* CrewMember_h */
