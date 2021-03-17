#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string a;
int b, dotIndex;

string add(string& x, string& y) {
	string result(max(x.size(), y.size()), '0');
	int carry = 0;
	for (int i = 0; i<result.size(); i++) {
		int temp = carry;
		carry = 0;
		if (i < x.size()) {
			temp += x[x.size() - 1 - i] - '0';
		}
		if (i < y.size()) {
			temp += y[y.size() - 1 - i] - '0';
		}
		if (temp >= 10) {
			carry = 1;
			temp %= 10;
		}
		result[result.size() - 1 - i] = temp + '0';
	}
	if (carry) {
		result.insert(result.begin(), '1');
	}
	return result;
}

string mul(string& x, string& y) {
	string result = "0";
	for (int i = 0; i < x.size(); i++) {
		string eachLine(y.size(), '0');
		int carry = 0;
		for (int j = 0; j < y.size(); j++) {
			int temp = carry;
			carry = 0;

			temp += (y[y.size() - 1 - j] - '0') * (x[x.size() - 1 - i] - '0');
			
			if (temp >= 10) {
				carry = temp / 10;
				temp %= 10;
			}
			eachLine[y.size()-1-j] = temp + '0';
		}
		if (carry) {
			eachLine.insert(eachLine.begin(), carry + '0');
		}
		eachLine += string(i, '0');
		result = add(result, eachLine);
	}
	return result;
}

string _pow(string& x, int y) {
	
	if (y == 1) return x;

	string result = _pow(x, y - 1);
	return mul(result, x);
}
void input() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b;
}
void removeDot() {
	string::iterator finder = find(a.begin(), a.end(), '.');
	if (finder != a.end()) { // has a Dot.
		dotIndex = a.end() - finder - 1;
		a.erase(finder);
	}

	dotIndex *= b;
	// why is dot in there?
	// xxx . xxxx  ->  4 * b 
}
void calc() {
	string result = _pow(a, b);
	if (dotIndex) result.insert(result.end() - dotIndex, '.');
	cout << result;
}
int main() {
	input();
	removeDot();
	calc();
}

// ref : https://jaimemin.tistory.com/1076 & https://github.com/kks227/BOJ/blob/master/10800/10827.cpp