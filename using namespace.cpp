#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream file("C:\\Users\\USER\\Desktop\\test\\A simple note for English.pdf", ios::binary); // replace "filename.bin" with the name of your file
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    stringstream ss; // create a stringstream object to store the hexadecimal values
    char ch;
    while (file.get(ch)) {
        ss << hex << uppercase << static_cast<int>(ch); // convert the character to its hexadecimal value and store it in the stringstream object
    }
    string hex = ss.str(); // convert the stringstream object to a string

    cout << hex << endl; // print the string of hexadecimal values
    file.close(); // close the file

    return 0;
}

