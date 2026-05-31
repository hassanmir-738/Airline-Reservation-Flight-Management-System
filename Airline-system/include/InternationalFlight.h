#ifndef INTERNATIONAL_FLIGHT_H
#define INTERNATIONAL_FLIGHT_H

#include "Flight.h"

// International flight - longer routes, higher fare, visa may be required
class InternationalFlight : public Flight {
private:
  bool visaRequired;
  string destinationCountry;

public:
  InternationalFlight(string fNum, string orig, string dest, string date,
                      string time, int total, int available, bool visa,
                      string country);
  ~InternationalFlight();

  // Implement pure virtual functions from Flight
  double calculateBaseFare() const;
  void displayDetails() const;
  string getFlightType() const;

  bool isVisaRequired() const;
  string getDestinationCountry() const;
  string toFileString() const;
};

#endif
#endif
