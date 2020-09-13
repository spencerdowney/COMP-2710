#include <iostream>
#include <cmath>
using namespace std;

float calculateSD(float data[], int n);
int main()
{
    //Variables;
    int i, n, factorial = 1;
    float data[n]; 

    cout << "How many positive numbers (must be less than 10) do you want to calculate: ";
    cin >> n;
   
    cout << "Please enter "<<n<<" elements: ";
    for (i = 0; i < n; ++i) {
	cin >> data[i];
    }
    cout << endl;
    
    //Prints out stadard deviation;
    cout << "Standard Deviation = "<< calculateSD(data, n);
    cout << endl;

    //Math for factorial;
    for (i = 1; i <= n; ++i) {
	factorial *= i; // factorial = factorial * i;
    }
  
    //Prints out the factorial;
    cout << "\nFactorial of "<<n<<" = "<< factorial;
    cout << endl;

    return 0;
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
