#include <iostream>

using namespace std;

int main() {
    for (int i = 2; i <= 5; i++) {
        for (int j = 2; j <= i; j++) {
            for (int k = i+1-j; k<=i ; k++) {
                cout << i << ',' << j << " : " << k << "," << 1 << '\n';
            }
        } cout << '\n';
        if (i == 4) break;
    }
}