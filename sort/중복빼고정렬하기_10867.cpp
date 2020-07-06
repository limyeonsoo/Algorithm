#pragma warning(disable:4996)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector <int> v;
vector <int>::iterator iter;
int main() {
	scanf("%d", &N); v.resize(N);
	for (int i = 0; i < N; i++) scanf("%d", &v[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (iter = v.begin(); iter != v.end(); iter++) printf("%d ", *iter);
}