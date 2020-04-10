#pragma once
#include <stdlib.h>

typedef struct Pose
{
	int x;
	int y;
}pose;


typedef struct Stack
{
	struct Stack* pre;
	struct Pose data;
}stack;

extern stack* head = NULL;

void push(struct Pose cur_pose) {
	if (head == NULL)
	{
		head = (stack*)malloc(sizeof(stack));
		head->data = cur_pose;
		return;
	}
	else
	{
		stack* new_stack = (stack*)malloc(sizeof(stack));
		new_stack->data = cur_pose;
		new_stack->pre = head;
		head = new_stack;
	
	}
}

pose pop() {
	stack* top_stack = head;
	head = top_stack->pre;
	
	return top_stack->data;

}