#include <iostream>
#include <queue>
using namespace std;
class JobQueue
{
private:
    queue<string> jobs;

public:
    void addJob(const string &job)
    {
        jobs.push(job);
        cout << "Job added to the queue: " << job << endl;
    }
    void deleteJob()
    {
        if (!jobs.empty())
        {
            cout << "Job deleted from the queue: " << jobs.front() << endl;
            jobs.pop();
        }
        else
        {
            cout << "Queue is empty. No job to delete." << endl;
        }
    }
    void displayJobs()
    {
        if (!jobs.empty())
        {
            cout << "Current jobs in the queue:\n";
            queue<string> tempQueue = jobs;
            while (!tempQueue.empty())
            {
                cout << tempQueue.front() << endl;
                tempQueue.pop();
            }
        }
        else
        {
            cout << "Queue is empty. No jobs to display." << endl;
        }
    }
};
int main()
{
    JobQueue jobQueue;
    int choice;
    string job;
    do
    {
        cout << "\nJob Queue Simulation\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the job name: ";
            cin >> job;
            jobQueue.addJob(job);
            break;
        case 2:
            jobQueue.deleteJob();
            break;
        case 3:
            jobQueue.displayJobs();
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