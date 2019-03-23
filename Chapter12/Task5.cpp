#include <iostream>

using namespace std;

bool input_is_correct(int value, int min, int max)
{
	if(cin.good())
	{
		if(!(value >= min && value <= max))
		{
			cout << "You're value must be between " << min << " and " << max << endl;
			return false;
		}

		cin.ignore(10, '\n');
		return true;
	}
	else
	{
		cin.clear();
		cout << "An error has occured\n";
		cin.ignore(10, '\n');
		return false;
	}
}

class Time
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	void get_time()
	{
		do 
		{
			cout << "Enter hours: ";
			cin >> hours;
		} while(!input_is_correct(hours, 0, 23));

		do 
		{
			cout << "Enter minutes: ";
			cin >> minutes;
		} while(!input_is_correct(minutes, 0, 59));

		do 
		{
			cout << "Enter seconds: ";
			cin >> seconds;
		} while(!input_is_correct(seconds, 0, 59));
	}

	void put_time()
	{
		cout << "Time = " << hours << ':';
		if(minutes > 9)
			cout << minutes;
		else
			cout << "0" << minutes;
		
		cout << ':';

		if(seconds > 9) 
			cout << seconds;
		else
			cout << "0" << seconds;
		cout << endl;
	}
};

int main()
{
	char answer;
	do
	{
		Time t;
		t.get_time();
		t.put_time();

		cout << "Continue y/n? ";
		cin >> answer;
	} while(answer == 'y');
	return 0;
}