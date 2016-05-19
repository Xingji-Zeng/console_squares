#include<iostream>
#include<stdlib.h>
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

		bool ifWin(int player){
			bool judgement;
				//horizonal
			if((ifPlaced[0]==player && ifPlaced[1]==player && ifPlaced[2]==player) ||
				(ifPlaced[3]==player && ifPlaced[4]==player && ifPlaced[5]==player) ||
				(ifPlaced[6]==player && ifPlaced[7]==player && ifPlaced[8]==player) ||
				//vertical
				(ifPlaced[0]==player && ifPlaced[3]==player && ifPlaced[6]==player) ||
				(ifPlaced[1]==player && ifPlaced[4]==player && ifPlaced[7]==player) ||
				(ifPlaced[2]==player && ifPlaced[5]==player && ifPlaced[8]==player) ||
				//slope
				(ifPlaced[0]==player && ifPlaced[4]==player && ifPlaced[8]==player) ||
				(ifPlaced[2]==player && ifPlaced[4]==player && ifPlaced[6]==player) ) judgement = 1;
			else judgement =0 ;
			return judgement;
		}

}	checker;

void introduction(){
	cout << "This is a very simple game, please each player input number from 0 ~ 8 to fill the checker like this\n"
		 << " __ __ __ \n"
		 << "|0_|1_|2_|\n"
		 << "|3_|4_|5_|\n"
		 << "|6_|7_|8_|\n" << endl;
}

void oneTurn( int turns)
{	
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
	
	//Break after A placed in the last turn 
	//B to place a piece
	if(turns < 4 && !checker.ifWin(1)){
		player = 2;
		havePlaced = 0;
		while(!havePlaced){
			cout << "B's turn to place" << endl;
			cin >> position ; 
			havePlaced = checker.placePiece(position , player);
			checker.printChecker();
		}	
	}
//	checker.printChecker();
}

int main(){
	introduction();
	checker.init();
	bool Awin=0 , Bwin=0;
	for(int i = 0 ; i < 5 ; i++){
		if(!Awin && !Bwin) oneTurn(i);
		if(i >= 2){
			Awin = checker.ifWin(1);
			Bwin = checker.ifWin(2);
		}
	}
	if(Awin) cout << "A wins!";
	else if(Bwin) cout << "B wins!";
	else cout << "Draw";
}
