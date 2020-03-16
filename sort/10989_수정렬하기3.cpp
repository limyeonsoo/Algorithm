#pragma warning(disable:4996)
#include <iostream>
using namespace std;
int cnt[10001];
int main() {
	int N, temp;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		cnt[temp]++;
	}

	for (int i = 1; i <= 10000; i++)
		if (cnt[i] > 0)
			for (int j = 0; j < cnt[i]; j++)
				printf("%d\n", i);
}