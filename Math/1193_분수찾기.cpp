/*
1	2	6	7	15	16	28
3	5	8	14	17	27
4	9	13	18	26
10	12	19	25
11	20	24
21	23
22	
*/

#include <iostream>
using namespace std;
int main() {
	int N; scanf("%d", &N);
	pair <int, int> result(1, 1);
	int sum = 1; 
	int cnt = 1;
	for (int i = 1; i <= N; i++) {
		cnt += sum;
		sum++;
		if (cnt >= N) break;
		
	} //  분자 / 분모   분자+분모 = sum;
	// sum 홀수면 세로줄 짝수면 가로줄
	if (sum % 2 == 1 && cnt != N) {
		result.second = sum - 1;
	}
	else if (sum % 2 == 0 && cnt != N) {
		result.first = sum - 1;
	}
	else if (cnt == N && sum % 2 == 1) result.second = sum;
	else result.first = sum;
	while (cnt!=N) {
		cnt--;
		if (cnt == N) break;
		if (sum % 2 == 1) {
			result.second--;
			result.first++;
		}
		else {
			result.first--;
			result.second++;
		}
	}
	printf("%d/%d", result.second, result.first);
}