
#include <iostream>
using namespace std;
class Deque
{
private:
    static const int MAX_SIZE = 10;
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Deque()
    {
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return front == -1 && rear == -1;
    }
    bool isFull()
    {
        return (rear + 1) % MAX_SIZE == front;
    }
    void insertFront(int element)
    {
        if (isFull())
        {
            cout << "Deque is full. Cannot insert at the front.\n";
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                front = (front - 1 + MAX_SIZE) % MAX_SIZE;
            }
            arr[front] = element;
            cout << "Inserted at the front: " << element << endl;
        }
    }
    void insertRear(int element)
    {
        if (isFull())
        {
            cout << "Deque is full. Cannot insert at the rear.\n";
        }
        else
        {
            if (isEmpty())
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % MAX_SIZE;
            }
            arr[rear] = element;
            cout << "Inserted at the rear: " << element << endl;
        }
    }
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot delete from the front.\n";
        }
        else
        {
            cout << "Deleted from the front: " << arr[front] << endl;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                front = (front + 1) % MAX_SIZE;
            }
        }
    }
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque is empty. Cannot delete from the rear.\n";
        }
        else
        {
            cout << "Deleted from the rear: " << arr[rear] << endl;
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
            }
        }
    }
    void displayDeque()
    {
        if (isEmpty())
        {
            cout << "Deque is empty.\n";
        }
        else
        {
            cout << "Deque elements: ";
            int i = front;
            while (true)
            {
                cout << arr[i] << " ";
                if (i == rear)
                {
                    break;
                }
                i = (i + 1) % MAX_SIZE;
            }
            cout << endl;
        }
    }
};
int main()
{
    Deque deque;
    int choice, element;
    do
    {
        cout << "\nDeque Simulation\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Deque\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to insert at the front: ";
            cin >> element;
            deque.insertFront(element);
            break;
        case 2:
            cout << "Enter the element to insert at the rear: ";
            cin >> element;
            deque.insertRear(element);
            break;
        case 3:
            deque.deleteFront();
            break;
        case 4:
            deque.deleteRear();
            break;
        case 5:
            deque.displayDeque();
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