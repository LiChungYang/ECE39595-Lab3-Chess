#include <assert.h>
#include<iostream>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

#define log_success() std::cout << __func__ << " passed" << std::endl
#define log_pair(arg1, arg2) std::cout << "(" << arg1 << "," << arg2 << ")" << std::endl
#define disp_board() std::cout << sBoard.displayBoard().str() << std::endl

void test_part1_4x4_scan() {
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);
	sBoard.createChessPiece(White, Pawn, 3, 1);
	sBoard.createChessPiece(Black, Pawn, 2, 2);

	//scanning Black Rook
	bool expected_scan_result[4][4] = {{false, true, false, false}, 
									    {true, false, true, false},
									    {false, true, false, false},
									    {false, true, false, false}};

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(sBoard.isValidMove(1,1,i,j) != expected_scan_result[i][j]) {
				std::cout << "Scan failed at: ";
				log_pair(i,j);
			}
			assert(sBoard.isValidMove(1,1,i,j) == expected_scan_result[i][j]);
		}
	}

	//scanning Black Bishop
	bool bishopExpectedResult[4][4] = {{false, false, true, false},
									   {false, false, false, false},
									   {false, false, false, false},
									   {false, false, false, false}};

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(sBoard.isValidMove(1,3,i,j) != bishopExpectedResult[i][j]) {
				std::cout << "Scan failed at: ";
				log_pair(i,j);
			}
			assert(sBoard.isValidMove(1,3,i,j) == bishopExpectedResult[i][j]);
		}
	}
	
	//checking Black Pawn

	assert(sBoard.isValidMove(2,2,3,1) == true);

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i != 3 && j != 1) {
				if(sBoard.isValidMove(2,2,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(2,2,i,j) == false);
			}
		}
	}

	//checking White Rook at (2,3)
	assert(sBoard.isValidMove(2,3,2,2) == true);
	assert(sBoard.isValidMove(2,3,1,3) == true);
	assert(sBoard.isValidMove(2,3,3,3) == true);

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if((!(i == 2 && j == 2)) && ((!(i == 1 && j == 3)) && (!(i == 3 && j == 3)))) {
				if(sBoard.isValidMove(2,3,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(2,3,i,j) == false);
			}
		}
	}
	//White Pawn at (3,1)
	assert(sBoard.isValidMove(3,1,2,1) == true);
	for (int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i != 2 && j != 1) {
				if(sBoard.isValidMove(3,1,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(3,1,i,j) == false);
			}
		}
	}

	//White Rook at (3,2)
	assert(sBoard.isValidMove(3,2,2,2) == true);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if((i != 2 && j != 2) && (i != 3 && j != 3)) {
				if(sBoard.isValidMove(3,2,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(3,2,i,j) == false);
			}
		}
	}
	log_success();
}

void test_part1_4x4_2_scan() {
/*	config content
 *  0
	4 4
	b r 0 2
	w b 3 0
	b r 2 2
	w b 3 3*/
	Student::ChessBoard sBoard(4,4);
    sBoard.createChessPiece(Black, Rook, 0, 2);
    sBoard.createChessPiece(White, Bishop, 3, 0);
    sBoard.createChessPiece(Black, Rook, 2, 2);
    sBoard.createChessPiece(White, Bishop, 3, 3);

	disp_board();

	//scanning Black Rook at (0,2)
	assert(sBoard.isValidMove(0,2,0,1) == true);
	assert(sBoard.isValidMove(0,2,0,0) == true);
	assert(sBoard.isValidMove(0,2,0,3) == true);
	assert(sBoard.isValidMove(0,2,1,2) == true);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if((i != 0) && (j != 1) && (j != 0) && (j != 3) && (j != 2)){
				if(sBoard.isValidMove(0,2,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(0,2,i,j) == false);
			}
		}
	}
	//scanning White Bishop at (3, 0)
	assert(sBoard.isValidMove(3,0,2,1) == true);
	assert(sBoard.isValidMove(3,0,1,2) == true);
	assert(sBoard.isValidMove(3,0,0,3) == true);
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(i != 2 && i != 1 && i != 0 && j != 1 && j != 2 && j != 3) {
				if(sBoard.isValidMove(3,0,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(3,0,i,j) == false);
			}
		}
	}
	//scanning White Bishop at (3,3)
	assert(sBoard.isValidMove(3,3,2,2) == true);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i != 2 && j != 2) {
				if(sBoard.isValidMove(3,3,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(3,3,i,j) == false);
			}
		}
	}
	//scanning Black Rook at (2,2)
	assert(sBoard.isValidMove(2,2,2,0) == true);
	assert(sBoard.isValidMove(2,2,2,1) == true);
	assert(sBoard.isValidMove(2,2,2,3) == true);
	assert(sBoard.isValidMove(2,2,1,2) == true);
	assert(sBoard.isValidMove(2,2,3,2) == true);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i != 1 && i != 2 && i != 3 && j != 0 && j != 1 && j != 2 && j != 3) {
				if(sBoard.isValidMove(2,2,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(2,2,i,j) == false);
			}
		}
	}

	log_success();
}

