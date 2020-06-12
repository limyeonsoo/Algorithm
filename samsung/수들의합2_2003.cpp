//#include <iostream>
//using namespace std;
//int arr[10001][10001];
//int N, M, cnt;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++) {
//		cin >> arr[i][1];
//		if (arr[i][1] == M) cnt++;
//		for (int j = 2; j <= i; j++) {
//			arr[i][j] = arr[i][1] + arr[i - 1][j-1];
//			if (arr[i][j] == M) cnt++;
//		}
//	}
//	cout << cnt;
//}

// 투포인터
#include <iostream>
using namespace std;
int arr[10001];
int N, M, result;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int start = 1, end = 1, sum = 0;
	for (;;) {
		
		if (sum >= M) sum -= arr[start++];
		else if (end == N + 1) break;
		else sum += arr[end++];
		
		if (sum == M) result++;
	}
	cout << result;
}