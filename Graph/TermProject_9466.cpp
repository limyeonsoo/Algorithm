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
int cnt[100001];     // cycle을 찾았다면 cycle의 요소를 알기 위해 체크 
int cycled[100001];   // 다른 dfs에서 방문했는지를 확인한다. 

int dfs(int x, int count, int self) {
	if (cnt[x] != 0) {    // 방문했었다.
		if (cycled[x] == self) {    // 현재 dfs번호와 방문했었던 dfs번호가 같으면 cycle
			return count - cnt[x];   //연결요소에서  cycle을 구성하는 정점의 개수만 구하기 위함. 
		}
		return 0;
	}
	cnt[x] = count;               // 한 연결요소 돌 때 몇 번째 노드인가를 체크하기 위한 count
	cycled[x] = self;             // 모든 연결요소 중 몇 번째 연결요소인가를 체크하기 위한 번호

	return dfs(v[x], count + 1, self);
}
int main() {
	scanf("%d", &T);    // 테케 수
	while (T--) {
		int ans = 0;
		scanf("%d", &n);  //학생의 수
		for (int i = 1; i <= n; i++) {
			scanf("%d", &want);
			v[i] = want;           // 정점 당 한 개의 정점.
			cycled[i] = 0;
			cnt[i] = 0;
		}   

		for (int i = 1; i <= n; i++) {  //모든 정점에 대해서 dfs 
			ans += dfs(i ,1, i);
		}
		printf("%d\n", n-ans);
	}
}