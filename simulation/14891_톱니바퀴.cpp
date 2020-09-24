/*
	�迭�� ��Ҹ� �����ϴ°ͺ���.
	�ε��� �ϳ��� �����ϴ°��� ȿ�������� ����.

	solve() ���� choice�� ������ direc�� 1ĭ

	�� ��� : 3 - 9   3 - 9  3 - 9

	1�θ� �̷�����ų�, 0���θ� �̷�����ɷ� �ð� ���� ����������,
	�Է��� �����鼭 solve �ϱ� ���� + �ð��� �˳��ؼ� pass


*/
#include <iostream>
#include <vector>
#include <string>
std::string temp;
int K, choice, direc, result;
int oclock1, oclock2, oclock3, oclock4;
std::vector < std::vector<int> > wheel(5, std::vector<int>(8));

bool check_three_nine(int three, int nine) {
	return (three == nine);
}

void solve() {
	int wheel1_three = wheel[1][(int)(oclock1 + 2) % 8];
	int wheel2_nine = wheel[2][(int)(oclock2 + 6) % 8];
	int wheel2_three = wheel[2][(int)(oclock2 + 2) % 8];
	int wheel3_nine = wheel[3][(int)(oclock3 + 6) % 8];
	int wheel3_three = wheel[3][(int)(oclock3 + 2) % 8];
	int wheel4_nine = wheel[4][(int)(oclock4 + 6) % 8];

	// ���� ������ ������ �ʰ� ������.
	switch (choice) {
	case 1:
		oclock1 = (oclock1 + (8 - direc) % 8) % 8;
		if (check_three_nine(wheel1_three, wheel2_nine)) break;
		oclock2 = (oclock2 + (8 + direc) % 8) % 8;
		if (check_three_nine(wheel2_three, wheel3_nine)) break;
		oclock3 = (oclock3 + (8 - direc) % 8) % 8;
		if (check_three_nine(wheel3_three, wheel4_nine)) break;
		oclock4 = (oclock4 + (8 + direc) % 8) % 8; break;
	case 2:
		oclock2 = (oclock2 + (8 - direc) % 8) % 8;
		if (!check_three_nine(wheel1_three, wheel2_nine)) {
			oclock1 = (oclock1 + (8 + direc) % 8) % 8;
		}
		if (check_three_nine(wheel2_three, wheel3_nine)) break;
		oclock3 = (oclock3 + (8 + direc) % 8) % 8;
		if (check_three_nine(wheel3_three, wheel4_nine)) break;
		oclock4 = (oclock4 + (8 - direc) % 8) % 8; break;
	case 3:
		oclock3 = (oclock3 + (8 - direc) % 8) % 8;
		if (!check_three_nine(wheel3_three, wheel4_nine)) {
			oclock4 = (oclock4 + (8 + direc) % 8) % 8;
		}
		if (check_three_nine(wheel2_three, wheel3_nine)) break;
		oclock2 = (oclock2 + (8 + direc) % 8) % 8;
		if (check_three_nine(wheel1_three, wheel2_nine)) break;
		oclock1 = (oclock1 + (8 - direc) % 8) % 8; break;
	case 4:
		oclock4 = (oclock4 + (8 - direc) % 8) % 8;
		if (check_three_nine(wheel3_three, wheel4_nine)) break;
		oclock3 = (oclock3 + (8 + direc) % 8) % 8;
		if (check_three_nine(wheel2_three, wheel3_nine)) break;
		oclock2 = (oclock2 + (8 - direc) % 8) % 8;
		if (check_three_nine(wheel1_three, wheel2_nine)) break;
		oclock1 = (oclock1 + (8 + direc) % 8) % 8;
	}
}

void input_N_solve() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	for (int i = 1; i <= 4; i++) {
		std::cin >> temp;
		for (int j = 0; j < temp.size(); j++) {
			wheel[i][j] = temp[j]-'0';
		}
	}
	std::cin >> K;
	for (int i = 0; i < K; i++) {
		std::cin >> choice >> direc;
		solve();
	}
	if (wheel[1][oclock1] == 1) result += 1;
	if (wheel[2][oclock2] == 1) result += 2;
	if (wheel[3][oclock3] == 1) result += 4;
	if (wheel[4][oclock4] == 1) result += 8;
	std::cout << result;
}

int main() {
	input_N_solve();
}