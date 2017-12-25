#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
#define PF printf
#define SF scanf
struct cnode
{
 int info;
 struct cnode *nxt;
};
void newnode();
struct cnode *start,*cur,*temp;
void create();
void insertbeg();
void insertend();
void insertafter();
void insertbefore();
void insertpos();
void search();
void delete1();
void delpos();
void display();
void erase();
void insasc();
void insdesc();
void rev(struct cnode *);
void newnode();
int count();
main()
{
int ch,i;
start=NULL;
  while(1)
  {
   clrscr();
   PF(".............................CIRCULAR SINGLY LINKED LIST.........................");
   PF("\nPRESS 1:     CREATE\nPRESS 2:     INSERT AT BEGINNING\nPRESS 3:     INSERT AT END\nPRESS 4:     INSERT AFTER\nPRESS 5:     INSERT BEFORE\nPRESS 6:     INSERT AT GIVEN POSITION\nPRESS 7:     COUNT THE NODES\nPRESS 8:     SEARCH THE NODE\nPRESS 9:     DELETE NODE\nPRESS 10:    DISPLAY LINKED LIST\nPRESS 11:    DESTROY LINKED LIST\nPRESS 12:    DELETE AT GIVEN POSITION\nPRESS 13:    INSERT IN ASCENDING ORDER\nPRESS 14:    INSERT IN DESCENDING ORDER\nPRESS 15:    DISPLAY REVERSE LINKED LIST\nPRESS 0:     EXIT");
   PF("\nENTER YOUR CHOICE:");
   SF("%d",&ch);
   switch(ch)
   {
     case 0:exit(0);
     case 1:create();       break;
     case 2:insertbeg();    break;
     case 3:insertend();    break;
     case 4:insertafter();  break;
     case 5:insertbefore(); break;
     case 6:insertpos();    break;
     case 7:count();        break;
     case 8:search();       break;
     case 9:delete1();      break;
     case 10:display();     break;
     case 11:erase();       break;
     case 12:delpos();      break;
     case 13:insasc();      break;
     case 14:insdesc();     break;
     case 15:rev(start);    break;
     default:PF("\nWrong Choice");
   }
     getch();
  }
}
void newnode()
{
 cur=(struct cnode*)malloc(sizeof(struct cnode));
 if(cur==NULL)
 {
  PF("\nSORRY..MEMORY NOT AVAILABLE...");
  return;
 }
 PF("Enter info ");
 SF("%d",&cur->info);
 cur->nxt=NULL;
}