void test_movePiece_4x4_1() {
	//driver code: set up board
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);
	sBoard.createChessPiece(White, Pawn, 3, 1);
	sBoard.createChessPiece(Black, Pawn, 2, 2);

	assert(sBoard.getPiece(1,1));
	assert(sBoard.getPiece(1,1) -> getType() == Rook);
	assert(sBoard.getPiece(1,1) -> getColor() == Black);


	//test moving not occupied cells on the board
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(i == 0) {
				if(sBoard.movePiece(i, j, j, i) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.movePiece(i, j, j, i) == false);
			}
			else if(i == 1) {
				if(j != 1 || j != 3) {
					if(sBoard.movePiece(i, j, j, i) == true) {
						std::cout << "Scan failed at: ";
						log_pair(i,j);
					}
					assert(sBoard.movePiece(i, j, j, i) == false);
				}
			}
			else if(i == 2) {
				if(j != 0 || j != 1) {
					if(sBoard.movePiece(i, j, j, i) == true) {
						std::cout << "Scan failed at: ";
						log_pair(i,j);
					}
					assert(sBoard.movePiece(i, j, j, i) == false);
				}
			}
			else {
				if(j != 1 || j != 2) {
					if(sBoard.movePiece(i, j, j, i) == true) {
						std::cout << "Scan failed at: ";
						log_pair(i,j);
					}
					assert(sBoard.movePiece(i, j, j, i) == false);
				}
			}
		}
	}
	//test moving pieces on the board
	//testing Black Rook starting at (1,1)
	
	//horizontal move
	assert(sBoard.movePiece(1,1,1,0));
	assert(sBoard.getPiece(1,1) == nullptr);
	assert(sBoard.getPiece(1,0) -> getType() == Rook);
	assert(sBoard.getPiece(1,0) -> getColor() == Black);
	assert(sBoard.movePiece(1,0,1,2));
	assert(sBoard.movePiece(1,2,1,3) == false);

	//move back to start
	sBoard.movePiece(1,2,1,1);
	//vertical move
	assert(sBoard.movePiece(1,1,0,1));
	assert(sBoard.movePiece(0,1,2,1));
	assert(sBoard.movePiece(2,1,3,1));
	sBoard.movePiece(3,1,1,1);
	//check capturing
	assert(sBoard.getPiece(3,1) == nullptr);

	//invalid moves
	log_success();
}
void test_king_piece_4x4_1(){
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(Black, Bishop, 1, 3);
    sBoard.createChessPiece(Black, Rook, 1, 1);
	sBoard.createChessPiece(Black, Pawn, 2, 2);
	sBoard.createChessPiece(Black, King, 0,0);
	sBoard.createChessPiece(White, King, 0,2);
	//checking isValidMove for Black King
	assert(sBoard.isValidMove(0,0,1,0));
	assert(sBoard.isValidMove(0,0,1,2) == false);

	for (int i = 0; i < 4; i++)	{
		for(int j = 0; j < 4; j++) {
			if(!((i == 1 && j == 0))){
				if(sBoard.isValidMove(0,0,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(0,0,i,j) == false);
			}
		}
	}

	//checking isValidMove for white King at (0,2)
	assert(sBoard.isValidMove(0,2,0,3) == true);
	assert(sBoard.isValidMove(0,2,1,3) == false);
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++){
			if(!(i == 0 && j == 3)){
				if(sBoard.isValidMove(0,2,i,j) == true) {
					std::cout << "Scan failed at: ";
					log_pair(i,j);
				}
				assert(sBoard.isValidMove(0,2,i,j) == false);
			}
		}
	}

	log_success();
}

