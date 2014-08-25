//Graph data structure implementation

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Vertex {
public:
    Vertex(int id)
        : m_id(id) {
    }
    
    void addNeighbour(Vertex *v, int weight) {
        m_neighbours[v] = weight;
    }
    
    void print() {
        cout<<m_id<<" ";
        for (map<Vertex*, int>::iterator it = m_neighbours.begin(); it != m_neighbours.end(); ++it)
            cout<<"("<<it->first->m_id<<":"<<it->second<<")";
        cout<<endl;
    }
    int key() {return m_id;}
    
    vector<Vertex*> getNeighbours() {
        vector<Vertex*> n;
        for (map<Vertex*, int>::iterator it = m_neighbours.begin(); it != m_neighbours.end(); ++it)
            n.push_back(it->first);
        
        return n;
    }
    
private:
    int m_id;
    map<Vertex*, int> m_neighbours;
};

class Graph {
public:
    Graph()
        : m_size(0) {
    }
    
    void addVertex(int key) {
        m_size++;
        m_vertices[key] = new Vertex(key);
    }
    
    void addEdge(int from, int to, int weight) {
        m_vertices[from]->addNeighbour(m_vertices[to], weight);
    }
    
    vector<int> getVertices() {
        vector<int> vertices(m_size);
        for (map<int, Vertex*>::iterator it = m_vertices.begin(); it != m_vertices.end(); ++it)
            vertices.push_back(it->first);
        return vertices;
    }
    
    Vertex* getVertex(int key) {
        return m_vertices[key];
    }
    
    void print(){
        for (map<int, Vertex*>::iterator it = m_vertices.begin(); it != m_vertices.end(); ++it)
            it->second->print();
    }
    
private:
    map<int, Vertex*> m_vertices;
    int m_size;
};
