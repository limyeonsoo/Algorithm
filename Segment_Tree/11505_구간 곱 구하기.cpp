//
// Created by 임연수 on 2021/08/29.
//
#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
#define MOD 1000000007
using namespace std;

int N, M, K, a, b, c;
vector <ll> trees;
vector <int> v;

ll init(int node, int start, int end){
    if(start == end) return trees[node] = v[start]%MOD;
    else{
        int mid = (end-start)/2 + start;
        return trees[node] = (init(node*2, start, mid)%MOD)*(init(node*2+1, mid+1, end)%MOD)%MOD;
    }
}

ll update(int node, int start, int end, int idx, int value){
    if(!(start <= idx && idx <= end)) return trees[node]%MOD;

    if(start == end) return trees[node] = value;

    int mid = (end-start)/2 + start;
    return trees[node] = (update(node*2, start, mid, idx, value)%MOD) * (update(node*2+1, mid+1, end, idx, value)%MOD)%MOD;
}

ll print(int node, int start, int end, int left, int right){
    if(right < start || end < left) return 1;

    if(left <= start && end <= right) return trees[node]%MOD;

    int mid = (end-start)/2 + start;

    return (print(node*2, start, mid, left, right)%MOD)*(print(node*2+1, mid+1, end, left, right)%MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    v = vector<int>(N);
    trees.resize(1 << (int)(ceil(log2(N))+1));

    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    init(1, 0, N-1);
    for(int i=0; i<M+K; i++){
        cin >> a >> b >> c;

        if(a==1) update(1, 0, N - 1, b - 1, c);
        else if(a==2) cout << print(1, 0, N-1, b-1, c-1)<<'\n';
    }
}