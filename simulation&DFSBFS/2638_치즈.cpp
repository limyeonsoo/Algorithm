#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Coord{
    int x;
    int y;
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M, allCheese;
vector <vector<int> > bases;
vector <vector<int> > visit;
vector <Coord> cheeses;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    bases.resize(N); for(auto &base: bases) base.resize(M);
    visit.resize(N); for(auto &v : visit) v.resize(M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> bases[i][j];
            if(bases[i][j] == 1){
                allCheese+=1;
                cheeses.push_back({j,i});
            }
        }
    }
}
bool openSurround(Coord point){
    int cnt=0;
    for(int d=0; d<4; d++){
        Coord next = {point.x+dx[d], point.y+dy[d]};
        if(bases[next.y][next.x] == 0) cnt++;
        if(cnt>=2) return true;
    }
    return false;
}
void search(){
    int time = 0;
    while(allCheese){
        time++;
        vector <Coord> melting;
        for(auto iter=cheeses.begin(); iter!=cheeses.end(); ) {
            if (!openSurround(*iter)) {
                ++iter;
                continue;
            }
            melting.push_back(*iter);
            allCheese--;
            cheeses.erase(iter);
        }

        for(auto &melt : melting) bases[melt.y][melt.x] = 0;
    }
    cout << time;
}

int main(){
    input();
    //basePrint();
    search();

}