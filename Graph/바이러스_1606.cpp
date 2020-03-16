//#pragma warning (disable:4996)
//#include <iostream>
//#include <cstring>
//#include <vector>
//
//using namespace std;
//
//int VERTEX, EDGE, a,b;
//vector <int> v[101];
//int cnt[101];
//int count1 = 0;
//
//int dfs(int x) {
//	if (cnt[x] != 0)return count1;
//	cnt[x] = 1;
//	count1++; 
//	for (int i = 0; i < v[x].size(); i++) {
//		dfs(v[x][i]);
//	}
//}
//
//int main() {
//	scanf("%d", &VERTEX);
//	scanf("%d", &EDGE);
//	for (int i = 1; i <= EDGE; i++) {
//		scanf("%d%d", &a, &b);
//		v[a].push_back(b); v[b].push_back(a);
//	}
//	printf("%d",dfs(1));
//}

#pragma warning (disable:4996)
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int VERTEX, EDGE, a, b;
vector <int> v[101];
int cnt[101];
int count1 = 0;

int dfs(int x) {
	if (cnt[x] != 0)return count1;
	cnt[x] = 1;
	for (int i = 0; i < v[x].size(); i++)
		dfs(v[x][i]);
}

int main() {
	scanf("%d", &VERTEX);
	scanf("%d", &EDGE);
	for (int i = 1; i <= EDGE; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b); v[b].push_back(a);
	}
	dfs(1);
	for (int i = 0; i < 101; i++)
		if (cnt[i] == 1) count1++;
	printf("%d", count1-1);
}