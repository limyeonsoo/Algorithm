//���� 1�ܰ� ������� 2839
//#include<cstdio>
//int N, sum;
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i <= N; i+=3) //3���� ���غ���.
//		if ((N - i) % 5 == 0) {
//			sum = (N - i) / 5 + i/3;
//			break;
//		}
//	printf("%d", sum != 0 ? sum: -1);
//}

#include <cstdio>
int N, cnt;
int main() {
	scanf("%d", &N);
	for (int i = 1; i*6 <= N; i ++) cnt++;
	printf("%d", cnt+1);
}