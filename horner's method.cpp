
#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout<<"Enter the number of polynomial degree: "<< endl;
    cin>> n;

    double coeff[n+1];

    cout<<"Enter coefficient  a "<< coeff[n+1] <<endl;
    for(int i=n; i>=0; i--)
    {

        cout<<"a"<< i <<" ="<<endl;
        cin>>coeff[i];
    }
  double result=coeff[n];
  double x;
  cout<<"enter value of x:  ";
  cin>>x;

  for(int i=n-1;i>=0;i--){

result= result*x +coeff[i];

cout<<"p:"<< i <<" result: "<<result<<endl;
  }

  cout<<"\n result:  "<< result<<endl;
return 0; 

}