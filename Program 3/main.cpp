#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    double n; int f=1;
    cout<<"Vvedite n:";
    cin>>n;
    int i; int j; int k=10;
    for(j=2;j<sqrt(n);j++)
    {
        if(!2%j){
                f=0;
                break;
        }
            else f=1;

    }
    if(f==1){
        cout<<2<<" ";
        }
   f=1;
    for(i=3;i<n;i+=2)
    {
        for(j=2;j<sqrt(n);j++)
        {

            if(i%j==0 && i/j!=1)
            {
                f=0;
               break;
            }
        else f=1;
        }
        if(f==1){
         if(i>k){
                cout<<"\n";
                k+=10;
         }
        cout<<i<<" ";
        }
    }

    return 0;
}
