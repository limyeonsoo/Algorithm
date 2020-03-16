#pragma warning(disable:4996)
//https://gist.github.com/Baekjoon/fd3b8be64b4dfa723da6
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//int main() {
//	int K;
//	int N;
//	
//	scanf("%d %d", &N, &K);
//	vector <int> v(N);
//	for (int i = 0; i < N; i++) {
//		scanf("%d", &v[i]);
//	}
//	sort(v.begin(), v.end());
//	printf("%d", v[K-1]);
//}

int main() {
	int K;
	int N;

	scanf("%d %d", &N, &K);
	vector <int> v(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	int low = *v.begin();
	int high = v.size();
	int ans;
	while (low < high) {
		int pivot = (low + high) / 2;
		if (pivot == K) {
			ans = v[K]; 
			break;
		}
		if (pivot > K) {
			sort(v[low], v[pivot - 1]);
			high = pivot - 1;
		}
		else if(pivot < K) {
			sort(v[pivot + 1], v[high]);
			low = pivot + 1;
		}
	}
	printf("%d", ans);
}