void test_king_piece_4x4_5(){
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(Black, Pawn, 0, 2);
    sBoard.createChessPiece(White, Bishop, 2, 1);
	sBoard.createChessPiece(White, Rook, 1, 3);
	sBoard.createChessPiece(White, Rook, 1,0);
	sBoard.createChessPiece(Black, King, 1,0);
	sBoard.createChessPiece(White, King, 3,2);

	assert(sBoard.isPieceUnderThreat(1,0) == true);
	
	//assert(sBoard.isValidMove(1,0,2,1) == true);

	//assert(sBoard.isPieceUnderThreat(2,1) == 1);
	/*
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++){
			if(sBoard.getPiece(i,j) != nullptr){
				// printf("i%d\n", i);
				// printf("j%d\n", j);

				std::cout << i << " " << j << " " << sBoard.isPieceUnderThreat(i,j) << std::endl;

			}
		}
	}
	*/
	//movePiece 1 3 2 3
	assert(sBoard.isValidMove(1,3,2,3));
	sBoard.movePiece(1,3,2,3);

	assert(sBoard.isValidMove(1,0,0,0));

	/*
	//here
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++){
			std::cout <<"result for(" << i << "," << j << ")\n";
			for(int k = 0; k < 4; k++)
			{
				for(int p = 0; p < 4; p++)
				{
					std::cout << sBoard.isValidMove(i,j,k,p) << " ";
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
			}
		std::cout<<"\n";
		}
	*/

	//movePiece 1 0 1 1
	assert(sBoard.isValidMove(1,0,1,1));
	sBoard.movePiece(1,0,1,1);
	//movePiece 2 1 0 3
	assert(sBoard.isValidMove(2,1,0,3));
	sBoard.movePiece(2,1,0,3);
	//movePiece 0 2 1 2
	assert(sBoard.isValidMove(0,2,1,2));
	sBoard.movePiece(0,2,1,2);
	//movePiece 2 3 2 3
	assert(sBoard.isValidMove(2,3,2,3) == false);
	//movePiece 2 3 3 3
	assert(sBoard.isValidMove(2,3,3,3));
	sBoard.movePiece(2,3,3,3);
	//movePiece 1 1 0 2
	assert(sBoard.isValidMove(1,1,0,2));
	sBoard.movePiece(1,1,0,2);

	assert(sBoard.isValidMove(3,2,2,1) == false);

	//movePiece 3 2 2 2
	assert(sBoard.isValidMove(3,2,2,2));
	sBoard.movePiece(3,2,2,2);
	//movePiece 0 2 0 1
	assert(sBoard.isValidMove(0,2,0,1));
	sBoard.movePiece(0,2,0,1);
	//movePiece 3 3 1 1
	assert(sBoard.isValidMove(3,3,1,1) == false);
	//movePiece 3 3 3 1
	assert(sBoard.isValidMove(3,3,3,1));
	sBoard.movePiece(3,3,3,1);
	//movePiece 0 1 0 0
	assert(sBoard.isValidMove(0,1,0,0));
	sBoard.movePiece(0,1,0,0);
	//movePiece 2 2 1 3
	assert(sBoard.isValidMove(2,2,1,3));
	sBoard.movePiece(2,2,1,3);
	//movePiece 1 2 3 2
	assert(sBoard.isValidMove(1,2,3,2));
	sBoard.movePiece(1,2,3,2);

	assert(sBoard.isValidMove(1,3,2,3));

	//movePiece 0 2 2 1
	assert(sBoard.isValidMove(0,2,2,1) == false);
	//movePiece 3 1 2 1
	assert(sBoard.isValidMove(3,1,2,1));
	sBoard.movePiece(3,1,2,1);
	//movePiece 0 0 1 0
	assert(sBoard.isValidMove(0,0,1,0));
	sBoard.movePiece(0,0,1,0);
	//movePiece 2 1 2 0
	assert(sBoard.isValidMove(2,1,2,0));
	sBoard.movePiece(2,1,2,0);

	assert(sBoard.isValidMove(1,0,0,0) == false);

	/*
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++){
			std::cout <<"result for(" << i << "," << j << ")\n";
			for(int k = 0; k < 4; k++)
			{
				for(int p = 0; p < 4; p++)
				{
					std::cout << sBoard.isValidMove(i,j,k,p) << " ";
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
			}
		std::cout<<"\n";
		}
	*/

	//movePiece 1 0 1 1
	assert(sBoard.isValidMove(1,0,1,1));
	sBoard.movePiece(1,0,1,1);
	//movePiece 0 2 3 0
	assert(sBoard.isValidMove(0,2,3,0) == false);	
	//movePiece 2 0 2 3
	assert(sBoard.isValidMove(2,0,2,3));
	sBoard.movePiece(2,0,2,3);
	//movePiece 1 1 1 0
	assert(sBoard.isValidMove(1,1,1,0));
	sBoard.movePiece(1,1,1,0);
	//movePiece 2 3 2 2
	assert(sBoard.isValidMove(2,3,2,2));
	sBoard.movePiece(2,3,2,2);
	//movePiece 1 0 1 1
	assert(sBoard.isValidMove(1,0,1,1));
	sBoard.movePiece(1,0,1,1);
	//movePiece 3 0 2 2
	assert(sBoard.isValidMove(3,0,2,2) == false);
	//movePiece 0 3 1 2
	assert(sBoard.isValidMove(0,3,1,2));
	sBoard.movePiece(0,3,1,2);
	//movePiece 1 1 1 0
	assert(sBoard.isValidMove(1,1,1,0));
	sBoard.movePiece(1,1,1,0);
	//movePiece 2 2 2 1
	assert(sBoard.isValidMove(2,2,2,1));
	sBoard.movePiece(2,2,2,1);
	//movePiece 1 0 0 0
	assert(sBoard.isValidMove(1,0,0,0));
	sBoard.movePiece(1,0,0,0);
	//movePiece 0 2 3 2
	assert(sBoard.isValidMove(0,2,3,2) == false);
	//movePiece 2 1 2 3
	assert(sBoard.isValidMove(2,1,2,3));
	sBoard.movePiece(2,1,2,3);
	//movePiece 0 0 1 1
	assert(sBoard.isValidMove(0,0,1,1));
	sBoard.movePiece(0,0,1,1);
	//movePiece 2 3 2 0
	assert(sBoard.isValidMove(2,3,2,0));
	sBoard.movePiece(2,3,2,0);
	//movePiece 1 1 2 0
	assert(sBoard.isValidMove(1,1,2,0));
	sBoard.movePiece(1,1,2,0);
	//movePiece 2 0 1 3
	assert(sBoard.isValidMove(2,0,1,3) == false);
	//movePiece 1 3 2 3
	assert(sBoard.isValidMove(1,3,2,3));
	sBoard.movePiece(1,3,2,3);
	//movePiece 2 0 1 0
	assert(sBoard.isValidMove(2,0,1,0));
	sBoard.movePiece(2,0,1,0);
	//movePiece 1 2 0 1
	assert(sBoard.isValidMove(1,2,0,1));
	sBoard.movePiece(1,2,0,1);
	//movePiece 1 0 0 0
	assert(sBoard.isValidMove(1,0,0,0));
	sBoard.movePiece(1,0,0,0);
	//movePiece 3 0 3 2
	assert(sBoard.isValidMove(3,0,3,2) == false);
	//movePiece 2 3 1 2
	assert(sBoard.isValidMove(2,3,1,2));
	sBoard.movePiece(2,3,1,2);
	//movePiece 3 2 3 2
	assert(sBoard.isValidMove(3,2,3,2) == false);
	//movePiece 2 1 2 3
	assert(sBoard.isValidMove(2,1,2,3) == false);
	//movePiece 2 3 3 0
	assert(sBoard.isValidMove(2,3,3,0) == false);
	//movePiece 3 2 2 1
	assert(sBoard.isValidMove(3,2,2,1) == false);

}


