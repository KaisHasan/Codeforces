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

int a1[MAX] , a2[MAX] , a3[MAX];
int n;


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(a1[i]);
    for(int i = 0 ; i < n - 1; ++i)
        sc(a2[i]);
    for(int i = 0 ; i < n - 2; ++i)
        sc(a3[i]);
    ll sum1 = 0 , sum2 = 0 , sum3 = 0;
    for(int i = 0 ; i < n ; ++i)
        sum1 += a1[i];
    for(int i = 0 ; i < n - 1; i++)
        sum2 += a2[i];
    for(int i = 0 ; i < n - 2 ;++i)
        sum3 += a3[i];
    printf("%I64d\n%I64d" , sum1 - sum2 , sum2 - sum3);

return 0;
}
