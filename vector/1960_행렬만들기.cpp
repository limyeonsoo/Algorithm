#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector <int> oneCol;
vector <int> oneRow;

void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; oneCol.resize(N+1); oneRow.resize(N+1);
    for(int i=1; i<=N; i++) cin >> oneRow[i];
    for(int i=1; i<=N; i++) cin >> oneCol[i];
}

void dfsCol(int k, int depth, vector <int> &currCol, vector <int> &currRow, vector <vector<int> > &arrays){
    if(depth == N){

    }
}

void dfsRow(int k, int depth, vector <int> &currCol, vector <int> &currRow, vector <vector<int> > &arrays){
    if(depth == N){

        if(currCol[k] < oneCol[k]){
            for(int i=k; i<=N; i++){
                dfsCol(k, i, currCol, currRow, arrays);
            }
        }
    }
}

void search(){
    vector <vector<int> > arrays; arrays.resize(N+1); for(auto &array : arrays) array.resize(N+1);
    fill(arrays.begin(), arrays.end(), vector<int>(arrays.size(), -1));
    vector <int> currCol(N+1, 0);
    vector <int> currRow(N+1, 0);

    for(int k=1; k<=N; k++){

        if(currRow[k] < oneRow[k]){
            for(int i=k; i<=N; i++){
                dfsRow(k, i, currCol, currRow, arrays);
            };

        }
    }

}
int main(){
    input();
    search();
}