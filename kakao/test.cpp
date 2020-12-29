//#include <string>
//#include <vector>
//#include <iostream>
//using namespace std;
//string str;
//int solution(string s) {
//    int answer = s.size();
//
//    for (int tok = 1; tok <= s.size() / 2; tok++) {  // tok 단위로 나눌 수 있음.
//        int result_len = 0;
//        //기준 부분문자열
//        
//        int i = 0, j = 0;
//        bool same = false;
//        while (i <= s.size() - tok) {
//            int cnt = 1;
//            string base_s = "";
//            for (i=j; i < tok+j; i++) {
//                base_s += s[i];
//            }
//            do {
//                string cmp_s = "";
//                for (j = i; j < tok+i && j <= s.size()-1; j++) {
//                    cmp_s += s[j];
//                }
//                if (base_s == cmp_s) {
//                    same = true;
//                    cnt++;
//                    i+=tok;
//                }
//                else {
//                    j-=tok;
//                    same = false;
//                    if (i == tok) break; // 처음 문자열 부터 시작했는데 안됨;
//                }
//            } while (same);
//            if (cnt > 1) {
//                result_len += (1 + tok);
//            }
//            else {
//                result_len += tok;
//            }
//        }
//        if (result_len != 0 && result_len < answer) {
//            cout << "tok : " << tok << '\n';
//            answer = result_len;
//        }
//    }
//
//    return answer;
//}
//
//void input() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cin >> str;
//}
//
//int main() {
//    input();
//
//
//    cout << solution(str);
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//using namespace std;
//bool state;   //true => 가로  false => 세로
//struct coord {
//    int x1, y1;
//    int x2, y2;
//};
//int direction = 8;  // 좌, 우, 상, 하, 1시, 5시, 7시, 11시
//
//
//
//
//int check[101][101];
//int result = 2147483647;
//queue <coord> q;
//vector <vector <int> > v;
//int solution(vector<vector<int>> board) {
//    int answer = 0;
//    coord now = { 1,1,1,2 };
//    q.push(now);
//    while (!q.empty()) {
//        coord now = q.front(); q.pop();
//        if (now.x2 == board.size() && now.y2 == board.size()) {
//            answer = check[now.x2][now.y2];
//            break;
//        }
//        
//    }
//
//
//    return answer;
//}
//void input() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    v.resize(6);
//    for (int i = 1; i < 6; i++) {
//        v[i].resize(6);
//    }
//    v[1] = { 0, 0, 0, 0, 1, 1 };
//    v[2] = { 0, 0, 0, 0, 1, 0 };
//    v[3] = { 0, 0, 1, 0, 1, 1 };
//    v[4] = { 0, 1, 1, 0, 0, 1 };
//    v[5] = { 0, 0, 0, 0, 0, 0 };
//
//}
//
//
//
//int main() {
//    input();
//    
//}


