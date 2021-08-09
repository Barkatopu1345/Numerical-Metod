#include<iostream>
#include <math.h>
#include <iomanip>
#define Error 0.1  ////approximate error
#define Degree 0.0174533333333333  //// pi/180

using namespace  std;


double func(double x)
{
  return x- (1.2*sin(x*Degree)) - 0.5;   //degree convirting into radian
  //return (x*x*x)-(4*x)-9;
}


double firstDerivative(double x)
{
	//return 3*(x*x)-4;
  return 1+(1.2*cos(x*Degree));   //degree convirting into radian
}


double percentageOfError(double x, double y){
  double result = 0;
  result = abs((y-x)/y)*100;
  return result;
}


void newtonRaphsonMethod(double initial){
  double error = 0;
  int i = 1;
  cout<<endl<<"No.      "<<"      Result      "<<"      Percentage of error(%)     "<<endl<<endl;

  double result = initial - (func(initial)/firstDerivative(initial));
  error = percentageOfError( error, result);
  cout<<i<<"            "<<setprecision(10)<< result;
  
  cout<<"            "<<setprecision(10)<< error<<"%     "<<endl<<endl;
  
  
  
  while (error>=Error)
  {
    initial = result;


    result = result - (func(result)/firstDerivative(result));
    
    error = percentageOfError( initial, result);
    

    
    cout<<++i<<"            "<<setprecision(10)<< result;
  
    cout<<"            "<<setprecision(10)<< error<<"%     "<<endl<<endl;
  }
  

    cout<<"The root is: "<<result<<endl;
  
  

}
int main(){
  double initial = 00.0;
  cout<<"Enter the initial value: ";
  cin>>initial;
  cout<<endl<<"The equation is: x- 1.2*sin(x) - 0.5"<<endl;
  cout<<"The first derivative of the equation is: 1+1.2*cos(x)"<<endl;
  cout<<"The initial value is: 00.00"<<endl;
  cout<<"The Condition of stoping iteration is: Percentage of error<0.1"<<endl;
  newtonRaphsonMethod(initial);
}