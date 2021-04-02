#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct Coord{
    int x;
    int y;
};
bool cmp(const Coord &a, const Coord &b){
    return a.x <b.x;
}
bool yCmp(const Coord &a, const Coord &b){
    return a.y < b.y;
}
int N;
vector <Coord> point;
void input(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; point.resize(N);
    for(int i=0; i<N; i++){
        cin >> point[i].x >> point[i].y;
    }
}
int calc(Coord a, Coord b){
    int xDistance = abs(a.x - b.x);
    int yDistance = abs(a.y - b.y);
    return ((xDistance * xDistance) + (yDistance * yDistance));
}

int tripleCalc(Coord a, Coord b, Coord c){
    return min(calc(c, a), min(calc(a, b), calc(b, c)));
}

int conquer(int left, int right){
    if(right - left == 1) return calc(point[left], point[right]);
    if(right - left == 2) return tripleCalc(point[left], point[left+1], point[right]);
    if(right - left < 1) return 2147483647;
    int mid = (right-left)/2 + left;
    //
    int resL = conquer(left, mid-1);
    int resR = conquer(mid+1, right);

    int minimum = min(resL, resR);

    vector <Coord> midCandidate;
    for(int i=left; i<right; i++){
        if(minimum > (point[mid].x - point[i].x) * (point[mid].x - point[i].x)){
            midCandidate.push_back(point[i]);
        }
    }
    sort(midCandidate.begin(), midCandidate.end(), yCmp);
    int midCandidateSZ = midCandidate.size();
    for(int i=0; i<midCandidateSZ-1; i++){
        for(int j=i+1; j<midCandidateSZ; j++){
            if((midCandidate[i].y - midCandidate[j].y) * (midCandidate[i].y - midCandidate[j].y) > minimum) break;
            int dist = calc(midCandidate[i], midCandidate[j]);
            minimum = min(dist, minimum);
        }
    }
    return minimum;

}

void divide(){

    cout << conquer(0, N-1);

}

int main(){
    input();
    sort(point.begin(), point.end(), cmp);

    divide();
}