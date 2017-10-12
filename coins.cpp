/*Chido Nguyen
931506965
CS325 HW3 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;

/*
//									MakeItRain
//Purpose: Generate the least amount of coins possible to give when given a value for change
//Parameters: Coin_type{} array that stores coin denomination
//			  int Change , value of change to give out
//Returns : The array we'll create inside the function to track coins given at each total
/*/

int MakeItRain(int &Coins, int change){
	
	
	
	return 0;
}


int main(){
	std::fstream doc;
	std::fstream output;
	int change;
	int tmp;
	doc.open("data.txt");
	output.open("stooge.out", std::fstream::out);

	if (doc) {
		
	}
	else
		cout << "data.txt failed to open" << endl;


	doc.close();
	output.close();
	
	return 0;
}