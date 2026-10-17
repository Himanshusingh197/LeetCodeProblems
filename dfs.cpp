//Write a programm to implement dfs 

#include<bits/stdc++.h>
using namespace std;

const int N = 4;
void DFS(int adj[N][N], int node, bool visited[]) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < N; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            DFS(adj, i, visited);
        }
    }
}

int main() {

    int adj[N][N] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };


    cout << "\nDFS Traversal: ";
    bool visited[N] = {false};
    DFS(adj, 0, visited);

    return 0;
}