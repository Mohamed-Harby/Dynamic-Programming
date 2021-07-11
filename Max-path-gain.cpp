#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define lol                                \
    std::ios_base::sync_with_stdio(false); \
    std::cin.tie(0);
#define vi vector<int>
#define ll long long

vector<vector<int>> maze = { { 5, 1, 2, 6 }, { 6, 7, 8, 9 }, { 1, 4, 9, 11 }, {
		5, 3, 4, 7 } };

int n = 4;

bool valid(int r, int c) {
	return (r >= 0 and r < n and c >= 0 and c < n);
}

int maxPath(int r, int c) {	// pure recursion
	if (!valid(r, c))
		return 0;

	if (r == n - 1 and c == n - 1)
		return maze[r][c];

	int path1 = maze[r][c] + maxPath(r, c + 1);
	int path2 = maze[r][c] + maxPath(r + 1, c);

	return max(path1, path2);
}

/*
 *  5 1 2 6
 *  6 7 8 9
 *  1 4 9 11
 *	5 3 4 7
 * */

vector<vector<int>> dp_values(n, vector<int>(n, -1));

int dp_path(int r, int c, int pre_sum = 0) {	// bottom-up
	if (!valid(r, c)) {
		return 0;
	}
	if (dp_values[r][c] == -1)
		dp_values[r][c] = pre_sum + maze[r][c];
	else {
		if (dp_values[r][c] >= pre_sum + maze[r][c]) {
			return 0;
		} else {
			dp_values[r][c] = pre_sum + maze[r][c];
		}
	}
	if (r == n - 1 and c == n - 1)
		return dp_values[r][c];

	int path1 = dp_path(r, c + 1, dp_values[r][c]);
	int path2 = dp_path(r + 1, c, dp_values[r][c]);

	return max(path1, path2);
}

vector<vector<int>> memoiztion_values(n, vector<int>(n, -1));

/*
 *  5 1 2 6
 *  6 7 8 9
 *  1 4 9 11
 *	5 3 4 7
 * */

int mem_path(int r, int c) {	// top-down
	if (!valid(r, c))
		return 0;

	if (r == n - 1 and c == n - 1)
		return maze[r][c];

	if (memoiztion_values[r][c] != -1)
		return memoiztion_values[r][c];

	int path1 = maze[r][c] + mem_path(r, c + 1);
	int path2 = maze[r][c] + mem_path(r + 1, c);

	return memoiztion_values[r][c] = max(path1, path2);

}

int main() {
	cout << dp_path(0, 0) << '\n';
	cout << mem_path(0, 0) << '\n';
	cout << maxPath(0, 0) << '\n';
}
