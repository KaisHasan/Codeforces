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
const int MAX = 3*(1e5)+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , m;
int c[MAX];
vi adj[MAX];
int vis[MAX];
vi SCC;
int dfs_num[MAX] , dfs_low[MAX];
int dfsNumberCounter;
int numSCC;
vi res[MAX];

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    vis[u] = 1;
    SCC.pb(u);
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            tarjanSCC(v);
        }
        if(vis[v]){
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
    }

    if(dfs_num[u] == dfs_low[u]){
        ++numSCC;
        while(1){
            int v = SCC.back();
            SCC.pop_back();
            vis[v] = 0;
            res[numSCC].pb(v);
            if(u == v)
                break;
        }
    }
}

int find_min(int x){
    int mn = inf;
    for(int i = 0 ; i < (int)res[x].size() ; ++i)
        mn = min(mn , c[res[x][i]]);
    return mn;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    memset(vis , 0 , sizeof(vis));
    memset(dfs_num , -1 ,sizeof(dfs_num));
    memset(dfs_low , 0 , sizeof(dfs_low));
    dfsNumberCounter = numSCC = 0;
    SCC.clear();
    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(c[i]);
    sc(m);
    for(int i = 0 ; i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        --u;
        --v;
        adj[u].pb(v);
    }
    for(int i = 0 ; i < n ; ++i){
        if(dfs_num[i] == -1){
            tarjanSCC(i);
        }
    }
    ll sum = 0;
    ll ans = 1;
    for(int i = 1 ; i <= numSCC ; ++i){
        if(res[i].size() == 0)
            continue;
        int cnt = 0;
        int mn = find_min(i);
        sum += mn;
        for(int j = 0 ;j < (int)res[i].size() ; ++j){
            if(c[res[i][j]] == mn)
                ++cnt;
        }
        ans = (ans * cnt)%MOD;
    }
    cout<<sum<<' '<<ans;

return 0;
}
