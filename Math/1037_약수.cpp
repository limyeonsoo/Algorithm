#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
vector <ll> v;
int main() {
    int N; cin >> N; v.resize(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << (v.size() % 2 == 0 ? v[(int)v.size() / 2 - 1] * v[(int)v.size() / 2] : v[(int)v.size()/2] * v[(int)v.size()/2]);
}
