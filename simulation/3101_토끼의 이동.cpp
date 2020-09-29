/*
	대각선을 구하자.
	대각선의 최대값은  1, 3, 6, 10, 15
						2, 3, 4, 5 .. ... 로 증가.
	***
	N번째 대각선 이후는 증가량이 감소.
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
	//갱신 필요
	if (!maxDiagnol[position.diagnol]) {
		if (position.diagnol <= N)
			maxDiagnol[position.diagnol] = maxDiagnol[position.diagnol - 1] + position.diagnol;
		else
			maxDiagnol[position.diagnol] = maxDiagnol[position.diagnol - 1] + (N - (position.diagnol - N));
	}
	//std::cout << "(" << position.x << ',' << position.y << ')' << '\n';
	if (position.diagnol <= N) {
		//짝수 번째 대각선이면 감소한다.
		if (position.diagnol % 2 == 0) {
			//std::cout << maxDiagnol[position.diagnol] - position.x + 1 << '\n';
			ans += maxDiagnol[position.diagnol] - position.x + 1;//0부터 시작이 아님.
		}//홀수 번째 대각선이면 증가한다.
		else {  //(maxDiagnol[position.diagnol] - (position.diagnol - 1) => x1좌표가 가장 작은 수)
			//std::cout << maxDiagnol[position.diagnol] - (position.diagnol - 1) + position.x - 1 << '\n';
			ans += maxDiagnol[position.diagnol] - (position.diagnol - 1) + position.x - 1; //0부터 시작이 아님.
		}
	}
	else {
		//짝수 번째 대각선이면 감소한다.
		if (position.diagnol % 2 == 0) {
			//std::cout << maxDiagnol[position.diagnol] - (N - position.y) << '\n';
			ans += maxDiagnol[position.diagnol] - (N - position.y);
		}//홀수 번째 대각선이면 증가한다.
		else {  //(maxDiagnol[position.diagnol] - (position.diagnol - 1) => x1좌표가 가장 작은 수)
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