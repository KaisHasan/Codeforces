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

map<char , int> cnts , cntt;
int yay , whoops;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    string s , t;
    cin>>s>>t;
    int ns = s.size();
    int nt = t.size();
    for(int i = 0 ; i < ns ; ++i){
        cnts[s[i]]++;
    }
    for(int i = 0 ; i < nt ; ++i)
        cntt[t[i]]++;

    for(char c = 'a' ; c <= 'z' ; ++c){
        int mn = min(cnts[c] , cntt[c]);
        cnts[c] -= mn;
        cntt[c] -= mn;
        yay += mn;
    }
    for(char c = 'A' ; c <= 'Z' ; ++c){
        int mn = min(cnts[c] , cntt[c]);
        cnts[c] -= mn;
        cntt[c] -= mn;
        yay += mn;
    }

    for(char c = 'a' ; c <= 'z' ; ++c){
        int mn = min(cnts[c] , cntt[toupper(c)]);
        cnts[c] -= mn;
        cntt[toupper(c)] -= mn;
        whoops += mn;
    }
    for(char c = 'A' ; c <= 'Z' ; ++c){
        int mn = min(cnts[c] , cntt[tolower(c)]);
        cnts[c] -= mn;
        cntt[tolower(c)] -= mn;
        whoops += mn;
    }

    printf("%d %d" , yay , whoops);


return 0;
}
