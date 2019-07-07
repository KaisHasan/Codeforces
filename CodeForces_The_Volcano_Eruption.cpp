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


int rnk[MAX];
int par[MAX];
pi num[MAX];

void initi(int n){
    for(int i = 0 ; i < n ; ++i){
        par[i] = i;
        rnk[i] = 1;
        num[i].first = num[i].second = 0;
    }
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}

bool _merge(int u , int v){
    int paru = parent(u) , parv = parent(v);
    if(paru == parv)
        return 0;
    if(rnk[paru] < rnk[parv]){
        par[paru] = parv;
        num[parv].first += num[paru].first;
        num[parv].second += num[paru].second;
        return 1;
    }
    else if(rnk[paru] > rnk[parv])
    {
        par[parv] = paru;
        num[paru].first += num[parv].first;
        num[paru].second += num[parv].second;
        return 1;
    }
    else{
        par[parv] = paru;
        num[paru].first += num[parv].first;
        num[paru].second += num[parv].second;
        rnk[paru]++;
        return 1;
    }
}

vector<pair<pi , int> > edges;
bool areIntersect(pair<pi,int> a , pair<pi ,int> b){
    ll res1 = (ll)(a.first.first - b.first.first)*(ll)(a.first.first - b.first.first) + (ll)(a.first.second-b.first.second)*(ll)(a.first.second-b.first.second);
    ll r1 = a.second;
    ll r2 = b.second;
    ll res2 = (r1+r2)*(r1+r2);
    return res1 <= res2;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);

    while(t--){
        edges.clear();
        int n;
        sc(n);
        int w , l;
        sc(w);sc(l);
        initi(n);
        for(int i = 0 ; i < n ; ++i){
            int x , y , r;
            sc(x);sc(y);sc(r);
            edges.pb(MP(MP(x,y), r));
            num[i].first = (x - r)<=0;
            num[i].second = (x+r)>= w;
        }

        for(int i = 0 ; i < n ; ++i){
            for(int j = i + 1 ; j < n ; ++j){
                if(areIntersect(edges[i], edges[j])){
                    int nothing = _merge(i , j);
                }
            }
        }
        int res = 0;
        for(int i = 0 ; i < n ; ++i){
            if(par[i] == i){
                res += (num[i].first > 0 && num[i].second > 0);
            }
        }
        printf("%d\n" , res);
    }




return 0;
}
