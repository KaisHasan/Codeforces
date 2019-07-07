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
const int MAX = 150000;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , m;
vi adj[MAX];
int marked[MAX] , d[MAX];
vi dist;

void dfs(int u , int par = -1){
    marked[u] = d[u];
    for(auto v : adj[u]){
        if(v == par)
            continue;
        dfs(v , u);
        marked[u] |= marked[v];
    }
}
int worst;
pi BFS(int st){
    dist.assign(n + 1 , -1);
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : adj[u]){
            if(marked[v] && dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    pi res(-1,-1);
    for(int i = 1 ; i <= n ; ++i){
        if(marked[i] && dist[i] > res.second){
            res.second = dist[i];
            res.first = i;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(marked[i] && dist[i] == res.second)
            worst = min(worst , i);
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    int k = n - 1;
    while(k--){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int f;
    for(int i = 0 ; i < m ; ++i){
        int x;
        sc(x);
        f = x;
        d[x] = 1;
    }
    worst = inf;
    dfs(f);
    int node = BFS(f).first;
    pi res = BFS(node);
    int tot = 0;
    for(int i = 1 ; i <= n ; ++i){
        tot += marked[i];
    }
    --tot;
    printf("%d\n%d" , worst , 2 * tot - res.second);



return 0;
}
