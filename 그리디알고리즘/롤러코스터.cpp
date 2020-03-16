/*
		r , c  �� Ȧ �� �� ��  :  ��� X
		r ¦��, c Ȧ�� �� �� :  Down �� Right
		r Ȧ��, c ¦�� �� �� :  Right �� Down
		r ¦��, c ¦�� �� �� :  �� ĭ�� ������.
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

    cin.tie(0); //cin ����ӵ� ���

    int R, C;

    cin >> R >> C;



    //���ΰ� Ȧ��

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

    //���ΰ� ¦�� ���ΰ� Ȧ��

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

    //���ΰ� ¦�� ���ΰ� ¦��

    else if (!(R % 2) && !(C % 2))

    {

        pair<int, int> minHappy; //���� ĭ�̸鼭 ������ ���ƾ� �� ����

        int minScore = INF;

        for (int y = 0; y < R; y++)

            for (int x = 0; x < C; x++)

            {

                cin >> arr[y][x];

                //����ĭ�̰� �ּ�����

                if ((y + x) % 2 && minScore > arr[y][x])

                {

                    minScore = arr[y][x];

                    minHappy = { y, x };

                }

            }



        //������ ���ƾ� �� ��ǥ�� ���������� ��������

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

        //������ ���ƾ� �� ��ǥ�� �밢�� �Ʒ����� �̵��ϰ�(��)

        int newC = minHappy.second;

        for (int x = 0; x < newC; x++)

            if (x % 2 == 0)

                result += "DR";

            else

                result += "UR";



        //������ ���ƾ� �� ��ǥ�� �ֿ������� �̵�

        for (int x = newC; x < C - 1; x++)

            if (x % 2 == 0)

                result += "RD";

            else

                result += "RU";



        //����������

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
//	} //�Է¿Ϸ�
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