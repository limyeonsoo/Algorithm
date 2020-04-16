#include <iostream>
#include <string>
using namespace std;
string S;
int cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> S;
	for (int i = 0; i < S.length(); i++) {
		if (i == S.length() - 1) { cnt++; break; }
		if (S[i] == 'c') { //c면 뒤에 =, - 확인.
			if (S[i + 1] == '=' || S[i + 1] == '-') i++;
		}
		else if (S[i] == 'd') { //d면 z=, -
			if (i < S.length() - 2 && S[i + 1] == 'z' && S[i + 2] == '=') i += 2;
			else if(S[i + 1] == '-') i++;
		}
		else if (S[i] == 'l') {
			if (S[i + 1] == 'j') i++;
		}
		else if (S[i] == 'n') {
			if (S[i + 1] == 'j') i++;
		}
		else if (S[i] == 's') {
			if (S[i + 1] == '=') i++;
		}
		else if (S[i] == 'z') {
			if (S[i + 1] == '=') i++;
		}
		cnt++;
	}
	cout << cnt;
}
