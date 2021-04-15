#pragma once

#define  _CRT_SECURE_NO_WARNINGS 1
#define NAME_MAX 10
#define TELE_MAX 14
#define INIT_NUM 4

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct PeoInfo
{
	char name[NAME_MAX];
	char tele[TELE_MAX];
	int age;
}PeoInfo;

typedef struct Contcat
{
	int sz;
	int capacity;
	PeoInfo *message;
}Contact;

void InitContact(Contact *s);
void AddContact(Contact *s);
void PrintContact(Contact *s);
void DeletContact(Contact *s);
int CheckContact(Contact *s, char *name);