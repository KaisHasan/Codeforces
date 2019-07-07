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

int M[33][33];
int childNum[33];
vpi edges;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    while(t--){
        mem(M , 0);
        mem(childNum , 0);
        edges.clear();
        int n , p;
        sc(n);sc(p);
        int cnt = 0;
        for(int i = 0 ; i < n - 1 && cnt < 2 * n + p ; ++i){
            for(int u = 1 ; u <= n && cnt < 2 * n + p; ++u){
                if(childNum[u] > i)
                    continue;
                int v = -1;
                int mn = inf;
                for(int j = 1 ; j <= n ; ++j){
                    if(j == u)
                        continue;
                    if(childNum[j] < mn && !M[u][j]){
                        mn = childNum[j];
                        v = j;
                    }
                }
                if(v == -1)
                    continue;
                M[u][v] = 1;
                M[v][u] = 1;
                ++childNum[u];
                ++childNum[v];
                edges.pb(MP(u,v));
                ++cnt;
            }
        }
        for(auto e : edges)
            printf("%d %d\n" , e.first , e.second);
    }



return 0;
}
