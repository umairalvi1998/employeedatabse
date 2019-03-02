#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int main () {
   FILE *fp,*ft;
   char another,choice;
   struct empty{
    char name[30];
    int age;
    float bs;
    }e;
char empname[30];
long int recsize;
fp=fopen("emplo.txt","rb+");
if(fp==NULL)
{

     fp=fopen("emplo.txt","wb+");
     if(fp==NULL)
     {
         puts("cannot open file");
         exit(1);
     }
}
recsize=sizeof(e);
while(1)
{

    printf("\n1.Add records\n");
    printf("2.list records\n");
    printf("3.modify records\n");
    printf("4.delete records\n");
    printf("0.exit\n");
    printf("\nENTER YOUR CHOICE\n");
  fflush(stdin);
  choice=getche();
  switch(choice)
  {

   case '1':
          fseek(fp,0,SEEK_END);//TAKES THE FILE POINTER TO THE END OF THE FILE
          another='y';
          while(another=='y')
          {
              printf("enter name,age and basic salary");
              scanf("%s%d%f",e.name,&e.age,&e.bs);
              fwrite(&e,recsize,1,fp);//WRITING RECORDS INTO FILE
              printf("\nadd another record(y/n)");
              fflush(stdin);
              another=getche();
          }
          break;
   case '2':
              rewind(fp);
              while(fread(&e,recsize,1,fp)==1)
                printf("\n%s %d %f",e.name,e.age,e.bs);
              break;
   case '3':
        another='y';
        while(another=='y')
        {
            printf("\n enter name of employee to modify");
            scanf("%s",empname);
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)
            {
                if(strcmp(e.name,empname)==0)
                {
                    printf("enter new name,age and bs");
                    scanf("%s%d%f",e.name,&e.age,&e.bs);
                    fseek(fp,-recsize,SEEK_CUR);
                    fwrite(&e,recsize,1,fp);
                    break;

                }
            }
            printf("\n modify another record(y/n)");
            fflush(stdin);
            another=getche();


        }
        break;
   case '4':
      another='y';
      while(another=='y')
      {
          printf("\n enter name of employee to delte");
          fflush(stdin);
          scanf("%s",empname);
          ft=fopen("TEMP.TXT","wb");
          rewind(fp);
          while(fread(&e,recsize,1,fp)==1)
          {
              if(strcmp(e.name,empname)!=0)
                fwrite(&e,recsize,1,ft);
          }
       fclose(fp);
       fclose(ft);
       remove("emplo.txt");
       rename("TEMP.TXT","emplo.txt");
       fp=fopen("emplo.txt","rb+");
       printf("delete another record(y/n)");
       fflush(stdin);
       another=getche();
      }
      break;
   case '0':
      fclose(fp);
      exit(0);

      }

  }
}

