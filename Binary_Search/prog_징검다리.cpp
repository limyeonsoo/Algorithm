#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    // 바위를 제거 했을 때, 최솟거리 중 가장 큰 값
    // 일단 거리를 기준으로 이분탐색
    sort(rocks.begin(), rocks.end());
    int start = 0, end = distance, answer = 1000000;
    while (end - start > 0) {
        int mid = (start + end) / 2;
        int remain = 0;
        int base = 0;
        for (auto &rock : rocks) { //최소를 일단 구하고 그 최소중 최댓값을 구해야함.
            if (rock - base < mid) { // 거리가 작다면 base 옮김
                remain++;
            }
            else {  //거리가 크면 없일 필요 X
                base = rock;
            }
        }
        if (remain > n) { //돌의개수가 적게 없앴다면? 간격을 촘촘히
            end = mid;
        }
        else {
            start = mid + 1;
        }

        answer = mid;
    }
    return answer;
}

void main() {
    cout<< solution(25, { 2,14,11,21,17 }, 2);
}