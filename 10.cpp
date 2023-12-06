#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct Appointment
{
    string startTime;
    string endTime;
    bool booked;
    Appointment *next;
};
class Schedule
{
private:
    Appointment *head;
    int minDuration;
    int maxDuration;

public:
    Schedule(string start, string end, int min, int max)
    {
        head = new Appointment{start, end, false, nullptr};
        minDuration = min;
        maxDuration = max;
        generateAppointments();
    }
    void displayFreeSlots()
    {
        Appointment *current = head;
        cout << "Free slots:\n";
        while (current != nullptr)
        {
            if (!current->booked)
            {
                cout << current->startTime << " - " << current->endTime << endl;
            }
            current = current->next;
        }
    }
    void bookAppointment(string startTime)
    {
        Appointment *current = head;
        while (current != nullptr)
        {
            if (!current->booked && current->startTime == startTime)
            {
                current->booked = true;
                cout << "Appointment booked for " << current->startTime << " - " << current->endTime << endl;
                return;
            }
            current = current->next;
        }
        cout << "Invalid or already booked time slot.\n";
    }
    void sortAppointments()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        Appointment *sortedList = nullptr;
        Appointment *current = head;
        while (current != nullptr)
        {
            Appointment *next = current->next;
            if (sortedList == nullptr || sortedList->startTime > current->startTime)
            {
                current->next = sortedList;
                sortedList = current;
            }
            else
            {
                Appointment *sortedCurrent = sortedList;
                while (sortedCurrent->next != nullptr && sortedCurrent->next -> startTime < current->startTime)
                {
                    sortedCurrent = sortedCurrent->next;
                }
                current->next = sortedCurrent->next;
                sortedCurrent->next = current;
            }
            current = next;
        }
        head = sortedList;
    }
    void cancelAppointment(string startTime)
    {
        Appointment *current = head;
        while (current != nullptr)
        {
            if (current->booked && current->startTime == startTime)
            {
                current->booked = false;
                cout << "Appointment canceled for " << current->startTime << " - " << current->endTime << endl;
                return;
            }
            current = current->next;
        }
        cout << "Invalid or already canceled time slot.\n";
    }

private:
    void generateAppointments()
    {
        Appointment *current = head;
        while (current != nullptr)
        {
            current->next = new Appointment{"", "", false, nullptr};
            current = current->next;
        }
        current = head;
        string currentTime = head->startTime;
        while (current->next != nullptr)
        {
            time_t t = time(0);
            struct tm *now = localtime(&t);
            int duration = rand() % (maxDuration - minDuration + 1) + minDuration;
            now->tm_hour = stoi(currentTime.substr(0, 2));
            now->tm_min = stoi(currentTime.substr(3, 2)) + duration;
            mktime(now);
            current->next->startTime = currentTime;
            current->next->endTime = (now->tm_hour < 10 ? "0" : "") + to_string(now -> tm_hour) + ":" +(now->tm_min < 10 ? "0" : "") + to_string(now -> tm_min);
            current = current->next;
            currentTime = current->endTime;
        }
    }
};
int main()
{
    srand(time(0));
    Schedule schedule("08:00", "18:00", 15, 60);
    int choice;
    string time;
    do
    {
        cout << "\nAppointment Schedule System\n";
        cout << "1. Display free slots\n";
        cout << "2. Book appointment\n";
        cout << "3. Sort appointments\n";
        cout << "4. Cancel appointment\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            schedule.displayFreeSlots();
            break;
        case 2:
            cout << "Enter the time you want to book (HH:MM): ";
            cin >> time;
            schedule.bookAppointment(time);
            break;
        case 3:
            schedule.sortAppointments();
            cout << "Appointments sorted based on time.\n";
            break;
        case 4:
            cout << "Enter the time you want to cancel (HH:MM): ";
            cin >> time;
            schedule.cancelAppointment(time);
            break;
        case 0:
            cout << "Exiting program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 0);
    return 0;
}