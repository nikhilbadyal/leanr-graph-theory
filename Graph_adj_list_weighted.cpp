#include<bits/stdc++.h>
using namespace std;


class Graph{
private:
protected:
    int no_of_vertices;
    vector<pair<int,int>> * adj_list ;
public:
    Graph(int v){
        this->no_of_vertices = v;
        this->adj_list = new vector<pair<int,int>>[v];
    }
    void add_edge(int, int ,int );
    void display();
    int get_weight(int source , int destination){
        for(auto x : adj_list[source]){
            if(x.first == destination){
                return x.second;
            }
        }
        return INT_MAX;
    }

};
void Graph::add_edge(int source , int destination , int weight){
    adj_list[source].push_back(make_pair(destination,weight));
}
void Graph::display(){
    for(int i = 0 ; i < no_of_vertices ; ++i){
        cout<<"Node "<<i<<" makes an edge with:\n ";
        for(auto  x : adj_list[i]){
            cout<<"\tNode "<<x.first<<"with a cost of "<<x.second<<"\n";
        }
        cout<<endl;
    }
}
/* 
int main(){
    Graph graph(4);
    graph.add_edge(0,1,1);
    graph.add_edge(0,2,1);
    graph.add_edge(1,2,1);
    graph.add_edge(1,3,1);
    graph.add_edge(2,2,1);
    graph.display();



    cout<<"Fine";

    return 0 ;
} */