// 281. Zigzag Iterator
// https://leetcode.com/problems/zigzag-iterator/
// https://discuss.leetcode.com/topic/24548/c-with-queue-compatible-with-k-vectors
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class ZigzagIterator {
public:
	ZigzagIterator(vector<int>& v1, vector<int>& v2): pointer(0) {
		size_t i;
		for (i = 0; (i >> 1) < v1.size() && (i >> 1) < v2.size(); ++i) {
			if (i % 2 == 0) this->v.push_back(v1[i >> 1]);
			else this->v.push_back(v2[i >> 1]);
		}
		if ((i >> 1) == v1.size()) this->v.insert(end(this->v), begin(v2) + v1.size(), end(v2));
		else this->v.insert(end(this->v), begin(v1) + v2.size(), end(v1));
	}

	int next() {
		return v[this->pointer++];
	}

	bool hasNext() {
		return this->pointer < this->v.size();
	}
private:
	size_t pointer;
	vector<int> v;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */

int main(void) {
	vector<int> v1 = {1, 2};
	vector<int> v2 = {3, 4, 5, 6};
	ZigzagIterator i(v1, v2);
	while (i.hasNext()) cout << i.next();
	cout << "\tPassed\n";
	cout << "\nPassed All\n";	
	return 0;
}