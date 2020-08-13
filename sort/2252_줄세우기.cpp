/*
	���������� �̿�
	* �ܹ����̿�����.
	* ���������� ����� Ʈ���� �Ǿ���.
	
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, A, B;
vector <vector <int> > students;
vector <int> lines;
queue <int> q;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	students.resize(N + 1);
	lines.resize(N + 1);
	for (int i = 1; i <= M; i++) {
		cin >> A >> B;
		students[A].push_back(B);
		lines[B]++;                 // �տ� ���� ��� üũ
	}
}
void topologicalSort() {
	for (int i = 1; i <= N; i++)    // base
		if (lines[i] == 0)		    // ������ ������ ���� ���
			q.push(i);         
	while (!q.empty()) {
		int now = q.front(); q.pop();
		cout << now << ' ';
		for (auto& next : students[now]) {
			lines[next]--;
			if (lines[next] == 0)
				q.push(next);
		}

	}
}
int main() {
	input();
	topologicalSort();
}



/*
	�ٸ� root�� ��� ��ٷ�����.
	ex) 
	          -> 6
	   ->  2  -> 7 -> 8
	1  
	   ->  3  -> 9 -> 7
	
	   ->  4  
	   �� ��, 3->9->7 �� 3�� �������� 7�� ����� �� �� ����.
	   �� ������ ���� ������ lines --;

*/