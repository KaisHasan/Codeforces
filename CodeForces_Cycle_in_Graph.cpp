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

int n , m , k;
vi cycle;
int loop = -1;
int f = 0;
int dis[MAX];
vi adj[MAX];

void dfs(int u , int depth){
    dis[u] = depth;
    if(f)
        return;
    for(auto v : adj[u]){
        if(f || loop != -1)
            break;
        if(!dis[v])
            dfs(v , depth + 1);
        else if(abs(dis[v] - dis[u]) >= k && loop == -1){
            loop = v;
            break;
        }
    }
    if(loop != -1 && !f){
        cycle.pb(u);
        if(u == loop)
            f = true;
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);sc(k);
    mem(dis , 0);
    for(int i = 0 ; i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    for(int i = 1 ; i <= n ; ++i){
        if(loop == -1 && dis[i] == 0){
            dfs(i , 1);
        }
        else if(loop != -1)
            break;
    }
    int res = cycle.size();
    printf("%d\n" , res);
    for(auto i : cycle)
        printf("%d " , i);


return 0;
}
