#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string T, P;
vector <int> fails;
vector <int> answer;
void Input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	getline(cin, T);
	getline(cin, P);
}

void Fail() {
	fails.resize(T.size()*2);
	for (int i = 1, j=0; i < P.size(); i++) {
		while (j > 0 && P[i] != P[j]) j = fails[j - 1];
		if (P[i] == P[j]) fails[i] = ++j;
	}
}

void Matching() {
	for (int i = 0, j = 0; i < T.size(); i++) {
		//다르면 fail을 참조해서 간다.
		while (j > 0 && T[i] != P[j]) j = fails[j - 1];
		
		//같은 것을 찾았다.
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {
				answer.push_back(i - P.size() + 2);
				//계속 전진
				j = fails[j];
			}
			else j++;
		}
	}
}

void Printing() {
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) cout << answer[i] << ' ';
}
int main() {
	Input();
	Fail();
	Matching();
	Printing();
}