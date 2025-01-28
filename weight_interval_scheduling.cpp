#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> T;

struct WIS
{
    int ts;
    int tf;
    int cost;

};
bool compare(WIS a,WIS b){
    return a.tf < b.tf;
}

int findNonConflict(WIS list[],int i){
    int low = 0,high = i-1;
    while (low <= high){
        int mid =(low+high)/2;
        if(list[mid].tf<=list[i].ts){
            if (mid+1<i && list[mid+1].tf<=list[i].ts)
            {
                low = mid +1;
            }else{
                return mid;
            }
        
        }
        else{
            high = mid -1;
        }
    }
    return -1;

 }

int OPT(WIS list[], int i) {
    if (i < 0) return 0; // Base case
    if (T[i] != -1) return T[i]; // ถ้าเคยคำนวณแล้วให้คืนค่าเลย

    // หา p(i)
    int p_i = findNonConflict(list, i);

    // ใช้ recursive relation
    T[i] = max(list[i].cost + OPT(list, p_i), OPT(list, i - 1));
    return T[i];
}



int main(){
    int job =0;
    cin >> job;
    WIS list[job];

    for (int i = 0;i<job;i++){
        cin >> list[i].ts >> list[i].tf >> list[i].cost;

    }
    sort(list,list+job,compare);
    T.resize(job,-1);
 
 cout << "Maximum weight: " << OPT(list, job - 1) << endl;


}
