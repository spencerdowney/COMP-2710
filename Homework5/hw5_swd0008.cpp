# include <iostream>
# include <cstring>
# include <assert.h>
# include <cstdlib>
using namespace std;

//Spencer Downey
//swd0008
//hw5_swd0008.cpp
//This program reads files and sorts their contents.
//I recieved no help at all.

/**
 * Comment this line to enable production version of code!
 **/
//#define UNIT_TESTING

//Creates a TriviaNode strucure containing info aout a single question and a pointer o other trivia node.
struct triviaNode {
    string question,answer;
    int points;
    triviaNode *next;
};

class triviaList{
     public:
    int count;
    triviaNode *head, *root;
    triviaList() {
      count = 0;
      head = NULL;
      root = NULL;
    }
};

//Initilizes the trivia questions.
void initializeList(triviaList &list) {
    triviaNode *q1 = new triviaNode;
    triviaNode *q2 = new triviaNode;
    triviaNode *q3 = new triviaNode;

//Trivia Question 1
    q1 -> question = "How long was the shortest war on record? (Hint: how many minutes)";
    q1 -> answer = "38";
    q1 -> points = 100;
    q1 -> next = q2;

//Trivia Question 2
    q2 -> question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    q2 -> answer = "Bank of Italy";
    q2 -> points = 50;
    q2 -> next = q3;

//Trivia Question 3
    q3 -> question = "What is the best-selling video game of all time? (Hint: Minecraft or Tetris)";
    q3 -> answer = "Tetris";
    q3 -> points = 20;
    q3 -> next = NULL;     

    list.head = q1;
    list.root = q3;
    list.count += 3;
}

//Function used to prompt the user to create a new question
void addNode(triviaList &list){
    string response;
    do {
	list.count++; //increases the number of questions
	triviaNode *temp = new triviaNode;

	//prompts the user to enter a question
	cout << "Enter a question: ";
	getline(cin, temp -> question);

	//prompts the user to enter an answer
	cout << "Enter an answer: ";
	getline(cin, temp -> answer);

	//prompts the user to enter the number of points
	cout << "Enter award points: ";
	cin >> temp -> points;

	//prompts the user to continue
	cout << "Continue? (Yes/No): ";
	getline(cin.ignore(), response);
    
    //adds new trivia to list
        list.root -> next = temp;
        list.root = temp;
        
 } while (response != "No");
}

//Function to ask the user a question.
int askQuestion(triviaList list, int count, int &bonus) {
    triviaNode *q = list.head;

 //parameter checking 

    if (count < 1) { // checks if the number of trivia questions is equal to zero
        cout << "\nWarning - The number of trivia to be asked must equal to or be larger than 1.";
        return 1;
    }
    if (count > list.count) { //checks if the number of trivia questions exceeds the number of questions in the list
        cout << "\nWarning - There are only " << list.count << " trivia in the list";
        count = list.count;
        return 0;
    }
    string ans;
    bonus = 0;

    for (int j = 0; j < count; j++) {
        cout << "\nQuestion: " << q -> question << "\nAnswer: ";
        getline(cin, ans);

        if (q -> answer == ans) {
            cout << "Your answer is correct. You receive " << q -> points << " points.";
            bonus += q -> points; //adds points to total point value   
        }    
        else {
            cout << "Your answer is wrong. The correct answer is: " << q -> answer;
        }
        cout << "\nYour Total Points: " << bonus << endl; 
        q = q -> next;
    }
    return 0; 
}

//Teting for the askQuestion method.
void test_askQuestion()
{
	// Initialize test fixtures
	triviaList tL;
    int bonus;
	
	// Setup Trivia list
	initializeList(tL);

	cout << "\nFunction to test: int askQuestion(triviaList& tL, int count, int &bonus)\n";

	// Case 1
	cout << "Unit Test Case 1: Ask no questions. The program should give a warning message.";
	assert(1 == askQuestion(tL, 0, bonus));
	cout << "\n";

	// Case 2.1
	cout << "\nUnit Test Case 2.1: Ask 1 question in the linked list. The tester enters a correct answer.";
	assert(0 == askQuestion(tL, 1, bonus));
	assert(100 == bonus);
	cout << "Case 2.1 passed...\n";

        // Case 2.2
	cout << "\nUnit Test Case 2.2: Ask 1 question in the linked list. The tester enters an incorrect answer.";
	assert(0 == askQuestion(tL, 1, bonus));
	assert(0 == bonus);
	cout << "Case 2.2 passed...\n";


	// Case 3.1
	cout << "\nUnit Test Case 3.1: Ask all of the questions in the linked list. The tester enters the correct answers.";
	assert(0 == askQuestion(tL, 3, bonus));
	// cover all possible scores
	assert(170 == bonus);
	cout << "Case 3.1 passed...\n";

        // Case 3.2
	cout << "\nUnit Test Case 3.2: Ask all of the questions in the linked list. The tester enters the incorrect answers.";
	assert(0 == askQuestion(tL, 3, bonus));
	// cover all possible scores
	assert(0 == bonus);
	cout << "Case 3.2 passed...\n";

	// Case 4
	cout << "\nUnit Test Case 4: Attempt to ask 5 questions in the linked list. Program should give a warning message.";
        assert (0 == askQuestion(tL, 5, bonus));
}


#ifdef UNIT_TESTING
	void test_askQuestion(void);
#endif

// main function
 int main() {
   //insert unit testing code
     #ifdef UNIT_TESTING
	cout << "*** This is a debug version ***\n";
	test_askQuestion();
	cout << "\n*** End of the Debug Version ***\n";

 //insert production code   
    #else
    cout << "*** Welcome to Spencer's trivia quiz game ***" << endl;
    triviaList game;
    int bonus;
    initializeList(game);
    addNode(game);
    
    askQuestion(game, game.count, bonus);

    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
    
    #endif
    return 0;
 }