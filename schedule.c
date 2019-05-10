#include <stdio.h>

typedef struct {
    int arrival, burst, finish, tat, wt;
} Job;

void schedule(Job job[], int n, int q, int mode){
    int burst[n];
    for(int i=0;i<n;i++)
        burst[i] = job[i].burst;
    int done = 0, curr, t = 0, diff = 0;
    float tat_avg = 0.0, wt_avg = 0.0;

    if(mode == 1)
            curr = -1;
    else 
        curr = 0;

    while(done < n){
        if(mode == 1){
            // SJF
            for(int x=0;x<n;x++){
                if(job[x].burst == 0)
                    curr = x;
                if(job[curr].burst > job[x].burst)
                    if(job[curr].burst > 0 && job[curr].arrival <= t)
                        curr = x;
            }
            diff = 1; // Preemptive
        }
        else{
            // Round Robin
            while(1){
               curr = (curr + 1)%n;
               if(job[curr].burst != 0)
                break;
            }
            diff = (q <= job[curr].burst) ? q : job[curr].burst; 
        }

        job[curr].burst -= diff;
        t += diff;

        if(job[curr].burst == 0){
            done++;
            job[curr].finish = t;
        }
    }
    if(mode == 1)
        printf("The SJF details are: \n");
    else 
        printf("The Round Robin details are: \n");
    for(int i=0;i<n;i++){
        job[i].tat = job[i].finish - job[i].arrival * mode;
        job[i].wt = job[i].tat - job[i].burst;
        printf("%d\t%d\t%d\n",i+1 ,job[i].tat,job[i].wt);
        tat_avg += job[i].tat;
        wt_avg += job[i].wt;
    }
    printf("\nTaT Average: %f\nWT Average: %f\n", tat_avg / n, wt_avg / n);
}

int main()
{
	Job job[100];
	int n,q,c;
	printf("Enter the number of jobs\n");
	scanf("%d", &n);
	printf("Enter arrival burst\n");
	for(int i=0;i<n;i++)
	{
		printf("J%d:",i+1);
		scanf("%d%d", &job[i].arrival, &job[i].burst);
	}
	printf("1:Round Robin\n2:Shortest Job First\n");
	scanf("%d",&c);
	switch (c)
	{
		case 1:	
			printf("Enter quantum for Round Robin\n");
			scanf("%d",&q);
			schedule(job, n, q, 0);	
			break;
		case 2:schedule(job, n, q, 1);
	}
}