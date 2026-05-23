#include "bigint.hpp"
#include <iostream>
#include <cassert>

void bigint::initialize() {
  for (int i = 0; i < CAPACITY; ++i) {
    numArray[i] = 0;
  }
}

bigint::bigint() {
  initialize();
}

bigint::bigint(int numbers) {
	initialize();
  int i = 0;
	while (numbers > 0) {
		numArray[i] = numbers % 10;
		numbers = numbers / 10;
		i++;
	}
}
// I'm going to use two different methods of adding comments and I hope you can tell me your preference.

// Takes a char array and converts it into bigint.
bigint::bigint(const char characters[]) {
	initialize(); // Initalizes an array to 0.
	int length =0; // Used to find the length of the char array without leading 0s.
	int temp=0; // Used to track position in number array.
	while (characters[length]!='\0') // Runs until the end of the array "characters".
		length++; // Increases Length for the previously stated reason.
	for (int i=length-1;i>=0;i--) // Uses the length from the previous while loop to start at the back of the char array and move towards the front.
		if(temp<CAPACITY) // Makes sure that there is no out of bounds in num array.
		{
			numArray[temp]=characters[i]-'0'; // converts the char into an int.
			temp++; // moves to the next array index.
		}
}

// Used to print the internal state of bigint for debugging purposes.
void bigint::debugPrint(std::ostream& out) const {
	// Prints the numArray with a '|' between each index.
	for (int i = CAPACITY - 1; i >= 0; i--) 
		out << numArray[i] << '|';
}

// Used to print bigint to the output stream.
std::ostream& operator<<(std::ostream& out, const bigint& obj) {
	int temp =0;
	int i = CAPACITY-1;
	// Skips any leading 0s.
	while (i>0&&obj.numArray[i]==0)
		i--;
	// Prints the number.
	while (i>=0)
	{
		out << obj.numArray[i];
		temp++;
		// Prints a new line for every 80 characters to remove line overflow.
		if (temp%80==0)
			out << "\n";
		i--;
	}
	return out;
}

// Used to read bigint from the input stream.
std::istream& operator>>(std::istream& in, bigint& obj) {
	char temp[CAPACITY];
	char temp2[CAPACITY] = {'\0',}; 
	int end=0;
	// Reads a line of the input and adds it to the next input until a semicolon is reached. Removes semicolon afterwards.
	while (in >> temp)
	{
		bool semiColon = false;
		int length=0;
		
		// Finds the length of the character array temp without having any 0s.
		while (temp[length]!='\0'&&length<CAPACITY-1) 
			length++;
		// adds temp 1 to temp 2 until a semicolon.
		for (int i=0;i<length;i++)
			 if (temp[i]==';') // removes semicolon and breaks loop.
			 {
				semiColon = true;
				temp[i]='\0';
				break;
			 }
			 else
			 	temp2[end++]=temp[i];
		if (semiColon)
			break;
	}
	obj = bigint(temp2);
	return in;
}

// Compares two bigints for equality.
bool bigint::operator==(const bigint& obj) {
	// Compares each index of both numArrays.
	for (int i=0;i<CAPACITY;i++)
		if (numArray[i]!=obj.numArray[i])
			return false;
	return true;
}

// Adds tw bigints together.
bigint bigint::operator+(bigint obj) const {
	bigint temp;
	int carry=0;
	// Adds each index of the numArrays together and carrys over extra digits.
	for (int i=0;i<CAPACITY;i++)
	{
		temp.numArray[i]=(numArray[i]+obj.numArray[i]+carry)%10;
		carry =(numArray[i]+obj.numArray[i]+carry)/10;
	}
	return temp;
}

// Multipliees the bigint by a digit. (Not full proof, negitives are read)
bigint bigint::timesDigit(int x) const {
	// Returns 0 if out of bounds.
	if (x<0||x>9) 
		return bigint();
	bigint temp;
	int carry=0;
	// Multiplies the index of numArray by the digit and carrys over extra digits.
	for (int i=0;i<CAPACITY;i++)
	{
		temp.numArray[i]=(numArray[i]*x+carry)%10;
		carry =(numArray[i]*x+carry)/10;
	}
	return temp;
}

// Multiplies the bigint by 10^x.
bigint bigint::times10(int x) const {
	// Returns 0 if out of bounds.
	if (x<0||x>CAPACITY) 
		return bigint();
	bigint temp;
	// Shifts the numArray "x" places to the left.
	for (int i=CAPACITY-x-1;i>=0;i--)
		temp.numArray[i+x]=numArray[i];
	return temp;
}

// Multiplies two bigints.
bigint bigint::operator*(bigint obj) const{
	bigint temp;
	// Uses timessDigit to gain the answer to multiplication. Then it uses times10 to shift the number to the correct place value. Afterwards it adds temp to the sum to prevent data loss from the previous iteration.
	for (int i=0;i<CAPACITY;i++)
		temp = temp+(timesDigit(obj.numArray[i]).times10(i));
	return temp;
}

// Accesses the index given in numArray.
int bigint::operator[](int i) const {
	// Returns 0 if out of bounds.
	if (i<0||i>CAPACITY-1) 
		return 0; 
	return numArray[i];
}

bigint bigint::factorial(int x)
{
	bigint obj(1);
	for (int i=1;i<x;i++)
		obj = obj+(obj*(i));
	return obj;
} 