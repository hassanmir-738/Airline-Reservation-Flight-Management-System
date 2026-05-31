#ifndef DOMESTIC_FLIGHT_H
#define DOMESTIC_FLIGHT_H

#include "Flight.h"

// Domestic flight - shorter routes, lower base fare, no visa needed
class DomesticFlight : public Flight {
private:
  string region; // e.g., "North", "South", "Central"

public:
  DomesticFlight(string fNum, string orig, string dest, string date,
                 string time, int total, int available, string reg);
  ~DomesticFlight();

  // Implement pure virtual functions from Flight
  double calculateBaseFare() const;
  void displayDetails() const;
  string getFlightType() const;

  string getRegion() const;
  string toFileString() const;
};

#endif
#endif
