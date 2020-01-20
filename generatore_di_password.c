#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char ** argv){
  START:
  printf("Inserire la lunghezza desiderata della password (minimo 4 caratteri, massimo 32)\n");
  int length;
  scanf("%d", &length);
  if(length < 4){
    printf("Valore inserito troppo piccolo, il minimo è 4\n");
    goto START;
  }
  if(length > 32){
    printf("Valore inserito troppo grande, il massimo è 32\n");
    goto START;
  }
  char password[length + 1];
  time_t hour;
  time(&hour);
  srand(hour);
  for(int i = 0; i < length; ++i){
    int value;
    do{
      value = rand() % 128;
    } while((value < 33) || (value > 57 && value < 65) || (value > 90 && value < 97) || (value >122));
    char character = (char) value;
    password[i] = character;
  }
  password[length] = '\0';
  printf("%s\n",password);
}
