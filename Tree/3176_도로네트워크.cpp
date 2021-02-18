#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, K, a, b, c, start, dest;
vector <vector<int> > roads;

int shortest(int start, int dest){

}
int longest(int start, int dest){

}
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; roads.resize(N+1); for(auto &road : roads) road.resize(N+1);
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        roads[a][b] = c;
        roads[b][a] = c;
    }
    cin >> K;
    for(int i=0; i<K; i++){
        cin >> start >> dest;

        cout << shortest(start, dest)<<' '<<longest(start, dest)<<'\n';
    }
}

int main(){
    input();
}