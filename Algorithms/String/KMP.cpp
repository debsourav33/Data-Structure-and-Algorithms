#include<bits/stdc++.h>
using namespace std;

vector<int> prefix(string &p){
    vector<int> pi(p.length(), 0);
    int now;

    pi[0]= now= -1;

    for(int i=1; i<p.length();i++){
        while(now!=-1 && p[i]!=p[now+1])
            now= pi[now];

        if(p[i]==p[now+1])    pi[i]= ++now;
        else    pi[i]= -1;
    }
    
    return pi;
}

vector<int> kmp(string &text, string &p, vector<int> &pi){
    vector<int> ret;
    int match=0, now;
    now= -1;

    for(int i=0;i<text.length();i++){
        while(now!=-1 && text[i]!=p[now+1])
            now= pi[now];

        if(text[i]==p[now+1])  ++now;
        else  now= -1;

        if(now==p.length()-1){
            match++;
            ret.push_back(i-p.length()+1);
            now= pi[now];
        }
    }

    return ret;
}


main(){
    cin>>text>>p;

    auto pi = prefix(p);
    auto matches = kmp(text, p, pi);
}
