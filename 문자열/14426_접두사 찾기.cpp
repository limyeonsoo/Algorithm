#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int N, M, answer;
vector <string> bases;
vector <string> queries;
vector <string>::iterator base;
vector <string>::iterator query;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	bases.resize(N);
	queries.resize(M);
	for (int i = 0; i < N; i++) {
		cin >> bases[i];
	}
	sort(bases.begin(), bases.end());
	for (int i = 0; i < M; i++) {
		cin >> queries[i];
	}
}
void queryMatching() {
	for (query = queries.begin(); query != queries.end(); ++query) {
		for (base = lower_bound(bases.begin(), bases.end(), *query); base != upper_bound(bases.begin(), bases.end(), *query)+1; ++base) {
			if (base->length() < query->length()) continue;
			if (*query == base->substr(0, query->length())) {
				answer++;
				break;
			}
		}
	}
	cout << answer;
}
int main() {
	input();
	queryMatching();
}