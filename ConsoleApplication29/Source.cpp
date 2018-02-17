#include <iostream>
#include<locale.h>
#include<stdio.h>
#include<time.h>
using namespace std;

//void starBars(int row, char symbol);
//void starBars(int *row, char *symbol);

int time(int h, int m, int s);
int sum_3(int chislo);
int palendrom(int ch);
void maximum(int *max, int chislo);
int GetCountDayMonth(int month, int year);


void main()
{

	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	/*int row_ = 0;
	cin >> row_;
	char symbol_;
	cin >> symbol_;
	starBars(row_ , symbol_);
	cout << "-----" << endl;*/



	///*starBars( &row_,  &symbol_);*/   //�������� �������

	short int o, p;

	do
	{
		cout << "������� �������:";
		cin >> o;
		switch (o)
		{
		case 1:
		{
			/*1.	�������� ������� int f(int h, int m, int s), ������� ��������� ��� ����� ���������(���� h, ������ m � ������� s)
				� ���������� ���������� ������, ��������� � ������ ���*/
			float resaut;
			float hour, min, sec;
			cout << "������� ����� ����, ������ , �������." << endl;
			cin >> hour >> min >> sec;

			resaut = time(hour, min, sec);
			cout << "������ �������" << resaut << endl;


		}
		break;
		case 2:
		{
			/*2.	�������� ��� ������������ ���������� ������.���������� �������� ����� ������������ �����,
				� ������� ����� ��� ������ ���� ���� ����� ����� ��� ��������� ���� ����.
				(���������� ������� ��� ������� ����� ���� ������������ �����.)*/
			int a[10];

			for (int i = 0; i < 10; i++)
			{
				a[i] = 10 % rand() + 20;
			}


			for (int i = 0; i < 10; i++)
			{
				int resault = sum_3(a[1]);
				if (resault == 1)
					cout << "�� ���������� �����" << endl;
				else
					cout << " ���������� �����" << endl;
			}


		}
		break;
		case 3:
		{
			/*3.	���� ��� ����������� �����.��������, �������� �� ���� ���� �� ��� �����������("������������"),
				�.�.����� ������, ���������� ������ �������� �������� ��������� ����� ������� � ������ ������.
				(���������� �������, ����������� ������������ ����� - ����������.)*/

			int a[2];
			for (int i = 0; i < 2; i++)
			{
				cout << "������� �����" << i << endl;
				cin >> a[i];
				if (palendrom(a[i]))
					cout << "������" << endl;
				else
					cout << "�� ������" << endl;
			}

		}
		break;
		case 4:
		{
			/*4.	���� ����� ��������� �����.���������� ������������ �� ���.
				(���������� �������, ��������� �������� �� ���� ��������� �����.)*/

			int max = 0;
			int a[20];
			for (int i = 0; i < 20; i++)
			{
				maximum(&max, a[i]);
				a[i] = 5 + rand() % 30;
			}
			cout << "������������ ����� " << max << endl;
		}
		break;
		case 5:
		{
			/*5.	���� ���������� ��� ��������������� ����� ������������ ������� : g(���), m(���������� ����� ������) � n(�����).
				�� �������� g, n � m ����������(���������� �������, �������������� ���������� ���� � ��� ��� ���� ������) :
				a.���� ����������� ���;
			b.���� ���������� ���*/

			int year,month;
			cout << "������� ���" << endl;
			cin >> year;
			cout << "������� �����" << endl;
			cin >> month;
			cout << GetCountDayMonth(month, year) << endl;
			



		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		default:cout << "�� ����� �������� ��������." << endl;
			break;

		}
		cout << "������ ���? (1)�� (2)���." << endl;
		cin >> p;

	} while (p == 1);

}

int time(int h, int m, int s)
{

	int second = h * 3600 + m * 60 + s;
	return second;


}
int sum_3(int chislo)
{
	int sum3 = chislo / 100000 + chislo / 10000 + chislo / 1000;
	int pos = chislo % 1000;
	if (sum3 == pos)
		return 0;
	else
		return 1;

}
int palendrom(int ch)
{
	if (((ch / 1000) == (ch % 10)) && (((ch / 100) % 10) == (ch % 100) / 10))
		return 1;

	return 0;
}
void maximum(int *max, int chislo)
{
	if (*max < chislo)
		*max = chislo;
}


int Isleap(int year)
{
	if (((year % 4) == 0)&&(year % 400)==0)
		return 1;

	return 0;
}
int GetCountDayMonth(int month, int year)
{
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (Isleap(year))
			return 29;
		else
			return 28;
		break;

	default: return 0;
		break;
	}
}
int NextDay(int day ,int month ,int year )
{



}
int NazadDay(int day, int month, int year)
{
	if (day == 1 && month == 1)
	{
		month = 12;
		year--;
		day = GetCountDayMonth(month, year);
	}
	else if ((day == 1) && (month == 3))
	{
		month--;
		day = GetCountDayMonth(month, year); 
	}

}
