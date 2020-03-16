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

	int m = 0;   // ���� ���� ī�� ����
	long long ans;  // ���� ���� ī�� ����
	for (auto& p : d) {
		if (p.second > m) {   // ���ݱ��� ���� �ִ� ī�尹������ ũ��.
			m = p.second;
			ans = p.first;
		}
		else if (p.second == m && p.first < ans) {  // ī�� ������ ������, ������ ���� ���� �۴�.
			ans = p.first;
		}
	}
	printf("%lld", ans);
}