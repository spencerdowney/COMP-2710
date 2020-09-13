#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include<ctime>
using namespace std;

//Spencer Downey
//swd0008
//hw3_swd0008.cpp
//This program determines the probability of each person winning a duel.
//I recieved no help at all.

const double A_AVG = 33;
const double B_AVG = 50;
const double NUM_DUELS = 10000;
const double PERCENT = 100;

/* Input: A_alive indicates whether Aaron is alive */
/* B_alive indicates whether Bob is alive */
/* C_alive indicates whether Charlie is alive */
/* Return: true if at least two are alive */
/* otherwise return false */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   return (A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive);
}

/*Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   double shoot = rand()%100;
   if (shoot <= A_AVG) {
	if (C_alive) {
	   C_alive = false;
	}
	else {
	   B_alive = false;
	}
   }
}

/* Return: Change A_alive into false if Aaron is killed.
* Change C_alive into false if Charlie is killed.
*/
void Bob_shoots(bool& A_alive, bool& C_alive) {
   double shoot = rand()%100;
   if (shoot <= B_AVG) {
	if (C_alive) {
	   C_alive = false;
	}
	else {
	   A_alive = false;
	}
   }
}

/* Return: Change A_alive into false if Aaron is killed.
* Change B_alive into false if Bob is killed.
*/
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   if (B_alive) {
	B_alive = false;
   }
   else {
	A_alive = false;
   }	
}

/* Return: Change B_alive into false if Bob is killed.
* Change C_alive into false if Charlie is killed.
*/
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   if (B_alive && C_alive) {
	return;
   }
   double shoot = rand()%100;
   if (shoot <= A_AVG) {
	if (C_alive) {
	   C_alive = false;
	}
	else {
	   B_alive = false;
	}
   }
}

//Test case to make sure at least two are alive.
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";

   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n";
}

//Press enter function.
void press_enter() {
   cout << "Press Enter to continue...";
   cin.get(); //Pause Command for Linux Terminal
}

//Main function.
int main() {
   int awins = 0, bwins = 0, cwins = 0;
   srand(time(0));

   cout << "*** Welcome to the Duel Simulator ***\n";
   test_at_least_two_alive();
   press_enter();
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   press_enter();

//Runs strategy 1.
   for (int i = 0; i < 10000; i++) {
        bool Aaron = true;
	bool Bob = true;
	bool Charlie = true;

	while (at_least_two_alive(Aaron, Bob, Charlie)) {
	   if (Aaron) {
		Aaron_shoots1(Bob, Charlie);
	   }
	   if (Bob) {
		Bob_shoots(Aaron, Charlie);
	   }
	   if (Charlie) {
		Charlie_shoots(Aaron, Bob);
	   }
	}
	if (Aaron) {
	   awins++;
	}
	if (Bob) {
	   bwins++;
	}
	if (Charlie) {
	   cwins++;
	}
        Aaron = true;
	Bob = true;
	Charlie = true;
   }
   cout << "Aaron won " << awins << " / 10000 duels or " << (awins / NUM_DUELS) * PERCENT << "%\n";
   cout << "Bob won " << bwins << " / 10000 duels or " << (bwins / NUM_DUELS) * PERCENT << "%\n";
   cout << "Charlie won " << cwins << " / 10000 duels or " << (cwins / NUM_DUELS) * PERCENT << "%" << endl;

   cout << "\nReady to test strategy 2 (run 10000 times)" << endl;
   press_enter();
   double awins2 = 0, bwins2 = 0, cwins2 = 0;

//Runs strategy 2.
   for (int j = 0; j < 10000; j++) {
        bool Aaron = true;
	bool Bob = true;
	bool Charlie = true;

	while (at_least_two_alive(Aaron, Bob, Charlie)) {
	   if (Aaron) {
		Aaron_shoots2(Bob, Charlie);
	   }
	   if (Bob) {
		Bob_shoots(Aaron, Charlie);
	   }
	   if (Charlie) {
		Charlie_shoots(Aaron, Bob);
	   }
	}
	if (Aaron) {
	   awins2++;
	}
	if (Bob) {
	   bwins2++;
	}
	if (Charlie) {
	   cwins2++;
	}
	Aaron = true;
	Bob = true;
	Charlie = true;
   }
   cout << "Aaron won " << awins2 << " / 10000 duels or " << (awins2 / 10000) * 100 << "%\n";
   cout << "Bob won " << bwins2 << " / 10000 duels or " << (bwins2 / 10000) * 100 << "%\n";
   cout << "Charlie won " << cwins2 << " / 10000 duels or " << (cwins2 / 10000) * 100 << "%" << endl;

   if (awins > awins2) {
	cout << "\nStrategy 1 is better than strategy 2.";
   }
   if (awins < awins2) {
	cout << "\nStrategy 2 is better than strategy 1.\n";
   }

   return 0;
}

