/*
    filename: rps.cpp
    Author: Abdurrahman Alyajouri
    Purpose: generate a seeded game of rock paper scissors
    Date: 2/4/2023
*/

#include <iostream>
using namespace std;

int main() {

   const int ROCK = 0;
   const int PAPER = 1;
   const int SCISSORS = 2;
   
   string player1,
          player2;

   int seed,
       numRounds,
       counter,
       rVal1,
       rVal2,
       score1,
       score2;
       
   cout << "Enter a seed, player 1 and player 2's names, and the desired number of rounds in that order\n";
       
   cin >> seed
       >> player1
       >> player2
       >> numRounds;
       
   srand(seed);

   while(numRounds < 1) {
       cin >> numRounds;
       cout << "Rounds must be > 0\n";
   }
   
   cout << player1 << " vs " << player2 << " for " << numRounds << " rounds\n";
   
   score1 = 0;
   score2 = 0;
   counter = 0;
   
   while(counter < numRounds) {
       rVal1 = rand() % 3;
       rVal2 = rand() % 3;
       
       while(rVal1 == rVal2) {
           cout << "Tie\n";
            rVal1 = rand() % 3;
            rVal2 = rand() % 3;
       }
       
       switch(rVal1) {
           case ROCK: if(rVal2 == SCISSORS) {
                            cout << player1 << " wins with rock\n";
                            score1 += 1;
                      } break;
           case SCISSORS: if(rVal2 == PAPER) {
                            cout << player1 << " wins with scissors\n";
                            score1 += 1;
                          } break;
           case PAPER: if(rVal2 == ROCK) {
                            cout << player1 << " wins with paper\n";
                            score1 += 1;
                       } break;
           default: score1 = 0;
                    break;
       }
       
       switch(rVal2) {
           case ROCK: if(rVal1 == SCISSORS) {
                            cout << player2 << " wins with rock\n";
                            score2 += 1;
                      } break;
           case SCISSORS: if(rVal1 == PAPER) {
                            cout << player2 << " wins with scissors\n";
                            score2 += 1;
                          } break;
           case PAPER: if(rVal1 == ROCK) {
                            cout << player2 << " wins with paper\n";
                            score2 += 1;
                       } break;
           default: score2 = 0;
                    break;
       }
       counter++;
   }
   
 
   cout << player1 << " wins " << score1 << " and " << player2 << " wins " << score2 << "\n";
   
   return 0;

}
