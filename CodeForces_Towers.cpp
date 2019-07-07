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

int n , k;
int a[MAX];
vpi res;


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    sc(n);sc(k);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    int _mn = inf, _mx = -1;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] > _mx)
            _mx = a[i];
        if(a[i] < _mn)
            _mn = a[i];
    }
    int dif = _mx - _mn;
    int lst = 0;
    for(int i = 0 ; i < k ; ++i){
        int mn = inf , mx = -1;
        int mnId = -1 , mxId= -1;
        for(int i = 0 ; i < n ; ++i){
            if(a[i] > mx){
                mx = a[i];
                mxId = i;
            }
            if(a[i] < mn){
                mn = a[i];
                mnId = i;
            }
        }
        if(mnId == mxId)
            break;
        res.pb(MP(mxId +1, mnId+1));
        a[mnId]++;
        a[mxId]--;
        mx = -1 , mn = inf;
        for(int i = 0 ; i < n ; ++i){
            if(a[i] > mx)
                mx = a[i];
            if(a[i] < mn)
                mn = a[i];
        }
        if(mx - mn < dif){
            lst = i + 1;
            dif = mx - mn;
        }
    }
    printf("%d %d\n" , dif , lst);
    for(int i = 0 ; i < lst ; ++i)
        printf("%d %d\n" , res[i].first , res[i].second);


return 0;
}
