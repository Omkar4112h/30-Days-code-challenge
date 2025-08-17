#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
int duplicate(vector<int> & arr)
{
    int ans;
    int n = arr.size();
    unordered_set<int> s;
    for(int i = 0; i<n ; i++)
    {

        if(s.find(arr[i]) != s.end())
        {
            ans = arr[i];
            break;
        }
        s.insert(arr[i]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1,3,3,3,3,6,7};
    int a= duplicate(arr);
    cout<<"The duplicate number is: "<<a;
}
