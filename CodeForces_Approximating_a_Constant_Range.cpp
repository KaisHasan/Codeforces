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

int n;
int a[MAX];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);

    int id = -1;
    int res = -1;
    int len = 0;
    int i = 0;
    while(i < n){
        i = id + 1;
        len = 0;
        int mn = inf;
        int mx = -inf;
        int mnid = -1;
        int mxid = -1;
        while(i < n){
            if(abs(mx - a[i]) > 1 || abs(a[i] - mn) > 1){
                if(mnid != -1)
                    break;
            }
            if(mn >= a[i]){
                mn = a[i];
                mnid = i;
            }
            if(mx <= a[i]){
                mx = a[i];
                mxid = i;
            }
            ++len;
            res = max(res , len);
            ++i;
        }
        if(i == n)
            break;
        id = min(mnid , mxid);
    }

    cout<<res;

return 0;
}
