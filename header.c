#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include<conio.h>
//==============================================================================
void gotoxy(int x, int y) {

    printf("\033[%d;%dH", y, x);

return;
}
//==============================================================================
int splashScreen(){

  system("cls");
    gotoxy(46, 11);
  printf("NUMBER SYSTEM CONVERTER\n");
    gotoxy(39, 12);
  printf("Program Created by Jon Erlo T. Hermosa.\n");
    gotoxy(59, 13);
  sleep(4);
  system("cls");

  return 0;
}
//==============================================================================
int getOpt(){
int opt;

  system("cls");
  gotoxy(42, 9);
  printf("Choose a number system to convert from. \n");
  printf("\n");
  gotoxy(55, 11);
  printf("1. Binary \n");
  gotoxy(55, 12);
  printf("2. Octal \n");
  gotoxy(55, 13);
  printf("3. Decimal \n");
  gotoxy(55, 14);
  printf("4. Hexadecimal \n");
  gotoxy(55, 15);
  printf("5. Exit\n\n");
  gotoxy(50, 17);
  printf("Enter option: ");
  scanf("%d", &opt);

return opt;
}
//==============================================================================
int getBin(int opt){
  long long binary;

  if(opt == 1){

    system("cls");
    gotoxy(50, 10);
    printf("You have selected BINARY\n");

    int binaryToDecimal(long binary) {
        long long decimal = 0, i = 0, remainder;
        while (binary != 0) {
            remainder = binary % 10;
            binary /= 10;
            decimal += remainder * (1 << i);
            ++i;
        }
        return decimal;
    }

    int binaryToOctal(long binary) {
        long long octal = 0, decimal = 0, i = 0;
        while (binary != 0) {
            decimal += (binary % 10) * (1 << i);
            ++i;
            binary /= 10;
        }
        i = 1;
        while (decimal != 0) {
            octal += (decimal % 8) * i;
            decimal /= 8;
            i *= 10;
        }
        return octal;
    }

    long long binaryToHexadecimal(long binary) {
        long long decimal = 0, i = 0;
        long long hexadecimal = 0;
        while (binary != 0) {
            decimal += (binary % 10) * (1 << i);
            ++i;
            binary /= 10;
        }
        i = 0;
        while (decimal != 0) {
            hexadecimal += (decimal % 16) * (1 << (4 * i));
            ++i;
            decimal /= 16;
        }
        return hexadecimal;
    }

    gotoxy(45, 12);
    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    long long decimal = binaryToDecimal(binary);
    long long octal = binaryToOctal(binary);
    long long hexadecimal = binaryToHexadecimal(binary);

    system("cls");
    gotoxy(55, 10);
    printf("RESULTS: \n");
    gotoxy(52, 12);
    printf("Decimal: %d\n", decimal);
    gotoxy(52, 13);
    printf("Octal: %d\n", octal);
    gotoxy(52, 14);
    printf("Hexadecimal: %llx\n", hexadecimal);
    gotoxy(44, 16);
    system("pause");
  }
return 0;
}
//==============================================================================
int getOct(int opt){
  char octal[20];

  if(opt==2){
    system("cls");
    gotoxy(50, 10);
    printf("You have selected OCTAL.\n");

    gotoxy(45, 12);
    printf("Enter an octal number: ");
    scanf("%s", octal);

    system("cls");
    gotoxy(55, 10);
    printf("RESULTS:\n");

    int decimal = 0;
    int length = strlen(octal);
    for (int i = 0; i < length; i++) {
        decimal = decimal * 8 + (octal[i] - '0');
    }

    gotoxy(52, 12);
    printf("Decimal: %d\n", decimal);

    long binary = 0;
    int remainder, base = 1;
    int temp_decimal = decimal;
    while (temp_decimal > 0) {
        remainder = temp_decimal % 2;
        binary += remainder * base;
        temp_decimal /= 2;
        base *= 10;
    }

    gotoxy(52, 13);
    printf("Binary: %ld\n", binary);

    char hexadecimal[100];
    int i = 0;
    while (decimal != 0) {
        int temp = 0;
        temp = decimal % 16;
        if (temp < 10) {
            hexadecimal[i] = temp + 48;
            i++;
        } else {
            hexadecimal[i] = temp + 55;
            i++;
        }
        decimal /= 16;
    }

    gotoxy(52, 14);
    printf("Hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }

  gotoxy(44, 16);
  system("pause");
  }
  return 0;
}
//==============================================================================
int getDec(int opt){

  if(opt==3){
    system("cls");
    gotoxy(50, 10);
    printf("You have selected DECIMAL.\n");

    void decimalToBinary(int decimal) {
        long binary = 0;
        int remainder, base = 1;
        int temp_decimal = decimal;
        while (temp_decimal > 0) {
            remainder = temp_decimal % 2;
            binary += remainder * base;
            temp_decimal /= 2;
            base *= 10;
        }
        printf("Binary: %ld\n", binary);
    }

    void decimalToOctal(int decimal) {
        int octal = 0, temp = 0, i = 1;
        while (decimal != 0) {
            temp += (decimal % 8) * i;
            decimal /= 8;
            i *= 10;
        }
        printf("Octal: %d\n", temp);
    }

    void decimalToHexadecimal(int decimal) {
        char hexadecimal[100];
        int i = 0;
        while (decimal != 0) {
            int temp = 0;
            temp = decimal % 16;
            if (temp < 10) {
                hexadecimal[i] = temp + 48;
                i++;
            } else {
                hexadecimal[i] = temp + 55;
                i++;
            }
            decimal /= 16;
        }
        printf("Hexadecimal: ");
        for (int j = i - 1; j >= 0; j--) {
            printf("%c", hexadecimal[j]);
        }
        printf("\n");
    }

    int decimal;
    gotoxy(45, 12);
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    system("cls");
    gotoxy(55, 10);
    printf("RESULTS:\n");
    gotoxy(52, 12);
    decimalToBinary(decimal);
    gotoxy(52, 13);
    decimalToOctal(decimal);
    gotoxy(52, 14);
    decimalToHexadecimal(decimal);

    gotoxy(44, 16);
    system("pause");
  }
  return 0;
}
//==============================================================================
int getHex(int opt){
   char hex[100];

  if(opt==4){
  system("cls");
  gotoxy(50, 10);
  printf("You have selected HEXADECIMAL.\n");

  gotoxy(45, 12);
  printf("Enter a hexadecimal number: ");
  scanf("%s", hex);

  system("cls");
  gotoxy(55, 10);
  printf("RESULTS: \n");

  gotoxy(52, 12);
  printf("Binary: ");
  for(int i = 0; hex[i] != '\0'; i++) {
      switch(hex[i]) {
          case '0':
              printf("0000");
              break;
          case '1':
              printf("0001");
              break;
          case '2':
              printf("0010");
              break;
          case '3':
              printf("0011");
              break;
          case '4':
              printf("0100");
              break;
          case '5':
              printf("0101");
              break;
          case '6':
              printf("0110");
              break;
          case '7':
              printf("0111");
              break;
          case '8':
              printf("1000");
              break;
          case '9':
              printf("1001");
              break;
          case 'A':
          case 'a':
              printf("1010");
              break;
          case 'B':
          case 'b':
              printf("1011");
              break;
          case 'C':
          case 'c':
              printf("1100");
              break;
          case 'D':
          case 'd':
              printf("1101");
              break;
          case 'E':
          case 'e':
              printf("1110");
              break;
          case 'F':
          case 'f':
              printf("1111");
              break;
          default:
              printf("\nInvalid hexadecimal digit %c", hex[i]);
      }
  }

  gotoxy(52, 13);
  printf("Decimal: %ld\n", strtol(hex, NULL, 16));
  long decimal = strtol(hex, NULL, 16);

  gotoxy(52, 14);
  printf("Octal: %lo\n", decimal);

    gotoxy(44, 16);
    system("pause");
  }
  return 0;
}
//==============================================================================
int sysExit(int opt){
  if(opt == 5){
    system("cls");
    printf("\n");
    gotoxy(45, 10);
    exit(0);
  }
  return 0;
}
//==============================================================================
int getInvalid(int opt){
  int i;

    if(opt > 5){
      system("cls");
      gotoxy(45, 10);
      printf("Invalid Input. Please try again.");
      sleep(2);
      system("cls");
  }

  return 0;
}
//==============================================================================
int menu(){

  int option = getOpt();
  getBin(option);
  getOct(option);
  getDec(option);
  getHex(option);
  sysExit(option);
  getInvalid(option);

  return menu();
}
//==============================================================================
