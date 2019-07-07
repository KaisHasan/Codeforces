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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const ll inf = 1e12+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n , k;
ll a[2*MAX];
int check(ll d){
    ll tot = 0;
    bool t = true;
    ll sub = 0;
    ll lst = 0;
    ll i = 0;
    while(t){
        for(; i < min(lst + d,(ll)n) ; ++i){
            if(a[i] - sub <= 0){
                t = false;
                break;
            }
            tot += (a[i] - sub);
        }
        if(i == (ll)n)
            t = false;
        lst = i;
        ++sub;
    }
    return tot >= k;
}




int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    sc(n);sc(k);
    for(int i =0 ; i < n ; ++i)
        scl(a[i]);
    sort(a , a + n , greater<ll>());
    ll st = 1 , en = inf;
    ll res = -1;
    while(st <= en){
        ll md = (st+en)>>1;
        if(check(md)){
            en = md - 1;
            res = md;
        }
        else{
            st = md + 1;
        }
    }
    printf("%I64d" , res);

return 0;
}
