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

int n , k;
int cnt;
int vis[MAX];
vi adj[MAX];

void dfs(int v){
    vis[v] = 1;
    ++cnt;
    for(auto u : adj[v]){
        if(!vis[u])
            dfs(u);
    }
}

ll power(ll x , ll y){
    if(!y)
        return 1;
    ll res = power(x , y / 2);
    res = (res * res)%MOD;
    if(y & 1)
        res = (res * x)%MOD;
    return res;
}



int main(){


    sc(n);sc(k);
    int m = n - 1;
    while(m--){
        int u , v , c;
        sc(u);sc(v);sc(c);
        if(!c){
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }

    ll res = power(n , k);
    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            cnt = 0;
            dfs(i);
            res = ((res%MOD) - power(cnt , k) + MOD)%MOD;
        }
    }

    printf("%I64d" , res);

return 0;
}
