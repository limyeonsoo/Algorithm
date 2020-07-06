#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
stack <int> s;
vector <char> answer;
int arr[100001], N, j;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++) {
		s.push(i);
		answer.push_back('+');
		while (!s.empty() && s.top() == arr[j]) {
			s.pop(); answer.push_back('-'); j++;
		}
	}
	if (!s.empty()) {
		printf("NO");
		return 0;
	}
	for (int i = 0; i < answer.size(); i++) printf("%c\n", answer[i]);
	return 0;
}