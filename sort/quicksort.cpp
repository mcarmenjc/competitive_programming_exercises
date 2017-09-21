/*
QUICKSORT
*/

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;

enum class Pivot {
    First,
    Last,
    Random,
    Median
};

int ChoosePivot(std::vector<int> &array, int start, int end, Pivot type){
    if (type == Pivot::First){
        return start;
    }
    else if (type == Pivot::Last){
        return end;
    }
    else if (type == Pivot::Random){
        return (rand() % (end - start + 1) + start);
    }
    else if (type == Pivot::Median){
        //look for implementation for this
        return start;
    }
    return end;
}

void SwapElements(std::vector<int> &array, int pos1, int pos2){
    int temp = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = temp;
}

int RearrangeElementsInArray(std::vector<int> &array, int start, int end, int pivot_position){
    SwapElements(array, end, pivot_position);
    pivot_position = end;
    int it_start = start;
    int it_end = end-1;
    while (it_start <= it_end){
        if (array[it_start] < array[end]){
            ++it_start;
        }
        if (array[it_end] >= array[end]){
            --it_end;
        }
        if (it_start < it_end &&
            array[it_start] >= array[end] && 
            array[it_end] < array[end]){
            SwapElements(array, it_start, it_end);
            ++it_start;
            --it_end;
        }
    }
    SwapElements(array, end, it_start);
    return it_start;
}

void Quicksort(std::vector<int> &array, int start, int end, Pivot type){
    if (start >= end){
        return;
    }

    int pivot_position = ChoosePivot(array, start, end, type);
    pivot_position = RearrangeElementsInArray(array, start, end, pivot_position);
    Quicksort(array, start, pivot_position - 1, type);
    Quicksort(array, pivot_position + 1, end, type);
}

void Print(const std::vector<int> &numbers){
    for (int n : numbers){
        std::cout << n << "  ";
    }
    std::cout << std::endl;
}

int main(){
    srand (time(NULL));
    std::vector<int> example1 = {};
    Print(example1);
    Quicksort(example1, 0, example1.size()-1, Pivot::Last);
    Print(example1);
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::vector<int> example2 = {2};
    Print(example2);
    Quicksort(example2, 0, example2.size()-1, Pivot::Last);
    Print(example2);
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::vector<int> example3 = {4, 3, 7, 1, 9, 5, 3, 4, 11, 14};
    Print(example3);
    Quicksort(example3, 0, example3.size()-1, Pivot::Last);
    Print(example3);
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::vector<int> example4 = {2, 4, 1};
    Print(example4);
    Quicksort(example4, 0, example4.size()-1, Pivot::Last);
    Print(example4);
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::vector<int> example5 = {4, 3, 7, 1, 9, 5, 3, 4, 11, 14};
    Print(example5);
    Quicksort(example5, 0, example5.size()-1, Pivot::First);
    Print(example5);
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    std::vector<int> example6 = {4, 3, 7, 1, 9, 5, 3, 4, 11, 14};
    Print(example6);
    Quicksort(example6, 0, example6.size()-1, Pivot::Random);
    Print(example6);
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
}