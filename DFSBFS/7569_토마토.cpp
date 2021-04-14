//
// Created by 임연수 on 2021/04/14.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[6] = {1, 0, -1, 0, 0, 0 };
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
struct Coord{
    int x;
    int y;
    int z;
};
queue <Coord> q;
int N, M, H;
int STomato;
int FTomato;
vector <vector<vector<int>>> tomatos;
vector <vector<vector<int>>> visit;
void countNqueuePush(int j, int i, int k){
    if(tomatos[k][i][j] == 1){
        STomato+=1;
        q.push({j,i,k});
        visit[k][i][j] = 1;
    }
    else if(tomatos[k][i][j] == 0) FTomato+=1;
}
void init(){
    tomatos.resize(H);
    for(auto &tomato : tomatos) tomato.resize(N);
    for(auto &tomato : tomatos) for(auto &tmt : tomato) tmt.resize(M);

    visit.resize(H);
    for(auto &vis : visit) vis.resize(N);
    for(auto &vis : visit) for(auto &v : vis) v.resize(M);
}
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> M >> N >> H;
    init();
    for(int k=0; k<H; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> tomatos[k][i][j];
                countNqueuePush(j, i, k);
            }
        }
    }
}
bool OOR(Coord next){
    return !(0<= next.x && next.x < M && 0 <= next.y && next.y < N && 0 <= next.z && next.z < H);
}
int bfs(){
    int maxDay = 0;
    if(FTomato == 0) return maxDay;

    while(!q.empty()){
        Coord now = q.front(); q.pop();
        for(int d=0; d<6; d++){
            Coord next = {now.x+dx[d], now.y+dy[d], now.z+dz[d]};
            if(OOR(next)) continue;
            if(visit[next.z][next.y][next.x]) continue;
            if(tomatos[next.z][next.y][next.x] == 1) continue;
            if(tomatos[next.z][next.y][next.x] == -1) continue;

            visit[next.z][next.y][next.x] = visit[now.z][now.y][now.x] + 1;
            FTomato -= 1;
            maxDay = max(maxDay, visit[now.z][now.y][now.x] + 1);
            q.push(next);
        }
    }

    if(FTomato == 0) return maxDay-1;
    else return -1;
}
int main(){
    input();
    cout << bfs();
}