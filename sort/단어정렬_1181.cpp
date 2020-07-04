#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;
set <string> sett;
vector <string> answer;
set <string>::iterator iter;

bool cmp(const string & a, const string & b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	int N; cin >> N;
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		sett.insert(temp);
	}
	for (iter = sett.begin(); iter != sett.end(); iter++) {
		answer.push_back(*iter);
	}
	sort(answer.begin(), answer.end(), cmp);

	for (auto& a : answer) {
		cout << a << '\n';
	}
}