#include <stdio.h>
 
int main() {
 
  double weight;
  int x;
 
  printf("Veuillez entrer votre poid Terrestre: ");
  scanf("%lf", &weight);
  int terre = weight;
 
  printf("\nJ'ai des informations pour les planetes suivantes :\n\n");
  printf("\t1. Mercure\t2. Venus\t3. Mars\t\t4. Jupiter\n");
  printf("\t5. Saturne\t6. Uranus\t7. Neptune\n\n");
 
  printf("Quel planete visitez vous ? ");
  scanf("%d", &x);
 
  switch(x){
    case 1:
      weight *= .38;
      break;
    case 2:
      weight *= .91;
      break;
    case 3:
      weight *= .38;
      break;
    case 4:
      weight *= 2.34;
      break;
    case 5:
      weight *= 1.06;
      break;
    case 6:
      weight *= 0.92;
      break;
    case 7:
      weight *= 1.19;
      break;
  }
  if (weight == terre)
  {
    printf("Erreur, veuillez entrer un numero correct.");
  }
  else{
    printf("\nVotre poid: %lfKg\n", weight);
  }
}
