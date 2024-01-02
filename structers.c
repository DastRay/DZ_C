#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "structers.h"

void addEmployee(Employees_storage* storage_, const char* surname_, const char* name_, const char* ptrnmc_, const char* post_, \
   const char* sex_, const int hire_date_d_, const int hire_date_m_, const int hire_date_y_)
{
   if (storage_->num_empl < MAX_EMPL_NUM)
   {
      Employee new_employee;

      strcpy_s(new_employee.surname, sizeof(new_employee.surname), surname_);
      strcpy_s(new_employee.name, sizeof(new_employee.name), name_);
      strcpy_s(new_employee.ptrnmc, sizeof(new_employee.ptrnmc), ptrnmc_);
      strcpy_s(new_employee.post, sizeof(new_employee.post), post_);
      strcpy_s(new_employee.sex, sizeof(new_employee.sex), sex_);
      new_employee.hiredate_d = hire_date_d_;
      new_employee.hiredate_m = hire_date_m_;
      new_employee.hiredate_y = hire_date_y_;

      storage_->employee[storage_->num_empl] = new_employee;
      storage_->num_empl++;
   }

   else
   {
      printf("��������� ���������! �������� ������ ���������� ����������");
   }
}

void printStorage(const Employees_storage* storage_)
{
   printf("�������� � �����������:\n-------------------------------------\n");

   for (int i = 0; i < storage_->num_empl; i++)
   {
      printf("��������� �%d\n", i + 1);
      printf("�������: %s\n", storage_->employee[i].surname);
      printf("���: %s\n", storage_->employee[i].name);
      printf("��������: %s\n", storage_->employee[i].ptrnmc);
      printf("���������: %s\n", storage_->employee[i].post);
      printf("���: %s\n", storage_->employee[i].sex);
      printf("���� ����� �� ������: %d-%d-%d\n", storage_->employee[i].hiredate_d, storage_->employee[i].hiredate_m, storage_->employee[i].hiredate_y);
      printf("-------------------------------------\n");
   }
}

void checkExp(const Employees_storage* storage_, int day_, int month_, int year_, int exp_)
{
   printf("����������, ���� ������� ��������� %d ���:\n", exp_);
   printf("-------------------------------------\n");

   for (int i = 0; i < storage_->num_empl; i++)
   {
      if ((storage_->employee[i].hiredate_y < year_) || (storage_->employee[i].hiredate_y == year_ && storage_->employee[i].hiredate_m < month_) || (storage_->employee[i].hiredate_y == year_ && storage_->employee[i].hiredate_m == month_ && storage_->employee[i].hiredate_d < day_))
      {
         printf("��������� �%d\n", i + 1);
         printf("�������: %s\n", storage_->employee[i].surname);
         printf("���: %s\n", storage_->employee[i].name);
         printf("��������: %s\n", storage_->employee[i].ptrnmc);
         printf("���������: %s\n", storage_->employee[i].post);
         printf("���: %s\n", storage_->employee[i].sex);
         printf("���� ����� �� ������: %d-%d-%d\n", storage_->employee[i].hiredate_d, storage_->employee[i].hiredate_m, storage_->employee[i].hiredate_y);
         printf("-------------------------------------\n");
      }
   }
}

void readFile(FILE* file)
{
   Employees_storage employees;
   employees.num_empl = 0;

   char sur_name[MAX_NAME_LEN];
   char na_me[MAX_NAME_LEN];
   char ptr_nmc[MAX_NAME_LEN];
   char po_st[MAX_POST_LEN];
   char s_ex[MAX_SEX_LEN];
   int hire_date_d;
   int hire_date_m;
   int hire_date_y;

   printf("������ � ����������� �������� �����������.\n");
   int count = 0;

   while (count < MAX_EMPL_NUM)
   {
      if (feof(file))
      {
         printf("��� ������ ������� ������� �������.\n");
         printf("\n");
         break;
      }
      else
      {
         fscanf_s(file, "%s", sur_name, MAX_NAME_LEN);
         fscanf_s(file, "%s", na_me, MAX_NAME_LEN);
         fscanf_s(file, "%s", ptr_nmc, MAX_NAME_LEN);
         fscanf_s(file, "%s", po_st, MAX_POST_LEN);
         fscanf_s(file, "%s", s_ex, MAX_SEX_LEN);
         fscanf_s(file, "%d-%d-%d", &hire_date_d, &hire_date_m, &hire_date_y);

         addEmployee(&employees, sur_name, na_me, ptr_nmc, po_st, s_ex, hire_date_d, hire_date_m, hire_date_y); // ���������� ����������
         count++;
      }
   }

   Mymenu(&employees, file);

   //printStorage(&employees); //����� ���� �����������
   //checkExp(&employees); //����� �����������, ���� ������� ��������� ... ���
}

void Mymenu(const Employees_storage* storage_, FILE* file)
{
   unsigned int f = 0;
   while (1)
   {
      printf("0 - ������� ���������\n1 - ������� ������ � ���� �����������\n2 - ������� ������ � �����������, ���� ������� ������ n-���\n\
3 - �������� ����������\n�������� ��������: ");
      scanf_s("%u", &f);
      printf("\n");

      switch (f)
      {
      case 0:
      {
         printf("����������� ����� �� ���������");
         exit(1);
      }
      case 1:
      {
         printStorage(storage_);
         printf("\n");
         break;
      }
      case 2:
      {
         unsigned int date[4]; //date[0] - �����, date[1] - �����, date[2] - ���, date[3] - ����
         printf("������� ������� ���� � ������� ��-��-����: ");
         scanf_s("%u-%u-%u", &date[0], &date[1], &date[2]);
         printf("������� ���� (���������� ���): ");
         scanf_s("%u", &date[3]);
         printf("\n");
         checkExp(storage_, date[0], date[1], date[2] - date[3], date[3]);
         printf("\n");
         break;
      }
      case 3:
      {
         char sur_name[MAX_NAME_LEN];
         char na_me[MAX_NAME_LEN];
         char ptr_nmc[MAX_NAME_LEN];
         char po_st[MAX_POST_LEN];
         char s_ex[MAX_SEX_LEN];
         unsigned int datee[3]; //datee[0] - �����, datee[1] - �����, datee[2] - ���
         printf("���������� ����������:\n");
         printf("������� �������: ");
         scanf_s("%s", sur_name, MAX_NAME_LEN);
         printf("������� ���: ");
         scanf_s("%s", na_me, MAX_NAME_LEN);
         printf("������� ��������: ");
         scanf_s("%s", ptr_nmc, MAX_NAME_LEN);
         printf("������� ���������: ");
         scanf_s("%s", po_st, MAX_POST_LEN);
         printf("������� ���: ");
         scanf_s("%s", s_ex, MAX_SEX_LEN);
         printf("������� ���� ����� �� ������ ��-��-����: ");
         scanf_s("%u-%u-%u", &datee[0], &datee[1], &datee[2]);
         addEmployee(storage_, sur_name, na_me, ptr_nmc, po_st, s_ex, datee[0], datee[1], datee[2]);

         fputs("\n", file);
         fprintf(file, "%s %s %s %s %s ", sur_name, na_me, ptr_nmc, po_st, s_ex);
         fprintf(file, "%u-%u-%u", datee[0], datee[1], datee[2]);

         printf("��������� ������� ��������.\n");
         printf("\n");
         break;
      }
      default:
         printf("�������� ��������\n");
         break;
      }
   }
}