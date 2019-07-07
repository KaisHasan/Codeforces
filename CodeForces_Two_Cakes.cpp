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
vi loc[2*MAX];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < 2*n ; ++i){
        int x;
        sc(x);
        loc[x].pb(i+1);
    }

    ll res1 = 0;
    int cur = 1;
    for(int i = 1 ; i <= n ; ++i){
        if(loc[i][0] < loc[i][1]){
            res1 += abs(cur - loc[i][0]);
            cur = loc[i][0];
            loc[i][0] = inf;
        }
        else{
            res1 += abs(cur - loc[i][1]);
            cur = loc[i][1];
            loc[i][1] = inf;
        }
    }

    ll res2 = 0;
    cur = 1;
    for(int i = 1 ; i <= n ; ++i){
        if(loc[i][0] < loc[i][1]){
            res2 += abs(cur - loc[i][0]);
            cur = loc[i][0];
            loc[i][0] = inf;
        }
        else{
            res2 += abs(cur - loc[i][1]);
            cur = loc[i][1];
            loc[i][1] = inf;
        }
    }
    cout<<res1+res2;


return 0;
}
