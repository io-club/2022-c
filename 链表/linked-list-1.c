#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int *score;
  char *name;
  struct Node *next;
};

struct LinkedList {
  struct Node *head;
  // 为了方便，这里可以添加链表的更多信息，例如节点的总数等
  struct Node *tail;
};

struct LinkedList *new_linked_list() {
  struct LinkedList *l = malloc(sizeof(struct LinkedList));
  l->head = NULL;
  l->tail = NULL;
  return l;
}

struct Node *last(struct LinkedList *l) {
  struct Node *current = l->head;
  while (current->next != NULL) {
    current = current->next;
  }
  return current;
}

void append_node(struct LinkedList *l, struct Node *your) {
  if (l->head == NULL) {
    l->head = your;
    l->tail = your;
    return;
  }
  struct Node *last_node = last(l);
  last_node->next = your;
  l->tail = your;
}

struct Node *new_node(int *scores, char *name) {
  struct Node *node = malloc(sizeof(struct Node));
  node->score = scores;
  node->name = name;
  node->next = NULL;
  return node;
}

struct Node *new_node_scanf() {
  int m = 3;
  int score[10];
  for (int i = 0; i < m; i++) {
    scanf("%d", &score[i]);
  }
  return new_node(score, "name");
}

int main(int argc, char const *argv[]) {
  struct LinkedList *l = new_linked_list();
  int n = 10;
  int m = 3;
  for (int i = 0; i < n; i++) {
    int *scores = malloc(sizeof(int) * m);
    scores[0] = i;
    append_node(l, new_node(scores, "aa"));
  }

  assert(last(l)->score[0] == n - 1);

  return 0;
}
