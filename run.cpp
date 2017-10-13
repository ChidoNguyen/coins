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
//			  our Purse{} is the type of coin we give  at each change total
//			  Fatorial{} is our array where index # equals our change amount, i.e. change for 30 means we have a container from 0->30.
//			  int Change , value of change to give out
// Returns : nothing explicitly returned, but our purse/factorial arrays will have updated values
// Credit to youtube video for help with understanding what needed to be returned: https://www.youtube.com/watch?v=NJuKJ8sasGk
// I knew how to approach it just not what I should've  used to "memo-ized" the data
// Turned out I could use the index of each "array location" as the value of change to be giving, rather than creating multi-dimensional array.
/*/

void MakeItRain(std::vector<int> &Coins, std::vector<int> &Purse, std::vector<int> &Factorial, int change) {
	//std::vector<int> Factorial(change+1, 9999999);
	Factorial[0] = 0; 								// our change given  at 0 is 0 
	for (int x = 0; x < Coins.size(); x++) {						//This for loop iterates through our different coin denominations in the coins array
		for (int y = 1; y <= change; y++) {							// This for loop is to find the smallest amount of coins possible to give at each "change" value from 1 to n being our change
			if (y >= Coins[x]) {										// We can only make change for coins that are at least equal to our coin value and not less than change of 1 cant be given by coin 3
				if (Factorial[y - Coins[x]] + 1 < Factorial[y]) {	//Look below function //
					Factorial[y] = Factorial[y - Coins[x]] + 1;
					Purse[y] = x;
				}
			}
		}
	}

}
// Function explanation  at line 32-35 :
// our if condition checks to see if the new coin change count is less than the current. I.e. say for change of 6 we are currently storing a value of 3 (4 + 1 +1). We now check what happens if we use 
// coin value 3, y = 6 so for  6-3 we look at Factorial [ 3] and if we've already done this change of 3 can be given with coin 3 so the index holds value 1 there, we get 1+1 = 2
// now we compare if 2 coins is less than 3 coins given for change if it is we replace , and then update our "purse" that at change 6 we gave coin 3 as change. 
/////////////////////////////////



// 						WriteItOut
// Function purpose: print out to output file coin denomination , change to be given, followed by amount of each coin given, and total coins given.
//I.e. : 	coins 1 , 2 , 5
//			#     0   0   2
//			Change : 10 
//			Total : 2 coins


void WriteItOut(std::vector<int> &Coins, std::vector<int> &Purse, std::vector<int> &Factorial, std::fstream &outtie) {


	// Amount of each coin used //
	int num_of_coins = Coins.size();
	int change = Purse.size() - 1;
	std::vector<int> TmpCoins(num_of_coins);

	while (Purse[change] != -1) {
		int tmp = Purse[change];
		TmpCoins[tmp] += 1;
		change -= Coins[tmp];
	}

	////////////////////////////////////////////////
	outtie << "Change to give: " << Factorial.size() - 1 << '\n';

	outtie << "Coin Value: 	";
	while (!(Coins.empty())) {
		outtie << Coins.front() << "	";
		Coins.erase(Coins.begin());
	}
	outtie << '\n';



	outtie << "Coin Used: 		";
	while (!(TmpCoins.empty())) {
		outtie << TmpCoins.front() << "	";
		TmpCoins.erase(TmpCoins.begin());
	}
	outtie << '\n';
	change = Purse.size() - 1;
	outtie << "Value of change to be given: " << change << '\n';

	outtie << "Total coins given for change: " << Factorial[change] << '\n' << '\n';


}




int main() {
	clock_t start;

	srand(time(NULL));
	int n_size = 0;
	int change;
	cout << "How many different denomination of coins?" << endl;
	cin >> n_size; // how many coins
	cout << "What value do you want to give change for? ";
	cin >> change;

	std::vector<int> denom(n_size);
	std::vector<int> storage(change + 1, -1); // what coins are given at each change index
	std::vector<int> iter_change(change + 1, 9999999); // # of coins used to provide change at each index
													   


													   // Random # Gen for array of N-size //
	for (int x = 0; x < n_size; x++) {
		if (x == 0)
			denom[0] = 1;
		else
			denom[x] = (rand() % (n_size * 10));
	}
	start = clock();
	MakeItRain(denom, storage, iter_change, change);
	start = clock() - start;
	double difff = (float)start / float(CLOCKS_PER_SEC);
	cout << difff << endl;
	return 0;
}