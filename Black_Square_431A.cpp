#include<bits/stdc++.h>

using namespace std;
typedef long l;
typedef long long ll;
typedef unsigned long long ull;

int main(void){


        map<char ,int> x;
        for(char i = '1' ; i <= '4' ; ++i)
            cin>>x[i];
        string s;
        cin>>s;
        int n = s.size();
        l sum = 0;
        for(int i = 0 ; i < n ; ++i){
            sum+= x[s[i]];
        }
        cout<<sum;





}
