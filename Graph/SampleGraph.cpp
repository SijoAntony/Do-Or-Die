#include <iostream>
#include <queue>
#include <stack>

#include "Graph.h"

using namespace std;

void bfs(Graph& g, int s)
{
    map<Vertex*, bool> visitedVertices;
    vector<int> vertices = g.getVertices();
    
    for (vector<int>::iterator it = vertices.begin(); it != vertices.end(); ++it)
        visitedVertices[g.getVertex(*it)] = false;
        
    queue<Vertex*> Q;
    Q.push(g.getVertex(vertices[0]));
    
    while (!Q.empty()) {
        Vertex  *v = Q.front();
        Q.pop();

        if(visitedVertices[v])
            continue;
            
        cout<<v->key()<<" ";
        visitedVertices[v] = true;
        vector<Vertex*> n = v->getNeighbours();
        
        for(int i = 0; i < n.size(); i++)
                Q.push(n[i]);        
    }
}

void dfs(Graph& g, int s)
{

}
int main()
{
    Graph g;
    for (int i = 0; i < 6; i++)
        g.addVertex(i);
    
    g.addEdge(0,1,5);
    g.addEdge(0,5,2);
    g.addEdge(1,2,4);
    g.addEdge(2,3,9);
    g.addEdge(3,4,7);
    g.addEdge(3,5,3);
    g.addEdge(4,0,1);
    g.addEdge(5,4,8);
    g.addEdge(5,2,1);         
    
    g.print();
    
    bfs(g, 0);
                
    return 0;
}
