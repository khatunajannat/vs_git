
#include<bits/stdc++.h>
using namespace std;

double func(double x){
//the function or the main equation 
return 2*pow(x,4)-3*pow(x,3)+3*x -5;
}


double f_der(double x){
//first order derivative of the function
return 8*pow(x,3)-9*pow(x,2)+3;
}


int main(){

double xo, e; //initial guess and tolarable error
cout<<"Enter estimated guess : " << endl;
cin>>xo;
cout<<"Enter the tolerable error: " << endl;
cin>> e;

//taking the variables to store the value of the executed functions of newton raphson main equation 
double x1, f1;
int step=0; // iteration tracking 

do{

if(f_der == 0 ){

    cout<<"Mathematical error : derivative is zero " << endl;
    return 0;

}
    x1= xo-func(xo)/f_der(xo);
    xo= x1;
    f1 = func(x1);
    step++;// tracking iteration 

    cout<< "Iteration "<< step << ":  x: "<<x1<<", f(x) : "<<f1 << endl;

}while(fabs(f1)>e); // the loop will execute untill the condition is fulfilled 

cout<<"\n root: " << endl;   // printing the root
return 0;

}

