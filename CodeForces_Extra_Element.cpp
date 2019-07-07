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

int n;
pi a[2*MAX];



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n; ++i){
        int x;sc(x);
        a[i] = MP(x, i);
    }
    int ans = -1;
    sort(a , a + n);
    int st = 0;
        int sec = 1;
        ll c = a[sec].first - a[st].first;
        ll cnt = 0;
        int del = -1;
        for(int i = 2 ; i < n ; ++i){
            if((ll)a[i].first != (ll)a[0].first + c * (ll)(i-cnt)){
                ++cnt;
                del = a[i].second + 1;
            }
            if(cnt > 1)
                break;
        }
        if(cnt <= 1){
            ans = del;
            for(int i = 1 ; i <= n && del == -1 ; ++i){
                if(i != a[st].second && i != a[sec].second){
                    ans = i;
                    break;
                }
            }
        }

        sec = 2;
        c = a[sec].first - a[st].first;
        cnt = 1;
        for(int i = 3 ; i < n ; ++i){
            if((ll)a[i].first != (ll)a[st].first + c * (ll)(i-cnt))
                ++cnt;
            if(cnt > 1)
                break;
        }
        if(cnt <= 1){
            ans = a[1].second + 1;
        }
    st = 1;
        sec = 2;
        c = a[sec].first - a[st].first;
        cnt = 1;
        for(int i = 3 ; i < n ; ++i){
            if((ll)a[i].first != (ll)a[st].first + c * (ll)(i-cnt))
                ++cnt;
            if(cnt > 1)
                break;
        }
        if(cnt <= 1){
            ans = a[0].second + 1;
        }

    printf("%d" , ans);


return 0;
}
