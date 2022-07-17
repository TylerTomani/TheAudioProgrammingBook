#include<stdio.h>

typedef struct breakpoint {
    double time;
    double value;
} BREAKPOINT;

BREAKPOINT points[64];

BREAKPOINT maxpoint(const BREAKPOINT* points, long npoints);
/* input: points = array of BREAKPOINTS,
npoints gives the legnth of the array */

BREAKPOINT maxpoint(const BREAKPOINT* points, long npoints){
    int i;
    BREAKPOINT point;
    point.time = points[0].time;
    point.value = points[0].value;
    
    for(i = 0; i < npoints; i++){
        if(point.value < points[i].value){
            point.value = points[i].value;
            point.time = points[i].time;
        }
    }
    return point;
}
BREAKPOINT* get_breakpoints(FILE* fp, long* psize){
    int got;
    long npoints = 0, size = 64;
    double lasttime = 0.0;
    BREAKPOINT* points = NULL; // Am i declaring the function within itself??
    char line[80];

    if(fp == NULL){
        return NULL:
    }
    points = (BREAKPOINT*)malloc(sizeof(BREAKPOINT) * size);
        if(points == NULL){
            return NULL;
        }

    while(fgets(line,80,fp)){
        got = sscanf(line, "%lf%lf",
            &points[npoints].time,&points[npoints].value);
        if(got < 0){
            continue;
        }
        if(got == 0){
            printf("Line %d has non-numeric data\n",npoints + 1);
            break;
        }
        if(got == 1){
            printf("Imcomplete breakpoint found at point %d\n",npoints+1);
            break;
        }
        if(points[npoints].time < lasttime){
            printf("data error at point %d: time not increasing",npoints + 1);
            break;
        }
    }
    lasttime = points[npoints].time;
    if(++npoints == size){
        BREAKPOINT* tmp;
        size += NPOINTS; // THERE is NO variable declared NPOINT, WHY ??
        tmp = (BREAKPOINT*)realloc(points,sizeof(BREAKPOINT) * size);
        if(tmp == NULL){
            npoints = 0;
            free(points);
            points = NULL;
            break;
        }
        points = tmp;
    }
    if(npoints){
        *psize = npoints;
    }
    return points
}