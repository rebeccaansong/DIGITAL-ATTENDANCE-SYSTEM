DIGITAL ATTENDANCE SYSTEM
Course: EEE227 – Introduction to C++ Programming
Programme: HND Electrical Engineering (Level 200)
Assessment Type: Mid-Semester Capstone Project


PROJECT DESCRIPTION

This project is a console-based Digital Attendance System developed using C++.

The system replaces the traditional paper-based attendance system used in lecture halls. 
It allows students to be registered, lecture sessions to be created, attendance to be marked, 
and attendance reports to be generated.

The program runs offline on Windows and stores data using text files to ensure persistence.


OBJECTIVES

- Apply C++ programming concepts to solve a real-world problem
- Use file handling (fstream) for data storage
- Design a menu-driven console application
- Practice version control using GitHub
- Implement structured and readable C++ code


DEVELOPMENT TOOLS

Programming Language: C++
Development Environment: Dev C++ / VS Code
Platform: Windows (Offline)
File Handling: fstream
Version Control: GitHub


PROJECT STRUCTURE

digital-attendance-system/
│── main.cpp
│── README.md
│── students.txt
│── session_courseCode_date.txt


FEATURES IMPLEMENTED

1. Student Management
   - Register students
   - View registered students
   - Search students by index number

2. Lecture Session Management
   - Create lecture session (course code, date, start time, duration)
   - Automatically generates session file
   - Mark attendance (Present / Absent / Late)
   - Update attendance records

3. Reports and Summary
   - Display attendance list for a session
   - Display attendance summary (Present, Absent, Late counts)

4. File Storage
   - Students saved in students.txt
   - Each session saved as a separate file
   - Data persists after program is closed


HOW TO RUN THE PROGRAM

1. Open Dev C++ or VS Code
2. Open main.cpp
3. Compile the program
4. Run the executable
5. Use the menu options to interact with the system


WEEKLY PROGRESS SUMMARY

Week 1:
- Project setup
- Student registration feature
- View and search students

Week 2:
- Session creation feature
- Improved menu structure

Week 3:
- Attendance marking functionality
- Attendance display and summary
- Input validation improvement

Week 4:
- Update attendance feature
- File handling refinement
- Final testing and documentation


KEY C++ CONCEPTS USED

- Functions
- File handling (ifstream and ofstream)
- Loops
- Conditional statements
- String manipulation
- Menu-driven program design


TESTING

The program was tested by:
- Registering multiple students
- Creating multiple sessions
- Marking attendance
- Updating attendance records
- Generating attendance summaries

All features work correctly and data is saved between executions.


CONCLUSION

This project demonstrates how C++ can be used to develop a practical digital attendance system.

The system improves efficiency compared to paper-based attendance and ensures organized and reliable record keeping.
AUTHOR

Name: Rebecca Ansong
