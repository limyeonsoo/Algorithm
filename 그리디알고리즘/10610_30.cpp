#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
vector <int> v;

string s;
int temp, ans = 0, ten = 1;
bool zero = false;
int main() {    //�ϴܵ��ڸ��� ������ 0�̿��� ��. 0�� ������ 30�� ����� �� �� ����.

	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		ans += s[i]-'0';
		v.push_back((int)s[i]-'0');
		if (s[i] == '0') zero = true;
	}
	

	if (zero == false || ans%3 != 0) printf("-1");
	else {
		sort(v.begin(), v.end());
		for (int i = v.size()-1; i >= 0; i--) {
			printf("%d", v[i]);
		}
	}
}