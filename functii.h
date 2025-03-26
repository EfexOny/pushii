#pragma once

#include <string.h>
using namespace std;

#define DIM 10

struct element
{
    string data;
    element *succ;
};
typedef element *stiva;


struct element2{
    char data;
    element2 *succ;
};
typedef element2* stiva2;

extern char exprModi[20];
extern int indexModi;

void init(stiva &s);
void init2(stiva2 &s);

bool isEmpty(const stiva &s);
bool isEmpty2(const stiva2 &s);

string top(const stiva &s);
char top2(const stiva2 &s);

void push(stiva &s, string val);
void push2(stiva2 &s,char val);

void pop(stiva &s);
void pop2(stiva2 &s);


void updateStack(stiva &s, char semn);
void updateStack2(stiva2 &s, char semn);

void updateExpresie(char semn);
void updateExpresie2(stiva &s, char semn);

int atribuireSemn(char semn);
int updateEval(char expresie);

int evaluarePrefix(stiva s,string expr);
int ecuatie(int nr1,int nr2,char semn);
