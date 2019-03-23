#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage example: %programname% filename" << endl;
		return -1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile)
	{
		cout << "Unable to open " << argv[1] << endl;
		return -1;
	}

	streampos fileSize = inputFile.seekg(0, ios::end).tellg();

	cout << fileSize << " bytes" << endl;
}
