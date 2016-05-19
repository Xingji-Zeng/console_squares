#include<iostream>
#include<assert.h>

using namespace std;

class Checker{
	public:
		//identify the status of checker
		//if = 0, it's unplaced
		//if = 1, placed by A
		//if = 2, placed by b
		int ifPlaced[9];

	public:

		void init(){
			for(int i = 0 ; i < 9 ; i++){
				ifPlaced[i] = 0;
			}
		}

		void printChecker(){
			char player[9];
			for (int i = 0 ; i < 9 ; i ++){
				if(ifPlaced[i] == 0) player[i] = '@';
				else if(ifPlaced[i] == 1) player[i] = 'o';
				else if(ifPlaced[i] == 2) player[i] = 'x';
				else assert("variaint ifPlaced is illegal!");
			}
			cout << player[0] << player[1] << player[2] << "\n"
				 << player[3] << player[4] << player[5] << "\n"
				 << player[6] << player[7] << player[8] << "\n";
		}
	
		bool placePiece(int position , int player){
			if(position < 0 || position > 8){ 
				cout << "please input position between 0 ~ 8" << endl;
				return 0;
			}
			else{
				if( ifPlaced[position] != 0){
					cout << "this position is place!" << endl;
					return 0;
				}	
					else{
						ifPlaced[position] = player;
						return 1;
					}
			}
		}

}	checker;


void oneTurn()
{
	checker.init();
	
	//A to place a piece
	int player = 1;
	int position = 0;
	bool havePlaced = 0;
	while(!havePlaced){
		cout << "A's turn to place" << endl;
		cin >> position ;
		havePlaced = checker.placePiece(position , player);
		checker.printChecker();
	}
//	checker.printChecker();
}

int main(){
	for(int i = 0 ; i < 2 ; i++){
		oneTurn();
	}
}
