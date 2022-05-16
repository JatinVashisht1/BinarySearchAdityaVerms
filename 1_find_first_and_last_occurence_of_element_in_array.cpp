#include<iostream>
using namespace std;



/**
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