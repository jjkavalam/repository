#include<iostream>
#include<list>

using namespace std;

class Graph {

    int V;
    list<int> *adj;

    public:
    Graph( int V );
    void add_edge ( int u , int v );
    void bfs ( int s );
 
};

Graph::Graph ( int V ) {
    
    Graph::V = V;
    Graph::adj = new list<int>[V]; 
} 

void Graph::add_edge ( int u , int v ) {

    adj[u].push_back ( v );
    
}

int main () {

    Graph ( 10 );
}
        
    

