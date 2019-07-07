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
#define sc(a) scanf(" %d",&a)
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
string goal;
vector<char> ans;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    cin>>n;
    cin.ignore();
    getline(cin , goal);
    int q;
    cin>>q;
    int flg = 0;
    while(q--){
        string qw;
        cin>>qw;
        char c = qw[0];
        if(c == 'C'){
            flg ^= 1;
        }
        else if(c == 'B'){
            if(ans.empty())
                continue;
            ans.pop_back();
        }
        else if(c == 'S'){
            ans.pb(' ');
        }
        else{
            if(flg)
                c = toupper(c);
            ans.pb(c);
        }
    }

    string res(all(ans));
    if(res == goal)
        printf("Correct");
    else
        printf("Incorrect");


return 0;
}
