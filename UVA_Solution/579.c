#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char time[6],hour[3],min[4];
    int hours,mins,i,k;
    float hour_degree,min_degree,degree,extra;
    while(scanf("%s",time)==1)
    {
        for(i=0;time[i]!=':';i++)
            hour[i]=time[i];
        hour[i]='\0';
        for(k=0;time[i+1]!='\0';i++&&k++)
            min[k]=time[i+1];
        //hour[2]='\0';
        min[k]='\0';
        hours=atoi(hour);
        mins=atoi(min);
        //printf("%d\n",mins);
        if((hours==0)&&(mins==0))
            return 0;;
        extra=(float)mins/(float)2;
        //printf("%f\n",extra);
        hour_degree=(float)(hours*5*6)+extra;
        min_degree=(float)mins*6;
        if(hour_degree>min_degree)
            degree=hour_degree-min_degree;
        else
            degree=min_degree-hour_degree;
        if(degree>180)
            degree=360-degree;
        printf("%.3f\n",degree);
    }
    return 0;
}
