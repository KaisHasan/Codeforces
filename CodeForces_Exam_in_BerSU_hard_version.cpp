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

int n , T;
int a[2*MAX] , cnt[101];



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(T);
    for(int  i = 0 ; i < n ; ++i){
        sc(a[i]);
    }
    printf("0");
    cnt[a[0]]++;
    for(int i = 1 ; i < n ; ++i){
        int rem = T - a[i];
        int tot = i;
        int res = 0;
        for(int j = 1 ; j <= min(100,rem) ; ++j){
            if(!cnt[j])
                continue;
            int mn = min(cnt[j] , rem / j);
            res += mn;
            rem -= mn*j;
        }
        res = tot - res;
        printf(" %d" , res);
        cnt[a[i]]++;
    }



return 0;
}
