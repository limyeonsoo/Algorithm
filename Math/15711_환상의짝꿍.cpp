#include <iostream>
#include <math.h>
#include <vector>

#define ll long long
using namespace std;
bool chae[2000001] = { true, true };
vector <ll> v;
ll T, A, B;
void eratho() {
	for (int i = 2; i <= 2000000; i++)
		if (chae[i] == false)
			for (int j = i + i; j <= 2000000; j += i)
				chae[j] = true;
}

bool prime(ll value) {
	for (ll i = 0; (i < v.size()) && (v[i]*v[i] <= value); i++) {
		if (value % v[i] == 0) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	eratho();
	for (ll i = 2; i <= 2000000; i++) if (!chae[i]) v.push_back(i);

	while (T--) {
		cin >> A >> B;
		if ((A + B) <= 3) {
			cout << "NO" << '\n';
			continue;
		}
		if ((A + B) % 2 == 0) cout << "YES" << '\n'; //°ñµå¹ÙÈå
		else cout << (prime((ll)A + (ll)B - (ll)2) ? "NO" : "YES") << '\n';
	}
}

// °ñµå¹ÙÈå¿¡ ÀÇÇØ Â¦¼ö´Â YES
// È¦¼öÀÏ °æ¿ì¿¡´Â  Â¦¼ö+È¦¼ö Áï, 2¸¦ ¹«Á¶°Ç Æ÷ÇÔÇÏ±â ¶§¹®¿¡ 
// sum-2 °¡ ¼Ò¼ö¿©¾ßÇÔ.

//6  =                   3 3
//7  =                   2 5
//8  =                   3 5
//9  =                   2 7
//10 =                   3 7
//11 = 2 9 3 8 4 7 5 6
//12 = 2 10 3 9 4 8      5 7
//13 =                   2 11
//14 = 2 12 3 11         3 11
//15 = 2 13 3 12         2 13
//16 =                   3 13  5 11
//17 =                  
//18 =                   3 15  5 13
//19 =                   2 17
//20 =                   3 17
//21 =                   2 19
//22 =                   3 19
//23 =                   5 17
//24 =                   7 17
//25 =                   2 23
//26 =					 3 23
//27                     
//28 =                   5 23
//29 =                   
/*
31  2  29
33  2  31
35  
37  

*/

//100 =                  