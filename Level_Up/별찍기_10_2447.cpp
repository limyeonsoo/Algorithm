/*
	1 => 1
	2 => 3
	3 => 9
	4 => 27
	5 => 81
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
//char result[2188][2188];  //3^7;
//char base[730][730];
int N, start_n;
int bs_size_x, bs_size_y;
int rs_size_x, rs_size_y;
vector <vector<char> > bs;
vector <vector<char>> result;
bool skip;


int main() {
	scanf("%d", &N);
	result.resize(N);
	bs.resize(N);
	for (int i = 0; i < N; i++) result[i].resize(N);
	for (int i = 0; i < N; i++) bs[i].resize(N);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) continue;
			bs[i][j] = '*';
		}
	}
	bs_size_x = 3; bs_size_y = 3;

	start_n = (int)(log(N) / log(3));
	for (int i = 1; i <= start_n; i++) {                  //단계를 정한다. 
		bs.resize(pow(3, i-1));
		for (int k = 0; k < bs.size(); k++) {
			bs[k].resize(pow(3,i-1));
		}
		fill(i, 1);
		start_x = 0; start_y = 0;
	}
	//for (int i = 0; i < pow(3, N); i++) {
	//	for (int j = 0; j < pow(3, N); j++) {
	//		printf("%c", result[i][j]);
	//	}printf("\n");
	//}
}