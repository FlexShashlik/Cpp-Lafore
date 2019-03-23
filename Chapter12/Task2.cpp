#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Command format is: programname srcfile destfile" << endl;
		return -1;
	}

	ifstream inputFile(argv[1], ios::binary);

	if (!inputFile)
	{
		cout << "Unable to open srcfile for reading :C" << endl;
		return -1;
	}
	
	ofstream outputFile(argv[2], ios::binary);

	if (!outputFile)
	{
		cout << "Unable to open destfile for writing :C" << endl;
		return -1;
	}

	char ch;

	while (inputFile.get(ch))
	{
		outputFile.put(ch);
	}

	inputFile.close();
	outputFile.close();
}
