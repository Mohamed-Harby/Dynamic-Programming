#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define vi vector<int>
#define ll long long
const int OO = 20000;

int poss[21][4];	// all possibilities for i , pre_color
vector<int> r, g, b;
int n;

int minPath(int i, int prev_color) {
	int &ret = poss[i][prev_color];
	if (ret != -1)
		return ret;

	if (i == n)
		return 0;
	ret = OO;
	if (prev_color != 0) {
		ret = min(ret, r[i] + minPath(i + 1, 0));
	}

	if (prev_color != 1) {
		ret = min(ret, g[i] + minPath(i + 1, 1));
	}

	if (prev_color != 2) {
		ret = min(ret, b[i] + minPath(i + 1, 2));
	}

	return ret;
}

class RGBStreet {
public:
	int estimateCost(vector<string> houses) {
		memset(poss, -1, sizeof(poss));
		n = houses.size();
		r = g = b = vi(n);
		istringstream iss;
		for (int i = 0; i < n; ++i) {
			istringstream iss(houses[i]);
			iss >> r[i] >> g[i] >> b[i];
		}
		return minPath(0, 3);
	}
};

int main() {
	RGBStreet test;
	cout << test.estimateCost( { "1 100 100", "100 1 100", "100 100 1" })
			<< '\n';
	cout << test.estimateCost( { "1 100 100", "100 100 100", "1 100 100" })
			<< '\n';
	cout << test.estimateCost( { "26 40 83", "49 60 57", "13 89 99" }) << '\n';
	cout << test.estimateCost( { "30 19 5", "64 77 64", "15 19 97", "4 71 57",
			"90 86 84", "93 32 91" }) << '\n';
	cout << test.estimateCost( { "71 39 44", "32 83 55", "51 37 63",
			"89 29 100", "83 58 11", "65 13 15", "47 25 29", "60 66 19" })
			<< '\n';
}
/*

Output:
3
102
96
208
253

*/
