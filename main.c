//#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#include "structers.h"


int main()
{
   //setlocale(LC_ALL, "Rus");

   system("chcp 1251");
   system("cls");
  
   FILE* file;
   errno_t err = fopen_s(&file, "file.txt", "a+");

   if (err != 0 || !file)
   {
      perror("File cant't open!");
      return 1;
   }

   readFile(file);

   //time_t mytime = time(NULL);
   //struct tm* now = localtime(&mytime);
   //printf("%d %d", now->tm_hour, now->tm_min);

   return 0;
}

