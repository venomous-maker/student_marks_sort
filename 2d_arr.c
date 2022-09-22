#include <stdio.h>

int main(/*int argc, char const *argv[]*/) {
  /* code */
  int student_num;
  printf("Enter the number of students: ");
  scanf("%d", &student_num);
  char names1[student_num][30];
  char names2[student_num][30];
  int marks[3][student_num];
  for(int i = 0; i < student_num; i++)
  {
    printf("Enter First Name, Second Name and English, Kiswahili and Mathematics marks for student %d: ", i+1);
    scanf("%s %s %d %d %d",&names1[i], &names2[i],&marks[0][i],&marks[1][i],&marks[2][i]);
  }
  size_t size =  sizeof(names1) / sizeof(names1[0]) ;
  //printf("%d\n",size );
  int SUM[student_num];
  int position[student_num];
  int minimum, temp, temp1;


  for (int i = 0; i < size; i++)
  {
    temp = marks[0][i]+marks[1][i]+marks[2][i];
    SUM[i]= temp;
  }


  for (int i = 0; i<size; i++ )
  {
    minimum=i;
    for(int j = i+1; j < size; j++)
    {
      if(SUM[minimum]<SUM[j])
      {
        minimum=j;
      }
    }
    if(minimum!=i)
    {
      temp = SUM[i];
      SUM[i] = SUM[minimum];
      SUM[minimum] = temp;
    }
  }
  for (int i = 0; i< size; i++)   position[i]=i+1;
  printf("\nFirst Name:\tSecond Name:\tEnglish:\tKiswahili:\tMathematics:\tTotal:\t\tAverage:\tPosition:\n");
  for(int i = 0; i < student_num; i++)
  {
    int sum = marks[0][i]+marks[1][i]+marks[2][i];
    int pst;
    for(int j = 0; j < size; j++)
    {
      if(SUM[j] == sum)
      { if (temp1==sum)
        {
          pst = temp;
        }
        else
        {
          pst = j+1;
        }
        break;
      }
    }
    temp = pst;
    temp1 == sum;
    int average = (marks[0][i]+marks[1][i]+marks[2][i])/3;
    printf("%s\t\t%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",names1[i], names2[i],marks[0][i],marks[1][i],marks[2][i],sum,average,pst);
  }
  return 0;
}
