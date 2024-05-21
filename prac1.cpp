#include <iostream>

using namespace std;

template <typename T1, typename T2, typename T3> 
class my_wrapper {
    T1 t1;
    T2 t2;
    T3 t3;

    public:
    explicit my_wrapper(T1 t1_, T2 t2_, T3 t3_) : t1{t1_}, t2{t2_}, t3{t3_} {}
    
};

int main()
{
    int x (1.2);
    int y = 1.3;
    auto z {1.2};
    // int z {1.2}

    //auto m {1 ,2, 3}; m: in a direct-list-initialization context the type for 'auto' can only be deduced from a single initializer expression
	auto m = {1,2,3};
    cout << "Hello VS Code!" << " x: " << x<< endl;
    return 0;
}