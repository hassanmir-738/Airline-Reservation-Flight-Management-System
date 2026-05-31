#include "../include/Airline.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

// ===================== CONSTRUCTOR / DESTRUCTOR =====================

Airline::Airline(string name)
    : airlineName(name), revenueCount(0), nextTicketID(1) {}

// Destructor - we must manually delete all raw pointers to avoid memory leaks
Airline::~Airline() {
  // Delete every Flight* we created with 'new'
  for (int i = 0; i < (int)flights.size(); i++) {
    delete flights[i];
  }
  flights.clear();

  // Delete every Passenger* we created with 'new'
  for (int i = 0; i < (int)passengers.size(); i++) {
    delete passengers[i];
  }
  passengers.clear();
}

// ===================== HELPER: TICKET ID GENERATOR =====================

string Airline::generateTicketID() {
  string id = "TKT";
  if (nextTicketID < 10)
    id += "00";
  else if (nextTicketID < 100)
    id += "0";
  id += to_string(nextTicketID);
  nextTicketID++;
  return id;
}

// ===================== HELPER: REVENUE STRUCT OPERATIONS =====================

// Find the index of a flight's revenue entry. Returns -1 if not found.
int Airline::findRevenueIndex(const string &flightNumber) const {
  for (int i = 0; i < revenueCount; i++) {
    if (revenueList[i].flightNumber == flightNumber) {
      return i;
    }
  }
  return -1; // not found
}

// Add a new revenue entry for a flight (initialised to $0.00)
void Airline::addRevenueEntry(const string &flightNumber) {
  if (revenueCount < 200) {
    revenueList[revenueCount].flightNumber = flightNumber;
    revenueList[revenueCount].totalRevenue = 0.0;
    revenueCount++;
  }
}

// ===================== FLIGHT MANAGEMENT =====================

void Airline::addFlight(Flight *flight) {
  // Check if a flight with this number already exists
  for (int i = 0; i < (int)flights.size(); i++) {
    if (flights[i]->getFlightNumber() == flight->getFlightNumber()) {
      cout << "Error: Flight " << flight->getFlightNumber()
           << " already exists!" << endl;
      delete flight; // avoid memory leak - we own this pointer
      return;
    }
  }

  flights.push_back(flight);
  addRevenueEntry(flight->getFlightNumber());
  cout << "Flight " << flight->getFlightNumber() << " added successfully!"
       << endl;
}

bool Airline::removeFlight(const string &flightNumber) {
  // First check: make sure no active tickets exist for this flight
  for (int i = 0; i < (int)tickets.size(); i++) {
    if (tickets[i].getFlightNumber() == flightNumber &&
        tickets[i].getBookingStatus() == "Booked") {
      cout << "Cannot remove flight " << flightNumber
           << ". Active bookings exist!" << endl;
      return false;
    }
  }

  // Find and remove the flight using a plain for-loop
  for (int i = 0; i < (int)flights.size(); i++) {
    if (flights[i]->getFlightNumber() == flightNumber) {
      delete flights[i]; // free the memory
      flights.erase(flights.begin() + i);
      cout << "Flight " << flightNumber << " removed successfully!" << endl;
      return true;
    }
  }

  cout << "Flight " << flightNumber << " not found!" << endl;
  return false;
}

// Search flights by flight number - results stored in the passed vector
void Airline::searchFlightsByNumber(const string &flightNum,
                                    vector<Flight *> &results) const {
  results.clear(); // make sure results starts empty
  for (int i = 0; i < (int)flights.size(); i++) {
    if (flights[i]->getFlightNumber() == flightNum) {
      results.push_back(flights[i]);
    }
  }
}

// Search flights by origin and destination
void Airline::searchFlightsByRoute(const string &origin, const string &dest,
                                   vector<Flight *> &results) const {
  results.clear();
  for (int i = 0; i < (int)flights.size(); i++) {
    if (flights[i]->getOrigin() == origin &&
        flights[i]->getDestination() == dest) {
      results.push_back(flights[i]);
    }
  }
}

