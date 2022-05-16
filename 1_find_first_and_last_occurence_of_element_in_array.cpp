#include<iostream>
using namespace std;

/**
 * @author Jatin Vashisht
 * @brief the way of finding first and last occurece of element in an array follows similar approach
 * @details The algorithm of finding first occurence of element in an array is the first we will find the  index of element through binary search.
 * Then instead of returning the elements index we will store its index inside a variable and search the left part of the array because the element can also be present before the index of current element also
 * If we found another element in left side then we will return the index of the newly found element otherwise the previous index will be returned
 * -1 will be returned if the element is not present in the array
 */

/*
 * @param arr array to search
 * @param start starting index from where we will start traversing the array
 * @param end  ending index upto which we will traverse the array
 * @param element element we want to search for
 * @param result variable with default value of -1, it will store the index of the element
 * @returns index of the first occurence of element if found else -1
 * */
int getFirstOccurenceOfElement(int* arr, int start, int end, int element, int result = -1){
    int mid = start - ((start - end)/2);
    // cout<<"mid is "<<mid<<" start is "<<start<<" end is "<<end<<"\n";
    if(start > end){
        return result;
    }
    else if(arr[mid] == element){
        result = mid;
        // cout<<"result is "<<result<<" "<<"mid is "<<mid<<"\n";
        return getFirstOccurenceOfElement(arr, 0, mid-1, element, result);
    }
    else if(element < arr[mid]){
        return getFirstOccurenceOfElement(arr, start, mid-1, element, result);
    }else if(element > arr[mid]){
        return getFirstOccurenceOfElement(arr, mid+1, end, element, result);
    }

}

int main(){
int arr[5] = {1,3,3,4,5};
cout<<getFirstOccurenceOfElement(arr, 0, 4, 3);
return 0;
}