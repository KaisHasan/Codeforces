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
const int MAX = 1e3+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int a[4*MAX];
int dp[4*MAX][2];
int n;

int solve(int id , int flg , int lst){
    if(id == n)
        return 0;
    int &res = dp[id][flg];
    if(res != -1)
        return res;
    res = 1;
    int m = ((flg == 0)? 1 : -1);
    int hop = m * (abs(a[id]-a[lst]));
    res = max(res , solve(id + 1 , flg , lst));
    for(int i = id + 1; i < n ; ++i){
        if(a[id] ==  a[i] + hop || (!lst))
            res = max(res , solve(i , 1 , id) + 1);
    }
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    mem(dp,-1);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    int res = solve(0 , 0 , 0);
    printf("%d\n" , res);


return 0;
}
