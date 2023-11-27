#pragma once
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#ifndef _FUNCTION_H_
#define _FUNCTION_H_

int Mult2(int value_);

/*
* @breaf ������� �������� ����� �� ��������
* @param x: �����, ������� �����������
* @return 1 - ���� ������� �����, 0 - ���� ������� �������
*/
int Prime(unsigned long long int x);

/*
* @breaf ������� �������� ����� �� ���������
* @param number_: ��c��, ������� �����������
* @return ��������� ��� ���
*/
bool IsPalindrome(const unsigned int number_);

/*
* @breaf ������� ����������� ���� ������ �� �����
* @param line_: ������, � ������� ��������� 
* @param FILE* f_: ����, �� �������� �������� ������
* @return ����� ������
*/
int fGetLine(char* line_, FILE* f_);
/*
* @breaf ������� �������������� ����� ������
* @param str_: ������, ����� ������� ������������ 
* @return ����� ������ 
*/
unsigned int StrLen(const char* str_);

/*
* @breaf ������� �������������� ����� ������
* @param str_: ������, ����� ������� ������������
* @return ����� ������
*/
int MyStrLen(char* str_);
/*
* @breaf ������� ����������� ����� ������ � ������
* @param src_: ���������� ������
* @param dest_: ������, � ������� ��������
*/
void �opyStr(char* src_, char* dest_);

/*
* @breaf ������� ������������ ����� ������ � ������
* @param src_: ������ � ������� ����������� ������ ������
* @param dest_: ������ ������� ����������� � ������
*/
void StrCat(char* dest_, const char* src_);

/*
* @breaf ������� ������������ ��� ������
* @param str1: ������ ������
* @param str2: ������ ������ 
*/
void �ompareStr(const char* str1, const char* str2);

/*
* @breaf ������� ����������� ���� ������ �� �����
* @param file_: ���� �� ������� ��������� ������
* @param line_: ������
*/
//void ReadLine(FILE* file_, char* line_); not working
#endif
  