#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
int N, Q;
int length;
vector <vector<int>> ices;
vector <int> query;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOR(pair<int,int> coord){
    return!(0<=coord.first && coord.first<length && 0<=coord.second && coord.second < length);
}
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> Q;
    length = pow(2, N);
    ices.resize(length, vector<int>(length));
    query.resize(Q);
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            cin >> ices[i][j];
        }
    }
    for(int i=0; i<Q; i++) cin >> query[i];
}
int lastSum(){
    int sum =0;
    for(int i=0; i<length; i++) for(int j=0; j<length; j++) sum+=ices[i][j];
    return sum;
}
int lastBiggestIce(){
    int answer = 0;
    vector <vector<bool>> visit;
    visit.resize(length, vector<bool>(length));
    queue <pair<int,int>> q;
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            if(visit[i][j]) continue;
            if(ices[i][j] == 0) continue;
            visit[i][j] = true;
            q.push({j,i});
            int blockSum = 0;
            while(!q.empty()){
                pair<int,int> curr = q.front(); q.pop();
                blockSum+=1;

                for(int d=0; d<4; d++){
                    pair<int,int> next = {curr.first+dx[d], curr.second+dy[d]};
                    if(OOR(next)) continue;
                    if(ices[next.second][next.first] == 0) continue;
                    if(visit[next.second][next.first]) continue;
                    visit[next.second][next.first] = true;
                    q.push(next);
                }
            }
            answer = max(answer, blockSum);
        }
    }
    return answer;
}

void rotate(int x, int y, int unit){
    vector <vector<int> > temp;
    temp.resize(unit, vector<int>(unit));

    for(int i=y; i<y+unit; i++){
        for(int j=x; j<x+unit; j++){
            temp[i-y][j-x] = ices[i][j];
        }
    }

    for(int i=0; i<unit; i++){
        for(int j=0; j<unit; j++){
            ices[y+i][x+j] = temp[unit-1-j][i];
        }
    }
}
void print(){
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            cout << ices[i][j]<<' ';
        }cout << '\n';
    }cout <<'\n';
}
void rotation(int q){
    int unit = pow(2,q);

    for(int i=0; i<length; i+=unit){
        for(int j=0; j<length; j+=unit){
            rotate(j, i, unit);
        }
    }
}
void melting(){
    queue <pair<int,int> > q;
    for(int i=0; i<length; i++){
        for(int j=0; j<length; j++){
            int neighborCnt = 0;

            for(int d=0; d<4; d++){
                pair<int,int> next = {j+dx[d], i+dy[d]};
                if(OOR(next)) continue;
                if(ices[next.second][next.first] == 0) continue;
                neighborCnt++;
            }
            if(neighborCnt < 3) q.push({j,i});
        }
    }
    while(!q.empty()){
        pair<int,int> curr = q.front(); q.pop();
        if(ices[curr.second][curr.first] > 0)
             ices[curr.second][curr.first] -= 1;
    }
}
void solve(){
//     print();
    for(auto &q : query){
        rotation(q);
//        cout << "rotate=====\n";
//        print();
        melting();
//        cout << "melting=====\n";
//        print();
    }
    cout << lastSum() << '\n';
    cout << lastBiggestIce();
}

int main(){
    input();
    solve();
}