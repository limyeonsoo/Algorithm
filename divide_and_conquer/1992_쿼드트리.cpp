//#include <iostream>
//#include <vector>
//
//using namespace std;
//int N;
//vector <vector<int> > v;
//
//
//void dfs(int sx, int sy, int ex, int ey) {
//	if ((ey - sy) == 0 || (ex - sx) == 0) {
//		cout << v[sx][sy];
//		return;
//	}
//	bool zero = true, one = true;
//	for (int i = sx; i < ex; i++) {
//		for (int j = sy; j < ey; j++) {
//			if (v[i][j])
//				one = false;
//			else 
//				zero = false;
//		}
//	}
//	if (zero) cout << "1";
//	else if (one) cout << "0";
//	else {
//		cout << "(";
//		dfs(sx, sy, sx + (ex - sx) / 2, sy + (ey - sy) / 2);
//		dfs(sx, sy + (ey - sy) / 2, sx + (ex - sx) / 2, ey);
//		dfs(sx + (ex - sx) / 2, sy, ex, sy + (ey - sy) / 2);
//		dfs(sx + (ex - sx) / 2, sy + (ey - sy) / 2, ex, ey);
//		cout << ")";
//	}
//	return;
//}
//
//void input() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//	v.resize(N); for (int i = 0; i < N; i++) v[i].resize(N);
//	for (int i = 0; i < N; i++) {
//		string s;
//		cin >> s;
//		for (int j = 0; j < N; j++) {
//			v[i][j] = s[j]-'0';
//		}
//	}
//}
//int main() {
//	input();
//	dfs(0, 0, N, N);
//}

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> rotation(vector<vector<int>> key) {
    cout << "key size : " << key.size() << '\n';

    vector<vector<int > > temp; temp.resize(key.size());
    for (int i = 0; i < temp.size(); i++) temp[i].resize(key.size());

    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            temp[i][j] = key[i][j];
        }
    }
    for (int i = 0; i < key.size(); i++)
        for (int j = 0; j < key.size(); j++)
            key[i][j] = temp[key.size() - j - 1][i];
    return key;
}
int main() {
    vector<vector<int>> key = { {0,0,0,1},{1,1,0,0,},{0,2,0,0},{1,2,3,4} };
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            cout << key[i][j] << ' ';
        }cout << '\n';
    }cout << '\n';
    vector<vector<int>> new_key = rotation(key);
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            cout << new_key[i][j] << ' ';
        }cout << '\n';
    }cout << '\n';
}