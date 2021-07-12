/*
 * Problem Statement: https://community.topcoder.com/stat?c=problem_statement&pm=8760
 * 
 * */
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define vi vector<int>
#define ll long long

ll mem[21][101];

int glob_k;

ll MaxProduct(int i, int rem) {
	ll &ret = mem[i][rem];
	if (ret != -1)
		return ret;

	if (i == glob_k) {
		if (rem == 0)
			return 1;
		else
			return 0;
	}
	int mostAvailable = rem - (glob_k - (i + 1)) + 1; // [] [] [] _ _ _, k = 6, i = 2, rem = 7
	// remaining places = k - (i+1) = 3, mostAvailable = rem - remaining places + 1 = 5

	for (int f = 1; f <= mostAvailable; ++f) {
		ret = max(ret, f * MaxProduct(i + 1, rem - f));
	}

	return ret;
}

class MaximalProduct {
public:
	ll maximalProduct(int s, int k) {	// s <= 100 , k <= 20
		glob_k = k;
		memset(mem, -1, sizeof(mem));
		return MaxProduct(0, s);
	}
};

int main() {
	MaximalProduct test;
	cout << test.maximalProduct(10, 3) << '\n';
	cout << test.maximalProduct(10, 1) << '\n';
	cout << test.maximalProduct(10, 10) << '\n';
	cout << test.maximalProduct(13, 8) << '\n';
	cout << test.maximalProduct(7, 2) << '\n';

}
/*
 * Output:
 * 36
 * 10
 * 1
 * 32
 * 12
 * 
 */
