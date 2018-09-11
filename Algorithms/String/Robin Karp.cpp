#include<bits/stdc++.h>
using namespace std;

//{
#define fr(i,a,n) for(int i=a;i<n;i++)
#define ull unsigned long long
#define ll long long
#define pb push_back
#define MX 10000007
#define all(v) v.begin(),v.end()
//}

ll b = 347, M = 1000000000+7;

ll hashing(string s, int m){
    ll h_value=0, p=1;

    for(int i=m-1;i>=0;i--){
      h_value+= (s[i] *p) % M;
      h_value= h_value % M;
      p= (p*b) % M;
    }

    return h_value;

}

int match(string s, string pattern){
    int t_len=s.length();
    ll m= pattern.length();

    ll h= hashing(s,m);
    ll pat_value= hashing(pattern,m);
    ll pow_b= 1;

    if(pat_value==h){
        return 0;
    }

    for(int i=0; i<m-1; i++)
        pow_b= (pow_b*b) % M;

    for(int i=1; i<=t_len-m+1;i++){
        ll pows= (s[i-1]*pow_b) % M;
        h= (h- pows) % M;
        h = (h + M) % M;
        h= (h*b) % M;
        h= (h +s [i+m-1]) % M;

        if(pat_value==h){
            return i;
        }
    }
}

main(){
    string s, pattern;
    cin>>s>>pattern;

    cout<<match(s,pattern)<<endl;

}
