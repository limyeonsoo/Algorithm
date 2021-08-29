//
// Created by 임연수 on 2021/08/29.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
struct _minmax{
    int min;
    int max;
};
int N, M, a, b;
vector <_minmax> trees;
vector <int> v;

int initMin(int node, int start, int end){
    if(start == end) return trees[node].min = v[start];
    else{
        int mid = (end-start)/2 + start;
        return trees[node].min = min(initMin(node*2, start, mid), initMin(node*2+1, mid+1, end));
    }
}
int initMax(int node, int start, int end){
    if(start == end) return trees[node].max = v[start];
    else{
        int mid = (end-start)/2 + start;
        return trees[node].max = max(initMax(node*2, start, mid), initMax(node*2+1, mid+1, end));
    }
}

int printMin(int node, int start, int end, int left, int right){
    if(right < start || end < left) return 2147483647;

    if(left <= start && end <= right) return trees[node].min;

    int mid = (end-start)/2 + start;

    return min(printMin(node*2, start, mid, left, right), printMin(node*2+1, mid+1, end, left, right));
}
int printMax(int node, int start, int end, int left, int right){
    if(right < start || end < left) return 0;

    if(left <= start && end <= right) return trees[node].max;

    int mid = (end-start)/2 + start;

    return max(printMax(node*2, start, mid, left, right), printMax(node*2+1, mid+1, end, left, right));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    v = vector<int>(N);
    trees.resize(1 << (int)(ceil(log2(N))+1));
    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    initMin(1, 0, N-1);
    initMax(1, 0, N-1);

//    for(int i=0; i<trees.size(); i++){
//        cout << trees[i].min<<' ';
//    }cout << '\n';
//    for(int i=0; i<trees.size(); i++){
//        cout << trees[i].max<<' ';
//    }cout << '\n';
    for(int i=0; i<M; i++){
        cin >> a >> b;
        cout << printMin(1, 0, N-1, a-1, b-1) <<' '<< printMax(1, 0, N-1, a-1, b-1) <<'\n';
    }
}