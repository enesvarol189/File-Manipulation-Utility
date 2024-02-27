#include "CMakeProject1.h"
#include "file_operations.h"

using namespace std;

int main()
{
	cout << "Copying file..." << endl;
	copyFile("C:\\Users\\Mehmet\\Desktop\\input.txt", "C:\\Users\\Mehmet\\Desktop\\output.txt");

	return 0;
}
