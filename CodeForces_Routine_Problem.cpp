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

pi res1 , res2;


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int a, b;
    pi c , d;
    sc(a);sc(b);
    sc(c.first);sc(d.first);
    c.second = d.second = 1;
    int g = __gcd(c.first , d.first);
    c.first /= g;
    d.first /= g;
    pi cc = c , dd = d;
    dd.second = cc.first;
    cc.first = 1;
    g = __gcd(dd.first , dd.second);
    dd.first /= g;
    dd.second /= g;
    cc.first = a;
    dd.first *= a;
    if((double)dd.first / dd.second - b > eps)
        res1 = MP(inf , 1);
    else{
        res1.first = (b * dd.second) - dd.first;
        res1.second = dd.second;
        res1.second *= b;
        g = __gcd(res1.first , res1.second);
        res1.first /= g;
        res1.second /= g;
    }

    ////////////////
    c.second = d.first;
    d.first = 1;
    g = __gcd(c.first , c.second);
    c.first /= g;
    c.second /= g;
    d.first = b;
    c.first *= b;
    if((double)c.first / c.second - a > eps)
        res2 = MP(inf , 1);
    else{
        res2.first = (a * c.second) - c.first;
        res2.second = c.second;
        res2.second *= a;
        g = __gcd(res2.first , res2.second);
        res2.first /= g;
        res2.second /= g;
    }

    if((double)res1.first / res1.second - (double)res2.first / res2.second > eps)
        printf("%d/%d" , res2.first , res2.second);
    else
        printf("%d/%d" , res1.first , res1.second);


return 0;
}
