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

char a[5210][5210];


string letters = "0123456789ABCDEF";
int toInt(char c){
    return letters.find(c);
}
int toDec(string in , int base){
    int res = 0;
    for(int i = 0 ; i < (int)in.size() ; ++i)
        res *= base , res += toInt(in[i]);
    return res;
}
string TOany(int number , int base){
    if(!number)
        return "0000";
    string res = "";
    for(; number; number/=base){
        res = letters[number%base] + res;
    }
    while(res.size() < 4)
        res = "0" + res;
    return res;
}
int n;
int check(int x){
    int g = 0;
    for(int i = 0 ; i < n ; ++i){
        int cnt = 1;
        for(int j = 1 ; j < n ; ++j){
            if(a[i][j] == a[i][j-1])
                ++cnt;
            else{
                g = __gcd(g , cnt);
                cnt = 1;
            }
        }
        g = __gcd(g , cnt);
    }
    for(int j = 0 ; j < n ; ++j){
        int cnt = 1;
        for(int i = 1 ; i < n ; ++i){
            if(a[i][j] == a[i-1][j])
                ++cnt;
            else{
                g = __gcd(g , cnt);
                cnt = 1;
            }
        }
        g = __gcd(g , cnt);
    }
    return g;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    sc(n);
    for(int i = 0; i < n ; ++i){
        string s;cin>>s;
        int id = 0;
        for(int j = 0; j < (int)s.size() ; ++j){
            string t = "";
            t += s[j];
            int D = toDec(t , 16);
            string temp = TOany(D , 2);
            for(int k = 0 ; k < (int)temp.size() ; ++k){
                a[i][id++] = temp[k];
            }
            t.clear();
        }
    }

    printf("%d" , check(n));

return 0;
}
