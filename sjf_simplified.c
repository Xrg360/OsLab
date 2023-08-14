#include <stdio.h>
#include <string.h>

struct process {
    char name[20];
    int at, tt, bt, wt, status, ct;
} p[20], temp;

struct done {
    char name[20];
    int st, ct;
} d[20];

int main() {
    int n, i, j, ls, fnd, num, idle;
    float twt = 0.0, ttt = 0.0;

    printf("ENTER THE NUMBER OF PROCESSES : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nENTER DETAILS OF PROCESS %d\n", i + 1);
        printf("PROCESS NAME : ");
        scanf(" %s", p[i].name);
        printf("ARRIVAL TIME : ");
        scanf("%d", &p[i].at);
        printf("BURST TIME : ");
        scanf("%d", &p[i].bt);
        p[i].status = 0;
    }

    for (i = 0, ls = 0, num = 0, idle = 0; ls < n;) {
        for (j = 0, fnd = -1; j < n; j++) {
            if (i >= p[j].at && p[j].status == 0) {
                if (fnd == -1 || p[j].bt < p[fnd].bt) {
                    fnd = j;
                }
            }
        }

        if (idle == 0 && fnd == -1) {
            strcpy(d[num].name, "Idle");
            d[num].st = i;
            i++;
            idle = 1;
        } else if (fnd != -1) {
            if (idle == 1) {
                d[num].ct = i;
                num++;
                idle = 0;
            }

            strcpy(d[num].name, p[fnd].name);
            p[fnd].status = 1;
            d[num].st = i;
            d[num].ct = i + p[fnd].bt;
            i = d[num].ct;
            p[fnd].ct = d[num].ct;
            p[fnd].tt = p[fnd].ct - p[fnd].at;
            p[fnd].wt = p[fnd].tt - p[fnd].bt;
            num++;
            ls++;
        } else {
            i++;
        }
    }

    printf("\nPROCESS NAME\tCOMPLETION TIME (ms)\tWAITING TIME (ms)\tTURNAROUND TIME (ms)\n\n");
    for (i = 0; i < n; i++) {
        printf("    %s\t\t\t%d\t\t\t%d\t\t\t%d\n", p[i].name, p[i].ct, p[i].wt, p[i].tt);
        twt += p[i].wt;
        ttt += p[i].tt;
    }

    printf("\n\nGANTT CHART ");
    printf("\n\t--------------------------------------------------------------------\n\t");

    for (i = 0; i < num; i++) {
        printf("|%s\t", d[i].name);
    }

    printf(" |\n\t--------------------------------------------------------------------\n\t");

    for (i = 0; i < num; i++) {
        printf("%d\t", d[i].st);
    }

    printf("%d\t\n", d[num - 1].ct);
    printf("\nAVERAGE WAITING TIME : %f", (twt / n));
    printf("\nAVERAGE TURNAROUND TIME : %f\n", (ttt / n));

    return 0;
}
