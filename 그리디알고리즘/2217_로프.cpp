#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer, N, temp;
vector <int> v;
bool cmp(const int& a, const int& b) {
	return a > b;
}
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> temp;
		v.push_back(temp);
	}
}
int minimum(int k) {
	int mini = 2147483647;
	for (int i = 0; i < k; i++) {
		mini = (mini > v[i] ? v[i] : mini);
	}
	return mini;
}
int calc() {
	sort(v.begin(), v.end(), cmp);
	answer = v[0];
	
	for (int k = 2; k <= N; k++) {
		int now = v[k-1] * k;
		if (answer < now) answer = now;
	}
	return answer;
}
int main() {
	input();
	cout << calc() << '\n';
}