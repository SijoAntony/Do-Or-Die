//Graph data structure implementation

#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class UndirectedGraph {
public:
    UndirectedGraph()
        : m_size(0) {
    }
    
    void addVertex(int key) {
        m_size++;
        m_vertices[key] = new UndirectedGraphNode(key);
    }
    
    void addEdge(int from, int to) {
        m_vertices[from]->neighbors.push_back(m_vertices[to]);
    }
    
    vector<UndirectedGraphNode*> getVertices() {
        vector<UndirectedGraphNode*> vertices(m_size);
        for (map<int, UndirectedGraphNode*>::iterator it = m_vertices.begin(); it != m_vertices.end(); ++it)
            vertices.push_back(it->second);
        return vertices;
    }
    
    UndirectedGraphNode* getVertex(int key) {
        return m_vertices[key];
    }
    
    static void bfs(UndirectedGraphNode* n) {
        if (!n)
            return;
            
        queue<UndirectedGraphNode*> q;
        map<UndirectedGraphNode*, bool> visited;
        q.push(n);
        
        while (!q.empty()) {
            UndirectedGraphNode* node = q.front();
            q.pop();
            
            visited[node] = true;
            cout<<node->label<<" ( ";
            for (vector<UndirectedGraphNode*>::iterator it = node->neighbors.begin(); it != node->neighbors.end(); ++it) {
                cout<<(*it)->label<<" ";
                if (visited.find(*it) == visited.end())
                    q.push(*it);
                visited[*it] = true;
            }
            cout<<")"<<endl;
        }
    }
    
    void print(){
        for (map<int, UndirectedGraphNode*>::iterator it = m_vertices.begin(); it != m_vertices.end(); ++it) {
            UndirectedGraphNode *v = it->second; 
            cout<<v->label<<" ( ";
            for (vector<UndirectedGraphNode*>::iterator n = v->neighbors.begin(); n != v->neighbors.end(); ++n)
                cout<<(*n)->label<<" ";
            cout<<")"<<endl;
        
        }
    }
    
private:
    map<int, UndirectedGraphNode*> m_vertices;
    int m_size;
};

struct Edge;

struct DirectedGraphNode {
    int label;
    vector<Edge*> neighbors;
    DirectedGraphNode(int x) : label(x) {}
};

struct Edge {
    DirectedGraphNode* node;
    int weight;
    Edge(DirectedGraphNode* _node, int _weight) 
        : node(_node)
        , weight(_weight) {}
};

class DirectedGraph {
public:
    DirectedGraph()
        : m_size(0) {
    }
    
    void addVertex(int key) {
        m_size++;
        m_vertices[key] = new DirectedGraphNode(key);
    }
    
    void addEdge(int from, int to, int weight) {
        m_vertices[from]->neighbors.push_back(new Edge(m_vertices[to], weight));
    }
    
    vector<DirectedGraphNode*> getVertices() {
        vector<DirectedGraphNode*> vertices(m_size);
        for (map<int, DirectedGraphNode*>::iterator it = m_vertices.begin(); it != m_vertices.end(); ++it)
            vertices.push_back(it->second);
        return vertices;
    }
    
    DirectedGraphNode* getVertex(int key) {
        return m_vertices[key];
    }
    
    static void bfs(DirectedGraphNode* n) {
        if (!n)
            return;
            
        queue<DirectedGraphNode*> q;
        map<DirectedGraphNode*, bool> visited;
        q.push(n);
        
        while (!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();
            
            visited[node] = true;
            cout<<node->label<<" (";
            for (vector<Edge*>::iterator it = node->neighbors.begin(); it != node->neighbors.end(); ++it) {
                DirectedGraphNode *neighbor = (*it)->node;
                cout<<"["<<neighbor->label<<" "<<(*it)->weight<<"]";
                if (visited.find(neighbor) == visited.end())
                    q.push(neighbor);
                visited[neighbor] = true;
            }
            cout<<")"<<endl;
        }
    }

    static void dfs(DirectedGraphNode *n, map<DirectedGraphNode *, bool> &visited) {
        if (!n)
            return;

        visited[n] = true;

        for (int i = 0; i < n->neighbors.size(); i++) {
            Edge *edge = n->neighbors[i];
            if (!visited[edge->node]) {
                cout<<n->label<<" ";
                cout<<"["<<edge->node->label<<" "<<edge->weight<<"] ";
                dfs(edge->node, visited);
            }
        }
    }
    
    static void dfs(DirectedGraphNode *n) {
        map<DirectedGraphNode *, bool> visited;
        dfs(n, visited);        
    }    
    void print(){
        for (map<int, DirectedGraphNode*>::iterator it = m_vertices.begin(); it != m_vertices.end(); ++it) {
            DirectedGraphNode *v = it->second; 
            cout<<v->label<<" (";
            for (vector<Edge*>::iterator n = v->neighbors.begin(); n != v->neighbors.end(); ++n)
                cout<<"["<<(*n)->node->label<<" "<<(*n)->weight<<"]";
            cout<<")"<<endl;
        }
    }
    
private:
    map<int, DirectedGraphNode*> m_vertices;
    int m_size;
};
