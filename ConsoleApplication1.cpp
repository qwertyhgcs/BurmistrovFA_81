// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

#include <iomanip>

#define ROMAN_STR_SIZE 80

using namespace std;

const int   arabar[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
const char *romanar[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

char *arab2roman(unsigned short int arab) {
	static char roman[ROMAN_STR_SIZE];
	const int m = sizeof(arabar) / sizeof(int) - 1, arabmax = arabar[m];
	const char romanmax = romanar[m][0];
	int i, n;
	if (!arab) {
		*roman = 0;
		return roman;
	}
	i = 0;
	while (arab>arabmax) {
		roman[i++] = romanmax;
		arab -= arabmax;
	}
	n = m;
	while (arab > 0) {
		if (arab >= arabar[n]) {
			roman[i++] = romanar[n][0];
			if (n & 1)
				roman[i++] = romanar[n][1];
			arab -= arabar[n];
		}
		else
			n--;
	}
	roman[i] = 0;
	return roman;
}

unsigned short int roman2arab(char *roman) {
	const int m = sizeof(arabar) / sizeof(int) - 1;
	unsigned short int arab;
	int len, n, i, pir;
	len = strlen(roman);

	arab = 0;
	n = m;
	i = 0;
	while (n >= 0 && i < len) {
		pir = n & 1;
		if (roman[i] == romanar[n][0] && (!pir || roman[i + 1] == romanar[n][1])) {
			arab += arabar[n];
			i += 1 + pir;
		}
		else
			n--;
	}
	return arab;
}


int _tmain(int argc, _TCHAR* argv[])
{
	static char roman[ROMAN_STR_SIZE];
	unsigned short int arab = 0;
	int counter_I = 0;
	int counter_X = 0;
	int counter_C = 0;
	int counter_V = 0;
	int counter_L = 0;
	int counter_D = 0;
	int i = 0;

	for (i = 0; i < ROMAN_STR_SIZE; i++) roman[i] = 0;

	cout << "Enter Roman" << endl;
	cin >> roman;
	
	i = 0;
	counter_I = 0;
	counter_X = 0;
	counter_C = 0;
	counter_V = 0;
	counter_L = 0;
	counter_D = 0;
	do{
		if ((roman[i] != 'I') && \
			(roman[i] != 'V') && \
			(roman[i] != 'X') && \
			(roman[i] != 'L') && \
			(roman[i] != 'C') && \
			(roman[i] != 'D') && \
			(roman[i] != 'M')){
			cout << "Input Error" << endl;
			system("PAUSE");
			return 0;
		}
		if (roman[i] == 'I') counter_I++;
		else counter_I = 0;
		if (counter_I >= 4){
			cout << "IIII Error" << endl;
			system("PAUSE");
			return 0;
		}
		if (roman[i] == 'X') counter_X++;
		else counter_X = 0;
		if (counter_X >= 4){
			cout << "XXXX Error" << endl;
			system("PAUSE");
			return 0;
		}
		if (roman[i] == 'C') counter_C++;
		else counter_C = 0;
		if (counter_C >= 4){
			cout << "CCCC Error" << endl;
			system("PAUSE");
			return 0;
		}
		if (roman[i] == 'V') counter_V++;
		else counter_V = 0;
		if (counter_V >= 2){
			cout << "VV Error" << endl;
			system("PAUSE");
			return 0;
		}
		if (roman[i] == 'L') counter_L++;
		else counter_L = 0;
		if (counter_L >= 2){
			cout << "LL Error" << endl;
			system("PAUSE");
			return 0;
		}
		if (roman[i] == 'D') counter_D++;
		else counter_D = 0;
		if (counter_D >= 2){
			cout << "DD Error" << endl;
			system("PAUSE");
			return 0;
		}
		i++;
	}while (roman[i] != 0);

	arab = roman2arab(roman);
	cout << "Arab:" << arab << endl;
	system("PAUSE");
	return 0;
}