void test_king_piece_4x4_4(){
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Bishop, 2, 0);
    sBoard.createChessPiece(Black, Pawn, 3, 0);
	sBoard.createChessPiece(White, Bishop, 2, 0);
	sBoard.createChessPiece(Black, Rook, 2,0);
	sBoard.createChessPiece(Black, King, 3,2);
	sBoard.createChessPiece(White, King, 1,1);

	//movePiece 1 1 0 2
	assert(sBoard.isValidMove(1,1,0,2));
	sBoard.movePiece(1,1,0,2);
	//movePiece 2 0 0 0
	assert(sBoard.isValidMove(2,0,0,0));
	sBoard.movePiece(2,0,0,0);

	assert(sBoard.isValidMove(0,2,0,3) == false);

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++){
			std::cout <<"result for(" << i << "," << j << ")\n";
			for(int k = 0; k < 4; k++)
			{
				for(int p = 0; p < 4; p++)
				{
					std::cout << sBoard.isValidMove(i,j,k,p) << " ";
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
			}
		std::cout<<"\n";
		}



	//movePiece 0 2 1 2
	assert(sBoard.isValidMove(0,2,1,2));
	sBoard.movePiece(0,2,1,2);

}

void test_king_piece_6x6_5(){
    Student::ChessBoard sBoard(6, 6);
    sBoard.createChessPiece(Black, Bishop, 0, 2);
    sBoard.createChessPiece(White, Bishop, 2, 2);
	sBoard.createChessPiece(Black, Pawn, 2, 1);
	sBoard.createChessPiece(Black, Pawn, 2, 5);
	sBoard.createChessPiece(White, Bishop, 0, 2);
	sBoard.createChessPiece(Black, Rook, 3,4);
	sBoard.createChessPiece(Black, King, 3,2);
	sBoard.createChessPiece(White, King, 0,1);

	//movePiece 2 2 0 4
	assert(sBoard.isValidMove(2,2,0,4));
	sBoard.movePiece(2,2,0,4);
	//movePiece 3 4 4 4
	assert(sBoard.isValidMove(3,4,4,4));
	sBoard.movePiece(3,4,4,4);
	//movePiece 0 4 2 2
	assert(sBoard.isValidMove(0,4,2,2));
	sBoard.movePiece(0,4,2,2);
	//movePiece 4 4 4 3
	assert(sBoard.isValidMove(4,4,4,3));
	sBoard.movePiece(4,4,4,3);
	//movePiece 1 1 0 4
	assert(sBoard.isValidMove(1,1,0,4) == false);
	//movePiece 2 2 3 1
	assert(sBoard.isValidMove(2,2,3,1));
	sBoard.movePiece(2,2,3,1);
	//movePiece 4 3 4 2
	assert(sBoard.isValidMove(4,3,4,2));
	sBoard.movePiece(4,3,4,2);
	//movePiece 0 2 2 4
	assert(sBoard.isValidMove(0,2,2,4));
	sBoard.movePiece(0,2,2,4);
	//movePiece 3 2 3 1
	assert(sBoard.isValidMove(3,2,3,1));
	sBoard.movePiece(3,2,3,1);
	//movePiece 4 3 3 1
	assert(sBoard.isValidMove(4,3,3,1) == false);
	//movePiece 2 4 1 3
	assert(sBoard.isValidMove(2,4,1,3));
	sBoard.movePiece(2,4,1,3);

	assert(sBoard.isValidMove(3,1,4,0) == false);
	/*
	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++){
			std::cout <<"result for(" << i << "," << j << ")\n";
			for(int k = 0; k < 6; k++)
			{
				for(int p = 0; p < 6; p++)
				{
					std::cout << sBoard.isValidMove(i,j,k,p) << " ";
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
			}
		std::cout<<"\n";
		}

	*/
	//movePiece 4 2 2 2
	assert(sBoard.isValidMove(4,2,2,2));
	sBoard.movePiece(4,2,2,2);


}

