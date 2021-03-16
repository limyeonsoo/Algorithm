#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map <string,int> network;
vector <int> parents;
vector <int> cnt;
int T, F;

int Find(int x){
    if(parents[x] == x) return x;
    return parents[x] = Find(parents[x]);
}
void Union(int x, int y){
    int X = Find(x), Y = Find(y);
    if(X != Y) {
        cnt[X] = cnt[X]+cnt[Y];
        parents[Y] = X;
    }
}

void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--){
        cin >> F;
        network.clear();
        parents.clear();
        parents.resize(F*2);
        cnt.clear(); cnt.resize(2*F);
        for(int i=0; i<F*2; i++){
            parents[i] = i;
            cnt[i] = 1;
        }
        for(int i=0; i<F; i++){
            string friendA, friendB;
            cin >> friendA >> friendB;
            if(network.find(friendA) == network.end()){
                network.insert({friendA, network.size()});
            }
            if(network.find(friendB) == network.end()) {
                network.insert({friendB, network.size()});
            }
            Union(network[friendA], network[friendB]);
//            for(int i=0; i<2*F; i++){
//                cout << i<<" : "<<parents[i]<<"    "<<cnt[i]<<'\n';
//            }
            cout << cnt[parents[network[friendA]]]<<'\n';

        }

    }
}
int main(){
    input();
}