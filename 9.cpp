#include <iostream>
using namespace std;
struct Seat
{
    int seatNumber;
    bool booked;
    Seat *next;
    Seat *prev;
};
class SeatRow
{
private:
    Seat *head;

public:
    SeatRow(int seatsPerRow)
    {
        head = nullptr;
        for (int i = 1; i <= seatsPerRow; ++i)
        {
            addSeat(i);
        }
    }
    void addSeat(int seatNumber)
    {
        Seat *newSeat = new Seat;
        newSeat->seatNumber = seatNumber;
        newSeat->booked = false;
        if (head == nullptr)
        {
            head = newSeat;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Seat *lastSeat = head->prev;
            lastSeat->next = newSeat;
            newSeat->prev = lastSeat;
            newSeat->next = head;
            head->prev = newSeat;
        }
    }
    void displayAvailableSeats()
    {
        Seat *current = head;
        cout << "Available seats in this row: ";
        do
        {
            if (!current->booked)
            {
                cout << current->seatNumber << " ";
            }
            current = current->next;
        } while (current != head);
        cout << endl;
    }
    void bookSeat(int seatNumber)
    {
        Seat *current = head;
        do
        {
            if (current->seatNumber == seatNumber && !current->booked)
            {
                current->booked = true;
                cout << "Seat " << seatNumber << " booked successfully!" << endl;
                return;
            }
            current = current->next;
        } while (current != head);
        cout << "Seat " << seatNumber << " not available or invalid seat number." << endl;
    }
    void cancelBooking(int seatNumber)
    {
        Seat *current = head;
        do
        {
            if (current->seatNumber == seatNumber && current->booked)
            {
                current->booked = false;
                cout << "Booking for seat " << seatNumber << " canceled successfully !" << endl;
                    return;
            }
            current = current->next;
        } while (current != head);
        cout << "Seat " << seatNumber << " not booked or invalid seat number." << endl;
    }
};
int main()
{
    const int numRows = 10;
    const int seatsPerRow = 7;
    SeatRow *rows[numRows];
    for (int i = 0; i < numRows; ++i)
    {
        rows[i] = new SeatRow(seatsPerRow);
    }
    int choice;
    do
    {
        cout << "\nCinemax Theater Ticket Booking System\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel booking\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < numRows; ++i)
            {
                rows[i]->displayAvailableSeats();
            }
            break;
        case 2:
            int row, seat;
            cout << "Enter row number and seat number to book: ";
            cin >> row >> seat;
            if (row >= 1 && row <= numRows && seat >= 1 && seat <= seatsPerRow)
            {
                rows[row - 1]->bookSeat(seat);
            }
            else
            {
                cout << "Invalid row or seat number!" << endl;
            }
            break;
        case 3:
            cout << "Enter row number and seat number to cancel booking: ";
            cin >> row >> seat;
            if (row >= 1 && row <= numRows && seat >= 1 && seat <= seatsPerRow)
            {
                rows[row - 1]->cancelBooking(seat);
            }
            else
            {
                cout << "Invalid row or seat number!" << endl;
            }
            break;
        case 0:
            cout << "Exiting program. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);
    for (int i = 0; i < numRows; ++i)
    {
        delete rows[i];
    }
    return 0;
}