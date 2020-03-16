#pragma warning (disable:4996)
#include <iostream>
using namespace std;
char A[50][2];
void pre_order(char a) {
	if (a == '.') return;
	cout << a;
	pre_order(A[a][0]);
	pre_order(A[a][1]);
}
void in_order(char a) {
	if (a == '.') return;
	in_order(A[a][0]);
	cout << a;
	in_order(A[a][1]);
}
void post_order(char a) {
	if (a == '.') return;
	post_order(A[a][0]);
	post_order(A[a][1]);
	cout << a;
}
int main() {
	int N;
	char x, y, z;
	cin >> N;
	while (N--) {
		cin >> x >> y >> z;
		y == '.' ? A[x][0] = '.' : A[x][0] = y;
		z == '.' ? A[x][1] = '.' : A[x][1] = z;
	}
	pre_order('A'); cout << '\n';
	in_order('A'); cout << '\n';
	post_order('A');
}