/**
* @file main.c
* @author Reshetnyak Kirill gr. 515b
* @date 25.06.2021
* @brief Летняя практика
*
* Вариант 30. Нахождение суммы цифр в числе 2^1000
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>    // подключение стандартных библиотек 
#include <locale.h>
#include <string.h>

// объявление переменых 
int w, d, s;
char sda[400], c;
double summ;
long double pows;

int clean_std();

int ctoint(char s);

int main()
{
	setlocale(LC_ALL, "RUS"); //подключение кирилицы

	do {
		printf("Ведите число (Выход с программы '0'):"); 
	} while (((scanf_s("%d%c", &d, &c) != 2 || c != '\n') && clean_std())); // ввод числа и провека на конкретность 
	if (d == 0) exit(0);
vozvrat:
	do {
		printf("Ведите степень: ");
	} while (((scanf_s("%d%c", &w, &c) != 2 || c != '\n') && clean_std())); // ввод степени и провека на конкретность 
	// проверка на положительность степени 
	if (w < 0) { printf("Прости друг, степень может быть только положительна ¯._(ツ)_.¯\n"); goto vozvrat; }

	pows = powl(d, w); // нахождения чисоа в степени с помощью библиотеки <math.h>  
	sprintf_s(sda, "%.0Lf", pows); // присваивание sda значения полученной степени 
	for (int i = 0; i < strlen(sda); ++i) { // цикл вывода
		if (i != 0 && i != strlen(sda)) {
			printf("+ ");
		}
		s = ctoint(sda[i]); // присваивание нужного элемента массива
		printf("%d ", s); // вывод числа
		summ += s; // суммирование 
	}
	printf("= %.0lf\n", summ);
	exit(0);
}

int ctoint(char s) { // функция определение какая строка принадлежит какой цифре
	if (s == '0')
		return 0;
	if (s == '1')
		return 1;
	if (s == '2')
		return 2;
	if (s == '3')
		return 3;
	if (s == '4')
		return 4;
	if (s == '5')
		return 5;
	if (s == '6')
		return 6;
	if (s == '7')
		return 7;
	if (s == '8')
		return 8;
	if (s == '9')
		return 9;
	return 0;
}

int clean_std() { // проверка на конкретность ввода
	while (getchar() != '\n');
	return 1;
}
