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

int cur[3*MAX];
int a[3*MAX];
int n , q;


int main(){

    sc(n);
    sc(q);
    ll res = 0;
    while(q--){
        int typ;
        sc(typ);
        if(typ == 1){
            int x;
            sc(x);
            ++a[x];
            res++;
        }
        else if(typ == 2){
            int x;
            sc(x);
            res -= (a[x] - cur[x]);
            cur[x] = a[x];
        }
        else{
            int
        }
    }

return 0;
}
