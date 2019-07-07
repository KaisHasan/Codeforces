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

int f_bit(int n){
    int res = 0;
    while(n % 2 == 0)
        n /= 2 , res++;
    return (1 << res);
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int sum , lim;
    sc(sum);sc(lim);
    vi res;
    for(int i = lim ; i > 0 ; --i){
        int k = f_bit(i);
        if(sum - k >= 0){
            sum -= k;
            res.pb(i);
        }
        if(sum == 0)
            break;
    }
    if(sum != 0){
        printf("-1");
        return 0;
    }
    printf("%d\n" , res.size());
    printf("%d" , res[0]);
    for(int i = 1 ; i < res.size() ; ++i)
        printf(" %d", res[i]);



return 0;
}
