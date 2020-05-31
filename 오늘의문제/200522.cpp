///* ¿∑≥Ó¿Ã 2490 */
//
///*
//	1 1 1 0 : A
//	1 1 0 0 : B
//	1 0 0 0 : C
//	0 0 0 0 : D
//	1 1 1 1 : E
//
//*/
//#include <cstdio>
//int main() {
//	const char* ans[5] = { "D", "C", "B", "A", "E" };
//	for (int i = 0; i < 3; i++) {
//		int temp = 0, bae = 0;
//		for (int j = 0; j < 4; j++) {
//			scanf("%d", &temp);
//			if (temp == 1) bae++;
//		}
//		printf("%s\n", ans[bae]);
//	}
//}

///* ºº∑Œ¿–±‚ 10798 */
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main() {
//	vector <string> v(5);
//	int maxi = 0;
//	for (int i = 0; i < 5; i++) {
//		cin >> v[i];
//		if (v[i].size() > maxi) maxi = v[i].size();
//	}
//	for (int i = 0; i < maxi; i++) {
//		for (int j = 0; j < 5; j++) {
//			if (v[j].empty()) continue;
//			cout << v[j][0];
//			v[j].erase(v[j].begin());
//		}
//	}
//}


/* ∑Œ∫ø Ω√πƒ∑π¿Ãº« 2174 */

/*
	L :
		E : N  0 -> 3
		W : S  1 -> 2
		S : E  2 -> 0
		N : W  3 -> 1

	R :
		E : S  0 -> 2
		W : N  1 -> 3
		S : W  2 -> 1
		N : E  3 -> 0

*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
typedef struct{
	int x;
	int y;
	int EWSN;
}Robot;

typedef struct {
	int x;
	int y;
}Coord;
map <char, int> direction;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int A, B, n, m;

vector <Robot> robot;
int check[102][102];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B >> n >> m;
	robot.resize(n+1);

	direction.insert({ 'E', 0 });
	direction.insert({ 'W', 1 });
	direction.insert({ 'S', 2 });
	direction.insert({ 'N', 3 });

	for (int i = 1; i <= n; i++) {
		char temp_direction;
		cin >> robot[i].x >> robot[i].y >> temp_direction;
		robot[i].EWSN = direction[temp_direction];
		check[robot[i].y][robot[i].x] = i;
	}

	int rob, iter;  //robot, direction, iteration;
	char command;
	for (int i = 0; i < m; i++) {
		cin >> rob >> command >> iter;

		if (command != 'F') {
			for (int c = 0; c < iter; c++) {
				if (command == 'L') { //øﬁ¬ ¿∏∑Œ »∏¿¸
					if (robot[rob].EWSN == 0) robot[rob].EWSN = 3;
					else if (robot[rob].EWSN == 1) robot[rob].EWSN = 2;
					else if (robot[rob].EWSN == 2) robot[rob].EWSN = 0;
					else if (robot[rob].EWSN == 3) robot[rob].EWSN = 1;
				}
				else { //ø¿∏•¬ ¿∏∑Œ »∏¿¸
					if (robot[rob].EWSN == 0) robot[rob].EWSN = 2;
					else if (robot[rob].EWSN == 1) robot[rob].EWSN = 3;
					else if (robot[rob].EWSN == 2) robot[rob].EWSN = 1;
					else if (robot[rob].EWSN == 3) robot[rob].EWSN = 0;
				}
			}
			continue;
		}
		for (int c = 0; c < iter; c++) {
			Coord next = { robot[rob].x + dx[robot[rob].EWSN] , robot[rob].y + dy[robot[rob].EWSN] };
			if (check[next.y][next.x]) { //∑Œ∫ø √Êµπ
				cout << "Robot " << rob << " crashes into robot " << check[next.y][next.x];
				return 0;
			}
			if (1 > next.x || next.x > A || 1 > next.y || next.y > B) {
				cout << "Robot " << rob << " crashes into the wall";
				return 0;
			}
			check[robot[rob].y][robot[rob].x] = 0;
			robot[rob].x += dx[robot[rob].EWSN];
			robot[rob].y += dy[robot[rob].EWSN];
			check[robot[rob].y][robot[rob].x] = rob;
		}
	}
	cout << "OK";
}
