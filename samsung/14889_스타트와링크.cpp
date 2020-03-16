#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N;
int sumA, sumB;
int ans = 2100000000;
bool check[21];
bool checkS[11];
int S[21];
int SS[11];
int team[11];

vector <int> A_team;
vector <int> B_team;
vector <vector<int> > R;

void dfsA(int depth) {
	if (depth == 2) {
		sumA += R[SS[0]][SS[1]];
		return;
	}
	for (int& i: A_team) {
		if (checkS[i]) continue;
		checkS[i] = true;
		SS[depth] = i;
		dfsA(depth+1);
		checkS[i] = false;
	}
}
void dfsB(int depth) {
	if (depth == 2) {
		sumB += R[SS[0]][SS[1]];
		return;
	}
	for (int& i : B_team) {
		if (checkS[i]) continue;
		checkS[i] = true;
		SS[depth] = i;
		dfsB(depth + 1);
		checkS[i] = false;
	}
}
void dfs(int depth) {  //팀 구성 하기 위함.
	if (depth == N / 2) { // 팀 구성 순열 종료 조건.
		for (int i = 0; i < N / 2; i++) {
			team[S[i]] = 1;
		}
		
		for (int i = 0; i < N; i++) {
			if (team[i] == 1)  A_team.push_back(i);
			else B_team.push_back(i);
		}
		//  A_team 이 완성 되었다. vector안에 팀 구성원.
		
		for (int& a : A_team) {
			checkS[a] = true;
			SS[0] = a;
			dfsA(1);
			checkS[a] = false;
		}
		//B team 계산
		for (int& b : B_team) {
			checkS[b] = true;
			SS[0] = b;
			dfsB(1);
			checkS[b] = false;
		}
		if (abs(sumA - sumB) < ans) {
			ans = abs(sumA - sumB);
		}
		sumA = 0;
		sumB = 0;
		memset(team, 0, sizeof(team));
		A_team.clear();
		B_team.clear();
		return;
	}
	///////////////////////// dfs진행
	for (int i = 0; i < N; i++) {
		if (check[i]) continue;
		check[i] = true;
		if (i > S[depth - 1] && S[0] == 0) {
			S[depth] = i;
			dfs(depth + 1);
		}
		check[i] = false;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		R.resize(N);
		for (int j = 0; j < N; j++) {
			int temp;
			scanf("%d", &temp);
			R[i].push_back(temp);
		}
	}
	// 팀 구성원을 순열로.
	for (int i = 0; i < N; i++) {
		check[i] = true;
		S[0] = i;
		dfs(1);
		check[i] = false;
	}
	printf("%d", ans);
}
