/*
	�밢���� ������.
	�밢���� �ִ밪��  1, 3, 6, 10, 15
						2, 3, 4, 5 .. ... �� ����.
	***
	N��° �밢�� ���Ĵ� �������� ����.
	15  21  26  30  33  35  36
	  6   5   4    3   2   1 

*/

#include <iostream>
#include <vector>
#define ll long long
struct Coord {
	ll x;
	ll y;
	ll diagnol;
};
ll N, K, ans;
char moving;
Coord now = { 1,1,1};
ll maxDiagnol[200001];
void calcDiagnol(Coord position) {
	//���� �ʿ�
	if (!maxDiagnol[position.diagnol]) {
		if (position.diagnol <= N)
			maxDiagnol[position.diagnol] = maxDiagnol[position.diagnol - 1] + position.diagnol;
		else
			maxDiagnol[position.diagnol] = maxDiagnol[position.diagnol - 1] + (N - (position.diagnol - N));
	}
	//std::cout << "(" << position.x << ',' << position.y << ')' << '\n';
	if (position.diagnol <= N) {
		//¦�� ��° �밢���̸� �����Ѵ�.
		if (position.diagnol % 2 == 0) {
			//std::cout << maxDiagnol[position.diagnol] - position.x + 1 << '\n';
			ans += maxDiagnol[position.diagnol] - position.x + 1;//0���� ������ �ƴ�.
		}//Ȧ�� ��° �밢���̸� �����Ѵ�.
		else {  //(maxDiagnol[position.diagnol] - (position.diagnol - 1) => x1��ǥ�� ���� ���� ��)
			//std::cout << maxDiagnol[position.diagnol] - (position.diagnol - 1) + position.x - 1 << '\n';
			ans += maxDiagnol[position.diagnol] - (position.diagnol - 1) + position.x - 1; //0���� ������ �ƴ�.
		}
	}
	else {
		//¦�� ��° �밢���̸� �����Ѵ�.
		if (position.diagnol % 2 == 0) {
			//std::cout << maxDiagnol[position.diagnol] - (N - position.y) << '\n';
			ans += maxDiagnol[position.diagnol] - (N - position.y);
		}//Ȧ�� ��° �밢���̸� �����Ѵ�.
		else {  //(maxDiagnol[position.diagnol] - (position.diagnol - 1) => x1��ǥ�� ���� ���� ��)
			//std::cout << maxDiagnol[position.diagnol] - (N - (position.diagnol - N) - 1) + (N - position.y) << '\n';
			ans += maxDiagnol[position.diagnol] - (N - (position.diagnol - N) - 1) + (N - position.y);
		}
	}
	
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> K;
	calcDiagnol({ 1,1,1 });
	for (ll i = 0; i < K; i++) {
		std::cin >> moving;
		switch (moving) {
		case 'U':
			now = { now.x, now.y - 1, now.diagnol - 1 };
			break;

		case 'D':
			now = { now.x, now.y + 1, now.diagnol + 1 };
			break;

		case 'L':
			now = { now.x - 1, now.y, now.diagnol - 1 };
			break;

		case 'R':
			now = { now.x + 1, now.y, now.diagnol + 1 };
			break;
		}
		calcDiagnol(now);
	}
	std::cout << ans;
	
}