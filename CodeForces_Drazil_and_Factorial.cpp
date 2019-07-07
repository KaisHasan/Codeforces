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

vi a[10];
int cnt[10];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    a[2].pb(2);
    a[3].pb(3);
    for(int i = 0 ; i < 2 ; ++i)
        a[4].pb(2);
    a[4].pb(3);
    a[5].pb(5);
    a[6].pb(5);
    a[6].pb(3);
    a[7].pb(7);
    for(int i = 0; i < 3 ; ++i)
        a[8].pb(2);
    a[8].pb(7);
    a[9].pb(7);
    a[9].pb(3);
    a[9].pb(3);
    a[9].pb(2);

    int n;
    sc(n);
    string s;
    cin>>s;
    for(int i = 0 ; i < n ; ++i){
        int x = s[i] - '0';
        cnt[x]++;
    }
    vi res;
    for(int i = 2 ;i < 10 ; ++i){
        while(cnt[i]--){
            for(auto it : a[i])
                res.pb(it);
        }
    }
    sort(all(res) , greater<int>());
    for(auto it : res)
        printf("%d" , it);

return 0;
}
