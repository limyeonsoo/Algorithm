/*
		r , c  가 홀 수 일 때  :  상관 X
		r 짝수, c 홀수 일 때 :  Down 후 Right
		r 홀수, c 짝수 일 때 :  Right 후 Down
		r 짝수, c 짝수 일 때 :  한 칸은 버린다.
*/

#pragma warning(disable:4996)

#include <iostream>

#include <string>

#include <algorithm>

using namespace std;



const int MAX = 1000;

const int INF = 987654321;



int arr[MAX][MAX];

string result;



int main(void)

{

    ios_base::sync_with_stdio(0);

    cin.tie(0); //cin 실행속도 향상

    int R, C;

    cin >> R >> C;



    //세로가 홀수

    if (R % 2)

    {

        for (int y = 0; y < R; y++)

        {

            for (int x = 0; x < C - 1; x++)

                if (y % 2 == 0)

                    result += 'R';

                else

                    result += 'L';

            if (y != R - 1)

                result += 'D';

        }

    }

    //세로가 짝수 가로가 홀수

    else if (!(R % 2) && C % 2)

    {

        for (int x = 0; x < C; x++)

        {

            for (int y = 0; y < R - 1; y++)

                if (x % 2 == 0)

                    result += 'D';

                else

                    result += 'U';

            if (x != C - 1)

                result += 'R';

        }

    }

    //세로가 짝수 가로가 짝수

    else if (!(R % 2) && !(C % 2))

    {

        pair<int, int> minHappy; //검은 칸이면서 지나지 말아야 할 지점

        int minScore = INF;

        for (int y = 0; y < R; y++)

            for (int x = 0; x < C; x++)

            {

                cin >> arr[y][x];

                //검은칸이고 최소점수

                if ((y + x) % 2 && minScore > arr[y][x])

                {

                    minScore = arr[y][x];

                    minHappy = { y, x };

                }

            }



        //지나지 말아야 할 좌표의 최좌측으로 내려오고

        int newR = minHappy.first % 2 ? minHappy.first - 1 : minHappy.first;

        for (int y = 0; y < newR; y++)

        {

            for (int x = 0; x < C - 1; x++)

                if (y % 2 == 0)

                    result += 'R';

                else

                    result += 'L';

            result += 'D';

        }

        //지나지 말아야 할 좌표의 대각선 아래까지 이동하고(↙)

        int newC = minHappy.second;

        for (int x = 0; x < newC; x++)

            if (x % 2 == 0)

                result += "DR";

            else

                result += "UR";



        //지나지 말아야 할 좌표의 최우측으로 이동

        for (int x = newC; x < C - 1; x++)

            if (x % 2 == 0)

                result += "RD";

            else

                result += "RU";



        //목적지까지

        if (minHappy.first % 2 == 0)

            newR = R - (minHappy.first + 2);

        else

            newR = R - (minHappy.first + 1);



        for (int y = 0; y < newR; y++)

        {

            result += 'D';

            for (int x = 0; x < C - 1; x++)

                if (y % 2 == 0)

                    result += 'L';

                else

                    result += 'R';

        }

    }

    cout << result << "\n";

    return 0;

}
//#include <iostream>
//#define MAX 1001
//#define printr (printf("R"))
//#define printd (printf("D"))
//#define printl (printf("L"))
//#define printu (printf("U"))
//using namespace std;
//int r, c;
//int tile[MAX][MAX];
//
//
//
//int main() {
//	scanf("%d %d", &r, &c);
//	for (int i = 0; i < r; i++) {
//		for (int j = 0; j < c; j++) {
//			scanf("%d", &tile[i][j]);
//		}
//	} //입력완료
//	
//	if (r % 2 == 1) {
//
//		for (int i = 0; i < r-1; i++) {
//			for (int j = 0; j < c - 1; j++) printr;
//			if (i == r - (r/2 + 1)) break;
//			printd;
//			for (int j = 0; j < c - 1; j++) printl;
//			printd;
//			
//		}
//	}
//
//	/*
//	  5 4 3 2
//	  2 2 2 2 
//	  1 1 1 1
//	  1 1 1 1
//	  */
//	else if (r % 2 == 0 && c % 2 == 1) {
//		for (int i = 0; i < c - 1; i++) {
//			for (int j = 0; j < r - 1; j++) printd;
//			if (i == c - (c / 2 + 1)) break;
//			printr;
//			for (int j = 0; j < r - 1; j++) printu;
//			printr;			
//		}
//	}
//	else {
//		int min = 1001, minx, miny;
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++) {
//				if (i % 2 != j % 2 && min > tile[i][j]) {
//					min = tile[i][j];
//					minx = j;
//					miny = i;
//				}
//
//
//			}
//		}
//	}
//}