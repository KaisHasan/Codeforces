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

int n,k;
string s;
char gc(int x){
    return char('A'+ x);
}
char nxt(char c){
    if(c == 'A')
        return 'B';
    return 'A';
}
char aft(char a , char b){
    for(int i = 0 ; i < k ; ++i){
        if(gc(i) != a && gc(i) != b)
            return gc(i);
    }
    return '?';
}
int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);sc(k);
    cin>>s;
    int res = 0;
    if(k == 2){
        string t1 = "A";
        string t2 = "B";
        char lst1 = 'A';
        char lst2 = 'B';
        for(int i = 1 ; i < n ; ++i){
            t1 += nxt(lst1);
            t2 += nxt(lst2);
            lst1 = nxt(lst1);
            lst2 = nxt(lst2);
        }
        int res1 = 0;
        int res2 = 0;
        for(int i = 0 ; i< n ; ++i){
            res1 += (s[i] != t1[i]);
            res2 += (s[i] != t2[i]);
        }
        printf("%d\n" , min(res1,res2));
        if(res1 < res2){
            cout<<t1;
        }
        else
            cout<<t2;
    }
    else{
        int res1 = 0 , res2 = 0;
        string t = s + "?";
        for(int i = 1 ; i < n ; ++i){
            if(t[i] == t[i-1]){
                ++res1;
                t[i] = aft(t[i-1] , t[i+1]);
            }
        }
        t = "?" + s;
        for(int i = 1 ; i < n ; ++i){
            if(t[i] == t[i+1]){
                ++res2;
                t[i] = aft(t[i-1] , t[i+1]);
            }
        }
        if(res1 < res2){
            s += '?';
            for(int i = 1 ; i < n ; ++i){
                if(s[i] == s[i-1]){
                    s[i] = aft(s[i-1] , s[i+1]);
                }
            }
        }
        else{
            s = t;
        }
        printf("%d\n" , min(res1,res2));
        for(int i = 0 ; i < n + 1; ++i)
            if(s[i] != '?')
                printf("%c" , s[i]);
    }


return 0;
}
