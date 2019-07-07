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

struct node{
    int blue , red;
    node(int _blue = 0 , int _red = 0){
        blue = _blue;
        red = _red;
    }
    node(const node& temp){
        blue = temp.blue;
        red = temp.red;
    }
};

node pre[3*MAX];
int color[3*MAX];
vi adj[3*MAX];
int vis[3*MAX];
vpi edges;
int dist[3*MAX];
// red 1
// blue 2
void dfs(int u , int depth){
    vis[u] = 1;
    dist[u] = depth;
    if(color[u] == 1)
        pre[u].red = 1;
    else if(color[u] == 2)
        pre[u].blue = 1;
    for(auto v : adj[u]){
        if(vis[v])
            continue;
        dfs(v , depth + 1);
        pre[u].blue += pre[v].blue;
        pre[u].red += pre[v].red;
    }
}

int tot[3];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);

    for(int i = 0 ; i < n; ++i){
        sc(color[i]);
        tot[color[i]]++;
    }
    int m = n - 1;
    while(m--){
        int x , y;
        sc(x);sc(y);
        --x;
        --y;
        adj[x].pb(y);
        adj[y].pb(x);
        edges.pb(MP(x,y));
    }
    dfs(0 , 0);
//    printf("pre[3].blue == %d , pre[3].red == %d\n" , pre[2].blue , pre[2].red);
    int res = 0;
    for(auto e : edges){
        int u = e.first;
        int v = e.second;
        bool test = false;
        if(dist[v] > dist[u])
            swap(u,v);
        if((pre[u].blue == tot[2] && pre[u].red == 0) || (pre[u].blue == 0 && pre[u].red == tot[1]))
            test = true;
        if(test)
            ++res;
//        if(test){
//            printf("u == %d , v == %d\n" , u+1 , v+1);
//        }
    }
    printf("%d" , res);


return 0;
}
