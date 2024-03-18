#include <stdio.h>

int main(void) {
  int month, day, year;

  // Standard date form
  printf("Veuillez entrer un date au formet suivant (dd/mm/yyyy): ");
  // Split the user input into 3 variables for the date
  // Don't worry about the `scanf()` below, you'll learn more about these later!
  scanf("%d /%d /%d", &day, &month, &year);

  // Print the day
  printf("%d ", day);

  // Print the month
  switch(month){
    case 1:
      printf("Janvier");
      break;
    case 2:
      printf("Fevrier");
      break;
    case 3:
      printf("Mars");
      break;
    case 4:
      printf("Avril");
      break;
    case 5:
      printf("Mai");
      break;
    case 6:
      printf("Juin");
      break;
    case 7:
      printf("Juillet");
      break;
    case 8:
      printf("Aout");
      break;
    case 9:
      printf("Septembre");
      break;
    case 10:
      printf("Octobre");
      break;
    case 11:
      printf("Novembre");
      break;
    case 12:
      printf("Decemebre");
      break;
  }

  // Print the year
  printf(" %d\n", year);
  
  return 0;
}