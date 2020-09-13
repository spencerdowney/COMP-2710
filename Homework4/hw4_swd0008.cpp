#include <fstream>
#include <iostream>
#include <cstdlib>
using namespace std; 
 
const int MAX_SIZE = 100; 

//Spencer Downey
//swd0008
//hw4_swd0008.cpp
//This program reads files and sorts their contents.
//I recieved no help at all.

int readfile(int inputArray[], ifstream& instream);
int sort (int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]);
void writefile (int outputArray[], int outputArray_size);

int main () {

   ifstream instream1;
   ifstream instream2;

   int iArray1[MAX_SIZE];
   int array1_size;
   int iArray2[MAX_SIZE];
   int array2_size;
   int outArray[MAX_SIZE];
   int outArray_size;

   string filename1, filename2;

   cout << "*** Welcome to Spencer Downey's sorting program ***" << endl;
   cout << "Enter the first input file name: ";
   cin >> filename1;

   instream1.open((char *) filename1.c_str()); 
   array1_size = readfile(iArray1, instream1);
   cout << "The list of " << array1_size << " numbers in file " << filename1 << " is: " << endl;
   for (int i = 0; i <= array1_size; i++) {
	cout << iArray1[i] << "\n";
   }
   instream1.close();

   cout << "\nEnter the second input file name: ";
   cin >> filename2;
   instream2.open((char *) filename2.c_str()); 
   array2_size = readfile(iArray2, instream2);
   cout << "The list of " << array2_size << " numbers in file " << filename2 << " is: " << endl;
   for (int j = 0; j <= array2_size; j++) {
	cout << iArray2[j] << "\n";
   }
   instream2.close();

   outArray_size = sort(iArray1, array1_size, iArray2, array2_size, outArray);
   cout << "The sorted list of " << outArray_size << " numbers is: ";
   for (int k = 0; k < outArray_size; k++) {
	cout << outArray[k] << " ";
   }
   cout << endl;
   writefile(outArray, outArray_size);

   return 0;
}

//Reads the file.
int readfile(int inputArray[], ifstream& inStream) {

   if (! inStream)
   {
	cout << "Cannot open file.\n";
	exit(1);
   }

   int index = 0;
   inStream >> inputArray[index];
   while (! inStream.eof()) {
	index++;
	inStream >> inputArray[index];
   }
   return index;
}

//Sorts what is in the files.
int sort (int inputArray1[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {
   int i = 0, j = 0, n = 0, k = 0;

   while (i < inputArray1_size && j < inputArray2_size) {
         if (inputArray1[i] <= inputArray2[j]) {
             outputArray[k] = inputArray1[i];
             i++;
         }
         else {
             outputArray[k] = inputArray2[j];
             j++;
         }
         k++;
   }
   if (i < inputArray1_size ) {
      for ( n = i; n <= inputArray1_size; n++) {
          outputArray[k] = inputArray1[n];
          k++;
      }
   }
   if (j < inputArray2_size) {
      for ( n = j; n <= inputArray2_size; n++) {
          outputArray[k] = inputArray2[n];
          k++;
      }
   }
   return k;
}

//Writes an output file.
void writefile (int outputArray[], int outputArray_size) {

   ofstream output;
   string filename = "output.txt";
   output.open((char *) filename.c_str());
   for (int i = 0; i < outputArray_size; i++) {
	output << outputArray[i] << "\n";
   }
   output.close();
}