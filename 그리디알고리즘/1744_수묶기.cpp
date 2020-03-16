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
	
	for (; left < right; left+=2) {   // �������� 0������ ���ϴ°� �̵�
		if (v[left + 1] < 1 && v[left] < 1) {
			ans += v[left] * v[left + 1];   //���ϱ� 
		}
		else
			break;
	}

	for (; right > 0; right -= 2) {      // 1���� ū ����� ���ϴ°� ����. 
		if (v[right] > 1 && v[right - 1] > 1) {
			ans += v[right] * v[right - 1];
		}
		else
			break;
	}

	for (; left <= right;left++) {  //���� ��  ���ؾ� �Ѵ�.
		ans += v[left];
	}

	printf("%d", ans);
}