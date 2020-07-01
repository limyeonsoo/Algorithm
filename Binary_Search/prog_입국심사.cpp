#include <string>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll solution(int n, vector<int> times) {
    ll answer = 0;

    ll start = 1; ll end = (ll)n * (*max_element(times.begin(), times.end()));
    while (end - start >= 0) {
        ll mid = (start + end) / 2;
        ll processed = 0;
        for (int i = 0; i < times.size(); i++) processed += mid / (ll)times[i];
        if (processed >= n) {
            answer = mid;
            end = mid - 1;
        }
        else start = mid + 1;

    }

    return answer;
}