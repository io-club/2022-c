#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int *score;
  char *name;
  struct Node *next;
};

struct Node *last(struct Node *head) {
  struct Node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  return current;
}

// 向链表中添加节点
// 1. 如果链表为空，直接将头指针指向新节点
// 2. 如果链表不为空，找到最后一个节点，将最后一个节点的 next 指针指向新节点
void append_node(struct Node **head, struct Node *your) {
  if (*head == NULL) {
    *head = your;
    return;
  }
  struct Node *last_node = last(*head);
  last_node->next = your;
}

// 向链表中添加节点, 同上，参数不同
// 1. 如果 head 为 NULL，直接返回 your，调用者必须使用
//     head = append_node2(head, your)
// 2. 如果 head 不为 NULL，找到最后一个节点，将最后一个节点的 next
//    指针指向新节点，不必接收返回值
struct Node *append_node2(struct Node *head, struct Node *your) {
  if (head == NULL) {
    return your;
  }
  struct Node *last_node = last(head);
  last_node->next = your;
  return head;
}

// 创建一个新的节点
struct Node *new_node(int *scores, char *name) {
  struct Node *node = malloc(sizeof(struct Node));
  node->score = scores;
  node->name = name;
  node->next = NULL;
  return node;
}

// 从键盘读取数据创建一个新的节点
struct Node *new_node_scanf() {
  int m = 3;
  int score[10];
  for (int i = 0; i < m; i++) {
    scanf("%d", &score[i]);
  }
  return new_node(score, "name");
}

int main(int argc, char const *argv[]) {
  struct Node *head = NULL;
  int n = 10;
  int m = 3;
  for (int i = 0; i < n; i++) {
    int *scores = malloc(sizeof(int) * m);
    scores[0] = i;
    append_node(&head, new_node(scores, "aa"));
  }

  assert(last(head)->score[0] == n - 1);

  return 0;
}
