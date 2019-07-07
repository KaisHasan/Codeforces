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

int par[MAX] , rnk[MAX];
ll sz[MAX];

void initi(int n){
    for(int i = 1 ; i <= n ; ++i){
        par[i] = i;
        sz[i] = 1;
        rnk[i] = 1;
    }
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}
ll mult;

bool _merge(int u , int v){
    int paru = parent(u) , parv = parent(v);
    if(paru == parv)
        return 0;
    mult = sz[parv] * sz[paru];
    if(rnk[paru] < rnk[parv]){
        par[paru] = parv;
        sz[parv] += sz[paru];
        return 1;
    }
    else if(rnk[paru] > rnk[parv])
    {
        par[parv] = paru;
        sz[paru] += sz[parv];
        return 1;
    }
    else{
        par[parv] = paru;
        rnk[paru]++;
        sz[paru] += sz[parv];
        return 1;
    }
}

pi a[MAX];
vi adj[MAX];
int in[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n , m;
    sc(n);sc(m);
    initi(n);
    for(int i = 1 ; i <= n ; ++i){
        int x;
        sc(x);
        a[i] = MP(x,i);
    }
    for(int i = 0 ; i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    sort(a + 1 , a + n + 1 , greater<pi>() );
    ll res = 0;
    for(int i = 1 ; i <= n ; ++i){
        int u = a[i].second;
        int cost = a[i].first;
        for(auto v : adj[u]){
            if(!in[v])
                continue;
            if(_merge(u , v)){
//                printf("mult == %d\n" , mult);
                res += mult*cost;
            }
        }
        in[u] = 1;
    }
    double ans = (double)res/((double)(n-1)*(double)n);
    cout<<setprecision(5)<<fixed<<ans*2.0;


return 0;
}
