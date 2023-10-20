#ifndef TICKET_H           // security guard
#define TICKET_H            

#include <iostream>
#include<string>

#include "bus.h"

using namespace std;

// CLASS TICKET
class Ticket
{
private:
    string name, pnrNo, date;
    Bus bus;

public:
    void generateTicket(string, Bus);
    void displayTicket();
    void bookTicket();
    void cancelTicket();
    void editTicket();
    void showTicketsByPNR();
    void showTicketsByName();
    void showTiscketByBus();
    void showTicketsBySource();
    void showTicketsByDestination();
    void showAllTickets();

    // GETTERS
    string getName()
    {
        return name;
    }

    string getPnrNo()
    {
        return pnrNo;
    }

    string getDate()
    {
        return date;
    }

    // SETTERS
    void setName(string &n)
    {
        // if (n && n[0])
           name= n;
    }
};
#endif // !TICKET_H