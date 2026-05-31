#include "../include/CharterFlight.h"
#include <iomanip>

using namespace std;

CharterFlight::CharterFlight(string fNum, string orig, string dest, string date,
                             string time, int total, int available,
                             string holder, double price)
    : Flight(fNum, orig, dest, date, time, total, available),
      contractHolder(holder), contractPrice(price) {}

CharterFlight::~CharterFlight() {}

// Charter fare = total contract price divided equally among all seats
double CharterFlight::calculateBaseFare() const {
    if (totalSeats == 0) return 0.0;
    return contractPrice / totalSeats;
}

void CharterFlight::displayDetails() const {
    cout << "=== CHARTER FLIGHT ===" << endl;
    cout << "Flight Number   : " << getFlightNumber() << endl;
    cout << "Route           : " << getOrigin() << " -> " << getDestination() << endl;
    cout << "Date & Time     : " << getDepartureDate() << " at " << getDepartureTime() << endl;
    cout << "Contract Holder : " << contractHolder << endl;
    cout << "Contract Price  : $" << fixed << setprecision(2) << contractPrice << endl;
    cout << "Seats           : " << getAvailableSeats() << "/" << getTotalSeats() << " available" << endl;
    cout << "Fare Per Seat   : $" << fixed << setprecision(2) << calculateBaseFare() << endl;
    cout << "========================" << endl;
}

string CharterFlight::getFlightType() const {
    return "Charter";
}

string CharterFlight::getContractHolder() const {
    return contractHolder;
}

double CharterFlight::getContractPrice() const {
    return contractPrice;
}

string CharterFlight::toFileString() const {
    // Format: Charter,fNum,orig,dest,date,time,total,avail,holder,price
    return "Charter," + Flight::toFileString() + "," +
           contractHolder + "," + to_string(contractPrice);
}
