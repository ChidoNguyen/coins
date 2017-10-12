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

void MakeItRain(std::vector<int> &Coins, std::vector<int> &Purse, std::vector<int> &Factorial,int change) {
	//std::vector<int> Factorial(change+1, 9999999);
	Factorial[0] = 0;
	for (int x = 0; x < Coins.size(); x++) {
		for (int y = 1; y <= change; y++) {
			if (y>= Coins[x]) {
				if (Factorial[y - Coins[x]] + 1 < Factorial[y]) {
					Factorial[y] = Factorial[y - Coins[x]] + 1;
					Purse[y] = x;
				}
			}
		}
	}

}


int main() {
	std::fstream doc;
	std::fstream output;
	int change;
	int tmp;
	doc.open("data.txt");
	output.open("stooge.out", std::fstream::out);
	std::vector<int> denom;
	



	if (doc) {
		while (!doc.eof()) {			// This one loops whole document
			do {		// Reads the coin types
				doc >> tmp;
				denom.push_back(tmp);
			} while (doc.peek() != '\n' && !(doc.eof()));
			do {				//Reads in change
				doc >> change;
			} while (doc.peek() != '\n' && !(doc.eof()));
			std::vector<int> storage(change +1,-1);
			std::vector<int> iter_change(change + 1, 9999999);
			MakeItRain(denom, storage,iter_change, change);
			// Add output to .out file
			//output << '\n';
			denom.clear();
			change = 9999999;
		};
	}
	else
		cout << "data.txt failed to open" << endl;


	doc.close();
	output.close();

	return 0;
}