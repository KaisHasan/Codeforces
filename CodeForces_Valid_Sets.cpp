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
const int MAX = 3055;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;


int n , d;
vi adj[MAX];
int vis[MAX];
int c[MAX];
int f[MAX];
void dfs(int u ,int root){
    vis[u] = 1;
    f[u] = 1;
    for(int v : adj[u]){
        if(vis[v])
            continue;
        if(c[v] < c[root] || c[v] > c[root] + d)
            continue;
        if(c[v] == c[root] && v < root)
            continue;
        dfs(v , root);
        f[u] = ((ll)f[u] * (f[v] + 1))%MOD;
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(d);sc(n);
    for(int i = 1 ;i <= n ; ++i)
        sc(c[i]);
    int m = n - 1;
    while(m--){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int res = 0;
    for(int i = 1 ; i <= n ;++i){
        mem(vis , 0);
        mem(f , 0);
        dfs(i,i);
        res =(res+f[i])%MOD;
    }
    cout<<res;

return 0;
}
