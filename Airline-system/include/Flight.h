#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>

using namespace std;

// Abstract base class for all flight types
class Flight {
protected:
  string flightNumber;
  string origin;
  string destination;
  string departureDate; // format: YYYY-MM-DD
  string departureTime; // format: HH:MM
  int totalSeats;
  int availableSeats;

public:
  // Constructor
  Flight(string fNum, string orig, string dest, string date, string time,
         int total, int available);

  // Virtual destructor for proper cleanup in inheritance
  virtual ~Flight();

  // Pure virtual functions - every subclass MUST implement these
  virtual double calculateBaseFare() const = 0;
  virtual void displayDetails() const = 0;
  virtual string getFlightType() const = 0;

  // Getters - return private/protected data
  string getFlightNumber() const;
  string getOrigin() const;
  string getDestination() const;
  string getDepartureDate() const;
  string getDepartureTime() const;
  int getTotalSeats() const;
  int getAvailableSeats() const;

  // Setter
  void setAvailableSeats(int seats);

  // Book a seat (decreases available seats by 1)
  bool bookSeat();

  // Cancel a seat (increases available seats by 1)
  void cancelSeat();

  // Calculate how full the flight is as a percentage
  double getOccupancyPercentage() const;

  // Display function (replaces operator<<)
  void display() const;

  // Save to file string format
  virtual string toFileString() const;
};

#endif
