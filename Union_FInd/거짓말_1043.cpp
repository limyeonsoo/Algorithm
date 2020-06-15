#include <iostream>
#include <vector>
using namespace std;

int N, M, know, party, people;
int parents[51];
vector <int> know_people;
vector <vector<int>> party_people(50);
int Find(int x) {
	if (x == parents[x]) return x;
	return x = Find(parents[x]);
}
void Union(int x, int y) {
	x = Find(x); y = Find(y);
	if (x != y) parents[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> know;
	for (int i = 1; i <= N; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < know; i++) {
		int temp; 
		cin >> temp;
		know_people.push_back(temp);
	}
	for (int i = 0; i < M; i++) {
		int temp, prev;
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			cin >> people;
			if (j == 0) prev = people;
			else Union(prev, people);
			party_people[i].push_back(people);
		}
	}
	for (auto& list : party_people) { //파티 하나 당
		bool solve = false;
		for (auto& person : list) {
			if (solve) break;
			for (auto& uf : know_people) {
				if (Find(person) == Find(uf)) {
					solve = true;
					break;
				}
			}
		}
		if (solve) M--;
	}
	cout << M;
}