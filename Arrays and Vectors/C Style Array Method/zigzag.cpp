#include <iostream>

// nums1 is a pointer to the first element in nums1 (which is an array that exists on the stack)
// nums2 is a pointer to the first element in nums2 (which is an array that exists on the stack)
int* mySolution(int* nums1, int* nums2) {
    int counter = 0;

    // Creating array in the heap because we want it
    // to continue existing after 'mySolution' goes out of scope
    int* new_array = new int[8];
    
    for (int i = 0; i < 4; i++) {
        new_array[counter] = nums1[i];
        counter++;
        new_array[counter] = nums2[i];
        counter++;
    }

    // We return the memory address of new_array (it's memory is in the heap)
    // The memory in the heap conintues existing even after 'mySolution' goes out
    // of scope
    return new_array;
}


int main() {
    // We are creating raw arrays like in C Style
    int nums1[4] = {16, 21, 3, 74};
    int nums2[4] = {-6, 0, 15, 1};

    // array1 is a pointer to the first element of new_array (which is stored in the heap)
    // new_array ceases to exits when 'mySolution' goes out of scope
    int* array1 = mySolution(nums1, nums2);

    for (int i = 0; i < 8; i++) {
        std::cout << array1[i] << std::endl;
    }

    delete[] array1;

    return 0;
}