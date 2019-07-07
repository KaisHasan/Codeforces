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


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int n;
    sc(n);
    string s;
    cin>>s;
    int stl = -1 , enl = -1;
    for(int i = 0 ; i < n; ++i){
        if(s[i] == 'L'){
            stl = i;
            break;
        }
    }
    if(stl != -1){
        for(int i = n - 1 ; i >= 0 ; --i){
            if(s[i] == 'L'){
                enl = i;
                break;
            }
        }
    }
    int str = -1 , enr = -1;
    for(int i = 0 ; i < n ; ++i){
        if(s[i] == 'R'){
            str = i;
            break;
        }
    }
    if(str != -1){
        for(int i = n - 1; i >= 0 ; --i){
            if(s[i] == 'R'){
                enr = i;
                break;
            }
        }
    }
    if(str == -1 && stl == -1){
        printf("1 1");
    }
    else if(str != -1 && stl == -1){
        printf("%d %d" , str + 1, enr + 2);
    }
    else if(str == -1 && stl != -1){
        printf("%d %d" , enl + 1, stl);
    }
    else{
        printf("%d %d" , str + 1, stl + 1);
    }




return 0;
}
