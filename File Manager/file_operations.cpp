#include "file_operations.h"
#include <fstream>
#include <iostream>

using namespace std;

void copyFile(const string& source, const string& destination) {
    ifstream src(source, ios::binary);
    if (!src.is_open()) {
        cerr << "Error: Source file '" << source << "' does not exist." << endl;
        return;
    }

    ifstream dest_check(destination);
    if (dest_check.good()) {
        cout << "Warning: Destination file '" << destination << "' already exists. Overwrite? (Y/N): ";
        char response;
        cin >> response;
        if (response != 'Y' && response != 'y') {
            cout << "File not copied." << endl;
            return;
        }
    }

    ofstream dest(destination, ios::binary);
    dest << src.rdbuf();

    if (!dest) {
        cerr << "Error: Failed to copy file from '" << source << "' to '" << destination << "'." << endl;
        return;
    }

    cout << "File copied successfully from '" << source << "' to '" << destination << "'." << endl;
}