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

pi a[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        int x , y;
        sc(x);sc(y);
        a[i] = MP(x,y);
    }
    pi lst = MP(0,0);
    ll res = 1;
    for(int i = 0 ; i < n ; ++i){
        int mx = max(lst.first , lst.second);
        int mn = min(a[i].first , a[i].second);
        if(mn >= mx){
            res += (mn - mx + (lst.first != lst.second));
        }
        lst = a[i];
    }

    cout<<res;



return 0;
}
