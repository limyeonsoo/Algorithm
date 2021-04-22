#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
struct minsik{
    int x;
    int y;
    int depth;
    bitset <6> key;
};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, dotCount;
vector <vector<char>> miro;
vector <vector<vector<bool>>> visit;
queue <minsik> q;

void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    miro.resize(N, vector<char>(M));
    visit.resize(N); for(auto &v : visit) v.resize(M);
    for(auto &v : visit){
        for(auto &a : v){
            a.resize(bitset<6>().size());
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> miro[i][j];
            if(miro[i][j]-'0' == 0) {
                visit[i][j][0] = true;
                q.push({j, i, 0, 0});
            }
            if(miro[i][j] == '.') dotCount++;
        }
    }
}
bool OOR(minsik next){
    return !(0<= next.x && next.x < M && 0<=next.y && next.y < N);
}
int upperCheck(minsik next){
    if(0 <= miro[next.y][next.x]-'A' && miro[next.y][next.x]-'A' <= 6) return miro[next.y][next.x]-'A';
    return -1;
}
int lowerCheck(minsik next){
    if(0 <= miro[next.y][next.x]-'a' && miro[next.y][next.x]-'a' <= 6) return miro[next.y][next.x]-'a';
    return -1;
}

int search(){
    while(!q.empty()){
        minsik curr = q.front(); q.pop();
        //cout << curr.x<<','<<curr.y<<' '<<curr.depth<<'\n';
        if(miro[curr.y][curr.x] == '1'){
            return curr.depth;
        }

        for(int d=0; d<4; d++){
            // 재방문 해야하는건 확실한데,, 줄여야 할 것 같은데...
            minsik next = {curr.x+dx[d], curr.y+dy[d], curr.depth+1, curr.key};
            if(OOR(next)) continue;
            if(miro[next.y][next.x] == '#') continue;
            if(visit[next.y][next.x][next.key.to_ulong()]) {
               // cout << "=================cut=============\n";
                continue;
            }

            // 대문자 체크
            int upperRes = upperCheck(next);
            if(upperRes != -1){
                if(next.key.test(upperRes)) {
                    visit[next.y][next.x][next.key.to_ulong()] = true;
                    q.push(next);
                }
                continue;
            }

            // 소문자 체크
            int lowerRes = lowerCheck(next);
            if(lowerRes != -1){
                next.key.set(lowerRes);
                visit[next.y][next.x][next.key.to_ulong()] = true;
                q.push(next);
                continue;
            }

            visit[next.y][next.x][next.key.to_ulong()] = true;
            q.push(next);
        }
    }
    return -1;
}
int main(){
    input();
    cout << search();
}