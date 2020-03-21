#pragma warning(disable:4996)
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cstring>
using namespace std;

const int MAXN = 50000;

void set(int N, uint64_t* dest, int k)
{
    int n = k >> 6; int b = k & 63;
    dest[n] |= uint64_t(1) << (63 - b);
}
bool isset(int N, uint64_t* dest, int k)
{
    int n = k >> 6; int b = k & 63;
    return (dest[n] & uint64_t(1) << (63 - b));
}
void clear(int N, uint64_t* dest)
{
    N = (N + 63) >> 6;
    memset(dest, 0, N * sizeof(uint64_t));
}

void rshiftor(int N, int k, uint64_t* src, uint64_t* dest)
{
    int rN = N;
    N = (N + 63) >> 6;
    int n = k >> 6; int b = k & 63;
    if (b)
    {
        dest[n] |= src[0] >> b;
        for (int i = 1; n + i < N; ++i)
            dest[n + i] |= (src[i - 1] << (64 - b)) | (src[i] >> b);
    }
    else
    {
        for (int i = 0; n + i < N; ++i)
            dest[n + i] |= src[i];
    }
    int rem = rN & 63;
    if (rem)
    {
        uint64_t mask = (uint64_t(1) << (64 - rem)) - 1;
        dest[N - 1] &= ~mask;
    }
}
void lshiftor(int N, int k, uint64_t* src, uint64_t* dest)
{
    int rN = N;
    N = (N + 63) >> 6;
    int n = k >> 6; int b = k & 63;
    if (b)
    {
        for (int i = 0; n + i + 1 < N; ++i)
            dest[i] |= (src[n + i] << b) | (src[n + i + 1] >> (64 - b));
        dest[N - n - 1] |= src[N - 1] << b;
    }
    else
    {
        for (int i = 0; n + i < N; ++i)
            dest[i] |= src[n + i];
    }
    int rem = rN & 63;
    if (rem)
    {
        uint64_t mask = (uint64_t(1) << (64 - rem)) - 1;
        dest[N - 1] &= ~mask;
    }
}

void bitcopy(int N, uint64_t* src, uint64_t* dest)
{
    N = (N + 63) >> 6;
    memcpy(dest, src, N * sizeof(uint64_t));
}


vector<bool> EGZ(int, vector<int>);

uint64_t dp[MAXN][(MAXN + 63) / 64];

vector<bool> EGZ_prime(int p, vector<int> arr)
{
    if (p == 1) return { true };
    vector<bool> ret(2 * p - 1, false);
    for (int i = 0; i < 2 * p - 1; ++i) arr[i] %= p;  //나머지 정보.

    vector<int> idx(2 * p - 1);
    /*for (int i = 0; i < idx.size(); i++) cout << idx[i] << " ";
    cout << "\n";*/
    iota(idx.begin(), idx.end(), 0);     //  0, 1, 2, 3, 4, 5, 6,  ;;;;;
    sort(idx.begin(), idx.end(), [&](int a, int b) {return arr[a] < arr[b]; });  //정렬을 작은 순으로
    for (int i = 0; i < p; ++i)
    {
        if (arr[idx[i]] == arr[idx[i + p - 1]])
        {
            for (int j = i; j < i + p; ++j) ret[idx[j]] = true;
            return ret;
        }
    }
    int imod = 0;
    for (int i = 0; i < p; ++i)
    {
        imod += arr[idx[i]];
        if (imod >= p) imod -= p;
        ret[idx[i]] = true;
    }
    if (imod == 0) return ret;

    clear(p, dp[0]);
    set(p, dp[0], imod);
    int i;
    for (i = 1; i < p; ++i)
    {
        int d = arr[idx[i + p - 1]] - arr[idx[i]];
        bitcopy(p, dp[i - 1], dp[i]);
        rshiftor(p, d, dp[i - 1], dp[i]);
        lshiftor(p, p - d, dp[i - 1], dp[i]);
        if (isset(p, dp[i], 0)) break;
    }
    assert(i != p);
    int cur = 0;
    //fprintf(stderr, "P: %d, ITER: %d\n", p, (i-1));
    for (int j = i; j >= 1; --j)
    {
        int d = arr[idx[j + p - 1]] - arr[idx[j]];
        int ncur = cur - d; if (ncur < 0) ncur += p;
        if (isset(p, dp[j - 1], ncur))
        {
            ret[idx[j]] = false;
            ret[idx[j + p - 1]] = true;
            cur = ncur;
        }
    }
    return ret;
}

