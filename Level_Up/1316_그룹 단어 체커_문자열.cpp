#include <iostream>
#include <string>
using namespace std;
string S;
int num, result;
bool alpha[26];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> num;
	result = num;
	while (num--) {
		cin >> S;
		for (int i = 1; i < S.length(); i++) {
			if (alpha[S[i] - 'a'] == true) {
				result--;
				break;
			}
			if (S[i] != S[i - 1]) alpha[S[i - 1] - 'a'] = true;
		}
		for (int i = 0; i < 26; i++) alpha[i] = false;
	}
	cout << result;
}