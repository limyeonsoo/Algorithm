/*
�ʷ� , ����  ������ �Ѹ� ��ġ�� ���ؾ���.
���ÿ� ������ �� ��.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef struct{
	int x;
	int y;
}coord;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int X, Y, G, R, med;
int garden[51][51];      //garden �Է�  ȣ��, ��, ���װ��� ��
vector <pair<coord, bool>> culture;

pair<int, int> check_flower[51][51];    //first �� G, or R  second�� ��
vector <pair <coord, int>> cand_R;
vector <pair <coord, int>> cand_G;

queue <coord> q;
int result = 0;

void gardening() {
	for (int y = 0; y < Y; y++) {           //�ʱ�ȭ.
		for (int x = 0; x < X; x++) {
			check_flower[y][x].first = 0;
			check_flower[y][x].second = 0;
		}
	}
	med = G;
	int cnt = 0;  //flower 3 �� count;
	for (int j = 0; j < R; j++) {   //����(2�� ��)���� bfs�� ���´�
		check_flower[cand_R[j].first.y][cand_R[j].first.x].first = 1;  //1�� G 2�� R  3�� flower
		q.push({ cand_R[j].first.x, cand_R[j].first.y });
		med--;
	}
	for (int j = 0; j < G; j++) {   //����(2�� ��)���� bfs�� ���´�
		check_flower[cand_G[j].first.y][cand_G[j].first.x].first = 2;  //1�� G 2�� R  3�� flower
		q.push({ cand_G[j].first.x, cand_G[j].first.y });
		med--;
	}  //ť�� ���� ���� �й� �Ϸ�.
	while (!q.empty()) {
		coord now = q.front(); q.pop();
		if (check_flower[now.y][now.x].first == 3) continue;  // �̹� flower�̸� Ȯ�� �ʿ� X
		for (int k = 0; k < 4; k++) { //����.
			coord next = { now.x + dx[k], now.y + dy[k] };
			if (!(0 <= next.x && next.x < X && 0 <= next.y && next.y < Y)) continue;// ���� ���� ���� ����.
			if (garden[next.y][next.x] == 0) continue;
			if (check_flower[next.y][next.x].first == 3) continue;  // �̹� flower�̸� Ȯ�� �ʿ� X
			if (check_flower[next.y][next.x].first == 0) { //���� ������ ���� ��.
				check_flower[next.y][next.x].first = check_flower[now.y][now.x].first;            //G�� R�� ������.
				check_flower[next.y][next.x].second = check_flower[now.y][now.x].second + 1;// �ʴ� �ٲ��.
				q.push(next);
			}
			else if (check_flower[now.y][now.x].first == 1 && check_flower[next.y][next.x].first == 2) { //R�� ���� G��
				if (check_flower[now.y][now.x].second + 1 != check_flower[next.y][next.x].second) continue;
				check_flower[next.y][next.x].first = 3;
				cnt++;
			}
			else if (check_flower[now.y][now.x].first == 2 && check_flower[next.y][next.x].first == 1) { //R�� ���� G��
				if (check_flower[now.y][now.x].second + 1 != check_flower[next.y][next.x].second) continue;
				check_flower[next.y][next.x].first = 3;
				cnt++;
			}
		}
	}
	if (result < cnt) result = cnt;
}
void permutation_R(int depth) {
	if (depth == R) { //cand�� ������ �̿��Ѵ�.
		gardening();
		return;
	}
	for (int i = depth == 0 ? 0 : cand_R[depth - 1].second + 1; i < culture.size(); i++) {
		if (culture[i].second == true) continue;
		culture[i].second = true;
		cand_R[depth] = { { culture[i].first.x, culture[i].first.y },i };
		permutation_R(depth + 1);
		culture[i].second = false;
	}
}

void permutation_G(int depth) {
	if (depth == G) { //cand�� ������ �̿��Ѵ�.
		permutation_R(0);
		return;
	}
	for (int i = depth == 0 ? 0 : cand_G[depth - 1].second + 1; i < culture.size(); i++) {
		if (culture[i].second == true) continue;
		culture[i].second = true;
		cand_G[depth] = {{ culture[i].first.x, culture[i].first.y }, i};
		permutation_G(depth+1);
		culture[i].second = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Y >> X >> G >> R;
	
	for (int i = 0; i < Y; i++)
		for (int j = 0; j < X; j++) {
			cin >> garden[i][j];
			if(garden[i][j] == 2) culture.push_back({ { j,i },false }); //��ǥ�� bool
		}
			//scanf("%d", &garden[i][j]);    //0 : ȣ��  1 : ���� X  2: ���� O
		   // ���� �Է� �޾���.

	 // TODO : G R �Ѹ� ���� ã�ƾ���. 2~10��
	 // �ߺ����� �ʴ� ����. ���� X
	cand_R.resize(R);
	cand_G.resize(G);
	permutation_G(0);
	cout << result << '\n';
	//printf("\n%d", result);
}
