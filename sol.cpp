#include <bits/stdc++.h>

using namespace std;

//int x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
//int y[8] = {0, 1, 0, -1, 1, -1, 1, -1};

//int x[4] = {1, 0, -1, 0};
//int y[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> w(n);
		for (int i = 0; i < n; i++) {
			cin >> w[i];
		}
		sort(w.begin(), w.end());
		int ans = 0;
		for (int num = 1; num <= 100; num++) {
			vector<bool> visited(n, false);
			int teams = 0;
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					if (visited[i] || visited[j] || i == j) {
						continue;
					}
					if (w[i] + w[j] == num) {
						teams++;
						visited[i] = true;
						visited[j] = true;
					}
				}
			}
			ans = max(ans, teams);
		}
		cout << ans << '\n';
	}
}
