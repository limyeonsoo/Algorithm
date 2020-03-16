#pragma warning(disable:4996)
// 동전 다음 단위는 전 단위의 배수라는 조건을 주었음. 
#include <iostream>
#include <vector>
using namespace std;

int N, K, temp, ans, sum_count;
vector <int> v;
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		v.push_back(temp);
	}
	temp = v.size()-1;
	while (ans < K) {
		if (ans + v[temp] <= K) {
			ans += v[temp];
			sum_count++;
		}
		else {
			temp--;
		}
	}
	printf("%d", sum_count);
}