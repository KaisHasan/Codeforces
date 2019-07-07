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

vi adj[2*MAX];
vi res;
int c[2*MAX] , vis[2*MAX] , cnt[2];
void dfs(int u , int flg){
    vis[u] = 1;
    c[u] = flg;
    cnt[flg]++;
    for(auto v : adj[u]){
        if(!vis[v]){
            dfs(v , 1 - flg);
        }
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        int n, m;
        sc(n);sc(m);
        for(int i = 0; i <= n ; ++i)
            adj[i].clear();
        cnt[0] = cnt[1] = 0;
        for(int i = 1 ; i <= n ; ++i){
            vis[i] = 0;
            c[i] = 0;
        }
        for(int i = 0 ; i < m;  ++i){
            int u , v;
            sc(u);sc(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }

        res.clear();
        dfs(1 , 1);
        int k = 1;
        if(cnt[0] < cnt[1])
            k = 0;
        printf("%d\n" , cnt[k]);
        for(int i = 1 ; i <= n ; ++i){
            if(c[i] == k){
                printf("%d " , i);
            }
        }
        blank;
    }



return 0;
}
