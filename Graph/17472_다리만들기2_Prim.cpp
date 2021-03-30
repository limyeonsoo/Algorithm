#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <unordered_set>

using namespace std;
int N, M, islandCnt;
vector <vector<int>> bases;
vector <vector<int>> graphs;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    bases.resize(N); for(auto &base: bases) base.resize(M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> bases[i][j];
        }
    }
}
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct islandInfo{
    int x;
    int y;
    int idx;
};
bool OOR(islandInfo next){
    return !(0<=next.x && next.x<M && 0<=next.y && next.y<N);
}
void countIsland(){
    vector <vector<int>> visit;
    visit.resize(N); for(auto &v: visit) v.resize(M, 0);

    queue <islandInfo> q;
    islandCnt = 0;
    for(int i=0; i<N; i++) {
        for (int j = 0; j < M; j++) {
            if (bases[i][j] >= 1) {
                if (visit[i][j]) continue;
                visit[i][j] = ++islandCnt;
                q.push({j, i, islandCnt});
                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    bases[curr.y][curr.x] = curr.idx;
                    for (int d = 0; d < 4; d++) {
                        islandInfo next = {curr.x + dx[d], curr.y + dy[d], curr.idx};
                        if (OOR(next)) continue;
                        if (visit[next.y][next.x]) continue;
                        if (bases[next.y][next.x] == 0) continue;

                        visit[next.y][next.x] = next.idx;
                        q.push(next);
                    }
                }
            };
        }
    }
}
void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++) {
            cout << bases[i][j]<<' ';
        }cout << '\n';
    }
}

vector <pair<islandInfo,int>> thereIsAnotherIsland(islandInfo curr, int direction){
    vector <pair<islandInfo,int> > result;
    switch(direction){ // 바로 리턴 : 무조건 첫번째 만나는 섬은 정해져있고, 그걸로 판별해야함.
        case 1:
            for(int i=curr.y+1; i<N; i++){
                if(bases[i][curr.x] == curr.idx) return result; // 섬 끝에서 출발해야함. 이거는 안쪽에 있는 요소
                if(bases[i][curr.x] != 0 && bases[i][curr.x] != curr.idx){
                    result.push_back({{curr.x, i, bases[i][curr.x]}, abs(curr.y - i)-1}); // abs 는 -1 해야 거리가 나온다.
                    return result;
                }
            }
            break;
        case 2:
            for(int i=curr.x-1; i>=0; i--){
                if(bases[curr.y][i] == curr.idx) return result; // 섬 끝에서 출발해야함. 이거는 안쪽에 있는 요소
                if(bases[curr.y][i] != 0 && bases[curr.y][i] != curr.idx){
                    result.push_back({{i, curr.y, bases[curr.y][i]}, abs(curr.x - i)-1});
                    return result;
                }
            }
            break;
        case 3:
            for(int i=curr.y-1; i>=0; i--){
                if(bases[i][curr.x] == curr.idx) return result; // 섬 끝에서 출발해야함. 이거는 안쪽에 있는 요소
                if(bases[i][curr.x] != 0 && bases[i][curr.x] != curr.idx){
                    result.push_back({{curr.x, i, bases[i][curr.x]}, abs(curr.y - i)-1});
                    return result;
                }
            }
            break;
        case 0:
            for(int i=curr.x+1; i<M; i++){
                if(bases[curr.y][i] == curr.idx) return result; // 섬 끝에서 출발해야함. 이거는 안쪽에 있는 요소
                if(bases[curr.y][i] != 0 && bases[curr.y][i] != curr.idx){
                    result.push_back({{i, curr.y, bases[curr.y][i]}, abs(curr.x - i)-1});
                    return result;
                }
            }
            break;
    }
    return result;
}

void monoDirectionBridge(){
    graphs.resize(islandCnt+1); for(auto &graph : graphs) graph.resize(islandCnt+1, 2147483647);
    //for(int island=1; island<=islandCnt; island++){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(bases[i][j] == 0) continue;
            for(int d=0; d<4; d++) {
                vector <pair<islandInfo, int>> partnerIsland = thereIsAnotherIsland({j,i,bases[i][j]}, d);
                if(partnerIsland.empty()) continue;
                if(partnerIsland[0].second < 2) continue;
                //cout << j<<','<<i<< " ==> "<<partnerIsland[0].first.x<<','<<partnerIsland[0].first.y<<' '<<partnerIsland[0].first.idx<<' '<<partnerIsland[0].second<<'\n';
                graphs[bases[i][j]][partnerIsland[0].first.idx] = min(graphs[bases[i][j]][partnerIsland[0].first.idx], partnerIsland[0].second);
                graphs[partnerIsland[0].first.idx][bases[i][j]] = min(graphs[partnerIsland[0].first.idx][bases[i][j]], partnerIsland[0].second);

            }
        }
    }
}
struct cmp{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second > b.second;
    }
};
int minimumSpanningTree() {
    for(int i=1; i<=islandCnt; i++){
        int sum = 0;
        for(int j=1; j<=islandCnt; j++){
            if(i==j) continue;
            if(graphs[i][j] == 2147483647) continue;
            sum += graphs[i][j];
        }
        if(sum == 0) return -1;
    }

    bitset <7> visit;
    priority_queue <pair<int,int>, vector <pair<int,int>> , cmp> pq;
    int result = 0, now = 1; visit.set(1);
    while(visit.count() != islandCnt){
        int checkCount = visit.count();
        for(int i=1; i<=islandCnt; i++){
            if(now == i) continue;
            if(graphs[now][i] == 2147483647) continue;
            if(visit.test(i)) continue;
            pq.push({i, graphs[now][i]});
        }
        while(!pq.empty()){
            pair<int,int> next = pq.top(); pq.pop();
            if(visit.test(next.first)) continue;
            visit.set(next.first);
            //cout << next.first <<','<<next.second<<'\n';
            result+=next.second;
            now = next.first;
            break;
        }
        if(visit.count() == checkCount) return -1;
    }
    return result;

}
int main(){
    input();
    countIsland();
    //print();

    monoDirectionBridge();
//    for(int i=1; i<=islandCnt; i++){
//        for(int j=1; j<=islandCnt; j++){
//            cout << graphs[i][j]<<' ';
//        }cout << '\n';
//    }
    cout << minimumSpanningTree();
}