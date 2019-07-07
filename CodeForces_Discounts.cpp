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

int n ,m;
ll a[3*MAX];



int main(){

    sc(n);
    for(int i = 0 ; i < n ; ++i)
        scanf("%I64d" , &a[i]);
    ll sum = 0;
    for(int i = 0 ; i < n; ++i)
        sum += a[i];
    sort(a , a + n , greater<int>());
    sc(m);
    while(m--){
        int x;
        sc(x);
        printf("%I64d\n" , sum - a[x-1]);
    }


return 0;
}
