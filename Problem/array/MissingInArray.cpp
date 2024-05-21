#include <iostream>
using namespace std;

int main() {
    int INRange = 10;
    
    int Arr[9] = {1,2,3,4,5,6,8,9,10};

    for (int i=0; i<INRange-1;i++) {
        if(Arr[i]!= i+1) {
            cout << i+1 << " is missing from array" << endl;
            return 0;
        }
    }
    return 0;

}