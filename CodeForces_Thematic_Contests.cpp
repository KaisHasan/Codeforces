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
map<int , int> c;
int cnt[5*MAX];
int cal[5*MAX];
vi numbers;

int Bin(int x){
    int st = 0 , en = numbers.size() - 1;
    int res = -1;
    while(st <= en){
        int md = (st + en)>>1;
        int id = numbers[md];
        if(cnt[id] - cal[id] > 0 && numbers[md] >= x){
            res = md;
            en = md - 1;
        }
        else
            st = md + 1;
    }
    return res;
}

int main(){

    sc(n);
    for(int i = 0 ; i < n ; ++i){
        int x;sc(x);
        c[x]++;
    }
    for(auto i : c){
        cnt[i.second]++;
        if(cnt[i.second] == 1)
            numbers.pb(i.second);
    }
    sort(all(numbers));
    ll ans = -1;
    vi taken;
    for(int i = 1 ; i < 200002 ; ++i){
        ll res = 0;
        taken.clear();
        int num = i;
        while(1){
            int pos = Bin(num);
            if(pos == -1)
                break;
            int id = numbers[pos];
            taken.pb(id);
            cal[id]++;
            res += num;
            num *= 2;
        }
        ans = max(ans , res);
        for(auto i : taken)
            cal[i] = 0;
    }
    printf("%I64d" , ans);



return 0;
}
