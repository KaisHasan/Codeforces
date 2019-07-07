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

string s;
int cs[MAX][3];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    cin>>s;
    int n = s.size();
    cs[0][0] = (s[0] == 'x');
    cs[0][1] = (s[0] == 'y');
    cs[0][2] = (s[0] == 'z');
    for(int i = 1 ; i < n ; ++i){
        cs[i][0] = (s[i] == 'x') + cs[i-1][0];
        cs[i][1] = (s[i] == 'y') + cs[i-1][1];
        cs[i][2] = (s[i] == 'z') + cs[i-1][2];
    }
    int m ;
    sc(m);
    while(m--){
        int l , r;
        sc(l);sc(r);
        --l;--r;
        int cx = cs[r][0] - ((l > 0)? cs[l-1][0] : 0);
        int cy = cs[r][1] - ((l > 0)? cs[l-1][1] : 0);
        int cz = cs[r][2] - ((l > 0)? cs[l-1][2] : 0);
        if(r - l + 1 < 3)
            printf("YES");
        else if(cs == 0 || cy == 0 || cz == 0)
            printf("NO");
        else{
            int mn = min(cx , min(cy , cz));
            cx -= mn;
            cy -= mn;
            cz -= mn;
            if(cx > 1 || cy > 1 || cz > 1)
                printf("NO");
            else
                printf("YES");
        }
        blank;
    }


return 0;
}
