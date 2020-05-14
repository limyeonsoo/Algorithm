#include <iostream>
#include <algorithm>
using namespace std;
int N, M, tmp;
int arr[100001];
bool search(int tmp) {
	int start = 0;
	int end = N - 1;
	while (end - start >= 0) {
		int mid = (end + start)/2;
		if (arr[mid] == tmp) return true;
		if (arr[mid] > tmp) end = mid - 1;
		else start = mid + 1;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << (search(tmp) ? "1" : "0") << '\n';
	}
}