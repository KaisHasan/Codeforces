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

struct node{
    bool isword;
    node* child[3];
    int len;
    node(int _len = -1){
        isword = 0;
        memset(child , 0 , sizeof(child));
        len = _len;
    }
}*head;

void _insert(string &s){
    node* it = head;
    for(int i = 0 ; i < s.size() ; ++i){
        int let = s[i] - 'a';
        if(!it->child[let])
            it->child[let] = new node(it->len + 1);
        it = it->child[let];
    }
it->isword = 1;
}
string t;
bool solve(node * it , int num = 0){
    if(it->len + 1 >= (int)t.size())
        return (num == 1) && it->isword;
    if(num > 1)
        return 0;
    int res = 0;
    for(int i = 0 ;i < 3 ; ++i){
        if(!it->child[i])
            continue;
//        printf("letter == %c , len == %d , t[] = %c\n" , char('a' + i) , it->len , t[it->len+1]);
        res |= solve(it->child[i] , num + (t[it->len+1] != char('a' + i)));
    }
    return res;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int n , q;
    sc(n);sc(q);
    head = new node();
    while(n--){
        string s;
        cin>>s;
        _insert(s);
    }
    while(q--){
        t.clear();
        cin>>t;
//        cout<<t<<endl;
//        printf("%d\n" , (int)t.size());
//        printf("len == %d\n" ,head->len);
        int ans = solve(head);
        if(ans)
            printf("YES");
        else
            printf("NO");
        blank;
    }



return 0;
}
