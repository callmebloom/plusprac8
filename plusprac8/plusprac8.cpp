#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

typedef bool(*FindSymvol)(const char*, const char*);

int main() {
	setlocale(LC_ALL, "Russian");

	HINSTANCE hGetProcIDDLL = LoadLibrary(L"biblio.dll");
	if (!hGetProcIDDLL) {
		cout << "не загружается библиотека((" << endl;
		return 1;
	}
	FindSymvol naitibukvu = (FindSymvol)GetProcAddress(hGetProcIDDLL, "FindLetters");
	if (!naitibukvu) {
		cout << "не загружается библиотека(((((" << endl;
		FreeLibrary(hGetProcIDDLL);
		return 1;
	}
	string vstroke, symvoly;
	do {
		cout << "пиши строку: ";
		getline(cin, vstroke);
	} 
	while (vstroke.empty());

	cout << "что тебе найти? ^^  ";
	cin >> symvoly;

	bool res = naitibukvu(vstroke.c_str(), symvoly.c_str());
	if (res) {
		cout << "есть такая буква! крутите барабан! (true)";
	}
	else {
		cout << "нет такого символа. подарки в студию! (false)";
	}
	
	FreeLibrary(hGetProcIDDLL);
	return 0;
}