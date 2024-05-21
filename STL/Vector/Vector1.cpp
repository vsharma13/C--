/*
Func1: 
Write a program that creates a vector of integers with 10 elements, initializes them with consecutive values from 1 to 10, and then prints each elemen
*/

#include <iostream>
#include <vector>

using namespace std;
vector<int> function1(int);

int main() {
    function1(10);
}

vector<int> function1(int NumElement) {
    vector<int> myvec (10, 0);
    for (int i=1; i<=10 ; ++i) {
        myvec.push_back(i);
    }
    
}
