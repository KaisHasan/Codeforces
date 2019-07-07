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

int n;
string s;
map<char , int > code;
int top[3];
int solve(){
    top[1] = 1;
    top[2] = 2;
    for(int i = 0 ; i < n ; ++i){
        char c = s[i];
        int x = code[c];
        if(x == 1){
            if(top[1] != 1)
                return 0;
            top[1] = 1;
        }
        else if(x == 2){
            if(top[2] == 2){
                top[2] = 2;
            }
            else{
                top[1] = 2;
            }
        }
        else{
            top[2] = 3;
        }
    }
    return 1;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    cin>>s;
    n = s.size();
    int a[3] = {0,0,0};
    for(int i = 0 ; i < n ; ++i){
        a[0] += s[i]=='R';
        a[1] += s[i] == 'G';
        a[2] += s[i] == 'B';
    }
    int cnt = (a[0] > 0) + (a[1] > 0) + (a[2] > 0);
    if(cnt < 3){
        printf("YES");
        return 0;
    }

    string p = "BGR";
    do{
        code[p[0]] = 1;
        code[p[1]] = 2;
        code[p[2]] = 3;
        int res = solve();
        if(res){
            printf("YES");
            return 0;
        }
    }while(next_permutation(all(p)));

    printf("NO");

return 0;
}
