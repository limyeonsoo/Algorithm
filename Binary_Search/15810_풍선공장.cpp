#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
ll N, M, low, high, mid, answer;
std::vector <ll> people;
bool check(ll mid) {
	ll ballon = 0;
	for (ll i = 0; i < people.size(); i++) ballon += (ll)mid/people[i];
	return ballon >= M ? true : false;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N >> M;
	people.resize(N);
	for (ll i = 0; i < N; i++) std::cin >> people[i];
	sort(people.begin(), people.end());
	low = 1; 
	high = people[people.size()-1]*M;
	answer = people[people.size() - 1] * M;
	while (high - low >= 0) {
		mid = (high + low) / 2;
		if (check(mid)) {
			high = mid - 1;
			if(answer>mid) answer = mid;
		}
		else {
			low = mid + 1;
		}
	}
	std::cout << answer;
}
