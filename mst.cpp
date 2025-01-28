#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent ;

struct G{
    int u;
    int v;
    int cost;
};

bool compareByCost(const G &a,const G &b){
    return a.cost < b.cost;
}

int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSet(int u,int v){
    int rootu = find(u);
    int rootv = find(v);
    if (rootu  != rootv){
        parent[rootu]=rootv;
    }
    
}


int main(){
    int node = 0;
    int edge = 0;
    int totalCost = 0;
    int edgeCount = 0;
    cin >> node; 
    cin >> edge;
    G g[edge];
///make parent for find path
    parent.resize(node+1);
    for (int i = 1; i <= node; i++){
        parent[i]=i;
    }
///input to array of struct
    for (int i = 0; i < edge; i++){
        cin >> g[i].u >> g[i].v >> g[i].cost ;
    }
//////sorting 
    sort(g,g+edge,compareByCost);


//////////////////DEBUG/////////////////////
/*
    for (int i = 0; i < edge; i++)
    {
        cout << "u: "  << g[i].u ;
        cout << " v: "  << g[i].v;
        cout << " cost: "  << g[i].cost;
        cout <<endl;
    }
*/
/////////////////////////////////////////////    
    
    for(int i=0;i<edge;i++){
        if (find(g[i].u) != find(g[i].v)){
            unionSet(g[i].u,g[i].v);
            totalCost += g[i].cost;
            edgeCount++;
        }
        

    } 
//////detect all node are connected
    if(edgeCount==node-1){
        cout << totalCost << endl;
    }else{
        cout << "-1";
    }


    return 0;
}