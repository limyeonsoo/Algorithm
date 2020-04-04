/*
 문자열의 length를 알 수 있을 때는 scanf("%s")로 처리 할 수 있다.
*/






#include <iostream>
#include <string>
using namespace std;
int Apb[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string S;
    cin >> S;
    int ans = S.length();
    for (int i = 0; i < S.length(); i++) ans += Apb[S[i] - 'A'];
    cout << ans;
}

//#include <cstdio>
//int s, A, B;
//int main() {
//    scanf("%1d", &s); A += s;
//    scanf("%1d", &s); A += 10 * s;
//    scanf("%1d", &s); A += 100 * s;
//    scanf("%1d", &s); B += s;
//    scanf("%1d", &s); B += 10 * s;
//    scanf("%1d", &s); B += 100 * s;
//    A > B ? printf("%d", A) : printf("%d", B);
//}




//#include <iostream>
//#include <string>
//#include <sstream>
//using namespace std;
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    string S; int cnt = 0;
//    getline(cin, S);
//    istringstream ss(S);
//    string stringBuffer;
//    while (getline(ss, stringBuffer, ' ')) {
//        if (cnt == 0 && (int)stringBuffer[0] == 0) continue;
//        cnt++;
//    }
//    cout << cnt;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int check[27];
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    string S; int max = 0, max_i, cnt = 0;
//    cin >> S;
//    for (int i = 0; i < S.length(); i++) {
//        if (S[i] >= 97) check[S[i] - 'a']++;
//        else check[S[i] - 'A']++;
//    }
//    for (int i = 0; i < 26; i++) {
//        if (max < check[i]){
//            max = check[i];
//            max_i = i;
//        }
//    }
//    for (int i = 0; i < 26; i++) {
//        if (check[i] == max) cnt++;
//    }
//    if (cnt > 1) cout << "?";
//    else cout << (char)(65 + (char)max_i);
//}











//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	string S;
//	int N, n;
//	cin >> N;
//	while (N--) {
//		cin >> n;
//		cin >> S;
//		for (int i = 0; i < S.length(); i++) for (int j = 0; j < n; j++) cout << S[i];
//		cout << '\n';
//	}
//}

//#include <cstdio>
//int main() {
//	char S; scanf("%c", &S);
//	printf("%d", S);
//}


