#include <stdio.h>
#include <stdlib.h>

// Simple Node for both Stack and Queue
struct Node {
    int data;
    struct Node* next;
};

// --- 1. STACK (LINKED LIST) ---
struct Node* top = NULL;
void push() {
    int val; printf("Enter val: "); scanf("%d", &val);
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val; nn->next = top; top = nn;
}
void pop() {
    if(!top) return;
    struct Node* t = top; top = top->next; free(t);
}
void showStack() {
    struct Node* t = top;
    while(t) { printf("%d ", t->data); t = t->next; }
}

// --- 2. QUEUE (ARRAY) ---
int q[10], f = -1, r = -1;
void enqA() {
    int val; printf("Enter val: "); scanf("%d", &val);
    if(r == 9) return;
    if(f == -1) f = 0;
    q[++r] = val;
}
void deqA() {
    if(f == -1 || f > r) return;
    f++;
}
void showQA() {
    for(int i=f; i<=r && f!=-1; i++) printf("%d ", q[i]);
}

// --- 3. QUEUE (LINKED LIST) ---
struct Node *front = NULL, *rear = NULL;
void enqL() {
    int val; printf("Enter val: "); scanf("%d", &val);
    struct Node* nn = (struct Node*)malloc(sizeof(struct Node));
    nn->data = val; nn->next = NULL;
    if(!rear) front = rear = nn;
    else { rear->next = nn; rear = nn; }
}
void deqL() {
    if(!front) return;
    struct Node* t = front; front = front->next;
    if(!front) rear = NULL;
    free(t);
}
void showQL() {
    struct Node* t = front;
    while(t) { printf("%d ", t->data); t = t->next; }
}

int main() {
    int ch;
    while(1) {
        printf("\n1.Push 2.Pop 3.Disp(Stack)\n4.EnqA 5.DeqA 6.DispQA\n7.EnqL 8.DeqL 9.DispQL 0.Exit\nChoice: ");
        scanf("%d", &ch);
        if(ch==1) push();      else if(ch==2) pop();  else if(ch==3) showStack();
        else if(ch==4) enqA(); else if(ch==5) deqA(); else if(ch==6) showQA();
        else if(ch==7) enqL(); else if(ch==8) deqL(); else if(ch==9) showQL();
        else exit(0);
    }
}