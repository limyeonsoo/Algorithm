#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct {
	int pop;
	vector <int> near;
}area;

unsigned int bitmasking = 0; // ������ 10���� bitmask
int N, s, temp, total_pop, mini = 100000000;
vector <area> a;

queue <int> q;

pair<bool, int> checkCycle(int depth, unsigned int check_node) { 
	for (int i = 1; i <= N; i++) { //������
		int sum = 0, cnt = 0;
		unsigned int check = 0;
		if (check_node & (1 << i)) {  // ��ϵ� ����
			q.push(i);
			while (!q.empty()) {
				int now = q.front(); q.pop();
				for (int& next : a[now].near) {
					if (check & (1 << next)) continue;
					if (check_node & (1 << next)) { // ��ϵ� ������ ����
						q.push(next);
						check |= (1 << next);
						sum += a[next].pop;
						cnt++;
					}
				}
			}
			// ��ϵ� ������ �� ������ ��,
			if (cnt == depth) { // �� �������� ����,
				return make_pair(true, sum);
			}
			else {
				return make_pair(false, 0);
			}
		}
	}
	return make_pair(false, 0);
}


void dfs(int now, int depth, int blue_sum, unsigned int check_blue) {  //�Ķ����� check_blue == -1 �� ���Ѵ�.
	// �̶�, blue ������ check_blue; depth��ŭ�� ��
	// �׷��� red ������ check_red = check_blue �� �ݴ�
	int diff = abs(blue_sum - (total_pop - blue_sum));
	if (mini > diff) { // �ּ� ���̰� ������ ����Ŭ�� Ȯ���Ѵ�.
		
		pair<bool, int> red, blue;
		unsigned int check_red = 0;
		for (int i = 1; i <= N; i++)
			check_red = ((check_blue & (1 << i) ? check_red : check_red | (1 << i)));
		red = checkCycle(N - depth, check_red);
		//blue �� check �ʿ� X => ���� �Ǵ� ���� �Ա� ����.
		
		if (red.first) { //red�� cycle�� �����ϸ�
		//blue�� sum�� ���Ѵ�.  red sum�� red.second
		// blue sum�� total_sum - red.second;
			mini = abs(red.second - (total_pop - red.second));
		}
	}
	

	for (int i = 1; i <= N; i++) {
		if (check_blue & (1 << i)) continue;  //�̹� �湮 ������ X
		bool connection = false;
		for (int pre = 1; pre <= N; pre++) {
			if (!(check_blue & (1 << pre))) continue;
			// ** �߿� : now������ ��������, team ��ü���� ���� ���� �� �� �ִ�. ** //
			if (a[pre].near.end() != find(a[pre].near.begin(), a[pre].near.end(), i)) {
				connection = true;
				break;  
			}
		}
		if (connection) {
			check_blue |= (1 << i);
			dfs(i, depth + 1, blue_sum+a[i].pop, check_blue);
			check_blue &= ~(1 << i);
		}
	}
}

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	a.resize(N + 1);  // index�� 1����

	for (int i = 1; i <= N; i++) {	
		cin >> a[i].pop;        // �� ���� �α���
		total_pop += a[i].pop;  // �� �α��� ��
	}

	for (int i = 1; i <= N; i++) {
		cin >> s;
		for (int j = 0; j < s; j++) {
			cin >> temp;
			a[i].near.push_back(temp); // ���� ��� �Է�  //�����
		}
	}
}

int main() {
	input();  // ���� �α�, ������ �̿� ������ ���� �迭 a����

	if (N == 2) {  // ������ 2���� �ٷ� �ذ� ����.
		cout << abs(a[1].pop - a[2].pop);
		return 0;
	}

	for (int i = 1; i <= N; i++) { // �������� �� ������
		bitmasking |= (1 << i);    // i ���� üũ ��
		dfs(i, 1, a[i].pop, bitmasking);
		bitmasking = 0;            // ����
	}

	cout << (mini == 100000000 ? -1 : mini);
}


/*
Ʋ�� ���̽� : 
8
17 42 46 81 71 8 37 12
4 2 4 5 7
5 1 3 4 5 8
2 2 4
5 1 2 3 7 8
5 1 2 6 7 8
2 5 8
4 1 4 5 8
5 2 4 5 6 7
ans : 2  but : 4

reason : 1 3 4 8 vs 1 4 5 6 // 156 vs 158
 ���������� �ۿ� ���� ������.

*/

/* 
Ʋ�� ���̽� : 
2
3 4 
0
0
ans : 1  but : -1

reason : ���̸� ���ϴ� ���ε�, 
  near�� 0�̶� ������ ���� ���� dfs�� ���� ���� -1�� ��ȯ.

*/

/*
�ð� �ʰ� : 
  ����Ŭ�� Ȯ�� �� -> �ּҰ��� ���ߴ�.
  �ּҰ��� �����ϸ� => ����Ŭ�� Ȯ���Ѵ�.
*/