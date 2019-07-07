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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

vi adj[2*MAX];
int dp[2*MAX];
int k;
int solve(int n){
    if(n == 1)
        return 1;
    int &res = dp[n];
    if(res != -1)
        return res;
    res = 0;
    for(int i = 0 ; i < k ; ++i){
        int _to = adj[n][i];
        if(_to == n)
            continue;
        res |= solve(_to);
    }
    return res;
}

vi temp;

int main(){

    mem(dp,-1);
    int n;
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        int x;sc(x);
        temp.pb(x);
    }
    sc(k);
    for(int i = 0 ; i < k ; ++i){
        for(int j = 0 ; j < n ; ++j){
            int x;sc(x);
            adj[x].pb(j+1);
        }
    }

    int x;
    sc(x);
    int pos = -1;
    for(int i = 0 ; i < (int)temp.size() ; ++i){
        if(temp[i] == x){
            pos = i + 1;
            break;
        }
    }

    int res = solve(pos);
    if(res)
        printf("YES");
    else
        printf("NO");


return 0;
}
