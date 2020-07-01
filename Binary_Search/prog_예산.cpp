#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll check(vector<int>& budgets, int mid) {
    ll result = 0;
    for (auto& budget : budgets) result += (budget < mid) ? (ll)budget : (ll)mid;
    return result;
}


ll solution(vector<int> budgets, int M) {
    ll answer = 0;
    for (auto& budget : budgets) answer += budget;
    if (answer <= M) return *max_element(budgets.begin(), budgets.end());
    int start = 1; int end = *max_element(budgets.begin(), budgets.end());
    cout << M;
    while (end - start >= 0) {
        int mid = (start + end) / 2;
        if (check(budgets, mid) <= (ll)M) {
            start = mid + 1;
            answer = mid;
        }
        else {
            end = mid - 1;
        }
    }


    return answer;
}