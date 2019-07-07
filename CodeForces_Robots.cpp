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

struct node{
    int l , r , d ,u;
    node(int _l = 0  ,int _r = 0 , int _d = 0 , int _u = 0){
        l = _l;
        r = _r;
        d = _d;
        u = _u;
    }
    node(const node& t){
        l = t.l;
        r = t.r;
        d = t.d;
        u = t.u;
    }
    friend operator<(node &a , node &b){
        if(a.l != b.l)
            return a.l < b.l;
        return a.d < b.d;
    }
};


vector<node> edges;
int n , q;
vpi adj[MAX] , G[MAX];

void dfs(int u , int l , int r , int d){
    edges.pb(node(l , r, d,u));
    for(int i = 0 ; i < (int)adj[u].size() - 1 ; ++i){
        int v = adj[u][i].first;
        int w = adj[u][i].second;
        int st = w + 1;
        int en = adj[u][i+1].second;
        st = max(st , l);
        en = min(en , r);
        if(st > en)
            continue;
        dfs(v , st, en , d + 1);
    }
    int sz = adj[u].size();
    if(!sz)
        return;
    int st = adj[u][sz-1].second + 1;
    st = max(st , l);
    int en = r;
    if(st > en)
        return;
    dfs(adj[u][sz-1].first , st , en , d + 1);
}


void fuck(int u , int par = -1){
    for(auto it : G[u]){
        int v = it.first;
        int w = it.second;
        if(v == par)
            continue;
        adj[u].pb(MP(v,w));
        fuck(v , u);
    }
}

bool cmp(pi a , pi b){
    return a.second < b.second;
}

int f(int x , int id){
    return x >= edges[id].l;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        sc(n);sc(q);
        edges.clear();
        int m = n - 1;
        while(m--){
            int u,  v , w;
            sc(u);sc(v);sc(w);
            G[u].pb(MP(v,w));
            G[v].pb(MP(u,w));
        }
        fuck(1);
        for(int i = 1 ; i <= n ; ++i){
            sort(all(adj[i]) , cmp);
        }
        dfs(1 , 0 , 1000000000 , 0);
        sort(all(edges));
//        pla;
//        for(auto e : edges){
//            printf("l == %d , r == %d , d == %d , u == %d\n" , e.l , e.r , e.d , e.u);
//        }
//        pla;
        ll ans = 0;
        while(q--){
            int x;
            sc(x);
            int st = 0 , en = (int)edges.size() - 1;
            int res = 0;
            while(st <= en){
                int md = (st + en)>>1;
                if(f(x,md)){
                    st = md + 1;
                    res = md;
                }
                else
                    en = md - 1;
            }
            ans += edges[res].u;
        }
        printf("%I64d\n" , ans);
        for(int i = 1 ; i <= n ; ++i){
            G[i].clear();
            adj[i].clear();
        }
    }



return 0;
}
