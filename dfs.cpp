#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int> *arr;

public:
    Graph(int V) {
        this->V = V;
        arr = new list<int>[V];
    }

    void addEdge(int u, int v) {
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    void print() {
        for (int u = 0; u < V; u++) {
            list<int> neighbors = arr[u];
            cout << u << ": ";

            for (int v : neighbors) {
                cout << v << " ";
            }

            cout << endl;
        }
    }
    
    ~Graph() {
        delete[] arr;
    }

    void bfs(){
        queue<int> q;
        vector<bool> visited(V,false);

        q.push(0);
        visited[0] = true;

        while(q.size()>0){
            int curr = q.front(); //curr is current vertx of graph
            q.pop();

            cout<<curr<<" ";

            list<int> neighbour = arr[curr];
            for(int v:neighbour){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }

        }
        cout<<endl;
    }

    void dfshelper(int source, vector<bool> &visited){
        visited[source]=true;
        cout<<source<<" ";

        list<int> neighbours = arr[source];
        for(int neighbour:neighbours){
            if(!visited[neighbour]){
                dfshelper(neighbour,visited);
            }
        }
    }
    void dfs(){
        vector<bool> visited(7,false);
        dfshelper(0,visited);
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);
    
    cout<<"graph:"<<endl;
    graph.print();

    cout<<"BFS traversal of the graph is: ";
    graph.bfs();
    cout<<endl;

    cout<<"DFS traversal of the graph is: ";
    graph.dfs();
    
    return 0;
}