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

string text, pat;
int pi[1000006];

void prefix_function(){
    int now;

    pi[0]= now= -1;

    fr(i,1,pat.length()){
        while(now!=-1 && pat[i]!=pat[now+1])
            now= pi[now];

        if(pat[i]==pat[now+1])    pi[i]= ++now;
        else    pi[i]= -1;
    }
}

int kmp(string text){
    int match=0, now;
    now= -1;

    fr(i,0,text.length()){
        while(now!=-1 && text[i]!=pat[now+1])
            now= pi[now];

        if(text[i]==pat[now+1])  ++now;
        else  now= -1;

        if(now==pat.length()-1){
            match++;
            now= pi[now];
        }
    }

    return match;
}


main(){
    cin>>text>>pat;

    prefix_function();
    cout<<kmp(text)<<endl;
}
