//
// Created by 임연수 on 2021/08/11.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

vector <vector<pair<int,int>>> node;
vector <bool> visit;
int N, Q;       // N: node Q: query
int p, q, r;    // p -> q = r
int k, v;       // over k:weight in v:video

int search(int k, int v){
    int sum = 0;
    visit = vector<bool>(N+1, 0);
    visit[v] = true;
    queue <int> searchQueue;
    searchQueue.push(v);

    while(!searchQueue.empty()) {

        int now = searchQueue.front();
        searchQueue.pop();

        for (int i = 0; i<node[now].size(); i++) {
            // dest ; node[now][i].first
            // weight: node[now][i].second
            if (visit[node[now][i].first]) continue;
            if(node[now][i].second < k) continue;

            searchQueue.push(node[now][i].first);
            //cout << now<<" -> "<<i<<'\n';
            visit[node[now][i].first] = true;
            sum++;
        }
    }
    return sum;
}
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;

    node.resize(N+1);
    visit.resize(N+1);
    for(int i=0; i<N-1; i++){
        cin >> p >> q >> r;

        node[p].push_back({q,r});
        node[q].push_back({p,r});
    }

    for(int i=0; i<Q; i++){
        cin >> k >> v;

        // k를 가진 채. K이상인 것으로만 탐색.
        // v 부터.

        cout << search(k, v) <<'\n';
    }
}



int main(){
    input();

}