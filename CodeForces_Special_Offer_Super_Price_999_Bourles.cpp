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
#define scl(a) scanf("%I64d",&a)
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

ll power(ll x ,ll y){
    if(!y)
        return 1;
    ll res = power(x , y / 2);
    res *= res;
    if(y&1)
        res *= x;
    return res;
}
string s;
void update(int id){
    s[id] = '9';
    id--;
    while(s[id] == '0'){
        s[id] = '9';
        --id;
    }
    s[id]--;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);



    ll n , d;
    scl(n);scl(d);
    int dig = (floor(log10((double)n)) + 1);
    s = to_string(n);
    int sz = s.size();
    int pos = 0;
    for(int i = sz -1 ; i >= 0 ; --i , ++pos){
        ll x = s[i] - '0';
        if(x == 9)
            continue;
        x++;
        x *= power(10 , pos);
        d -= x;
        if(d < 0)
            break;
        update(i);
    }
    int id = 0;
    while(s[id] == '0')
        ++id;
    printf("%s" , s.substr(id).c_str());
return 0;
}
