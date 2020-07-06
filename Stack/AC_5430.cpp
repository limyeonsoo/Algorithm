#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
string q, input;
int T, N, temp;
deque <int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		bool state = true;
		cin >> q >> N;
		v.clear();
		cin >> input;
		int number = 0;
		bool direction = true;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '[') continue;
			else if (input[i] - '0' >= 0 && input[i] - '0' <= 9) {
				number *= 10;
				number += input[i] - '0';
			}
			else if (input[i] == ',' || input[i] == ']') {
				if(number!=0)v.push_back(number);
				number = 0;
			}
		}
		for (int i = 0; i < q.size(); i++) {
			if (q[i] == 'R') {
				direction = (direction == true ? false : true);
			}
			else if (q[i] == 'D') {
				if (v.empty()) {
					state = false;
					break;
				}
				if (direction) v.pop_front();
				else v.pop_back();
			}
		}
		if (!state) {
			cout << "error\n";
			continue;
		}
		else if (v.size() == 1 && v[0] == 0) {
			cout << "[]\n";
			continue;
		}
		cout << '[';
		if (direction) {
			for (int i = 0; i < v.size(); i++) {
				if (i == 0) cout << v[i];
				else cout << "," << v[i];
			}
		}
		else {
			for (int i = v.size() - 1; i >= 0; i--) {
				if (i == v.size() - 1) cout << v[i];
				else cout << "," << v[i];
			}
		}
		cout << "]\n";
	}
}