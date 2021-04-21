//
// Created by 임연수 on 2021/04/21.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;
int N, M;
vector <vector<int> > marbleHeavy;
vector <vector<int> > marbleLight;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M; marbleHeavy.resize(N+1); marbleLight.resize(N+1);
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        marbleHeavy[b].push_back(a);
        marbleLight[a].push_back(b);
    }
}
void dfsHeavy(int curr, vector <bool> &visitHeavy){
    for(auto &next : marbleHeavy[curr]){
        if(visitHeavy[next]) continue;
        visitHeavy[next] = true;
        dfsHeavy(next, visitHeavy);
    }

}
void dfsLight(int curr, vector <bool> &visitLight){
    for(auto &next : marbleLight[curr]){
        if(visitLight[next]) continue;
        visitLight[next] = true;
        dfsLight(next, visitLight);
    }
}
int search(){
    set <int> candidate;
    for(int i=1; i<=N; i++){
        vector <bool> visitLight; visitLight.resize(N+1, false);
        vector <bool> visitHeavy; visitHeavy.resize(N+1, false);
        dfsHeavy(i, visitHeavy);
        dfsLight(i, visitLight);
        int totalLight = 0, totalHeavy = 0;
        //cout << "I : "<<i<<'\n';
        for(int k=1; k<=N; k++){
           // cout << "In "<<k<<" = > "<< "H : "<<visitHeavy[k]<<' '<<"L : "<<visitLight[k]<<'\n';
            if(visitLight[k]) totalLight++;
            if(visitHeavy[k]) totalHeavy++;
        }
        if(totalLight > N/2 || totalHeavy > N/2) candidate.insert(i);
    }
//    for(auto &cand : candidate){
//        cout << cand<<'\t';
//    }cout << '\n';
    return (int)candidate.size();
}

int main(){
    input();
    cout << search();
}