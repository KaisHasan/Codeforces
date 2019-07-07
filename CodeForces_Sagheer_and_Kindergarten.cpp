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

int n, m , k , q;
int lst[MAX] , tin[MAX] , tout[MAX] , num[MAX] , inD[MAX];
vi adj[MAX];
int tot = 1;

void dfs(int u){
    tin[u] = tot++;
    num[u] = 1;
    for(auto v : adj[u]){
        dfs(v);
        num[u] += num[v];
    }
    tout[u] = tot++;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);sc(k);sc(q);
    mem(lst,-1);
    for(int i = 0 ; i < k ; ++i){
        int u , v;
        sc(u);sc(v);
        if(lst[v] != -1){
            adj[lst[v]].pb(u);
            inD[u]++;
        }
        lst[v] = u;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!inD[i]){
            dfs(i);
        }
    }
    while(q--){
        int x , y;
        sc(x);sc(y);
        if(lst[y] == -1){
            printf("0");
        }
        else{
            int z = lst[y];
            if(tin[x] <= tin[z] && tout[z] <= tout[x]){
                printf("%d" , num[x]);
            }
            else
                printf("0");
        }
        blank;
    }


return 0;
}
