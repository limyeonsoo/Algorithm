#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
struct Trie {
	// 먹이의 정보 개수가 N, 1000이하면 next가 1000이상이 되지 않지 않을까?
	Trie* next[1001];
	bool isEnd;
	std::unordered_map <std::string, int> map;
	int count;
	Trie() {
		std::fill(next, next + 1001, nullptr);
		map.clear();
		count = 0;
		isEnd = false;
	}
	~Trie() {

	}
	void insert(std::vector <std::string> key, int idx) {
		if (key[idx] == " ") {
			isEnd = true;
			return;
		}
		std::string currStr = key[idx];
		
		std::unordered_map<std::string, int>::const_iterator got = map.find(currStr);
		// map에 있을 때.
		if (got != map.end()) {
			next[got->second]->insert(key, idx + 1);
		}
		else { //map에 없을 때.
			if(!next[count]) next[count] = new Trie;
			map.insert({currStr, count});
			next[count++]->insert(key, idx + 1);
		}
		return;
	}
	void preorder(int depth) {
		std::vector <std::pair<std::string, int> > temp;
		std::unordered_map<std::string, int>::iterator iter;
		for (iter = map.begin(); iter != map.end(); ++iter) temp.push_back(*iter);
		sort(temp.begin(), temp.end());
		for (auto &set : temp) {
			for (int hyphen = 0; hyphen < depth; hyphen++) std::cout << "-";
			std::cout << set.first << '\n';
			next[set.second]->preorder(depth + 2);
		}
	}
};
Trie* root = new Trie;
void input() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int T;
	std::cin >> T;
	while (T--) {
		std::vector < std::string> str;
		std::string temp;
		int tokenNumber;
		std::cin >> tokenNumber;
		for (int i = 0; i < tokenNumber; i++) {
			std::cin >> temp;
			str.push_back(temp);
		}
		str.push_back(std::string(" "));
		root->insert(str, 0);
	}
}
void output() {
	root->preorder(0);
}
int main() {
	input();
	output();
}