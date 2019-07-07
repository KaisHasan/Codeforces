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

/*
    0   1   2   3
    n   g   c   GC
*/
int a[101];
int n;
int dp[101][3];
int solve(int id , int lst){
    if(id == n)
        return 0;
    int &res = dp[id][lst];
    if(res != -1)
        return res;
    res = inf;
    bool contest = (lst != 2 && a[id] >= 2);
    bool gym = (lst != 1 && (a[id] == 1 || a[id] == 3));
    res = min(res , solve(id + 1 , 0) + 1);
    if(contest)
        res = min(res , solve(id + 1 , 2));
    if(gym)
        res = min(res , solve(id + 1 , 1));
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    mem(dp , -1);
    cout<<solve(0 , 0);




return 0;
}