void create()
{
 int n,i;
 struct cnode *pr;
 PF("Enter how much nodes you want to create ");
 SF("%d",&n);
 for(i=1;i<=n;i++)
 {
   newnode();
 //insert new node at end
   if(i==1)
   {
     start=cur;
     start->nxt=start;
   }
   else
   {
    temp->nxt=cur;
      cur->nxt=start;
    }
   temp=cur;
  }
  //insert cur node at beginning

/*  if(i==1)
   {
     start=cur;
     pr=start;
     start->nxt=start;
   }
   else
   {
   cur->nxt=temp;
  // temp->nxt=cur;
    }
   temp=cur;
 }
 start=temp;
pr->nxt=start;
*/
 PF("\nLINKED LIST IS CREATED....");

}
void insertbeg()
{
 newnode();
 if(start==NULL)
 {
   start=cur;
   cur->nxt=start;
  PF("\n%d IS SUCCESSFULLY INSERTED AT BEGINNING..",cur->info);
  return;
 }
  temp=start;
  do
   temp=temp->nxt;
 while(temp->nxt!=start);
 cur->nxt=start;
 start=cur;
 temp->nxt=start;
  PF("\n%d IS SUCCESSFULLY INSERTED AT BEGINNING..",cur->info);
}
void insertend()
{
   newnode();
   if(start==NULL)
 {
   start=cur;
   cur->nxt=start;
    PF("\n%d IS SUCCESSFULLY INSERTED AT END..",cur->info);
  return;
 }
 temp=start;
 do
  temp=temp->nxt;
 while(temp->nxt!=start);
 temp->nxt=cur;
 cur->nxt=start;

   PF("\n%d IS SUCCESSFULLY INSERTED AT BEGINNING..",cur->info);
}
void insertafter()
{
   struct cnode *t,*nxt1;
   int se,pos;
   if(start==NULL)
   {
    PF("\nLL IS EMPTY");
    return;
   }
    pos=0;
    t=start;

   PF("\nENTER INFO AFTER YOU WANT TO INSERT:");
   SF("%d",&se);

   do
   {
     if(t->info==se)
     {
       newnode();
       cur->nxt=t->nxt;
       t->nxt=cur;
       PF("\n%d IS PROPERLY  INSERTED AFTER %d.",cur->info,se);
       return;
     }
     t=t->nxt;
   }while(t!=start);
	  PF("\n%d IS NOT PRESENT IN LINKED LIST..",se);
}
void insertbefore()
{
 struct cnode *t;
   int se,pos;
   if(start==NULL)
   {
    PF("\nLL IS EMPTY");
    return;
   }
    t=start;
   PF("\nENTER INFO BEFORE YOU WANT TO INSERT:");
   SF("%d",&se);

   do
     t=t->nxt;
   while(t->nxt!=start);
   if(se==start->info)
   {
    newnode();
    cur->nxt=start;
    start=cur;
    t->nxt=start;
     PF("\n%d IS PROPERLY  INSERTED BEFORE %d.",cur->info,se);
    return;
   }
   t=start;
   while(t->nxt!=start)
   {
     if(t->nxt->info==se)
     {
       newnode();
	cur->nxt=t->nxt;
       t->nxt=cur;
       PF("\nPROPERLY INSERTED BEFORE %d.",se);
       return;
     }
     t=t->nxt;
   }
	  PF("\n%d IS NOT PRESENT IN LINKED LIST..",se);
}
/*void insertpos()
{
 int pos,i;
 if(start==NULL)
 {
  PF("\nSORRY LINKED LIST IS EMPTY...");
  return;
 }
 PF("\nENTER POSITION IN WHICH YOU WANT TO INSERT A NODE(START AT 1):");
 SF("%d",&pos);
  if(pos==(count()+1))
 {
  insertend();
  return;
 }
 if(pos>count())
 {
   PF("\nNOT A PROPER POSITION");
   return;
 }

 newnode();
   do
     temp=temp->nxt;
   while(temp->nxt!=start);

 if(pos==1 || pos==0)
 {
 cur->nxt=start;
 start=cur;
 temp->nxt=start;
 PF("\n%d IS PROPERLY INSERTED AT POS %d",cur->info,pos) ;
 return;
 }

 temp=start;
 for(i=1;i<pos-1;i++)
   temp=temp->nxt;

 cur->nxt=temp->nxt;
 temp->nxt=cur;
  PF("\n%d IS PROPERLY INSERTED AT POS %d",cur->info,pos) ;
} */
void insertpos()
{
 int pos,i=1;
 struct cnode *t;
 if(start==NULL)
 {
  PF("\nSORRY LINKED LIST IS EMPTY...");
  return;
 }
 PF("\nENTER POSITION IN WHICH YOU WANT TO INSERT A NODE(START AT 1):");
 SF("%d",&pos);

 if(pos==1 || pos==0)
 {
  insertbeg();
 return;
 }
 t=start;
 while(i!=pos-1)
 {
   t=t->nxt;
   i++;
 }
	newnode();
	cur->nxt=t->nxt;
	t->nxt=cur;
  PF("\n%d IS PROPERLY INSERTED AT POS %d",cur->info,pos) ;
}
int count()
{
int i=0;

if(start==NULL)
{
  PF("\nLINKED LIST IS EMPTY...");
  return;
}
temp=start;
do
{
  i++;
  temp=temp->nxt;
}while(temp!=start);
PF("NUMBER OF NODES IN LINKED LIST=%d",i);
return i;
}
void search()
{
 int se,i;
 if(start==NULL)
 {
  PF("\nLINKED LIST IS NOT AVAILABLE...");
  return;
 }
 i=0;
 PF("\nENTER SEARCH ELEMENT");
 SF("%d",&se);
 temp=start;
 do
 {
  i++;
  if(temp->info==se)
  {
    PF("%d IS FOUND AT %d LOCATION.",se,i);
    return;
  }
    temp=temp->nxt;
 }
 while(temp!=start);
       PF("%d IS NOT FOUND IN LINKED LIST",se);
}
void delete1()
{
  int pos,se;
  struct cnode *pr,*t;
  if(start==NULL)
 {
  PF("\nSORRY LINKED LIST IS EMPTY...");
  return;
 }
 PF("\nENTER ELEMENT YOU WANT TO DELETE..");
 SF("%d",&se);
 pr=t=temp=start;
 if(se==start->info)
 {
   do
    t=t->nxt;
   while(t->nxt!=start);

   start=start->nxt;
   t->nxt=start;
   free(temp);
 /* t->nxt=start->nxt;
  pr=start;
  start=start->nxt;
  free(pr);  */
  PF("%d IS SUCCESSFULLY DELTETED FROM LINKED LIST.",se);
  free(temp);
  return;
 }
 t=start;
do
{
if(se==t->info)
{
 pr->nxt=t->nxt;
 free(t);
 return;
}
 pr=t;
 t=t->nxt;
}while(t!=start);

printf("%d does not exist",se);

       PF("%d IS NOT PRESENT IN LINKED LIST.",pos);
}
void display()
{
struct cnode *t;
if(start==NULL)
{
  PF("List is not available");
  return;
}
t=start;

PF("\nSTART->");
do
{
PF("%5d->",t->info) ;
t=t->nxt;
}while(t!=start);

PF("START");
}
void erase()
{
  struct cnode *t,*tstart;
  if(start==NULL)
  {
  PF("List is not available");
  return;
  }
 tstart=t=start;
  do
    {
   t=start;
   start=start->nxt;
   free(t);
  }while(t!=t->nxt);

/* do
 {
  t=start;
  start=start->nxt;
  tstart=tstart->nxt;
  free(t);
 } while(tstart!=start);*/
 PF("linked list is destroyed");
}
void delpos()
{
 int i,pos=0,u=0;
 struct cnode *ptr,*t,*p;
 if(start==NULL)
 {
  PF("\nSORRY..CREATE LINKED LIST FIRST");
  return;
 }
 PF("\nENTER POSITION OF NODE YOU WANT TO DELETE");
 SF("%d",&pos);
 t=start;

 do
 {
  u++;
  t=t->nxt;
 }while((t->nxt!=start));
  if(pos>u+1)
 {
   PF("\nNOT A PROPER POSITION TRY AGAI...");
   return;
 }
 p=start;
  if(pos==1 || pos==0)
 {
  start=start->nxt;
  t->nxt=start;
  free(p);
  return;
 }
 ptr=start;
 for(i=1;i<pos;i++)
 {
   t=ptr;
   ptr=ptr->nxt;
 }
 t->nxt=ptr->nxt;

 free(ptr);
}
void insasc()
{
  int n,i;
  struct cnode *t;
 PF("Enter how much nodes you want to create ");
 SF("%d",&n);
 for(i=1;i<=n;i++)
 {
   newnode();
  if(start==NULL || cur->info<=start->info)
  {
    cur->nxt=start;
    start=cur;
  //  PF("\n%d is inserted according to priority",cur->d);
  }
else{
 t=start;
 //we have to locate t in a such a way that cur->p
 //should be greater than t->p
 while(t->nxt!=NULL && t->nxt->info<=cur->info)
   t=t->nxt;
  cur->nxt=t->nxt;
  t->nxt=cur;
  }
 }
  t=start;
 while(t->nxt!=NULL)
     t=t->nxt;
  t->nxt=start;
  PF("\nLinked list is created.");
 }
void insdesc()
{
  int n,i;
  struct cnode *t;
  start=NULL;
 PF("Enter how much nodes you want to create ");
 SF("%d",&n);
 for(i=1;i<=n;i++)
 {
   newnode();
  if(start==NULL || cur->info>=start->info)
  {
    cur->nxt=start;
    start=cur;
  //  PF("\n%d is inserted according to priority",cur->d);
  }
else{
 t=start;
 //we have to locate t in a such a way that cur->p
 //should be greater than t->p
 while(t->nxt!=NULL && t->nxt->info>=cur->info)
   t=t->nxt;
  cur->nxt=t->nxt;
  t->nxt=cur;
  }
 }
 t=start;
   while(t->nxt!=NULL)
     t=t->nxt;
  t->nxt=start;
  PF("\nLinked list is created.");
 }
void rev(struct cnode *t)
{

 if(t->nxt==start)
   return;
 rev(t->nxt);
 PF("\n%d",t->info);
 if(t==start)
    PF("\n%d",t->info);
}