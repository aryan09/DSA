#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<climits>
using namespace std;

template<typename T>
class Graph{
public:

    map<T,list<T> > adjList;

    void addEdge(T u,T v,bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void printadjList(){
        for(auto node:adjList){
            cout<<node.first<<"-->";
            for(auto neighbour:node.second){
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
    }

    void BFS(T src){
        queue<T> q;
        map<T,bool> visited;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T node=q.front();
            cout<<node<<" ";
            q.pop();

            for(auto children:adjList[node]){

                if(!visited[children]){
                    q.push(children);
                    visited[children]=true;
                }
            }

        }
        cout<<endl;
    }

    int SSSP(T src,T des){    //Single Shortest Path
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;
        //SET distance of all node to infinity
        for(auto node:adjList){
            dist[node.first]=INT_MAX;
        }

        q.push(src);
        dist[src]=0;

        while(!q.empty()){
            T node=q.front();
            q.pop();

            for(auto children:adjList[node]){
                if(dist[children]==INT_MAX){
                    dist[children]=dist[node]+1;
                    parent[children]=node;
                    q.push(children);
                }
            }
        }

        for(auto node:dist){
            cout<<"Distance of "<<node.first<<" from "<<src<<" : "<<dist[node.first]<<endl;
        }
        return dist[des];
    }

    void dfsHelper(T src,map<T,bool> &visited){
        cout<<src<<" ";
        visited[src]=true;
        for(auto children:adjList[src]){
            if(!visited[children]){
                dfsHelper((children,visited));
            }
        }
    }
    void dfs(T src){
        map<T,bool> visited;
        dfsHelper(src,visited);

        int component=1;

        for(auto node:adjList){
            if(!visited[node.first]){
                dfsHelper(node.first,visited);
                component++;
            }
        }
        cout<<endl<<"component : "<<component<<endl;

    }



    int SnakeAndLadder(T src,T des){
        queue<T> q;
        map<T,int> dist;
        map<T,T> parent;

        for(auto node:adjList){
            dist[node.first]=INT_MAX;
        }

        q.push(src);
        parent[src]=src;
        dist[src]=0;

        while(!q.empty()){
            T node=q.front();
            q.pop();

            for(auto children:adjList[node]){
                if(dist[children]==INT_MAX){
                    dist[children]=dist[node]+1;
                    parent[children]=node;
                    q.push(children);
                }
            }
        }

        T temp=des;
        while(des!=src){
            cout<<des<<"<--";
            des=parent[des];
        }
        return dist[temp];
    }

};


int main(){

/*Graph<string> g;

g.addEdge("Putin","Trump",false);
g.addEdge("Putin","Modi",false);
g.addEdge("Trump","Modi");
g.addEdge("Yogi","Modi");
g.addEdge("Yogi","Prabhu",false);
g.addEdge("Prabhu","Modi",false);
g.addEdge("Putin","Pope",false); */

/*Graph<int> g;

g.addEdge(0,1);
g.addEdge(0,4);
g.addEdge(2,4);
g.addEdge(2,1);
g.addEdge(2,3);
g.addEdge(3,4);
g.addEdge(5,3);
g.BFS(0);   */

//cout<<g.SSSP(0,5)<<endl;

//g.printadjList();

Graph<int> g;

int board[50] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17]=-13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    for(int i=0;i<36;i++){
        for(int dice=1;dice<=6;dice++){
            int v=i+dice+board[i+dice];
            g.addEdge(i,v,false);
        }
    }

 //   cout<<g.SnakeAndLadder(0,36)<<endl;

    g.dfs();

return 0;
}
