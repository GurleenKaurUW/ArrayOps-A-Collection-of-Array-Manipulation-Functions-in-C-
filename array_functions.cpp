#include <iostream>
#include <cassert>

// void print_array(int *array, std::size_t cap){
//     if(cap == 0)return;
//     std::cout<<array[0];
//     for(std::size_t i{1}; i<cap; i++){ //start at 1
//         std::cout<<", "<<array[i];
//     }
//     std::cout<<std::endl;

//     //do i need to set the ptr to nullptr?
// }

double *geometric( double a, double ratio, std::size_t cap ){
    double *result{new double[cap]};
    
    for (std::size_t i{0}; i<cap; i++){
        double power{1};
        for(int j{1};j<=i;j++){
            power *= ratio;
        }
        result[i] = a*power;
    }
    return result;
    //do i need to delete anything here or set something to nullptr?
}

double *cross_correlation(double array0[], std::size_t cap0, double array1[], std::size_t cap1){
    assert(cap0 + cap1 >= 1);
    std::size_t cap_result{cap0 + cap1 -1};

    double *result{new double[cap_result]};

    //set everything to zero
    for(std::size_t index{0}; index<cap_result; index++) result[index] = 0;

    for(std::size_t index_arr_0{0}; index_arr_0<cap0; index_arr_0++){
        for(std::size_t index_arr_1{0}; index_arr_1<cap1; index_arr_1++){

            result[index_arr_1+index_arr_0] += array0[index_arr_0]*array1[index_arr_1];

        }
    }

    return result;

}

std::size_t shift_duplicates( int array[], std::size_t capacity ){
    std::size_t unique_index{0};
    std::size_t index{0};
    
    for(std::size_t counter{0}; counter < capacity; index++, counter++){
        //check if there is a duplicate
        bool is_duplicate{false};
        for(std::size_t i{0}; i<index; i++){
            if(array[index]==array[i]){
                is_duplicate = true;
            }
        }
        if(is_duplicate){
            int duplicate_val = array[index];
            //shift everything down one
            for(std::size_t i{index};i<capacity-1; i++){
                array[i] = array[i+1];
            }
            //set last entry to the duplicate val
            array[capacity-1] = duplicate_val;
            index --;
        }else{
            unique_index++;
        }
    }

    // print_array(array, capacity);

    return unique_index;
}

void deallocate( double *&ptr, bool is_array, std::size_t capacity = 0 ){
    if(is_array){
        for(std::size_t index{0}; index<capacity; index++){
            ptr[index] = 0;
        }
        delete[] ptr;
        ptr = nullptr;
    }
    else{
        *ptr = 0;
        delete ptr;
        ptr = nullptr;
    }
}


// int main(){

//     int array[5] = {2,3,4,1,1};
//     std::cout<<shift_duplicates(array,5)<<std::endl;

//     return 0;
// }