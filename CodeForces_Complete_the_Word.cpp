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

map<char , int> cnt;
set<char> st;

char nextChar(char lst){
    if(lst == '0')
        lst = char('A' - 1);
    for(char c = lst + 1 ; c <= 'Z' ; ++c){
        if(!cnt[c])
            return c;
    }
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    string s;cin>>s;
    int n = s.size();
    int l = 0 , r = 0;
    while(l < n){
        while(r < n && r - l + 1 <= 26){
            cnt[s[r]]++;
            if(s[r] != '?' && cnt[s[r]] == 2){
                ++r;
                break;
            }
            if(s[r] != '?')
                st.insert(s[r]);
            ++r;
        }
        if(st.size() + cnt['?'] == 26){
            char lst = '0';
            for(int i = l ; i < r ; ++i){
                if(s[i] == '?'){
                    char cur = nextChar(lst);
                    lst = cur;
                    s[i] = cur;
                }
            }
            for(int i = 0 ; i < n ; ++i){
                if(s[i] != '?')
                    printf("%c" , s[i]);
                else{
                    printf("A");
                }
            }
            return 0;
        }
        while(l < n){
            cnt[s[l]]--;
            if(s[l] != '?' && cnt[s[l]] == 1)
            {
                ++l;
                break;
            }
            if(s[l] != '?' && cnt[s[l]] == 0)
                st.erase(s[l]);
            ++l;
        }
    }
    printf("-1");

return 0;
}
