
#include <stdio.h>
#include <stdlib.h>

void fcfs();
void sstf();
void scan();
void cscan();
void look();
void clook();

int main() {
    int choice;
    
    printf("Disk Scheduling Algorithms:\n");
    printf("1. FCFS (First-Come, First-Served)\n");
    printf("2. SSTF (Shortest Seek Time First)\n");
    printf("3. SCAN\n");
    printf("4. CSCAN (Circular SCAN)\n");
    printf("5. LOOK\n");
    printf("6. CLOOK (Circular LOOK)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            fcfs();
            break;
        case 2:
            sstf();
            break;
        case 3:
            scan();
            break;
        case 4:
            cscan();
            break;
        case 5:
            look();
            break;
        case 6:
            clook();
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}

void fcfs() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("%d=>", initial);
    for (i = 0; i < n; i++) {
        TotalHeadMoment += abs(RQ[i] - initial);
        initial = RQ[i];
        printf("%d=>", initial);
    }
    printf("end\n");
    printf("Total head movement is %d\n", TotalHeadMoment);
}

void sstf() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, min, index, j;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    
    printf("%d=>", initial);
    int visited[n];
    for (i = 0; i < n; i++)
        visited[i] = 0;
    
    for (i = 0; i < n; i++) {
        min = 1000;
        for (j = 0; j < n; j++) {
            if (!visited[j] && abs(RQ[j] - initial) < min) {
                min = abs(RQ[j] - initial);
                index = j;
            }
        }
        visited[index] = 1;
        TotalHeadMoment += min;
        initial = RQ[index];
        printf("%d=>", initial);
    }
    
    printf("end\n");
    printf("Total head movement is %d\n", TotalHeadMoment);
}

void scan() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, size, move, j;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d", &move);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    
    printf("%d=>", initial);
    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }
    
    if (move == 1) {
        for (i = index; i < n; i++) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment += abs(size - RQ[i - 1] - 1);
        printf("%d=>", size - 1);
        initial = size - 1;
        for (i = index - 1; i >= 0; i--) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        for (i = index - 1; i >= 0; i--) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment += abs(RQ[i + 1] - 0);
        printf("0=>");
        initial = 0;
        for (i = index; i < n; i++) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    
    printf("end\n");
    printf("Total head movement is %d\n", TotalHeadMoment);
}

void cscan() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, size, move, j;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d", &move);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    
    printf("%d=>", initial);
    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }
    
    if (move == 1) {
        for (i = index; i < n; i++) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment += abs(size - RQ[i - 1] - 1);
        printf("%d=>", size - 1);
        TotalHeadMoment += abs(size - 1);
        printf("0=>");
        initial = 0;
        for (i = 0; i < index; i++) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        for (i = index - 1; i >= 0; i--) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        TotalHeadMoment += abs(RQ[i + 1] - 0);
        printf("0=>");
        TotalHeadMoment += abs(size - 1);
        printf("%d=>", size - 1);
        initial = size - 1;
        for (i = n - 1; i >= index; i--) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    
    printf("end\n"); 
    printf("Total head movement is %d\n", TotalHeadMoment);
}

void look() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, size, move, j;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d", &move);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    
    printf("%d=>", initial);
    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }
    
    if (move == 1) {
        for (i = index; i < n; i++) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index - 1; i >= 0; i--) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        for (i = index - 1; i >= 0; i--) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = index; i < n; i++) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    
    printf("end\n");
    printf("Total head movement is %d\n", TotalHeadMoment);
}

void clook() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, size, move, j;
    printf("Enter the number of Requests: ");
    scanf("%d", &n);
    printf("Enter the Requests sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position: ");
    scanf("%d", &initial);
    printf("Enter total disk size: ");
    scanf("%d", &size);
    printf("Enter the head movement direction for high 1 and for low 0: ");
    scanf("%d", &move);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (RQ[j] > RQ[j + 1]) {
                int temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }
    
    printf("%d=>", initial);
    int index;
    for (i = 0; i < n; i++) {
        if (initial < RQ[i]) {
            index = i;
            break;
        }
    }
    
    if (move == 1) {
        for (i = index; i < n; i++) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = 0; i < index; i++) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else {
        for (i = index - 1; i >= 0; i--) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        for (i = n - 1; i >= index; i--) {
            printf("%d=>", RQ[i]);
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }
    
    printf("end\n");
    printf("Total head movement is %d\n", TotalHeadMoment);
}