#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, ans, itg;

struct time{
	int start;
	int end;
	int diff;
};
vector <time> v;

bool cmp(const time & x, const time &y) {
	if (x.end == y.end) return x.start < y.start;
	return x.end < y.end;
}

int main() {
	scanf("%d", &N);
	int temp1, temp2;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &temp1, &temp2);
		time x = { temp1, temp2, temp2 - temp1 };
		v.push_back(x);
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		if (v[i].start >= itg)
		{
			itg = v[i].end;
			ans++;
		}
	}
	printf("%d", ans);
}