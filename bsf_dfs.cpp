#include<bits/stdc++.h>
#include"Graph_adj_list.cpp"
using namespace std;

class GraphFunctions : public Graph{
private:
    void dfs_utility(int starting_vertex, vector<bool> & visited){
        if(visited[starting_vertex])
            return ;
        cout<<starting_vertex<<"  ";
        visited[starting_vertex] = true;
        for(int x : adj_list[starting_vertex]){
            dfs_utility(x,visited);
        }
    }
public:
    GraphFunctions(int v ): Graph(v){
    }
    void bfs(int );
    void dfs(int );
};
void GraphFunctions::bfs(int starting_vertex ){
    
    vector<bool> visited(no_of_vertices);
    for(int i =0  ; i < no_of_vertices ; ++ i ){
        visited[i] = false;
    }
    visited[starting_vertex] = true;
    
    list<int> queue ;
    queue.push_back(starting_vertex);
    while (!queue.empty()){
        starting_vertex = queue.front();
        cout<<starting_vertex<<"  ";
        queue.pop_front();

        for(int x : adj_list[starting_vertex]){
            if(!visited[x]){
                visited[x]  = true;
                queue.push_back(x);
            }
        }
    }

}

void GraphFunctions::dfs(int starting_vertex){
    vector<bool> visited(no_of_vertices);
    for(int i =0  ; i < no_of_vertices ; ++ i ){
        visited[i] = false;
    }

    dfs_utility(starting_vertex,visited);
}
int main(){
    GraphFunctions graph(13);
    
    graph.add_edge(0,7);
    graph.add_edge(0,9);
    graph.add_edge(0,11);
    graph.add_edge(1,10);
    graph.add_edge(1,8);
    graph.add_edge(2,12);
    graph.add_edge(2,3);
    graph.add_edge(3,7);
    graph.add_edge(4,3);
    graph.add_edge(5,6);
    graph.add_edge(6,7);
    graph.add_edge(7,11);
    graph.add_edge(8,9);
    graph.add_edge(8,12);
    graph.add_edge(9,10);

   /// graph.bfs(0);
    graph.dfs(0);

    cout<<"Fine";


    return 0 ;
}
