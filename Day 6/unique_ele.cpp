#include<iostream>
#include<vector>

using namespace std;
int single(vector<int> & arr)
{
    int ans = 0;
    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,1,1,1,2,3,3,3};
    int a = single(arr);
    cout<<a;
}
