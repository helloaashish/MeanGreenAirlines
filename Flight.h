//
//  Flight.h
//  Homework MeanGreen airlines
//
//  Created by Aashish Pandey on 11/13/17.
//  Copyright © 2017 Aashish Pandey. All rights reserved.
//

#ifndef Flight_h
#define Flight_h
#include <string>
using namespace std;

class Flight{
public:
    //default and parameterized constructors
    Flight();
    Flight(string flight_id, string plane_id, string pilot_id, string copilot_id, string member_1,string member_2,string member_3, string start_date, string end_date, string a_code, string b_code, int number_passengers, string flight_status);
    //mutators that lets you set the different details of the flight
    void SetFlightId(string flight_id);
    void SetPlaneId(string plane_id);
    void SetPilotId(string pilot_id);
    void SetCoPilotId(string copilot_id);

    void SetCabinMembersId(string member1_id, string member2_id, string member3_id);
    void SetStartDate(string start_date);
    void SetEndDate(string end_date);
    void SetStartingAirportCode(string airportcode_a);
    void SetEndingAirportCode(string airportcode_b);
    void SetNumberofPassengers(int passengers_number);
    void SetFlightStatus(string flight_status);
    
    //accessors which lets us access the different details of the flight
    string GetFlightId() const;
    string GetPlaneId() const;
    string GetPilotId() const;
    string GetCoPilotId() const;
    string GetCabinMember1Id();
    string GetCabinMember2Id();
    string GetCabinMember3Id();
    string GetStartDate() const;
    string GetEndDate() const;
    string GetSrartingAirportCode() const;
    string GetEndingAirportCode() const;
    int GetNumberofPassengers() const;
    string GetFlightStatus() const;
    
private:
    //attributes for the class flight
    string flightId;
    string planeId;
    string pilotId;
    string copilotId;
    string cabinmembersId[3];
    string startDate;
    string endDate;
    string aCode;  //starting airport code
    string bCode;   //ending airport code
    int numberofPassengers;
    string flightStatus;
};


#endif /* Flight_h */
