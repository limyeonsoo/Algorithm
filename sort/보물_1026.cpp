#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <int> va;
vector <pair<int, int> > vb;
int answer;
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main() {
	int N, temp; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		va.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;
		vb.push_back({ temp, i });
	}
	sort(vb.begin(), vb.end(), cmp);

	sort(va.begin(), va.end());
	for (int i = 0; i < va.size(); i++) {
		answer += vb[i].first * va[i];
	}
	cout << answer;
}