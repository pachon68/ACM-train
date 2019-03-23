#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int m,n;

struct cla{
  int tal;
  int avg;
}a[10];
struct stu
{
   int xh;
   char name[10];
   int score[10];
   int total;
   int ave;
}s[50];
int q=0,b=0,c=0,d=0,e=0;
int cmp4(const void *a,const void *b)
{
    struct stu x=*(struct stu*)a;
    struct stu y=*(struct stu*)b;
    return (((x.name)>(y.name))?1:-1);
}
int cmp(const void *a,const void *b)
{
      struct stu x=*(struct stu*)a;
      struct stu y=*(struct stu*)b;
      return (((x.total)>(y.total))?1:-1);
}
int comp(const void *a,const void *b)
{
     struct stu x=*(struct stu *)a;
     struct stu y=*(struct stu *)b;
     return (((x.total)<(y.total))?1:-1);
}
int cmp3(const void *a,const void *b)
{
     struct stu x=*(struct stu *)a;
     struct stu y=*(struct stu *)b;
     return (((x.xh)<(y.xh))?1:-1);
}
int sear(int x)
{
    for(int i=0;i<n;i++){
       int h = s[i].xh;
       if(h==x){return i;}
    }
    return -1;
}
int sea(char x[])
{
  for(int i=0;i<n;i++){
    if(strcmp(x,s[i].name)==0){return i;}
  }
  return -1;
}
int am,bm,cm,dm,em;
int select()
{
   for(int i=0;i<m;i++){
     if(s[i].total<=100&&s[i].total>=90)
     {
            q++;
     }
     else if(s[i].total<=89&&s[i].total>=80)
     {
            b++;
     }
     else if(s[i].total<=79&&s[i].total>=70)
     {
            c++;
     }
     else if(s[i].total<=69&&s[i].total>=60)
     {
            d++;
     }
     else
     {
            e++;
     }
   }
   am=q/m;
   bm=b/m;
   cm=c/m;
   dm=d/m;
   em=e/m;
}
void writetofile()
{
    FILE *fp;
    if((fp=fopen("score.txt","w"))==NULL)
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    fprintf(fp,"d\t%d\n",n,m);
    fwrite(s,sizeof(1),m,fp);
    fclose(fp);
}
void readfile()
{
    FILE *fp;
    if((fp=fopen("score.txt","w"))==NULL)
    {
        printf("Failure to open score.txt!\n");
        exit(0);
    }
    fprintf(fp,"d\t%d\n",n,m);
    for(int i=0;!feof(fp);i++)
    {
      fread(&s[i],sizeof(1),1,fp);
    }
    fclose(fp);
}
int main()
{
    char k[100];
    int x,i;
    int n,m;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++)
    {
        scanf("%d",&s[i].xh);
        scanf("%s",&s[i].name);
        for(int j=0;j<n;j++){
            scanf("%d",s[i].score[j]);
            s[i].total+=s[i].score[j];
        }
        s[i].ave=s[i].total/n;
    }
    for(i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i].tal+=s[j].score[i];
        }
        a[i].avg=a[i].tal/m;
    }
    qsort(s,m,sizeof(s[0]),cmp);
    for(i=0;i<m;i++){
        printf("%d",s[i].xh);
        printf("%s",s[i].name);
        for(int j=0;j<n;j++){
         printf("%d",s[i].score[j]);
        }
        printf("\n");
    }
    qsort(s,m,sizeof(s[0]),comp);
    for(i=0;i<m;i++){
        printf("%d",s[i].xh);
        printf("%s",s[i].name);
        for(int j=0;j<n;j++)
        {
             printf("%d",s[i].score[j]);
        }
        printf("\n");
    }
    qsort(s,m,sizeof(s[0]),cmp3);
    for(i=0;i<m;i++)
    {
        printf("%d\n",s[i].xh);
        printf("%s\n",s[i].name);
        for(int j=0;j<n;j++)
        {
            printf("%d",s[i].score[j]);
        }
        printf("\n");
    }
    qsort(s,m,sizeof(s[0]),cmp4);
    for(i=0;i<m;i++)
    {
        printf("%d",s[i].xh);
        printf("%d",s[i].name);
        for(int j=0;j<n;j++)
        {
            printf("%d",s[i].score[j]);
        }
        printf("\n");
    }
    scanf("%d",x);
    int pos=sear(x);
    printf("%d %d",pos+1,s[pos].score);
    scanf("%s",k);
    int po=sea(k);
    printf("%d %d",pos+1,s[pos].score);
    return 0;
}
