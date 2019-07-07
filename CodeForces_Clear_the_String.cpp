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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 600;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
int dp[MAX][MAX];
string s;

int solve(int l, int r){
    if(l > r)
        return 0;
    if(l == r)
        return 1;
    int &res = dp[l][r];
    if(res != -1)
        return res;
    res = inf;
    res = min(res , solve(l + 1 , r) + 1);
    for(int i = l + 1; i <= r ; ++i){
        if(s[i] == s[l])
            res = min(res , solve(l + 1 , i - 1) + solve(i , r));
    }
    return res;
}

int main(){

    sc(n);
    cin>>s;
    mem(dp,-1);
    int res = solve(0 , n - 1);
    cout<<res;


return 0;
}
