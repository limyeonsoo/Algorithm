//#include <iostream>
//
//using namespace std;
//int T, N1, N2, result;
//int value[1000001] = { 0, 0, 1 }; // 0Àº Á¦¿Ü 1 -> 0, 2 -> 1
//
//
//int fill_value(int blank) {
//	if (blank == 1) return 0;
//	if (value[blank] != 0) return value[blank];
//	int cnt = 0;
//	if (blank % 2 == 1) { // È¦¼ö
//		if (value[blank + 1] != 0) value[blank] = 1 + value[blank + 1];
//		else value[blank] = 1 + fill_value(blank + 1);
//		//value[blank] = 1 + (value[blank + 1] != 0 ? value[blank + 1] : fill_value(blank + 1));
//	}
//	else if (blank % 2 == 0) { // Â¦¼ö
//		if (value[blank % 2] != 0) value[blank] = 1 + value[blank / 2];
//		else value[blank] = 1 + fill_value(blank / 2);
//		//value[blank] = 1 + (value[blank % 2] != 0 ? value[blank / 2] : fill_value(blank / 2));
//	}
//	////Debug
//	//cout << "blank : " << blank << "  =>  " << value[blank] << '\n';
//	return value[blank];
//}
//
//void check_range(int N1, int N2) {
//	for (int i = N1; i <= N2; i++)
//		if (value[i] == 0 && i != 1)
//			fill_value(i);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	cin >> T;
//	for (int i = 1; i <= T; i++) {
//		cin >> N1 >> N2;
//		int result = 0;
//
//		check_range(N1, N2);
//
//		//// Debug
//		for (int k = N1; k <= N2; k++) {
//		//	cout << "K : " << k << "  =>  " << value[k] << '\n';
//			result += value[k];
//		}
//
//		cout << "Case #" << i << '\n';
//		cout << result << '\n';
//	}
//}


#include <iostream>

using namespace std;
int T, N1, N2, result;
int value[1000001] = { 0, 0, 1 }; // 0Àº Á¦¿Ü 1 -> 0, 2 -> 1
int preSum[1000001];

int fill_value(int blank) {
	if (blank == 1) return 0;
	if (value[blank] != 0) return value[blank];
	int cnt = 0;
	if (blank % 2 == 1) { // È¦¼ö
		if (value[blank + 1] != 0)
			value[blank] = 1 + value[blank + 1];
		else
			value[blank] = 1 + fill_value(blank + 1);
	}
	else if (blank % 2 == 0) { // Â¦¼ö
		if (value[blank % 2] != 0)
			value[blank] = 1 + value[blank / 2];
		else 
			value[blank] = 1 + fill_value(blank / 2);
	}
	return value[blank];
}

void check_range(int N1, int N2) {
	for (int i = N1; i <= N2; i++)
		if (value[i] == 0 && i != 1)
			fill_value(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	check_range(1, 1000001);
	for (int i = 1; i < 1000001; i++) preSum[i] = preSum[i - 1] + value[i];

	for (int i = 1; i <= T; i++) {
		cin >> N1 >> N2;

		cout << "Case #" << i << '\n';
		cout << preSum[N2]-preSum[N1-1] << '\n';
	}
}

