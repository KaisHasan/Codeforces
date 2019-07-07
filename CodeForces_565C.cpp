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

vi loc[44];
int a[] = {4 , 8 , 15 , 16 , 23 , 42};
int id[44];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    for(int i = 0 ; i < n ; ++i){
        int x;
        sc(x);
        loc[x].pb(i);
    }
    int res = 0;
    while(1){
        int cnt = 0;
        int mn = -1;
        for(int i = 0 ; i < 6 ; ++i){
            for(int j = id[a[i]] ; j < (int)loc[a[i]].size() ; ++j){
                ++id[a[i]];
                if(loc[a[i]][j] > mn){
                    mn = loc[a[i]][j];
                    ++cnt;
                    break;
                }
            }
        }
        if(cnt == 6){
            ++res;
        }
        else
            break;
    }

    int ans = n - res*6;
    cout<<ans;




return 0;
}
