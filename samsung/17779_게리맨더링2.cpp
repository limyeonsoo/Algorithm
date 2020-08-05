
/*
	경계선 활용 : 
	1 : (x, y), (x+1, y-1), ..., (x+d1, y-d1)
	2 :	(x, y), (x+1, y+1), ..., (x+d2, y+d2)
	3 :	(x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
	4 :	(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)

	선거구 영역 활용 : 
	1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
	2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
	3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
	4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N

	d1, d2를 정한다. (
	  d1, d2 ≥ 1, 
	  1 ≤ x < x+d1+d2 ≤ N, 
	  1 ≤ y-d1 < y < y+d2 ≤ N
	)
	SOLVE : 
	1. 1~4 인구를 구하면 5는 자동으로 나온다.
	2-0. x, y를 지정한다. 
	     (d1, d2 는 1이상 이므로 x = 1~N-2까지)
		 (y-d1은 1보다 크거나 같으므로 y는 2보다 크거나 같다.
		 (y+d2는 N보다 작거나 같으므로 y는 N-1보다 작거나 같다.
	2-1. d1, d2 의 candidate를 구한다.
	{
		d1 <= y-1 && d1 <= N-1-x
		d2 <= N-x-d1 && d2 <= N-y
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, total_sum, mini = 0x7fffffff;
vector <vector <int> > A;  // r행 c열
vector <vector <int> > border;  // 5구역 테두리 : 유동적이라 미리 구해 놓는다.
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A.resize(N + 1);								  // y 좌표 index가 1부터
	for (int i = 0; i <= N; i++) A[i].resize(N + 1);  // x 좌표 1부터 N 
	border.resize(N + 1);
	for (int i = 0; i <= N; i++) border[i].resize(N + 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			total_sum += A[i][j];      // total sum;
		}
	}
}
void borderFifth(int x, int y, int d1, int d2) {
	// border초기화
	for (int i = 0; i <= N; i++) for (int j = 0; j <= N; j++) border[i][j] = 0;
   
	//(x, y), (x+1, y-1), ..., (x+d1, y-d1)
	//(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
	for (int i = 0; i <= d1; i++) {  // 1,4 border
		border[x + i][y - i] = 5;
		border[x + d2 + i][y + d2 - i] = 5;
	}
	//(x, y), (x+1, y+1), ..., (x+d2, y+d2)
	//(x + d1, y - d1), (x + d1 + 1, y - d1 + 1), ... (x + d1 + d2, y - d1 + d2)
	for (int i = 0; i <= d2; i++) {  // 2,3 border
		border[x + i][y + i] = 5;
		border[x + d1 + i][y - d1 + i] = 5;
	}
}
int first(int x, int y, int d1, int d2) { // ==> 오른쪽 진행
	int sum = 0;
	for (int r = 1; r < x + d1; r++) { // ㅜ 아래쪽 진행
		for (int c = 1; c <= y; c++) { // ㅏ 오른쪽 진행
			if (border[r][c] == 5) break;
			sum += A[r][c];
		}
	}
	return sum;
}

int second(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int r = 1; r <= x + d2; r++) {   // ㅜ 아래쪽 진행
		for(int c = N; c >= y + 1; c--){  // ㅓ 왼쪽 진행
			if (border[r][c] == 5) break;
			sum += A[r][c];
		}
	}
	return sum;
}

int third(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int r = x + d1; r <= N; r++) {          // ㅜ 아래쪽 진행
		for (int c = 1; c < y - d1 + d2; c++) {  // ㅏ 오른쪽 진행
			if (border[r][c] == 5) break;
			sum += A[r][c];
		}
	}
	return sum;
}

int forth(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int r = x + d2 + 1; r <= N; r++) {      // ㅜ 아래쪽 진행
		for (int c = N; c >= y - d1 + d2; c--) { // ㅓ 왼쪽 진행
			if (border[r][c] == 5) break;
			sum += A[r][c];
		}
	}
	return sum;
}

int resultFourArea(int x, int y, int d1, int d2) {
	int a, b, c, d, e;
	borderFifth(x, y, d1, d2);
	a = first(x, y, d1, d2);
	b = second(x, y, d1, d2);
	c = third(x, y, d1, d2);
	d = forth(x, y, d1, d2);
	e = total_sum - (a + b + c + d);
	int Maximum = max(a, max(b, max(c, max(d, e))));
	int minimum = min(a, min(b, min(c, min(d, e))));
	return Maximum - minimum;	
}

int main() {
	input();   // 인구 수 입력 및 합계 구하기
	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; (d1<=N-1-x) && (d1<=y-1); d1++) {            // d1조건
				for (int d2 = 1; (d2<=N-y) && (d2<=N-x-d1); d2++) {  // d2조건
					// x, y, d1, d2가 주어졌을 때, 각 선거구의 인구를 구한다. 
					int temp = resultFourArea(x, y, d1, d2);
					//cout << temp <<" : " << x << "," << y<<"," << d1 << "," << d2 << '\n';
					mini = (mini > temp ? temp : mini);	
				}
			}
		}
	}
	cout << mini;
}

/*
	틀린 이유 : 경계선이 계단 식임.
	범위를 따라 그리면 최대 x, y까지의 직사각형.
	즉, 5인 곳을 빼주어야함.
	borderFifth();
*/