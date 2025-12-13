using namespace std;

#include <iostream>
#include <algorithm>

int largestContainer(int* array, int size) {
    int maxHeight = 0, maxPos = 0, maxContainer = 0;
    int left = 0, right = size - 1;
    while(left < right) {
        int leftHeigh = array[left];
        int rightHeigh = array[right];
        int currContainer = min(leftHeigh, rightHeigh) * (right - left);
        
        if(currContainer > maxContainer) {
            maxContainer = currContainer;
        }

        if(leftHeigh == rightHeigh || leftHeigh < rightHeigh) left++;
        if(leftHeigh == rightHeigh || leftHeigh > rightHeigh) right--;
    }
    
    return maxContainer;
}

int main() {
    int test1[] = { 2, 7, 8, 3, 7, 6};
    cout << largestContainer(test1, 6) << " (expected: 24)" << endl;

    int test2[] = { };
    cout << largestContainer(test2, 0) << " (expected: 0)" << endl;

    int test3[] = { 1 };
    cout << largestContainer(test3, 1) << " (expected: 0)" << endl;

    int test4[] = { 3, 3, 3, 3 };
    cout << largestContainer(test4, 4) << " (expected: 9)" << endl;

    int test5[] = { 1, 2, 3 };
    cout << largestContainer(test5, 3) << " (expected: 2)" << endl;

    int test6[] = { 3, 2, 1 };
    cout << largestContainer(test6, 3) << " (expected: 2)" << endl;

    return 0;
}