#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

unordered_map <string, int> map;
unordered_map <string, int>::iterator iter;
vector <string> vec;
int treeTotal;
void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string treeName;
	while (getline(cin, treeName)) {
		treeTotal++;
		if (map.find(treeName) == map.end()) map.insert({ treeName, 1 });
		else map[treeName]++;
	}
}
void copy() {
	for (iter = map.begin(); iter != map.end(); ++iter) 
		vec.push_back(iter->first);
}
void print() {
	for (auto& answer : vec)
		cout << answer << ' ' <<fixed<<setprecision(4)<< ((double)map[answer]/treeTotal)*100 << '\n';
}
int main() {
	input();
	copy();
	sort(vec.begin(), vec.end());
	print();
}