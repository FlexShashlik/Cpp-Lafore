// days.cpp
// ����� ���������� ���� � ������ ���� � �� ��������� ����
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251 > nul");

	int month, day, total_days;
	int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cout << "\n������� ����� (�� 1 �� 12): ";
	cin >> month;
	cout << "\n������� ���� (�� 1 �� 31): ";
	cin >> day;
	total_days = day;

	for(int j = 0; j < month - 1; j++)
		total_days += days_per_month[j];
	cout << "����� ����� ���� � ������ ����: " << total_days << endl;

	return 0;
}