// Search flights by departure date
void Airline::searchFlightsByDate(const string &date,
                                  vector<Flight *> &results) const {
  results.clear();
  for (int i = 0; i < (int)flights.size(); i++) {
    if (flights[i]->getDepartureDate() == date) {
      results.push_back(flights[i]);
    }
  }
}

// List all flights in the system
void Airline::listAllFlights() const {
  if (flights.empty()) {
    cout << "No flights available." << endl;
    return;
  }
  cout << "\n========== ALL FLIGHTS ==========" << endl;
  for (int i = 0; i < (int)flights.size(); i++) {
    flights[i]->displayDetails();
    cout << endl;
  }
}

// ===================== PASSENGER MANAGEMENT =====================

void Airline::registerPassenger(Passenger *passenger) {
  // Check if passenger ID already exists
  for (int i = 0; i < (int)passengers.size(); i++) {
    if (passengers[i]->getPassengerID() == passenger->getPassengerID()) {
      cout << "Error: Passenger " << passenger->getPassengerID()
           << " already registered!" << endl;
      delete passenger; // avoid memory leak
      return;
    }
  }
  passengers.push_back(passenger);
  cout << "Passenger " << passenger->getName() << " registered successfully!"
       << endl;
}

bool Airline::removePassenger(const string &passengerID) {
  // Check for active bookings first
  for (int i = 0; i < (int)tickets.size(); i++) {
    if (tickets[i].getPassengerID() == passengerID &&
        tickets[i].getBookingStatus() == "Booked") {
      cout << "Cannot remove passenger. Active bookings exist!" << endl;
      return false;
    }
  }

  // Find and remove the passenger using a plain for-loop
  for (int i = 0; i < (int)passengers.size(); i++) {
    if (passengers[i]->getPassengerID() == passengerID) {
      delete passengers[i]; // free the memory
      passengers.erase(passengers.begin() + i);
      cout << "Passenger " << passengerID << " removed successfully!" << endl;
      return true;
    }
  }

  cout << "Passenger " << passengerID << " not found!" << endl;
  return false;
}

void Airline::viewBookingHistory(const string &passengerID) const {
  cout << "\n=== Booking History for Passenger " << passengerID
       << " ===" << endl;
  bool found = false;
  for (int i = 0; i < (int)tickets.size(); i++) {
    if (tickets[i].getPassengerID() == passengerID) {
      tickets[i].display(); // use display() instead of operator<<
      found = true;
    }
  }
  if (!found) {
    cout << "No bookings found for this passenger." << endl;
  }
}

// Find a passenger by ID - returns raw pointer (nullptr if not found)
Passenger *Airline::findPassenger(const string &passengerID) const {
  for (int i = 0; i < (int)passengers.size(); i++) {
    if (passengers[i]->getPassengerID() == passengerID) {
      return passengers[i];
    }
  }
  return nullptr; // not found
}

// ===================== BOOKING =====================

