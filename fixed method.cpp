
#include<bits/stdc++.h>
using namespace std;

double func(double x){

return  x*x -5*x;

}

double g(double x){
return sqrt(5*x);

}


int main(){

double x0,e,n;

cout<<"enter a guess : " << endl;
cin>> x0;
cout<< "Enter step u wanna count for: "<<endl;
cin>>n;
cout << " enter a tolerant error:  "<< endl;
cin>> e;


double x1;
int step =0 ;
do{

 x1= g(x0);

 if(step>n){
cout<<"not in convergence !!! "<<endl;
return 0;

 }

    x0= x1;
    step++;

cout<<"iteration: "<<step << " ,x: "<< x1<< " ,f(x): "<<func(x1)<<endl;
}while(fabs(func(x1))>e);

cout<<"\n root is: " << x1<<endl;
return 0;

}
