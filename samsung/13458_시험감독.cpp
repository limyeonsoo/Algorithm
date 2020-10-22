#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
int N, B, C;
vector <int> areas;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N; areas.resize(N);
	for (int i = 0; i < N; i++) 
		cin >> areas[i];
	cin >> B >> C;
}

ll distribution() {
	ll answer = areas.size();
	for (int i = 0; i < areas.size(); i++) {
		areas[i] = areas[i] - B;
		if (areas[i] < 0) continue;
		answer += (ll)ceil((double)areas[i] / C);
	}
	return answer;
}

int main() {
	input();
	cout << distribution();
}