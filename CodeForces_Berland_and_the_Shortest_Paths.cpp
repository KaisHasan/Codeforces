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
vpi adj[2*MAX];
int lvl[2*MAX];
vi roads[2*MAX];

void BFS(){
    mem(lvl, -1);
    lvl[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it : adj[u]){
            int v = it.first;
            int r = it.second;
            if(lvl[v] == -1){
                roads[v].pb(r);
                lvl[v] = lvl[u] + 1;
                q.push(v);
            }
            else if(lvl[u] + 1 == lvl[v]){
                roads[v].pb(r);
            }
        }
    }
}

string ans;

void solve(int node){
    if(!k)
        exit(0);
    if(node == n + 1){
        printf("%s\n" , ans.c_str());
        --k;
        return;
    }
    for(auto i : roads[node]){
        ans[i] = '1';
        solve(node + 1);
        ans[i] = '0';
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);sc(k);
    for(int i = 0 ; i < m ; ++i){
        int u , v;
        sc(u);sc(v);
        adj[u].pb(MP(v,i));
        adj[v].pb(MP(u,i));
    }
    BFS();
    ans = "";
    for(int i =0 ; i < m ; ++i)
        ans += "0";
    int res = 1;
    for(int i = 2 ; i <= n ; ++i){
        res *= (int)roads[i].size();
        if(res > k)
            break;
    }
    res = min(res , k);
    printf("%d\n"  ,res);
    solve(2);

return 0;
}
