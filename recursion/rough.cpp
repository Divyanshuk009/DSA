#include <iostream>
using namespace std;

// int binSearch(int arr[], int size, int key)
// {

//     int start = 0;
//     int end = size - 1;
//     int mid = start + (end - start) / 2;

//     while (start <= end)
//     {
//         if (arr[mid] == key)
//         {
//             return mid;
//         }
//         if (arr[mid] < key)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//         mid = start + (end - start) / 2;
//     }
//     return -1;
// }

// int main()
// {

//     int num[] = {13, 34, 54, 66, 76, 120, 130, 232, 540};

//     int size = 9;
//     int key = 232;
//     int index = binSearch(num, size, key);

//     cout << "66 is at index: " << index;
// }

int firstOccur(int num[],int size,int key){
    int start=0;
    int end=size-1;

    int mid = start + (end-start)/2;
    int ans =-1;

    while(start<=end){
        if(num[mid]==key){
            ans=mid;
            end=mid-1;
        }
        if(num[mid]<key){
            end=mid-1
        }
        if(num[mid]>key){
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int lastOccur(int num[],int size,int key){
    int start=0;
    int end=size-1;

    int mid = start + (end-start)/2;
    int ans =-1;

    while(start<=end){
        if(num[mid]==key){
            ans=mid;
            start=mid+1;
        }
        if(num[mid]<key){
            end=mid-1
        }
        if(num[mid]>key){
            start=mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int main(){
    int arr[]={1,2,3,4,5,5,5,5,5,6,7,8,9};
    int size=13;
    int key=5;

    int first=firstOccur(arr,size,key);
    int last=lastOccur(arr,size,key);

    cout<<"first occurence of 5 is at index: "<<first<<endl;
    cout<<"last occurence of 5 is at index: "<<last<<endl;
}


