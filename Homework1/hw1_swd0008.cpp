#include <iostream>
#include <cmath>
using namespace std;

//Spencer Downey
//swd0008
//hw1_swd0008.cpp
//This program calculates the fatal amount of diet coke
//I recieved no help at all
int main() {
    double FatalAmountMouse = -99, WeightHuman = -99, WeightMouse = -99;
    const double FractionOfSweetenerInCoke = 0.001;

    while (WeightMouse == -99) {
	cout << endl << "Please input the weight of the mouse in kg:\n";
	cin >> WeightMouse;
        if (WeightMouse <= 0) {
	    WeightMouse = -99;
	    cout << "Invalid Input.";
	}
    }
   
    while (FatalAmountMouse == -99) {
	cout << endl << "Please input the fatal amount of sweetener for mouse in kg:\n";
	cin >> FatalAmountMouse;
	if (FatalAmountMouse <= 0) {
	    FatalAmountMouse = -99;
	    cout << "Invalid Input";
	}
    }

    while (WeightHuman == -99) {
	cout << endl << "Please input the weight of your dear friend in kg:\n";
	cin >> WeightHuman;
	if (WeightHuman <= 0) {
	    WeightHuman = -99;
	    cout << "Invalid Input.";
	}	
    }

    double FatalAmountHuman = ((FatalAmountMouse * WeightHuman) / (WeightMouse * FractionOfSweetenerInCoke));
    
    cout << endl << "The fatal amount of Coke for your friend is: "<<FatalAmountHuman<<" kg\n";
}
