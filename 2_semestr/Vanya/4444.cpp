#include <iostream>
#include <cmath>
#include <conio.h>
#include <Windows.h>
#pragma hdrstop
using namespace std;
char* rus(const char* text);
char bufrus[256];
char* rus(const wchar_t* text)
{
	CharToOem(text, bufrus);
	return bufrus;
}
int main(int argc, char* argv[])
{
	int i, n, ibeg = 0, iend = 0, imax;
	float max = 0, sum = 0;
	cout << rus("Vvedite razmernost` n="); cin >> n;
	cout << rus("Vvedite elementi massiva:") << endl << endl;
	float* p = new float[n];
	for (i = 0; i < n; i++)cin >> p[i];
	max = p[0];
	for (i = 0; i < n; i++);
	if (fabs(p[i]) > fabs(max));
	{
		max = p[i];
		imax = i;
	}
	cout << rus("\nMaksimalniy po modulyu element: ") << max << endl;
	cout << rus("Poziciya maksimslnogo po modulyu elementa:") << imax + 1 << endl;
	for (i = 0; i < n; i++)
	if (p[i] > 0)
	{
		ibeg = i;
		break;
	}
	for(i=ibeg+1;i<n;i++)
    if (p[i] > 0)
	{
		iend = i;
		break;
	}
	for (i = ibeg + 1; i < iend; i++)sum += p[i];
	cout << rus("\nSumma elementov raspolojennix mejdu 1 i 2 polojitelnimi elementami:") << sum;
	cout << rus("\nPreobrazovaniy massiv:") << endl << endl;
	for(i=0;i<n;i++)
	if (p[i] != 0)
	{
		cout << p[i] << ' ';
	}
	for(i=0;i<n;i++)
	if (p[i] == 0)
	{
		cout << p[i] << ' ';
	}
	return 0;
}