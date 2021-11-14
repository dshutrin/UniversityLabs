#include <iostream>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <initializer_list>
#include <random>
#include <iomanip>
#pragma hdrstop
using namespace std;
char* rus(const char* text);
int main(int argc, char* argv[])
{
	void randomize(void); {
		srand((unsigned int)time(NULL));
	}
	int n = 10, i, j, l, k ;
	float sum = 0;
	cout << rus("Vvedite razmernost massiva:") << endl;
	cout << rus("Vvedite koli4estvo strok i stolbcov") << n;
	float** a = new float* [n];
	for (i = 0; i < n; i++) a[i] = new float[n];
	float** a1 = new float* [n];
	for (k = 0; k < n; k++) a1[i] = new float[n];
	cout << rus("\nVvedite elementi massiva:\n \n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = -2.1 + (10.1);
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
	for (i = 0, k = 0; i < n, k < n, i++, k++;)
	{
		for (j = 0, l = 0; j < n, l < n, j++, l++;)
		{
			if (i == 0){
				if (j == 0) a1[k][l] = (a[i][j + 1] + a[i + 1][j]) / 2;
			}

				if (i == 0){
					if (j > 0 && j < (n - 1)) a1[k][j] = (a[i][j + 1] + a[i][i - 1] + a[i + 1][j]) / 3;
				}

			if (i == 0){
				if (j == (n - 1)) a1[k][l] = (a[i][j - 1] + a[i + 1][j]) / 2;
			}

				if (i > 0 && i < (n - 1)){
					if (j == 0)a1[k][l] = (a[i][j + 1] + a[i - 1][j] + a[i + 1][j]) / 3;
				}

			if (i > 0 && i < (n - 1)){
				if (j > 0 && j < (n - 1))a1[k][l] = (a[i][j + 1] + a[i][j - 1] + a[i - 1][j] + a[i + 1][j]) / 4;
			}

				if (i > 0 && i < (n - 1)){
					if (j == (n-1))a1[k][l] = (a[i][j + 1] + a[i - 1][j] + a[i + 1][j]) / 3;
				}

			if (i == (n - 1)){
				if (j == 0) a1[k][l] = (a[i][j + 1] + a[i - 1][j]) / 2;
			}

				if (i == (n - 1)){
					if (j > 0 && j < (n - 1)) a1[k][j] = (a[i][j + 1] + a[i][i - 1] + a[i + 1][j]) / 3;
				}

			if (i == (n - 1)){
				if (j == (n - 1)) a1[k][l] = (a[i][j - 1] + a[i - 1][j]) / 2;
			}
		}
	}
	cout << rus("\nSglajennaya matrica:\n \n");
	for (k = 0; k < n; k++)
	{
		for (l = 0; l < n; l++)
		cout << setw(10) << a1[k][l];
		cout << endl;
	}
	for (k = 0; k < n; k++)
	{
		for (l = 0; l < n; l++)
		{
			if (l < n)
			{
				sum += fabs(a1[k][l]);
			}
		}
	}
	cout << rus("\nSumma moduley elementov raspolojennix nije glavnoy diagonali matrici: ");
	cout << sum;
	return 0;
}
char bufrus[256];
char* rus(const wchar_t* text)
{
	CharToOem(text, bufrus);
	return bufrus;
}
