//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <stdbool.h>
//#include "../../headers/stc_pessoa.h"

typedef struct _node {
    Pessoa p;
    struct _node *next;
} node;

typedef struct _list {
    node *root;
}list;

list* create_list();
node* create_node();
bool insertion(node *root, node *n);
bool insert(list *l, Pessoa p);
void printl(node *root);
void printList(list *l);
Pessoa searching(node *root, int chave);
Pessoa search(list *l, int chave);
void destroying(node*root);
void destroy(list *l);
void erase_data(node *root, int chave);
void erase(list *l, int chave);
Pessoa front(list *l);
void pop_front(list *l);


list* create_list(){
    list *l = (list*) malloc(sizeof(list));
    if(l != NULL){
        l->root = NULL;
    }
    return l;
}

node* create_node(){
    node *n = (node*) malloc(sizeof(node));
    if(n != NULL){
        n->next = NULL;
    }
    return n;
}

bool insertion(node *root, node *n){
    if(root->next == NULL){
        //insert
        root->next = n;
    } else {
        insertion(root->next, n);
    }
}
bool insert(list *l, Pessoa p){
    node *temp = create_node();
    temp->p = p;
    if(l == NULL){
        return false;
    }
    if(l->root == NULL){
        //lista vazia
        l->root = temp;
        return true;
    }
    return insertion(l->root, temp);
    
}

void printl(node *root){
    if(root == NULL){
        return;
    }
    printPessoa(root->p);
    printl(root->next);
}

void printList(list *l){
    if(l == NULL){
        return ;
    }
    printl(l->root);
    return ;
}

Pessoa searching(node *root, int chave){
    if(root == NULL){
        exit(1);
    }
    if(root->p.chave == chave){
        return root->p;
    } else {
        return searching(root->next, chave);
    }
}
Pessoa search(list *l, int chave){
    return searching(l->root, chave);
}
void destroying(node*root){
    if(root == NULL){
        return;
    }
    destroying(root->next);
    free(root);
}

void destroy(list *l){
    destroying(l->root);
}
void erase_data(node *root, int chave){
    node *temp;
   
    while(root != NULL){
        temp = root; //pai
        root = root->next;
        if(root->p.chave == chave){
            temp->next = root->next;
            free(root);
            return ;
        } 
    }
}

void erase(list *l, int chave){
    node *temp = l->root;
    if(l == NULL){
        return ;
    }
    if(l->root == NULL){
        return ;
    }
     if(temp->p.chave == chave){
        //primeiro elemento da lista
        l->root = l->root->next;
        free(temp);
        return ;
    
    }
    erase_data(l->root, chave);
    return ;
}
Pessoa front(list *l){
    if(l != NULL){
        if(l->root != NULL){
            return l->root->p;
        }
    }
    
}

void pop_front(list *l){
    node *temp = l->root;
    if(l != NULL){
        if(l->root != NULL){
            l->root = l->root->next;
            free(temp);
        }
    }
}