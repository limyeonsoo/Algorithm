#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct tree{
	int x;
	int y;
	int z;
};
int N, M, K; // N*N��, M���� ���� ���� x,y,z x,y��ġ  z�� ����  K�� ���� ��
int x, y, z;
vector <vector<vector<int>>> garden;
vector <vector<int>> gradient;
vector <tree> Tree; //������

void spring() {  //�ڽ��� ���� (garden�� �� ��ŭ)��� �԰� 1 ����. ���� �� ������� � ������. ��� ������ �״´�.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (garden[i][j].size() != 0) {  //������ �ִ�.
				sort(garden[i][j].begin(), garden[i][j].end());
				for (int t = 0; t < garden[i][j].size(); t++) {
					if (gradient[i][j] >= garden[i][j][t]) { //����� ���� �� �ִ�.
						gradient[i][j] -= garden[i][j][t];
						garden[i][j][t] += 1;
					}
					else { //t���Ĵ� �� �״´�.
						for (int g = t; g < garden[i][j].size(); g++) {
							Tree.push_back({ j,i,garden[i][j][g] });
						}
						garden[i][j].erase(garden[i][j].begin() + t, garden[i][j].end());
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K;
	garden.resize(N); for (int i = 0; i < N; i++) garden[i].resize(N);
	gradient.resize(N); for (int i = 0; i < N; i++) gradient[i].resize(N);
	for (int i = 0; i < N; i++) { // �� ���� �Է� �ޱ�.
		for (int j = 0; j < N; j++) {
			cin >> gradient[i][j];       //���
		}
	}
	for (int i = 0; i < M; i++) {  //���� ���� �Է� �ޱ�.
		cin >> x >> y >> z;
		garden[y-1][x-1].push_back(z);   //�ε����� 0���� ����.
	}
	
	
}
