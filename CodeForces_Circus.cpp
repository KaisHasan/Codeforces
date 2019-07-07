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
const int MAX = 5055;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int n;
int a[MAX] , c[MAX];


int main(){
    sc(n);
    string s;
    cin>>s;
    for(int i = 0 ; i < n; ++i)
        c[i] = (s[i] == '1');
    s.clear();
    cin>>s;
    for(int i = 0 ; i < n ; ++i)
        a[i] = (s[i] == '1');
    int m = n /2 ;
    int na = 0 , nc = 0 , nca = 0 , nb = 0;
    for(int i = 0 ; i < n ; ++i){
        na += (a[i] && !c[i]);
        nc += (c[i] && !a[i]);
        nca += (a[i] && c[i]);
        nb += (a[i] + c[i] == 0);
    }
    for(int i = 0 ; i <= nc + nca ; ++i){
        int remca = ((i > nc)?(nca -i+nc):nca);
        int numc = min(i , nc);
        int needA = i;
        needA -= remca;
        if(needA < 0 || needA > na)
            continue;
        int numa = na - needA;
        int numca = nca - remca;

        if(numc + numca + numa > m)
            continue;
        int numb = m - (numc + numca + numa);
        if(numb > nb)
            continue;
        int rem2 = m;
        rem2 -= needA;
        rem2 -= remca;
        rem2 -= (nb - numb);
        rem2 -= (nc - numc);
        if(rem2 != 0)
            continue;
        for(int i = 0 ; i < n && numc; ++i){
            if(c[i] && !a[i]){
                printf("%d " , i + 1);
                --numc;
            }
        }
        for(int i = 0 ; i < n && numca; ++i){
            if(c[i] && a[i]){
                printf("%d " , i + 1);
                --numca;
            }
        }
        for(int i = 0 ; i < n && numa ; ++i){
            if(a[i] && !c[i]){
                printf("%d " , i + 1);
                --numa;
            }
        }
        for(int i = 0 ; i < n && numb ; ++i){
            if(a[i] + c[i] == 0){
                printf("%d " , i + 1);
                --numb;
            }
        }
        return 0;
    }
    printf("-1");
return 0;
}
