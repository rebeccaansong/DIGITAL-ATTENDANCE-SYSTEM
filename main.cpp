#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* ============================
   STUDENT MANAGEMENT
   ============================ */

void registerStudent() {
    ofstream file("students.txt", ios::app);

    string name;
    string index;

    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, name);

    cout << "Enter index number: ";
    getline(cin, index);

    file << name << "," << index << endl;
    file.close();

    cout << "Student registered successfully!" << endl;
}

void viewStudents() {
    ifstream file("students.txt");

    string name;
    string index;

    cout << "\n--- Registered Students ---" << endl;

    while (getline(file, name, ',') && getline(file, index)) {
        cout << "Name: " << name << " | Index: " << index << endl;
    }

    file.close();
}

void searchStudent() {
    ifstream file("students.txt");

    string name;
    string index;
    string searchIndex;
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
        cout << "Student not found." << endl;

    file.close();
}

/* ============================
   SESSION CREATION
   ============================ */

void createSession() {
    string courseCode;
    string date;
    string time;
    int duration;

    cout << "Enter course code: ";
    cin >> courseCode;

    cout << "Enter date (YYYY_MM_DD): ";
    cin >> date;

    cout << "Enter start time: ";
    cin >> time;

    cout << "Enter duration (minutes): ";
    cin >> duration;

    string filename = "session_" + courseCode + "_" + date + ".txt";

    ofstream file(filename.c_str());

    file << "Course Code: " << courseCode << endl;
    file << "Date: " << date << endl;
    file << "Start Time: " << time << endl;
    file << "Duration: " << duration << endl;
    file << "--------------------------" << endl;

    file.close();

    cout << "Session created successfully!" << endl;
}

/* ============================
   WEEK 3 - ATTENDANCE
   ============================ */

void markAttendance() {
    string courseCode;
    string date;

    cout << "Enter course code: ";
    cin >> courseCode;

    cout << "Enter date (YYYY_MM_DD): ";
    cin >> date;

    string filename = "session_" + courseCode + "_" + date + ".txt";

    ofstream file(filename.c_str(), ios::app);
    ifstream studentFile("students.txt");

    if (!studentFile) {
        cout << "No students registered." << endl;
        return;
    }

    string name;
    string index;
    string status;

    while (getline(studentFile, name, ',') && getline(studentFile, index)) {

        cout << "Mark attendance for " << name
             << " (Present/Absent/Late): ";
        cin >> status;

        while (status != "Present" &&
               status != "Absent" &&
               status != "Late") {
            cout << "Invalid input. Enter Present/Absent/Late: ";
            cin >> status;
        }

        file << name << "," << index << "," << status << endl;
    }

    file.close();
    studentFile.close();

    cout << "Attendance recorded successfully." << endl;
}

void displayAttendance() {
    string courseCode;
    string date;

    cout << "Enter course code: ";
    cin >> courseCode;

    cout << "Enter date (YYYY_MM_DD): ";
    cin >> date;

    string filename = "session_" + courseCode + "_" + date + ".txt";

    ifstream file(filename.c_str());

    if (!file) {
        cout << "Session file not found." << endl;
        return;
    }

    string line;

    cout << "\n--- Attendance List ---" << endl;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void attendanceSummary() {
    string courseCode;
    string date;

    cout << "Enter course code: ";
    cin >> courseCode;

    cout << "Enter date (YYYY_MM_DD): ";
    cin >> date;

    string filename = "session_" + courseCode + "_" + date + ".txt";

    ifstream file(filename.c_str());

    if (!file) {
        cout << "Session file not found." << endl;
        return;
    }

    string line;
    int present = 0;
    int absent = 0;
    int late = 0;

    while (getline(file, line)) {
        if (line.find("Present") != string::npos)
            present++;
        else if (line.find("Absent") != string::npos)
            absent++;
        else if (line.find("Late") != string::npos)
            late++;
    }

    cout << "\n--- Attendance Summary ---" << endl;
    cout << "Present: " << present << endl;
    cout << "Absent: " << absent << endl;
    cout << "Late: " << late << endl;

    file.close();
}

/* ============================
   MAIN MENU
   ============================ */

int main() {

    int choice;

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Create Lecture Session" << endl;
        cout << "5. Mark Attendance" << endl;
        cout << "6. Display Attendance" << endl;
        cout << "7. Attendance Summary" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: registerStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: createSession(); break;
            case 5: markAttendance(); break;
            case 6: displayAttendance(); break;
            case 7: attendanceSummary(); break;
            case 8: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice." << endl;
        }

    } while(choice != 8);

    return 0;
}

