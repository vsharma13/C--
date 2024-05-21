/*find max and min in given array of integers
*/
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

// void FindMinMaxofArray(const int *arr, int arrlen, int *min, int *max);
tuple<int, int> FindMinMaxofArray(const int *arr, int arrlen);

int main() {
	// int *min = new int;
	// int *max = new int;
    int testArr[9]= {12, 43, 551, 1, 34, 768, 1,1,2};
	min_element()

	int SizeArr = sizeof(testArr)/sizeof(testArr[0]);
	
	//FindMinMaxofArray(testArr, SizeArr, min,max);
	auto [min, max] = FindMinMaxofArray(testArr, SizeArr);
	cout << "Min of Array: " << min << endl;
	cout << "Max of Array: " << max << endl;
	
	return 0;
}

//void FindMinMaxofArray(const int *arr, int arrlen, int *min, int *max) {
tuple<int, int> FindMinMaxofArray(const int *arr, int arrlen) {
	int min=0;
	int max=0;
	for (int i=0 ; i < arrlen; i++) {
		if (arr[i] < min ) {
			min = arr[i];
		} else if (arr[i] > max) {
			max = arr[i];
		}
	}
	return {min, max};

	cout << endl;
	
}