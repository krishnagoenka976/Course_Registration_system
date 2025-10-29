// system.cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Course {
private:
    int code;
    string title;
    int credits;
public:
    Course(int c, const string &t, int cr) : code(c), title(t), credits(cr) {}
    void showCourse() const {
        cout << "Course Code: " << code << ", Title: " << title
             << ", Credits: " << credits << endl;
    }
    int getCredits() const { return credits; }
    string getTitle() const { return title; }
    int getCode() const { return code; }
};

class Student {
private:
    string name;
    int id;
public:
    Student() : name(""), id(0) {}
    Student(const string &n, int i) : name(n), id(i) {}
    void showDetails() const {
        cout << "Student ID: " << id << ", Name: " << name << endl;
    }
    string getName() const { return name; }
    int getId() const { return id; }
};

class Registration {
private:
    Student student;
    Course course;
public:
    Registration(const Student &s, const Course &c) : student(s), course(c) {}
    void confirm() const {
        cout << "\n===== Registration Successful =====" << endl;
        student.showDetails();
        cout << "Registered in: " << course.getTitle()
             << " | Credits: " << course.getCredits() << endl;
        cout << "==================================" << endl;
    }
};

int main() {
    // Predefined courses
    Course c1(101, "Database Management", 4);
    Course c2(102, "Data Structures and Algorithms", 3);
    Course c3(103, "Operating Systems", 3);

    string name;
    int id, choice;

    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student ID: ";
    if (!(cin >> id)) return 0; // simple guard
    cin.ignore(); // clear newline

    Student s1(name, id);

    cout << "\nAvailable Courses:\n";
    cout << "1. "; c1.showCourse();
    cout << "2. "; c2.showCourse();
    cout << "3. "; c3.showCourse();

    cout << "\nEnter course number to register (1-3): ";
    if (!(cin >> choice)) return 0;

    if (choice == 1) {
        Registration r(s1, c1);
        r.confirm();
    } else if (choice == 2) {
        Registration r(s1, c2);
        r.confirm();
    } else if (choice == 3) {
        Registration r(s1, c3);
        r.confirm();
    } else {
        cout << "Invalid choice! Registration failed." << endl;
    }

    return 0;
}

