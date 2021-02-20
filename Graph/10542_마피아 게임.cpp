#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
int N, answer, remain;
vector <int> pointing;
vector <int> pointed;
unordered_set <int> mapia;
unordered_set <int> human;
void input() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N; pointing.resize(N + 1); pointed.resize(N + 1); remain = N;
	for (int i = 1; i <= N; i++) {
		cin >> pointing[i];
		pointed[pointing[i]]++;
	}

	for (int i = 1; i <= N; i++) {
		cout << pointing[i] << ' ';
	}cout << '\n';
	for (int i = 1; i <= N; i++) {
		cout << pointed[i] << ' ';
	}
}

void entryMapia() {
	for (int i = 1; i <= N; i++) {
		if (pointed[i] == 0) mapia.insert(i);
		remain -= mapia.size();
	}
}

void setHuman() {

}

int main() {
	input();
	entryMapia();

	while (remain) {

		setHuman();


	}
}