//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//#include <stack>
//using namespace std;
//
//int N, M, S, sp, temp, result;
//unsigned int true_people;
//unsigned int false_people;
//vector <vector<int> > party;
//bool check[51];
//
//
//
//
//int true_false(int i) {
//	int t = 0, f = 0;
//	for (auto &k : party[i]) {
//		if (true_people & (1 << k)) { // ������ �ƴ� �ڰ� �ִ�.
//			t++;
//		}
//		else if (false_people & (1 << k)) {
//			f++;
//		}
//		else if (true_people & (1 << k) && false_people & (1 << k)) {
//			return -1;
//		}
//	}
//	if (t == 0) {
//		for (auto k : party[i]) {
//			false_people = false_people | (1 << k);
//		}
//		return 0; //������ ����
//	}
//	else if (f == 0) {
//		for (auto k : party[i]) {
//			true_people = true_people | (1 << k);
//		}
//		return 1; //����
//	}
//	else return -1;
//}
//
//void finalizing(int checking, int i) {
//	if (checking == 0) {  // �������� �߾���.
//		for (auto k : party[i]) {
//			false_people &= ~(1 << k);
//		}
//	}
//	else if (checking == 1) {  //����
//		for (auto k : party[i]) {
//			true_people &=  ~(1 << k);
//		}
//	}
//}
//
//void dfs(int now, int depth, int cnt) {
//	if (depth == M) {
//		if (result < cnt) result = cnt;
//		return;
//	}
//	
//	for (int i = 1; i < M; i++) {
//		if (check[i])continue;
//		int checking = 0;
//		
//		check[i] = true;
//		checking = true_false(i);
//		if (checking == 1) {
//			dfs(i, 1, cnt);
//		}
//		else if (checking == 0) {
//			dfs(i, 1, cnt+1);
//		}
//		finalizing(checking, i);
//		check[i] = false;
//	}
//}
//
//
//
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N >> M >> S;
//	for (int i = 0; i < S; i++) {
//		cin >> sp;
//		true_people = true_people | (1 << sp);
//	}
//
//	/*for (int i = 50; i > 0; i--) {
//		printf("%d", (secret & (1 << i - 1)) ? 1 : 0);
//	}*/
//	party.resize(M+1);
//	for (int i = 0; i < M; i++) { //party
//		cin >> temp;
//		for (int j = 0; j < temp; j++) {
//			cin >> sp;
//			party[temp].push_back(sp);
//		}
//	}
//
//	for (int i = 1; i < M; i++) {
//		int checking;
//		check[i] = true;
//		checking = true_false(i);
//		if (checking == 1) {
//			dfs(i, 1, 0);
//		}
//		else if (checking == 0) {
//			dfs(i, 1, 1);
//		}
//		check[i] = false;
//	}
//	cout << result;
//}


/* ���� 2232 */
//#include <iostream>
//#include <vector>
//using namespace std;
//int N, temp, base;
//vector <int> v;
//vector <int> result;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cin >> N;
//
//	v.push_back(0);
//	for (int i = 0; i < N; i++) {
//		cin >> temp;
//		v.push_back(temp);
//	}
//	v.push_back(0);     //v�� size ��  N+2
//
//	for (int i = 1; i < v.size() - 1; i++) {
//		if (v[i] > v[i - 1] && v[i] > v[i + 1]) result.push_back(i);
//		else if (v[i] > v[i - 1] && v[i] == v[i + 1]) result.push_back(i);
//		else if (v[i] == v[i - 1] && v[i] > v[i + 1]) result.push_back(i);
//		else if (v[i] == v[i - 1] && v[i] == v[i + 1]) result.push_back(i);
//	}
//	for (int i = 0; i < result.size(); i++) cout << result[i] << '\n';
//}

