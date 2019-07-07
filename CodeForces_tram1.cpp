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

int s , x1 , x2;
int t1 , t2;
int p , d , igor;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(s);sc(x1);sc(x2);
    sc(t1);sc(t2);
    sc(p);sc(d);
    if(t1 >= t2){
        ll res = abs(x2 - x1) * t2;
        printf("%I64d" , res);
    }
    else{
        if(x2 < x1){
            igor = -1;
        }
        else
            igor = 1;
        int dis = 0;
        if(d + igor == 0){
            if(d == -1)
                dis = p + x2;
            else
                dis = s - p + s - x2;
        }
        else{
            if(d == 1){
                if(p > x1){
                    dis = s - p + s + x2;
                }
                else
                    dis = x2 - p;
            }
            else{
                if(p < x1)
                    dis = p + s + s - x2;
                else
                    dis = p - x2;
            }
        }
        int res1 = dis * t1;
        int res2 = abs(x2-x1)*t2;
        printf("%d" , min(res1 , res2));
    }



return 0;
}
