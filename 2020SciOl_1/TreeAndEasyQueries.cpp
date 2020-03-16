//#pragma warning(disable:4996)
//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//using namespace std;
//int N, Q, k, x, p;
//long long int max_sum;
//vector <vector<pair<int,int>>> weight;
//vector <vector<pair<int, int>>> vertex;
//bool check[150001];
//long long int dfs(int node, long long int sum) {
//
//	if (max_sum < sum) {  //종료조건.
//		max_sum = sum;
//	}
//	for (auto& i: weight[node]) {
//		if (check[i.first]) continue;
//		check[i.first] = true;
//		dfs(i.first, sum + i.second );
//		check[i.first] = false;
//	}
//	return max_sum;
//}
//int main() {
//	scanf("%d %d", &N, &Q);
//	weight.resize(N+1);
//	vertex.resize(N + 1);
//	for (int i = 1; i <= N - 1; i++) {
//		int u, v, w;
//		scanf("%d %d %d", &u, &v, &w);
//		vertex[i].push_back({ u,v });
//		weight[u].push_back({ v,w });
//		weight[v].push_back({ u,w });
//	}
//	for (int i = 0; i < Q; i++) {  //쿼리 .
//		int temp;
//		scanf("%d", &temp);
//		if (temp == 1) {
//			scanf("%d %d", &k, &x);  //k번 간선의 weight을 x로 바꾼다.
//			weight[vertex[k].front().first].front().second = x;
//			weight[vertex[k].front().second].front().second = x;
//		}
//		else {
//			max_sum = 0;
//			scanf("%d", &p);    //p번 정점을 지나는 가장 긴 단순 경로의 길이를 출력.
//			check[p] = true;
//			dfs(p, 0);
//			check[p] = false;
//			printf("%lld\n", max_sum);
//		}
//	}
//}

#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct footprint{
	vector <int> v;
	long long int max_answer;
};

int N, Q, k, x, p;
long long int max_sum;
vector <vector<pair<int, int>>> weight;
vector <vector<pair<int, int>>> vertex;
bool check[150001];
vector <footprint> answer;

long long int dfs(int root, int node, long long int sum) {

	if (max_sum < sum) {  //종료조건.
		answer[root].v.clear();
		for (int i = 0; i <= N + 1; i++) if (check[i] == true) answer[root].v.push_back(i); //root시작 경로 저장.
		max_sum = sum;
	}
	for (auto& i : weight[node]) {
		if (check[i.first]) continue;
		check[i.first] = true;
		dfs(root, i.first, sum + i.second);
		check[i.first] = false;
	}
	return max_sum;
}
int main() {
	scanf("%d %d", &N, &Q);
	weight.resize(N + 1);
	vertex.resize(N + 1);
	answer.resize(N + 1);
	for (int i = 1; i <= N - 1; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		vertex[i].push_back({ u,v });
		weight[u].push_back({ v,w });
		weight[v].push_back({ u,w });
	}
	for (int i = 0; i < Q; i++) {  //쿼리 .
		int temp;
		scanf("%d", &temp);
		if (temp == 1) {
			scanf("%d %d", &k, &x);  //k번 간선의 weight을 x로 바꾼다.
			long long int diff = x - weight[vertex[k].front().first].front().second;
			weight[vertex[k].front().first].front().second = x;
			weight[vertex[k].front().second].front().second = x;
			for (auto p : answer) {
				for (int& node : p.v) {
					if (node == vertex[k].front().first || node == vertex[k].front().second) {
						p.max_answer += x;
						break;
					}
				}
			}
		}
		else {
			max_sum = 0;
			scanf("%d", &p);    //p번 정점을 지나는 가장 긴 단순 경로의 길이를 출력.
			if (answer[p].max_answer > 0) printf("%lld\n", answer[p].max_answer);
			else {
				check[p] = true;
				dfs(p, p, 0);
				check[p] = false;
				printf("%lld\n", max_sum);
			}
		}
	}
}