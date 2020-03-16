#pragma warning (disable:4996)
//#include <cstdio>
//int a[100001];
//int check[100001];
//int which_step[100001];
//int n;
//int dfs(int x, int cnt, int& step) {
//    if (check[x] != 0) {
//        if (step != which_step[x]) {
//            return 0;
//        }
//        return cnt - check[x];
//    }
//    check[x] = cnt;
//    which_step[x] = step;
//    return dfs(a[x], cnt + 1, step);
//}
//int main() {
//    int t;
//    scanf("%d", &t);
//    while (t--) {
//        scanf("%d", &n);
//        for (int i = 1; i <= n; i++) {
//            scanf("%d", &a[i]);
//            check[i] = 0;
//            which_step[i] = 0;
//        }
//        int ans = 0;
//        for (int i = 1; i <= n; i++) {
//            if (check[i] == 0) {
//                ans += dfs(i, 1, i);
//            }
//        }
//        printf("%d\n", n - ans);
//    }
//    return 0;
//}
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, n, want;
int v[100001];
int cnt[100001];     // cycle�� ã�Ҵٸ� cycle�� ��Ҹ� �˱� ���� üũ 
int cycled[100001];   // �ٸ� dfs���� �湮�ߴ����� Ȯ���Ѵ�. 

int dfs(int x, int count, int self) {
	if (cnt[x] != 0) {    // �湮�߾���.
		if (cycled[x] == self) {    // ���� dfs��ȣ�� �湮�߾��� dfs��ȣ�� ������ cycle
			return count - cnt[x];   //�����ҿ���  cycle�� �����ϴ� ������ ������ ���ϱ� ����. 
		}
		return 0;
	}
	cnt[x] = count;               // �� ������ �� �� �� ��° ����ΰ��� üũ�ϱ� ���� count
	cycled[x] = self;             // ��� ������ �� �� ��° �������ΰ��� üũ�ϱ� ���� ��ȣ

	return dfs(v[x], count + 1, self);
}
int main() {
	scanf("%d", &T);    // ���� ��
	while (T--) {
		int ans = 0;
		scanf("%d", &n);  //�л��� ��
		for (int i = 1; i <= n; i++) {
			scanf("%d", &want);
			v[i] = want;           // ���� �� �� ���� ����.
			cycled[i] = 0;
			cnt[i] = 0;
		}   

		for (int i = 1; i <= n; i++) {  //��� ������ ���ؼ� dfs 
			ans += dfs(i ,1, i);
		}
		printf("%d\n", n-ans);
	}
}