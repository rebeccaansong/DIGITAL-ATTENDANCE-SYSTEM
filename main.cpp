#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* ============================
   STUDENT MANAGEMENT - WEEK 1
   ============================ */

void registerStudent() {
    ofstream file("students.txt", ios::app);

    string name, index;

    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter index number: ";
    getline(cin, index);

    file << name << "," << index << endl;
    file.close();

    cout << "Student registered successfully!\n";
}

void viewStudents() {
    ifstream file("students.txt");
    string name, index;

    cout << "\n--- Registered Students ---\n";

    while (getline(file, name, ',') && getline(file, index)) {
        cout << "Name: " << name << " | Index: " << index << endl;
    }

    file.close();
}

void searchStudent() {
    ifstream file("students.txt");
    string name, index, searchIndex;
    bool found = false;

    cout << "Enter index number to search: ";
    cin >> searchIndex;

    while (getline(file, name, ',') && getline(file, index)) {
        if (index == searchIndex) {
            cout << "Student Found: " << name << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found.\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: registerStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while(choice != 4);

    return 0;
}

