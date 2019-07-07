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

string s1 , s2;
int m;
int sum;
int dp[11][11][11];
int solve(int id , int pos , int neg){
    if(id == m){
        if(pos - neg == sum){
            return 1;
        }
        return 0;
    }
    int &res = dp[id][pos][neg];
    if(res != -1)
        return res;
    res = solve(id + 1 , pos + 1, neg) + solve(id + 1 , pos, neg + 1);
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    cin>>s1>>s2;
    int n = s1.size();
    mem(dp , -1);
    int sum1 = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s1[i] == '+')
            sum1++;
        else
            sum1--;
    }
    int sum2 = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s2[i] == '+')
            ++sum2;
        if(s2[i] == '-')
            --sum2;
        if(s2[i] == '?')
            ++m;
    }
    sum = sum1 - sum2;
    if(m != 0){
        int d = 1<<m;
        int res = solve(0 , 0 , 0);
        cout<<setprecision(9)<<fixed<<double(res)/double(d);
    }
    else{
        cout<<setprecision(9)<<fixed<<double(sum == 0);
    }



return 0;
}
