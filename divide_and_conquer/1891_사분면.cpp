/*
	자릿 수 별 칸 이동
	2^0  2^1  2^2  ... ...
	1~4사이

	앞자리 = 2^(digit-1) 4
	2자리 = 2^(digit-2) 2

	x축 
	1사분면 => size/2의 오른쪽
	2사분면 => size/2의 왼쪽
	3사분면 => size/2의 왼쪽
	4사분면 => size/2의 오른쪽


	y축
	1사분면 => size/2의 위쪽
	2사분면 => size/2의 위쪽
	3사분면 => size/2의 아래쪽
	4사분면 => size/2의 아래쪽
	
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#define ll long long

ll digit, dimension, x, y, result;
std::string num;
void input() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> digit >> num >> x >> y;
}
std::pair<ll, ll> numToCoord(ll depth, ll x, ll y, ll dimension) {
	if (depth == digit) return { x,y };

	switch (num[depth]) {
	case '1':
		return numToCoord(depth + 1, x+(dimension / 2), y, dimension/2);
	case '2':
		return numToCoord(depth + 1, x, y, dimension / 2);
	case '3':
		return numToCoord(depth + 1, x, y+(dimension / 2), dimension / 2);
	case '4':
		return numToCoord(depth + 1, x+(dimension / 2), y+(dimension / 2), dimension / 2);
	}
	return { 0,0 };
}
std::string coordToNum(std::string result, ll depth, std::pair<ll, ll> coord, ll dimension, ll criteria_x, ll criteria_y) {
	if (depth == digit) return result;
	ll now_x = coord.first; ll now_y = coord.second;
	if (now_x < 0 || now_y < 0 || now_x >= (1LL << digit) || now_y >= (1LL << digit)) return "-1";
	if (now_x >= criteria_x && now_y < criteria_y) {
		return coordToNum(result += "1", depth+1, coord, dimension/2, criteria_x+dimension/2, criteria_y-dimension / 2);
	} else if (now_x < criteria_x && now_y < criteria_y) {
		return coordToNum(result += "2", depth + 1, coord, dimension / 2, criteria_x-dimension / 2, criteria_y-dimension / 2);
	} else if (now_x < criteria_x && now_y >= criteria_y) {
		return coordToNum(result += "3", depth + 1, coord, dimension / 2, criteria_x-dimension / 2, criteria_y+dimension / 2);
	} else if (now_x >= criteria_x && now_y >= criteria_y) {
		return coordToNum(result += "4", depth + 1, coord, dimension / 2, criteria_x+dimension / 2, criteria_y+dimension / 2);
	}
}
int main() {
	input();
	
	std::pair<ll, ll> start_coord = numToCoord(0, 0, 0, (1LL << digit));
	std::pair<ll, ll> end_coord = { start_coord.first + x, start_coord.second - y };
	
	std::cout << coordToNum("", 0, end_coord, (1LL << digit) / 2, (1LL << digit)/2, (1LL <<digit)/2);
}