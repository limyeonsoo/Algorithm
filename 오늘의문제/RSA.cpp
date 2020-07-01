#include <iostream>
#include <math.h>
#define ll long long  // pow(m, d), pow(s, e) ��

using namespace std;

int p, q, n, on, e, d, m;
ll S, M;
bool eratos[1000001] = { true, true };
void Eratosthenes_chae() {
	for (int i = 2; i <= 1000000; i++)
		if (eratos[i] == false) 
			for (int j = i + i; j <= 1000000; j += i) 
				eratos[j] = true; 
}

int main() {
	Eratosthenes_chae(); // �Ҽ� �Ǻ� �� �����佺�׳׽� ü ����

	/*
		p�� q�� �Ҽ� �� ����.
		n <- p * q; on <- (p-1) * (q-1);
		e <- on�� coprime����; d <- e * d mod on = 1 d��;
		�� ���� m <= 4
		�޽��� S <= M^d mod n
		���� Ȯ�� M = S^e mod n	
	*/
	// p, q �Է�
	cout << "p�� �Ҽ��� �Է����ּ���" << '\n';
	while (1) {
		cin >> p;
		if (eratos[p]) cout << "�Ҽ��� �ٽ� �Է����ּ���" << '\n';
		else break;
	}
	cout << "p = " << p << '\n';
	cout << "q�� �Ҽ��� �Է����ּ���" << '\n';
	while (1) {
		cin >> q;
		if (eratos[q]) cout << "�Ҽ��� �ٽ� �Է����ּ���" << '\n';
		else break;
	}
	cout << "p = " << p << ", q = " << q <<"\n\n";
	
	// n, on ���ϱ�
	cout << "n = p * q = " << p << " * " << q << " = " << p * q << '\n';
	cout << "on = (p-1) * (q-1) = " << p-1 << " * " << q-1 << " = " << (p-1) * (q-1) << "\n\n";
	n = p * q; on = (p - 1) * (q - 1);
	
	//e, d ����
	cout << "on:" << on << "�� coprime ������ �Ҽ� 'e' �� �Է����ּ���" << '\n';
	bool check = true;
	while (check) {
		cin >> e; check = false;
		for (int i = 2; i <= e; i++) {
			if (e % i == 0 && on % i == 0) {
				cout << "e�� on�� ����� "<<i << "�� �����ϴ�." << '\n';
				cout << "e�� �ٽ� �Է����ּ���" << '\n';
				check = true;
				break;
			}
		}		
	}
	cout << "d => e * d mod 120 == 1 �� �̿��Ͽ� d ��� : ";
	while (d==0) {
		for (int i = 1;; i++) {
			if ((e * i) % on == 1) {
				d = i;
				cout << d << '\n';
				break;
			}
		}
	}
	cout << "e = " << e << ", " << "d = " << d << "\n\n";

	//�� ����
	cout << "������ �� m�� �Է����ּ���" << '\n';
	cin >> m;
	/*S = ((ll)pow(m, d) % n);
	cout << "���۵� �޽��� S = M^d mod n = " << m << "^" << d << " mod " << n << " = " << S << '\n';
	M = ((ll)pow(S, e) % n);
	cout << "���� Ȯ�� M = S^e mod n "<< S << "^" << e << " mod " << n << " = " << M << "\n\n";
	cout << "Ȯ�� �Ϸ�";*/

	S = m;
	for (int i = 0; i < d-1; i++) {
		S = (ll)S * m % n;
	}
	cout << "���۵� �޽��� S = M^d mod n = " << m << "^" << d << " mod " << n << " = " << S << '\n';
	M = S;
	for (int i = 0; i < e-1; i++) {
		M = (ll)M * S % n;
	}
	cout << "���� Ȯ�� M = S^e mod n "<< S << "^" << e << " mod " << n << " = " << M << "\n\n";
	cout << "�����ߴ� m : " << m << " == " << "��ȣȭ �� M : " << M << "\n\n";
	cout << "Ȯ�� �Ϸ�";

}