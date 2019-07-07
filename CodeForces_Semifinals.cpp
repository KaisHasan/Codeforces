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

int a[MAX] , b[MAX];
vector<pair<int , pi> > tot;


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;sc(n);
    int k = n / 2;
    for(int i = 0 ; i < n ; ++i){
        sc(a[i]);sc(b[i]);
        tot.pb(MP(a[i] , MP(1 , i)));
        tot.pb(MP(b[i] , MP(2 , i)));
    }
    sort(all(tot));
    string f = "";
    for(int i = 0 ; i < n ; ++i)
        f += "0";
    string s = "";
    for(int i = 0 ; i < n ; ++i)
        s += "0";
    for(int i = 0 ; i < k ; ++i)
        s[i] = '1' , f[i] = '1';
    for(int i = 0 ; i < n; ++i){
        int d = tot[i].second.first;
        int id = tot[i].second.second;
        if(d == 1)
            f[id] = '1';
        else
            s[id] = '1';
    }

    cout<<f<<endl<<s;



return 0;
}
