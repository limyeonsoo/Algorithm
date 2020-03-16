#pragma warning(disable:4996)
// 2020-02-16
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <int> v;
int ans;
int main() {
	scanf("%d", &N);
	v.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());
	int left = 0;
	int right = v.size()-1;
	
	for (; left < right; left+=2) {   // 음수에서 0까지는 곱하는게 이득
		if (v[left + 1] < 1 && v[left] < 1) {
			ans += v[left] * v[left + 1];   //곱하기 
		}
		else
			break;
	}

	for (; right > 0; right -= 2) {      // 1보다 큰 양수는 곱하는게 좋다. 
		if (v[right] > 1 && v[right - 1] > 1) {
			ans += v[right] * v[right - 1];
		}
		else
			break;
	}

	for (; left <= right;left++) {  //남은 수  더해야 한다.
		ans += v[left];
	}

	printf("%d", ans);
}