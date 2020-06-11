#include <stdio.h>
#include <stdlib.h>

struct student
{
    int number;
    float mid_term;
    float lab;
    float final_exam;
};

struct student std[1000];

int main()
{
    int std_number,a=0,b=0,c=0,d=0,f=0,absent=0;
    float pass=0,total_degree=0;
    printf("Enter the number of the students : ");
    scanf("%d",&std_number);
    printf("\n");
    for(int i=0; i<std_number; i++)
    {
        printf("Student %d number = ",i+1);
        scanf("%d",&std[i].number);
        printf("Student number %d mid term degree = ",std[i].number);
        scanf("%f",&std[i].mid_term);
        printf("Student number %d lab degree = ",std[i].number);
        scanf("%f",&std[i].lab);
        printf("Student number %d final degree (if absent enter -1) = ",std[i].number);
        scanf("%f",&std[i].final_exam);
        printf("\n");
    }
    printf("\n");
    printf("\t\t\t\t\t\tStudents Marks Are \n\n");
    for(int i=0; i<std_number; i++)
    {
        if(std[i].final_exam==-1)
        {
            printf("Student number %d is fail because he was absent F\n",std[i].number);
            f++;
            absent++;
        }
        else if(std[i].final_exam<15)
        {
            float degree=std[i].lab+std[i].mid_term+std[i].final_exam;
            printf("Student number %d is fail because the final exam degree is : %.2f F\n",std[i].number,std[i].final_exam);
            total_degree+=degree;
            f++;
        }
        else
        {
            float degree=std[i].lab+std[i].mid_term+std[i].final_exam;
            total_degree+=degree;
            printf("Student number %d degree is : %.2f",std[i].number,degree);
            if(degree>=90)
            {
                printf(" A\n");
                pass++;
                a++;
            }
            else if(degree>=80 && degree<90)
            {
                printf(" B\n");
                pass++;
                b++;
            }
            else if(degree>=70 && degree<80)
            {
                printf(" C\n");
                pass++;
                c++;
            }
            else if(degree>=60 && degree<70)
            {
                printf(" D\n");
                pass++;
                d++;
            }
            else if(degree<60)
               {
                   printf(" F\n");
                   f++;
               }
        }
    }
    printf("\nPercent success rate is : %.2f\n",(pass*100)/std_number);
    printf("\nThe average overall grade is : %.2f\n",total_degree/std_number);
    printf("\nThe number of student with grade A is : %d\n",a);
    printf("\nThe number of student with grade B is : %d\n",b);
    printf("\nThe number of student with grade C is : %d\n",c);
    printf("\nThe number of student with grade D is : %d\n",d);
    printf("\nThe number of student with grade F is : %d\n",f);
    printf("\nThe number of absent students is : %d\n",absent);
}
