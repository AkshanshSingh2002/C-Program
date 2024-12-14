/*
#include<stdio.h>
#include<conio.h>
#define max 30
void main()
{
    int i, j, n,k, t, p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;
    
    printf("Enter the Number of Processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the burst time of the process: ");
    for (k= 0; k<n; k++)
    {   
        scanf("%d", &bt[k]);
    }
    
    //applying bubble short technique to short according to their burst time
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (bt[j]>bt[j+1])
            {
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    printf("process\t burst time\t waiting time\t turn around time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        //tat[i] = 0;
        for (j = 0; j<=1; j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[j];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t %d\t\t %d\t\t %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("Average waiting time =%f\n", awt);
    printf("Average turn around time= %f", atat);
    return 0;
}

wt[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    { 
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);*/

#include<stdio.h>
#include<conio.h>
#define max 30

void main() {
    int i, j, n, k, t, p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the Number of Processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of the process: ");
    for (k = 0; k < n; k++) {
        scanf("%d", &bt[k]);
        p[k] = k + 1; // Assign process numbers
    }

    // Applying bubble sort technique to sort according to burst time
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                t = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j];
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }

    // Calculating waiting time and turnaround time
    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    awt = awt / n;
    atat = atat / n;
    printf("Average waiting time = %f\n", awt);
    printf("Average turnaround time = %f", atat);

    return 0;
}