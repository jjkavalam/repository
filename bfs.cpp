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
    
    this->V = V;
    adj = new list<int>[V]; 
} 

void Graph::add_edge ( int u , int v ) {

    adj[u].push_back ( v );
    
}

void Graph::bfs ( int s ) {
    
    bool *visited = new bool [ V ];
    list<int> queue;
    
    for( int i = 0 ; i < V ; i++ ){
    
        visited [ i ] = false;
    }
    
    queue.push_back ( s );
    visited [ s ] = true;
    
    list<int>::iterator i;
    
    while ( !queue.empty() ) {    
        
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        for ( i = adj[s].begin() ; i != adj[s].end() ; ++i ){
                
            if ( !visited[ *i ] ) {
            
                queue.push_back ( *i );
                visited[ *i ] = true;
            }                  
        } 
            
    }    
    
}

int main () {

    Graph test = Graph ( 7 );
    test.add_edge( 1, 2 );
    test.add_edge( 1, 3 );
    test.add_edge( 2, 4 );
    test.add_edge( 2, 5 );
    test.add_edge( 3, 6 );
    test.add_edge( 6, 5 );
    
    test.bfs( 1 );
    
    return 0;
}
        
    

