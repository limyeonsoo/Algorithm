#include <iostream>
#include <math.h>
#include <vector>

#define ll long long
using namespace std;
bool chae[2000001] = { true, true };
vector <ll> v;
ll T, A, B;
void eratho() {
	for (int i = 2; i <= 2000000; i++)
		if (chae[i] == false)
			for (int j = i + i; j <= 2000000; j += i)
				chae[j] = true;
}

bool prime(ll value) {
	for (ll i = 0; (i < v.size()) && (v[i] * v[i] <= value); i++) {
		if (value % v[i] == 0) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	eratho();
	for (ll i = 2; i <= 2000000; i++) if (!chae[i]) v.push_back(i);

	while (T--) {
		cin >> A >> B;
		if ((A + B) <= 3) {
			cout << "NO" << '\n';
			continue;
		}
		if ((A + B) % 2 == 0) cout << "YES" << '\n'; //°ñµå¹ÙÈå
		else cout << (prime((ll)A + (ll)B - (ll)2) ? "NO" : "YES") << '\n';
	}
}