#include <iostream>
#include <vector>
using namespace std;
int N;
vector <vector<int> > spaces;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
}
void makeSpaces(){
    spaces.resize(N); for(auto &space : spaces) space.resize(N, 1);
}
void print(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << ( spaces[i][j] == 0 ? " " : "*");
        }cout << '\n';
    }
}
void dq(int start, int end, int length){
    for(int i=start+length/3; i<start+2*length/3; i++){
        for(int j=end-length/3-1; j>=end-2*length/3; j--){
            spaces[i][j] = 0;
        }
    }

    if(length == 3) return;


    dq(start, end-2*length/3, length/3);
    dq(start, end-length/3, length/3);
    dq(start, end, length/3);
    dq(start+length/3, end-2*length/3, length/3);

    dq(start+length/3, end, length/3);
    dq(start+2*length/3, end-2*length/3, length/3);
    dq(start+2*length/3, end-length/3, length/3);
    dq(start+2*length/3, end, length/3);

//    if(length==3){
//        for(int i=0; i<3; i++){
//            for(int j=0;j<3; j++){
//                if(i==1 && j==1) continue;
//                spaces[i+start][j+end] = 1;
//            }
//        }
//        return;
//    }
//
//    dq(start, end, length/3);
//    dq(start, end+length/3, length/3);
//    dq(start, end+(2*(length/3)), length/3);
//    dq(start+length/3, end, length/3);
//
//    dq(start+length/3, end+(2*(length/3)), length/3);
//    dq(start+(2*(length/3)), end, length/3);
//    dq(start+(2*(length/3)), end+length/3, length/3);
//    dq(start+(2*(length/3)), end+(2*(length/3)), length/3);


}


int main(){
    input();
    makeSpaces();
    dq(0, N, N);
    print();
}