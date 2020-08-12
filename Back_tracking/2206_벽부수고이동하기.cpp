/*
	���� �ϳ��� �μ��� ��� :

	1. �� ���� 1�� 1���� ��θ� ����?
	2. 1�� �� ���� �������鼭 ��θ� Ž��? o -> x ���� ���� ��� �鸸X�鸸�� ���⵵ �ʿ�.

	���� BFS�� Ž���� ��� �ִܰ�ΰ� ��.
	��� ������ ����� �ȳ�.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
struct xyz {
	int x, y, z;
};
vector <vector<int> > base;
int check[1001][1001][2];  // ��ǥ �� step�� �� & wall�� �� 
queue <xyz> q;


int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int N, M, result = 2147483647;
string temp;
int main() {
	cin >> N >> M;
	base.resize(N + 1); for (int i = 1; i <= N; i++) base[i].resize(M + 1);
	
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		for (int j = 0; j < temp.size(); j++) {   // index �� 1,1����
			base[i][j+1] = temp[j]-'0';    
		}
	}

		/*
			���� ��� �ٲ۴�. 
			 ��θ� Ž���Ѵ�.
			�������´�.
		*/
	q.push({1,1,0 });
	check[1][1][0] = 1;   // step & wall
	while (!q.empty()) {
		xyz now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			xyz next = { now.x + dx[i], now.y + dy[i], now.z };
			if (next.x < 1 || N < next.x) continue;			// x ����
			if (next.y < 1 || M < next.y) continue;	    // y ����
			//if (check[next.first][next.second].first == 0 ) continue;     // �ߺ� ����
			
			if (base[next.x][next.y] == 1) {	
				/*  �� �̸� 
					���� �վ����°�
					ó�� �մ°��ΰ� �����ʿ�.
				*/
				if (next.z == 1) continue;
				check[next.x][next.y][1] = check[now.x][now.y][0] + 1;
				q.push({ next.x, next.y, 1 });
			}
			else if(base[next.x][next.y] == 0){
				if (check[next.x][next.y][next.z] != 0) continue;
				check[next.x][next.y][next.z] = check[now.x][now.y][next.z] + 1;
				q.push({ next.x, next.y, next.z });
			}
		}
	}
	
	if (check[N][M][0] == 0 && check[N][M][1] == 0) cout << "-1";
	else {
		if (check[N][M][0] == 0) cout << check[N][M][1];
		else if (check[N][M][1] == 0) cout << check[N][M][0];
		else cout << (check[N][M][0] < check[N][M][1] ? check[N][M][0] : check[N][M][1]);
	}
}


/*
	https://kswims.tistory.com/52

*/