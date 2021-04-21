#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int T, value;
string query;
int visited;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> query ;
		if (query == "add") {
			cin >> value;
			if ((visited & (1 << value)) != 0) continue;
			visited = visited | (1 << value);
		}
		else if (query== "remove") {
			cin >> value;
			if ((visited & (1 << value)) == 0) continue;
			visited = visited & ~(1 << value);
		}
		else if (query == "check") {
			cin >> value;
			cout << ((visited & (1 << value)) ? "1" : "0") << '\n';
		}
		else if (query == "toggle") {
			cin >> value;
			visited = visited ^ (1 << value);
		}
		else if (query == "all") {
			visited = visited | ((1 << 21) - 1);
		}
		else if (query == "empty") {
			visited = 0;
		}
	}
}