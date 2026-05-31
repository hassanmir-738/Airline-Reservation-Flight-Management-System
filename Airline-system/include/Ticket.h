#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>

using namespace std;

// Ticket class - links a passenger to a flight booking
class Ticket {
private:
  string ticketID;
  string passengerID;
  string flightNumber;
  string seatNumber;
  double farePaid;
  string bookingStatus; // "Booked" or "Cancelled"
  string bookingDate;

public:
  Ticket(string tID, string pID, string fNum, string seat, double fare,
         string status, string bDate);
  ~Ticket();

  // Getters
  string getTicketID() const;
  string getPassengerID() const;
  string getFlightNumber() const;
  string getSeatNumber() const;
  double getFarePaid() const;
  string getBookingStatus() const;
  string getBookingDate() const;

  // Setter
  void setBookingStatus(string status);

  // Compare two tickets by ticket ID (replaces operator==)
  bool isSameTicket(const Ticket &other) const;

  // Display ticket info (replaces operator<<)
  void display() const;

  // Save to file
  string toFileString() const;
};

#endif

// OPERATOR OVERLOADING: << prints ticket to output stream
friend ostream &operator<<(ostream &os, const Ticket &t);

// Save to file
string toFileString() const;
}
;

#endif
