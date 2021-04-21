#include <iostream>
#include <cstdio>
using namespace std;
int N;
int IP[1001], subnetmask;

void print(int mask) {
	int shift = 24;
	for (int i = 0; i < 4; i++, shift -= 8) {
		cout << ((mask >> shift) & ((1 << 8) - 1));
		if (i != 3) cout << '.';
	}
	cout << '\n';
}

int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			int temp;
			cin >> temp;
			IP[i] <<= 8;
			IP[i] |= temp;
			getchar();  // ','
		}
	}
	for (int i = 31; i >= 0; i--) {
		int bit = 1 << i;
		bool same = 0;
		for (int j = 1; j < N; j++) {
			if ((IP[0] & bit) != (IP[j] & bit)) {
				same = 1;
				break;
			}
		}
		//same == 0 ? subnetmask |= bit : i=-1;
		if (same) break;
		else subnetmask |= bit;
	}
	print(IP[0] & subnetmask);
	print(subnetmask);
	
}