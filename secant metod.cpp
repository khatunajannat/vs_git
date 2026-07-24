
#include<bits/stdc++.h>
using namespace std;

double func(double x){

return x*x*x-2*x+3;

}


int main(){

double x0, x1, e;
cout<< " Take two guesses : " << endl;
cout<< " x0: " << endl;
cin>>x0;
cout<< "x1:  "<< endl;
cin>> x1;

cout << "enter the tolerant error: ";
cin >>e;

double x2;
int step = 0;

do{

 double fx0= func(x0);
 double fx1 = func(x1);

 if(fx1- fx0==0){

    cout<< "Mathematical error "<< endl;
    return 0;
 }


 x2= x1-(func(x1)*(x1-x0)/(func(x1)-func(x0)));

 x0=x1;
 x1=x2;
 step++;
 cout<< "Iteration: "<<step <<",x: " << x2 <<", f(x): "<<func(x2)<< endl;


}while(fabs(func(x2))>e); // relative  error 
///normally we could do it passing only x2 in there and if we are told to do it with absolute error it would've been x2-x1 

cout<< "\n Root is: " << x2 << endl;

return 0;

}






