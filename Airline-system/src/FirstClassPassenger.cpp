#include "../include/FirstClassPassenger.h"

using namespace std;

FirstClassPassenger::FirstClassPassenger(string id, string n, string ph, string em)
    : Passenger(id, n, ph, em) {}

FirstClassPassenger::~FirstClassPassenger() {}

double FirstClassPassenger::getBaggageAllowance() const {
    return 50.0; // 50 kg for first class
}

double FirstClassPassenger::getLoyaltyMultiplier() const {
    return 2.0; // 2.0x multiplier (best rate)
}

double FirstClassPassenger::getRefundPercentage() const {
    return 90.0; // 90% refund on cancellation
}

string FirstClassPassenger::getPassengerType() const {
    return "FirstClass";
}

void FirstClassPassenger::displayInfo() const {
    cout << "=== FIRST CLASS PASSENGER ===" << endl;
    Passenger::displayInfo(); // call base class display
    cout << "Baggage       : " << getBaggageAllowance() << " kg" << endl;
    cout << "Refund Rate   : " << getRefundPercentage() << "%" << endl;
    cout << "==============================" << endl;
}
