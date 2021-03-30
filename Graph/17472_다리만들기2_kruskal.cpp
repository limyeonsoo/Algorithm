#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <unordered_set>

using namespace std;
struct Edge{
    int start;
    int dest;
    int weight;
};
struct islandInfo{
    int x;
    int y;
    int idx;
};
int N, M, islandCnt;
vector <vector<int>> bases;
vector <Edge> edges;

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
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(bases[i][j] == 0) continue;
            for(int d=0; d<4; d++) {
                vector <pair<islandInfo, int>> partnerIsland = thereIsAnotherIsland({j,i,bases[i][j]}, d);
                if(partnerIsland.empty()) continue;
                if(partnerIsland[0].second < 2) continue;
                edges.push_back({bases[i][j], partnerIsland[0].first.idx, partnerIsland[0].second});
                edges.push_back({partnerIsland[0].first.idx, bases[i][j], partnerIsland[0].second});
            }
        }
    }
}
bool cmp(const Edge &a, const Edge &b){
    return a.weight < b.weight;
}

vector <int> parents;
int Find(int x){
    if(parents[x] == x) return x;
    return Find(parents[x]);
}
int Union(int x, int y){
    x = Find(x), y=Find(y);
    if(x == y) return 0;
    if(x != y) parents[y] = x;
    return 1;
}

int minimumSpanningTree() {
    parents.resize(islandCnt+1);
    for(int i=1; i<=islandCnt; i++) parents[i] = i;
    int result = 0, cnt = 1; //  edge의 갯수는 vertex - 1;
    sort(edges.begin(), edges.end(), cmp);
    for(auto &edge : edges){
        if(Union(edge.start, edge.dest)){
            result += edge.weight;
            cnt++;
        }
    }
    if(cnt == islandCnt) return result;
    else return -1;
}
int main(){
    input();
    countIsland();
    monoDirectionBridge();

    cout << minimumSpanningTree();
}