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

int n , k;
int a[2*MAX];
int cnt[2*MAX];

int check(int t){
    int c = 0;
    for(int i = 1 ; i < 2 * MAX ; ++i){
        c += (cnt[i] / t);
    }
    return c >= k;
}



int main(){

    sc(n);sc(k);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    for(int i = 0 ; i < n ; ++i)
        cnt[a[i]]++;
    int st = 1 , en = 2 * MAX;
    int res = -1;
    while(st <= en){
        int md = (st+en)>>1;
        if(check(md)){
            st = md + 1;
            res = md;
        }
        else
            en = md - 1;
    }
    int t = res;
    for(int i = 1 ; i < 2 * MAX && k ; ++i){
        while(cnt[i] >= res  && k){
            cnt[i] -= res;
            --k;
            printf("%d " , i);
        }
    }

return 0;
}
