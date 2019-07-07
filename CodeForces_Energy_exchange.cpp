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
const double eps = 1e-9;

int n , k;
double a[MAX];

bool check(double x){
    double over = 0;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] - x > eps){
            over += a[i] - x;
        }
    }
    for(int i = 0 ; i < n ; ++i){
        if(x - a[i] > eps){
            double to_take = (x - a[i]);
            over -= to_take * (100.0)/(100.0 - k);
        }
    }

    if(over < eps && fabs(over) > eps)
        return 0;
    return 1;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    sc(k);
    for(int i = 0 ; i < n ; ++i)
        cin>>a[i];
    double st = 0 , en = 1500;
    double res = 0;
    while(en - st > eps){
        double md = (st+en)/2;
        if(check(md)){
            st = md;
            res = md;
        }
        else{
            en = md;
        }
    }

    cout<<setprecision(9)<<fixed<<res<<endl;



return 0;
}
