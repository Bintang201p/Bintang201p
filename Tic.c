#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

void drawBoard(char *space);
void getPlayerMove(char *space, char player);
void getComputerMove(char *space, char computer);
bool getWinner(char *space, char player, char computer);
bool getTie(char *space, char player, char computer);



int main()
{
  char player = 'X';
  char computer = 'O';
  char space[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  bool running = true;
  drawBoard(space);

  while(running){
    getPlayerMove(space, player);
    drawBoard(space);
    if(getWinner(space, player, computer)){
      running = false;
      break;
    }
    else if(getTie(space, player, computer)){
      running = false;
      break;
    }

    getComputerMove(space, computer);
    drawBoard(space);
    if(getWinner(space, player, computer)){
      running = false;
      break;
    }
    else if(getTie(space, player, computer)){
      running = false;
      break;
    }
  }
  return 0;
}

void drawBoard(char *space){
  printf("      |     |     \n");
  printf("   %c  |  %c  |   %c\n", space[0], space[1], space[2]);
  printf(" _____|_____|_____\n");
  printf("      |     |     \n");
  printf("   %c  |  %c  |   %c\n", space[3], space[4], space[5]);
  printf(" _____|_____|_____\n");
  printf("      |     |     \n");
  printf("   %c  |  %c  |   %c\n", space[6], space[7], space[8]);
  printf("\n\n\n");
}
void getPlayerMove(char *space, char player){
  int num = 0;
  do{
    printf("Enter a number to start: ");
    scanf("%d", &num);
    num--;
    if(space[num] == ' '){
      space[num] = player;
      break;
    }
  }while(!num > 0 || !num < 8);
}
void getComputerMove(char *space, char computer){
  srand(time(NULL));
   while(true){
     int num = rand() % 8 + 1;
      if(space[num] == ' '){
        space[num] = computer;
        printf("Computer choice is %d!\n", num);
        break;
      }
   }
}
bool getWinner(char *space, char player, char computer){
  if((space[0] != ' ') && space[0] == space[1] && space[1] == space[2]){
    (space[0] == player) ? printf("You win!\n") : printf("You lose!\n");
  }
  else if((space[3] != ' ') && space[3] == space[4] && space[4] == space[5]){
    (space[3] == player) ? printf("You win!\n") : printf("You lose!\n");
  }
  else if((space[6] != ' ') && space[6] == space[7] && space[7] == space[8]){
    (space[6] == player) ? printf("You win!\n") : printf("You lose!\n");
  }
  else if((space[0] != ' ') && space[0] == space[3] && space[3] == space[6]){
    (space[0] == player) ? printf("You win!\n") : printf("You lose!\n");
  }
  else if((space[1] != ' ') && space[1] == space[4] && space[4] == space[7]){
    (space[1] == player) ? printf("You win!\n") : printf("You lose!\n");
  }
  else if((space[2] != ' ') && space[2] == space[5] && space[5] == space[8]){
    (space[2] == player) ? printf("You win!\n") : printf("You lose!\n");
  }
  else if((space[0] != ' ') && space[0] == space[4] && space[4] == space[8]){
    (space[0] == player) ? printf("You win!\n") : printf("You lose!\n");
  }
  else if((space[2] != ' ') && space[2] == space[4] && space[4] == space[6]){
    (space[2] == player) ? printf("You win!\n") : printf("You lose!\n");
  }
  else{
    return false;
  }
  return true;
}
bool getTie(char *space, char player, char computer){
  for(int i = 0; i < 9; i++){
    return false;
  }
  return true;
}
