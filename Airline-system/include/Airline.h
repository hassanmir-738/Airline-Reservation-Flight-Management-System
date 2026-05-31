#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include <vector>

#include "BusinessPassenger.h"
#include "CharterFlight.h"
#include "DomesticFlight.h"
#include "EconomyPassenger.h"
#include "FirstClassPassenger.h"
#include "Flight.h"
#include "InternationalFlight.h"
#include "Passenger.h"
#include "Ticket.h"

using namespace std;

// Simple struct to track revenue per flight
// Replaces std::map<string, double>
struct RevenueEntry {
  string flightNumber;
  double totalRevenue;
};

// Main Airline class - manages flights, passengers, and tickets
class Airline {
private:
  string airlineName;

  // Raw pointer arrays stored in vectors
  // We use Flight* and Passenger* instead of shared_ptr
  vector<Flight *> flights;
  vector<Passenger *> passengers;
  vector<Ticket> tickets;

  // Revenue tracking using a simple array of structs
  RevenueEntry revenueList[200]; // supports up to 200 flights
  int revenueCount;              // how many entries are currently used

  int nextTicketID; // counter for generating ticket IDs

  // Helper: generate a ticket ID like TKT001, TKT002, ...
  string generateTicketID();

  // Helper: find revenue index for a given flight number (-1 if not found)
  int findRevenueIndex(const string &flightNumber) const;

  // Helper: add revenue entry for a new flight
  void addRevenueEntry(const string &flightNumber);

public:
  Airline(string name);
  ~Airline(); // destructor deletes all raw pointers to prevent memory leaks

  // ---- Flight Management ----
  void addFlight(Flight *flight);
  bool removeFlight(const string &flightNumber);

  // Search functions - return raw pointer arrays via vector
  // Each function loops through and checks manually
  void searchFlightsByNumber(const string &flightNum,
                             vector<Flight *> &results) const;
  void searchFlightsByRoute(const string &origin, const string &dest,
                            vector<Flight *> &results) const;
  void searchFlightsByDate(const string &date, vector<Flight *> &results) const;
  void listAllFlights() const;

  // ---- Passenger Management ----
  void registerPassenger(Passenger *passenger);
  bool removePassenger(const string &passengerID);
  void viewBookingHistory(const string &passengerID) const;
  Passenger *findPassenger(const string &passengerID) const;

  // ---- Booking ----
  void bookTicket(const string &passengerID, const string &flightNumber,
                  const string &currentDate);

  // ---- Cancellation & Refund ----
  void cancelTicket(const string &ticketID, const string &currentDate);

  // ---- Reports ----
  void todaysDepartures(const string &today) const;
  void occupancyReport() const;
  void topRevenueFlights() const;

  // ---- File Persistence ----
  void saveToFile(const string &filename) const;
  void loadFromFile(const string &filename);

  // ---- Getters ----
  const vector<Flight *> &getFlights() const;
  const vector<Passenger *> &getPassengers() const;
  const vector<Ticket> &getTickets() const;
};

#endif
