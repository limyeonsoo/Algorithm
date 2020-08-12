/*
	*  1 != 2
	*  N-1 != N           
	*  i-1 != i != i+1    ( 2<= i <= N-1 )
	
	red -> blue -> gree -> blue -> red 

	Red -> Green -> Blue

	1000 개의 집
	1000 * 999* 998  1억정도 브루투포스도 될듯.

	3개일 때, 마지막이 R 인 경로는
	R G R
	R B R
	G B R
	B G R
	2 번 또는 3번의 1번은 돌아온다. (저장 일 듯)
	R입장에서 바로 전 만 다르면 됨.
*/

#include <cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
typedef struct {
	int R, G, B;
}RGB;
RGB now, pre, input;
int home;
int main() {
	scanf("%d", &home);
	for (int i = 1; i <= home; i++) {
		scanf("%d%d%d", &input.R, &input.G, &input.B);
		pre = now;
		now.R = min(pre.G, pre.B) + input.R;
		now.G = min(pre.R, pre.B) + input.G;
		now.B = min(pre.R, pre.G) + input.B;
	}
	printf("%d", min(now.R, min(now.G, now.B)));
}