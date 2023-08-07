#include<stdio.h>
#include<stdlib.h>

int Rock_paper_Scissor()
{ 
 int computer, you, random; 

 computer = 0; 
 you = 0; 

 while (1) 
 { 
  printf("\n\t\t\t\tWelcome To Rock Paper Scissor Game\n\n\n"); 
  printf("\t\t\tPlease Choose one of the below option\n\n"); 
  printf("\t\t\t\t1. Rock \t 2.Paper \t 3.Scissor \n\n"); 
  printf("\t\t\t\t Your Choice: "); 

  scanf("%d", &you); 

  random = rand() % 3 + 1; 

  if (random == 1) 
   printf("\t\t\t\t Computer's choice is: Rock\n"); 
  else if (random == 2) 
   printf("\t\t\t\t Computer's choice is: Paper\n"); 
  else if (random == 3) 
   printf("\t\t\t\t Computer's choice is: Scissor\n"); 

  
  if (you == computer) 
   printf("\n\t\t\t\tGame draw\n"); 
  else if (you == 1 && random == 2) 
   printf("\n\t\t\t\tComputer Wins\n"); 
  else if (you == 2 && random == 1) 
   printf("\n\t\t\t\tYou Win\n"); 
  else if (you == 1 && random == 3) 
   printf("\n\t\t\t\tYou Win\n"); 
  else if (you == 3 && random == 1) 
   printf("\n\t\t\t\tComputer Wins\n"); 
  else if (you == 2 && random == 3) 
   printf("\n\t\t\t\tComputer Wins\n"); 
  else if (you == 3 && random == 2) 
   printf("\n\t\t\t\tYou Win\n"); 

  
  char ch; 
  printf("\n\n\t\t\t\tDo you want to play again (y/n): "); 
  scanf(" %c", &ch); 
  if (ch == 'y' || ch == 'Y') 
   continue; 
  else
   break; 
 } 
 return 0; 
}
void main() {
    Rock_paper_Scissor();
}