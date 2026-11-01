#include <string>
#include <iostream>
using namespace std;

int main()
{
    int age;
    string name;

    cout << "Enter your age: ";
    cin >> age;

    // Fix input buffer issue
    cin.ignore(); // Ignore the leftover '\n'

    cout << "Enter your full name: ";
    getline(cin, name);

    cout << "Age: " << age << ", Name: " << name << endl;
    return 0;
}
