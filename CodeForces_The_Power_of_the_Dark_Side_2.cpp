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
#define scl(a) scanf("%I64d",&a)
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
ll  s[3];
ll a[5*MAX] , p[5*MAX];

int bin(ll x){
    int st = 0 , en = n - 1;
    int res = -1;
    while(st <= en){
        int md = (st+en)>>1;
        if(x >= a[md] + 2ll){
            st = md + 1;
            res = md;
        }
        else{
            en = md - 1;
        }
    }
    return res + 1;
}

int sub[5*MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i){
        scl(s[0]);scl(s[1]);scl(s[2]);
        p[i] = s[0] + s[1] + s[2];
        sort(s , s + 3);
        a[i] = s[0] + s[1];
        sub[i] = p[i] >= a[i] + 2;
    }

    sort(a , a + n);
    for(int i = 0 ; i < n ; ++i){
        ll x = p[i];
        int res = bin(x) - sub[i];
        printf("%d " , res);
    }


return 0;
}
