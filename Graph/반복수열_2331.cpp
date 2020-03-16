#pragma warning(disable:4996)
#include <iostream>
#include <vector>
using namespace std;

int A, P; 
int cnt[1000000];
int check_count = 0; 

int pow(int a) {     //라이브러리의 pow는 double형이므로 하나 만듬. 
	int answer = 1;
	for (int i = 0; i < P; i++) {
		answer = answer * a;
	}
	return answer;
}

int next(int x) {
	int ans=0;

	while (x > 0) {
		ans = ans + pow(x % 10);
		x /= 10;
	}
	return ans;
}
int bfs(int A) {
	if (cnt[A] != 0) return cnt[A] - 1;
	cnt[A] = ++check_count;

	return bfs(next(A));
}
int main() {
	scanf("%d%d", &A, & P);
	printf("%d", bfs(A));

}