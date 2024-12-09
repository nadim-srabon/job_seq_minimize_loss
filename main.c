#include <stdio.h>


struct Job {
    int jobId;   // Job ID
    int loss;    // Loss per day (Li)
    int time;    // Time required to complete the job (Ti)
};

// Comparator to sort jobs by the ratio (loss/time) in descending order
int compare(const void *a, const void *b) {
    struct Job *job1 = (struct Job *)a;
    struct Job *job2 = (struct Job *)b;
    double ratio1 = (double)job1->loss / job1->time;
    double ratio2 = (double)job2->loss / job2->time;
    return (ratio2 > ratio1) - (ratio2 < ratio1); // Descending order
}

int main() {
    // Input Losses and Times
    int L[] = {3, 1, 2, 4};
    int T[] = {4, 1000, 2, 5};
    int n = sizeof(L) / sizeof(L[0]); // Number of jobs

    // Create an array of jobs
    struct Job jobs[n];
    for (int i = 0; i < n; i++) {
        jobs[i].jobId = i + 1; // Job ID (1-based index)
        jobs[i].loss = L[i];
        jobs[i].time = T[i];
    }

    // Sort jobs by the ratio (loss/time) in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = (double)jobs[j].loss / jobs[j].time;
            double ratio2 = (double)jobs[j + 1].loss / jobs[j + 1].time;
            if (ratio1 < ratio2) {
                struct Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }

    // Print the optimal job sequence
    printf("Optimal job sequence to minimize loss: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", jobs[i].jobId);
    }
    printf("\n");

    return 0;
}
