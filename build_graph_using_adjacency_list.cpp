#include <iostream>
#include <list>
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
};

int main() {
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);

    graph.print();
    return 0;
}