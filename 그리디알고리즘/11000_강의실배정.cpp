/*
	int형
	끝나는 시간으로 정렬.

	끝나는 시간이 같으면 어떨까?
	1. 수업시간이 짧은 것  => 많이 넣을 수 있다.
	2. 수업시작시간이 이른 것.  => 빼곡하게 넣을 수 있다.


	=============================
	문제를 잘못 이해했다.

	강의실의 개수 구하기
	연결 되지 않는 것을 따로 떼어내야함.

	탐색하는 start time이  강의실의 end time과 맞으면 될듯함.
	강의실의 end time을 관리하고 있는 vector 필요.
	(정렬된 상태를 유지)

	lowerbound?
	tree?

	=======================
	시간 초과

	vector는 시작 시간 부터 비교
	queue는 끝나는 시간을 기준.

	=> 시작시간이 들어갈 곳이 없으면 pq.push
	=> 들어갈 곳이 있으면 pq 삭제후 다시 push

	* 모든 수업을 해야하는데, 
	pq에 있는 것은 강의별 끝나는 시간.
	classes는 start time으로 강의실 시간표가 뛰어넘지 않아야함.

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
