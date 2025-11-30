#include <iostream>
#include <string> // Required for std::string and getline

using namespace std;

int main() {
    string name;

    cout << "Enter your full name: ";
    getline(cin, name); // Reads the entire line, including spaces

    cout << "Hello, " << name << "!" << endl;

    return 0;
}