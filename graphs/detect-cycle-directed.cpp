#include <iostream>
#include <list>
using namespace std;

bool detectCycleUtil(int v, bool visited[], bool recur[], list<int> *adj) {
    if(!visited[v]) {
        visited[v] = true;
        recur[v] = true;

        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i) {
            if(!visited[*i] && detectCycleUtil(v, visited, recur, adj))
                return true;
            else if(recur[*i])
                return true;
        }
    }
    recur[v] = false;
    return false;
}

bool detectCycle(int V, list<int> *adj) {
    bool visited[V];
    bool recur[V];

    for(int i = 0; i < V; i++) {
        if(detectCycleUtil(i, visited, recur, adj))
            return true;
    return false;
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

    bool isCyclic = detectCycle(V, adj);
    cout << isCyclic;
}
