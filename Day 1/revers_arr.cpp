#include<iostream>
#include<vector>
using namespace std;

int revers(int arr[], int sz)
{
    int st=0;
    int end=sz-1;

    while(st<end)
    {
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
}
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int sz = sizeof(arr)/sizeof(arr[0]);
    revers(arr,sz);
    for(int i=0;i<sz;i++)
    {
        cout<<arr[i];
    }
 
}
