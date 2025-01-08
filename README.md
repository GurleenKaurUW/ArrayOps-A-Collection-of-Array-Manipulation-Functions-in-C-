# ArrayOps-A-Collection-of-Array-Manipulation-Functions-in-C-
ArrayOps is a C++ library for array manipulation, offering functions to generate geometric progressions, compute cross-correlation, remove duplicates, and manage dynamic memory safely. It simplifies common array operations, making it a practical tool for handling arrays in C++ projects.

# ArrayOps: C++ Array Manipulation Library

**ArrayOps** is a C++ library offering various functions to manipulate arrays, such as generating geometric progressions, performing cross-correlation, removing duplicates, and safely deallocating memory. This library serves as a practical resource for working with arrays in C++.

## Features

- **Geometric Progression**: Generate arrays following a geometric sequence.
- **Cross-Correlation**: Compute the cross-correlation of two arrays.
- **Remove Duplicates**: Shift duplicate elements to the end of an array and return the number of unique elements.
- **Memory Deallocation**: Safely deallocate dynamically allocated memory for arrays and single elements.

## Functions

### `double* geometric(double a, double ratio, std::size_t cap)`
Generates a geometric progression array of size `cap` starting with `a` and using the common ratio `ratio`.

**Parameters**:
- `a`: Starting value of the progression.
- `ratio`: Common ratio between consecutive terms.
- `cap`: Size of the resulting array.

**Returns**: A pointer to the dynamically allocated array containing the geometric progression.

---

### `double* cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1)`
Computes the cross-correlation of two input arrays.

**Parameters**:
- `array0[]`: First input array.
- `cap0`: Size of the first array.
- `array1[]`: Second input array.
- `cap1`: Size of the second array.

**Returns**: A pointer to the dynamically allocated array containing the cross-correlation result.

---

### `std::size_t shift_duplicates(int array[], std::size_t capacity)`
Removes duplicates from an array by shifting them to the end and returns the number of unique elements.

**Parameters**:
- `array[]`: Input array to be processed.
- `capacity`: Size of the array.

**Returns**: The number of unique elements after duplicates have been shifted.

---

### `void deallocate(double*& ptr, bool is_array, std::size_t capacity = 0)`
Safely deallocates memory for arrays or single elements.

**Parameters**:
- `ptr`: A reference to the pointer to be deallocated.
- `is_array`: `true` if `ptr` points to an array, `false` if it points to a single element.
- `capacity`: Size of the array (only used when `is_array` is `true`).

## Example Usage

```cpp
#include "ArrayOps.h"
#include <iostream>

int main() {
    // Geometric Progression Example
    double *gp_result = geometric(2.0, 3.0, 5);
    for (std::size_t i = 0; i < 5; i++) {
        std::cout << gp_result[i] << " ";
    }
    std::cout << std::endl;
    deallocate(gp_result, true, 5);  // Free the array

    // Cross-Correlation Example
    double array0[] = {1, 2, 3};
    double array1[] = {0, 1, 2};
    double *cc_result = cross_correlation(array0, 3, array1, 3);
    for (std::size_t i = 0; i < 5; i++) {
        std::cout << cc_result[i] << " ";
    }
    std::cout << std::endl;
    deallocate(cc_result, true, 5);  // Free the array

    // Remove Duplicates Example
    int array[] = {1, 2, 2, 3, 3, 3, 4};
    std::size_t new_size = shift_duplicates(array, 7);
    for (std::size_t i = 0; i < new_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


