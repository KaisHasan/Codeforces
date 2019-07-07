#include<bits/stdc++.h>

using namespace std;
typedef long l;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
const int MAX = 102;
const int inf = 1e7+77;
const int MOD = 1e8+7;

int B[MAX] , G[MAX];

int main(){

    int n , m;
    sc(n);
    for(int i = 0 ; i < n ; ++i)
        sc(B[i]);
    sort(B , B + n);
    sc(m);
    for(int i = 0 ; i < m ; ++i)
        sc(G[i]);
    sort(G , G + m);

    int b = 0 , g = 0 , res = 0;
    while(b < n && g < m){
        if(abs(B[b] - G[g]) <= 1)
        {
            res++;
            b++;
            g++;
        }
        else if(B[b] < G[g])
            b++;
        else
            g++;
    }


cout<<res;


return 0;
}
