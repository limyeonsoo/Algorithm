#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;

struct Person {
	int num;
	string name;
};

bool cmp(const Person& u, const Person& v) {
	return u.num < v.num;
}
int main() {
	int N;
	cin >> N;
	vector <Person> v(N);
	for (int i = 0; i < N; i++) {
		//scanf("%d %s", &v[i].num, v[i].name);
		cin >> v[i].num >> v[i].name;
	}

	stable_sort(v.begin(), v.end(), cmp);
	
	for (int i = 0; i < N; i++) {
		//printf("%d %s\n", v[i].num, v[i].name);
		cout << v[i].num << ' ' << v[i].name;
	}
}