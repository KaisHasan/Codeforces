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

int n;
int a[3*MAX];
ll sum[2] , num[2];
//0 is right
//1 is left


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ;++i)
        sc(a[i]);
    sort(a , a + n);
    int l = 1 , r = n - 2;
    int k = n - 2;
    sum[1] = a[0];
    sum[0] = a[n-1];
    num[0] = num[1] = 1;
    int flg = 0;
    ll res = sum[0] - sum[1];
    printf("%I64d" , res);
    while(k--){
        flg ^= 1;
        ll x;
        if(flg)
            x = a[l++];
        else
            x = a[r--];
        res += (num[1]*x)-(sum[1]);
        res += (sum[0])-(num[0]*x);
        sum[flg] += x;
        num[flg]++;
        printf(" %I64d" ,res);
    }


return 0;
}
