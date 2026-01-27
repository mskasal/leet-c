#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSERT(condition)                                                      \
  do {                                                                         \
    if (!(condition)) {                                                        \
      printf("FAIL: %s (line %d)\n", #condition, __LINE__);                    \
      return 1;                                                                \
    } else {                                                                   \
      printf("PASS: %s\n", #condition);                                        \
    }                                                                          \
  } while (0)

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
  struct ListNode *dummy = malloc(sizeof(struct ListNode));
  dummy->val = l1->val + l2->val;
  dummy->next = NULL;
  return dummy;
}

int *two_sum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 0;

  int *result = malloc(2 * sizeof(int));
  if (result == NULL) {
    return NULL;
  }

  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (nums[i] + nums[j] == target) {
        result[0] = i;
        result[1] = j;
        *returnSize = 2;
        return result;
      }
    }
  }

  *returnSize = 0;
  return result;
}

int test_addTwoNumbers() {
  struct ListNode *l1 = malloc(sizeof(struct ListNode));
  l1->val = 2;
  l1->next = NULL;
  struct ListNode *l2 = malloc(sizeof(struct ListNode));
  l2->val = 3;
  l2->next = NULL;

  struct ListNode *result = addTwoNumbers(l1, l2);

  ASSERT(result->val == 5);

  free(l1);
  free(l2);
  free(result);
  return 0;
}

int length_of_longest_substring(char *s) {
  if (!s || !*s)
    return 0;

  int last[256];
  memset(last, -1, sizeof(last));

  int left = 0;
  int max_len = 0;

  for (int i = 0; s[i]; i++) {
    unsigned char ch = (unsigned char)s[i];

    if (last[ch] >= left) {
      left = last[ch] + 1;
    }

    last[ch] = i;

    int len = i - left + 1;
    if (len > max_len)
      max_len = len;
  }

  return max_len;
}

double median_of_two_sorted_arrays(int *nums1, int nums1Size, int *nums2,
                                   int nums2Size) {
  double result = 0;

  for (int i = 0; i < nums1Size + nums2Size; i++) {
  }

  return result;
}

bool palindrome_number(int x) {
  if (x < 0 || (x % 10 == 0 && x != 0)) {
    return false;
  }

  int reversed = 0;

  while (x > reversed) {
    reversed = reversed * 10 + x % 10;
    x /= 10;
  }

  return (x == reversed) || (x == reversed / 10);
}

int search_insert(int *nums, int numsSize, int target) {
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] == target) {
      return i;
    }
    if (nums[i] > target) {
      return i;
    }
  }
  return numsSize;
}

int *plus_one(int *digits, int digitsSize, int *returnSize) {
  int *result = malloc((digitsSize + 1) * sizeof(int));

  if (result == NULL) {
    *returnSize = 0;
    return NULL;
  }

  int carry = 1;

  for (int i = digitsSize - 1; i >= 0; i--) {
    int sum = digits[i] + carry;
    result[i + 1] = sum % 10;
    carry = sum / 10;
  }

  result[0] = carry;

  if (carry == 0) {
    *returnSize = digitsSize;
    memmove(result, result + 1, digitsSize * sizeof(int));
  } else {
    *returnSize = digitsSize + 1;
  }

  return result;
}

char *add_binary(char *a, char *b) { return "12"; }

char *longest_common_prefix(char **strs, int strsSize) {
  if (strsSize == 0)
    return "";

  char *prefix = strs[0];

  for (int j = 0; prefix[j] != '\0'; j++) {
    char c = prefix[j];

    for (int i = 1; i < strsSize; i++) {
      if (strs[i][j] == '\0' || strs[i][j] != c) {
        char *result = (char *)malloc((j + 1) * sizeof(char));
        strncpy(result, prefix, j);
        result[j] = '\0';
        return result;
      }
    }
  }

  char *result = (char *)malloc((strlen(prefix) + 1) * sizeof(char));
  strcpy(result, prefix);
  return result;
}

bool linked_list_cycle(struct ListNode *head) { return false; }

int indices_equal(const int *a, const int *b, int size) {
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i])
      return 0;
  }
  return 1;
}

int test_two_sum(void) {
  int nums1[] = {2, 7, 11, 15};
  int expected1[] = {0, 1};

  int returnSize1;
  int *result1 =
      two_sum(nums1, (int)(sizeof(nums1) / sizeof(nums1[0])), 9, &returnSize1);

  ASSERT(returnSize1 == 2);
  ASSERT(indices_equal(result1, expected1, 2) ||
         indices_equal(result1, (int[]){1, 0}, 2));

  free(result1);

  int nums2[] = {3, 2, 4};
  int expected2[] = {1, 2};

  int returnSize2;
  int *result2 =
      two_sum(nums2, (int)(sizeof(nums2) / sizeof(nums2[0])), 6, &returnSize2);

  ASSERT(returnSize2 == 2);
  ASSERT(indices_equal(result2, expected2, 2));

  free(result2);

  int nums3[] = {3, 3};
  int expected3[] = {0, 1};

  int returnSize3;
  int *result3 =
      two_sum(nums3, (int)(sizeof(nums3) / sizeof(nums3[0])), 6, &returnSize3);

  ASSERT(returnSize3 == 2);
  ASSERT(indices_equal(result3, expected3, 2));

  free(result3);

  return 0;
}

int test_median_of_two_sorted_arrays() {

  int nums11[] = {1, 3};
  int nums12[] = {2};
  double expected1 = 2.00000;

  int nums21[] = {1, 2};
  int nums22[] = {3, 4};
  double expected2 = 2.50000;

  ASSERT(median_of_two_sorted_arrays(nums11, sizeof(nums11), nums12,
                                     sizeof(nums12)) == expected1);

  ASSERT(median_of_two_sorted_arrays(nums21, sizeof(nums21), nums22,
                                     sizeof(nums22)) == expected2);

  return 0;
}

