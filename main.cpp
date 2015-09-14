using namespace std;
#include <iostream>
#include <cmath>
#include <fstream>
int main()
{   int i;
    int n = 10;
    double h = 1./(n+1);


    double *x;double *f;double *u_closed_form;
    f = new double[n];u_closed_form = new double[n];x=new double[n];
    for(i=0;i<n;i++){
        f[i]=100.*exp(-10.*i*h)*h*h;
        u_closed_form[i]=1-(1-exp(-10))*h*i-exp(-10*h*i);
        x[i]=i*h;
    }
    double * b;
    b = new double[n];
    //for(i=0;i<n;i++){*(b+i)=2;}

    //

    double btemp=2;double ctemp=-1./btemp;double ftemp=f[0]/btemp;
    b[0]=2;
    for(i=1;i<n;i++){
        b[i]=2+ctemp;
        f[i]+=ftemp;
        btemp=b[i];
        ctemp=-1/btemp;ftemp=f[i]/btemp;
    }
    double *u;
    u = new double[n];
    u[n-1]=(f[n-1]/b[n-1]);
    for(i=n-2;i>-1;i--){
        u[i]=(f[i]+u[i+1])/b[i];
    }
    //writing it all out to a file:

    ofstream outputFile1 ("data1.dat");
    ofstream outputFile2 ("data2.dat");
    for(i=0;i<n;i++){
        outputFile1 <<x[i]<<' '<<u[i]<<' '<<u_closed_form[i]<<endl;
        outputFile2 <<x[i]<<' '<<u_closed_form[i]<<endl;
    }

    outputFile1.close();
    outputFile2.close();
    return 0;
}

