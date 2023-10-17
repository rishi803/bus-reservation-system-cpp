#ifndef TICKET_H           // security guard
#define TICKET_H            

#include <iostream>
#include<string>

using namespace std;

// CLASS TICKET
class Ticket
{
private:
    string name, pnrNo, date;

public:
    void generateTicket();
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
    void setName(char *n)
    {
        if (n && n[0])
           name= n;
    }
};
#endif // !TICKET_H