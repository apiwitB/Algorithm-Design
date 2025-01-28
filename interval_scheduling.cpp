#include<iostream>
#include<algorithm>
using namespace std;

struct S{
    int st;
    int fi;
};

int main(){
    int n,con=0,cf=0;
    cin >> n;
    S arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i].st;
        cin >> arr[i].fi;
    }


    sort(arr, arr + n, [](const S& a, const S& b){
        return a.fi < b.fi;
    });


    for (int i = 0; i < n; i++){
        if (arr[i].st >= cf){
            con++;
            cf = arr[i].fi;
        }
    }


    cout << con << endl;

    return 0;
}
