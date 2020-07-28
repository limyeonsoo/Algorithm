#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector <int> v;
int gcd(int a, int b) {
	int t;
	while (b) {
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main() {
	cin >> N; v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int min = v[1]-v[0]; int diff = 0;
	for (int i = 2; i < N; i++) {
		min = gcd(min, v[i] - v[i - 1]);
	}
	for (int i = 1; i < N; i++) {
		if (v[i] - v[i - 1] == min) continue;
		diff += (((v[i] - v[i - 1]) / min) - 1);
	}

	cout << diff;
}

