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

map<pi , int> cnt;
int a[2*MAX] , b[2*MAX];



int main(){



    int n;
    sc(n);
    for(int i = 0 ; i< n ; ++i){
        sc(a[i]);
    }
    for(int i = 0 ; i< n ; ++i){
        sc(b[i]);
    }
    int add = 0;
    for(int i = 0 ; i <n ; ++i){
        int x = -b[i];
        int y = a[i];
        if(y == 0){
            if(x == 0)
                add++;
            continue;
        }
        if(x == 0){
            cnt[MP(0,1)]++;
            continue;
        }
        if((ll)x * (ll)y > 0){
            x = abs(x);
            y = abs(y);
        }
        else{
            x = -abs(x);
            y = abs(y);
        }
        int g = __gcd(abs(x) ,abs(y));
        x /= g;
        y /= g;
        cnt[MP(x,y)]++;
    }

    int mx = 0;
    for(auto it : cnt)
        mx = max(mx , it.second);

    printf("%d" , mx + add);


return 0;
}
