#include<iostream>
#include<cmath>
#include <math.h>
#include <iomanip>
#define Error 5  ////approximate error

using namespace std;

double percentageOfError(double x, double y);
void seidalMethod(double c11, double c12, double c13,double c21, double c22, double c23,double c31, double c32, double c33, double p,double q,double r);
double firstEquation(double c1, double c2, double c3, double y, double z, double p);
double secondEquation(double c21, double c22, double c23, double x, double z, double q);
double thirdEquation(double c31, double c32, double c33, double x, double y, double r);
string sP(double v);

int main(){
    
    double c11 = 0;double c12 = 0;double c13 = 0;
    
    double c21 = 0;double c22 = 0;double c23 = 0;
    
    double c31 = 0;double c32 = 0;double c33 = 0;
    
    double p = 0;double q = 0;double r = 0;
    
    cout<<"Enter First Equation: ";
    cout<<"C11: "; cin>>c11;
    cout<<endl<<"C12: "; cin>>c12;
    cout<<endl<<"C13: "; cin>>c13;
    cout<<endl<<"p "; cin>>p;
    
    cout<<"Enter Second Equation: ";
    cout<<"C21: "; cin>>c21;
    cout<<endl<<"C22: "; cin>>c22;
    cout<<endl<<"C23: "; cin>>c23;
    cout<<endl<<"q "; cin>>q;
    
    cout<<"Enter Third Equation: ";
    cout<<"C31: "; cin>>c31;
    cout<<endl<<"C32: "; cin>>c32;
    cout<<endl<<"C33: "; cin>>c33;
    cout<<endl<<"r "; cin>>r;
    
    // c11 = 3; c12 = -.1; c13 = -.2; p = 7.85; //Example from book
    // c21 = .1; c22 = 7; c23 = -0.30; q = -19.3;
    // c31 = .3; c32 = -0.2; c33 =10; r = 71.4;

    cout<<endl<<c11<<"x"<<sP(c12)<<c12<<"y"<<sP(c13)<<c13<<"z ="<<p<<endl;
    cout<<c21<<"x"<<sP(c22)<<c22<<"y"<<sP(c23)<<c23<<"z ="<<q<<endl;
    cout<<c31<<"x"<<sP(c32)<<c32<<"y"<<sP(c33)<<c33<<"z ="<<r<<endl<<endl;


    
    seidalMethod(c11,c12,c13,c21,c22,c23,c31,c32,c33,p,q,r);

    return 0;
}

string sP(double v){
    if (v>=0) return "+";
    else return "";
}


double firstEquation(double c1, double c2, double c3, double y, double z, double p){
    c2 *= -1;c3 *= -1;
    double x = (p+(c2*y)+(c3*z))/c1;
    return x;

}
double secondEquation(double c21, double c22, double c23, double x, double z, double q){
    c21 *= -1;;c23 *= -1;
    double y = (q+(c21*x)+(c23*z))/c22;
    return y;

}
double thirdEquation(double c31, double c32, double c33, double x, double y, double r){

    c31 *= -1;c32 *= -1;
    double z = (r+(c31*x)+(c32*y))/c33;
    return z;

}



void seidalMethod(double c11, double c12, double c13,double c21, double c22, double c23,double c31, double c32, double c33, double p,double q,double r){
    double x = 0;
    double y = 0;
    double z = 0;
    
    double error01 = 100;
    double error02 = 100;
    double error03 = 100;
    int i = 1;
    
    
    cout<<"Iteration no: "<<i++<<endl;
    cout<<"   Value   "<<"    Error(%)"<<endl;
    double value1 = firstEquation(c11,c12,c13,y,z,p);
    
    double value2 = secondEquation(c21,c22,c23,value1,z,q);
    
    double value3 = thirdEquation(c31,c32,c33,value1,value2,r);

    
    error01 = percentageOfError(x,value1);
    
    error02 = percentageOfError(y,value2);
    
    error03 = percentageOfError(z,value3);
    
    swap(x,value1);swap(y,value2);swap(z,value3);
    
    cout<<"x: "<<setprecision(6)<<x<<"  "<<setprecision(6)<<error01<<"%"<<endl<<"y: "<<setprecision(6)<< y<<"  "<<setprecision(6)<<error02<<"%"<<endl<<"z: "<<setprecision(6)<<z<<" "<<setprecision(6)<<error03<<"%"<<endl<<endl;
    
    double error = (error01+error02+error03)/3;
    
    while ( error01>Error || error02>Error || error03>Error){
        cout<<endl<<"Iteration no: "<<i++<<endl;
        cout<<"   Value   "<<"    Error(%)"<<endl;
        value1 = firstEquation(c11,c12,c13,y,z,p);

        value2 = secondEquation(c21,c22,c23,value1,z,q);
    
        value3 = thirdEquation(c31,c32,c33,value1,value2,r);
        
        error01 = percentageOfError(x,value1);
        
        error02 = percentageOfError(y,value2);
        
        error03 = percentageOfError(z,value3);
        
        error = (error01+error02+error03)/3;
        cout<<"x: "<<setprecision(6)<<value1<<"  "<<setprecision(6)<<error01<<"%"<<endl<<"y: "<<setprecision(6)<< value2<<"  "<<setprecision(6)<<error02<<"%"<<endl<<"z: "<<setprecision(6)<<value3<<" "<<setprecision(6)<<error03<<"%"<<endl<<endl;
        
        swap(x,value1);swap(y,value2);swap(z,value3);
    }

}



double percentageOfError(double x, double y){
  double result = 0;
  
  result = abs((y-x)/y)*100;
  return result;
}