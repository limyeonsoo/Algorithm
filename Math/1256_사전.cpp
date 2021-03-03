#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define LIMIT 1000000001

using namespace std;
int N, M, K;
vector <vector<int> > nCr;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
}
void init_nCr(){
    nCr.resize(201); for(auto &a : nCr) a.resize(201);
    nCr[0][0] = nCr[1][0] = nCr[1][1] = 1;
    for(int i=1; i<=N+M; i++){
        nCr[i][0] = 1;
        for(int j=1; j<=i; j++){
            nCr[i][j] = min(LIMIT, nCr[i-1][j] + nCr[i-1][j-1]);
        }
    }
}

void check(){
    K--;
    for(int i= N+M-1; i>=0; i--){
        if(i >= M && nCr[i][M] > K){
            cout << "a";
        }else{   // z가 앞에 나올때마다 숫자는 커진다.
            K -= nCr[i][M]; // z가 나왔으면 그에 해당하는 큰 수만큼은 다 빠진다.
            M--;
            cout << "z";
        }
    }
}
int main(){
    input();
    init_nCr();
    if(nCr[N+M][M] <= K) cout << "-1";
    else check();
}

// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaazazzzzzzzzzzzzzzzzzzazzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzazzzzzzzaazzzzzzzzzzzzzzazzzzzzzzzzzzzzz
// aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaazazzzzzzzzzzzzzzzzzzazzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzazzzzzzzaazzzzzzzzzzzzzzazzzzzzzzzzzzzzz