//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int N, temp;
//vector <int> v;
//vector <int>::iterator iter;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N; v.push_back(-1000000001);
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		if (temp > v.back()) v.push_back(temp);
//		else {
//			iter = lower_bound(v.begin(), v.end(), temp);
//			v[iter - v.begin()] = temp;
//		}
//	}
//	cout << v.size() - 1;
//}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, temp;
vector <int> v;
vector <int>::iterator iter;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N; v.push_back(-1000000001);
	for (int i = 0; i < N; i++) {
		cin >> temp;
		if (temp > v.back()) v.push_back(temp);
		else {
			iter = lower_bound(v.begin(), v.end(), temp);
			v[iter - v.begin()] = temp;
		}
	}
	cout << v.size() - 1 << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
}