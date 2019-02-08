// times1.cpp
// программа перевода времени в 24-часовом написании
// в 12-часовое
#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////
class time12
{
private:
	bool pm;					// true = pm, false = am
	int hrs;					// 1 - 12
	int mins;					// 0 - 59
public:					        // конструктор без аргументов
	time12() : pm(true), hrs(0), mins(0)
	{ }							// конструктор с тремя аргументами
	time12(bool ap, int h, int m) : pm (ap), hrs (h), mins (m)
	{ }
	void display() const		// формат: 23:59.
	{
		cout << hrs << ':';
		if(mins < 10)
			cout << '0';		// дополнительный нуль для "01"

		cout << mins << ' ';
		string am_pm = pm ? "p.m." : "a.m.";
		cout << am_pm;
	}
};
///////////////////////////////////////////////////////////
class time24
{
private:
	int hours;					// 0 - 23
	int minutes;				// 0 - 59
	int seconds;				// 0 - 59
public:				            // конструктор без аргументов
	time24() : hours(0), minutes(0), seconds(0)
	{ }							// конструктор с тремя аргументами
	time24(int h, int m, int s) : hours(h), minutes(m), seconds(s)
	{ }
	void display() const		// формат: 23:15:01
	{
		if(hours < 10) cout << '0';
		cout << hours << ':';
		if(minutes < 10) cout << '0';
		cout << minutes << ':';
		if(seconds < 10) cout << '0';
		cout << seconds;
	}
	operator time12() const;	// оператор преобразования
};
///////////////////////////////////////////////////////////
time24::operator time12() const	// оператор преобразования
{
	int hrs24 = hours;
	bool pm = hours < 12 ? false : true;// определение am/pm

								// округление секунд
	int roundMins = seconds < 30 ? minutes : minutes + 1;
	if(roundMins == 60)			// переносим минуты?
	{
		roundMins = 0;
		++hrs24;
		if(hrs24 == 12 || hrs24 == 24)// переносим часы?
			pm = (pm == true) ? false : true;// переключатель am/pm
	}
	int hrs12 = (hrs24 < 13) ? hrs24 : hrs24 - 12;
	if(hrs12 == 0)				// 00 это 12 a.m.
	{
		hrs12 = 12;
		pm = false;
	}
	return time12(pm, hrs12, roundMins);
}
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	int h, m, s;

	while(true)
	{ // получение времени в 24-ом формате от пользователя
		cout << "Введите время в 24-часовом формате: \n";
		cout << "  Часы (от 0 до 23): "; cin >> h;
		if(h > 23)				// выход, если часов > 23
			return (1);
		cout << "  Минуты: "; cin >> m;
		cout << "  Секунды: "; cin >> s;

		time24 t24(h, m, s);	// сделать время в 24-часовом формате
		cout << "Исходное время: ";
		t24.display();			// вывести на экран время в 24-часовом формате

		time12 t12 = t24;		// преобразовать time24 в time12

		cout << "\nВ 12-часовом формате: ";
		t12.display();			// вывести на экран время в 12-часовом формате
		cout << "\n\n";
	}

	return 0;
}
