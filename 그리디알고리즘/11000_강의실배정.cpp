/*
	int��
	������ �ð����� ����.

	������ �ð��� ������ ���?
	1. �����ð��� ª�� ��  => ���� ���� �� �ִ�.
	2. �������۽ð��� �̸� ��.  => �����ϰ� ���� �� �ִ�.


	=============================
	������ �߸� �����ߴ�.

	���ǽ��� ���� ���ϱ�
	���� ���� �ʴ� ���� ���� �������.

	Ž���ϴ� start time��  ���ǽ��� end time�� ������ �ɵ���.
	���ǽ��� end time�� �����ϰ� �ִ� vector �ʿ�.
	(���ĵ� ���¸� ����)

	lowerbound?
	tree?

	=======================
	�ð� �ʰ�

	vector�� ���� �ð� ���� ��
	queue�� ������ �ð��� ����.

	=> ���۽ð��� �� ���� ������ pq.push
	=> �� ���� ������ pq ������ �ٽ� push

	* ��� ������ �ؾ��ϴµ�, 
	pq�� �ִ� ���� ���Ǻ� ������ �ð�.
	classes�� start time���� ���ǽ� �ð�ǥ�� �پ���� �ʾƾ���.

	3
999999999 1000000000
999999998 999999999
1 999999998

1 3
2 5
7 8
4 12
9 10
7 11
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

int N, s, t;
struct Classes {
	int start;
	int end;
};

bool compare(const Classes& a, const Classes& b) {
	return a.start < b.start;
}

std::priority_queue <int, std::vector<int>, std::greater<int>> pq;
std::vector <Classes> classes;

void input() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N;
	classes.resize(N);
	for (int i = 0; i < N; i++)	std::cin >> classes[i].start >> classes[i].end;
}

void scheduling() {
	pq.push(classes[0].end);
	for (int i = 1; i < classes.size(); i++) {
		int endTime = pq.top();
		if (endTime <= classes[i].start) pq.pop();
		pq.push(classes[i].end);
	}
}

int main() {
	input();
	sort(classes.begin(), classes.end(), compare);
	scheduling();
	std::cout << pq.size();
}
