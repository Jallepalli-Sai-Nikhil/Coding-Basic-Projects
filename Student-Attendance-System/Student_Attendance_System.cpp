#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;
    int rollNumber;
    int attendance;

public:
    Student(std::string name, int rollNumber) {
        this->name = name;
        this->rollNumber = rollNumber;
        this->attendance = 0;
    }

    void markAttendance() {
        attendance++;
    }

    void displayAttendance() const {
        std::cout << "Name: " << name << ", Roll Number: " << rollNumber 
                  << ", Attendance: " << attendance << std::endl;
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

class AttendanceSystem {
private:
    std::vector<Student> students;

public:
    void addStudent(const std::string &name, int rollNumber) {
        students.emplace_back(name, rollNumber);
    }

    void markAttendance(int rollNumber) {
        for (auto &student : students) {
            if (student.getRollNumber() == rollNumber) {
                student.markAttendance();
                return;
            }
        }
        std::cout << "Student with roll number " << rollNumber << " not found." << std::endl;
    }

    void displayAllAttendance() const {
        for (const auto &student : students) {
            student.displayAttendance();
        }
    }
};

int main() {
    AttendanceSystem system;

    system.addStudent("Alice", 1);
    system.addStudent("Bob", 2);
    system.addStudent("Charlie", 3);

    system.markAttendance(1);
    system.markAttendance(2);
    system.markAttendance(1);
    system.markAttendance(4);  // Roll number 4 does not exist

    system.displayAllAttendance();

    return 0;
}
