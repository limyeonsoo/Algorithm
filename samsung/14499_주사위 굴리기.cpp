/*
	����:
		�� -> ��
		�� -> �Ʒ�
		�Ʒ� -> ��
		�� -> ��
	����:
		�� -> ��
		�� -> �Ʒ�
		�Ʒ� -> ��
		�� -> ��
	����:  (�޿��� �ȹٲ��)
		�� -> ��
		�� -> �Ʒ�
		�Ʒ� -> ��
		�� -> ��
	���� : 
		�� -> ��
		�� -> �Ʒ�
		�Ʒ� -> ��
		�� -> ��
*/


#include <iostream>
#include <vector>

using namespace std;
int dx[5] = {0, 0, 0, -1, 1 };
int dy[5] = {0, 1, -1, 0, 0 };
int state[6]; //��, �Ʒ�, ��, ��, ��, ��
int N, M, x, y, K;
vector <vector<int> > base;
vector <int> queries;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> x >> y >> K;
	base.resize(N); for (int i = 0; i < N; i++) base[i].resize(M);
	queries.resize(K);
	for (int i = 0; i < N; i++)	for (int j = 0; j < M; j++) cin >> base[i][j];
	for (int i = 0; i < K; i++) cin >> queries[i];
}
bool inner(int x, int y) {
	return(0 <= x && x < N && 0 <= y && y < M);
}
void solve(int direction) {
	int temp[6];
	for (int i = 0; i < 6; i++) temp[i] = state[i];
	switch (direction) {
	case 1:
		state[0] = temp[2];
		state[2] = temp[1];
		state[1] = temp[3];
		state[3] = temp[0];
		break;
	case 2:
		state[0] = temp[3];
		state[3] = temp[1];
		state[1] = temp[2];
		state[2] = temp[0];
		break;
	case 3:
		state[0] = temp[4];
		state[4] = temp[1];
		state[1] = temp[5];
		state[5] = temp[0];
		break;
	case 4:
		state[0] = temp[5];
		state[5] = temp[1];
		state[1] = temp[4];
		state[4] = temp[0];
		break;
	}
}

int main() {
	input();
	for (auto &query : queries) {
		int next_x = x + dx[query], next_y = y + dy[query];
		if (!inner(next_x, next_y)) continue;
		x = next_x; y = next_y;
		solve(query);
		if (base[x][y] != 0) state[1] = base[x][y], base[x][y] = 0;
		else base[x][y] = state[1];
		cout << state[0] << '\n';
	}
}