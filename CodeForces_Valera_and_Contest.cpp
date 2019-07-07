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



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n , k , l , r , s_all , s_k;
    sc(n);sc(k);sc(l);sc(r);sc(s_all);sc(s_k);
    int in_k = s_k / k;
    int hold_k = s_k % k;
    int in_rem;
    int hold_rem;
    if(n != k){
        in_rem = (s_all - s_k) / (n - k);
        hold_rem = (s_all - s_k) % (n - k);
    }
    for(int i = 0 ; i < hold_k ; ++i)
        printf("%d " , in_k + 1);
    for(int i = hold_k ; i < k ; ++i)
        printf("%d " , in_k);
    if(n != k){
        for(int i = 0 ; i < hold_rem ; ++i)
            printf("%d " , in_rem + 1);
        for(int i = hold_rem ; i < n - k ; ++i)
            printf("%d " , in_rem);
    }


return 0;
}
