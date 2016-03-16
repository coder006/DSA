#include <iostream>
#include<list>

using namespace std;

void DFSUtil(int s, int V, list<int> *adj, bool visited[]) {
    visited[s] = true;
    cout << s << " ";

    list<int>::iterator i;
    for(i = adj[s].begin(); i != adj[s].end(); ++i) {
        if(!visited[*i]) {
            DFSUtil(*i, V, adj, visited);
        }
    }
}

void DFS(int s, int V, list<int> *adj) {
    bool visited[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    DFSUtil(s, V, adj, visited);
}

int main() {
    int V = 4;
    list<int> *adj;
    adj = new list<int>[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(3);

    DFS(2, V, adj);
}
