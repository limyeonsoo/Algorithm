#include <iostream>
#include <vector>

using namespace std;
int N, oneAnswer, zeroAnswer;
vector <vector<int>> papers;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    papers.resize(N); for(auto &paper : papers) paper.resize(N);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin >> papers[i][j];
}
bool OOR(int x, int y){
    return !(0<=x && x<N && 0<=y && y<N);
}

void dfs(int length, int x, int y){
    if(OOR(x,y)) return;
    int sum = 0;
    if(length == 2){
        for(int i=x; i<x+length; i++) for(int j=y; j<y+length; j++) sum += papers[i][j];
        if(sum == length*length) oneAnswer += 1;
        else if(sum == 0) zeroAnswer += 1;
        else{
            oneAnswer += sum;
            zeroAnswer += (4-sum);
        }
        return;
    }


    for(int i=x; i<x+length; i++) for(int j=y; j<y+length; j++) sum += papers[i][j];
    if(sum == length*length) oneAnswer += 1;
    else if(sum == 0) zeroAnswer += 1;
    else{
        dfs(length/2, x, y);
        dfs(length/2, x+length/2, y);
        dfs(length/2, x, y+length/2);
        dfs(length/2, x+length/2, y+length/2);
    };
}

void divide(){
    int length = N; //only 2^k;
    int x = 0, y = 0;

    dfs(length, x, y);
    dfs(length, x+length, y);
    dfs(length, x, y+length);
    dfs(length, x+length, y+length);
}

int main(){
    input();
    divide();
    cout << zeroAnswer <<'\n'<<oneAnswer;
}