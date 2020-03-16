#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

vector <pair<int, int>> v;

bool cmp(const pair<int,int> & u, const pair<int,int> & v) {
	return make_tuple(u.first, u.second) < make_tuple(v.first, v.second);
}

int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back({ b,a });
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", v[i].second, v[i].first);
	}
}