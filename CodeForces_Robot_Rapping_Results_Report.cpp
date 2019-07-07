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

int n , m;
vpi adj[MAX];

bool test;
int vis[MAX] , in[MAX] , nodes;

void cycle(int u){
    ++nodes;
    vis[u] = 1;
    if(test)
        return;
    for(auto it : adj[u]){
        int v = it.first;
        if(!vis[v])
            cycle(v);
        else if(vis[v] == 1){
            test = true;
            return;
        }
    }
    vis[u] = 2;
}
int k;
int d[MAX];
void dfs(int u){
    d[u] = 1;
    int mx = 0;
    for(auto it : adj[u]){
        int v = it.first;
        int t = it.second;
        if(t > k)
            continue;
        if(!d[v])
            dfs(v);
        mx = max(mx , d[v]);
    }
    d[u] += mx;
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 1 ; i <= m ; ++i){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(MP(v,i));
        in[v]++;
    }
    int root = -1;
    for(int i = 1 ; i <= n ; ++i){
        if(!in[i]){
            root = i;
            break;
        }
    }
    if(root == -1){
        printf("-1");
        return 0;
    }
    test = false;
    nodes = 0;
    cycle(root);
    if(test || nodes < n){
        printf("-1");
        return 0;
    }
    int st = 1 , en = m;
    int res = -1;
    while(st <= en){
        int md = (st+en)>>1;
        k = md;
        mem(d,0);
        dfs(root);
        if(d[root] == n)
            test = true;
        else
            test = false;
        if(test){
            res = md;
            en = md - 1;
        }
        else
            st = md + 1;
    }

    printf("%d" , res);

return 0;
}
