using namespace std;
#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm> //to find max value in error list Prob C)

//for PROBLEM B)
void initialize(int, double *, double *,double *);
void solve_matrix(int, double *, double *);
void write_out(int,double *, double *, double *);
//for PROBLEM C)
void relative_error(int,double *,double *);

int main()
{

    // PROBLEM B)
    int n = 100000;
    // making pointers
    double *u;
    double *x;double *f;double *u_closed_form;
    // giving size to the arrays
    f = new double[n];u_closed_form = new double[n];x=new double[n];u = new double[n];
    // initializing vectors
    initialize(n,f,u_closed_form,x);

    // solving the matrix
    solve_matrix(n, u,f);
    // writing out the results to files so that we can plot them later
    write_out(n,x,u,u_closed_form);

    // PROBLEM C)

    relative_error(n,u_closed_form,u);


    return 0;
}


void initialize(int n_,double *f_, double *u_closed_form_,double *x_){
    double h = 1./(n_+1);
    for(int i=0;i<n_;i++){
        f_[i]=100.*exp(-10.*i*h)*h*h;
        u_closed_form_[i]=1-(1-exp(-10))*h*i-exp(-10*h*i);
        x_[i]=i*h;
    }
}

void solve_matrix(int n_,double *u_,double *f_){

    // definining needed variables
    double b[n_];
   // b = double[n_];
    double btemp=2;double ctemp=-1./btemp;double ftemp=f_[0]/btemp;
    b[0]=2;

    for(int i=1;i<n_;i++){
        b[i]=2+ctemp;
        f_[i]+=ftemp;
        btemp=b[i];
        ctemp=-1/btemp;ftemp=f_[i]/btemp;
    }

    u_[n_-1]=(f_[n_-1]/b[n_-1]);
    for(int i=n_-2;i>-1;i--){
        u_[i]=(f_[i]+u_[i+1])/b[i];
    }
}


void write_out(int n_,double *x_,double *u_,double *u_closed_form_){

    //writing it all out to a file:

    ofstream outputFile1 ("data1.dat");
    ofstream outputFile2 ("data2.dat");
    for(int i=0;i<n_;i++){
        outputFile1 <<x_[i]<<' '<<u_[i]<<endl;
        outputFile2 <<x_[i]<<' '<<u_closed_form_[i]<<endl;
    }

    outputFile1.close();
    outputFile2.close();
}


void relative_error(int n_,double *u_closed_form_, double *u_){

    double errors[n_];
    for(int i=1;i<n_;i++){
        errors[i]=abs((u_[i]-u_closed_form_[i])/u_closed_form_[i]);
        //cout<<errors[i];

    }
    double max=*std::max_element(errors,errors+n_);
    cout << "problem C) for N="<<n_<<" the relative error is: "<< max<<endl;

}


