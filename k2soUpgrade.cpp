#include<iostream>
#include<algorithm>
using namespace std;

struct store{
    int ts;
    int tf;
};

int main(){
    int n, counter = 0,cf = -1;
    cin >> n;
    store arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i].ts;
        cin >> arr[i].tf;
    }

    sort(arr, arr + n, [](const store& a, const store& b){
        return a.tf < b.tf;
    });

    for (int i = 0; i < n; i++){
        if (arr[i].ts > cf) {
            counter++;
            cf = arr[i].tf;
        }
    }

    cout << counter ;
    cout << endl;


    return 0;
}
