/*
	min~max  ���̴�  1, 000, 000 �̱� ������ int ���ɤ�
	�� ������ �������� ���س��´�.



	1 -> 4
	2 -> 4
	3 -> 4
	4 -> 4


	5 -> 9
	6 -> 9
	7 -> 9
	8 -> 9
	9 -> 9

	//���۰���  min���� ū square ��� �� �ּڰ�.
	4, 9 ���� ��츦 ����ؼ� -1�� �� �� square�� ������ 0
	0 * square == 0 �̴ϱ� 
	1�� ���ؼ� * square  == square

*/


#include <iostream>
#define ll long long
using namespace std;

ll checked_num[1000001];
ll checked_sqr[1000001];
ll mini, maxi, cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> mini >> maxi;
	for (ll i = 2; i*i <= maxi; i++) {
		if (checked_num[i]) continue;

		for (ll j = i + i; j * j <= maxi; j += i) {
			checked_num[i] = true;  //�������� ��� üũ
		}

		//���۰���  min���� ū square ��� �� �ּڰ�.
		ll square = i * i;
		for (ll k = ((mini-1)/square+1)*square; k <= maxi; k+= square) {  
			if (k%(i*i) == 0 && checked_sqr[k-mini]==false) {
				cnt++;
				checked_sqr[k-mini] = true;
			}
		}
	}

	cout << maxi-mini-cnt+1;
}

/*

1 2 3  5 6 7  10

*/
