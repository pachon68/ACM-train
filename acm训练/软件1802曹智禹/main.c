#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define REP(i, a, b) for(int i = (a); i <= (b); ++ i)
#define REP(j, a, b) for(int j = (a); j <= (b); ++ j)
#define PER(i, a, b) for(int i = (a); i >= (b); -- i)
int m,n;
typedef long long ll;
int read()
{
    int k=0;
    char f=1,c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())k=k*10+c-'0';
    return k*f;
}
struct cla
{
  int tal;
  int avg;
}a[10];
struct stu
{
   ll xh;
   char name[10];
   int score[10];
   int total;
   double ave;
}s[50];
struct tmp
{
     ll xh;
     char name[10];
     int total;
}tp[50];
int q=0,b=0,c=0,d=0,e=0;
int cmp4(const void *a,const void *b)
{
      struct stu x=*(struct stu*)a;
      struct stu y=*(struct stu*)b;
      return strcmp(x.name,y.name);
}
int cmp(const void *a,const void *b)
{
      struct stu x=*(struct stu*)a;
      struct stu y=*(struct stu*)b;
      return (((x.total)<(y.total))?1:-1);
}
int comp(const void *a,const void *b)
{
      struct stu x=*(struct stu *)a;
      struct stu y=*(struct stu *)b;
      return (((x.total)>(y.total))?1:-1);
}
int cmp3(const void *a,const void *b)
{
      struct stu x=*(struct stu *)a;
      struct stu y=*(struct stu *)b;
      return (((x.xh)>(y.xh))?1:-1);
}
int sear(int x)
{
    int i=0;
    for(i=0;i<m;i++){
       int h = s[i].xh;
       if(h==x){
            return i;
       }
    }
    return -1;
}
int sea(char tmp[])
{
   int i=0;
   for(i=0;i<m-1;i++){
     if(strcmp(tmp,s[i].name)==0){
            return i;
     }
   }
   return -1;
}
double am,bm,cm,dm,em;
void st()
{
   int i,j;
   for(i=0;i<n;i++){
       am=bm=cm=dm=em=0;
       q=b=c=d=e=0;
       for(j=0;j<m;j++){
             if(s[j].score[i]<=100&&s[j].score[i]>=90)
             {
                    q++;
             }
             else if(s[j].score[i]<=89&&s[j].score[i]>=80)
             {
                    b++;
             }
             else if(s[j].score[i]<=79&&s[j].score[i]>=70)
             {
                    c++;
             }
             else if(s[j].score[i]<=69&&s[j].score[i]>=60)
             {
                    d++;
             }
             else
             {
                    e++;
             }
       }
       am=q/(double)m;
       bm=b/(double)m;
       cm=c/(double)m;
       dm=d/(double)m;
       em=e/(double)m;
       printf("课程%d：优秀有%d人,比例为%.3f\n良好有%d人,比例为%.3f\n中等有%d人,比例为%.3f\n及格有%d人,比例为%.3f\n不及格有%d人,比例为%.3f\n\n",i+1,q,am,b,bm,c,cm,d,dm,e,em);
   }
   return;
}
void writefile()
{
    FILE *fp;

    fp=fopen("score.txt","w");
    if(fp==NULL)
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    fprintf(fp,"%d %d\n",n,m);
    for(int i=0;i<m;i++){
         fprintf(fp,"学生姓名:%s 学号:%lld 总分:%d\n",s[i].name,s[i].xh,s[i].total);
    }
    fclose(fp);
}
void readfile()
{
    int x,y;
    FILE *fp;
    if((fp=fopen("score.txt","r"))==NULL)
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    fscanf(fp,"%d %d\n",&x,&y);
    for(int i=1;i<=m;i++){
        fscanf(fp,"学生姓名:%s 学号:%lld 总分:%d\n",&tp[i].name,&tp[i].xh,&tp[i].total);
    }
    printf("共%d人 %d门课\n",x,y);
    for(int i=1;i<=m;i++){
        printf("姓名:%s   学号:%lld  总分:%d\n",tp[i].name,tp[i].xh,tp[i].total);
    }
}
int main()
{
    system("color 34");
    char k[100];
    int i,chs;
    ll x;
    while(1){
        printf("\n\n"
           "_______Welcome to use student information management system_______\n"
           "|1. Input record                                              |\n"
           "|2. Caculate total and average score of every course          |\n"
           "|3. Caculate total and average score of every student         |\n"
           "|4. Sort in descending order by total score of every student  |\n"
           "|5. Sort in ascending order by total score of every student   |\n"
           "|6. Sort in ascending order by number                         |\n"
           "|7. Sort in dictionary order by name                          |\n"
           "|8. Search by number                                          |\n"
           "|9. Search by name                                            |\n"
           "|10. Statistic analysis for every course                      |\n"
           "|11. List record                                              |\n"
           "|12. Write to file                                            |\n"
           "|13. Read from a file                                         |\n"
           "|0.Exit                                                       |\n");
        printf("Please enter your choice:\n");
        chs=read();
    switch(chs){
      case 1:
            system("cls");
            printf("请输入人数和课程数：");
            m=read(),n=read();
            REP(i, 0, m-1)
            {
                printf("请输入学号和姓名:\n");
                scanf("%lld",&s[i].xh);
                scanf("%s",s[i].name);
                printf("请输入分数:\n");
                for(int j=0;j<n;j++)
                {
                    s[i].score[j]=read();
                    s[i].total+=s[i].score[j];
                }
                printf("该学生总分为:%d\n",s[i].total);
                s[i].ave=s[i].total/n;
                printf("该学生平均分为:%.3f\n",s[i].ave);
            }
            break;
      case 2:
            system("cls");
            printf("各门课总分和平均分分别为:\n");
            for(i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    a[i].tal+=s[j].score[i];
                }
                printf("%d:",i+1);
                printf("%d  ",a[i].tal);
                a[i].avg=a[i].tal/m;
                printf("%d\n",a[i].avg);
            }
            break;
      case 3:
             system("cls");
             REP(i, 0, m-1)
             {
                 printf("姓名:%s",s[i].name);
                 printf("  学号:%lld",s[i].xh);
                 printf("  总分:%d\n",s[i].total);
             }
             break;
      case 4:
            system("cls");
            qsort(s,m,sizeof(s[0]),comp);
            for(i=0;i<m;i++)
            {
                printf("第%d名：\n",i+1);
                printf("学号:%lld     ",s[i].xh);
                printf("姓名:%s\n",s[i].name);
                printf("各科分数:");
                for(int j=0;j<n;j++)
                {
                     printf("%d ",s[i].score[j]);
                }
                printf("\n总分：%d",s[i].total);
                printf("\n\n\n");
            }
            break;
      case 5:
            system("cls");
            qsort(s,m,sizeof(s[0]),cmp);
            for(i=0;i<m;i++)
            {
                printf("第%d名：\n",i+1);
                printf("学号:%lld     ",s[i].xh);
                printf("姓名:%s\n",s[i].name);
                printf("各科分数:");
                for(int j=0;j<n;j++)
                {
                   printf("%d ",s[i].score[j]);
                }
                printf("\n总分：%d",s[i].total);
                printf("\n\n\n");
            }
            break;

      case 6:
            system("cls");
            qsort(s,m,sizeof(s[0]),cmp3);
            for(i=0;i<m;i++)
            {
                printf("学号:%lld     ",s[i].xh);
                printf("姓名:%s\n",s[i].name);
                printf("各科分数:");
                for(int j=0;j<n;j++)
                {
                    printf("%d ",s[i].score[j]);
                }
                printf("\n总分：%d",s[i].total);
                printf("\n\n\n");
            }
            break;
      case 7:
            system("cls");
            qsort(s,m,sizeof(s[0]),cmp4);
            for(i=0;i<m;i++)
            {
                printf("学号:%lld     ",s[i].xh);
                printf("姓名:%s\n",s[i].name);
                printf("各科分数:");
                for(int j=0;j<n;j++)
                {
                    printf("%d ",s[i].score[j]);
                }
                printf("\n总分：%d",s[i].total);
                printf("\n\n\n");
            }
            break;
      case 8:
            system("cls");
            printf("请输入要查找的学生学号:\n");
            x=read();
            qsort(s,m,sizeof(s[0]),cmp);
            int pos=sear(x);
            if(pos==-1)
            {
                printf("不存在有关该学生的信息！，请检查拼写是否正确。");
                break;
            }
            printf("该学生姓名为:");
            printf("%s\n",s[pos].name);
            printf("各科分数分别为：\n");
            REP(i,0,n-1)
            {
                 printf("%d  ",s[pos].score[i]);
            }
            printf("\n");
            printf("该学生排名为:%d 该学生总分为:%d",pos+1,s[pos].total);
            printf("\n");
            break;
      case 9:
            system("cls");
            printf("请输入要查找的学生姓名:\n");
            scanf("%s",k);
            qsort(s,m,sizeof(s[0]),cmp);
            int po=sea(k);
            if(po==-1)
            {
                printf("不存在有关该学生的信息！，请检查拼写是否正确。");
                break;
            }
            printf("该学生姓名为:");
            printf("%s\n",s[po].name);
            printf("各科分数分别为：\n");
            REP(i,0,n-1)
            {
                 printf("%d  ",s[po].score[i]);
            }
            printf("\n");
            printf("该学生排名为:%d 该学生总分为:%d",po+1,s[po].total);
            printf("\n");
            break;
       case 10:
               system("cls");
               st();
               break;
       case 11:
               system("cls");
               for(i=0;i<m;i++)
               {
                   printf("学号:%lld",s[i].xh);
                   printf("   姓名:%s",s[i].name);
                   printf("   各科分数:");
                   for(int j=0;j<n;j++)
                   {
                        printf("%d ",s[i].score[j]);
                   }
                   printf("该学生总分为:%d\n",s[i].total);
                   printf("该学生平均分为:%.3f\n",s[i].ave);
                   printf("\n");
               }
               system("cls");
               printf("各门课总分和平均分分别为:\n");
               for(i=0;i<n;i++)
               {
                  printf("%d:",i+1);
                  printf("%d  ",a[i].tal);
                  printf("%d\n",a[i].avg);
               }
               break;
       case 12:
                system("cls");
                writefile();
                break;
       case 13:
                system("cls");
                readfile();
                break;
       case 0:
                printf("\n\t\t感谢您的使用！\n");
                printf("\n\t\t");
                system("pause");
                exit(0);
                break;
       }
    }
    return 0;
}
