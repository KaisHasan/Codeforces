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

int n , m;
bool grid[105][1005];
int cnt[105];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(m);
    for(int i = 1 ; i <= m ; ++i){
        int u , v;
        sc(u);sc(v);
        ++cnt[u];
        ++cnt[v];
        grid[u][i] = 1;
        grid[v][i] = 1;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!cnt[i]){
            printf("1\n");
            ++m;
            printf("%d %d\n" , i , m);
            continue;
        }
        printf("%d\n" , cnt[i]);
        for(int j = 1 ; j < 1004 ; ++j){
            if(grid[i][j])
                printf("%d %d\n" , i , j);
        }
    }





return 0;
}