void Airline::bookTicket(const string &passengerID, const string &flightNumber,
                         const string &currentDate) {
  // Step 1: Find the passenger
  Passenger *passenger = findPassenger(passengerID);
  if (passenger == nullptr) {
    cout << "Error: Passenger " << passengerID
         << " not found! Please register first." << endl;
    return;
  }

  // Step 2: Find the flight using a plain for-loop
  Flight *flight = nullptr;
  for (int i = 0; i < (int)flights.size(); i++) {
    if (flights[i]->getFlightNumber() == flightNumber) {
      flight = flights[i];
      break;
    }
  }
  if (flight == nullptr) {
    cout << "Error: Flight " << flightNumber << " not found!" << endl;
    return;
  }

  // Step 3: Check for duplicate booking (same passenger, same flight, still
  // active)
  for (int i = 0; i < (int)tickets.size(); i++) {
    if (tickets[i].getPassengerID() == passengerID &&
        tickets[i].getFlightNumber() == flightNumber &&
        tickets[i].getBookingStatus() == "Booked") {
      cout << "Error: Passenger " << passengerID
           << " already has a ticket on flight " << flightNumber << "!" << endl;
      return;
    }
  }

  // Step 4: Check if any seats are available
  if (flight->getAvailableSeats() <= 0) {
    cout << "Error: Flight " << flightNumber << " is full. No seats available!"
         << endl;
    return;
  }

  // Step 5: Calculate fare (uses virtual function - polymorphism)
  double fare = flight->calculateBaseFare();

  // Step 6: Book the seat (decreases availableSeats by 1)
  flight->bookSeat();

  // Step 7: Generate seat number (simple: seat row + "A")
  int seatRow = flight->getTotalSeats() - flight->getAvailableSeats();
  string seatNumber = to_string(seatRow) + "A";

  // Step 8: Create a new ticket
  string ticketID = generateTicketID();
  Ticket newTicket(ticketID, passengerID, flightNumber, seatNumber, fare,
                   "Booked", currentDate);
  tickets.push_back(newTicket);

  // Step 9: Update revenue for this flight
  int idx = findRevenueIndex(flightNumber);
  if (idx != -1) {
    revenueList[idx].totalRevenue += fare;
  }

  // Step 10: Award loyalty points to passenger (uses virtual function -
  // polymorphism)
  int points = (int)(fare * passenger->getLoyaltyMultiplier());
  passenger->addLoyaltyPoints(points);

  cout << "\nBooking Successful!" << endl;
  newTicket.display(); // use display() instead of operator<<
}

// ===================== CANCELLATION & REFUND =====================

void Airline::cancelTicket(const string &ticketID, const string &currentDate) {
  // Step 1: Find the ticket using a plain for-loop
  Ticket *foundTicket = nullptr;
  for (int i = 0; i < (int)tickets.size(); i++) {
    if (tickets[i].getTicketID() == ticketID) {
      foundTicket = &tickets[i];
      break;
    }
  }

  // Check if ticket was found
  if (foundTicket == nullptr) {
    cout << "Error: Ticket " << ticketID << " not found!" << endl;
    return;
  }

  // Check if already cancelled
  if (foundTicket->getBookingStatus() == "Cancelled") {
    cout << "Error: Ticket " << ticketID << " is already cancelled!" << endl;
    return;
  }

  // Step 2: Find the passenger to get their refund rate
  Passenger *passenger = findPassenger(foundTicket->getPassengerID());
  if (passenger == nullptr) {
    cout << "Error: Passenger not found for this ticket!" << endl;
    return;
  }

  // Step 3: Get refund percentage (uses virtual function - polymorphism)
  double refundPercent = passenger->getRefundPercentage();

  // Step 4: Find the flight to restore the seat and check departure date
  for (int i = 0; i < (int)flights.size(); i++) {
    if (flights[i]->getFlightNumber() == foundTicket->getFlightNumber()) {
      // Reduce refund if cancelling on the same day as departure
      if (flights[i]->getDepartureDate() == currentDate) {
        refundPercent = refundPercent * 0.5; // halve the refund
      }
      // Give back the seat
      flights[i]->cancelSeat();
      break;
    }
  }

  // Step 5: Calculate refund amount
  double refundAmount = foundTicket->getFarePaid() * (refundPercent / 100.0);

  // Step 6: Mark ticket as cancelled
  foundTicket->setBookingStatus("Cancelled");

  // Step 7: Deduct refund from revenue tracking
  int idx = findRevenueIndex(foundTicket->getFlightNumber());
  if (idx != -1) {
    revenueList[idx].totalRevenue -= refundAmount;
  }

  cout << "\nCancellation Successful!" << endl;
  cout << "Ticket ID    : " << ticketID << endl;
  cout << "Refund Rate  : " << refundPercent << "%" << endl;
  cout << "Refund Amount: $" << fixed << setprecision(2) << refundAmount
       << endl;
}

// ===================== REPORTS =====================

