# ArrayOps-A-Collection-of-Array-Manipulation-Functions-in-C-
ArrayOps is a C++ library for array manipulation, offering functions to generate geometric progressions, compute cross-correlation, remove duplicates, and manage dynamic memory safely. It simplifies common array operations, making it a practical tool for handling arrays in C++ projects.

ArrayOps: A Collection of Array Manipulation Functions in C++
Overview
ArrayOps is a C++ library that provides a set of powerful functions for manipulating arrays. These functions include operations such as calculating geometric progressions, performing cross-correlation, and removing duplicate elements from arrays. The library demonstrates practical applications of array manipulation and memory management in C++, and can be integrated into various C++ projects that require array-based operations.

Features
1. Geometric Progression
Generates an array of size cap representing the geometric progression of a given starting value (a) and ratio (ratio).
The elements of the array are computed using the formula:
𝑎
×
𝑟
𝑖
a×r 
i
 , where i is the index of the array (starting from 0).
2. Cross-Correlation
Computes the cross-correlation of two input arrays (array0 and array1).
The function returns a new array where each element is the result of the convolution of the two input arrays, calculated as:
result
[
𝑖
]
=
∑
𝑗
=
0
𝑐
𝑎
𝑝
1
array0
[
𝑖
+
𝑗
]
×
array1
[
𝑗
]
result[i]= 
j=0
∑
cap 
1
​
 
​
 array0[i+j]×array1[j]
The resulting array has a length of cap0 + cap1 - 1, where cap0 and cap1 are the sizes of the two input arrays.
3. Shifting Duplicates
This function removes duplicates from an array by shifting them to the end.
The function returns the number of unique elements in the array after duplicates are moved to the end.
The array is modified in-place.
4. Deallocation Function
Provides a safe memory deallocation function to delete dynamically allocated memory for arrays and single elements.
Ensures that the pointer is set to nullptr after deallocation to avoid dangling pointers.
Example Usage
cpp
Copy code
#include "ArrayOps.h"
#include <iostream>

int main() {
    // Example 1: Geometric Progression
    double *gp_result = geometric(2.0, 3.0, 5);  // Starting value 2.0, ratio 3.0, size 5
    for (std::size_t i = 0; i < 5; i++) {
        std::cout << gp_result[i] << " ";  // Prints the generated geometric sequence
    }
    std::cout << std::endl;
    deallocate(gp_result, true, 5);  // Clean up after using the array

    // Example 2: Cross-Correlation
    double array0[] = {1, 2, 3};
    double array1[] = {0, 1, 2};
    double *cc_result = cross_correlation(array0, 3, array1, 3);
    for (std::size_t i = 0; i < 5; i++) {
        std::cout << cc_result[i] << " ";  // Prints cross-correlation result
    }
    std::cout << std::endl;
    deallocate(cc_result, true, 5);  // Clean up after using the array

    // Example 3: Shifting Duplicates
    int array[] = {1, 2, 2, 3, 3, 3, 4};
    std::size_t new_size = shift_duplicates(array, 7);
    for (std::size_t i = 0; i < new_size; i++) {
        std::cout << array[i] << " ";  // Prints the array with duplicates shifted
    }
    std::cout << std::endl;

    return 0;
}
Functions
1. double* geometric(double a, double ratio, std::size_t cap)
Generates a geometric progression array of size cap starting with the value a and using the common ratio ratio.

Parameters:
a: The starting value of the progression.
ratio: The common ratio between successive terms.
cap: The size of the resulting array.
Returns: A pointer to a dynamically allocated array containing the geometric progression.
2. double* cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1)
Computes the cross-correlation of two arrays.

Parameters:
array0[]: The first input array.
cap0: The size of the first input array.
array1[]: The second input array.
cap1: The size of the second input array.
Returns: A pointer to a dynamically allocated array containing the cross-correlation result.
3. std::size_t shift_duplicates(int array[], std::size_t capacity)
Removes duplicate elements from the array and shifts them to the end.

Parameters:
array[]: The input array to be processed.
capacity: The size of the array.
Returns: The number of unique elements in the array.
4. void deallocate(double*& ptr, bool is_array, std::size_t capacity = 0)
Deallocates the dynamically allocated memory for arrays or single elements.

Parameters:
ptr: A reference to the pointer that points to the allocated memory.
is_array: A boolean flag indicating whether the pointer is an array (true) or a single element (false).
capacity: The size of the array, used only when is_array is true.
Installation
Clone this repository to your local machine:

bash
Copy code
git clone https://github.com/your-username/arrayops.git
Include the ArrayOps.h file in your project and link the implementation when compiling.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Contributions
If you want to contribute to this project, feel free to fork the repository, make your changes, and submit a pull request. All contributions are welcome!

Notes:
The geometric and cross_correlation functions dynamically allocate memory, and you need to manually deallocate the memory using the deallocate function to avoid memory leaks.
The shift_duplicates function modifies the array in place and returns the new size of the array after duplicates are removed.
