#include <iostream>
#include <stack>
#include <string>
using namespace std;

int N, q;
string query;
stack <int> st;

int main() {
	cin >> N;
	while (N--) {
		cin >> query;
		if (query == "push") {
			cin >> q;
			st.push(q);
		}
		else if (query == "top") {
			if (st.empty()) cout << -1 << '\n';
			else cout << st.top() << '\n';
		}
		else if (query == "size") {
			cout << st.size() << '\n';
		}
		else if (query == "pop") {
			if (st.empty()) cout << -1 << '\n';
			else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (query == "empty") {
			/*cout << st.empty() ? 1 : 0;
			cout << '\n';*/
			cout << (st.empty() ? 1 : 0) << '\n';
		}
	}
}