// Show all flights departing on a given date
void Airline::todaysDepartures(const string &today) const {
  cout << "\n========== TODAY'S DEPARTURES (" << today
       << ") ==========" << endl;
  bool found = false;
  for (int i = 0; i < (int)flights.size(); i++) {
    if (flights[i]->getDepartureDate() == today) {
      flights[i]->displayDetails();
      found = true;
    }
  }
  if (!found) {
    cout << "No flights departing today." << endl;
  }
}

// Show how full each flight is
void Airline::occupancyReport() const {
  cout << "\n========== OCCUPANCY REPORT ==========" << endl;
  cout << left << setw(12) << "Flight" << setw(22) << "Route" << setw(12)
       << "Date" << setw(10) << "Seats"
       << "Occupancy" << endl;
  cout << string(65, '-') << endl;

  for (int i = 0; i < (int)flights.size(); i++) {
    string route =
        flights[i]->getOrigin() + "->" + flights[i]->getDestination();
    int booked = flights[i]->getTotalSeats() - flights[i]->getAvailableSeats();
    string seats =
        to_string(booked) + "/" + to_string(flights[i]->getTotalSeats());

    cout << left << setw(12) << flights[i]->getFlightNumber() << setw(22)
         << route << setw(12) << flights[i]->getDepartureDate() << setw(10)
         << seats << fixed << setprecision(1)
         << flights[i]->getOccupancyPercentage() << "%" << endl;
  }
}

// Show top 5 flights by revenue - uses a simple selection sort approach
void Airline::topRevenueFlights() const {
  cout << "\n========== TOP 5 REVENUE FLIGHTS ==========" << endl;

  if (revenueCount == 0) {
    cout << "No revenue data available." << endl;
    return;
  }

  // Copy revenue data into a temporary local array for sorting
  RevenueEntry temp[200];
  for (int i = 0; i < revenueCount; i++) {
    temp[i] = revenueList[i];
  }

  // Simple bubble sort: sort by revenue in descending order
  for (int i = 0; i < revenueCount - 1; i++) {
    for (int j = 0; j < revenueCount - 1 - i; j++) {
      if (temp[j].totalRevenue < temp[j + 1].totalRevenue) {
        // Swap
        RevenueEntry swap = temp[j];
        temp[j] = temp[j + 1];
        temp[j + 1] = swap;
      }
    }
  }

  cout << left << setw(15) << "Flight" << "Revenue" << endl;
  cout << string(30, '-') << endl;

  int showCount = revenueCount;
  if (showCount > 5)
    showCount = 5; // cap at 5

  for (int i = 0; i < showCount; i++) {
    cout << left << setw(15) << temp[i].flightNumber << "$" << fixed
         << setprecision(2) << temp[i].totalRevenue << endl;
  }
}

// ===================== FILE PERSISTENCE =====================

void Airline::saveToFile(const string &filename) const {
  ofstream file(filename);
  if (!file.is_open()) {
    cout << "Error: Cannot open file for saving!" << endl;
    return;
  }

  // Save airline name and next ticket counter
  file << airlineName << endl;
  file << nextTicketID << endl;

  // Save flights
  file << flights.size() << endl;
  for (int i = 0; i < (int)flights.size(); i++) {
    file << flights[i]->toFileString() << endl;
  }

  // Save passengers
  file << passengers.size() << endl;
  for (int i = 0; i < (int)passengers.size(); i++) {
    file << passengers[i]->getPassengerType() << ","
         << passengers[i]->toFileString() << endl;
  }

  // Save tickets
  file << tickets.size() << endl;
  for (int i = 0; i < (int)tickets.size(); i++) {
    file << tickets[i].toFileString() << endl;
  }

  // Save revenue entries
  file << revenueCount << endl;
  for (int i = 0; i < revenueCount; i++) {
    file << revenueList[i].flightNumber << "," << revenueList[i].totalRevenue
         << endl;
  }

  file.close();
  cout << "Data saved successfully to " << filename << endl;
}

