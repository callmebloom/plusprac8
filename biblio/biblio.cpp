#include <iostream>
#include <string>

using namespace std;

__declspec(dllexport) bool FindLetters(const char* vstroke, const char* naitibukvu) {
	string str(vstroke);
	string chars(naitibukvu);

	for (char c : chars) {
		if (str.find(c) == string::npos) {
			return false;
		}
	}
	return true;
	
}