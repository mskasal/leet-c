#include <stdbool.h> // For bool type
#include <stdio.h>
#include <stdlib.h> // For exit() if needed

// Simple assertion macro for TDD (prints failure and exits if condition is
// false)
#define ASSERT(condition)                                                      \
  do {                                                                         \
    if (!(condition)) {                                                        \
      printf("FAIL: %s (line %d)\n", #condition, __LINE__);                    \
      return 1;                                                                \
    } else {                                                                   \
      printf("PASS: %s\n", #condition);                                        \
    }                                                                          \
  } while (0)

// Example LeetCode function: Add two numbers (from problem 2)
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  // Your implementation here...
  // For demo, return a dummy node
  struct ListNode *dummy = malloc(sizeof(struct ListNode));
  dummy->val = 0;
  dummy->next = NULL;
  return dummy;
}

// Test function for addTwoNumbers
int test_addTwoNumbers() {
  // Setup test data
  struct ListNode *l1 = malloc(sizeof(struct ListNode));
  l1->val = 2;
  l1->next = NULL;
  struct ListNode *l2 = malloc(sizeof(struct ListNode));
  l2->val = 3;
  l2->next = NULL;

  // Call function
  struct ListNode *result = addTwoNumbers(l1, l2);

  // Assertions
  ASSERT(result->val == 5); // Expected result

  // Cleanup
  free(l1);
  free(l2);
  free(result);
  return 0;
}

// Add more LeetCode functions and their test functions here...

int main() {
  int failures = 0;

  printf("Running tests...\n");

  // Run all tests
  failures += test_addTwoNumbers();
  // Add calls to more test_xxx() functions here...

  if (failures == 0) {
    printf("All tests passed!\n");
  } else {
    printf("%d tests failed.\n", failures);
    return 1;
  }

  return 0;
}