void Airline::loadFromFile(const string &filename) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "No saved data found. Starting fresh." << endl;
    return;
  }

  string line;

  // Read airline name
  getline(file, airlineName);

  // Read next ticket ID counter
  getline(file, line);
  nextTicketID = stoi(line);

  // Clear old data before loading
  for (int i = 0; i < (int)flights.size(); i++)
    delete flights[i];
  flights.clear();
  for (int i = 0; i < (int)passengers.size(); i++)
    delete passengers[i];
  passengers.clear();
  tickets.clear();
  revenueCount = 0;

  // --- Load Flights ---
  getline(file, line);
  int flightCount = stoi(line);

  for (int i = 0; i < flightCount; i++) {
    getline(file, line);
    stringstream ss(line);
    string type, fNum, orig, dest, date, time, totalStr, availStr;

    getline(ss, type, ',');
    getline(ss, fNum, ',');
    getline(ss, orig, ',');
    getline(ss, dest, ',');
    getline(ss, date, ',');
    getline(ss, time, ',');
    getline(ss, totalStr, ',');
    getline(ss, availStr, ',');

    int total = stoi(totalStr);
    int avail = stoi(availStr);

    if (type == "Domestic") {
      string region;
      getline(ss, region);
      flights.push_back(new DomesticFlight(fNum, orig, dest, date, time, total,
                                           avail, region));
    } else if (type == "International") {
      string visaStr, country;
      getline(ss, visaStr, ',');
      getline(ss, country);
      bool visa = (visaStr == "1");
      flights.push_back(new InternationalFlight(fNum, orig, dest, date, time,
                                                total, avail, visa, country));
    } else if (type == "Charter") {
      string holder, priceStr;
      getline(ss, holder, ',');
      getline(ss, priceStr);
      double price = stod(priceStr);
      flights.push_back(new CharterFlight(fNum, orig, dest, date, time, total,
                                          avail, holder, price));
    }
    // Add revenue entry for every loaded flight
    addRevenueEntry(fNum);
  }

  // --- Load Passengers ---
  getline(file, line);
  int passengerCount = stoi(line);

  for (int i = 0; i < passengerCount; i++) {
    getline(file, line);
    stringstream ss(line);
    string type, id, name, phone, email, pointsStr;

    getline(ss, type, ',');
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, phone, ',');
    getline(ss, email, ',');
    getline(ss, pointsStr);

    Passenger *p = nullptr;
    if (type == "Economy") {
      p = new EconomyPassenger(id, name, phone, email);
    } else if (type == "Business") {
      p = new BusinessPassenger(id, name, phone, email);
    } else if (type == "FirstClass") {
      p = new FirstClassPassenger(id, name, phone, email);
    }

    if (p != nullptr) {
      p->addLoyaltyPoints(stoi(pointsStr));
      passengers.push_back(p);
    }
  }

  // --- Load Tickets ---
  getline(file, line);
  int ticketCount = stoi(line);

  for (int i = 0; i < ticketCount; i++) {
    getline(file, line);
    stringstream ss(line);
    string tID, pID, fNum, seat, fareStr, status, bDate;

    getline(ss, tID, ',');
    getline(ss, pID, ',');
    getline(ss, fNum, ',');
    getline(ss, seat, ',');
    getline(ss, fareStr, ',');
    getline(ss, status, ',');
    getline(ss, bDate);

    double fare = stod(fareStr);
    tickets.push_back(Ticket(tID, pID, fNum, seat, fare, status, bDate));
  }

  // --- Load Revenue Entries ---
  getline(file, line);
  int revCount = stoi(line);

  for (int i = 0; i < revCount; i++) {
    getline(file, line);
    stringstream ss(line);
    string fNum, revStr;
    getline(ss, fNum, ',');
    getline(ss, revStr);

    // Find existing entry and update it
    int idx = findRevenueIndex(fNum);
    if (idx != -1) {
      revenueList[idx].totalRevenue = stod(revStr);
    }
  }

  file.close();
  cout << "Data loaded successfully from " << filename << endl;
}

// ===================== GETTERS =====================

const vector<Flight *> &Airline::getFlights() const { return flights; }
const vector<Passenger *> &Airline::getPassengers() const { return passengers; }
const vector<Ticket> &Airline::getTickets() const { return tickets; }
