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

string s;
int a[3];
void out(){
    for(int i = 0 ; i < a[0] ; ++i)
        printf("|");
    printf("+");
    for(int i = 0 ; i < a[1] ; ++i)
        printf("|");
    printf("=");
    for(int i = 0 ; i < a[2]; ++i)
        printf("|");
}
int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    cin>>s;
    int cnt = 0;
    int n = s.size();
    int side = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == '+')
            side = 1;
        if(s[i] == '=')
            side = 2;
        if(s[i] == '|')
        {
            a[side]++;
        }
    }

    if(a[0] + a[1] == a[2]){
        out();
        return 0;
    }
    a[0]++;
    a[2]--;
    if(a[0] != 0 && a[2] != 0 && a[0] + a[1] == a[2]){
        out();
        return 0;
    }
    a[0] -= 2;
    a[2] += 2;
    if(a[0] != 0 && a[2] != 0 && a[0] + a[1] == a[2])
    {
        out();
        return 0;
    }
    a[0]++;
    a[2]--;
    a[1]++;
    a[2]--;
    if(a[1] != 0 && a[2] != 0 && a[0] + a[1] == a[2]){
        out();
        return 0;
    }
    a[1] -= 2;
    a[2] += 2;
    if(a[1] != 0 && a[2] != 0 && a[0] + a[1] == a[2])
    {
        out();
        return 0;
    }
    printf("Impossible");



return 0;
}
