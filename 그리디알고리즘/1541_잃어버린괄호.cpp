#pragma warning(disable:4996)
#include <iostream>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;
queue <char> q;

stack <char> num_stack;
stack <char> op_stack;
vector <string> v;
vector <int> num_vector;
bool pluus = false;
int count_10;
void cal() {
	string dumy;
	while (!q.empty()) {
		char temp = q.front(); q.pop();
		if (temp == '(') {
			do {
				dumy += q.front(); q.pop();
			} while (q.front() != ')');
			q.pop();
			v.push_back(dumy);
			dumy = "";
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int count_10 = 1;
		int number = 0;
		int dumy_result = 0;
		bool plus_ok = false;  // ���� +��ȣ�� �ִ�. �� 2�� �̻��� ���� ���ؾ���. 
		for (int j = 0; j < v[i].length(); j++) { //�� ������ ���ش�.
			if (v[i][j] != '+') {  //���ڴ�
				num_stack.push(v[i][j]);
				continue;
			}
			else if(v[i][j] == '+') {  //+��
				plus_ok = true;
				int count_10 = 1;
				int number = 0;
				for (int k = 0; k < num_stack.size();) {
					number += (int)(num_stack.top()-'0') * count_10; num_stack.pop();
					count_10 *= 10;
				}
				dumy_result += number;
			}
			
		}   
		if (!num_stack.empty()) { //���ϱⰡ ���� ��� �׳� ���ڷ�
			for (int k = 0; k < num_stack.size();) {
				number += (int)(num_stack.top() - '0') * count_10; num_stack.pop();
				count_10 *= 10;
			}
			plus_ok == true ? dumy_result += number : dumy_result = number;
		}
		num_vector.push_back(dumy_result);
	}  // ��ȣ�� ������ �׷�ȭ�� ���� ���ڷ� �� �ٲ� �� num_vector��

	
	int ans = num_vector[0];
	for (int i = 1; i < num_vector.size(); i++) {
		ans -= num_vector[i];
	}
	cout << ans;
}


int main() {
	string S; cin >> S;
	q.push('(');
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '-') {  //���� ���� ��ȣ�� ���ش�.
			q.push(')');
			q.push(S[i]);
			q.push('(');
		}
		else q.push(S[i]);
	}
	q.push(')');
	if (S[0] == '-') { q.pop(); q.pop(); } // ���� �����̿����� ��ȣ �ΰ� ����.  () - ~~~ 
	cal();
	
}