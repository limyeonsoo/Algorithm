/*
	위에서 부터 스캔.
	 : 이유: 낮은 빌딩을 생략 할 수 있어야함.
	   => X좌표에 대한 visit 설정?
	우선순위는 x좌표가 작은 것 부터.

	warning : 
	  우뚝 솟은 빌딩으로 반 이 갈라졌을 경우.

	  => 시간 복잡도가 너무 크다.

	  0 인 평지를 처리 못함.  0의 길이를 알 수 없음.


	  1.  0-5  4-10  일 경우 0-4로 자를 수 있어야함.
	  2.  15-25  20-23 일 경우 23-25를 앞에 빌딩으로 연결할 수 있어야함.


*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

int N, s, t, deadline;
struct Coord {
	int start;
	int height;
	int end;
};

struct cmp {
	bool operator()(const Coord& a, const Coord& b) {
		return a.start > b.start;
	}
};

std::priority_queue <Coord, std::vector<Coord>, cmp> pq;
std::vector <Coord> buildings;

void input() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> N; 
	buildings.resize(N);
	for (int i = 0; i < N; i++) {
		std::cin >> buildings[i].start >> buildings[i].height >> buildings[i].end;
		pq.push(buildings[i]);
	}

	//x좌표의 끝 좌표 구하기 위한 코드.
	const auto p = max_element(buildings.begin(), buildings.end(), [](const auto& lhs, const auto& rhs) {return lhs.end < rhs.end; });
	deadline = p->end + 1;
}

void sweeping() {
	Coord now = pq.top(); pq.pop();
	while (!pq.empty()) {
		Coord next = pq.top(); pq.pop();	
		// 겹치는게 없다.
		if (now.end <= next.start) {
			// 높이가 달라야한다.
			if (now.height == next.height) {
				pq.push({ now.start, now.height, next.end });
			}
			else {
				// 공간사이 건물.
				if (next.start - now.end > 0) {
					pq.push({ now.end, 0, next.start });
				}
				std::cout << now.start << ' ' << now.height << ' ';
				pq.push(next);
			}
		}
		//시작점이 같다.
		else if (now.start == next.start) {
			if (now.height != next.height) {
				//next가 길다.
				if (now.end < next.end) {
					if (now.height > next.height) {
						pq.push({ now.start, now.height, now.end });
						pq.push({ now.end, next.height, next.end });
					}
					else if(now.height < next.height){
						pq.push({ now.start, next.height, next.end });
					}
				}
				// now 가 길다.
				else if (now.end > next.end) {
					if (now.height > next.height) {
						pq.push({ now.start, now.height, now.end });
					}
					else if (now.height < next.height) {
						pq.push({ now.start, next.height, next.end });
						pq.push({ next.end, now.height, now.end });
					}
				}
			}
			//높이가 같다.  but 완전 같으면 안됨.
			else if(now.height == next.height && now.end != next.end){
				pq.push({ now.start, now.height, std::max(now.end, next.end) });
			}
		}
		//next가 튀어나가게 겹친다. ** 시작점이 같을 수 있다.**
		else if (now.start < next.start && now.end < next.end) {
			//now가 낮을 때
			if (now.height < next.height) {
				//시작은 같은데 덮어버리는 경우.
				if(now.start != next.start)
					pq.push({ now.start, now.height, next.start });
				pq.push({ next.start, next.height, next.end });
			}
			//now가 높을 때
			else if (now.height > next.height) {
				pq.push({ now.start, now.height, now.end });
				pq.push({ now.end, next.height, next.end });
			}
			//높이가 같을 때
			else if (now.height == next.height) {
				pq.push({ now.start, now.height, next.end });
			}
		}
		// next가 중간에 꼈다. **시작점이 같을 수 있다.**
		else if (now.start < next.start && now.end >= next.end) {
			// next가 중간에서 솟았다.
			// + 같아서 now가 더 크다.
			if (now.height >= next.height) {
				pq.push({ now.start, now.height, now.end });
			}
			else if (now.height < next.height) {

				pq.push({ now.start, now.height, next.start });
				pq.push({ next.start, next.height, next.end });
				//끝이 같을 수도 있다.
				if (now.end != next.end && now.start != next.start) {
					pq.push({ next.end, now.height, now.end });
				}
			}
			
		}		
		now = next;
	}
	//마지막 건물
	if (pq.empty()) std::cout << now.start << ' ' << now.height << ' ';
	//마지막 데드라인
	if (now.end != deadline) std::cout << now.end << ' ' << 0;	
}

int main() {
	input();
	sweeping();
}


/*

2
1 5 5
1 8 5

-> 1 8 5 0

2
5 8 8
5 6 6

-> 5 8 8 0

3
1 5 5
3 4 6
4 3 7

-> 1 5 5 4 6 3 7 0

3
1 8 6
3 6 8
6 8 9

-> 1 8 9 0

*/