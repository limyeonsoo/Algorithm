#include <cstdio>
int main() {
	int result = 0, score;
	for (int i = 0; i < 5; i++) {
		scanf("%d", &score);
		result+= score<=40?40:score;
	}
	printf("%d", result / 5);
}