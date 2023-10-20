#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <algorithm> // For std::transform

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

// BOOK TICKET
void Ticket::bookTicket()
{
    system("cls");

    string from, to;
    int chk = 0;

    Bus b;
    fstream busFileStream, ticketFileStream, tempFileStream;

    printHeading("BOOK TICKET");

    busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
    if (!busFileStream)
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Source:-> ";
        cin.ignore();
        getline(cin,from);
        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Destination:-> ";
        getline(cin,to);

        system("cls");
        printHeading("AVAILABLE BUSES");

        busFileStream.read((char *)&b, sizeof(b));
        while (!busFileStream.eof())
        {
             string user_from = b.getSource();
            string user_to = b.getDestination();

    // Convert both strings to lowercase
    transform(user_from.begin(), user_from.end(), user_from.begin(), ::tolower);
    transform(user_to.begin(), user_to.end(), user_to.begin(), ::tolower);

            if ((user_from == from) && (user_to == to) )
            {
                b.showBusDetails();
                chk = 1;
            }
            busFileStream.read((char *)&b, sizeof(b));
        }

        busFileStream.close();

        if (chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Buses Found...!!\n";
        }
        else
        {
            string bNo;
            int booked = 0;

            cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
            getline(cin,bNo);

            busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
            tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

            busFileStream.read((char *)&b, sizeof(b));
            while (!busFileStream.eof())
            {
                string user_from = b.getSource();
            string user_to = b.getDestination();

    // Convert both strings to lowercase
    transform(user_from.begin(), user_from.end(), user_from.begin(), ::tolower);
    transform(user_to.begin(), user_to.end(), user_to.begin(), ::tolower);

                if ((user_from == from) && (user_to == to) && (b.getBusNo() == bNo) )
                {
                    if (b.getBookedSeats() >= 32)
                    {
                        cout << "\n\t\t\t\t\t\t\t\t\t\tSeat not available...!!\n";
                        break;
                    }
                    else
                    {
                        system("cls");
                        printHeading("BOOK TICKET");
                        string n;
                        cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Customer Name :-> ";
                        getline(cin,n);
                        b.setBookedSeats();
                        generateTicket(n, b);
                        ticketFileStream.open("tickets.dat", ios::out | ios::app | ios::binary);
                        ticketFileStream.write((char *)this, sizeof(*this));
                        ticketFileStream.close();
                        tempFileStream.write((char *)&b, sizeof(b));

                        booked = 1;
                        system("cls");
                        printHeading("BOOKING DETAILS");
                        displayTicket();
                        cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Booked Successfully...!!\n";
                    }
                }
                else
                {
                    tempFileStream.write((char *)&b, sizeof(b));
                }
                busFileStream.read((char *)&b, sizeof(b));
            }

            if (booked == 1)
            {
                busFileStream.close();
                tempFileStream.close();
                remove("buses.dat");
                rename("temp.dat", "buses.dat");
            }
        }
        busFileStream.close();
    }
}

// CANCEL TICKET
void Ticket::cancelTicket()
{
    system("cls");

    string pnr;
    int chk = 0;

    fstream busFileStream, ticketFileStream, tempFileStream, busTempFileStream;

    printHeading("CANCEL TICKET");
    cout << "\n\t\t\t\t\t\t\t\t\t\tEnter PNR Number:-> ";
    cin.ignore();
    getline(cin,pnr);

    ticketFileStream.open("tickets.dat", ios::in | ios::app | ios::binary);
    tempFileStream.open("temp.dat", ios::out | ios::app | ios::binary);

    if (!ticketFileStream)
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!\n";
    }

    else
    {
        ticketFileStream.read((char *)this, sizeof(*this));
        while (!ticketFileStream.eof())
        {
            if ((getPnrNo() != pnr))
            {
                tempFileStream.write((char *)this, sizeof(*this));
            }
            else
            {
                Bus b;
                busFileStream.open("buses.dat", ios::in | ios::app | ios::binary);
                busTempFileStream.open("bustemp.dat", ios::out | ios::app | ios::binary);

                busFileStream.read((char *)&b, sizeof(b));
                while (!busFileStream.eof())
                {
                    if ((b.getBusNo() == bus.getBusNo()))
                    {
                        b.setCancelTicket();
                        busTempFileStream.write((char *)&b, sizeof(b));
                    }
                    else
                    {
                        busTempFileStream.write((char *)&b, sizeof(b));
                    }
                    busFileStream.read((char *)&b, sizeof(b));
                }
                busFileStream.close();
                busTempFileStream.close();
                remove("buses.dat");
                rename("bustemp.dat", "buses.dat");
                chk = 1;
            }
            ticketFileStream.read((char *)this, sizeof(*this));
        }
        if (chk == 0)
        {
            ticketFileStream.close();
            tempFileStream.close();
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Not Found...!!\n";
        }
        else
        {
            ticketFileStream.close();
            tempFileStream.close();
            remove("tickets.dat");
            rename("temp.dat", "tickets.dat");
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Cancelled...!!\n";
        }
    }
}