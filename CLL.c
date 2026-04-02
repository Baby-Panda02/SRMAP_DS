//CLL
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *last=NULL;
int read_int(){
    int x;
    while(scanf("%d",&x)!=1){
        printf("Invalid input! Enter integer: ");
        while(getchar()!='\n');
    }
    return x;
}
struct node* create(int v){
    struct node *n=malloc(sizeof(struct node));
    n->data=v; n->next=NULL;
    return n;
}
void insert_begin(){
    printf("Value: "); int v=read_int();
    struct node *n=create(v);
    if(!last){
        last=n;
        last->next=last;
        return;
    }
    n->next=last->next;
    last->next=n;
}
void insert_end(){
    printf("Value: "); int v=read_int();
    struct node *n=create(v);

    if(!last){
        last=n;
        last->next=last;
        return;
    }

    n->next=last->next;
    last->next=n;
    last=n;
}

void insert_pos(){
    int pos,i;
    printf("Position: "); pos=read_int();
    printf("Value: "); int v=read_int();

    if(!last || pos==1){ insert_begin(); return; }

    struct node *t=last->next,*n=create(v);

    for(i=1;i<pos-1;i++){
        t=t->next;
        if(t==last->next){
            printf("Invalid position\n");
            free(n);
            return;
        }
    }

    n->next=t->next;
    t->next=n;

    if(t==last) last=n;
}

void delete_begin(){
    if(!last){ printf("Empty list\n"); return; }

    struct node *t=last->next;

    if(last==last->next){
        free(last);
        last=NULL;
        return;
    }

    last->next=t->next;
    free(t);
}

void delete_end(){
    if(!last){ printf("Empty list\n"); return; }

    if(last==last->next){
        free(last);
        last=NULL;
        return;
    }

    struct node *t=last->next;

    while(t->next!=last)
        t=t->next;

    t->next=last->next;
    free(last);
    last=t;
}

void delete_pos(){
    int pos,i;
    printf("Position: "); pos=read_int();

    if(pos==1){ delete_begin(); return; }

    struct node *t=last->next,*p;

    for(i=1;i<pos;i++){
        p=t;
        t=t->next;
        if(t==last->next){
            printf("Invalid position\n");
            return;
        }
    }

    p->next=t->next;

    if(t==last) last=p;

    free(t);
}

void display(){
    if(!last){ printf("Empty list\n"); return; }

    struct node *t=last->next;

    do{
        printf("%d -> ",t->data);
        t=t->next;
    }while(t!=last->next);

    printf("(back to head)\n");
}
int main(){
    int ch;

    while(1){
        printf("\n1.InsBeg 2.InsEnd 3.InsPos 4.DelBeg 5.DelEnd 6.DelPos 7.Display 8.Exit\nChoice: ");

        if(scanf("%d",&ch)!=1){
            while(getchar()!='\n');
            printf("Invalid!\n");
            continue;
        }

        switch(ch){
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7: display(); break;
            case 8: return 0;
            default: printf("Enter 1-8 only\n");
        }
    }
}