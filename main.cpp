#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

// ================= STUDENT =================
struct Student {
    string name;
    string indexNumber;
};

// ================= ATTENDANCE RECORD =================
struct AttendanceRecord {
    string indexNumber;
    string name;
    char status; // P, A, L
};

// ================= SESSION =================
struct AttendanceSession {
    string courseCode;
    string date;
    string startTime;
    int duration;
    vector<AttendanceRecord> records;
};

// ================= GLOBAL DATA =================
vector<Student> students;
AttendanceSession session;

// ================= STUDENT FUNCTIONS =================
void registerStudent() {
    Student s;
    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter index number: ";
    getline(cin, s.indexNumber);

    students.push_back(s);
    cout << "Student registered successfully!\n";
}

void viewStudents() {
    cout << "\n===== STUDENT LIST =====\n";
    for (int i = 0; i < students.size(); i++) {
        cout << i + 1 << ". " << students[i].name 
             << " (" << students[i].indexNumber << ")\n";
    }
}

void searchStudent() {
    string searchIndex;
    cout << "Enter index number to search: ";
    cin >> searchIndex;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].indexNumber == searchIndex) {
            cout << "Found: " << students[i].name << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}

// ================= SESSION FUNCTIONS =================
void createSession() {
    cout << "\nEnter Course Code: ";
    cin >> session.courseCode;
    cout << "Enter Date (YYYY-MM-DD): ";
    cin >> session.date;
    cout << "Enter Start Time: ";
    cin >> session.startTime;
    cout << "Enter Duration (hours): ";
    cin >> session.duration;

    session.records.clear();

    for (int i = 0; i < students.size(); i++) {
        AttendanceRecord r;
        r.indexNumber = students[i].indexNumber;
        r.name = students[i].name;
        r.status = 'A'; // default absent
        session.records.push_back(r);
    }

    cout << "Session created successfully!\n";
}

// ================= MARK ATTENDANCE =================
void markAttendance() {
    cout << "\nMark Attendance (P=Present, A=Absent, L=Late)\n";

    for (int i = 0; i < session.records.size(); i++) {
        cout << session.records[i].name << ": ";
        cin >> session.records[i].status;
    }
}

// ================= REPORT =================
void showReport() {
    int present = 0, absent = 0, late = 0;

    cout << "\n===== ATTENDANCE REPORT =====\n";
    cout << "Course: " << session.courseCode << endl;
    cout << "Date: " << session.date << endl;

    cout << left << setw(15) << "Index" 
         << setw(20) << "Name" 
         << setw(10) << "Status" << endl;

    for (int i = 0; i < session.records.size(); i++) {
        cout << setw(15) << session.records[i].indexNumber
             << setw(20) << session.records[i].name
             << setw(10) << session.records[i].status << endl;

        if (session.records[i].status == 'P') present++;
        else if (session.records[i].status == 'A') absent++;
        else if (session.records[i].status == 'L') late++;
    }

    cout << "\nSummary:\n";
    cout << "Present: " << present << endl;
    cout << "Absent: " << absent << endl;
    cout << "Late: " << late << endl;
}

// ================= FILE SAVE =================
void saveStudents() {
    ofstream file("students.txt");

    for (int i = 0; i < students.size(); i++) {
        file << students[i].indexNumber << "," << students[i].name << endl;
    }

    file.close();
    cout << "Students saved to file.\n";
}

void loadStudents() {
    ifstream file("students.txt");

    if (!file) return;

    students.clear();

    string index, name;
    while (getline(file, index, ',') && getline(file, name)) {
        Student s;
        s.name = name;
        s.indexNumber = index;
        students.push_back(s);
    }

    file.close();
}

// ================= SAVE SESSION =================
void saveSession() {
    string filename = "session_" + session.courseCode + "_" + session.date + ".txt";
    ofstream file(filename.c_str());

    file << session.courseCode << "," << session.date << "," 
         << session.startTime << "," << session.duration << endl;

    for (int i = 0; i < session.records.size(); i++) {
        file << session.records[i].indexNumber << ","
             << session.records[i].name << ","
             << session.records[i].status << endl;
    }

    file.close();
    cout << "Session saved to file.\n";
}

// ================= EXPORT TO EXCEL =================
void exportToCSV() {
    ofstream file("attendance.csv");

    file << "Course,Date,IndexNumber,Name,Status\n";

    for (int i = 0; i < session.records.size(); i++) {
        file << session.courseCode << ","
             << session.date << ","
             << session.records[i].indexNumber << ","
             << session.records[i].name << ","
             << session.records[i].status << endl;
    }

    file.close();
    cout << "Exported to attendance.csv (Open with Excel)\n";
}

// ================= MAIN =================
int main() {
    loadStudents();

    int choice;

    do {
        cout << "\n====== DIGITAL ATTENDANCE SYSTEM ======\n";
        cout << "1. Register Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Create Session\n";
        cout << "5. Mark Attendance\n";
        cout << "6. Show Report\n";
        cout << "7. Save Students\n";
        cout << "8. Save Session\n";
        cout << "9. Export to Excel\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: registerStudent(); break;
        case 2: viewStudents(); break;
        case 3: searchStudent(); break;
        case 4: createSession(); break;
        case 5: markAttendance(); break;
        case 6: showReport(); break;
        case 7: saveStudents(); break;
        case 8: saveSession(); break;
        case 9: exportToCSV(); break;
        }

    } while (choice != 0);

    return 0;
}
