#include <iostream>
#include <cstring>
#include <queue>
#include <list>
#include <typeinfo>

using namespace std;

void BFS(int s, int V, list<int>* adj) {
    bool visited[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q;
    visited[s] = true;
    q.push(s);
    
    while(!q.empty()) {
        s = q.front();
        q.pop();
        cout << s << " ";
        list<int>::iterator i;
        for(i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
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

    BFS(2, V, adj);
}
