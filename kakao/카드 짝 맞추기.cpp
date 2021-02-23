#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
struct Coord{ int x; int y; };
struct Info{
    vector <vector<int> > states;
    int open = 0;
    Coord openCoord;
    Coord coord;
    int click;
};
int answer = 2147483647;
vector <int> nPr;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector <vector<Coord> > groups(7);
set <int> kind;
bool inner(Coord xy){
    return (0<= xy.x && xy.x < 4 && 0<= xy.y && xy.y <4);
}
void setGroup(vector<vector<int>> &boards){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(boards[i][j] == 0) continue;
            kind.insert(boards[i][j]);
            groups[boards[i][j]].push_back({j,i});
        }
    }
    for(auto iter = kind.begin(); iter!= kind.end(); ++iter){
        nPr.push_back(*iter);
    }
}
Coord moveOne(int direction, Coord xy){
    return {xy.x+dx[direction], xy.y+dy[direction]};
}
Coord moveSome(vector<vector<int>> &boards, int direction, Coord XY){
    while(inner(XY)){
        XY = {XY.x+dx[direction], XY.y+dy[direction]};
        if(!inner(XY)) return {XY.x-dx[direction], XY.y-dy[direction]};
        if(boards[XY.y][XY.x] > 0) break;
    }
    return XY;
}
Info initInfo(vector<vector<int>> &board, int x, int y){
    int click = (int)kind.size()*2;
    Coord openCoord = {-1,-1};
    int open = 0;
    return{ board, open, openCoord, {x,y}, click };
}

Info search(Info &nowInfo, Coord nextCoord){
    Info nextInfo = nowInfo;
    nextInfo.coord = nextCoord;
    nextInfo.click += 1;
    if(nowInfo.states[nextCoord.y][nextCoord.x] > 0){ // 뭔가 있다.
        if(nowInfo.open == nowInfo.states[nextInfo.coord.y][nextInfo.coord.x]){
            nextInfo.states[nextInfo.openCoord.y][nextInfo.openCoord.x] =  0;
            nextInfo.states[nextCoord.y][nextCoord.x] = 0;
            nextInfo.openCoord = {-1,-1};
            nextInfo.open = 0;
        }else{
            nextInfo.openCoord = {nextCoord.x, nextCoord.y};
            nextInfo.open = nowInfo.states[nextCoord.y][nextCoord.x];
        }
    }
    return nextInfo;
}

Info bfs(Info &curr, Coord target){
    queue <Info> q;
    q.push(curr);
    while(!q.empty()){
        Info nowInfo = q.front(); q.pop();
        if(nowInfo.coord.x == target.x && nowInfo.coord.y == target.y) return nowInfo;
        for(int d=0; d<4; d++){
            Coord nextSomeCoord = moveSome(nowInfo.states, d, nowInfo.coord);
            if(inner(nextSomeCoord) && (nowInfo.coord.x != nextSomeCoord.x || nowInfo.coord.y != nextSomeCoord.y)){
                q.push(search(nowInfo, nextSomeCoord));
            }
            Coord nextOneCoord = moveOne(d, nowInfo.coord);
            if(inner(nextOneCoord)){
                q.push(search(nowInfo, nextOneCoord));
            }
        }
    }
}
void dfs(int depth, int click, Info currentInfo){
    if(depth == kind.size()){
        if(answer > currentInfo.click){
            cout << currentInfo.coord.x<<','<<currentInfo.coord.y<<" : "<<currentInfo.click <<'\n';
            for(int i=0; i<kind.size(); i++){
                cout << nPr[i]<<' ';
            }cout << '\n';
        }
        answer = min(answer, currentInfo.click);
        return;
    }

    Info left= bfs(currentInfo, groups[nPr[depth]][0]);
    Info right = bfs(currentInfo, groups[nPr[depth]][1]);

    if(left.click < answer){
        Info leftRight = bfs(left, groups[nPr[depth]][1]);

        if(leftRight.click < answer){
            dfs(depth+1, click, leftRight);
        }
    }
    if(right.click < answer){
        Info rightLeft = bfs(right, groups[nPr[depth]][0]);

        if(rightLeft.click <answer){
            dfs(depth+1, click, rightLeft);
        }
    }
}
int solution(vector<vector<int>> board, int r, int c) {
    setGroup(board);
    int cnt = 0;
    nPr = {6, 5, 4, 3, 2, 1};
    do{
        cnt++;
//        Info init = initInfo(board, c, r);
//        if(init.coord.x == groups[nPr[0]][0].x && init.coord.y == groups[nPr[0]][0].y) init.click-=1;
//        dfs(0, 0, init);
        for(int i=0; i<nPr.size(); i++){
            cout <<nPr[i]<<' ';
        }cout << '\n';

    }while(next_permutation(nPr.begin(), nPr.end()));
cout << cnt<<'\n';

    return answer;
}

int main(){
    vector<vector<int>> board = {{1, 6, 2, 5}, {4, 3, 4, 3}, {5, 2, 1, 6}, {0, 0, 0, 0}};
    int r = 3;
    int c = 3;
    cout << solution(board, r, c);
}