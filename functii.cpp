#include <iostream>
#include <string.h>
#include "functii.h"

using namespace std;

char exprModi[20];
int indexModi = 0;

int nrez=0; 

void init(stiva &s)
{
    s = 0;
}

void init2(stiva2 &s)
{
    s = 0;
}

bool isEmpty(const stiva &s)
{
    if (s == 0)
        return true;
    else
        return false;
}

bool isEmpty2(const stiva2 &s)
{
    if(s==0)
        return true;
    else
        return false;
}




string top(const stiva &s)
{
    if (!isEmpty(s))
    {
        return s->data;
    }
    else
    {
        // cout << "e goala";
        return " ";
    }
}

char top2(const stiva2 &s)
{   
    if(!isEmpty2(s)){
        return s->data;
    }
    else
    {
        // cout<<"e goala";
        return -1;
    }
}

void push(stiva &s, string val)
{
    element *p = new element;
    p->data = val;
    p->succ = s;
    s = p;
}
void push2(stiva2 &s,char val)
{
    element2 *p = new element2;
    p->data = val;
    p->succ=s;
    s=p;   
}

void pop(stiva &s)
{
    if (!isEmpty(s))
    {
        element *p = s;
        s = s->succ;
        delete p;
    }
    else
    {
        cout << "e goala";
    }
}

void pop2(stiva2 &s)
{
    if(!isEmpty2(s))
    {
        element2 *p=s;
        s=s->succ;
        delete p;
    }   
    else
    {
        cout<<"e goala";
    } 
}



int atribuireSemn(char semn)
{
    int val = -1;

    switch (semn)
    {
    case '*':
        val = 2;
        break;

    case '/':
        val = 2;
        break;

    case '+':
        val = 1;
        break;

    case '-':
        val = 1;
        break;

    case '(':
        val = 0;
        break;

    case ')':
        val = 3;
        break;
    }
    return val;
}

void updateStack2(stiva2 &s,char semn)
{

    int x,y;
    y=atribuireSemn(semn);

    if(isEmpty2(s) || y==0 )
    {
        push2(s,semn);
    }
    else
    {
        if(y==3)
        {
            while(!isEmpty2(s) && top2(s)!='(')
            {
                updateExpresie(top2(s));
                pop2(s);
            }
            pop2(s);
        }
        else
            if(y<=atribuireSemn(top2(s)))
            {
                while( !isEmpty2(s) && y<=atribuireSemn(top2(s)) )
                {
                    updateExpresie(top2(s));
                    pop2(s);
                }
                push2(s,semn);
            }
            else
            {
                push2(s,semn);
            }
        }
}

void updateStack(stiva &s, char semn)
{
    push(s, string(1, semn));
}

void updateExpresie(char semn)
{
    exprModi[indexModi++] = semn;
}

void updateExpresie2(stiva &s, char semn)
{

    string expresieStiva = "";
    string semiE = "";

    for (int i = 0; i < 2 && !isEmpty(s); i++)
    {
        expresieStiva = top(s) + expresieStiva;
        pop(s);
    }

    int start = 0, end = expresieStiva.length();

    semiE = semn + expresieStiva;

    push(s, semiE);
}

int updateEval(char expresie)
{
    return 1;
}




int evaluarePrefix(stiva s,string expr)
{
    int rez=0;

    for(int i=expr.length()-1;i>=0;i--)
    {
        if(!isdigit(expr[i]))
        {
            
            int nr1,nr2;
            string n1,n2;
           

                n2=top(s);
                pop(s);
                n1=top(s);
                pop(s);
    
                nr2=n2[0] -'0';
                nr1=n1[0] -'0';

                rez = ecuatie(nr2,nr1,expr[i]);

                cout<<endl<<nr2<<" "<<expr[i]<<" "<<nr1<<" = "<<rez<<" "<<endl;

                push(s,to_string(rez));

        }
        else
        {
            push(s,string(1,expr[i]));
        }
    }
    return rez;
}

int ecuatie(int nr1,int nr2,char semn)
{
    switch (semn)
    {
        case '*':
        return nr1*nr2;
        break;

        case '/':
        return nr1/nr2;
        break;

        case '+':
        return nr1+nr2;
        break;

        case '-':
        return nr1-nr2;
        break;

        default:
        return 0;
    }
}
