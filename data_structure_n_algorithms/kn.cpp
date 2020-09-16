#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;
// find what the hell a kind of graphs by greedy algorithms?
// a homework

double W(int *color, int c, int n) {
    // c == 0 for black, c == 1 for white
    int e1, e2, e3, e4, e5, e6;
    double w = 0.;
    int uc = 0;
    int cc = 0;
    int tmpuc1, tmpcc1, tmpuc2, tmpcc2;
    for (int i1 = 0; i1 < n; i1++)
    for (int i2 = i1 + 1; i2 < n; i2++) {
        uc = 0;
        cc = 0;

        e1 = color[i1 * n + i2];
        if (e1 < 0) uc++; else if (e1 == c) cc++;

        tmpcc1 = cc;
        tmpuc1 = uc;

        for (int i3 = i2 + 1; i3 < n; i3++){
            cc = tmpcc1;
            uc = tmpuc1;

            e2 = color[i2 * n + i3];
            if (e2 < 0) uc++; else if (e2 == c) cc++;
            e3 = color[i1 * n + i3];
            if (e3 < 0) uc++; else if (e3 == c) cc++;
            if (cc + uc != 3) continue;

            tmpcc2 = cc;
            tmpuc2 = uc;

            for (int i4 = i3 + 1; i4 < n; i4++) {
                cc = tmpcc2;
                uc = tmpuc2;

                e4 = color[i1 * n + i4];
                if (e4 < 0) uc++; else if (e4 == c) cc++;
                e5 = color[i2 * n + i4];
                if (e5 < 0) uc++; else if (e5 == c) cc++;
                e6 = color[i3 * n + i4];
                if (e6 < 0) uc++; else if (e6 == c) cc++;

                if (cc + uc != 6) continue;
                else if (cc == 0) w += 1./32;
                else if (cc > 0) w += pow(2., -uc);
            }
        }
    }
    return w;
}

void count_kn(int *color, int c, int n, int print_detail) {
    // c == 0 for black, c == 1 for white
    cout << "\nCounting color: " << c << endl;

    int total_count = 0;

    int e1, e2, e3, e4, e5, e6;
    int uc = 0;
    int cc = 0;
    int tmpuc1, tmpcc1, tmpuc2, tmpcc2;
    for (int i1 = 0; i1 < n; i1++)
    for (int i2 = i1 + 1; i2 < n; i2++) {
        uc = 0;
        cc = 0;

        e1 = color[i1 * n + i2];
        if (e1 < 0) uc++; else if (e1 == c) cc++;

        tmpcc1 = cc;
        tmpuc1 = uc;

        for (int i3 = i2 + 1; i3 < n; i3++){
            cc = tmpcc1;
            uc = tmpuc1;

            e2 = color[i2 * n + i3];
            if (e2 < 0) uc++; else if (e2 == c) cc++;
            e3 = color[i1 * n + i3];
            if (e3 < 0) uc++; else if (e3 == c) cc++;
            if (cc + uc != 3) continue;

            tmpcc2 = cc;
            tmpuc2 = uc;

            for (int i4 = i3 + 1; i4 < n; i4++) {
                cc = tmpcc2;
                uc = tmpuc2;

                e4 = color[i1 * n + i4];
                if (e4 < 0) uc++; else if (e4 == c) cc++;
                e5 = color[i2 * n + i4];
                if (e5 < 0) uc++; else if (e5 == c) cc++;
                e6 = color[i3 * n + i4];
                if (e6 < 0) uc++; else if (e6 == c) cc++;

                if (cc == 6) {
                    total_count++;
                    if (print_detail) printf("clique %d %d %d %d\n", i1, i2, i3, i4);
                }
            }
        }
    }
    cout << "total count: " << total_count << endl;
}

int ArgPos(char *str, int argc, char **argv){
    int a;
    for (a = 1; a < argc; a++) if (!strcmp(str, argv[a])) {
        if (a == argc - 1) {
            printf("Argument missing for %s\n", str);
            exit(1);
        }
        return a;
    }
    return -1;
}

int main(int argc, char **argv){
    int p;
    int n = 10;
    int print_detail = 0;

    cout << "Usage:" << endl;
    cout << "-n: total number of nodes in the graph" << endl;
    cout << "-p: 1 for printing details and 0 for not printing details" << endl;
    if ((p = ArgPos((char *)"-n", argc, argv)) > 0) n = atoi(argv[p + 1]);
    if ((p = ArgPos((char *)"-p", argc, argv)) > 0) print_detail = atoi(argv[p + 1]);

    if (n <= 5) {
        cout << "Please input a larger n" << endl;
        exit(0);
    }

    int *color = new int [n * n];
    double w1, w2;

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) color[i * n + j] = -1;

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        color[i * n + j] = 0;
        w1 = W(color, 0, n);
        color[i * n + j] = 1;
        w2 = W(color, 1, n);
        if (w1 < w2) {
            color[i * n + j] = 0;
            if (print_detail) cout << "i: " << i << " j: " << j << " color: " << 0 << endl;
        }
        else if (print_detail) cout << "i: " << i << " j: " << j << " color: " << 1 << endl;
    }

    double kn = (double)(n * (n-1) * (n-2) * (n-3)) / (2 * 3 * 4 * 32.);
    printf("\nTheoretically Kn (by 2^(-5)*C^n_4): %.2lf\n", kn);

    count_kn(color, 0, n, print_detail);
    count_kn(color, 1, n, print_detail);

    return 0;
}
