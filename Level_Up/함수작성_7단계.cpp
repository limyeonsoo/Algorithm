//#include <vector>
//long long sum(std::vector<int>& a) {
//	long long ans = 0;
//	for (int i = 0; i < a.size(); i++) ans += a[i];
//	return ans;
//}

//#include <iostream>
//using namespace std;
//
//bool check[10001];
//void func(int n) {
//	if (check[n] == true) return;	
//	if (n < 10) {
//		func(n + n);
//		check[n + n] = true;
//	}
//	else if(n < 100) {
//		func(n + n % 10 + n / 10);
//		check[n + n % 10 + n / 10] = true;
//	}
//	else if (n < 1000) {
//		func(n + (n % 10) + (n / 10 % 10) + n / 100);
//		check[n + (n % 10) + (n / 10 % 10) + n / 100] = true;
//	}
//	else if (n < 10000) {
//		func(n + n % 10 + (n / 10 % 10) + (n / 100 % 10) + (n / 1000));
//		check[n + n % 10 + (n / 10 % 10) + (n / 100 % 10) + (n / 1000)] = true;
//	}
//	return;
//}
//
//int main() {
//	for (int i = 1; i <= 10000; i++) {
//		if (check[i] == true) continue;
//		func(i);
//	}
//	for (int i = 1; i <= 10000; i++) {
//		if (check[i] == false) printf("%d\n", i);
//	}
//}

#include <iostream>
using namespace std;
int main() {
	int A[3];
	int N, temp; scanf("%d", &N);
	if (N < 100)printf("%d", N);
	else if (N == 1000)printf("144");
	else {
		int count = 99;
		for (int i = 100; i <= N; i++) {
			temp = i;
			A[2] = temp % 10;
			temp /= 10;
			A[1] = temp % 10;
			A[0] = temp / 10;
			if ((A[1] - A[0]) == (A[2] - A[1])) count++;
		}
		printf("%d", count);		
	}
}