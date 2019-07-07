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

int Int(char c){
    return (c - '0');
}

string s;
int n;
int md[] = {0 , 10 , 100};

int dp[101][8][9];
string ans;
int solve(int id , int mod , string result){
    if(mod == 0){
        ans = result;
        return 1;
    }
    if(id == n)
        return 0;
    int &res = dp[id][mod];
    if(res != -1)
        return res;
    res = 0;
    res |= solve(id + 1 , (mod * 10 + k) % 8 , result + s[id]);
    res |= solve(id + 1 , mod , result);
    return res;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    cin>>s;
    n = s.size();
    solve(0 , 0)


return 0;
}
