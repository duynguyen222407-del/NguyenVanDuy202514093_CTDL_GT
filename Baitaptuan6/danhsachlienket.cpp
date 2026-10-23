#include<iostream>
#include<string>
using namespace std;

struct Node {
    string file_name;
    double file_size;
    long time_created;
    Node *next;
};

struct List{
    Node *first_node;
};

void List_init(List *list){
    list -> first_node = 0;
}

Node *create_file(string name, double size, long time){
    Node *new_node = new Node;
    new_node -> file_name = name;
    new_node -> file_size = size;
    new_node -> time_created = time;
    new_node -> next = 0;
    return new_node;
}

void insert_file(List *list, string name, double size, long time){
    Node *new_node = create_file(name, size, time);
    if (list -> first_node == 0){
        list -> first_node = new_node;
        return;
    }
    Node *ptr = list -> first_node;
    Node *tmp = ptr;
    while(ptr -> next != 0 && ptr -> time_created < time){
        tmp = ptr;
        ptr = ptr -> next;
    }
    if (ptr -> time_created < time){
        ptr -> next = new_node;
    }
    else {
        new_node -> next = ptr;
        tmp -> next = new_node;
    }
}