int test_length_of_longest_substring() {
  char *chars1 = "abcabcbb";
  char *chars2 = "bbbbb";
  char *chars3 = "pwwkew";

  int expected1 = 3;
  int expected2 = 1;
  int expected3 = 3;

  ASSERT(length_of_longest_substring(chars1) == expected1);
  ASSERT(length_of_longest_substring(chars2) == expected2);
  ASSERT(length_of_longest_substring(chars3) == expected3);

  return 0;
}

int test_palindrome_number() {
  int x1 = 121;
  bool expected1 = true;

  int x2 = -121;
  bool expected2 = false;

  int x3 = 10;
  bool expected3 = false;

  ASSERT(palindrome_number(x1) == expected1);
  ASSERT(palindrome_number(x2) == expected2);
  ASSERT(palindrome_number(x3) == expected3);

  return 0;
}

int test_search_insert() {
  int nums1[] = {1, 3, 5, 6};
  int nums1Size = 4;
  int expected1 = 2;

  int nums2[] = {1, 3, 5, 6};
  int nums2Size = 4;
  int expected2 = 1;

  int nums3[] = {1, 3, 5, 6};
  int nums3Size = 4;
  int expected3 = 4;

  ASSERT(search_insert(nums1, nums1Size, 5) == 2);
  ASSERT(search_insert(nums2, nums2Size, 2) == 1);
  ASSERT(search_insert(nums3, nums3Size, 7) == 4);

  return 0;
}

int test_plus_one(void) {
  int returnSize;
  int *result;

  int nums1[] = {1, 2, 3};
  int expected1[] = {1, 2, 4};
  result = plus_one(nums1, 3, &returnSize);

  ASSERT(returnSize == 3);
  ASSERT(memcmp(result, expected1, returnSize * sizeof(int)) == 0);
  free(result);

  int nums2[] = {4, 3, 2, 1};
  int expected2[] = {4, 3, 2, 2};
  result = plus_one(nums2, 4, &returnSize);

  ASSERT(returnSize == 4);
  ASSERT(memcmp(result, expected2, returnSize * sizeof(int)) == 0);
  free(result);

  int nums3[] = {9};
  int expected3[] = {1, 0};
  result = plus_one(nums3, 1, &returnSize);

  ASSERT(returnSize == 2);
  ASSERT(memcmp(result, expected3, returnSize * sizeof(int)) == 0);
  free(result);

  int nums4[] = {9, 9, 9};
  int expected4[] = {1, 0, 0, 0};
  result = plus_one(nums4, 3, &returnSize);

  ASSERT(returnSize == 4);
  ASSERT(memcmp(result, expected4, returnSize * sizeof(int)) == 0);
  free(result);

  int nums5[] = {0};
  int expected5[] = {1};
  result = plus_one(nums5, 1, &returnSize);

  ASSERT(returnSize == 1);
  ASSERT(memcmp(result, expected5, returnSize * sizeof(int)) == 0);
  free(result);

  return 0;
}

int test_add_binary() {
  char *a1 = "11";
  char *b1 = "1";

  char *expected1 = "100";

  char *a2 = "1010";
  char *b2 = "1011";

  char *expected2 = "10101";

  ASSERT(add_binary(a1, b1) == expected1);
  ASSERT(add_binary(a2, b2) == expected2);

  return 0;
}

int test_longest_common_prefix() {
  char *strs1[] = {"flower", "flow", "flight"};
  char *expected1 = "fl";

  char *result1 = longest_common_prefix(strs1, 3);

  ASSERT(strcmp(result1, expected1) == 0);

  char *strs2[] = {"dog", "racecar", "car"};
  char *expected2 = "";

  char *result2 = longest_common_prefix(strs2, 3);
  ASSERT(strcmp(result2, expected2) == 0);

  return 0;
}

int test_linked_list_cycle() {

  struct ListNode *head = malloc(sizeof(struct ListNode));
  struct ListNode *next1 = malloc(sizeof(struct ListNode));
  struct ListNode *next2 = malloc(sizeof(struct ListNode));
  struct ListNode *next3 = malloc(sizeof(struct ListNode));

  head->val = 3;
  head->next = next1;

  next1->val = 2;
  next1->next = next2;

  next2->val = 0;
  next2->next = next3;

  next3->val = -4;
  next2->next = NULL;

  bool expected1 = true;

  ASSERT(expected1 == linked_list_cycle(head));

  struct ListNode *head1 = malloc(sizeof(struct ListNode));
  struct ListNode *next11 = malloc(sizeof(struct ListNode));

  head1->val = 1;
  head1->next = next11;

  next11->val = 2;
  next11->next = NULL;

  bool expected11 = true;

  ASSERT(expected11 == linked_list_cycle(head1));

  struct ListNode *head2 = malloc(sizeof(struct ListNode));
  struct ListNode *next21 = malloc(sizeof(struct ListNode));

  head2->val = 1;
  head2->next = NULL;

  bool expected21 = true;

  ASSERT(expected21 == linked_list_cycle(head));

  return 0;
}

int main() {
  int failures = 0;

  printf("Running tests...\n");

  failures += test_addTwoNumbers();
  failures += test_two_sum();
  failures += test_median_of_two_sorted_arrays();
  failures += test_length_of_longest_substring();
  failures += test_palindrome_number();
  failures += test_search_insert();
  failures += test_plus_one();
  failures += test_add_binary();
  failures += test_longest_common_prefix();
  failures += test_linked_list_cycle();

  if (failures == 0) {
    printf("All tests passed!\n");
  } else {
    printf("%d tests failed.\n", failures);
    return 1;
  }

  return 0;
}
