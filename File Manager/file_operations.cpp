#include "file_operations.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

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

void searchFiles(const string& directory, const string& pattern) {
    try {
        for (const auto& entry : fs::recursive_directory_iterator(directory)) {
            if (fs::is_regular_file(entry) && entry.path().filename().string().find(pattern) != string::npos) {
                cout << "Found matching file: " << entry.path() << endl;
            }
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

double compareFiles(const string& file1, const string& file2) {
    ifstream fileStream1(file1, ios::binary);
    ifstream fileStream2(file2, ios::binary);

    if (!fileStream1.is_open() || !fileStream2.is_open()) {
        cerr << "Error: Unable to open files for comparison." << endl;
        return -1;
    }

    vector<unsigned char> content1(istreambuf_iterator<char>(fileStream1), {});
    vector<unsigned char> content2(istreambuf_iterator<char>(fileStream2), {});

    size_t matchingBytes = 0;
    size_t totalBytes = min(content1.size(), content2.size());
    for (size_t i = 0; i < totalBytes; ++i) {
        if (content1[i] == content2[i]) {
            ++matchingBytes;
        }
    }

    double similarityPercentage = (static_cast<double>(matchingBytes) / totalBytes) * 100;

    return similarityPercentage;
}
