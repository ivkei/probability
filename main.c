#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  srand(time(NULL));

  const int TRIALS = 1000000;
  const int DOORS = 3;

  int stayWins = 0;
  int switchWins = 0;

  //Dont allocate in the loop
  int doorWithCar;
  int initGuess;
  int didGuess;

  for (int i = 0; i < TRIALS; ++i){
    doorWithCar = rand() % DOORS;
    initGuess = rand() % DOORS;

    didGuess = initGuess == doorWithCar;

    //Stay behavior
    stayWins += didGuess;

    //Switch behavior
    switchWins += !didGuess;
  }

  printf("Without switching, win rate is %f\n", (float)stayWins / TRIALS);
  printf("With switching, win rate is %f\n", (float)switchWins / TRIALS);

  return 0;
}