vector<bool> EGZ_composite(int a, int b, vector<int> arr)
{
    vector<vector<int> > index;
    vector<int> index_vector;
    int tp = 0;
    for (int j = 0; j < a - 1; ++j)
        index_vector.push_back(tp++);

    for (int i = 0; i < 2 * b - 1; ++i)
    {
        for (int j = 0; j < a; ++j) index_vector.push_back(tp++);
        vector<int> recur_vector(2 * a - 1);
        for (int i = 0; i < 2 * a - 1; ++i) recur_vector[i] = arr[index_vector[i]];
        vector<bool> recur_answer = EGZ(a, recur_vector);

        vector<int> push_index, remain_index;
        for (int i = 0; i < 2 * a - 1; ++i)
            if (recur_answer[i]) push_index.push_back(index_vector[i]);
            else remain_index.push_back(index_vector[i]);
        index_vector = remain_index;
        index.push_back(push_index);
    }

    vector<int> sum_vector(2 * b - 1);
    for (int i = 0; i < 2 * b - 1; ++i)
    {
        long long sv = 0;
        for (int j = 0; j < a; ++j) sv += arr[index[i][j]];
        sum_vector[i] = sv / a % b;
    }
    vector<bool> rec = EGZ(b, sum_vector);
    vector<bool> ret(2 * a * b - 1, false);
    for (int i = 0; i < 2 * b - 1; ++i)
        if (rec[i])
            for (int j : index[i])
                ret[j] = true;
    return ret;
}
vector<bool> EGZ(int N, vector<int> arr)
{    
    for (int i = 2; i < N; ++i)             //복합수
        if (N % i == 0)
            return EGZ_composite(i, N / i, arr);
    
    return EGZ_prime(N, arr);               //소수
}
int main()
{
    int N; cin >> N;
    vector<int> V;
    for (int i = 0; i < 2 * N - 1; ++i)
    {
        int t; cin >> t;
        V.push_back(t);
    }
    vector<bool> ans = EGZ(N, V);
    for (int i = 0; i < 2 * N - 1; ++i)
        if (ans[i])
            cout << V[i] << " ";
    cout << endl;
    return 0;
}



//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <numeric>
//#define MAX 1000
//using namespace std;
//int N;
//int A[MAX];
//bool check[MAX];
//vector <int> ans;
//
//void dfs(int depth) {
//
//	int sum = accumulate(ans.begin(), ans.end(), 0);
//	if (sum != 0 && sum % N == 0 && depth == N) {
//		for (auto& k : ans) {
//			printf("%d ", k);
//		}
//		exit(0);
//	}
//	if (depth == N) {
//		return;
//	}
//	
//	for (int i = 0; i < 2 * N - 1; i++) {
//		if (check[i]) continue;
//		if (check[i] == false) {
//			check[i] = true;
//			ans[depth] = A[i];
//			dfs(depth + 1);
//			check[i] = false;
//		}
//	}
//}
//
//#include <malloc.h>
//int main() {
//	scanf("%d", &N); 
//	for (int i = 0; i < 2 * N - 1; ++i) {
//		scanf("%d", &A[i]);
//	}
//	ans.resize(N);
//	sort(A, A + N + 1);
//	for (int i = 0; i < 2*N-1; i++) {
//		check[i] = true;
//		ans[0] = A[i];
//		dfs(1);
//		check[i] = false;
//	}
//	printf("-1");
//}