void test_king_piece_6x6_3(){
    Student::ChessBoard sBoard(6, 6);
    sBoard.createChessPiece(White, Pawn, 2, 2);
    sBoard.createChessPiece(Black, Rook, 1, 4);
	sBoard.createChessPiece(White, Pawn, 0, 4);
	sBoard.createChessPiece(White, Rook, 3, 3);
	sBoard.createChessPiece(Black, Pawn, 3, 4);
	sBoard.createChessPiece(White, Pawn, 5,4);
	sBoard.createChessPiece(Black, King, 0,1);
	sBoard.createChessPiece(White, King, 2,1);

	//movePiece 5 4 4 4
	assert(sBoard.isValidMove(5,4,4,4));
	sBoard.movePiece(5,4,4,4);
	//movePiece 0 1 0 2
	assert(sBoard.isValidMove(0,1,0,2));
	sBoard.movePiece(0,1,0,2);
	//movePiece 2 1 3 0
	assert(sBoard.isValidMove(2,1,3,0));
	sBoard.movePiece(2,1,3,0);
	//movePiece 1 4 1 5
	assert(sBoard.isValidMove(1,4,1,5));
	sBoard.movePiece(1,4,1,5);
	//movePiece 4 1 4 2
	assert(sBoard.isValidMove(4,1,4,2) == false);
	//movePiece 3 3 4 3
	assert(sBoard.isValidMove(3,3,4,3));
	sBoard.movePiece(3,3,4,3);
	//movePiece 1 5 1 3
	assert(sBoard.isValidMove(1,5,1,3));
	sBoard.movePiece(1,5,1,3);
	//movePiece 3 0 2 1
	assert(sBoard.isValidMove(3,0,2,1));
	sBoard.movePiece(3,0,2,1);
	//movePiece 0 2 0 1
	assert(sBoard.isValidMove(0,2,0,1));
	sBoard.movePiece(0,2,0,1);
	//movePiece 3 0 0 0
	assert(sBoard.isValidMove(3,0,0,0) == false);
	//movePiece 2 1 2 0
	assert(sBoard.isValidMove(2,1,2,0));
	sBoard.movePiece(2,1,2,0);
	//movePiece 0 1 1 2
	assert(sBoard.isValidMove(0,1,1,2));
	sBoard.movePiece(0,1,1,2);
	//movePiece 4 3 5 3
	assert(sBoard.isValidMove(4,3,5,3));
	sBoard.movePiece(4,3,5,3);
	//movePiece 1 2 0 3
	assert(sBoard.isValidMove(1,2,0,3));
	sBoard.movePiece(1,2,0,3);
	//movePiece 0 2 5 3
	assert(sBoard.isValidMove(0,2,5,3) == false);
	//movePiece 2 0 3 1
	assert(sBoard.isValidMove(2,0,3,1));
	sBoard.movePiece(2,0,3,1);

	assert(sBoard.isValidMove(1,3,1,4) == false);

	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++){
			std::cout <<"result for(" << i << "," << j << ")\n";
			for(int k = 0; k < 6; k++)
			{
				for(int p = 0; p < 6; p++)
				{
					std::cout << sBoard.isValidMove(i,j,k,p) << " ";
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
			}
		std::cout<<"\n";
		}

	//movePiece 1 3 4 3
	assert(sBoard.isValidMove(1,3,4,3));
	sBoard.movePiece(1,3,4,3);

}

