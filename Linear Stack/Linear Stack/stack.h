#pragma once
#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;

typedef struct Stack
{
	ElemType * storage;
	int top;
} *subsequ_stack;

//1,init stack
subsequ_stack init_stack(subsequ_stack a);
//2,come into the stack
void push(subsequ_stack a, const ElemType elem);
//3,get out of the stack
void pop(subsequ_stack a);
//4,stack full
bool stack_full(subsequ_stack a);