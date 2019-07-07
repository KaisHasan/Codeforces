#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define blank printf("\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 0.0000001;

ll power(ll x , ll y){
    if(y == 0)
        return 1;
    ll res = power(x , y / 2);
    res *= res;
    if(y % 2)
        res *= x;
    return res;
}
ll kp[100];
ll n ,k;
bool check(ll v){
    ll sum = 0;
    ll i = 0;
    while(1){
        //cout<<"kp[i] = "<<kp[i]<<endl;
        ll p = v / kp[i++];
        if(!p){
            if(sum >= n)
                return 1;
            return 0;
        }
        sum += p;
    }
}


int main(){

    scl(n);
    scl(k);
    for(ll i = 0 ; kp[i-1] < ll(1e17) ; ++i)
        kp[i] = power(k , i);

    ll st = 0 , en = 1e14;
    ll res = -1;
    while(st <= en){
        ll md = (st + en)>>1;
        //cout<<"md = "<<md<<endl;
        if(check(md)){
            en = md - 1;
            res = md;
        }
        else
            st = md + 1;
    }

    cout<<res;



return 0;
}
