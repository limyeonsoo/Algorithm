//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int N, M, mini = 2147483647;
//vector <vector<int >> v;
//vector <vector<bool >> check;
//vector <pair<int, int> > selected;
//vector <pair<int, int> > home;
//
//void dfs(int x, int y, int depth) {
//	if (depth == M) {
//		int sum = 0;
//		for (int i = 0; i < home.size(); i++) {
//			int home_mini = 2147483647;
//			for (int j = 0; j < selected.size(); j++) {
//				int dist = abs(home[i].first - selected[j].first) + abs(home[i].second - selected[j].second);
//				if (home_mini > dist) {
//					home_mini = dist;
//					/*cout << "home : " << home[i].first << ' ' << home[i].second << '\n';
//					cout << "chic : " << selected[j].first << ' ' << selected[j].second << '\n';
//					cout << dist << "\n\n";*/
//				}
//			}
//			sum += home_mini;
//		}
//		if (sum < mini) mini = sum;
//		return;
//	}
//	for (int i = x; i <= N; i++) {
//		for (int j = 0; j <= N; j++) {
//			if (v[i][j] != 2)continue;
//			if (check[i][j])continue;
//			check[i][j] = true;
//			selected.push_back({ i,j });
//			dfs(i, j, depth + 1);
//			selected.pop_back();
//			check[i][j] = false;
//		}
//	}
//	return;
//}
//
//int main() {
//	cin >> N >> M; 
//	v.resize(N+1); for (auto& n : v)n.resize(N+1);
//	check.resize(N + 1); for (auto& i : check) i.resize(N + 1);
//	for (int i = 1; i <= N; i++) {
//		for (int j = 1; j <= N; j++) {
//			cin >> v[i][j];
//			if (v[i][j] == 1) home.push_back({ i,j });
//		}
//	}
//	dfs(0, 0, 0);
//	cout << mini;
//}


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, mini = 2147483647;
vector <vector<int >> v;
vector <bool> check;
vector <pair<int, int> > home;
vector <pair<int, int> > chicken;

void dfs(int idx, int depth) {
	if (depth == M) {
		int sum = 0;
		for (int i = 0; i < home.size(); i++) {
			int home_mini = 2147483647;
			for (int j = 0; j < check.size(); j++) {
				if (!check[j]) continue;
				int dist = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
				if (home_mini > dist) home_mini = dist;
			}
			sum += home_mini;
		}
		if (mini > sum) mini = sum;
		return;
	}
	for (int i = idx; i < chicken.size(); i++) {
		if (check[i])continue;
		check[i] = true;
		dfs(i, depth + 1);
		check[i] = false;
	}
	return;
}

int main() {
	cin >> N >> M;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	v.resize(N + 1); for (auto& n : v)n.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) home.push_back({ i,j });
			if (v[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	check.resize(chicken.size());
	dfs(0, 0);
	cout << mini;
}