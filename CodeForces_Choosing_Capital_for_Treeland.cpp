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

int n;
vpi adj[2*MAX];
int in[2*MAX];
int dp1[2*MAX] , dp2[2*MAX];
int vis[2*MAX];
void dfs1(int u , int p = -1){
    vis[u] = 1;
    dp1[u] = 0;
    for(auto it : adj[u]){
        int v = it.first;
        int w = it.second;
        if(!vis[v]){
            dfs1(v , u);
            dp1[u] += dp1[v] + w;
        }
    }
}

void dfs2(int u){
    vis[u] = 1;
    for(auto it : adj[u]){
        int v = it.first;
        int w = it.second;
        if(!vis[v]){
//            printf("w == %d\n" , !w);
            dp2[v] = dp2[u] + (!w) - (w);
            dfs2(v);
        }
    }
}

int solve(){
    int mn = inf;
    for(int i = 1 ; i <= n; ++i){
        mn = min(dp2[i] , mn);
    }
    return mn;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    int m = n - 1;
    for(int i =0 ; i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(MP(v,0));
        adj[v].pb(MP(u,1));
        in[v]++;
    }
    int st = -1;
    for(int i = 1 ; i <= n ; ++i){
        if(!in[i]){
            st = i;
            break;
        }
    }
//    printf("st == %d\n" , st);
    dfs1(st);
//    for(int i = 1;  i<= n ; ++i)
//        printf("dp1[%d] == %d ,  " , i , dp1[i]);
//    blank;
    mem(vis,0);
    dp2[st] = dp1[st];
    dfs2(st);
//    for(int i = 1;  i<= n ; ++i)
//        printf("dp2[%d] == %d ,  " , i , dp2[i]);

    int res = solve();
    printf("%d\n" , res);
    for(int i = 1; i <= n ; ++i)
        if(dp2[i] == res)
            printf("%d " , i);



return 0;
}
