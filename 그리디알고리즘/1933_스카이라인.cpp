/*
	������ ���� ��ĵ.
	 : ����: ���� ������ ���� �� �� �־����.
	   => X��ǥ�� ���� visit ����?
	�켱������ x��ǥ�� ���� �� ����.

	warning : 
	  ��� ���� �������� �� �� �������� ���.

	  => �ð� ���⵵�� �ʹ� ũ��.

	  0 �� ������ ó�� ����.  0�� ���̸� �� �� ����.


	  1.  0-5  4-10  �� ��� 0-4�� �ڸ� �� �־����.
	  2.  15-25  20-23 �� ��� 23-25�� �տ� �������� ������ �� �־����.


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

	//x��ǥ�� �� ��ǥ ���ϱ� ���� �ڵ�.
	const auto p = max_element(buildings.begin(), buildings.end(), [](const auto& lhs, const auto& rhs) {return lhs.end < rhs.end; });
	deadline = p->end + 1;
}

void sweeping() {
	Coord now = pq.top(); pq.pop();
	while (!pq.empty()) {
		Coord next = pq.top(); pq.pop();	
		// ��ġ�°� ����.
		if (now.end <= next.start) {
			// ���̰� �޶���Ѵ�.
			if (now.height == next.height) {
				pq.push({ now.start, now.height, next.end });
			}
			else {
				// �������� �ǹ�.
				if (next.start - now.end > 0) {
					pq.push({ now.end, 0, next.start });
				}
				std::cout << now.start << ' ' << now.height << ' ';
				pq.push(next);
			}
		}
		//�������� ����.
		else if (now.start == next.start) {
			if (now.height != next.height) {
				//next�� ���.
				if (now.end < next.end) {
					if (now.height > next.height) {
						pq.push({ now.start, now.height, now.end });
						pq.push({ now.end, next.height, next.end });
					}
					else if(now.height < next.height){
						pq.push({ now.start, next.height, next.end });
					}
				}
				// now �� ���.
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
			//���̰� ����.  but ���� ������ �ȵ�.
			else if(now.height == next.height && now.end != next.end){
				pq.push({ now.start, now.height, std::max(now.end, next.end) });
			}
		}
		//next�� Ƣ����� ��ģ��. ** �������� ���� �� �ִ�.**
		else if (now.start < next.start && now.end < next.end) {
			//now�� ���� ��
			if (now.height < next.height) {
				//������ ������ ��������� ���.
				if(now.start != next.start)
					pq.push({ now.start, now.height, next.start });
				pq.push({ next.start, next.height, next.end });
			}
			//now�� ���� ��
			else if (now.height > next.height) {
				pq.push({ now.start, now.height, now.end });
				pq.push({ now.end, next.height, next.end });
			}
			//���̰� ���� ��
			else if (now.height == next.height) {
				pq.push({ now.start, now.height, next.end });
			}
		}
		// next�� �߰��� ����. **�������� ���� �� �ִ�.**
		else if (now.start < next.start && now.end >= next.end) {
			// next�� �߰����� �ھҴ�.
			// + ���Ƽ� now�� �� ũ��.
			if (now.height >= next.height) {
				pq.push({ now.start, now.height, now.end });
			}
			else if (now.height < next.height) {

				pq.push({ now.start, now.height, next.start });
				pq.push({ next.start, next.height, next.end });
				//���� ���� ���� �ִ�.
				if (now.end != next.end && now.start != next.start) {
					pq.push({ next.end, now.height, now.end });
				}
			}
			
		}		
		now = next;
	}
	//������ �ǹ�
	if (pq.empty()) std::cout << now.start << ' ' << now.height << ' ';
	//������ �������
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