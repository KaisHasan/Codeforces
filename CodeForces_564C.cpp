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
int exist[2*MAX] , temp[2*MAX];
int a[2*MAX] , b[2*MAX];

int f(int pos){
    mem(temp , 0);
    for(int i = 0 ; i < n ; ++i)
        temp[b[i]] = 1;
    for(int i = 0 ; i < pos; ++i){
        temp[a[i]] = 1;
    }
    int num = 1;
    for(int i = pos; i < n ; ++i , ++num){
        if(!temp[num])
            return 0;
        temp[a[i]] = 1;
    }
    return 1;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0 ; i < n ; ++i){
        sc(b[i]);
        exist[b[i]] = 1;
    }


    for(int i = 0 ; i < n ; ++i){
        sc(a[i]);
    }

    int num = 1;
    int pos = -1;
    int val = 1;
    for(int i = 0 ; i < n ; ++i){
        if(a[i] == val){
            pos = i;
            break;
        }
    }
    if(pos != -1){
        bool test = true;
        for(int i = pos ; i < n ; ++i , ++val){
            if(a[i] != val){
                test = false;
                break;
            }
        }
        if(test){
            num = a[n-1] + 1 ;
            for(int i = 0 ; i < pos ; ++i){
                if(!exist[num])
                    break;
                ++num;
                exist[a[i]] = 1;
            }
            if(num > n){
                n -= a[n-1];
                printf("%d" , n);
                return 0;
            }
        }
    }
    int st = 0 , en = n;
    int res = -1;
    while(st <= en){
        int md = (st +en)>>1;
        if(f(md)){
            en = md - 1;
            res = md;
        }
        else
            st = md + 1;
    }
    res += n;

    printf("%d" , res);





return 0;
}
