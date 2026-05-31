#include "../include/Flight.h"
#include <iomanip>

using namespace std;

// Constructor - initialise all member variables
Flight::Flight(string fNum, string orig, string dest, string date, string time,
               int total, int available)
    : flightNumber(fNum), origin(orig), destination(dest), departureDate(date),
      departureTime(time), totalSeats(total), availableSeats(available) {}

// Virtual destructor
Flight::~Flight() {}

// Getters
string Flight::getFlightNumber() const { return flightNumber; }
string Flight::getOrigin() const { return origin; }
string Flight::getDestination() const { return destination; }
string Flight::getDepartureDate() const { return departureDate; }
string Flight::getDepartureTime() const { return departureTime; }
int Flight::getTotalSeats() const { return totalSeats; }
int Flight::getAvailableSeats() const { return availableSeats; }

// Setter
void Flight::setAvailableSeats(int seats) { availableSeats = seats; }

// Book a seat - returns true if a seat was available
bool Flight::bookSeat() {
  if (availableSeats > 0) {
    availableSeats--;
    return true;
  }
  return false;
}

// Cancel a seat - gives back one seat
void Flight::cancelSeat() {
  if (availableSeats < totalSeats) {
    availableSeats++;
  }
}

// Calculate how full the flight is as a percentage
double Flight::getOccupancyPercentage() const {
  if (totalSeats == 0)
    return 0.0;
  return ((double)(totalSeats - availableSeats) / totalSeats) * 100.0;
}

// Display basic flight info (replaces operator<<)
void Flight::display() const {
  cout << "--------------------------------------" << endl;
  cout << "Flight Number : " << flightNumber << endl;
  cout << "Route         : " << origin << " -> " << destination << endl;
  cout << "Date & Time   : " << departureDate << " at " << departureTime
       << endl;
  cout << "Seats         : " << availableSeats << "/" << totalSeats
       << " available" << endl;
  cout << "Base Fare     : $" << fixed << setprecision(2) << calculateBaseFare()
       << endl;
  cout << "Occupancy     : " << fixed << setprecision(1)
       << getOccupancyPercentage() << "%" << endl;
  cout << "--------------------------------------" << endl;
}

// Default file string - derived classes add their own fields
string Flight::toFileString() const {
  return flightNumber + "," + origin + "," + destination + "," + departureDate +
         "," + departureTime + "," + to_string(totalSeats) + "," +
         to_string(availableSeats);
}

// FRIEND FUNCTION definition
// Has direct access to protected members (flightNumber) without a getter
bool cheaperFlight(const Flight &a, const Flight &b) {
  if (a.calculateBaseFare() < b.calculateBaseFare()) {
    cout << a.flightNumber << " is cheaper than " << b.flightNumber << endl;
    return true;
  } else {
    cout << b.flightNumber << " is cheaper than or equal to " << a.flightNumber
         << endl;
    return false;
  }
}
