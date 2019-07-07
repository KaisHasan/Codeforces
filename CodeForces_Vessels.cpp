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
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
int par[2*MAX];
ll sz[2*MAX] , cap[2*MAX];
void initi(int n){
    for(int i = 1 ; i <= n ; ++i)
        par[i] = i;
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}

void update(int u , ll x);

void _merge(int u , ll x){
    if(u == n){
        sz[u] = cap[u];
        return;
    }
    x -= (cap[u] - sz[u]);
    x = max(0ll , x);
    sz[u] = cap[u];
    int paru = parent(u + 1);
    par[u] = paru;
    update(paru , x);
}


int main(){

    sc(n);
    for(int i =1 ; i <= n ; ++i)
        sc(cap[i]);
    initi(n);
    int q;
    sc(q);
    while(q--){
        int c;
        sc(c);
        if(c == 1){
            int u , x;
            sc(u);sc(x);
            update(u , x);
        }
        else{
            int u;
            sc(u);
            printf("%d\n" , sz[u]);
        }
    }

return 0;
}

void update(int u , ll x){
    int paru = parent(u);
    if(x + sz[paru] > cap[paru])
        _merge(paru , x);
    else
        sz[paru] += x;
}
