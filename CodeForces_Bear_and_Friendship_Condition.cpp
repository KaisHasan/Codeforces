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
//vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

vector<int> adj[2 * MAX];
int vis[2 * MAX];

ll nodes , edges;
void dfs(int v){
    vis[v] = 1;
    ++nodes;
    for(auto node : adj[v]){
        ++edges;
        if(!vis[node])
            dfs(node);
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n , m;
    sc(n);sc(m);
    for(int i = 0 ; i < m ; ++i){
        int x , y;
        sc(x);sc(y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int test = true;
    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            nodes = 0;
            edges = 0;
            dfs(i);
            if((nodes * (nodes - 1))  != edges){
                test = false;
                break;
            }
        }
    }
    if(test)
        printf("YES");
    else
        printf("NO");



return 0;
}
