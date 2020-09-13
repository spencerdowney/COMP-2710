#include <iostream>
#include <cmath>
using namespace std;

float calculateSD(float data[], int n);
int factorial(int n);
int main()
{
    //Variables;
    int i, n = 99; 

    while (n == 99) {
        cout << endl << "How many positive numbers (must be less than 10) do you want to calculate: ";
        cin >> n;

        if ((n > 10) || (n < 0)) {
	    cout << endl << "Invalid number.";
	    n = 99;
        }
    }
   
    float data[n]; 
    cout << endl << "Please enter " << n << " elements: ";
    for (i = 0; i < n; ++i) {
	cin >> data[i];
    }
    
    //Prints out stadard deviation;
    cout << endl << "Standard Deviation = "<< calculateSD(data, n);
  
    //Prints out the factorial;
    cout << endl << "\nFactorial of "<<n<<" = "<< factorial(n);
    cout << endl;

    return 0;
}

int factorial(int n) {
    int factorial = 1;
    int i;
    for (i = 1; i <= n; ++i) {
	factorial *= i;
    }
    return factorial;
}

float calculateSD(float data[], int n) 
{
   float sum = 0.0, mean, standardDeviation = 0.0;
   
   int i;

   for (i = 0; i < n; ++i) {
	sum += data[i];
   }

   mean = sum/n;

   for (i = 0; i < n; ++i) {
	standardDeviation += pow(data[i] - mean, 2);
   }

   return sqrt(standardDeviation / n);
}
