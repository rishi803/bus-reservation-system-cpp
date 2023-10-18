#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "ticket.h"
#include "bus.h"
#include "utils.h"

using namespace std;

// GENERATE TICKET
void Ticket::generateTicket(string n, Bus b) {
    name = n;
    pnrNo = generatePNR(99999);
    date = getCurrentDate();
    bus = b;
}

// DISPLAY TICKET DETAILS
void Ticket::displayTicket()
{
    cout << "\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t\t\t Name:-> " << getName();
    cout << "\n\t\t\t\t\t\t\t\t\t\t PNR No:-> " << getPnrNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Bus No:-> " << bus.getBusNo();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Seat No.:-> " << bus.getBookedSeats();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Date:-> " << getDate();
    cout << "\n\t\t\t\t\t\t\t\t\t\t From:-> " << bus.getSource();
    cout << "\n\t\t\t\t\t\t\t\t\t\t To:-> " << bus.getDestination();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Source Time:-> " << bus.getSourceTime();
    cout << "\n\t\t\t\t\t\t\t\t\t\t Destination Time:-> " << bus.getDestinationTime();
    cout << fixed << setprecision(2);
    cout << "\n\t\t\t\t\t\t\t\t\t\t Bus Fare:-> " << bus.getBusFare();
    cout << "\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
    cout << "\n";
}

