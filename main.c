#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  srand(time(NULL));

  //Request values
  int trials = 1000000;
  int doors = 3;

  printf("Enter amount of trials and doors (trials doors): ");
  scanf("%d %d", &trials, &doors);

  printf("\nTrials: %d\n", trials);
  printf("Doors: %d\n", doors);

  //Counters
  int stayWins = 0;
  int switchWins = 0;

  //Dont allocate in the loop
  int doorWithCar;
  int initGuess;
  int didGuess;

  for (int i = 0; i < trials; ++i){
    doorWithCar = rand() % doors;
    initGuess = rand() % doors;

    didGuess = initGuess == doorWithCar;

    //Stay behavior
    stayWins += didGuess;

    //Switch behavior
    switchWins += !didGuess;
  }

  printf("\nWithout switching, win rate is %f\n", (float)stayWins / trials);
  printf("With switching, win rate is %f\n", (float)switchWins / trials);

  return 0;
}
