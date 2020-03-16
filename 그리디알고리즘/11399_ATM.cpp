#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>

using namespace std;
int N, spend, ans;

pair<int, int> people[1001];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &people[i].first);
	sort(people + 0, people + N);
	for (int i = 0; i < N; i++) {
		spend += people[i].first;
		people[i].second = spend;
		ans += people[i].second;
	}
	printf("%d", ans);
}