///* 1515 �� �̾� ����*/
//#pragma warning(disable:4996)
//#include <stdio.h>
//#include <vector>
//#define ll long long
//ll temp, cnt;
//int i;
//char N;
//int main() {
//	while (~scanf("%c", &N)) {
//		if (N == '\n') break;
//		if (i > 0) {
//			i--;
//			continue;
//		}
//		while (1) {
//			cnt++;
//			ll tmp = 0;
//			if (cnt < 10) if (cnt == N - '0') break;
//			else if (cnt < 100) {
//				if (cnt % 10 == N - '0') tmp++;
//				if (cnt / 10 == N - '0') tmp++;
//				if (tmp > 0) {
//					i += tmp - 1;
//					break;
//				}
//			}
//			else if (cnt < 1000) {
//				if (cnt % 10 == N - '0')tmp++;
//				if (cnt / 10 == N - '0')tmp++;
//				if (cnt / 10 % 10 == N - '0')tmp++;
//				if (cnt / 10 / 10 == N - '0')tmp++;
//				if (tmp > 0) {
//					i += tmp - 1;
//					break;
//				}
//			}
//			else {
//				if (cnt % 10 == N - '0')tmp++;
//				if (cnt / 10 == N - '0')tmp++;
//				if (cnt / 10 % 10 == N - '0')tmp++;
//				if (cnt / 10 / 10 == N - '0')tmp++;
//				if (cnt / 100 % 10 == N - '0')tmp++;
//				if (cnt / 1000 == N - '0')tmp++;
//				if (tmp > 0) {
//					i += tmp - 1;
//					break;
//				}
//			}
//		}
//	}
//	printf("%d", cnt);
//}

//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//int N, A, B;
//int AA[5];
//int BB[5];
//
//void input(int A, int CC[]) {
//	if (A / 1000 > 0) CC[1] = A / 1000;
//	if (A / 100 > 0) CC[2] = A / 100 % 10;
//	if (A / 10 > 0) CC[3] = A / 10 % 10;
//	CC[4] = A % 10;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cin >> N;
//	while(N--){
//		memset(AA, 0, sizeof(AA));
//		memset(BB, 0, sizeof(BB));
//		cin >> A >> B;
//		input(A, AA); input(B, BB);
//
//		cout << AA[1] << AA[2] << AA[3] << AA[4];
//	}
//}


//#include <iostream>
//#include <math.h>
//#define ll long long  // pow(m, d), pow(s, e) ��
//
//using namespace std;
//
//int p, q, n, on, e, d, m;
//ll S, M;
//bool eratos[1000001] = { true, true };
//void Eratosthenes_chae() {
//	for (int i = 2; i <= 1000000; i++)
//		if (eratos[i] == false) 
//			for (int j = i + i; j <= 1000000; j += i) 
//				eratos[j] = true; 
//}
//
//int main() {
//	Eratosthenes_chae(); // �Ҽ� �Ǻ� �� �����佺�׳׽� ü ����
//
//	/*
//		p�� q�� �Ҽ� �� ����.
//		n <- p * q; on <- (p-1) * (q-1);
//		e <- on�� coprime����; d <- e * d mod on = 1 d��;
//		�� ���� m <= 4
//		�޽��� S <= M^d mod n
//		���� Ȯ�� M = S^e mod n	
//	*/
//	// p, q �Է�
//	cout << "p�� �Ҽ��� �Է����ּ���" << '\n';
//	while (1) {
//		cin >> p;
//		if (eratos[p]) cout << "�Ҽ��� �ٽ� �Է����ּ���" << '\n';
//		else break;
//	}
//	cout << "p = " << p << '\n';
//	cout << "q�� �Ҽ��� �Է����ּ���" << '\n';
//	while (1) {
//		cin >> q;
//		if (eratos[q]) cout << "�Ҽ��� �ٽ� �Է����ּ���" << '\n';
//		else break;
//	}
//	cout << "p = " << p << ", q = " << q <<"\n\n";
//	
//	// n, on ���ϱ�
//	cout << "n = p * q = " << p << " * " << q << " = " << p * q << '\n';
//	cout << "on = (p-1) * (q-1) = " << p-1 << " * " << q-1 << " = " << (p-1) * (q-1) << "\n\n";
//	n = p * q; on = (p - 1) * (q - 1);
//	
//	//e, d ����
//	cout << "on:" << on << "�� coprime ������ �Ҽ� 'e' �� �Է����ּ���" << '\n';
//	bool check = true;
//	while (check) {
//		cin >> e; check = false;
//		for (int i = 2; i <= e; i++) {
//			if (e % i == 0 && on % i == 0) {
//				cout << "e�� on�� ����� "<<i << "�� �����ϴ�." << '\n';
//				cout << "e�� �ٽ� �Է����ּ���" << '\n';
//				check = true;
//				break;
//			}
//		}		
//	}
//	cout << "d => e * d mod 120 == 1 �� �̿��Ͽ� d ��� : ";
//	while (d==0) {
//		for (int i = 1;; i++) {
//			if ((e * i) % on == 1) {
//				d = i;
//				cout << d << '\n';
//				break;
//			}
//		}
//	}
//	cout << "e = " << e << ", " << "d = " << d << "\n\n";
//
//	//�� ����
//	cout << "������ �� m�� �Է����ּ���" << '\n';
//	cin >> m;
//	/*S = ((ll)pow(m, d) % n);
//	cout << "���۵� �޽��� S = M^d mod n = " << m << "^" << d << " mod " << n << " = " << S << '\n';
//	M = ((ll)pow(S, e) % n);
//	cout << "���� Ȯ�� M = S^e mod n "<< S << "^" << e << " mod " << n << " = " << M << "\n\n";
//	cout << "Ȯ�� �Ϸ�";*/
//
//	S = m;
//	for (int i = 0; i < d-1; i++) {
//		S = (ll)S * m % n;
//	}
//	cout << "���۵� �޽��� S = M^d mod n = " << m << "^" << d << " mod " << n << " = " << S << '\n';
//	M = S;
//	for (int i = 0; i < e-1; i++) {
//		M = (ll)M * S % n;
//	}
//	cout << "���� Ȯ�� M = S^e mod n "<< S << "^" << e << " mod " << n << " = " << M << "\n\n";
//	cout << "�����ߴ� m : " << m << " == " << "��ȣȭ �� M : " << M << "\n\n";
//	cout << "Ȯ�� �Ϸ�";
//
//}

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

