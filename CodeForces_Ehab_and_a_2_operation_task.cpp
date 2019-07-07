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
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n;
int a[MAX];
vector<pi> v;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    int M = n;
    int add = 0;
    int steps = n+1;
    for(int i = n - 1 ; i >= 0 ; --i){
        a[i] += add;
        if(a[i] % M != i){
            if(a[i] % M > i){
                add += M - i;
                v.pb(make_pair(i+1 , M-(a[i]%M)+i));
            }
            else{
                add += i - (a[i]%M);
                v.pb(make_pair(i+1 , i - (a[i]%M)));
            }
        }
        else{
            --steps;
        }
    }
    cout<<steps<<endl;
    for(int i = 0 ; i < v.size() ; ++i){
        cout<<"1 "<<v[i].first<<' '<<v[i].second<<endl;
    }
    cout<<"2 "<<n<<' '<<M;


return 0;
}
