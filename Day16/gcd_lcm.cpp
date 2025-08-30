#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}

int lcm(int a,int b)
{

    return (a * b) / gcd(a, b);
}


int main()
{
    int a,b;
    cout<<"Enter the a and b: ";
    cin>>a>>b;
    int resultGCD = gcd(a,b);
    int resultLCM = lcm(a,b);

    cout<<"GCD: "<<resultGCD<<endl;
    cout<<"LCM: "<<resultLCM<<endl;
}
