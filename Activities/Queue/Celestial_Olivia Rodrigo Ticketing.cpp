#include <iostream>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <thread>
#include <chrono>

using namespace std;

struct Person {
    string name;
    int ticket_number;
};

string toLower(const string &str) {
    string lower_str = str;
    transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

class TicketingSystem {
private:
    queue<Person> q;
    int ticket_counter = 1;
    unordered_map<string, int> position_map;
    bool stop_dequeueing = false;

public:
    void Enqueue(const string &name) {
        Person person = {name, ticket_counter++};
        q.push(person);
        position_map[toLower(name)] = q.size();

        cout << name << " added to the queue with Ticket #" 
             << setw(3) << setfill('0') << person.ticket_number << endl
             << "Queue size: " << q.size() << endl;
    }

    void Dequeue() {
        if (q.empty()) {
            cout << "Queue is empty.\n";
            return;
        }

        Person frontPerson = q.front();
        q.pop();
        position_map.erase(toLower(frontPerson.name));

        cout << "Dequeue: " << frontPerson.name 
             << " received a ticket (Ticket #" 
             << setw(3) << setfill('0') << frontPerson.ticket_number << ")\n"
             << "Queue size: " << q.size() << endl;

        if (!q.empty()) {
            Person nextPerson = q.front();
            cout << "Next in line: " << nextPerson.name 
                 << " (Ticket #" << setw(3) << setfill('0') 
                 << nextPerson.ticket_number << ")\n";
        } else {
            cout << "No one is next in line.\n";
        }
    }

    void AutomaticDequeue() {
        while (!stop_dequeueing) {
            this_thread::sleep_for(chrono::seconds(60));
            if (!q.empty()) {
                Dequeue();
            } else {
                cout << "Queue is empty. Waiting for more people to enqueue...\n";
            }
        }
    }

    void Position(const string &name_or_ticket) const {
        string lower_input = toLower(name_or_ticket);
        if (position_map.count(lower_input)) {
            cout << name_or_ticket << " is currently at position " 
                 << position_map.at(lower_input) << " in the queue.\n";
        } else {
            cout << "No person with the given name or ticket number found in the queue.\n";
        }
    }

    void DisplayMenu() const {
        cout << "\nWelcome to Olivia Rodrigo's Concert Ticketing System!\n"
             << "1. Enqueue a person\n"
             << "2. Check your position in the queue\n"
             << "3. Exit\n";
    }


    void StopDequeueing() {
        stop_dequeueing = true;
    }
};

int main() {
    TicketingSystem system;
    thread dequeueThread(&TicketingSystem::AutomaticDequeue, &system);

    int choice;
    string name_or_ticket;

    while (true) {
        system.DisplayMenu();
        cout << "\nChoose an option: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            cout << "Enter the name: ";
            getline(cin, name_or_ticket);
            system.Enqueue(name_or_ticket);
        } else if (choice == 2) {
            cout << "Enter your name or ticket number: ";
            getline(cin, name_or_ticket);
            system.Position(name_or_ticket);
        } else if (choice == 3) {
            cout << "Exiting the system. Thank you!\n";
            system.StopDequeueing();
            dequeueThread.join();
            break;
        } else {
            cout << "Invalid option. Please choose again.\n";
        }
    }

    return 0;
}
