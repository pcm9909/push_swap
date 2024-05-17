#pragma once

typedef struct s_node
{
    struct s_node *prev;
    int data;
    int idx;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    int size;
    t_node *head;
    t_node *tail;
} t_stack;