//
// Created by 임연수 on 2021/04/21.
//

#include<iostream>
#include <bitset>
#include <vector>

using namespace std;
int N, M;
vector <bitset<51>> subject;
vector <bitset<51>> student;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; subject.resize(N);
    int cnt, time;
    for(int i=0; i<N; i++){
        cin >> cnt;
        for(int j=0; j<cnt; j++){
            cin >> time;
            subject[i].set(time);
        }
    }
    cin >> M; student.resize(M);
    for(int i=0; i<M; i++){
        cin >> cnt;
        for(int j=0; j<cnt; j++){
            cin >> time;
            student[i].set(time);
        }
    }
}

void search(){

    for(auto & std : student){
        int success=0; int cnt = std.count();
        for(auto & sub : subject){
            bitset <51> orResult = std | sub;
            if(orResult.count() == cnt) success++;
        }
        cout << success<<'\n';
    }

}

int main(){
    input();
    search();
}