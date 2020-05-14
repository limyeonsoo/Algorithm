#include <iostream>
#include <vector>
using namespace std;
int N, result, mini = 1000000000, maxi = -1000000000;
int op[4];
vector <int> v;
vector <int> p;
bool check[100];
vector <int> permutation;   //연산자의 조합
int operation() {
	result = v[0];
	for (int i = 0; i < N - 1; i++) {   // 연산자
		switch (permutation[i]) {
		case 0: result += v[i + 1]; break;
		case 1:	result -= v[i + 1]; break;
		case 2: result *= v[i + 1]; break;
		case 3: result /= v[i + 1]; break;
		}
	}
	return result;
}

void op_permutation(int depth) {
	if (depth == N-1) {
		result = operation();
		if (result < mini) mini = result;
		if (result > maxi) maxi = result;
		return;
	}
	for (int i = 0  ; i < N - 1; i++) {
		if (check[i] == true) continue;
		check[i] = true;
		permutation[depth] = p[i];
		op_permutation(depth + 1);
		check[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N; v.resize(N); permutation.resize(N - 1);
	for(int i=0; i<N; i++) cin >> v[i]; 
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
		for (int j = 0; j < op[i]; j++) p.push_back(i); // p벡터에 연산자 넣기. 순열용
	}

	for (int i = 0; i < N - 1; i++) {
		check[i] = true;
		permutation[0] = p[i];
		op_permutation(1);
		check[i] = false;
	}
	cout << maxi << '\n' << mini;
}

//int operation() {
//	result = v[0];
//	cout << v[0] << ' ';
//	for (int i = 0; i < N - 1; i++) {   // 연산자
//		switch (permutation[i].first) {
//		case 0: result += v[i + 1]; cout << "+ "; break;
//		case 1:	result -= v[i + 1]; cout << "- "; break;
//		case 2: result *= v[i + 1]; cout << "* "; break;
//		case 3: result /= v[i + 1]; cout << "/ "; break;
//		}
//		cout << v[i + 1] << ' ';
//	}
//	cout << "= " << result << '\n';
//	return result;
//}