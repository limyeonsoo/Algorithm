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
//		if (true_people & (1 << k)) { // 진실을 아는 자가 있다.
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
//		return 0; //거짓말 가능
//	}
//	else if (f == 0) {
//		for (auto k : party[i]) {
//			true_people = true_people | (1 << k);
//		}
//		return 1; //진실
//	}
//	else return -1;
//}
//
//void finalizing(int checking, int i) {
//	if (checking == 0) {  // 거짓말을 했었다.
//		for (auto k : party[i]) {
//			false_people &= ~(1 << k);
//		}
//	}
//	else if (checking == 1) {  //진실
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


/* 지뢰 2232 */
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
//	v.push_back(0);     //v의 size 는  N+2
//
//	for (int i = 1; i < v.size() - 1; i++) {
//		if (v[i] > v[i - 1] && v[i] > v[i + 1]) result.push_back(i);
//		else if (v[i] > v[i - 1] && v[i] == v[i + 1]) result.push_back(i);
//		else if (v[i] == v[i - 1] && v[i] > v[i + 1]) result.push_back(i);
//		else if (v[i] == v[i - 1] && v[i] == v[i + 1]) result.push_back(i);
//	}
//	for (int i = 0; i < result.size(); i++) cout << result[i] << '\n';
//}

///* 1515 수 이어 쓰기*/
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
//#define ll long long  // pow(m, d), pow(s, e) 용
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
//	Eratosthenes_chae(); // 소수 판별 용 에라토스테네스 체 생성
//
//	/*
//		p와 q는 소수 중 선택.
//		n <- p * q; on <- (p-1) * (q-1);
//		e <- on과 coprime관계; d <- e * d mod on = 1 d값;
//		평문 선택 m <= 4
//		메시지 S <= M^d mod n
//		서명 확인 M = S^e mod n	
//	*/
//	// p, q 입력
//	cout << "p를 소수로 입력해주세요" << '\n';
//	while (1) {
//		cin >> p;
//		if (eratos[p]) cout << "소수로 다시 입력해주세요" << '\n';
//		else break;
//	}
//	cout << "p = " << p << '\n';
//	cout << "q를 소수로 입력해주세요" << '\n';
//	while (1) {
//		cin >> q;
//		if (eratos[q]) cout << "소수로 다시 입력해주세요" << '\n';
//		else break;
//	}
//	cout << "p = " << p << ", q = " << q <<"\n\n";
//	
//	// n, on 구하기
//	cout << "n = p * q = " << p << " * " << q << " = " << p * q << '\n';
//	cout << "on = (p-1) * (q-1) = " << p-1 << " * " << q-1 << " = " << (p-1) * (q-1) << "\n\n";
//	n = p * q; on = (p - 1) * (q - 1);
//	
//	//e, d 선택
//	cout << "on:" << on << "과 coprime 관계인 소수 'e' 를 입력해주세요" << '\n';
//	bool check = true;
//	while (check) {
//		cin >> e; check = false;
//		for (int i = 2; i <= e; i++) {
//			if (e % i == 0 && on % i == 0) {
//				cout << "e와 on은 공약수 "<<i << "를 가집니다." << '\n';
//				cout << "e를 다시 입력해주세요" << '\n';
//				check = true;
//				break;
//			}
//		}		
//	}
//	cout << "d => e * d mod 120 == 1 을 이용하여 d 계산 : ";
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
//	//평문 선택
//	cout << "보내실 평문 m을 입력해주세요" << '\n';
//	cin >> m;
//	/*S = ((ll)pow(m, d) % n);
//	cout << "전송될 메시지 S = M^d mod n = " << m << "^" << d << " mod " << n << " = " << S << '\n';
//	M = ((ll)pow(S, e) % n);
//	cout << "서명 확인 M = S^e mod n "<< S << "^" << e << " mod " << n << " = " << M << "\n\n";
//	cout << "확인 완료";*/
//
//	S = m;
//	for (int i = 0; i < d-1; i++) {
//		S = (ll)S * m % n;
//	}
//	cout << "전송될 메시지 S = M^d mod n = " << m << "^" << d << " mod " << n << " = " << S << '\n';
//	M = S;
//	for (int i = 0; i < e-1; i++) {
//		M = (ll)M * S % n;
//	}
//	cout << "서명 확인 M = S^e mod n "<< S << "^" << e << " mod " << n << " = " << M << "\n\n";
//	cout << "선택했던 m : " << m << " == " << "복호화 후 M : " << M << "\n\n";
//	cout << "확인 완료";
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
        if (genre_map.find(genres[i]) == genre_map.end()) {   //없는 장르가 오면
            genre_map.insert({ genres[i], cnt++ });           // genre_map 은 (genre종류, 인덱스(cnt))
            genre_sum.insert({ genres[i], plays[i] });        // genre_sum 은 (genre종류, 총 재생수)
            vectorData.resize(vectorData.size() + 1);         // genre에 따라 노래를 담는 벡터
        }
        vectorData[genre_map[genres[i]]].push_back(make_pair(plays[i], i));  // (재생, 주어진 인덱스)를 장르에 담는다.
        genre_sum[genres[i]] += plays[i];                                    // genre_sum의 총 재생수 증가.
    }
    for (iter = genre_sum.begin(); iter != genre_sum.end(); iter++) {        // map이용 중복 제거 후 vector로 옮김
        vectorSum.emplace_back(make_pair(iter->first, iter->second));
    }
    sort(vectorSum.begin(), vectorSum.end(), compare_pair_second<std::greater>()); //장르별 총 재생수를 얻기 위해 내림차순 정렬.

    for (auto& data : vectorData) sort(data.begin(), data.end(), cmp);             // 장르 안 노래 재생 수를 얻기 위해 내림차순 정렬.

    for (int i = 0; i < vectorSum.size(); i++) {              // 많이 재생된 장르 돌면서
        int index = genre_map[vectorSum[i].first];            // 그 장르에 해당하는 index
        for (int j = 0; j < vectorData[index].size(); j++) {  // 장르안에서 많이 재생된 노래
            if (j >= 2)break;                                 // 2개 까지만
            answer.push_back(vectorData[index][j].second);    // 주어진 인덱스를 정답으로
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