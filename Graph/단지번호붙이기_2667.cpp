#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N;

queue <pair<int, int>> q;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt[26][26];
char d[26][26];
int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", d[i]);
	}  //���簢�� �Է� �Ϸ�.
	int step = 0;
	int result[400] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (cnt[i][j] == 0 && d[i][j] == '1') {    //���ε� �湮��������,
				q.push({ i, j });
				cnt[i][j] = ++step;
				result[step]++;           //���� ���� ���� �� �� �ΰ��� ���� ����. 
				//q.push(make_pair(0, 0));
				while (!q.empty()) {   //��ó 4���⿡ �湮���� ���� ���� �ִٸ� ť�� ��� �� ����. 
					pair<int, int> curr = q.front(); q.pop();
					for (int i = 0; i < 4; i++) {
						pair<int, int> next = { curr.first + dx[i], curr.second + dy[i] };

						if (next.first < 0 && next.first >= N && next.second < 0 && next.second >= N) continue;
						if (cnt[next.first][next.second] == 0 && d[next.first][next.second] == '1') { //���ƾ��Ѵ�.
							cnt[next.first][next.second] = step;
							q.push(next);
							result[step]++;
						}
					}
				}
			}
		}
	}
	printf("%d\n", step);
	sort(result + 1, result + step+1);
	for (int i = 1; i <= step; i++) {
		printf("%d\n", result[i]);
	}
}

////////////////////////////////////////////////////////////DFS///////////////////////////////////
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//char d[26][26];
//int cnt[26][26];
//int N;
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { -1,1,0,0 };
//
//void dfs(int x, int y, int step) {
//	cnt[x][y] = step;  //�湮�ߴ�. 
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dx[i]; int ny = y + dy[i];
//		if (nx < 0 && nx >= N && ny < 0 && ny >= N) continue;
//		if (cnt[nx][ny] == 0 && d[nx][ny] == '1') {
//			dfs(nx, ny, step);
//		}
//	}
//	return;
//}
//
//int main() {
//	scanf("%d", &N);
//
//	int step = 1;
//	int temp;
//
//	for (int i = 0; i < N; i++) {
//		scanf("%s", d[i]);
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (cnt[i][j] == 0 & d[i][j] == '1') { //���̰�, ������ ������
//				dfs(i, j, step);
//				step++;
//			}
//		}
//	}
//	int result[350] = { 0, };
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			result[cnt[i][j]]++;
//		}
//	}
//
//	sort(&result[1], &result[step]);
//
//	printf("%d\n", step - 1);
//	for (int i = 1; i < step; i++) {
//		printf("%d\n", result[i]);
//	}
//}
