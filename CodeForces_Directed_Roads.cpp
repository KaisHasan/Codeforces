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
vi adj[2*MAX];

ll power(int x , int y){
    if(!y)
        return 1;
    ll res = power(x , y / 2);
    res = (res * res)%MOD;
    if(y & 1)
        res = (res * (x%MOD))%MOD;
    return res;
}
int vis[2*MAX];
int loop = -1;
set<int> res;
bool f = false;
int nodes = 0;
void dfs(int u){
    vis[u] = 1;
    ++nodes;
    for(auto v : adj[u]){
        if(!vis[v])
            dfs(v);
        else if(vis[v] == 1 && loop == -1 && !f){
            loop = v;
        }
    }
    if(loop != -1 && !f){
        res.insert(u);
        if(u == loop)
            f = true;
    }
    vis[u] = 2;
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 1 ; i <= n ; ++i){
        int x;sc(x);
        adj[i].pb(x);
    }
    ll ans = 1;
    for(int i = 1;  i <= n ; ++i){
        if(!vis[i]){
            nodes =  0;
            res.clear();
            f = false;
            loop = -1;
            dfs(i);
            int m = res.size();
//            printf("m == %d\n" ,m);
            ans = (ans * ((power(2 ,nodes) - (m != 0 ? power(2 , nodes - m + 1) : 0) + MOD)%MOD))%MOD;
        }
    }
    printf("%I64d", ans);



return 0;
}
