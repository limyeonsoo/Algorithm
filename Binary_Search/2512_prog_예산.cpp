//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#define ll long long
//
//using namespace std;
//
//ll check(vector<int>& budgets, int mid) {
//    ll result = 0;
//    for (auto& budget : budgets) result += (budget < mid) ? (ll)budget : (ll)mid;
//    return result;
//}
//
//
//ll solution(vector<int> budgets, int M) {
//    ll answer = 0;
//    for (auto& budget : budgets) answer += budget;
//    if (answer <= M) return *max_element(budgets.begin(), budgets.end());
//    int start = 1; int end = *max_element(budgets.begin(), budgets.end());
//    cout << M;
//    while (end - start >= 0) {
//        int mid = (start + end) / 2;
//        if (check(budgets, mid) <= (ll)M) {
//            start = mid + 1;
//            answer = mid;
//        }
//        else {
//            end = mid - 1;
//        }
//    }
//
//
//    return answer;
//}

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
int N, M, temp;
vector <int> v;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp; v.push_back(temp);
	}
	cin >> M;
}

bool check(int mid) {
	ll sum = 0;
	for (auto& each : v) {
		sum += (mid >= each ? each : mid);
	}
	return sum <= M;
}

int search() {
	int H = 0;
	int left = 1;
	//int right = M;
	int right = *max_element(v.begin(), v.end());
	while (left <= right) {
		int mid = (right - left) / 2 + left;
		int res = check(mid);
		if (res) {
			H = (H < mid ? mid : H);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return H;
}
int main() {
	input();
	cout << search();
}