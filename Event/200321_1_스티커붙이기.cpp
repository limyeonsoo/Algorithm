#pragma warning(disable:4996)
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int W, H, K, w, h;  //  //세로, 가로, 스티커의 개수, 스티커w,h
vector <vector<int> > base;
vector <vector<int> > input;
vector <vector<int> > temp;

void rotate() {
	temp.resize(h); for (int i = 0; i < h; i++) temp[i].resize(w);
	temp.assign(input.begin(), input.end());
	input.resize(w); for (int i = 0; i < w; i++) input[i].resize(h);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			input[i][j] = temp[j][w - i];
		}
	}
		
			
}

int main() {
	scanf("%d %d %d", &H, &W, &K);
	base.resize(H); for (int i = 0; i < H; i++) base[i].resize(W);
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)	
			scanf("%d", &base[i][j]);
	while (K--) {
		scanf("%d %d", &h, &w);
		input.resize(h); for (int i = 0; i < h; i++) input[i].resize(w);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				scanf("%d", &input[i][j]); //입력
		//for (int r = 0; r < 4; r++) { //회전.
		//	if(w>W || h>)
		//}

		rotate();
		/*for (int i = 0; i < w; i++)
			for (int j = 0; j < h; j++)
				printf("%d", input[i][j]);*/
	}
}