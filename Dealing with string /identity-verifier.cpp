#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// ═══════════════════════════════════════════════════
// STEP 1: Clean the input code
// Remove punctuation, first letter uppercase, rest lowercase
// ═══════════════════════════════════════════════════
string CleanCode(string raw)
{
    string result = "";

    // Remove punctuation
    for (char c : raw)
    {
        if (!ispunct(c))  // Keep only letters and numbers
        {
            result += c;
        }
    }

    // Fix case: First Upper, Rest Lower
    if (result.length() > 0)
    {
        result[0] = toupper(result[0]);

        for (int i = 1; i < result.length(); i++)
        {
            result[i] = tolower(result[i]);
        }
    }

    return result;
}

// ═══════════════════════════════════════════════════
// STEP 2: Store cleaned code in Heap, save pointer in Vector
// ═══════════════════════════════════════════════════
void AddToSystem(vector<string*>& storage, string cleanedCode)
{
    // Create new string on HEAP
    string* heapString = new string(cleanedCode);

    // Save pointer in vector
    storage.push_back(heapString);
}

// ═══════════════════════════════════════════════════
// STEP 3: Display all codes using Iterator
// Show memory address AND value
// ═══════════════════════════════════════════════════
void ShowAllCodes(vector<string*>& storage)
{
    cout << "\n========== All Codes ==========\n";

    // Iterator = pointer that moves through vector
    vector<string*>::iterator it;

    for (it = storage.begin(); it != storage.end(); it++)
    {
        // *it  = the pointer (memory address)
        // **it = the actual string value

        cout << "Address: " << *it << endl;
        cout << "Value  : " << **it << endl;
        cout << "-------------------\n";
    }
}

// ═══════════════════════════════════════════════════
// STEP 4: Access specific code by index (safe with try-catch)
// ═══════════════════════════════════════════════════
void AccessCode(vector<string*>& storage)
{
    int index;
    cout << "\nEnter index (0 to " << storage.size() - 1 << "): ";
    cin >> index;

    try
    {
        // at() checks bounds, throws if invalid
        string* ptr = storage.at(index);
        cout << "Code at " << index << ": " << *ptr << endl;
    }
    catch (...)
    {
        cout << "Error: Index not found!\n";
    }
}

// ═══════════════════════════════════════════════════
// STEP 5: Cleanup - Delete all heap memory
// ═══════════════════════════════════════════════════
void DeleteAll(vector<string*>& storage)
{
    cout << "\nCleaning up memory...\n";

    for (string* ptr : storage)
    {
        delete ptr;  // Free each heap string
    }

    storage.clear();  // Empty the vector

    cout << "Done! No memory leaks.\n";
}

// ═══════════════════════════════════════════════════
// MAIN - Run all phases
// ═══════════════════════════════════════════════════
int main()
{
    vector<string*> codes;  // Will store pointers to heap strings
    char choice = 'Y';

    // PHASE 1 & 2: Input + Clean + Store
    while (choice == 'Y' || choice == 'y')
    {
        string raw;
        cout << "Enter code (with symbols): ";
        cin >> raw;

        string cleaned = CleanCode(raw);
        cout << "Cleaned: " << cleaned << endl;

        AddToSystem(codes, cleaned);

        cout << "Add more? (Y/N): ";
        cin >> choice;
    }

    // PHASE 3: Display
    ShowAllCodes(codes);

    // PHASE 4: Access by index
    AccessCode(codes);

    // PHASE 5: Cleanup
    DeleteAll(codes);

    return 0;
}
