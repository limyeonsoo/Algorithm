#pragma warning (disable:4996)
#include<iostream>

using namespace std;

int main(){
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if (B>= C) {
        printf("-1");
        return -1;
    }
    //�̵溻 ������ �� ���� A�� �Ѿ�� ��.
    printf("%d", A / (C-B) + 1);
    return 0;
}