//#pragma warning(disable:4996)
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//using namespace std;
//int N;
//int A[1001];
//vector <int> odd;
//vector <int> sum;
//int dist[1001];
//int dp[1001][1001];
//vector <vector<int>> v;
//int main() {
//	scanf("%d", &N);
//	v.resize(N+1);
//	for (int i = 0; i < 2 * N - 1; ++i) {
//		scanf("%d", &A[i]);
//		if (A[i] % 2 == 1) odd.push_back(A[i]);
//		dist[A[i]]++;   //수의 종류를 담아놓는 배열.
//	}
//	if (odd.size() >= N)
//	{
//		for (int i = 0; i < N; i++) {
//			printf("%d ", odd[i]);
//		}
//	}
//	else if (odd.size() < N) {  //홀수가 N개 없으면
//		for (int i = 0; i < N; i++) {
//			if (dist[i] > 0) {
//				dp[1][i] = i;
//				dist[i]--;
//			}
//		}  // dp 기본값.
//		for (int i = 2; i <= N; i++) {    // dp의 변수
//			for (int j = 0; j < N; j++) {  // 해당 수의 변수
//				if (j == 0 && dist[0] > 0) {
//					dp[i][j] = dp[i - 1][0] % 0;
//					v[i].push_back(j);
//					dist[0]--;
//				}
//				else if (dist[j] > 0) {
//					dp[i][j] = dp[i - 1][N - j] % j;
//					v[i].push_back(j);
//					dist[j]--;
//				}
//				 
//			}
//		}
//	}
//	for (int i = 1; i < v[N].size(); i++) {
//		printf("%d ", v[N][i]);
//	}
//
//
//}

/*
	N*0 이 되는 조합을 찾고,  없으면 ->
	N*1 이 되는 조합...
	N^(2N-1)이 되는 조합 까지.
	  x => 이러면 너무 많이 봐야함. 
	N각각 나머지를 더해서 0이되도록?
	
	
*/


//#pragma warning(disable:4996)
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//using namespace std;
//int N;
//int A[1001];
//vector <pair<long long int, int>> v;
//
//int check[1001];
//
//void dfs(int index, int depth) {
//	if (depth == N) {
//		return;
//	}
//	for (int i = 0; i <= N; i++) { //A[]의 index가 될 것.
//		if (check[i] != 0) continue;
//
//	}
//	
//}
//
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i < 2 * N - 1; ++i) {
//		scanf("%d", &A[i]);
//	}
//	// 가능한 배수를 구하자.
//	sort(A, A + N + 1); //가장 뒤에 N개 숫자의 합을 구해본다. 
//	int MAX_total = 0;
//	for (int i = 2 * N - 2; i >= N - 1; i--) {
//		MAX_total += A[i];
//	} // 이 수 안에서 N의 배수를 만들면 된다. 
//
//	for (int sum = N; sum <= MAX_total; sum*=2) { //합이 sum이 되는 것을 구하면 종료.
//		
//		for (int i = 0; i <= N; i++) {
//			check[i] = 1;
//			dfs(i,1);
//			check[i] = 0;
//		}
//
//	}
//	printf("-1");
//
//
//}

//#include <iostream>
//using namespace std;
//int N;
//bool dp[501][501][501];
//int A[501];
//int J, K;
//int main() {
//	scanf("%d", &N);
//	for (int i = 0; i < 2 * N - 1; i++) {
//		scanf("%d", &A[i]);
//	}
//	dp[0][0][0] = true; // 0개 검사 0개 골라 나머지가 0
//	for (int i = 0; i < 2 * N - 1; i++) {       // 2N-1 중 검사한 수.
//		for (int j = 0; j <= N; j++) {           // 2N-1 중 선택한 수.
//			for (int k = 0; k <= N - 1; k++) {   // 선택한 수의 나머지가 K로 떨어지는가.
//						
//			}
//		}
//	}
//}