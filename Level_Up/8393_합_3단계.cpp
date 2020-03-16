#pragma warning(disable:4996)
#include <iostream>
int main() {
	int a, ans=0; scanf("%d", &a);
	for (int i = 1; i <= a; i++) {
		ans += i;
	}
	printf("%d", ans);
}