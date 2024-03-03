#include <string>
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

using namespace std;

void copyFile(const string& source, const string& destination);

void searchFiles(const string& directory, const string& pattern);

#endif
