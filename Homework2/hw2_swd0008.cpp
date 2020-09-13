#include <iostream>
using namespace std;

//Spencer Downey
//swd0008
//hw2_swd0008.cpp
//This program calculates how long it takes to pay off a loan and the total interest paid.
//I recieved no help at all.

float calculate(float balance, float rate, float monthRate, float payment);
int main() {

   float balance, yearRate, payment;
   bool x = true;
   while (x) {
   	cout << "Loan Amount: ";
   	cin >> balance;

   	cout << "Interest Rate (" << "%" << " per year) : ";
   	cin >> yearRate;
   
   	cout << "Monthly Payments: ";
   	cin >> payment;

        if ((balance * ((yearRate/12)/100)) > payment) {
	   cout << "Invalid input."<<endl;
	}
	else {
	   x = false;
	}
   }
   cout.precision(2);
   float monthRate = (yearRate/12);
   float rate = monthRate / 100;

   cout << "******************************************************" << endl;
   cout << "         Amortization Table" << endl;
   cout << "******************************************************" << endl;
   cout << "Month   Balance  Payment Rate   Interest Principal"<< endl; 
   cout << "0\t$"<<fixed<<balance<<"  N/A\tN/A\tN/A\tN/A"<<endl;
   calculate(balance, rate, monthRate, payment);
    
}

float calculate(float balance, float rate, float monthRate, float payment) {

   float interest, principal, intCounter = 0.0;
   int monthCounter = 0;
   for (int month = 1; balance > 0; month++) {
	monthCounter++;
	if (balance < payment) {
	   interest =rate * balance;
	   intCounter+= interest;
	   principal = balance;
	   payment = interest + principal;
	   balance -= balance;
	}

	if (balance >= payment) {
	   interest = rate * balance;
 	   intCounter += interest;
	   principal = payment - interest;
	   balance -= principal;
	}
	
	
	cout<<month<<"\t$"<<fixed<<balance<<" $"<<payment<<"\t";
	cout.precision(1);
	cout<<fixed<<monthRate;
	cout.precision(2);
	cout<<"\t$"<<fixed<<interest<<"\t$"<<principal<<endl;
   }
   cout << "******************************************************" << endl;
   cout << "\nIt takes "<<monthCounter<<" months to payoff the loan." <<endl;
   cout << "Total interest paid is: $" << intCounter <<endl;
}
