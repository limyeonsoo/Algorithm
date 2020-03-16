#pragma warning (disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N, temp;
	scanf("%d", &N);
	vector <int> v1(N);
	vector <pair<int, int>> v2(N);   // sort 할 vector

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		v1[i] = temp;
		v2[i].second = i;   //1~ N까지의 index를 pair.second에 메김.
		v2[i].first = temp;
	}
	sort(v2.begin(), v2.end());
	int level = 0;
	for (int i = 0; i < v2.size(); i++) {
		if (v2[i].second - i > level)
			level = v2[i].second-i;
	}
	printf("%d", level+1);
}