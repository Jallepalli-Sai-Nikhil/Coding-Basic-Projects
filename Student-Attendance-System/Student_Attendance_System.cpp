#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Class to represent a student
class Student {
public:
    string name;
    int rollNo;

    // Default constructor
    Student() : name("Unnamed"), rollNo(0) {}

    // Parameterized constructor
    Student(string n, int r) : name(n), rollNo(r) {}

    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

// Class to represent a branch (e.g., ECE, CSE, etc.)
class Branch {
private:
    string branchName;
    unordered_map<int, Student> students;

public:
    Branch() : branchName("Unnamed") {}  // Default constructor

    Branch(string name) : branchName(name) {}

    void addStudent(const Student& student) {
        students[student.rollNo] = student;
    }

    void editStudent(int rollNo, const string& newName) {
        auto it = students.find(rollNo);
        if (it != students.end()) {
            it->second.name = newName;
        } else {
            cout << "Student with Roll No " << rollNo << " not found." << endl;
        }
    }

    void viewStudents() const {
        cout << "Branch: " << branchName << endl;
        for (const auto& pair : students) {
            pair.second.display();
        }
    }

    string getName() const {
        return branchName;
    }
};

// Class to represent the college with multiple branches
class College {
private:
    unordered_map<string, Branch> branches;

public:
    College() {
        branches["ECE"] = Branch("ECE");
        branches["CSE"] = Branch("CSE");
        branches["Civil"] = Branch("Civil");
        branches["Mech"] = Branch("Mech");
        branches["EEE"] = Branch("EEE");
    }

    void addStudentToBranch(const string& branchName, const Student& student) {
        auto it = branches.find(branchName);
        if (it != branches.end()) {
            it->second.addStudent(student);
        } else {
            cout << "Branch " << branchName << " not found." << endl;
        }
    }

    void editStudentInBranch(const string& branchName, int rollNo, const string& newName) {
        auto it = branches.find(branchName);
        if (it != branches.end()) {
            it->second.editStudent(rollNo, newName);
        } else {
            cout << "Branch " << branchName << " not found." << endl;
        }
    }

    void viewBranchStudents(const string& branchName) const {
        auto it = branches.find(branchName);
        if (it != branches.end()) {
            it->second.viewStudents();
        } else {
            cout << "Branch " << branchName << " not found." << endl;
        }
    }
};

// Class to represent the accountant
class Accountant {
private:
    College& college;

public:
    Accountant(College& c) : college(c) {}

    void addStudent(const string& branchName, const Student& student) {
        college.addStudentToBranch(branchName, student);
    }

    void editStudent(const string& branchName, int rollNo, const string& newName) {
        college.editStudentInBranch(branchName, rollNo, newName);
    }

    void viewStudents(const string& branchName) const {
        college.viewBranchStudents(branchName);
    }
};

int main() {
    College college;
    Accountant accountant(college);

    // Adding students
    accountant.addStudent("CSE", Student("Alice", 1));
    accountant.addStudent("ECE", Student("Bob", 2));
    accountant.addStudent("EEE", Student("Charlie", 3));

    // Viewing students
    cout << "Students in CSE Branch:" << endl;
    accountant.viewStudents("CSE");

    // Editing a student's name
    accountant.editStudent("CSE", 1, "Alicia");

    // Viewing students after editing
    cout << "Students in CSE Branch after editing:" << endl;
    accountant.viewStudents("CSE");

    return 0;
}
