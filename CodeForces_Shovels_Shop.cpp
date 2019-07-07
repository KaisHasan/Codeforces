#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<long long , long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
#define INF 1e9
#define EPS 1e-9
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n, m, k;
	sc(n);sc(m);sc(k);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	a.resize(k);
	reverse(a.begin(), a.end());

	vector<int> offers(k + 1);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (x <= k) {
			offers[x] = max(offers[x], y);
		}
	}

	vector<int> pref(k + 1);
	for (int i = 0; i < k; ++i) {
		pref[i + 1] = pref[i] + a[i];
	}

	vector<int> dp(k + 1, INF);
	dp[0] = 0;
	for (int i = 0; i < k; ++i) {
		dp[i + 1] = min(dp[i + 1], dp[i] + a[i]);
		for (int j = 1; j <= k; ++j) {
			if (offers[j] == 0) continue;
			if (i + j > k) break;
			dp[i + j] = min(dp[i + j], dp[i] + pref[i + j - offers[j]] - pref[i]);
		}
	}

	cout << dp[k] << endl;

return 0;
}
