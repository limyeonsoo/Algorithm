#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    // ������ ���� ���� ��, �ּڰŸ� �� ���� ū ��
    // �ϴ� �Ÿ��� �������� �̺�Ž��
    sort(rocks.begin(), rocks.end());
    int start = 0, end = distance, answer = 1000000;
    while (end - start > 0) {
        int mid = (start + end) / 2;
        int remain = 0;
        int base = 0;
        for (auto &rock : rocks) { //�ּҸ� �ϴ� ���ϰ� �� �ּ��� �ִ��� ���ؾ���.
            if (rock - base < mid) { // �Ÿ��� �۴ٸ� base �ű�
                remain++;
            }
            else {  //�Ÿ��� ũ�� ���� �ʿ� X
                base = rock;
            }
        }
        if (remain > n) { //���ǰ����� ���� ���ݴٸ�? ������ ������
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