void test_king_piece_6x6_2(){
    Student::ChessBoard sBoard(6, 6);
    sBoard.createChessPiece(Black, King, 2, 4);
    sBoard.createChessPiece(White, Bishop, 0, 1);
	sBoard.createChessPiece(Black, Bishop, 0, 5);
	sBoard.createChessPiece(White, Pawn, 1, 3);
	sBoard.createChessPiece(Black, Bishop, 1, 5);
	sBoard.createChessPiece(White, King, 5, 1);

	assert(sBoard.isValidMove(5,1,4,2));

	for(int i = 0; i < 6; i++) {
		for(int j = 0; j < 6; j++){
			std::cout <<"result for(" << i << "," << j << ")\n";
			for(int k = 0; k < 6; k++)
			{
				for(int p = 0; p < 6; p++)
				{
					std::cout << sBoard.isValidMove(i,j,k,p) << " ";
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
			}
		std::cout<<"\n";
		}

}


void test_king_piece_8x8_10(){
    Student::ChessBoard sBoard(8, 8);
    sBoard.createChessPiece(White, Rook, 0, 0);
    sBoard.createChessPiece(Black, Bishop, 1, 1);
	sBoard.createChessPiece(White, Rook, 2, 1);
	sBoard.createChessPiece(White, King, 2, 3);
	sBoard.createChessPiece(White, Bishop, 3, 1);
	sBoard.createChessPiece(Black, Bishop, 3,3);
	sBoard.createChessPiece(Black, Rook, 5,1);
	sBoard.createChessPiece(White, Rook, 5,7);
	sBoard.createChessPiece(Black, Bishop, 6, 2);
	sBoard.createChessPiece(White, Bishop, 6,7);
	sBoard.createChessPiece(Black, Rook, 7,1);

	//assert(sBoard.isValidMove(0,0,1,0) == false);
	//movePiece 6 2 7 3
	assert(sBoard.isValidMove(6,2,7,3));
	sBoard.movePiece(6,2,7,3);

	/*
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++){
			std::cout <<"result for(" << i << "," << j << ")\n";
			for(int k = 0; k < 8; k++)
			{
				for(int p = 0; p < 8; p++)
				{
					std::cout << sBoard.isValidMove(i,j,k,p) << " ";
				}
				std::cout<<"\n";
			}
			std::cout<<"\n";
			}
		std::cout<<"\n";
		}
		*/

}




int main()
{
	//test_part1_4x4_scan();
	//test_part1_4x4_2_scan();
	//test_king_piece_4x4_1();
	//test_king_piece_4x4_5();
	//test_king_piece_4x4_4();
	//test_king_piece_6x6_5();
	//test_king_piece_6x6_3();
	test_king_piece_8x8_10();
	//test_king_piece_6x6_2();
    return EXIT_SUCCESS;
}
