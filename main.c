﻿#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#include "function.h"
#include "Euler.h"

#define SIZE 2

int main()
{	
   setlocale(LC_ALL, "Rus");

   /*int value = 0;
   int array[SIZE];

   printf("value = ");
   scanf_s("%d", &value);

   printf("array = ");
   for (unsigned int i = 0; i < SIZE; ++i)
      scanf_s("%d", &array[i]);

   printf("answer = %llu\n", Problem_1(value, array, SIZE));
   */

   /*int value = 0;
   printf("value = ");
   scanf_s("%d", &value);

   printf("answer = %llu\n", Problem_2(value));
   */

   /*
   long long value_ = 0;
   printf("value = ");
   scanf_s("%llu", &value_);
   printf("answer = %llu\n", Problem_3(value_));
   */
   //600851475143  13195
   
   /*
   printf("%llu", Problem_4());
   */

   /*
   printf("%llu\n", Problem_5(20));
   */

   /*
   unsigned int quantity = 0;
   printf("quantity = ");
   scanf_s("%d", &quantity);
   printf("answer = %d\n", Problem_6(quantity));
   */


   ////////////////Работа с файлами//////////////////////////////////////////////////////////////////

   FILE* file;
   errno_t err = fopen_s(&file, "file.txt", "r"); // открытие файла на чтение

   if (err != 0 || !file)
   {
      perror("File cant't open!");
      return 1;
   }
   /*
   char line[255];
   fgets(line, 255, file);
   printf("%s\n", line);
   fgets(line, 255, file);
   printf("%s\n", line);
   */

   /*
   char SrcStr[] = "Hello, world!";
   char DestStr[100];
   СopyStr(SrcStr, DestStr);
   printf("Скопированная строка: %s\n", DestStr);
   printf("Длина строки: %d", StrLen(SrcStr));
   */
   
   /*
   char str1[20] = "Hello, ";
   char str2[] = "world!";
   StrCat(str1, str2);
   printf("%s\n", str1);
   */

   /*
   char* str1 = "Hell";
   char* str2 = "Hello";
   СompareStr(str1, str2);
   */
   
   /* function not working
   char line[255];
   ReadLine(file, line);
   printf("%s\n", line);
   */

   /*
   char line[100];
   printf("%d\n", fGetLine(line, file)); // длина считанной строки
   printf("%s\n", line);                 // считанная строка 
   */
   
   /*
   char* str = "Hell";
   int res = MyStrLen(str);
   printf("%d", res);
   */

   float x = 1.123456789f;
   double y = 1.12345678987654321;

   int d = 10;
   int* p;
   //int* const p = &d;
   p = &d;
   *p = 100;
   //printf("%d", d);
   //printf("%d %d", d, *p);
   //printf("%llu", sizeof(int));

   //int r = getc(file);
   //printf("%d", r);
   

  
   return 0;
}

