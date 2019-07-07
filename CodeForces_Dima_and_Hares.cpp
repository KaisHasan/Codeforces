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
const int MAX = 3055;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int a[3][MAX];
int n;

int dp[MAX][2];
int solve(int id , int flg){
    if(id == n - 1){
        return a[flg][id];
    }
    int &res = dp[id][flg];
    if(res != -1)
        return res;
    res = max(solve(id + 1 , 1) + a[flg][id] , solve(id + 1 , 0) + a[flg+1][id]);
    return res;
}


int main(){

    sc(n);
    for(int i = 0 ; i < 3 ; ++i){
        for(int j = 0 ; j < n ; ++j){
            sc(a[i][j]);
        }
    }
    mem(dp,-1);
    int res = solve(0 , 0);
    printf("%d" , res);


return 0;
}
