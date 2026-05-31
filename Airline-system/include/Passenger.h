#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>

using namespace std;

// Base class for all passenger types
class Passenger {
protected:
  string passengerID;
  string name;
  string phone;
  string email;
  int loyaltyPoints;

public:
  Passenger(string id, string n, string ph, string em);
  virtual ~Passenger();

  // Pure virtual functions - different for each passenger class
  virtual double getBaggageAllowance() const = 0;  // in kg
  virtual double getLoyaltyMultiplier() const = 0; // points multiplier
  virtual double getRefundPercentage() const = 0;  // base refund %
  virtual string getPassengerType() const = 0;
  virtual void displayInfo() const;

  // Getters
  string getPassengerID() const;
  string getName() const;
  string getPhone() const;
  string getEmail() const;
  int getLoyaltyPoints() const;

  // Setter
  void addLoyaltyPoints(int points);

  // Save to file
  virtual string toFileString() const;
};

#endif

// Save to file
virtual string toFileString() const;
}
;

#endif
