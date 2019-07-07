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

vi adj[2*MAX];
int par[2*MAX];
int bot[2*MAX];


void initi(int n){
    for(int i = 1 ; i <= n ; ++i){
        par[i] = i;
        bot[i] = i;
    }
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}

int BOT(int v){
    if(bot[v] == v)
        return v;
    return bot[v] = BOT(bot[v]);
}

void _merge(int u , int v){
    int paru = parent(u) , parv = parent(v);
    int botu = BOT(u) , botv = BOT(v);
    if(paru == parv || botu == botv)
        return;
    par[paru] = botv;
    bot[botv] = botu;
    adj[paru].pb(botv);
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int n;
    sc(n);
    int m = n - 1;
    initi(n);
    while(m--){
        int u , v;
        sc(u);sc(v);
        _merge(u , v);
    }
    int cur = BOT(1);
    while(1){
        if((int)adj[cur].size() == 0){
            printf("%d " , cur);
            break;
        }
        printf("%d " , cur);
        cur = adj[cur][0];
    }




return 0;
}
