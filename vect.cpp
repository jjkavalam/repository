#include<vector>
#include<iostream>
#include<limits.h>

using namespace std;

class Graph{
    
    int V;
    vector<int> *weight_matrix;
 
    public:
    Graph( int v );
    void add_edge( int u , int v , int weight);
    void dijkstra( int s );
    int min_distance_not_in_mst( vector<bool> &mst, vector<int> &distance );
};

Graph::Graph( int v ){
    
    this->V = v;
    weight_matrix = new vector<int>[V];
    for(int j = 0 ; j < V ; j++ )
        for( int i = 0 ; i < V ; i++)
            weight_matrix[j].push_back(0);
}

void Graph::add_edge( int u , int v , int weight ){
    
    weight_matrix[u][v] = weight;
}

int Graph::min_distance_not_in_mst( vector<bool> &mst, vector<int> &distance){
    int min = INT_MAX;
    int min_idx = -1;    
    for(int i = 0 ; i < V ; i++){
        int temp = distance[i];
        if(mst[i] != true && temp < min){
            min = distance[i];
            min_idx = i;
            cout<<i;
         }
     }
     return min_idx;
}
void Graph::dijkstra( int s ){
    
    vector<int> distance;
    vector<bool> mst;
    
    for( int i = 0 ; i < V ; i++ ){
        distance.push_back(INT_MAX);
        mst.push_back(false);
     }
     
     distance[s] = 0;
     mst[s] = true;
     
     for( int i = 0 ; i < V; i++ ){
        
        int current_node = min_distance_not_in_mst( mst , distance );
        if( current_node == -1 ){
            cout<<"\nNot Reachable:";
            for( int k = 0; k < V ; k++)
                if(!(mst[k]))
                    cout<<k;
            break;
        }
        for( int j = 0 ; j < V ;j++ ){
            int j_distance_via_current_node = distance[current_node] + weight_matrix[current_node][j];
            if( weight_matrix[current_node][j] > 0 && j_distance_via_current_node < distance[j] ){
                distance[j] = j_distance_via_current_node;
            }
        }
     }      
}

int main(){
    
    Graph test = Graph(4);
    test.add_edge(0,1,1);
    test.add_edge(0,2,1);
    test.add_edge(0,3,1);
    test.dijkstra(0);         
}    
