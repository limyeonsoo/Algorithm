/*
	*  1 != 2
	*  N-1 != N           
	*  i-1 != i != i+1    ( 2<= i <= N-1 )
	
	red -> blue -> gree -> blue -> red 

	Red -> Green -> Blue

	1000 ���� ��
	1000 * 999* 998  1������ ����������� �ɵ�.

	3���� ��, �������� R �� ��δ�
	R G R
	R B R
	G B R
	B G R
	2 �� �Ǵ� 3���� 1���� ���ƿ´�. (���� �� ��)
	R���忡�� �ٷ� �� �� �ٸ��� ��.
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