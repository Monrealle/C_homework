#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

int main() {
    int n, m;
    
    printf("Введите количество воинов (n): ");
    scanf("%d", &n);
    printf("Введите шаг (m): ");
    scanf("%d", &m);
    
    if (n == 1) {
        printf("Последний выживший: 1\n");
        return 0;
    }
    
    Node* head = (Node*)malloc(sizeof(Node));
    head->value = 1;
    
    Node* prev = head;
    for (int i = 2; i <= n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->value = i;
        prev->next = new_node;
        prev = new_node;
    }
    prev->next = head;
    
    Node* current = head;
    prev = NULL;
    
    if (m == 1) {
        prev = current;
        while (prev->next != head) {
            prev = prev->next;
        }
    }
    
    int count = n;
    
    while (count > 1) {
        for (int i = 0; i < m - 1; i++) {
            prev = current;
            current = current->next;
        }
        
        Node* to_delete = current;
        prev->next = current->next;
        current = current->next;
        free(to_delete);
        
        count--;
    }
    
    printf("Последний выживший: %d\n", current->value);
    
    free(current);
    
    return 0;
}