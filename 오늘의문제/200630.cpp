#include<iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int board[4][4];
string cmp1 = "111211";
set <string> s;
void dfs(int x, int y, int depth, string number) {
    
    if (depth == 6) {
        s.insert(number);
        return;
    }
    if (number == cmp1) {
        cout << number << '\n';

    }
    for (int d = 0; d < 4; d++) {
        int next_x = x + dx[d];
        int next_y = y + dy[d];
        if (next_x < 0 || next_x >= 4) continue;
        if (next_y < 0 || next_y >= 4) continue;
        dfs(next_x, next_y, depth+1, number+to_string(board[next_y][next_x]));
    }
}
int main(int argc, char** argv)
{
    int temp;
    cin >> temp;
        s.clear();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << board[i][j] << ' ';
            }cout << '\n';
        }


       for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dfs(j, i, 0, to_string(board[i][j]));
            }
        }
         for(set <string> ::iterator iter = s.begin(); iter!=s.end(); ++iter){
             cout << *iter <<'\n';
         }
        cout << "# " << " " << s.size() << '\n';

    
    return 0;
}

//#include <iostream>
//using namespace std;
//int map[4][4];
//bool visitednum[10000000];
//int dy[4] = { 0,0,1,-1 };
//int dx[4] = { 1,-1,0,0 };
//
//int cnt;
//
//int dfs(int y, int x, int depth, int now)
//{
// 
//    if (depth == 7)
//    {
//        
//        if (!visitednum[now]) { 
//            /*if (now == 1112112) {
//                cout << x << ',' << y << '\n';
//            }*/
//            visitednum[now] = 1; cnt++;
//        }
//        return 0;
//    }
//    now *= 10;
//    now += map[y][x];
//
//
//    for (int i = 0; i < 4; i++)
//    {
//        int ny = y + dy[i];
//        int nx = x + dx[i];
//
//        if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4)
//        {
//            if (now == 1112112 && !visitednum[now]) cout << x << ',' << y << '\n';
//            dfs(ny, nx, depth + 1, now);
//            
//        }
//    }
//    now /= 10;
//    now -= map[y][x];
//
//}
//int main()
//{
//   
//
//        cnt = 0;
//        for (int i = 0; i < 4; i++)
//            for (int j = 0; j < 4; j++)
//                cin >> map[i][j];
//
//        for (int i = 0; i <= 9999999; i++) visitednum[i] = 0;
//        for (int i = 0; i < 4; i++)
//            for (int j = 0; j < 4; j++)
//                dfs(i, j, 0, 0);
//
//        for (int i = 0; i < 10000000; i++) {
//            if (visitednum[i]) cout << i << '\n';
//        }
//        cout << "#"<< " " << cnt << endl;
//}

/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

//#include<iostream>
//#include <vector>
//#include <set>
//#include <cmath>
//#include <string>
//using namespace std;
//
//int dx[4] = { -1, 1, 0, 0 };
//int dy[4] = { 0, 0, 1, -1 };
//int board[4][4];
//set <string> s;
//void dfs(int x, int y, string number) {
//    if (number.size() == 7) {
//        s.insert(number);
//        return;
//    }
//
//    for (int d = 0; d < 4; d++) {
//        int next_x = x + dx[d];
//        int next_y = y + dy[d];
//        if (number.size() > 6) continue;
//        if (next_x < 0 || next_x >= 4) continue;
//        if (next_y < 0 || next_y >= 4) continue;
//        number += to_string(board[next_y][next_x]);
//        dfs(next_x, next_y, number);
//    }
//}
//int main(int argc, char** argv)
//{
//    int test_case;
//    int T;
//
//    cin >> T;
//    for (test_case = 1; test_case <= T; ++test_case)
//    {
//        s.clear();
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 4; j++) {
//                cin >> board[i][j];
//            }
//        }
//
//
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 4; j++) {
//                dfs(j, i, to_string(board[i][j]));
//            }
//        }
//        for (set <string> ::iterator iter = s.begin(); iter != s.end(); ++iter) {
//            cout << *iter << '\n';
//        }
//        cout << "# " << test_case << " " << s.size() << '\n';
//
//    }
//    return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//#define INF 1000000001
//using namespace std;
//
//int N, temp, qn, q, pos;
//vector <int> value;
//vector <int> tree;
//
//int init(int node, int start, int end) {
//	if (start == end) return tree[node] = value[start];
//	else {
//		return tree[node] = min(init(node * 2, start, (start + end) / 2),
//		init(node * 2+1, (start + end) / 2 + 1, end));
//	}
//}
//int update(int node, int start, int end, int index, int value) {
////void update(int node, int start, int end, int index, int value) {
//	/*index = index + pos;
//	cout << "index : " << index<<'\n';
//	tree[index] = value;
//	while (true) {
//		index = index / 2;
//		cout << "index : " << index << '\n';
//		if (index <= 0) break;
//		tree[index] = min(tree[index*2], tree[index*2+1]);
//	}*/
//	//cout << "node : " << node << '\n';
//	if (!(start <= index && index <= end))  //구간 확인.
//		return tree[node];
//	if (start == end) {
//		//cout << "st == end node : " << node << '\n';
//		return tree[node] = value;
//	}
//	return tree[node] = min(update(node * 2, start, (start+end)/2, index, value), update(node * 2+1, (start + end) / 2+1, end, index, value));
//	
//}
//
//int print(int node, int start, int end, int left, int right) {
//	if (right < start || end < left)  //전혀 X
//		return INF;
//	if (left <= start && end <= right) { //모두 포함.
//		return tree[node];
//	}
//	int mid = (start + end) / 2;
//	return min(print(node * 2, start, mid, left, right),
//	print(node * 2 + 1, mid + 1, end, left, right)); //다음 구간으로.
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N; value.resize(N); 
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		value[i] = temp;
//	}
//	pos = pow(2,(int)ceil(log2(N))-1);
//	tree.resize(1 << ((int)ceil(log2(N)) + 1));
//	init(1, 0, N-1);
//
//	cin >> qn;
//	while (qn--) {
//		cin >> q;
//		if (q == 1) {
//			int idx, value;
//			cin >> idx >> value;
//			update(1, 0, N-1, idx-1, value);
//			
//		}
//		else if (q == 2) {
//			int left, right;
//			cin >> left >> right;
//			cout << print(1, 0, N - 1, left - 1, right - 1) << '\n';
//		}
//	}
//
//}



