#include<bits/stdc++.h>
using namespace std;
#define Error 0.01
#define MAX_ITER 1000000
#define Degree 0.0174533333333333  //// pi/180

 
// An example function whose solution is determined using
// Bisection Method. The function is x^3 - x^2  + 2
double func(double x)
{
    //return x*x*x - x*x + 2;
    //return (x*x*x)-(4*x)-9;
    return x- (1.2*sin(x*Degree)) - 0.5;   

}
double percentageOfError(double x, double y){
    double result = 0;
    result = abs((y-x)/y)*100;
    return result;
}
// Prints root of func(x) in interval [a, b]
void regulaFalsi(double a, double b)
{
    double error = 100;
    int i = 0;
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }
 
    double c = a;  // Initialize result
    
    while(error>Error)
    {
        // Find the point that touches x axis
        c = (a*func(b) - b*func(a))/ (func(b) - func(a));
 
        // Check if the above found point is root
        if (func(c)==0)
            break;
 
        // Decide the side to repeat the steps
        else if (func(c)*func(a) < 0){
            error = percentageOfError(b,c);
            b = c;
        }
        else{
            error = percentageOfError(a,c);
            a = c;
        }
        cout<<++i<<"        "<<c<<"        "<<error<<endl;
    }
    cout << c;
}
 
// Driver program to test above function
int main()
{
    // Initial values assumed
    double a =1, b = -3;
    regulaFalsi(a, b);
    return 0;
}