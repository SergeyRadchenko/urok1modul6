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



	///*starBars( &row_,  &symbol_);*/   //передача адресса

	short int o, p;

	do
	{
		cout << "Введите задание:";
		cin >> o;
		switch (o)
		{
		case 1:
		{
			/*1.	Напишите функцию int f(int h, int m, int s), которая принимает три целых аргумента(часы h, минуты m и секунды s)
				и возвращает количество секунд, прошедших с начала дня*/
			float resaut;
			float hour, min, sec;
			cout << "Введите время Часы, минуты , секунды." << endl;
			cin >> hour >> min >> sec;

			resaut = time(hour, min, sec);
			cout << "Прошло времени" << resaut << endl;


		}
		break;
		case 2:
		{
			/*2.	Получить все шестизначные счастливые номера.Счастливым называют такое шестизначное число,
				в котором сумма его первых трех цифр равна сумме его последних трех цифр.
				(Определить функцию для расчета суммы цифр трехзначного числа.)*/
			int a[10];

			for (int i = 0; i < 10; i++)
			{
				a[i] = 10 % rand() + 20;
			}


			for (int i = 0; i < 10; i++)
			{
				int resault = sum_3(a[1]);
				if (resault == 1)
					cout << "Не Счастливое число" << endl;
				else
					cout << " счастливое число" << endl;
			}


		}
		break;
		case 3:
		{
			/*3.	Даны два натуральных числа.Выяснить, является ли хоть одно из них палиндромом("перевертышем"),
				т.е.таким числом, десятичная запись которого читается одинаково слева направо и справа налево.
				(Определить функцию, позволяющую распознавать числа - палиндромы.)*/

			int a[2];
			for (int i = 0; i < 2; i++)
			{
				cout << "Введите число" << i << endl;
				cin >> a[i];
				if (palendrom(a[i]))
					cout << "Палено" << endl;
				else
					cout << "Не Палено" << endl;
			}

		}
		break;
		case 4:
		{
			/*4.	Даны шесть различных чисел.Определить максимальное из них.
				(Определить функцию, находящую максимум из двух различных чисел.)*/

			int max = 0;
			int a[20];
			for (int i = 0; i < 20; i++)
			{
				maximum(&max, a[i]);
				a[i] = 5 + rand() % 30;
			}
			cout << "Максимальное число " << max << endl;
		}
		break;
		case 5:
		{
			/*5.	Дата некоторого дня характеризуется тремя натуральными числами : g(год), m(порядковый номер месяца) и n(число).
				По заданным g, n и m определить(Определить функцию, подсчитывающую количество дней в том или ином месяце) :
				a.дату предыдущего дня;
			b.дату следующего дня*/

			int year,month;
			cout << "Введите год" << endl;
			cin >> year;
			cout << "Введите месяц" << endl;
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
		default:cout << "Вы ввели неверное значение." << endl;
			break;

		}
		cout << "Хотите еще? (1)дА (2)НЕт." << endl;
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
