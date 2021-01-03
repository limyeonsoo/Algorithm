#include <iostream>
#include <algorithm>

using namespace std;

const int ALPHABET = 26;
const int NUMBER = 10;

struct Trie {
	bool isEnd;
	bool hasChild;
	Trie* next[ALPHABET];
	
	// 持失切
	Trie() {
		fill(next, next + 26, nullptr);
		isEnd = hasChild = false;
	}
	
	// 社瑚切
	~Trie() {
		for (int i = 0; i < ALPHABET; i++) if(next[i]) delete next[i];
	}

	void insert(const char* key) {
		if (*key == '\0') isEnd = true;
		else {
			int current = *key - 'a';
			if (next[current] == NULL) next[current] = new Trie();
			next[current]->insert(key + 1);
		}
	}

	Trie* find(const char* key) {
		if (*key == '\0') return this;
		int current = *key - 'a';
		if (next[current] == NULL) return NULL;
		return next[current]->find(key + 1);
	}
};


int main() {

}