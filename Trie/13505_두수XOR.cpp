#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#define uint unsigned int
using namespace std;

struct Trie {
	Trie* next[2];
	int nowTrie;
	Trie() {
		fill(next, next + 2, nullptr);
	}
	~Trie() {
		for (int i = 0; i < 2; i++) if (next[i]) delete next[i];
	}
	void insert(const char* bit) {
		if (*bit == '\0') {
			return;
		}
		int curr = *bit - '0';
		
		if (curr == 1) {
			if (!next[1]) next[1] = new Trie;
			next[1]->insert(bit + 1);
			nowTrie = 1;
		}
		else {
			if (!next[0]) next[0] = new Trie;
			next[0]->insert(bit + 1);
			nowTrie = 0;
		}
	}
	uint find(const char* bit, uint depth) {
		uint temp = 0;
		if (*bit == '\0') {
			return 0;
		}
		int curr = *bit - '0';
		if (curr == 1) {
			//이왕이면 0으로 
			if (next[0]) temp += pow(2,depth)+next[0]->find(bit + 1, depth - 1);
			else temp = next[1]->find(bit + 1, depth-1);
		}
		else {
			//이왕이면 1로
			if (next[1]) temp += pow(2,depth)+next[1]->find(bit + 1, depth - 1);
			else temp = next[0]->find(bit + 1, depth-1);
		}
		return temp;
	}
	 
};
Trie* root = new Trie;
vector <uint> numbers;
uint maxValue;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int testCase, temp;
	cin >> testCase;
	while (testCase--) {
		cin >> temp;
		numbers.push_back((uint)temp);
		uint tempBit = (uint)temp;
		string bitStr;
		for (int i = 31; i >= 0; i--)
			bitStr += (tempBit & (1 << i) ? '1':'0');
		root->insert(bitStr.c_str());
	}
}
int main() {
	input();
	
	for (auto& number : numbers) {
		string bitStr;
		for (int i = 31; i >= 0; i--)
			bitStr += (number & (1 << i) ? '1' : '0');
		uint res = root->find(bitStr.c_str(), 31);
		maxValue = (maxValue < res ? res : maxValue);
	}
	cout << maxValue;
}