#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct stStudent {
    string Name;
    int Grade;
};


void ReadStudents(vector<stStudent>& vStudents) {
    char choice = 'Y';
    
    while (choice == 'Y' || choice == 'y') {
        stStudent s;
        
        cout << "Enter student name: ";
        cin >> s.Name;
        
        cout << "Enter grade (0-100): ";
        cin >> s.Grade;
        
        vStudents.push_back(s);
        
        cout << "Add more? (Y/N): ";
        cin >> choice;
    }
}


void PrintTopStudents(const vector<stStudent>& vStudents) {
    cout << "\n========== TOP STUDENTS (Grade > 90) ==========\n";
    
    bool found = false;
    
    for (const stStudent& s : vStudents) {
        if (s.Grade > 90) {  // FILTER LOGIC
            cout << "Name: " << s.Name 
                 << " | Grade: " << s.Grade << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << "No students with grade above 90.\n";
    }
}


void PrintAllStudents(const vector<stStudent>& vStudents) {
    cout << "\n========== ALL STUDENTS ==========\n";
    
    for (const stStudent& s : vStudents) {
        cout << "Name: " << s.Name 
             << " | Grade: " << s.Grade << endl;
    }
}


void ResetSystem(vector<stStudent>& vStudents) {
    cout << "\n========== RESETTING SYSTEM ==========\n";
    
    cout << "Before clear:\n";
    cout << "  Size: " << vStudents.size() << endl;
    cout << "  Capacity: " << vStudents.capacity() << endl;
    
    vStudents.clear();  // EMPTY THE VECTOR
    
    cout << "\nAfter clear:\n";
    cout << "  Size: " << vStudents.size() << endl;      // 0
    cout << "  Capacity: " << vStudents.capacity() << endl;  // STAYS SAME!
    
    if (vStudents.empty()) {
        cout << "\nSystem reset complete. Vector is empty.\n";
    }
}

int main() {
    vector<stStudent> students;
    
    
    ReadStudents(students);
    
  
    PrintAllStudents(students);
    
  
    PrintTopStudents(students);

    ResetSystem(students);
    
    return 0;
}
