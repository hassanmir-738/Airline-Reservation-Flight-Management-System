#include "../include/Passenger.h"

using namespace std;

// Constructor - initialise all member variables
Passenger::Passenger(string id, string n, string ph, string em)
    : passengerID(id), name(n), phone(ph), email(em), loyaltyPoints(0) {}

// Virtual destructor
Passenger::~Passenger() {}

// Display basic passenger info
void Passenger::displayInfo() const {
  cout << "Passenger ID  : " << passengerID << endl;
  cout << "Name          : " << name << endl;
  cout << "Phone         : " << phone << endl;
  cout << "Email         : " << email << endl;
  cout << "Loyalty Points: " << loyaltyPoints << endl;
}

// Getters
string Passenger::getPassengerID() const { return passengerID; }
string Passenger::getName() const { return name; }
string Passenger::getPhone() const { return phone; }
string Passenger::getEmail() const { return email; }
int Passenger::getLoyaltyPoints() const { return loyaltyPoints; }

// Add loyalty points (called after a booking)
void Passenger::addLoyaltyPoints(int points) { loyaltyPoints += points; }

// Save to file string
string Passenger::toFileString() const {
  return passengerID + "," + name + "," + phone + "," + email + "," +
         to_string(loyaltyPoints);
}
}
}

// Save to file string
string Passenger::toFileString() const {
  return passengerID + "," + name + "," + phone + "," + email + "," +
         to_string(loyaltyPoints);
}
