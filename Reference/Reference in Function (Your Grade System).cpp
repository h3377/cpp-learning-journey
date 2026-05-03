#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Student {
    string name;
    int grade;
};


Student& GetTopStudent(vector<Student>& students) {
    // Assume first is top
    int maxIndex = 0;

    // Search for actual highest grade
    for (int i = 1; i < students.size(); i++) {
        if (students[i].grade > students[maxIndex].grade) {
            maxIndex = i;
        }
    }

    // Return REFERENCE to original student in vector
    // NOT a copy!
    return students[maxIndex];
}


void PrintStudents(vector<Student>& students) {
    cout << "\n--- Student List ---\n";
    for (Student& s : students) {
        cout << s.name << ": " << s.grade << endl;
    }
}


int main() {
    // Create students
    vector<Student> students = {
        {"Ahmed", 85},
        {"Sara", 92},
        {"Ali", 78}
    };

    cout << "Before bonus:\n";
    PrintStudents(students);

   
    Student& top = GetTopStudent(students);
    //     ↑
    //     └── Reference! Same memory as students[1]

    cout << "\nTop student: " << top.name
        << " (" << top.grade << ")\n";

  
    top.grade += 5;  // Adds 5 bonus points!
    // ↑
    // └── Modifies students[1].grade directly!

    cout << "\nAfter adding 5 bonus through reference:\n";
    PrintStudents(students);
    // Sara: 92 → 97! (original changed!)

    // ═══════════════════════════════════════════════════
    // PROOF: Check addresses are the same
    // ═══════════════════════════════════════════════════
    cout << "\n--- Address Proof ---\n";
    cout << "&students[1] = " << &students[1] << endl;
    cout << "&top        = " << &top << endl;
    // SAME ADDRESS! Same memory cell!

    // ═══════════════════════════════════════════════════
    // BONUS: Change name through reference too
    // ═══════════════════════════════════════════════════
    top.name += " (Star)";
    cout << "\nAfter name change:\n";
    PrintStudents(students);
    // Sara (Star): 97

    return 0;
}
