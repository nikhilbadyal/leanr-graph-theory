#include<bits/stdc++.h>
using namespace std;


class Graph{
private:
protected:
    int no_of_vertices;
    vector<int> * adj_list ;
public:
    Graph(int v){
        this->no_of_vertices = v;
        this->adj_list = new vector<int>[v];
    }
    void add_edge(int, int);
    void display();

};
void Graph::add_edge(int source , int destination){
    adj_list[source].push_back(destination);
    if(source != destination)
        adj_list[destination].push_back(source);
}
void Graph::display(){
    
    for(int i =0 ; i < no_of_vertices ; ++i){
        cout<<"Vertex "<<i<<" makes an edge with:\n ";
        for(int x : adj_list[i]){
            cout<<"\tNode "<<x<<"\n";
        }
        cout<<endl;
    }
}
/*
int main(){
    Graph graph(4);
    graph.add_edge(0,1);
    graph.add_edge(0,2);
    graph.add_edge(1,2);
    graph.add_edge(1,3);
    graph.add_edge(2,2);
    graph.display();



    cout<<"Fine";

    return 0 ;
}
*/