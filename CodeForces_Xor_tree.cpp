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
vi adj[MAX];
int cur[MAX];
int nxt[MAX];
vi res;
void dfs(int u , int par = -1, int x0 = 0 , int x1 = 0 , int x = 0){
    if(x){
        cur[u] ^= x1;
        if(cur[u] != nxt[u]){
            x1 ^= 1;
            res.pb(u);
        }
    }
    else{
        cur[u] ^= x0;
        if(cur[u] != nxt[u]){
            x0 ^= 1;
            res.pb(u);
        }
    }
    for(auto v : adj[u]){
        if(v != par)
            dfs(v , u , x0 ,x1 , x ^ 1);
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    int m = n - 1;
    while(m--){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 1 ; i <= n ; ++i){
        sc(cur[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        sc(nxt[i]);
    }

    dfs(1);
    int k = (int)res.size();
    printf("%d\n" , k);
    for(auto it : res){
        printf("%d\n" , it);
    }




return 0;
}
