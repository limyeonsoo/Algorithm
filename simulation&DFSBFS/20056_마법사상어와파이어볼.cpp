//
// Created by 임연수 on 2021/04/20.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Fire{
    int m;
    int s;
    int d;
};
struct Coord{
    int x;
    int y;
};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int N, M, K;
vector <vector<vector<Fire>>> base;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    base.resize(N+1); for(auto &b : base) b.resize(N+1);
    int r, c, m, s, d;
    for(int i=0; i<M; i++){
        cin >> r >> c >> m >> s >> d;
        Fire fire = {m, s, d};
        base[r][c].push_back(fire);
    }
}

Coord getNextCoord(int x, int y, int direction, int speed){
    Coord next;

    int move = speed % N;

    next.x = x + (dx[direction]*move);
    next.y = y + (dy[direction]*move);

    if(next.x < 1) next.x+=N;
    if(next.y < 1) next.y+=N;
    if(next.x > N) next.x-=N;
    if(next.y > N) next.y-=N;

    return next;

}
void print(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << base[i][j].size()<<' ';
        }cout << '\n';
    }cout << '\n';
}
void command(){
    while(K--){
        vector <vector<vector<Fire>>> temp;
        temp.resize(N+1); for(auto &t : temp) t.resize(N+1);
        //print();
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){

                for(auto &fire : base[i][j]){
                    Coord xy = getNextCoord(j, i, fire.d, fire.s);
                    temp[xy.y][xy.x].push_back(fire);
                }
            }
        }
        //print();
        base.clear();
        base.resize(N+1); for(auto &b : base) b.resize(N+1);

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(temp[i][j].size() == 1) {
                    base[i][j].push_back(temp[i][j][0]);
                    continue;
                }else if(temp[i][j].size() >= 2){
                    int fireTotal = 0, mTotal = 0, sTotal = 0;
                    bool odd = false, even = false;

                    for(auto &fire : temp[i][j]){
                        fireTotal++;
                        mTotal += fire.m;
                        sTotal += fire.s;
                        if(fire.d%2 == 0) even = true;
                        else odd = true;
                    }

                    if(even == odd){
                        // 1 3 5 7
                        for(int f=1; f<=7; f+=2){
                            Fire fire = {mTotal/5, sTotal/fireTotal, f};
                            if(fire.m == 0) continue;
                            base[i][j].push_back(fire);
                        }
                    }else {
                        // 0 2 4 6
                        for (int f = 0; f <= 6; f += 2) {
                            Fire fire = {mTotal / 5, sTotal / fireTotal, f};
                            if (fire.m == 0) continue;
                            base[i][j].push_back(fire);
                        }
                    }
                }
            }
        }
        //print();
    }
    //print();
}
int getSum(){
    int sum = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(auto &fire : base[i][j]){
                sum += fire.m;
            }
        }
    }
    return sum;
}
int main(){
    input();
    command();
    cout << getSum();

}