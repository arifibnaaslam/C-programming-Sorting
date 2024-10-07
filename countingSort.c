#include<stdio.h>

#define size 50

void setArrayValu(int ar[], int lb, int ub){

    for(int i= lb;i<=ub; i++){

        ar[i] = rand()%101;
    }
}
void printArray(int ar[], int lb, int ub){

    for(int i= lb;i<=ub; i++){

        printf("%d\t",ar[i]);
    }
    printf("\n");
}

void swip(int ar[],int a,int b){
    int temp = ar[a];
    ar[a]=ar[b];
    ar[b]=temp;
}
int find_max(int ar[], int lb, int ub){

    int max = ar[lb];
    for(int i =lb;i<=ub;i++){
        if (ar[i]>max)
            max = ar[i];
    }
    return max;
}




void countingsort(int ar[], int lb, int ub)
{
 int max = find_max(ar,lb,ub);
 printf("max is %d\n",max);
 int count[max+1] ; // careted and initialz 0  count array where eliment will be max + 1 . and
 for(int i= 0; i<=max; i++)
 {
     count[i]=0; // inisialize 0;
 }
 for(int i =0; i<=ub;i++){
    count[ar[i]]++;  // count frequency in count array
 }
 printArray(count,0,max);
 for(int j =1; j<=max; j++)
 {
     count[j]= count[j]+count[j-1];  // cumeleting number
 }
  printArray(count,0,max);
int b[ub-lb+1];
for(int i=ub; i>=0;i--){

    b[count[ar[i]]-1]=ar[i];
    count[ar[i]]--;

}
// for (int i = lb, j = 0; i <= ub; i++, j++) {
//        ar[i] = b[j];
//    }

 printArray(b,0,ub);
}



int main(){

    int lb=0,ub=10;
    int ar[size] ;
    //int n = sizeof(ar)/sizeof (ar[0]);
   // printf(" Eliments number is %d\n",n);

    setArrayValu(ar,lb,ub);
    printArray(ar,lb,ub);


    // test for find max
    //printf("%d is max in ths array \n", find_max(ar,lb,ub));

    countingsort(ar,lb,ub);
    printArray(ar,lb,ub);



return 0;
}
/*

void countingsort(int ar[], int lb, int ub)
{
    int max = find_max(ar, lb, ub);
    int c[max+1];

    for (int n = 0; n <= max; n++) {
        c[n] = 0;
    }

    for (int i = lb; i <= ub; i++) {
        c[ar[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        c[i] += c[i-1];
    }

    int b[ub - lb + 1];

    for (int i = ub; i >= lb; i--) {
        b[c[ar[i]] - 1] = ar[i];
        c[ar[i]]--;
    }

    for (int i = lb, j = 0; i <= ub; i++, j++) {
        ar[i] = b[j];
    }
}

*/

