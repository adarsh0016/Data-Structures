#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class graph{
    int V;
    vector<int>* aList;
    public:
    graph(int n){
        V = n;
        aList = new vector<int>[n];
    }
        void addEdge(int u, int v){
            aList[u].push_back(v);
            //for underected graph add
            aList[v].push_back(u);
        }



        void printGraph(){
            for(int v= 0; v < V; v++){
                cout<<"\n Adjancency list of vertex "<<v<<"\n head";
                for(int i = 0; i < aList[v].size(); i++){
                    cout<<"-> "<<aList[v][i];
                }
                cout<<endl;
            }
        }



        void depthFirstPrint(int source){
            stack<int> S;
            S.push(source);

            while(!S.empty()){
                int curr = S.top();
                S.pop();
                cout<<curr<<" ";
                for(auto x: aList[curr]){
                    S.push(x);
                }
            }
        }



        void depthFirstPrint_recurr(int Source){
            cout<<Source<<" ";
            for(int x: aList[Source]){
                depthFirstPrint_recurr(x);
            }
        }



        void breadthFirstPrint(int source){
            queue<int> Q;
            Q.push(source);

            while(!Q.empty()){
                int curr = Q.front();
                Q.pop();
                cout<<curr<<" ";
                for(int x: aList[curr]){
                    Q.push(x);
                }
            }
        }



        bool depthFirstSearch(int source, int dest){
            if(source == dest) return true;
            for(int x: aList[source]){
                if(depthFirstSearch(x, dest)) return true;
            }
            return false;
        }



        bool depthFirstSearch_undirected(int source, int dest, vector<int> visited = {}){
            if(source == dest) return true;
            if(count(visited.begin(), visited.end(), source)) return false;

            visited.push_back(source);

            for(int x: aList[source]){
                if(depthFirstSearch_undirected(x, dest, visited)) return true;
            }
            return false;
        }



        bool explore_all_connections(int current, vector<int> &visited){
            if(count(visited.begin(), visited.end(), current)) return false;

            visited.push_back(current);

            for(int x: aList[current]){
                explore_all_connections(x, visited);
            }
            return true;
        }
        int connnectedComponents(){
            vector<int> visited = {};
            int count = 0;
            for(int node = 0 ; node < V ; node++){
                if(explore_all_connections(node, visited)) count++;
            }
            return count;
        }



        int no_of_nodes_in_a_connection(int current, vector<int> &visited){
            int count_n = 1;
            if(count(visited.begin(), visited.end(), current)) return 0;

            visited.push_back(current);

            for(int x: aList[current]){
                count_n += no_of_nodes_in_a_connection(x, visited);
            }
            return count_n;
        }
        int largestComponent(){
            vector<int> visited = {};
            int count = 0;
            for(int node = 0 ; node < V ; node++){
                count = max(count,no_of_nodes_in_a_connection(node, visited));
            }
            return count;
        }



        int shortestPath(int source, int dest){
            struct list_node{
                int data;
                int path_length;
                list_node(int a, int n){
                    data = a;
                    path_length = n;
                }
            };

            vector<int> visited;
            queue<list_node> Q;
            list_node L_n(source, 0);
            Q.push(L_n);
            while(!Q.empty()){
                int node = Q.front().data;
                int distance = Q.front().path_length;
                if(node == dest){
                    return distance;
                }
                Q.pop();
                for(int x : aList[node]){
                    if(!count(visited.begin(), visited.end(), x)){
                        visited.push_back(x);
                        list_node L_nn(x, distance + 1);
                        Q.push(L_nn);
                    }
                }
            }
            return -1;
        }
};

int main(){
    int V = 8;
    graph G(V);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(3,1);
    G.addEdge(3,5);
    G.addEdge(4,3);
    cout<<G.shortestPath(0,4);
    return 0;
}