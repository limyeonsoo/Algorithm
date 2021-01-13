#include <iostream>
#include <vector>
#include <string>
#define uint unsigned int

using namespace std;
int N;
char chr;
vector <string> v;
void input() {
	cin >> N;
	while (N--) {
		cin >> chr;
		v.push_back(to_string(chr));
	}
}
string getMinimum(string answer, uint bit) {
	if (answer.size() == v.size() + 1) return answer;
	if (answer.size() == 0) {
		for (int i = 0; i < 10; i++) {
			string res = getMinimum(to_string(i), bit | (1 << i));
			if (res != "") return res;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (bit & (1 << i)) continue;
		
		if (v[answer.size()-1] == to_string('<')) {
			if (answer[answer.size() - 1]-'0' >= i) continue;
			string res = getMinimum(answer + to_string(i), bit | (1 << i));
			if (res == "") continue;
			else return res;
		}
		else {
			if (answer[answer.size() - 1]-'0' <= i) break;
			string res = getMinimum(answer + to_string(i), bit | (1 << i));
			if (res == "") continue;
			else return res;
		}
	}
	return "";
}
string getMaximum(string answer, uint bit) {
	if (answer.size() == v.size() + 1) return answer;
	if (answer.size() == 0) {
		for (int i = 9; i >= 0; i--) {
			string res = getMaximum(to_string(i), bit | (1 << i));
			if (res != "") return res;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (bit & (1 << i)) continue;
		if (v[answer.size() - 1] == to_string('<')) {
			if (answer[answer.size() - 1] - '0' >= i) break;
			string res = getMaximum(answer + to_string(i), bit | (1 << i));
			if (res == "") continue;
			else return res;
		}
		else {
			if (answer[answer.size() - 1]-'0' <= i) continue;
			string res = getMaximum(answer + to_string(i), bit | (1 << i));
			if (res == "") continue;
			else return res;
		}
	}

	return "";
}
int main() {
	input();
	cout << getMaximum("", 0) << '\n' << getMinimum("", 0);
}