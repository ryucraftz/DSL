#include <iostream>
#include <cstring>

using namespace std;

struct Node {
    int prn;
    char name[50];
    Node* next;
};

class PinnacleClub {
private:
    Node* president;
    Node* secretary;

public:
    PinnacleClub() {
        president = nullptr;
        secretary = nullptr;
    }

    void addMember(int prn, const char* name) {
        Node* newNode = new Node;
        newNode->prn = prn;
        strncpy(newNode->name, name, sizeof(newNode->name));
        newNode->next = nullptr;

        if (president == nullptr) {
            president = newNode;
            secretary = newNode;
        } else {
            secretary->next = newNode;
            secretary = newNode;
        }

        cout << "Member added successfully!" << endl;
    }

    void deleteMember(int prn) {
        Node* current = president;
        Node* previous = nullptr;

        while (current != nullptr && current->prn != prn) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Member not found!" << endl;
            return;
        }

        if (current == president) {
            president = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
        cout << "Member deleted successfully!" << endl;
    }

    int totalMembers() {
        int count = 0;
        Node* current = president;

        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    void displayMembers() {
        Node* current = president;
        cout << "Club Members:" << endl;

        while (current != nullptr) {
            cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
            current = current->next;
        }
    }

    void concatenateLists(PinnacleClub& otherClub) {
        if (president == nullptr) {
            president = otherClub.president;
            secretary = otherClub.secretary;
        } else {
            secretary->next = otherClub.president;
            secretary = otherClub.secretary;
        }

        otherClub.president = nullptr;
        otherClub.secretary = nullptr;
    }
};

int main() {
    PinnacleClub division1, division2;

    division1.addMember(101, "John");
    division1.addMember(102, "Alice");
    division1.addMember(103, "Bob");

    division2.addMember(201, "Charlie");
    division2.addMember(202, "David");
    division2.addMember(203, "Eva");

    cout << "Division 1:" << endl;
    division1.displayMembers();

    cout << "\nDivision 2:" << endl;
    division2.displayMembers();

    division1.concatenateLists(division2);

    cout << "\nAfter Concatenation:" << endl;
    division1.displayMembers();

    return 0;
}
