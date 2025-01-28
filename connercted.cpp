#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
vector<int> Rank;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        if (Rank[rootU] > Rank[rootV]) {
            parent[rootV] = rootU;
        } else if (Rank[rootU] < Rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            Rank[rootU]++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    Rank.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

////read eage
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unionSet(u, v);
    }

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            components++;
        }
    }

    cout << components << endl;
    return 0;
}
