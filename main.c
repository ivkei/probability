#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
  int gate1;
  int gate2;
  int gate3;
} Gates;

static void DeselectGate(Gates* pGates){
  pGates->gate1 = 0;
  pGates->gate2 = 0;
  pGates->gate3 = 0;
}

static void SelectGate(Gates* pGates){
  int whichGate = rand() % 3;

  int* pTrueGate = (int*)((char*)pGates + whichGate * sizeof(int));

  *pTrueGate = 1;
}

static int* GuessGateOutOf3(Gates* pGates){
  int whichGate = rand() % 3;
  int* pGate = (int*)((char*)pGates + whichGate * sizeof(int));
  return pGate;
}

static int* GuessGateOutOf2(Gates* pGates, void* pAvoidGate){
  int* pGate = pAvoidGate;

  while (pGate == pAvoidGate){
    int whichGate = rand() % 3;

    pGate = (int*)((char*)pGates + whichGate * sizeof(int));
  }

  return pGate;
}

int main() {
  srand(time(NULL));

  const int NUM_TRIALS = 100000000;
  int wins = 0;

  Gates gates;

  //Without switching
  for (int i = 0; i < NUM_TRIALS; ++i){
    DeselectGate(&gates);
    SelectGate(&gates);

    if (*GuessGateOutOf3(&gates) == 1){
      ++wins;
    }
  
  }
  printf("Without switching, win rate is %f\n", (float)wins / NUM_TRIALS);

  //With switching
  for (int i = 0; i < NUM_TRIALS; ++i){
    DeselectGate(&gates);
    SelectGate(&gates);
    int* pAvoidGate = GuessGateOutOf3(&gates);
    if (*GuessGateOutOf2(&gates, pAvoidGate) == 1){
      ++wins;
    }
  }
  printf("With switching, win rate is %f\n", (float)wins / NUM_TRIALS);

  return 0;
}
