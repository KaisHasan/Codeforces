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
const int MAX = 1e6+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

set<int> vertices;
map<pi,bool> forbidden;
int n , m , k;

void dfs(int v){
    vi temp;
    for(auto i : vertices)
        if(!forbidden[MP(min(i,v) , max(i,v))])
            temp.pb(i);
    for(auto i : temp)
        vertices.erase(i);
    for(auto i : temp)
        dfs(i);
}

int main(){

    sc(n);sc(m);sc(k);
    for(int i = 2 ; i <= n ; ++i)
        vertices.insert(i);

    int mx = n - 1;
    while(m--){
        int u , v;
        sc(u);sc(v);
        if(min(u,v) == 1)
            --mx;
        forbidden[MP(min(u,v) , max(u,v))] = 1;
    }
    if(mx < k){
        printf("impossible");
        return 0;
    }
    int cmps = 0;
    for(int i = 2 ; i <= n ; ++i){
        if(!forbidden[MP(1,i)] && vertices.find(i) != vertices.end()){
            dfs(i);
            ++cmps;
        }
    }

    if(cmps > k || !vertices.empty())
        printf("impossible");
    else
        printf("possible");


return 0;
}
