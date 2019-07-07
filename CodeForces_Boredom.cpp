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

ll pre[MAX] , aft[MAX];
ll cnt[MAX];
int a[MAX];
int n;
ll dp[MAX][3];

ll solve(int id , int flg){
    if(id == n)
        return 0;
    ll &res = dp[id][flg];
    if(res != -1)
        return res;
    res = 0;
    res = max(res , solve(aft[a[id]] , 1) + (cnt[a[id]] * a[id]));
    if(flg)
        res = max(res , solve(id + cnt[a[id]] , 0));

    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    sc(n);
    for(int i = 0 ; i < n ; ++i){
        sc(a[i]);
        cnt[a[i]]++;
    }
    sort(a , a + n);

    for(int i = 0 ; i < n ;++i){
        int x = a[i];
        int low = lower_bound(a , a + n , x - 1) - a;
        int up = upper_bound(a , a + n , x + 1) - a;
        if(a[low] == x || a[low] == x - 1)
            --low;
        if(a[up] == x)
            ++up;
        pre[x] = low;
        aft[x] = up;
    }
//    for(int i = 0 ; i < n ; ++i){
//        int x = a[i];
//        printf("a[%d] == %d\n" , i , x);
//        printf("pre == %I64d ,  aft == %I64d  , cnt == %I64d\n" , pre[x] , aft[x] , cnt[x]);
//    }
//        for(int i = 0 ; i < n; ++i)
//        printf("cnt[%d] == %d\n" , a[i] , cnt[a[i]]);
    mem(dp , -1);
    printf("%I64d" , solve(0 , 2));


return 0;
}
