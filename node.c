#include "stdio.h"
#include "graph.h"
#include "stdlib.h"

pnode getNode(int data, pnode head){
    while (head){
        if (head->node_num == data){
            return head;
        }
        head = head->next;
    }
    return NULL;
}

pnode newnode(int k, pnode next){
    pnode p = (pnode) malloc(sizeof(node));
    if(p==NULL)
        exit(0);
    p->node_num = k;
    p->next = next;
    p->edges = NULL;
    return p;
}



pnode generate(int k){
    pnode head = NULL;
    for (int i=k-1;i>=0;i--){
        head = newnode(i,head);
    }
    return head;
}

void remove_out_edges(pnode here){
    pedge next = here->edges;
    while(next){
        pedge prev = next;
        next = next->next;
        free(prev);
    }
}

void remove_edge_to(int data, pnode here){
    pedge check_edge = here->edges;
    if(check_edge){
        if (check_edge->endpoint->node_num == data){
            pedge delete = check_edge;
            here->edges = check_edge->next;
            free(delete);
            return;
        }
        while(check_edge->next != NULL){
            if (check_edge->next->endpoint->node_num == data){
                pedge delete = check_edge->next;
                check_edge->next = delete->next;
                free(delete);
                return;
            }
            check_edge = check_edge->next;
        }
    }
}

pnode insertNode(int input, pnode *head){
    pnode *current = head;
    while ((*current)->next){
        if((*current)->node_num < input && (*current)->next->node_num > input){
            pnode new_node = newnode(input,(*current)->next);
            (*current)->next = new_node;
            return new_node;
        }
        current = &((*current)->next);
    }
    pnode new_node = newnode(input,(*current)->next);
    (*current)->next = new_node;
    return new_node;
}