#include <iostream>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#pragma hdrstop
using namespace std;
char* rus(const char* text);
int main(int argc, char* argv[])
{
	const int k = 30;
	int n, i,  numb = 0;
	bool sort = 1, not_found;
	struct train
	{
		char destiny[k];
		int numb;
		char time[k];
	};
	train buffer;
	cout << rus("Vvedite koli4estvo struktur TRAIN:"); cin >> n;
	cout << endl;
	cin.ignore();
	train* TRAIN = new train[n];
	for (i = 0; i < n; i++)
	{
		cout << ' ' << (i + 1) << rus("Vvedite punkt nazna4eniya:");
		cin.getline(TRAIN[i].destiny, k);
		cout << rus("vvedite nomer poezda:"); cin >> TRAIN[i].numb;
		cout << rus("Vvedite vremya otpravleniya:");
		cin.ignore(); cin.getline(TRAIN[i].time, k);
		cout << endl;
	}
	while (sort)
	{
		sort = 0;
		for(i=0;i<n-1;i++)
			if (TRAIN[i].numb > TRAIN[i + 1].numb)
			{
				buffer = TRAIN[i];
				TRAIN[i] = TRAIN[i + 1];
				TRAIN[i + 1] = buffer;
				sort = 1;
			}
	}
	cout << endl;
	cout << rus("Spisok poezdov uporyado4ennblx po nomeram:\n\n");
	for (i = 0; i < n; i++)
	{
		cout << rus("Punkt nazna4eniya:") << TRAIN[i].destiny << endl;
		cout << rus("Nomer poezda:") << TRAIN[i].numb << endl;
		cout << rus("Vremya otpravleniya:") << TRAIN[i].time << endl;
		cout << endl;
	}
	cout << rus("\nInformaciya o poezdax, nomer kotorogo vveden s klaviaturi:") << endl << endl;
	while (true)
	{
		cout << rus("Vvedite nomer poezda ili 0 dlya okon4aniya:"); cin >> numb;
		if (0 == numb)break;
		not_found = true;
		for (i = 0; i < n; i++)
		{
			if (TRAIN[i].numb == numb)
			{
				cout << rus("\nPunkt nazna4eniya:") << TRAIN[i].destiny << endl;
				cout << rus("Vremya otpravleniya:") << TRAIN[i].time << endl;
				not_found = false;
				cout << endl;
			}
		}
		if (not_found)cout << rus("Takix poezdov net!") << endl << endl;
	}

	return 0;
}
char bufrus[256];
char* rus(const wchar_t* text)
{
	CharToOem(text, bufrus);
	return bufrus;