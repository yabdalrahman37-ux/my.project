#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
};

vector<Student> students;
//هنضيف الطالب
void addStudent() {
    Student s;

    cout << "Enter ID: ";
    cin >> s.id;

    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Grade: ";
    cin >> s.grade;

    students.push_back(s);
    cout << "Student added successfully ✅\n";
}

// عرض الطلاب
void displayStudents() {
    if (students.empty()) {
        cout << "No students found ❌\n";
        return;
    }

    for (const auto& s : students) {
        cout << "ID: " << s.id 
             << " | Name: " << s.name 
             << " | Grade: " << s.grade << endl;
    }
}

// البحث عن الطلاب
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (const auto& s : students) {
        if (s.id == id) {
            cout << "Student found:\n";
            cout << "Name: " << s.name << " | Grade: " << s.grade << endl;
            return;
        }
    }

    cout << "Student not found ❌\n";
}

// حذف الطلاب
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student deleted ✅\n";
            return;
        }
    }

    cout << "Student not found ❌\n";
}

// الدالة الرئيسية
int main() {
    int choice;

    do {
        cout << "\n====== Student Management System ======\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice ❌\n";
        }

    } while(choice != 5);

    return 0;
}