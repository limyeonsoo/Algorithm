//#include <iostream>
//#include <algorithm>
//#include <set>
//
//using namespace std;
//int N, M, tmp, cnt;
//int hist[20000001];
//int arr[20000001];
//set <int> s;
//set <int>::iterator iter;
//
//
//void search(int tmp) {
//	int start = 0;
//	int end = cnt-1;
//	while (end - start >= 0) {
//		int mid = (end + start) / 2;
//		if (arr[mid] == tmp) {
//			cout << hist[arr[mid]] << '\n';
//			return ;
//		}
//		if (arr[mid] > tmp) end = mid - 1;
//		else start = mid + 1;
//	}
//	cout << "0" << '\n';
//	return ;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		cin >> tmp;
//		tmp >= 0 ? hist[tmp]++ : hist[10000000 - tmp]++;
//		tmp >= 0 ? s.insert(tmp) : s.insert(10000000 - tmp);
//	}
//	
//	for (iter = s.begin(); iter != s.end(); iter++) {
//		arr[cnt++] = *iter;
//	}
//
//	cin >> M;
//	for (int i = 0; i < M; i++) {
//		cin >> tmp;
//		tmp >= 0 ? tmp : tmp = 10000000 - tmp;
//		tmp >= 0? search(tmp):search(10000000 - tmp);
//	}
//}

#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    int Ns[N];
    for (int i = 0; i < N; i++) {
        cin >> Ns[i];
    }
    int M; cin >> M;
    int Ms[M];
    for (int i = 0; i < M; i++) {
        cin >> Ms[i];
    }

    // Process
    sort(Ns, Ns + N);

    // Control : Output
    for (int i = 0; i < M; i++) {
        int* lb, * up;
        tie(lb, up) = equal_range(Ns, Ns + N, Ms[i]);
        if (lb == up) {
            cout << 0;
        }
        else {
            cout << up-lb;
        }
        if (i != M - 1) { cout << ' '; }
    } cout << endl;
}