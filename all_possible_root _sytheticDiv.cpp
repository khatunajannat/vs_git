#include<bits/stdc++.h>
using namespace std;
//for x^4+4x^3-7x^2 -22X+24
double func(double *a, double x, int n){

double res=0;
for(int i=0; i<=n; i++){

    res = res*x+a[i];

}
return res;
}

double f_der(double *a,double x, int n){
 double res =0;
 for(int i=0; i<n;i++){

    res= res*x+(n-i)*a[i];

 }

return res;

}





int main(){

double a[10]={1,4,-7,-22,24};// this is the array for the co efficient
double x0= 2.5; // the first assumption because you are using newton raphson
double x1; // for updating purpose we are taking x1 where u will store the root coming from the new raphson formula
double error, tolErr=0.00001;
int degree=4;

 cout<<fixed<<setprecision(10);
while(degree>1){
    error = 100;
    while(error>tolErr){

        double fval=func(a,x0,degree);
        double dval = f_der(a,x0,degree);
        x1= x0- (fval/dval);
        error = fabs(x1-x0);
        x0=x1;

    }
    cout<< "\n Root : "<< x1<< endl;
    //synthetic division

   double b[10]={0};
   b[0]=a[0];
   for(int i=1; i<=degree; i++){

    b[i]= b[i-1]*x1+a[i];

   }
   degree--;// polynomial is now 1 degree smaller

   cout<< "polynomial coefficient for degree : " << degree << endl;
   for(int i=0; i<=degree; i++){
    cout<< b[i]<< endl;
    a[i]=b[i];

   }

   cout << endl;
}

  //once the degree is 1 , ax+b=0  directly get the root
   cout << "The root is : " <<  -a[1]/a[0];
return 0;
}
