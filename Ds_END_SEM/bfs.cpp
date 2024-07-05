#include "iostream"
#include <vector>
#include <queue>
#define MAX 5
using namespace std;

class AdjList {
public:
    int data;
    AdjList* next;
};

AdjList* create(int data) {
    AdjList* temp = new AdjList();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

class Graph {
public:
    AdjList* adj[MAX];
    bool visited[MAX];  // Changed to bool for clarity

    Graph() {
        for (int i = 0; i < MAX; i++) {
            visited[i] = false;  // Initialize visited array elements to false
            adj[i] = NULL;       // Initialize adj array elements to NULL
        }
    }

    ~Graph() {
        // Clean up memory to avoid memory leaks
        for (int i = 0; i < MAX; i++) {
            AdjList* current = adj[i];
            while (current != NULL) {
                AdjList* next = current->next;
                delete current;
                current = next;
            }
        }
    }
};

Graph* graph;

void insertEdge(int start, int dest) {
    AdjList* nn = create(dest);
    nn->next = graph->adj[start];
    graph->adj[start] = nn;
    nn = create(start);
    nn->next = graph->adj[dest];
    graph->adj[dest] = nn;
}

void BFS(int start) {
    queue<int> q;
    q.push(start);
    graph->visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        AdjList* tmp = graph->adj[node];
        while (tmp) {
            if (!graph->visited[tmp->data]) {
                graph->visited[tmp->data] = true;
                q.push(tmp->data);
            }
            tmp = tmp->next;
        }
    }
}

int main() {
    graph = new Graph();
    insertEdge(0, 1);
    insertEdge(0, 2);
    insertEdge(1, 2);
    insertEdge(1, 4);
    insertEdge(1, 3);
    insertEdge(2, 4);
    insertEdge(3, 4);

    cout << "BFS Traversal starting from node 0: ";
    BFS(2);

    delete graph;  // Clean up allocated memory

    return 0;
}
