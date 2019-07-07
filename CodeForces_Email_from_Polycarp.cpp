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


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n ;sc(n);
    while(n--){
        string s , t;
        cin>>s>>t;
        int n1 = s.size();
        int n2 = t.size();
        int i = 0 , j = 0;
        bool test = true;
        while(i < n1 && j < n2){
            if(s[i] != t[j]){
                test = false;
                break;
            }
            bool c = true;
            if(i < n1 - 1){
                if(s[i] == s[i+1])
                    c = false;
            }
            ++i;
            char k = t[j];
            ++j;
            while(c && t[j] == k){
                ++j;
            }
        }
        if(i < n1 || j < n2)
            test = false;
        if(test)
            printf("YES");
        else
            printf("NO");
        blank;
    }



return 0;
}
