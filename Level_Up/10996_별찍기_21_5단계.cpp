//#include <cstdio>
//int main() {
//	int N; scanf("%d", &N);
//	if (N == 1) printf("*");
//	else {
//		for (int j = 1; j <= 2 * N; j++) {
//			if (j % 2 == 1) {
//				for (int i = 1; i <= N - 1 + (i % 2); i++) {
//					printf("%s", i % 2 == 1 ? "*" : " ");
//				}
//				printf("\n");
//			}
//			else {
//				for (int i = 1; i <= N; i++) {
//					printf("%s", i % 2 == 1 ? " " : "*");
//				}
//				printf("\n");
//			}
//		}
//	}
//}

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
vector <int> v;
int N, S, county;
int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &S); v.resize(S); county = 0;
		for (int i = 0; i < S; i++)	scanf("%d", &v[i]);
		for (int i = 0; i < S; i++) v[i] > accumulate(v.begin(), v.end(), 0.0) / v.size() ? county++ : 0;
		printf("%.3f%%\n", (float)county / v.size() * 100);
	}
}