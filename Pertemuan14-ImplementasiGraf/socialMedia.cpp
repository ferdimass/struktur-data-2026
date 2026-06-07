#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SocialGraph {
private:
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<string> users;

public:
    SocialGraph(int vertices, vector<string> names) {
        V = vertices;
        adj.resize(V);
        visited.resize(V, false);
        users = names;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void resetVisited() {
        fill(visited.begin(), visited.end(), false);
    }

    void DFS(int v) {
        visited[v] = true;
        cout << users[v] << " ";
        for(int u : adj[v]) {
            if(!visited[u]) DFS(u);
        }
    }

    void BFS(int start) {
        resetVisited();
        queue<int> q;
        vector<int> level(V, -1);
        visited[start] = true;
        level[start] = 0;
        q.push(start);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            cout << users[v] << " (tingkat " << level[v] << ")" << endl;
            for(int u : adj[v]) {
                if(!visited[u]) {
                    visited[u] = true;
                    level[u] = level[v] + 1;
                    q.push(u);
                }
            }
        }
    }

    void showFriends(int v) {
        cout << "Teman " << users[v] << " : ";
        for(int u : adj[v]) {
            cout << users[u] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<string> users = {"Andi", "Budi", "Citra", "Dina", "Eko"};
    SocialGraph g(5, users);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "===== DATA PERTEMANAN =====" << endl;
    for(int i = 0; i < 5; i++) g.showFriends(i);

    cout << "\n===== DFS (Seluruh Teman Terhubung) =====" << endl;
    cout << "Mulai dari Andi : ";
    g.DFS(0);
    cout << endl;

    cout << "\n===== BFS (Tingkat Pertemanan) =====" << endl;
    cout << "Mulai dari Andi :" << endl;
    g.BFS(0);

    return 0;
}