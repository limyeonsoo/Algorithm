#pragma warning(disable:4996)
#include <iostream>
#include <map>
using namespace std;

int main() {
	int N;
	long long key;
	scanf("%d", &N); 
	map <long long, int > d; 
	for (int i = 0; i < N; i++) {
		scanf("%lld", &key);
		d[key] += 1;
	}

	int m = 0;   // 가장 많은 카드 개수
	long long ans;  // 가장 많은 카드 정수
	for (auto& p : d) {
		if (p.second > m) {   // 지금까지 나온 최대 카드갯수보다 크다.
			m = p.second;
			ans = p.first;
		}
		else if (p.second == m && p.first < ans) {  // 카드 갯수가 같은데, 정수는 현재 보다 작다.
			ans = p.first;
		}
	}
	printf("%lld", ans);
}