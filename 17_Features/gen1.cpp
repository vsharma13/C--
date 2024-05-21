#include <iostream>
using namespace std;

class VSs {
	public:
		int id;
		
		VSs() {
			cout << "Default Constructor ..." << endl;
			id = -1;
		}
		
		VSs(int x) {
			cout << "Parameterized Constructor ..." << endl;
			id = x;
		}
};

int main() {
	VSs vs1;
	cout << "VS id is " << vs1.id << endl;
	
	VSs vs2(25);
	cout << "VS id is " << vs2.id << endl;
	
	return 0;
}
	
		