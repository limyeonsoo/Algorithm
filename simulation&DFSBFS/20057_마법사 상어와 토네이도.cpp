//
// Created by 임연수 on 2021/04/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector <vector<int> > bases;
vector <vector<int>> temp;

void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    bases.resize(N, vector<int>(N));
    temp.resize(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> bases[i][j];
        }
    }
}
bool inner(int x, int y){
    return (0<=x && x <N && 0<=y && y<N);
}
void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << bases[i][j]<<' ';
        }cout << '\n';
    }cout << '\n';
}
int sandSpread(int &x, int &y){
    int originSand = bases[y][x-1];
    int outerSand = 0;
    // nextX = x-1, nextY = y;
    // 10%  x-2  y-1/y+1
    // 7%  x-1 y-1/y+1
    // 1% x y-1/y+1
    // 2% x-1  y-2/y+2
    // 5% x-3
    // a  x-2 y
    int ratio10 = (int)(originSand*0.1);
    int ratio7 = (int)(originSand*0.07);
    int ratio5 = (int)(originSand*0.05);
    int ratio2 = (int)(originSand*0.02);
    int ratio1 = (int)(originSand*0.01);
    int ratioA = originSand - (ratio10 + ratio7 + ratio5 + ratio2 + ratio1);

    if(inner(x-2, y-1)) bases[y-1][x-2] += ratio10;
    else outerSand += ratio10;
    originSand -= ratio10;
    if(inner(x-2, y+1)) bases[y+1][x-2] += ratio10;
    else outerSand += ratio10;
    originSand -= ratio10;

    if(inner(x-1, y-1)) bases[y-1][x-1] += ratio7;
    else outerSand += ratio7;
    originSand -= ratio7;
    if(inner(x-1, y+1)) bases[y+1][x-1] += ratio7;
    else outerSand += ratio7;
    originSand -= ratio7;

    if(inner(x-3, y)) bases[y][x-3] += ratio5;
    else outerSand += ratio5;
    originSand -= ratio5;

    if(inner(x-1, y-2)) bases[y-2][x-1] += ratio2;
    else outerSand += ratio2;
    originSand -= ratio2;
    if(inner(x-1, y+2)) bases[y+2][x-1] += ratio2;
    else outerSand += ratio2;
    originSand -= ratio2;

    if(inner(x, y-1)) bases[y-1][x] += ratio1;
    else outerSand += ratio1;
    originSand -= ratio1;
    if(inner(x, y+1)) bases[y+1][x] += ratio1;
    else outerSand += ratio1;
    originSand -= ratio1;

    if(inner(x-2, y)) bases[y][x-2] += originSand;
    else outerSand += originSand;

    return outerSand;

}
void rotate(){
    copy(bases.begin(), bases.end(), temp.begin());
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            bases[i][j] = temp[N-j-1][i];
        }
    }
}

void tonado(){
    int currX = N/2, currY = N/2;
    int answer =0;

      // 1 1 2 2 3 3
    for(int i=1; i<=N-1; i++){
        for(int j=0; j<i; j++){
            answer += sandSpread(currX, currY);
            currX -= 1;
        }
        rotate();
        int temp = currX;
        currX = N-1-currY;
        currY = temp;

        for(int j=0; j<i; j++){
            answer+= sandSpread(currX, currY);
            currX -= 1;
        }
        rotate();
        currX = N-1-currX;
        currY = currY;
    }
    for(int i=0; i<N-1; i++){
        answer += sandSpread(currX, currY);
        currX -= 1;
    }
    cout << answer;
}
int main(){
    input();
    tonado();

}