#include<bits/stdc++.h>
using namespace std;

class Ordinate{
    friend is_escape_possible(vector<vector<int>>  , Ordinate  );
//private:
public:
    int row ;
    int column ;
    int direction_vector_row[4] = {-1 , 1, 0 , 0 };
    int direction_vector_column[4] = { 0 , 0 ,1 , -1};
public:
    Ordinate(int row , int column){
        this->column = column;
        this->row = row;
    }
    Ordinate(){
        this->column = -1;
        this->row = -1;
    }

};
void explore_neighbour(Ordinate rc ,int&  no_of_nodes_in_next_layer , list<Ordinate> & q, vector<vector<char>> &  maze , vector<vector<bool>> &  visited){
    Ordinate temp ; 
    for(int i = 0 ; i < 4 ; ++i){
        temp.row = rc.row + rc.direction_vector_row[i];
        temp.column= rc.column + rc.direction_vector_column[i];

        if(temp.row < 0 || temp.column < 0 || temp.row >= (int)maze.size()  || temp.column >=(int) maze[0].size() || visited[temp.row][temp.column] || maze[temp.row][temp.column] == '#' ){
            continue;
        }
        q.push_back(temp);
        no_of_nodes_in_next_layer++;
        visited[temp.row][temp.column] = true;
    }
}

pair<int , bool> is_escape_possible(vector<vector<char>>  & maze , Ordinate start_pos){
    list<Ordinate> q;
    bool reached_end = false;
    Ordinate temp ;
    int no_of_nodes_left_in_the_layer = 1;
    int no_of_nodes_in_next_layer = 0 ;
    int step_count = 0 ;
    vector<vector<bool>> visited(maze.size() , vector<bool> (maze[0].size() , false));



    q.push_back(start_pos);
    visited[start_pos.row][start_pos.column] = true;
    
    while(q.size() >0){
        temp = q.front();
        q.pop_front();
       // cout<<temp.row<<"  "<<temp.column<<"  \n";
        if(maze[temp.row][temp.column] == 'E'){
            reached_end = true;
            break;
        }
        explore_neighbour(temp , no_of_nodes_in_next_layer ,  q , maze, visited);
        no_of_nodes_left_in_the_layer  = no_of_nodes_left_in_the_layer - 1 ;
        if(no_of_nodes_left_in_the_layer == 0 ){
           // cout<<"Helllow ";
            no_of_nodes_left_in_the_layer = no_of_nodes_in_next_layer;
            no_of_nodes_in_next_layer = 0 ;
            step_count = step_count + 1 ;
        }

    }

    cout<<" Step Count \n"<<step_count;
    
    if(reached_end){
        return make_pair(step_count,true);
    }
    return make_pair(-1,false);
}
int main(){
    vector<vector<char>> maze (5 , vector<char>(7,'*'));
    maze[0][0] = 'S';
    maze[4][3] = 'E';

    maze[4][0] = '#';
    maze[1][1] = '#';
    maze[2][1] = '#';
    maze[3][2] = '#';
    maze[4][2] = '#';
    maze[0][3] = '#';
    maze[3][3] = '#';
    maze[1][5] = '#';
    maze[4][5] = '#';
    Ordinate start(0,0);
    auto ans = is_escape_possible(maze,start);
    if(std::get<1>(ans)){
        cout<<"Escape is possible in " << get<0>(ans)<<" steps.";
    }else{
        cout<<"Escape not possible.";
    }

    cout<<"Fine.";
    return 0 ;
}