#include<bits/stdc++.h>
using namespace std;

double func(double x)
{

    double sum = sqrt(x+1)-x-0.5;
    return sum;
}


int main()
{
    cout <<fixed<< setprecision(6);
    int iter=0;
    double x;
    double a,b;
    cin>>a >>b ;
    cout<<"========================================================================================================================="<<endl;
    cout<<"No|      a|      b|      f(a)|      f(b)|      x0|      f(x0)|      sign|      Interval|        update   " << endl;
    cout<<"========================================================================================================================="<<endl;
    if(func(a)*func(b)>0)
    {

        cout <<"you wanting me tonight is impossible!!!!!" <<endl;

    }
    else
    {

        double curr_root;
        double prev_root=a;
        double err=100;


        while(err>0.00001)
        {
            double tempA=a;
            double tempB=b;
            double interval= abs(tempA-tempB);
            iter++;
            string update;
            x=(a+b)/2;
            char sign;
            if(func(x)>0)
            {
                sign ='+';

            }
            else
            {
                sign ='-' ;
            }

            if(func(a)*func(x)<0)
            {
                b=x;
                update="upper";

            }
            else if(func(b)*func(x)<0)
            {
                a=x;
                update="Lower";

            }
            else
            {

                cout<<"Exact root found " << endl;

            }
            prev_root = curr_root;
            curr_root= x;
            err = abs(curr_root-prev_root);
            //err= abs(curr_root-prev_root)/curr_root;
           // cout<<"\nError: " << err << endl;
            printf("%2d|  %0.6f|  %0.6f|  %0.6f|  %0.6f|   %0.6f|   %0.6f|   %c|   %0.6f|   %s| \n ", iter, tempA, tempB, func(tempA),func(tempB),x,func(x),sign,interval,update.c_str() );

        }

        cout << "Root is: " << x << endl;

    }
    return 0;
}





