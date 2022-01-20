#include<bits/stdc++.h>
#include"Graph_adj_list_weighted.cpp"
using namespace std ;


class Dijkstra : public Graph {
public:
    Dijkstra(int no_of_nodes) : Graph(no_of_nodes){}

    void shortest_path(int , vector<int> & );

};
class mycomparison
{
public:
    bool operator() (pair<int , int > & p1 , pair<int, int > & p2  ) { 
      return p1.second > p2.second;
    }
};


void Dijkstra::shortest_path(int start , vector<int> & distances ){
    vector<bool> visited(distances.size() , false);
    distances[start] = 0 ;
    typedef pair<int,int> queue_data;
    priority_queue< queue_data, vector<queue_data> , mycomparison > pq;
    pq.push(make_pair(start,0));
    int new_distance = 0 ;
    while(pq.size()!= 0){
        auto temp = pq.top();
        pq.pop();
        visited[temp.first] = true;
        if(distances[temp.first] < temp.second ){
            continue;
        }
        for(auto x : adj_list[temp.first]){
            if(visited[x.first]){
                continue;
            }
            new_distance = distances[temp.first] + x.second ;
            if(new_distance < distances[x.first]){
                distances[x.first] = new_distance;
                pq.push(make_pair(x.first,new_distance));
            }
            
        }
    }

}

int main(){
    Dijkstra graph(5);
    graph.add_edge(0,1,4);
    graph.add_edge(0,2,1);
    graph.add_edge(1,3,1);
    graph.add_edge(2,1,2);
    graph.add_edge(2,3,5);
    graph.add_edge(3,4,3);

    vector<int> distances(5,INT_MAX);
    int start = 0 ;
    graph.shortest_path(start , distances);

    for(int x : distances){
        cout<<x<<"  ";
    }

    return 0 ;
}