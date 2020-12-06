#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct R {int a; int b; char c; char* d;};
void error(char* msg);
struct R parse(char* buf, int idx);
bool check(struct R r);

int main() {
  FILE *fp;
  int buflen = 255;
  char buf[buflen];
  fp = fopen("../input.txt", "r");

  int count = 0;
  while (fgets(buf, buflen - 1, fp)) {
    int idx = strcspn(buf, "\r\n");
    buf[idx] = '\0';
    if (check(parse(buf, idx))) count++;
  }

  fclose(fp);
  fprintf(stdout, "%d\n", count);
  return 0;
}

void error(char* msg) {
  fprintf(stderr, "ERROR: %s\n", msg);
  exit(1);
}

struct R parse(char* buf, int idx) {
    char a[4];
    char b[4];
    char c;
    char* d;
    int start = 0;
    int length = 1;
    struct R r;

    for (int i = 0; i < idx - 1; i++) {
      switch (buf[i]) {
      case '-':
        if (length > 4) error("Would overflow array.");
        strncpy(a, &buf[start], length - 1);
        start = i + 1;
        length = 1;
        r.a = atoi(a);
        break;
      case ' ':
        if (length > 4) error("Would overflow array.");
        strncpy(b, &buf[start], length - 1);
        start = i + 1;
        length = 1;
        r.b = atoi(b);
        break;
      case ':':
        c = buf[i - 1];
        r.c = c;
        d = &buf[i + 2];
        r.d = d;        
        i = idx;
        break;
      default:
        length++;
        break;
      }
    }
    return r;
}

bool check(struct R r) {
  int length = strlen(r.d);
  if (r.a > length) return false;
  if (r.b > length) return false;
  bool x = (r.d[r.a -1] != r.c);
  bool y = (r.d[r.b -1] != r.c);
  return (x != y);
}
