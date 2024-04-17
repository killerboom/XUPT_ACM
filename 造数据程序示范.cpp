#include <bits/stdc++.h>
#define FAST                     \
	ios::sync_with_stdio(false); \
	cin.tie(0);                  \
	cout.tie(0)
#define debug(x) cout << endl << #x << ": " << x << endl
#define endl "\n"
#define PII pair<int, int>
#define ls p << 1
#define rs (p << 1) + 1
#define int ll
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
using db = double;
const int N = 1e3, INF = 2e5, K = 1e6;

void input() {
	int n, m = 0, k1, k2;
	n = rand() % N + 1;
	k1 = rand() % K + 1;
	k2 = rand() % K + 1;
	while(k2 > k1) k2 = rand() % K + 1;

	vector<int> a;
	for(int i = 1; i <= n; ++i) {
		int x = rand() % N + 1;
		a.push_back(x);
		m += x;
	}

	cout << n << " " << m << " " << k1 << " " << k2 << endl;
	for(int i : a) cout << i << " ";
}

void output() {
	int n, m, k1, k2;
	cin >> n >> m >> k1 >> k2;

	db sum = 0;
	for(int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		sum += x;
	}

	int l = 1, r = m;
	db h = 0.75 * k1 - 0.75 * k2;

	while(l + 10 < r) {
		int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
		db t1 = 1.5 * m1 - 0.75, ef1 = 1.0 + h * (m1 - 1) + 0.75 * k1;
		db t2 = 1.5 * m2 - 0.75, ef2 = 1.0 + h * (m2 - 1) + 0.75 * k1;

		if(t2 + sum / ef2 > m) r = m2;
		else if(t1 + sum / ef1 > m) l = m1;
		else if(t1 + sum / ef1 - (t2 + sum / ef2) < 0) r = m2;
		else l = m1;
	}

	db T = 0, EF = 1, ans = sum;
	for(int i = l; i <= r; ++i) {
		db t = 1.5 * i - 0.75, ef = 1.0 + h * (i - 1) + 0.75 * k1;

		if(ans > t + sum / ef) {
			ans = t + sum / ef;
			T = t;
			EF = ef;
		}
	}

	if(ans - m > 0) cout << -1 << endl;
	else printf("%.4f %.4f %.4f\n", T, EF, ans);
}

signed main() {
	srand((unsigned)time(NULL));
	for(int T = 1; T <= 4; ++T) {
		string c = to_string(T);
		string filename = c + ".in";
		freopen(filename.c_str(), "w", stdout);
		input();
		fclose(stdout);
	}

	for(int T = 1; T <= 4; ++T) {
		string c = to_string(T);
		string out = c + ".ans";
		string in = c + ".in";
		freopen(in.c_str(), "r", stdin);
		freopen(out.c_str(), "w", stdout);
		output();
		fclose(stdout);
	}
}
