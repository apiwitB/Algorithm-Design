#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> 
using namespace std;
vector<int> save;
struct nugget
{
    int n,p;
};

int find_min (nugget ng[],int amount){
    if (amount<=0)return 0;
    if (save[amount]!=-1)return save[amount];

    save[amount] = min(min(ng[0].p + find_min(ng,amount-ng[0].n),ng[1].p+find_min(ng,amount-ng[1].n)),ng[2].p+find_min(ng,amount-ng[2].n));

    return save[amount];

}


int main (){
    nugget ng[3];
    int amount;
    for (int i = 0; i < 3; i++)
    {
        cin >> ng[i].n >> ng[i].p;
    }
    cin >> amount;
    save.resize(amount+1,-1);
    
    cout << find_min(ng,amount);

}