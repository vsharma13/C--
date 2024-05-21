#include<iostream>
#include <vector>
using namespace std;

class Solution {
    private:
        //Add your code here
        int x1 = 1;
        int x2 {1};
        // int x3 (1);

public: 
vector<int> v1 {1,2,3};
vector<int> v2 = {1,2,3};
    // vector<int> v3 (10,20); 


    // auto v {1}; // v is int
    // auto w {1, 2}; // error: only single elements in direct
    // // auto initialization allowed! (this is new)
    // auto x = {1}; // x is std::initializer_list<int>
    // auto y = {1, 2}; // y is std::initializer_list<int>
    // auto z = {1, 2, 3.0}; // error: Cannot deduce element type
};

int main()
{
Solution sol;
sol.v2.push_back(4);
std::cout<< sol.v2[3] << endl;
 return 0;
}