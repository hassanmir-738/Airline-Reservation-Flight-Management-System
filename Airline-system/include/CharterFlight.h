#ifndef CHARTER_FLIGHT_H
#define CHARTER_FLIGHT_H

#include "Flight.h"

// Charter flight - hired by a company or person, fixed contract price
class CharterFlight : public Flight {
private:
  string contractHolder; // company or person who chartered the flight
  double contractPrice;  // total contract price

public:
  CharterFlight(string fNum, string orig, string dest, string date, string time,
                int total, int available, string holder, double price);
  ~CharterFlight();

  // Implement pure virtual functions from Flight
  double calculateBaseFare() const;
  void displayDetails() const;
  string getFlightType() const;

  string getContractHolder() const;
  double getContractPrice() const;
  string toFileString() const;
};

#endif
#endif
