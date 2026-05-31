#include "../include/Ticket.h"
#include <iomanip>

using namespace std;

Ticket::Ticket(string tID, string pID, string fNum, string seat, double fare,
               string status, string bDate)
    : ticketID(tID), passengerID(pID), flightNumber(fNum), seatNumber(seat),
      farePaid(fare), bookingStatus(status), bookingDate(bDate) {}

Ticket::~Ticket() {}

// Getters
string Ticket::getTicketID() const { return ticketID; }
string Ticket::getPassengerID() const { return passengerID; }
string Ticket::getFlightNumber() const { return flightNumber; }
string Ticket::getSeatNumber() const { return seatNumber; }
double Ticket::getFarePaid() const { return farePaid; }
string Ticket::getBookingStatus() const { return bookingStatus; }
string Ticket::getBookingDate() const { return bookingDate; }

// Setter
void Ticket::setBookingStatus(string status) { bookingStatus = status; }

// Compare two tickets by their ID (replaces operator==)
bool Ticket::isSameTicket(const Ticket &other) const {
  return ticketID == other.ticketID;
}

// Display ticket info (replaces operator<<)
void Ticket::display() const {
  cout << "--------------------------------------" << endl;
  cout << "Ticket ID     : " << ticketID << endl;
  cout << "Passenger ID  : " << passengerID << endl;
  cout << "Flight Number : " << flightNumber << endl;
  cout << "Seat Number   : " << seatNumber << endl;
  cout << "Fare Paid     : $" << fixed << setprecision(2) << farePaid << endl;
  cout << "Status        : " << bookingStatus << endl;
  cout << "Booking Date  : " << bookingDate << endl;
  cout << "--------------------------------------" << endl;
}

// Save to file string
string Ticket::toFileString() const {
  return ticketID + "," + passengerID + "," + flightNumber + "," + seatNumber +
         "," + to_string(farePaid) + "," + bookingStatus + "," + bookingDate;
}
}

ostream &operator<<(ostream &os, const Ticket &t) {
  os << "--------------------------------------" << endl;
  os << "Ticket ID     : " << t.ticketID << endl;
  os << "Passenger ID  : " << t.passengerID << endl;
  os << "Flight Number : " << t.flightNumber << endl;
  os << "Seat Number   : " << t.seatNumber << endl;
  os << "Fare Paid     : $" << fixed << setprecision(2) << t.farePaid << endl;
  os << "Status        : " << t.bookingStatus << endl;
  os << "Booking Date  : " << t.bookingDate << endl;
  os << "--------------------------------------" << endl;
  return os;
}

// Save to file string
string Ticket::toFileString() const {
  return ticketID + "," + passengerID + "," + flightNumber + "," + seatNumber +
         "," + to_string(farePaid) + "," + bookingStatus + "," + bookingDate;
}
