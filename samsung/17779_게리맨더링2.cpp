
/*
	��輱 Ȱ�� : 
	1 : (x, y), (x+1, y-1), ..., (x+d1, y-d1)
	2 :	(x, y), (x+1, y+1), ..., (x+d2, y+d2)
	3 :	(x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
	4 :	(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)

	���ű� ���� Ȱ�� : 
	1�� ���ű�: 1 �� r < x+d1, 1 �� c �� y
	2�� ���ű�: 1 �� r �� x+d2, y < c �� N
	3�� ���ű�: x+d1 �� r �� N, 1 �� c < y-d1+d2
	4�� ���ű�: x+d2 < r �� N, y-d1+d2 �� c �� N

	d1, d2�� ���Ѵ�. (
	  d1, d2 �� 1, 
	  1 �� x < x+d1+d2 �� N, 
	  1 �� y-d1 < y < y+d2 �� N
	)
	SOLVE : 
	1. 1~4 �α��� ���ϸ� 5�� �ڵ����� ���´�.
	2-0. x, y�� �����Ѵ�. 
	     (d1, d2 �� 1�̻� �̹Ƿ� x = 1~N-2����)
		 (y-d1�� 1���� ũ�ų� �����Ƿ� y�� 2���� ũ�ų� ����.
		 (y+d2�� N���� �۰ų� �����Ƿ� y�� N-1���� �۰ų� ����.
	2-1. d1, d2 �� candidate�� ���Ѵ�.
	{
		d1 <= y-1 && d1 <= N-1-x
		d2 <= N-x-d1 && d2 <= N-y
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, total_sum, mini = 0x7fffffff;
vector <vector <int> > A;  // r�� c��
vector <vector <int> > border;  // 5���� �׵θ� : �������̶� �̸� ���� ���´�.
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A.resize(N + 1);								  // y ��ǥ index�� 1����
	for (int i = 0; i <= N; i++) A[i].resize(N + 1);  // x ��ǥ 1���� N 
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
	// border�ʱ�ȭ
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
int first(int x, int y, int d1, int d2) { // ==> ������ ����
	int sum = 0;
	for (int r = 1; r < x + d1; r++) { // �� �Ʒ��� ����
		for (int c = 1; c <= y; c++) { // �� ������ ����
			if (border[r][c] == 5) break;
			sum += A[r][c];
		}
	}
	return sum;
}

int second(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int r = 1; r <= x + d2; r++) {   // �� �Ʒ��� ����
		for(int c = N; c >= y + 1; c--){  // �� ���� ����
			if (border[r][c] == 5) break;
			sum += A[r][c];
		}
	}
	return sum;
}

int third(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int r = x + d1; r <= N; r++) {          // �� �Ʒ��� ����
		for (int c = 1; c < y - d1 + d2; c++) {  // �� ������ ����
			if (border[r][c] == 5) break;
			sum += A[r][c];
		}
	}
	return sum;
}

int forth(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int r = x + d2 + 1; r <= N; r++) {      // �� �Ʒ��� ����
		for (int c = N; c >= y - d1 + d2; c--) { // �� ���� ����
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
	input();   // �α� �� �Է� �� �հ� ���ϱ�
	for (int x = 1; x <= N - 2; x++) {
		for (int y = 2; y <= N - 1; y++) {
			for (int d1 = 1; (d1<=N-1-x) && (d1<=y-1); d1++) {            // d1����
				for (int d2 = 1; (d2<=N-y) && (d2<=N-x-d1); d2++) {  // d2����
					// x, y, d1, d2�� �־����� ��, �� ���ű��� �α��� ���Ѵ�. 
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
	Ʋ�� ���� : ��輱�� ��� ����.
	������ ���� �׸��� �ִ� x, y������ ���簢��.
	��, 5�� ���� ���־����.
	borderFifth();
*/