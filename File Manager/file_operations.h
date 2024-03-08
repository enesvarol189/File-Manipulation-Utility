#include <string>
#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

using namespace std;

void copyFile(const string& source, const string& destination);

void searchFiles(const string& directory, const string& pattern);

double compareFiles(const string& file1, const string& file2);

#endif
