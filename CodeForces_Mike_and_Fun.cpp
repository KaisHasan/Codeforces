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

int grid[544][544];
int n , m , q;

int solve(){
    int res = 0;
    for(int i = 0 ; i < n ; ++i){
        int sum = 0;
        for(int j = 0 ; j < m ; ++j){
            if(!grid[i][j])
                sum = 0;
            else
                ++sum;
            res = max(res , sum);
        }
    }
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    sc(m);
    sc(q);
    for(int i = 0 ; i < n ; ++i)
        for(int j = 0 ; j < m ; ++j)
            sc(grid[i][j]);

    while(q--){
        int x , y;
        sc(x);sc(y);
        --x;--y;
        grid[x][y] = 1 - grid[x][y];
        int res = solve();
        printf("%d\n" , res);
    }



return 0;
}
