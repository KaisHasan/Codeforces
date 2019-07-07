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
//divide it
ll a[3] = {2 , 3 , 5};

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int q;
    sc(q);
    while(q--){
        ull n;
        cin>>n;
        ll res = 0;
        while(1){
            int cnt = 0;
            for(int i = 0;  i < 3 ; ++i){
                while(n % a[i] == 0){
                    if(i == 0){
                        n /= a[i];
                    }
                    else if(i == 1){
                        n /= a[i];
                        n *= 2;
                    }
                    else{
                        n /= a[i];
                        n *= 4ull;
                    }
                    ++res;
                    ++cnt;
                }
            }
            if(!cnt)
                break;
        }
        if(n != 1)
            res = -1;
        cout<<res<<endl;
    }


return 0;
}
