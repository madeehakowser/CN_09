#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FRAM_TXT_SIZ 3
#define MAX_NOF_FRAM 127
char str[FRAM_TXT_SIZ*MAX_NOF_FRAM];
struct frame
{
char text[FRAM_TXT_SIZ];
int seq_no;
}
fr[MAX_NOF_FRAM],shuf_ary[MAX_NOF_FRAM];
int assign_seq_no()
{
int k=0,i,j;
for(i=0;i<strlen(str);k++)
{
fr[k].seq_no=k;
for(j=0;j<FRAM_TXT_SIZ&&str[i]!='\0';j++)
{
fr[k].text[j]=str[i];
i++;
}
}
printf("\n After assigning sequence numbers:\n");
for(i=0;i<k;i++)
{
printf("%d:",i);
for(j=0;j<3;j++)
{
printf("%c",fr[i].text[j]);
}
printf("\t");
}
return k;
}
void generate(int*random_ary,const int limit)
{
int r,i=0,j;
while(i<limit)
{
r=rand()%limit;
for(j=0;j<i;j++)
if(random_ary[j]==r)
break;
if(i==j)random_ary[i++]=r;
}
}
void shuffle(const int no_frames)
{
int i,j,k,*random_ary,a=no_frames;
random_ary=(int*)malloc(a*sizeof(int));
generate(random_ary,no_frames);
for(i=0;i<no_frames;i++)
shuf_ary[i]=fr[random_ary[i]];
printf("\n\nAFTER SHUFFLING:\n");
for(i=0;i<no_frames;i++)
{
printf("%d:",i);
for(j=0;j<3;j++)
{
printf("%c",shuf_ary[i].text[j]);
}
printf("\t");
}
}
void sort(const int no_frames)
{
int i,j,flag=1;
struct frame hold;
for(i=0;i<no_frames-1&&flag==1;i++)
{
flag=0;
for(j=0;j<no_frames-1;j++)
if(shuf_ary[j].seq_no>shuf_ary[j+1].seq_no)
{
hold=shuf_ary[j];
shuf_ary[j]=shuf_ary[j+1];
shuf_ary[j+1]=hold;
flag=1;
}
}
}
int main()
{
int no_frames,i,j;
clrscr();
printf("ENTER THE MESSAGE:");
gets(str);
no_frames=assign_seq_no();
shuffle(no_frames);
sort(no_frames);
printf("\n\nAFTER SORTING\n");
for(i=0;i<no_frames;i++)
for(j=0;j<3;j++)
printf("%c",shuf_ary[i].text[j]);
printf("\n\n");
getch();
return 0;
}

