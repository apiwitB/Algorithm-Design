#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>> &graph, int start){
    int n = graph.size();
    vector<bool> visited(n,false);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";

        for(int neighbor : graph[node]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor]=true;
            }
        }

    }
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for(int i = 0;i<m;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    int start;
    cin >> start;

    cout << "BFS Traversal:";
    BFS(graph,start);
    return 0;

}