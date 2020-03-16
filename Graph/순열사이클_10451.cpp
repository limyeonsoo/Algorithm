#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int K, N, p; 
vector <int> v(1001);
int check[1001];
void dfs(int x) {       //������ �� ������ �ϳ����� ����Ǿ������Ƿ�, for�� �ʿ� X
	if (check[x] != 0) return;
	check[x] = 1;
	x = v[x];
	dfs(x);
}

int main() {
	scanf("%d", &K);
	while (K--) {
		int count = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &p);
			v[i]=p;                      // 1���� �迭   �� ������ ����� ������ �� �ϳ�,
		}
		for (int i = 1; i <= N; i++) {
			if (check[i] == 0) {         //�湮���� �ʾ����� dfs�� count++
				dfs(i);
				count++;                 //�����Ҹ� ���ϴ� count.
			}
		}
		memset(check, 0, sizeof(check));
		printf("%d\n", count);
	}

}