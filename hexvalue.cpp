#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream file("C:\\Users\\Pc7\\Desktop\\antivirus\\pic.jpg", ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    stringstream ss;
    char ch;
    while (file.get(ch)) {
        ss << hex << uppercase << static_cast<int>(ch);
    }
    string hex = ss.str();

    cout << hex << endl;
    file.close();

    return 0;
}
