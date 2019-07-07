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
vi adj[MAX];
int vis[MAX];
set<int> cycle;
int loop = -1;
bool f = false;

void dfs1(int u , int par = -1){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(loop != -1)
            break;
        if(!vis[v] && v != par)
            dfs1(v ,u);
        else if(v != par && loop == -1){
            loop = v;
            break;
        }
    }
    if(loop != -1 && !f){
        cycle.insert(u);
        if(u == loop)
            f = true;
    }
}
int tot = 0;
void dfs2(int u){
    vis[u] = 1;
    ++tot;
    for(auto v : adj[u]){
        if(!vis[v])
            dfs2(v);
    }
}
int in[MAX] , cnt;
bool test;
void check(int u , int par = -1){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(v == par)
            continue;
        if(in[v]){
            ++cnt;
        }
        else if(!vis[v]){
            check(v , u);
        }
        else if(vis[v] == 1){
            test = true;
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 0 ; i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs2(1);
    mem(vis,0);
    if(tot != n){
        printf("NO");
        return 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            dfs1(i);
            if(!cycle.empty())
                break;
        }
    }
    if(cycle.empty()){
        printf("NO");
        return 0;
    }
    for(auto i : cycle){
        in[i] = 1;
//        printf("%d , " , i);
    }

    for(int i = 1 ; i <= n ; ++i){
        if(!in[i])
            continue;
        mem(vis,0);
        test = false;
        cnt = 0;
        check(i);
        if(test || cnt > 2){
//            printf("i == %d , cnt == %d , test == %d\n" , i , cnt, test);
//            for(auto p : adj[i]){
//                printf("%d , " , p);
//            }
//            blank;
            break;
        }
    }

    if(test || cnt > 2)
        printf("NO");
    else
        printf("FHTAGN!");




return 0;
}
