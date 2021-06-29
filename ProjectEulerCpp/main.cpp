//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Project Euler problems solved with C++
//https://projecteuler.net
//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 1: Multiples of 3 and 5
// Sum up all multiples of 3 and 5 <1000
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//using namespace std;
//
//int main() {
//	int Summe = 0;
//	for (int i = 1; i < 1000; i++) {
//		if (i % 3 == 0 || i % 5 == 0) {
//			Summe += i;
//		}
//	}
//	cout << Summe << endl;
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 2: Even Fibonacci numbers
// Sum up all even Fibonacci numbers <= 4 000 000
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//using namespace std;
//
//int SumEvFib(int max) {
//	int Summe = 0;
//	int a = 1;
//	int b = 2;
//	int temp = 0;
//	while (b <= max) {
//		//cout << b << ", ";
//		if (b % 2 == 0) {
//			Summe += b;
//		}
//		temp = a + b;
//		a = b;
//		b = temp;
//	}
//	return Summe;
//}
//
//int main() {
//	cout << endl << SumEvFib(4000000)<<endl;
//return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 3: Largest prime factor of 600 851 475 143
// Find the largest prime factor of 600 851 475 143
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//#include<cmath>
//using namespace std;
//
//bool isPrime(int a) {                    //As long as the largest prime factor is not overly large, the use of int is sufficient here
//	for (int i = 2; i < int(sqrt(a)); i++) {
//		if (a % i == 0) {
//			return false;
//		}
//		return true;
//	}
//}
//
//long int LarPrFac(long long int b) {     //The long long int type has to be used for the function as well, since the initial number is so big
//	long long int i = 2;
//	while(i<b){
//		if (isPrime(i) && (b % i == 0)) {
//			b /= i;
//			i = 2;
//		}
//		else i++;
//	}
//	return b;
//}
//
//int main() {
//	long long int a = 600851475143;      //This number is so big, that the int and long int types are not enough to save it 
//	cout << LarPrFac(a)<<endl;
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 4: Largest palindrome product
// Find the largest palindrome (e.g. 91x99=9009) made from the product of two 3-digit numbers 
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<algorithm>
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//bool isPalin(int a) {
//	string temp = to_string(a);
//	string temp2 = temp;
//	reverse(temp.begin(), temp.end());
//	if (temp == temp2) {
//		return true;
//	}
//	else return false;
//}
//
//int LargPalin(int a) {
//	int max = 0;
//	for (int i = a; i > 0; i--) {
//		for (int j = a; j > 0; j--) {
//			if (isPalin(j * i) && j*i>max) {
//				max = j * i;
//			}
//		}
//	}
//	return max;
//}
//
//int main() {
//	/* //Test reverse int
//	int a = 9007;
//	string NR = to_string(a);
//	reverse(NR.begin(),NR.end());
//	cout << NR << endl;
//	*/
//	/* //Test isPalin
//	cout << isPalin(9009) << endl;
//	cout << isPalin(9007) << endl;
//	*/
//	cout << LargPalin(999);
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 5: Smallest multiple 
// Find the smallest number that is evenly divisible by all numbers from 1 to 20
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//using namespace std;
//
////Quite fast if not all numbers, but only the numbers divisible by a (the highest divisor) are checked :)
////This version worked here, but in python an elegant much faster alternative had to be found and was found.
//int EvDiv(int a) {
//	int i = a;
//	int counter = 0;
//	while (counter < a) {
//		counter = 0;
//		for (int j = 1; j <= a; j++) {
//			if (i % j == 0) {
//				counter++;
//			}
//		}
//		i+=a;
//	}
//	return i-a;
//}
//
//int main() {
//	cout << EvDiv(20) << endl;
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 6: Sum square difference 
// Find the difference between the square of the sum of all numbers from 1 to 100 and the sum of the squares of all numbers from 1 to 100
// (sum_i=1_to_n(i))^2 - sum_i=1_to_n(i^2), n=100
//----------------------------------------------------------------------------------------------------------------------------------------------------------

