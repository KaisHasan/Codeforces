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

    vector<int> p1 , p2;
    ll sum1 = 0 , sum2 = 0;
    bool test = 1;
    int n;sc(n);
    for(int i = 0 ; i < n ; ++i){
        int x;sc(x);
        if(x > 0){
            p1.pb(x);
            sum1 += x;
            test = 1;
        }
        else{
            p2.pb(-x);
            sum2 += (-x);
            test = 0;
        }
    }
    if(sum1 != sum2){
        if(sum1 > sum2)
            printf("first");
        else
            printf("second");
        return 0;
    }
    int n1 = p1.size();
    int n2 = p2.size();
    for(int i = 0 ; i < min(n1 , n2) ; ++i){
        if(p1[i] != p2[i]){
            if(p1[i] > p2[i])
                printf("first");
            else
                printf("second");
            return 0;
        }
    }

    if(n1 != n2){
        if(n1 > n2)
            printf("first");
        else
            printf("second");
        return 0;
    }
    if(test)
        printf("first");
    else
        printf("second");



return 0;
}
