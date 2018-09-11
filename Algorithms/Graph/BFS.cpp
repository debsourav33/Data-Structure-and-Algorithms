#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000];
int visited[1000], level[1000], path[1000], cycle=0;

void reset(){
    memset(visited, 0, sizeof(visited));
    memset(level, 0, sizeof level);
    memset(path, -1, sizeof path);
}


void bfs(int source){
    queue<int> q;
    q.push(source);
    visited[source]= 1;

    while(!q.empty()){
        int u= q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int node= v[u][i];

            if(!visited[node]){
                visited[node]= 1;
                level[node]= level[u]+ 1;
                path[node]= u;

                q.push(node);
            }

        }
    }

}

bool bipar= true;
void bipartite(int source){
    queue<int> q;
    q.push(source);
    visited[source]= 1;

    while(!q.empty()){
        int u= q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++){
            int node= v[u][i];

            if(!visited[node]){
                visited[node]= 1;
                level[node]= level[u]+ 1;
                path[node]= u;

                q.push(node);
            }

            else{
                if(level[u]%2==level[node]%2){
                    bipar= false;
                    return;
                }
            }

        }
    }

}

void print_path(int node){
    if(node==-1)
        return;

    print_path(path[node]);
    cout<<node<<" ";
}

main(){
    reset();
    int a, b, n, edges;

    cin>>n>>edges;

    for(int i=0;i<edges;i++){
        cin>>a>>b;

        v[a].push_back(b);
        //v[b].pb(a);
    }

    bfs(0);

    for(int i=0;i<n;i++){
        cout<<i<<": ";

        if(visited[i])
            cout<<level[i]<<endl;
        else
            cout<<"Not Reachable"<<endl;
    }


}
