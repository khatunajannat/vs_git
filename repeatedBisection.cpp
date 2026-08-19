#include<bits/stdc++.h>
using namespace std;
// function x^4+4x^3-7X^2-22X+24
vector<int> coeff= {1,4,-7,-22,24};

double func(double x)
{

    double result =0;
    for(int i=0; i<coeff.size(); i++)
    {

        result = result*x +coeff[i];
    }
    return result;
}

int main()
{

    double a=-8, b=8;
    double x1, x2,x0, error, tolErr=0.00001,ds=0.1,prev_root;
    x1=a;
    x2=x1+ds;

    while(x2<=b)
    {
        error =100;
        prev_root=x1;
        if(func(x1)*func(x2)<0)
        {
            while(error>tolErr)
            {

                x0= (x1+x2)/2 ;

                double fx0= func(x0);
                double fx1=func(x1);
                double fx2= func(x2);

                error = abs(x0-prev_root);
                if(fx0==0)
                {

                    cout<<"Root found"<< endl;
                    break;
                }
                else if(fx0*fx1<0)
                {

                    x2=x0;

                }
                else
                {
                    x1=x0;
                }
                prev_root =x0;
            }
            cout<< "root is :  "<<x0 << endl;

        }

        x1=x2;
        x2= x1+ds;

    }
    return 0;
}
