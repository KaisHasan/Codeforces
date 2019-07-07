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

int n;
int a[MAX];
vi v;
void GenerateDivisors(int n){
    int i;
    for( i = 1 ; i * i < n ; ++i){
        if(n%i == 0){
            v.push_back(i);
            if(i != 1)
                v.push_back(n/i);
        }
    }
    if(i * i == n)
        v.push_back(i);
}

bool check(int st , int hop){
    for(int i = st ; i < n ; i += hop)
        if(!a[i])
            return false;
    return true;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ;i < n ; ++i)
        sc(a[i]);
    GenerateDivisors(n);
    sort(all(v) , greater<int>());
//    for(auto it : v)
//        printf("%d " , it);
//    blank;
//    pla;
    for(int i = 1 - (n%2) ; i < (int)v.size() ; ++i){
        int d = v[i];
        for(int j = 0; j < d ; ++j){
            if(check(j , d)){
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");


return 0;
}
