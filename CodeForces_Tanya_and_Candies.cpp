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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
int odd[2*MAX] ,even[2*MAX];
int a[2*MAX];



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 1 ; i <= n ; ++i)
        sc(a[i]);
    odd[1] = a[1];
    for(int i = 3 ;i <= n ; i += 2)
        odd[i] = odd[i-2] + a[i];
    even[0] = a[0];
    for(int i = 2 ; i <= n ; i += 2)
        even[i] = even[i-2] + a[i];
    int res = 0;
    for(int i = 1 ; i <= n ; ++i){
        int sume = 0 , sumo = 0;
        if(i & 1){
            sume = (i > 1)? even[i-1] : 0;
            sumo = (i > 2)? odd[i-2] : 0;
            if(n & 1){
                sumo += (n > 1)?(even[n-1] - sume) : 0;
                sume += odd[n] - odd[i];
            }
            else{
                sume += (n > 1)?(odd[n-1] - (sumo+a[i])) : 0;
                sumo +=  even[n] - ((i > 1)?even[i-1]:0);
            }
        }
        else{
            sume = (n > 2)? even[i-2] : 0;
            sumo = (n > 1)? odd[i-1] : 0;
            if(n & 1){
                sume += odd[n] - sumo;
                sumo += (n > 1)?even[n-1] - even[i] : 0;
            }
            else{
                sume += (n > 1)? odd[n-1] - sumo : 0;
                sumo += even[n] - even[i];
            }
        }
//        printf("i == %d\n" , i);
//        printf("sume == %d , sumo == %d\n" , sume , sumo);
        if(sume == sumo){
            ++res;
        }
    }
    printf("%d" , res);


return 0;
}
