/*
	에라토스테네스 체 변형해야함.
*/
#include <iostream>
#include <math.h>
using namespace std;
int A, B;
//bool erathos[100001] = { true, true };
//void erathos_chae() {
//	for (int i = 2; i <= 100001; i++)
//		if(erathos[i] == false)
//			for (int j = i+i; j <= 100001; j+=i)
//				erathos[j] = true;
//}
int erathos[100001] = { 1,1 };
void erathos_chae() {
	for (int i = 2; i <= 100001; i++)
		if(erathos[i] == 0)
			for (int j = i + i; j <= 100001; j += i)
				for(int k=j; k%i==0; k/=i)
					erathos[j]++;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B;
	erathos_chae();
	int result = 0;
	for (int i = A; i <= B; i++) {
		if (erathos[erathos[i]] == 0) {
			result++;
		}
	}
	cout << result;
}