map <string, int> genre_map;
map <string, int> genre_sum;
map <string, int>::iterator iter;

vector <vector<pair<int, int>>> vectorData;
vector <pair<string, int>> vectorSum;

template<template <typename> class P = std::less >
struct compare_pair_second {
    template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
        return P<T2>()(left.second, right.second);
    }
};
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int cnt = 0;
    for (int i = 0; i < genres.size(); i++) {
        if (genre_map.find(genres[i]) == genre_map.end()) {   //���� �帣�� ����
            genre_map.insert({ genres[i], cnt++ });           // genre_map �� (genre����, �ε���(cnt))
            genre_sum.insert({ genres[i], plays[i] });        // genre_sum �� (genre����, �� �����)
            vectorData.resize(vectorData.size() + 1);         // genre�� ���� �뷡�� ��� ����
        }
        vectorData[genre_map[genres[i]]].push_back(make_pair(plays[i], i));  // (���, �־��� �ε���)�� �帣�� ��´�.
        genre_sum[genres[i]] += plays[i];                                    // genre_sum�� �� ����� ����.
    }
    for (iter = genre_sum.begin(); iter != genre_sum.end(); iter++) {        // map�̿� �ߺ� ���� �� vector�� �ű�
        vectorSum.emplace_back(make_pair(iter->first, iter->second));
    }
    sort(vectorSum.begin(), vectorSum.end(), compare_pair_second<std::greater>()); //�帣�� �� ������� ��� ���� �������� ����.

    for (auto& data : vectorData) sort(data.begin(), data.end(), cmp);             // �帣 �� �뷡 ��� ���� ��� ���� �������� ����.

    for (int i = 0; i < vectorSum.size(); i++) {              // ���� ����� �帣 ���鼭
        int index = genre_map[vectorSum[i].first];            // �� �帣�� �ش��ϴ� index
        for (int j = 0; j < vectorData[index].size(); j++) {  // �帣�ȿ��� ���� ����� �뷡
            if (j >= 2)break;                                 // 2�� ������
            answer.push_back(vectorData[index][j].second);    // �־��� �ε����� ��������
        }
    }
    return answer;
}

int main() {
    vector <string> genres{ "classic", "pop", "classic", "classic", "pop" };
    vector <int> plays{ 500, 600, 150, 800, 2500 };
    vector <int> answer;
    answer = solution(genres, plays);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}