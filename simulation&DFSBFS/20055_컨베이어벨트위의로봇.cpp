//
// Created by 임연수 on 2021/04/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct Belt{
    int power;
    int hasRobot;
    int originIdx;
};
vector <Belt> belts;
int N, K;
unordered_set <int> powerZero;

void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K; belts.resize(2*N);
    for(int i=0; i<2*N; i++) {
        cin >> belts[i].power; belts[i].hasRobot = false; belts[i].originIdx = i;
        if(belts[i].power <= 0) powerZero.insert(belts[i].originIdx);
    }
    // 0~N-1 까지 상단.
    // 2*N-1 ~ N 까지 하단.
}

void check1(){
    vector <Belt> forCopy(2*N);
    copy(belts.begin(), belts.end(), forCopy.begin());

    belts[0] = forCopy[2*N-1]; // 상
    for(int i=1; i<N; i++){
        belts[i] = forCopy[i-1];
    }
    if(belts[N-1].hasRobot) belts[N-1].hasRobot = false;

    for(int i=N; i<2*N; i++){
        belts[i] = forCopy[i-1];
        belts[i].hasRobot = false;
    }
}
void check2(){
    for(int i=N-1; i>=1; i--){
        if(belts[i].hasRobot) continue;
        if(belts[i].power <= 0){
            powerZero.insert(belts[i].originIdx);
            continue;
        }

        if(belts[i-1].hasRobot){
            belts[i-1].hasRobot = false;
            belts[i].hasRobot = true;
            belts[i].power -= 1;
            if(belts[i].power <= 0){
                powerZero.insert(belts[i].originIdx);
                continue;
            }
        }
    }
    if(belts[N-1].hasRobot){
        belts[N-1].hasRobot = false;
        if(belts[N-1].power <= 0){
            powerZero.insert(belts[N-1].originIdx);
        }
    }
}
void check3(){
    if(!belts[0].hasRobot && belts[0].power > 0){
        belts[0].hasRobot = true;
        belts[0].power -= 1;
        if(belts[0].power <= 0){
            powerZero.insert(belts[0].originIdx);
        }
    }
}
bool check4(){ return powerZero.size() < K; }
void print(int level){
    cout << "Level : "<<level<<'\n';
    for(int i=0; i<2*N; i++){
        cout << belts[i].power<<' '<<belts[i].hasRobot<<' '<<belts[i].originIdx<<'\n';
    }
    cout << "PowerZero : "<<powerZero.size()<<'\n';
}
int solve(){
    bool continueFlag = true;
    int level = 0;
    while(continueFlag){
        level++;
        check1();
        //print(level);

        check2();
        //print(level);

        check3();
        //print(level);

        continueFlag = check4();
        //print(level);
    }
    return level;
}
int main(){
    input();
    cout << solve();
}