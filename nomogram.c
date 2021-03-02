#include <stdio.h>

int check(int n, int m, int l[100][100], int c[100][100], int a[100][100]) {
  int nr, i, j, k, dim;

  for (i = 0; i < n; i++) {
    nr = 0;
    k = 1;
    dim = 0;
    if (a[i][0] == 1) {
      nr++;
      dim = 1;
    }

    for (j = 1; j < m; j++) {
      if (a[i][j-1] == 1 && a[i][j] == 1) {
        dim++;
        if (j == m - 1 && dim != l[i][k])
          return 0;
      }
      if (a[i][j-1] == 0 && a[i][j] == 1) {
        nr++;
        dim = 1;
        if (j == m - 1 && dim != l[i][k])
          return 0;
      }
      if (a[i][j-1] == 1 && a[i][j] == 0) {
        if (dim != l[i][k])
          return 0;
        dim = 0;
        k++;
      }
    }

    if (nr != l[i][0])
      return 0;
  }

  for (j = 0; j < m; j++) {
    nr = 0;
    k = 1;
    dim = 0;
    if (a[0][j] == 1) {
      nr++;
      dim = 1;
    }

    for (i = 1; i < n; i++) {
      if (a[i-1][j] == 1 && a[i][j] == 1) {
        dim++;
        if (i == n - 1 && dim != c[j][k])
          return 0;
      }
      if (a[i-1][j] == 0 && a[i][j] == 1) {
        nr++;
        dim = 1;
        if (i == n - 1 && dim != c[j][k])
          return 0;
      }
      if (a[i-1][j] == 1 && a[i][j] == 0) {
        if (dim != c[j][k])
          return 0;
        dim = 0;
        k++;
      }
    }

    if (nr != c[j][0])
      return 0;
  }
  return 1;
}

int main() {
  int t, n, m, i, j, k;
  int l[100][100], c[100][100], a[100][100], v[100];

  scanf("%d", &t);

  for (k = 0; k < t; k++) {
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++) {
      scanf("%d", &l[i][0]);
      for (j = 1; j <= l[i][0]; j++)
        scanf("%d", &l[i][j]);
    }

    for (i = 0; i < m; i++) {
      scanf("%d", &c[i][0]);
      for (j = 1; j <= c[i][0]; j++)
        scanf("%d", &c[i][j]);
    }

    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        scanf("%d", &a[i][j]);
    v[k] = check(n, m, l, c, a);
  }

  for (k = 0; k < t; k++)
    if (v[k] == 1)
      printf("Corect\n");
    else
      printf("Eroare\n");
  return 0;
}