////In this case it makes sense to have a look at sum conversions before starting with programming:
////(sum_i=1_to_n(i))^2 = (0.5n(n+1))^2
////and
////sum_i=1_to_n(i^2)= (1/6)n(n+1)(2n+1)
////and (0.5n(n+1))^2 - (1/6)n(n+1)(2n+1) = 0.25n(n^3 + (2/3)n^2 - n - (2/3))
//
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int DifSqOS_SoSq(float n) {
//    int Res = 0.25 * n * (pow(n, 3.0) + (2.0 / 3.0) * pow(n, 2.0) - n - (2.0 / 3.0));  //Remember that 2/3 = 0, but 2.0/3.0=0.666666...
//	return Res;
//}
//
//int main() {
//	//cout << DifSqOS_SoSq(10)<<endl;
//	cout << DifSqOS_SoSq(100)<<endl;
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 7: 10 001st prime
// Find the 10 001st prime number
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//using namespace std;
//
//bool isPrime(long int a) {             //reuse of and addition to isPrime function from problem 3
//	if (a == 1) {                        //Number 1 is not a prime
//		return false;
//	}
//	if (a == 2 || a==3) {                //This is necessary to include 2 and 3 as primes
//		return true;
//	}
//	for (long int i = 2; i <= int(sqrt(a)); i++) { //with <= instead of < the number 4 is recognized as prime
//		if (a % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//
//long int nthPrime(int n) {
//	n--;                     //Since 2 is skipped below (all other even numbers can't be prime) and thus are not counted
//	int counter = 0;
//	long int i = 1;
//	while (counter < n) {
//		if (isPrime(i)) {
//			counter++;
//		}
//		i+=2;
//	}
//	return i-2;
//}
//
//int main() {
//	cout << nthPrime(10001) << endl; 
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 8: Largest Product in a Series
// Find the largest product of 13 digits in a row within a series of 1000 digits
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//int main() {
//
//	ifstream input("Problem_8.txt");
//	string str;
//	for (std::string line; getline(input, line); )
//	{
//		str.append(line);
//	}
//	//cout << str << endl;           
//	cout << "length of string is: " << str.length() << endl << endl;   //1000 elements, str[0] to str[99], line breaks have not been read
//
//	//int(str[0]) returns the ascii code number of the first char, since the chars are all numbers and they start at int('0')=48
//	//the way to obtain the actual number as int is to write int(str[0])-int('0')
//	//cout << int(str[0]) - int('0') << endl << int(str[1]) - int('0') << endl << int(str[2]) - int('0') << endl << int(str[3]) - int('0') << endl;
//
//	unsigned int nrdig = 13;     //if value is >=0 unsigned int should be used. 
//	long long int max = 0;       //long long int necessary, since maximum product has 11 digits but int limit is at 10 digits
//	long long int prod = 1;
//	unsigned int a = 0;          
//	unsigned int frstnr = int('0');  //to convert from char to int it is not enough to write int(char) since that return the ascii value
//	                                 //but the difference int('7') - int('0') equals 7, making it possible to use that approach
//
//	for (unsigned int i = 0; i < str.length(); i++) {     //loop over all string elements
//		if (prod > max) {                                 //if the current product is greater than the max value then max=prod
//			max = prod;
//		}
//		prod = 1;
//		for (unsigned int j = 0; j < nrdig; j++) {        //loop for the calculation of the product and for skipping products if they include a zero
//			a = i + j;
//			if (a > str.length()-1) {                     //if the last chars of the string have been reached the loop uses the chars at the beginning
//				a -= str.length();
//			}
//			if ((int(str[a]) - frstnr) == 0) {            //if there is a zero in the product all products including this zero are skipped
//				i += j;
//				prod *= 0;
//			}
//			else {
//				prod *= (int(str[a]) - frstnr);
//			}
//		}
//	}
//	cout << "largest product of " << nrdig << " digits is " << max << endl;
//
//	return 0;
//  }

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 9: Special Pythagorean triplet
// Find the numbers a, b and c for which a^2+b^2=c^2 and a+b+c=1000
//----------------------------------------------------------------------------------------------------------------------------------------------------------

////a+b+sqrt(a^2+b^2)=1000
//
//#include<iostream>
//#include<cmath>
//
//using namespace std;
//
//int main() {
//	for (float i = 1; i < 400; i++) {
//		for (float j = 1; j < 400; j++) {
//			if (i + j + sqrt(pow(i, 2) + pow(j, 2)) == 1000.0) {
//				cout << int(i) << "," << int(j) << "," << int(1000-i-j) << endl;
//				cout << int(i * j * (1000 - i - j)) << endl;
//				return 0;
//			}
//		}
//	}
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 10: Summation of primes
// Sum up all primes <2 000 000
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//using namespace std;
//
//bool isPrime(long int a) {                    //reuse of isPrime function from problem 3 without first part for better performance
//	//if (a == 1) {                           //Number 1 is not a prime
//	//	return false;
//	//}
//	//if (a == 2 || a == 3) {                 //This is necessary to include 2 and 3 as primes
//	//	return true;
//	//}
//	for (long int i = 2; i <= int(sqrt(a)); i++) { //with <= instead of < the number 4 is recognized as prime
//		if (a % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//
//
//int main() {
//	long long int Sum = 0;
//	for (int i = 5; i < 2000000; i += 2) {    //Start at 5 to shorten isPrime function, but 2+3=5 has to be added to final sum
//		if (isPrime(i)) {
//			Sum += i;
//		}
//	}
//	cout << Sum + 5 << endl;                  //There is a bit of runtime but as expected much less than in python
//
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 11: Largest product in a grid
// Find the largest product of four 2-digit numbers within a 20x20 grid (vertically, horizontally, diagonally)
//----------------------------------------------------------------------------------------------------------------------------------------------------------

////20x20 grid of numbers between 00 and 99, 20 lines, each divided by spaces
////Largest product in all directions (left-right, up-down, diagonally left down-right up, diagonally left up-right down)
////Maybe read line by line, get into one long list of single entries,remember that always two digits per Nr, convert to int and save in 20x20 2d array
////https://stackoverflow.com/questions/36708370/reading-from-txt-file-into-two-dimensional-array-in-c
//
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<array>
//
//using namespace std;
//
//int main() {
//
//	//Reading all chars in all lines into one consecutive string
//	ifstream input("Problem_11.txt");
//	string str;
//	for (std::string line; getline(input, line); )
//	{
//		str.append(line);
//	}
//
//
//	//erasing all spaces within the string
//	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
//	
//	const int ArrSize = 20;  //Size of the ArrSizexArrSize 2D array.
//	
//
//	//Creating 2D int array and saving string divided after every two chars as ints into the array
//	int Arr[ArrSize][ArrSize];
//	int row = 0;
//	for (int i = 0; i < ArrSize; i++) {
//		for (int j = 0; j < ArrSize; j++) {
//			Arr[i][j]= ((str[2*(row* ArrSize +j)] - str[0])*10 + str[2 * (row * ArrSize + j)+1] - str[0]) ;
//		}
//		row++;
//	}
//
//	
//	//After successfully saving values in array the main problem is tackled: greatest product in all directions (increase i => down, increase j => right)
//	//Possible directions: right (if j+3<20), down(if i+3<20), right/down(if j+3<20 && i+3<20), left/down(if j-3>=0 && i+3<20)
//	//4 possible products per element, maximum possible is 99^4=96059601 ==> int should be sufficient
//
//	int Max1, Max2, Max3, Max4;                                                //Definition of 4 integers for maximum products for different directions
//	Max1 = Max2 = Max3 = Max4 = 0;                                             //All max values first set to zero
//	int prod1, prod2, prod3, prod4;                                            //Definition of 4 integers for products for different directions
//	prod1 = prod2 = prod3 = prod4 = 0;                                         //All products first set to zero
//
//	for (int i = 0; i < ArrSize; i++) {                                        //Iteration over all lines from 0 to ArrSize-1
//		for (int j = 0; j < ArrSize; j++) {                                    //Iteration over all columns from 0 to ArrSize-1
//			//right:
//			if (j + 3 < ArrSize) {
//				prod1 = Arr[i][j] * Arr[i][j + 1] * Arr[i][j + 2] * Arr[i][j + 3];
//				if (prod1 > Max1) {
//					Max1 = prod1;
//					prod1 = 1;
//				}
//			}
//			//down:
//			if (i + 3 < ArrSize) {
//				prod2 = Arr[i][j] * Arr[i + 1][j] * Arr[i + 2][j] * Arr[i + 3][j];
//				if (prod2 > Max2) {
//					Max2 = prod2;
//					prod2 = 1;
//				}
//			}
//			//right/down:
//			if (i + 3 < ArrSize && j+3 < ArrSize) {
//				prod3 = Arr[i][j] * Arr[i + 1][j + 1] * Arr[i + 2][j + 2] * Arr[i + 3][j + 3];
//				if (prod3 > Max3) {
//					Max3 = prod3;
//					prod3 = 1;
//				}
//			}
//			//left/down:
//			if (j - 3 >= 0 && i + 3 < ArrSize) {
//				prod4 = Arr[i][j] * Arr[i + 1][j - 1] * Arr[i + 2][j - 2] * Arr[i + 3][j - 3];
//				if (prod4 > Max4) {
//					Max4 = prod4;
//					prod4 = 1;
//				}
//			}
//		}
//	}
//
//	// highest product for all directions is determined
//	int Max = Max1;
//	if (Max2 > Max) {
//		Max = Max2;
//	}
//	if (Max3 > Max) {
//		Max = Max3;
//	}
//	if (Max4 > Max) {
//		Max = Max4;
//	}
//
//	//output of max products for different directions and all in all
//	//VS claims that cout in this case isn't defined clearly and has more than one meaning. Works nevertheless, but strange...
//	cout << "right:" << Max1 << endl;
//	cout << "down:" << Max2 << endl;
//	cout << "right/down:" << Max3 << endl;
//	cout << "left/down:" << Max4 << endl << endl;
//	cout << "all directions:" << Max << endl;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 12: Highly divisible tringular number
// Find the first triangle number (1, 1+2=3, 1+2+3=6, 1+2+3+4=10, ...) that has more than 500 divisors
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//#include<cmath>
//using namespace std;
//
////function that takes a number Nr and a number of divisors NrDiv as input and returns true if Nr has more than NrDiv divisors
//bool MoreThanNDiv(long long int Nr, int NrDiv) {
//	int NrD = 0;
//	if (Nr <= 1) {                                 //To ensure the loop below runs properly or left out if Nr<=1
//		return false;
//	}
//	for (int i = 1; i <= sqrt(Nr); i++) {          //Similar to isPrime function, loop from i=1 to sqrt(Nr)
//		if (Nr % i == 0 && Nr % i != sqrt(Nr)) {   //If a divisor below sqrt(Nr) is found there has to be another above the sqrt and the counter 
//			NrD+=2;                                // NrD is increased by two
//		}
//		if (Nr % i == 0 && i == sqrt(Nr)) {        //If the divisor found is equal to sqrt(Nr) the counter is only increased by one
//			NrD++;
//		}
//		if (NrD > NrDiv) {                         //If the number of divisors is greater than NrDiv (function input) true is returned
//			return true;
//		}
//	}
//	return false;                                  //else false is returned
//}
//
////Function that returns the first triangle number (1, 1+2=3, 1+2+3=6, 1+2+3+4=10) that has more than 500 divisors
//void TriMoreTh500() { 
//	long long int i = 1;                  //First triangle number that is to be incremented in the loop
//	long long int Sum = 0;                //Sum which represents the triangle numbers
//	while (!MoreThanNDiv(Sum, 500)) {     //While the triangle number has not more than 500 divisors do ...
//		Sum+=i;                           //First i is added to get the next triangle number
//		i++;                              //then the number that is added is increased by one
//	}
//	cout << Sum << endl;                  //return the first triangle number that has more than 500 divisors
//}
//
//int main() {
//	TriMoreTh500();
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 13: Large sum 
// Sum up 100 50 digit integers
//----------------------------------------------------------------------------------------------------------------------------------------------------------

//#include<iostream>
//#include<fstream>
//#include<string>
//#include<array>
//using namespace std;
//
////It's not possible to save a 50 digit integer number in any given number type
////It is however possible to save it as a string and convert the single digits to integers
////It should also be possible to create a long number class that has long numbers as objects and an add method to add long numbers
//
//int main() {
//
//	//Reading all chars in all lines into one array of integers string
//	ifstream input("Problem_13.txt");
//
//	int str[100][50];
//	int count = 0;
//	for (std::string line; getline(input, line); )       //Loop over all lines of file
//	{
//		for (int i = 0; i < 50; i++) {                   //Loop over all positions in a line
//			str[count][i] = int(line[i]) - int('0');
//		}
//		count++;
//	}
//
//	/*
//	cout << sizeof(str) / sizeof(str[0][0]) << endl;
//	cout << str[0][0]*str[0][1] << endl;
//	*/
//
//	// If the last digits of all numbers are added the final sum can't be more than 9*100=900, even if 9 is added from the summation before its only 909
//	//1000=10^3, 1 with 49 zeros =10^49 has 50 digits, 100 numbers ==> max sum of factor (10^49)*(10^2)=10^51 (52 digits) 
//	//To be sure just use 4 digit number (a=sum%10, sum-=sum%10; b=sum%100, sum-=sum%100; c=sum%1000, sum-=sum%1000; d=sum%10000)
//	//Array and append sum%10 elements to get number in reverse order
//	//create array with number that has to be added to each sum (52+ elements)
//
//	int Arr[55] = { 0 }; //Create array of integers for result
//
//	//100 50-digit numbers
//	int SUM = 0;
//	for (int i = 49; i >= 0; i--) {
//		for (int j = 0; j < 100; j++) {
//			SUM += str[j][i];
//		}
//		Arr[i + 5] += SUM % 10;
//		SUM -= SUM % 10;
//		if (Arr[i + 5] >= 10) {
//			Arr[i + 4] += Arr[i + 5] / 10;
//			Arr[i + 5] = Arr[i + 5] % 10;
//		}
//
//		Arr[i + 4] += (SUM % 100)/10;
//		SUM -= SUM % 100;
//		if (Arr[i + 4] >= 10) {
//			Arr[i + 3] += Arr[i + 4] / 10;
//			Arr[i + 4] = Arr[i + 4] % 10;
//		}
//
//		Arr[i + 3] += (SUM % 1000)/100;
//		SUM = 0;
//		if (Arr[i + 3] >= 10) {
//			Arr[i + 2] += Arr[i + 3] / 10;
//			Arr[i + 3] = Arr[i + 3] % 10;
//		}
//	}
//
//	for (int k = 0; k < 55; k++) {
//		cout << Arr[k];
//}
//	cout << endl;
//
//	return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 14: Largest Collatz sequence
// Find the starting number n<1 000 000 with the longest resulting Collatz sequence (n even -> n/=2; n uneven -> n=3n+1)
//----------------------------------------------------------------------------------------------------------------------------------------------------------

////Sequence for starting number n, if n even n/=2, if not n=n*3+1
////Longest sequence for starting number n<1 Mio
//
////len(74) = len(37)+1, can be solved by recursion,
////How is explained here and code is also taken from there to retrace the steps that were taken and to understand the methods :
////https://codereview.stackexchange.com/questions/39898/finding-maximum-collatz-sequence-between-1-1000000
////first version of the code was similar with respect to the steps that have to be taken, but results array was exceeding the stack size
//
//#include <iostream>
//#include <limits>
//#include <stdexcept>
//#include <vector>
//
//using namespace std;                                                 //Added to get rid of the need to use std::... (see commented lines with //std)
//
//
//
////Definition of rec. function that returns Collatz length of number and results vector,  Vector 'results' of type int is passed by reference 
//// (Function can change values of elements within original vector)
//
////int collatz(unsigned long long n, std::vector<int>& results) {              //std
//int collatz(unsigned long long n, vector<int>& results) {            
//    int c;                                                                    //integer c is created as chain length to save in results and to return 
//    if (n == 1) {                                                             //If n is 1 the Collatz chain length is also 1
//        return 1;
//    }
//    else if (n < results.size() && results[n]) {                              //If n < vector size and there is already a length entry ==> return length
//        return results[n];
//    }
//    else if (n % 2 == 0) {                                                    //If n is even, the length is set to 1 + length for n/2
//        c = 1 + collatz(n / 2, results);
//    }
//    //else if (n >= (std::numeric_limits<unsigned long long>::max() - 1) / 3) {   //std
//    else if (n >= (numeric_limits<unsigned long long>::max() - 1) / 3) {      //if n*3+1 > limits ULL ==> overflow error message
//        //throw std::overflow_error("Overflow");                              //std
//        throw overflow_error("Overflow");                                     //throw signals an erroneous condition and executes an error handler.
//                                                                              //https://en.cppreference.com/w/cpp/language/throw
//    }
//    else {                                                                    //If n is uneven, the length is set to 1 + length for 3*n+1
//        c = 1 + collatz(3 * n + 1, results);
//    }
//    if (n < results.size()) {                                                 //If n lies within the boundaries of the res vector the length is saved
//        results[n] = c;
//    }
//    return c;                                                                 //The length is returned
//}
//
//int main() {
//    const unsigned long long N = 1000000ULL;                                  //Maximum length N of vector is set, ULL stands for unsigned long long
//    //std::vector<int> results(N);                                            //std
//    vector<int> results(N);                                                   //results vector of length N with integers is created
//    int max = 0, max_i;                                                       //integers for maximum length and respective n is created
//    for (unsigned long long i = 1; i < N; ++i) {                              //loop over all numbers between 1 and N
//        results[i] = collatz(i, results);                                     //ith element of results is set to collatz length for n=i
//        // std::cout << "collatz(" << i << ") = " << results[i] << std::endl;    //Commented by original creator
//        if (max < results[i]) {                                               //If the length for i > than the maximum length
//            max = results[i];                                                 // ==> update maximum length
//            max_i = i;                                                        // ==> update number with maximum length
//        }
//    }
//    //std::cout << "Max: " << max_i << " with " << max << " steps" << std::endl;
//    cout << "Max: " << max_i << " with " << max << " steps" << endl;          
//    return 0;
//}

//----------------------------------------------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------------------------------------------
//Problem 15: Lattice paths
// How many different routes are there from top left to bottom low of a 20x20 grid?
//----------------------------------------------------------------------------------------------------------------------------------------------------------

// There are 40!/20! paths through a 20x20 lattice (Addition of possible paths at nodes). The numbers are to big for any variable type
// Therefore vectors and methods specifically written for them have to be used.

#include<iostream>
#include<vector>
using namespace std;

void MultiplyVectorByScalar(vector<int>& v, int k) {
	for (int i = 0; i < v.size(); ++i)
		v[i] = v[i] * k;
}

//Function to calculate the product of all numbers from start to stop, in this case from 21 to 40
vector<int> factorial(int start, int stop){
	//Creating the result vector
	vector<int> fac;
	int i = start;
	//using the value of start to fill the results vector (reversed, ones first)
	while (i > 0)
	{
		fac.push_back(i % 10);
		i /= 10;
	}
	int s = fac.size();
	//Creating a loop to multiply the start value with all other values up to stop
	for (int j = start + 1; j <= stop; j++) {
		s = fac.size();
		MultiplyVectorByScalar(fac, j);

		/*cout << "vec of size " << fac.size() << " multiplied with " << j << endl;
		for (int z = 0; z < fac.size(); z++) {
			cout << fac[z] << " ";
		}
		cout << endl;*/

		int c = 0; //to see if fac entry was > 9
		//Another loop needed to divide by ten and so on
		for (int k = 0; k < s; k++) {
			int a = fac[k]; //To save original value
			int b = 0; //To change fac position every time the original value is divided by 10
			while (a > 9) {
				c = 1;
				if (b==0) {
					fac[k] = a % 10;
				}
				else if (b > 0 && k + b < fac.size()) {
					fac[k+b] += a % 10;
				}
				else {
					fac.push_back(a % 10);
				}
				a /= 10;
				b++;
			}
			if (k + b < fac.size() && c==1) {  // if fac entry was >9 and there is an entry to the right
				//cout << "added " << a << endl;
				fac[k + b] += a;
			}
			else {
				if (c == 1) {  // if fac entry was >9 but there is no entry to the right
					//cout << "pushed back " << a << endl;
					fac.push_back(a);
				}
			}
			c = 0;
		}

		//cout << "vec multiplied with " << j << " set right" << endl;
		//for (int y = 0; y < fac.size(); y++) {
		//	cout << fac[y] << " ";
		//}
		//cout << endl;
	}


	reverse(fac.begin(), fac.end());
	return fac;
}

int main() {

	vector<int> paths = factorial(21, 40);
	for (int i = 0; i < paths.size();i++) {
		cout << paths[i] << " ";
	}
	cout << endl;
	return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------