#include <iostream>
#include <math.h>
#define ll long long  // pow(m, d), pow(s, e) 용

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
	Eratosthenes_chae(); // 소수 판별 용 에라토스테네스 체 생성

	/*
		p와 q는 소수 중 선택.
		n <- p * q; on <- (p-1) * (q-1);
		e <- on과 coprime관계; d <- e * d mod on = 1 d값;
		평문 선택 m <= 4
		메시지 S <= M^d mod n
		서명 확인 M = S^e mod n	
	*/
	// p, q 입력
	cout << "p를 소수로 입력해주세요" << '\n';
	while (1) {
		cin >> p;
		if (eratos[p]) cout << "소수로 다시 입력해주세요" << '\n';
		else break;
	}
	cout << "p = " << p << '\n';
	cout << "q를 소수로 입력해주세요" << '\n';
	while (1) {
		cin >> q;
		if (eratos[q]) cout << "소수로 다시 입력해주세요" << '\n';
		else break;
	}
	cout << "p = " << p << ", q = " << q <<"\n\n";
	
	// n, on 구하기
	cout << "n = p * q = " << p << " * " << q << " = " << p * q << '\n';
	cout << "on = (p-1) * (q-1) = " << p-1 << " * " << q-1 << " = " << (p-1) * (q-1) << "\n\n";
	n = p * q; on = (p - 1) * (q - 1);
	
	//e, d 선택
	cout << "on:" << on << "과 coprime 관계인 소수 'e' 를 입력해주세요" << '\n';
	bool check = true;
	while (check) {
		cin >> e; check = false;
		for (int i = 2; i <= e; i++) {
			if (e % i == 0 && on % i == 0) {
				cout << "e와 on은 공약수 "<<i << "를 가집니다." << '\n';
				cout << "e를 다시 입력해주세요" << '\n';
				check = true;
				break;
			}
		}		
	}
	cout << "d => e * d mod 120 == 1 을 이용하여 d 계산 : ";
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

	//평문 선택
	cout << "보내실 평문 m을 입력해주세요" << '\n';
	cin >> m;
	/*S = ((ll)pow(m, d) % n);
	cout << "전송될 메시지 S = M^d mod n = " << m << "^" << d << " mod " << n << " = " << S << '\n';
	M = ((ll)pow(S, e) % n);
	cout << "서명 확인 M = S^e mod n "<< S << "^" << e << " mod " << n << " = " << M << "\n\n";
	cout << "확인 완료";*/

	S = m;
	for (int i = 0; i < d-1; i++) {
		S = (ll)S * m % n;
	}
	cout << "전송될 메시지 S = M^d mod n = " << m << "^" << d << " mod " << n << " = " << S << '\n';
	M = S;
	for (int i = 0; i < e-1; i++) {
		M = (ll)M * S % n;
	}
	cout << "서명 확인 M = S^e mod n "<< S << "^" << e << " mod " << n << " = " << M << "\n\n";
	cout << "선택했던 m : " << m << " == " << "복호화 후 M : " << M << "\n\n";
	cout << "확인 완료";

}