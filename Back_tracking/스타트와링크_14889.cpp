#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <vector<int> > v;
int N, result = 987654321;
unsigned int check;


int main() {
	cin >> N; v.resize(N); for (int i = 0; i < N; i++) v[i].resize(N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)	cin >> v[i][j];
	for (int i = (1<< N-1); i < (1 << N); i++) {
		vector<int> start, link;
		for (int j = 0; j < N; j++) {
			if ((i & (1 << j)) != 0) start.push_back(j);
			else link.push_back(j);
		}
		int st = 0, li = 0;
		if (start.size() == N / 2 && link.size() == N / 2) {
			for (int a = 0; a < N / 2; a++) {
				for (int b = a+1; b < N / 2; b++) {
					if (a == b)continue;
					st += v[start[a]][start[b]] + v[start[b]][start[a]];
					li += v[link[a]][link[b]] + v[link[b]][link[a]];
				}
			}
			result = (result > abs(st - li) ? abs(st - li) : result);
		}
	}
	cout << result;
}

//https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14889-%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80-%EB%A7%81%ED%81%AClimy