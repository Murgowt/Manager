#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct btnode
{
 int year;
 int cost;
 int sales;
 int profit;
 struct btnode *l;
 struct btnode *r;
}*root = NULL, *temp = NULL, *t2, *t1;
void delete1(struct btnode *t);

void insert();
void delete2();
void inorder(struct btnode *t);
void create();
void search(struct btnode *t);
void preorder(struct btnode *t);
void postorder(struct btnode *t);
void search1(struct btnode *t,int data);
int smallest(struct btnode *t);
int largest(struct btnode *t);
void particular_search(struct btnode *t,int yr)
{
if(t==NULL)
printf("\nRecord not available.\n");
if(t->year==yr)
{
printf("--%d --\n ", t->year);
 printf("Cost:%d \n ", t->cost);
 printf("Sales:%d \n", t->sales);
 printf("Profit:%d \n", t->profit);
 printf("\n");
}
if(t->year>yr)
particular_search(t->l,yr);
else if(t->year<yr)
particular_search(t->r,yr);
}
int flag = 1;
void sales_record()
{
 int ch=0;

 while(ch!=5)
 {
 printf("\n1 - Enter a New Record.\n");
 printf("2 - Erase an Incorrect Record\n");
 printf("3 - Chronological Order of Existing Records\n");
 printf("4 - Search a particular year's Record'\n");
 printf("5 - Exit\n");
 printf("\nEnter your choice : ");
 scanf("%d", &ch);
  int yr;
 switch (ch)
 {
 case 1:
 insert();
 break;
 case 2:
 delete2();
 break;
 case 3:
 inorder(root);
 break;
 case 4:

printf("Enter the year of the record to be searched");
scanf("%d",&yr);
particular_search(root,yr);
break;
 case 5:
 continue;
 break;

 default :
 printf("Wrong choice, Please enter correct choice ");
 break;
 }
 }
}
void insert()
{
 create();
 if (root == NULL)
 root = temp;
 else
 search(root);
}
void create()
{

 temp = (struct btnode *)malloc(1*sizeof(struct btnode));
 printf("Enter the year of the Record: ");
 scanf("%d", &temp->year);
 printf("Enter the Cost of the Record: ");
 scanf("%d", &temp->cost);
 printf("Enter the sales of the Record: ");
 scanf("%d", &temp->sales);
 temp->profit=temp->sales-temp->cost;
 temp->l = temp->r = NULL;
}
void search(struct btnode *t)
{
 if ((temp->year > t->year) && (t->r != NULL))
 search(t->r);
 else if ((temp->year > t->year) && (t->r == NULL))
 t->r = temp;
 else if ((temp->year < t->year) && (t->l != NULL))
 search(t->l);
 else if ((temp->year < t->year) && (t->l == NULL))
 t->l = temp;
}
void inorder(struct btnode *t)
{
 if (root == NULL)
 {
 printf("No records to display");
 return;
 }
 if (t->l != NULL)
 inorder(t->l);
 printf("--%d --\n ", t->year);
 printf("Cost:%d \n ", t->cost);
 printf("Sales:%d \n", t->sales);
 printf("Profit:%d \n", t->profit);
 printf("\n");
 if (t->r != NULL)
 inorder(t->r);
}
/* To check for the deleted node */
void delete2()
{
 int data;
 if (root == NULL)
 {
 printf("No records to delete");
 return;
 }
 printf("Enter the year to be deleted : ");
 scanf("%d", &data);
 t1 = root;
 t2 = root;
 search1(root, data);
}
/* Search for the appropriate position to insert the new node */
void search1(struct btnode *t, int data)
{
 if ((data>t->year))
 {
 t1 = t;
 search1(t->r, data);
 }
 else if ((data < t->year))
 {
 t1 = t;
 search1(t->l, data);
 }
 else if ((data==t->year))
 {
 delete1(t);
 }
}
/* To delete a node */
void delete1(struct btnode *t)
{
 int k;
 /* To delete leaf node */
 if ((t->l == NULL) && (t->r == NULL))
 {
 if (t1->l == t)
 {
 t1->l = NULL;
 }
 else
 {
 t1->r = NULL;
 }
 t = NULL;
 free(t);
 return;
 }
 /* To delete node having one left hand child */
 else if ((t->r == NULL))
 {
 if (t1 == t)
 {
 root = t->l;
 t1 = root;
 }
 else if (t1->l == t)
 {
 t1->l = t->l;
 }
 else
 {
 t1->r = t->l;
 }
 t = NULL;
 free(t);
 return;
 }
 /* To delete node having right hand child */
 else if (t->l == NULL)
 {
 if (t1 == t)
 {
 root = t->r;
 t1 = root;
 }
 else if (t1->r == t)
 t1->r = t->r;
 else
 t1->l = t->r;
 t == NULL;
 free(t);
 return;
 }
 /* To delete node having two child */
 else if ((t->l != NULL) && (t->r != NULL))
 {
 t2 = root;
 if (t->r != NULL)
 {
 k = smallest(t->r);
 flag = 1;
 }
 else
 {
 k =largest(t->l);
 flag = 2;
 }
 search1(root, k);
 t->year = k;
 }
}
int smallest(struct btnode *t)
{
 t2 = t;
 if (t->l != NULL)
 {
 t2 = t;
 return(smallest(t->l));
 }
 else
 return (t->year);
}
int largest(struct btnode *t)
{
 if (t->r != NULL)
 {
 t2 = t;
 return(largest(t->r));
 }
 else
 return(t->year);
}
struct node *create1(struct node *start);
void display(struct node *start);
struct node *delete_func(struct node *start);
void enqueue_order();
void display_order();
void dequeue_order();
struct node
{
 int expenditure;
 char name[100];
 struct node *next;
};
struct order
{
char name[100];
int month;
int year;
int date;
};
struct order queue[100];
int rear=-1,front=-1;
struct node *item_start=NULL;
struct node *employee_start=NULL;

void assign(int i,struct order temp)
{
int j;
for (j = rear + 1; j > i; j--)
 {
 queue[j] = queue[j - 1];
 }
strcpy(queue[rear].name,temp.name);
queue[i].year = temp.year;
queue[i].month = temp.month;
queue[i].date = temp.date;
}
void check(struct order temp)
{
int i,j;
 for (i = 0; i <= rear; i++)
 {
 if (temp.year < queue[i].year)
 {
 assign(i,temp);
 return;
 }
 else if( temp.year==queue[i].year)
 {
 if (temp.month < queue[i].month)
 {
 assign(i,temp);
 return;
 }
 else if(temp.month==queue[i].month)
 {
 if(temp.date<=queue[i].date)
 {
 assign(i,temp);
 return;
 }
}

 }
}
strcpy(queue[rear].name,temp.name);
 queue[i].year = temp.year;
queue[i].month = temp.month;
queue[i].date = temp.date;
}
void order_manager()
{
int choice=0;
 while(choice!=5)
{
 printf("\n 1.Add a New Order .\n");
 printf(" 2.Display the Pending Orders\n");
 printf(" 3.Remove the Upcoming Order.\n");
 printf(" 4.Sales_record.\n");
 printf(" 5.Exit\n");
 printf("Enter your choice:\t");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 enqueue_order();
 break;
 case 2:
 display_order();
 break;
 case 3:
 dequeue_order();
 break;
 case 5:
sales_record();
break;
 case 4:
 continue;
 break;
 default:
 printf("\n Wrong Choice:\n");
 break;
 }
 }
}
void enqueue_order()
{
struct order temper;
printf("Enter the Name of delivery Reciptant: ");
scanf("%s",&temper.name);
printf("\nEnter the Year of delivery: ");
scanf("%d",&temper.year);
printf("Enter the month of delivery: ");
scanf("%d",&temper.month);
printf("Enter the date of delivery: ");
scanf("%d",&temper.date);
if (rear >=99)
 {
 printf("\nThe Hotel takes in only 100 orders at a time.\n");
 return;
 }
 if ((front == -1) && (rear == -1))
 {
 front++;
 rear++;
 strcpy(queue[rear].name,temper.name);
 queue[rear].year=temper.year;
 queue[rear].month=temper.month;
 queue[rear].date=temper.date;
 return;
 }
 else
 check(temper);
 rear++;
};
void display_order()
{
int temperory=front;
 if ((front == -1) && (rear == -1)||(front==rear && front!=0))
 {
 printf("\nNo orders Yet.");
 return;
 }
 for (temperory; temperory <= rear; temperory++)
 {
 printf("%s =>%d.%d.%d\n",queue[temperory].name,queue[temperory].date,queue[temperory].month,queue[temperory].year);
 }
}
void dequeue_order()
{
if((rear==-1 && front==-1) || (rear<=front))
{
printf("\nNo Orders Pending.\n");
}
else
front++;
}
void employee_menu()
{
int choice=0;
 while(choice!=4)
{
 printf("\n 1.Appoint a New Staff Member .\n");
 printf(" 2.Display the Current Staff\n");
 printf(" 3.Delete a Staff Member from the DataBase\n");
 printf(" 4.Exit\n");
 printf("Enter your choice:\t");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 employee_start=create1(employee_start);
 break;
 case 2:
 display(employee_start);
 break;
 case 3:
 employee_start=delete_func(employee_start);
 break;
 case 4:
 continue;
 break;
 default:
 printf("\n Wrong Choice:\n");
 break;
 }
 }
}
void item_menu()
{
int choice=0;
 while(choice!=4)
{
 printf("\n 1.Add an item to the Menu.\n");
 printf(" 2.Display the items in the Menu\n");
 printf(" 3.Delete an item from the Menu\n");
 printf(" 4.Exit\n");
 printf("Enter your choice:\t");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 item_start=create1(item_start);
 break;
 case 2:
 display(item_start);
 break;
 case 3:
 item_start=delete_func(item_start);
 break;
 case 4:
 continue;
 break;
 default:
 printf("\n Wrong Choice:\n");
 break;
 }

 }
}
int main()
{
printf("----------------WELCOME TO Les-Amigos Restaurant----------------");
 int choice=0;
 while(1)
{
 printf("\n 1.Item Inventory.\n");
 printf(" 2.Employee Database\n");
 printf(" 3.Orders Management\n");
 printf(" 4.Sales Records\n");
 printf(" 5.Exit\n");
 printf("Enter your choice:\t");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 item_menu();
 break;
 case 2:
 employee_menu();
 break;
 case 3:
 order_manager();
 break;
 case 4:
 sales_record();
 break;
 case 5:
 exit(0);
 break;
 default:
 printf("\n Wrong Choice:\n");
 break;
 }
 }
 return 0;
}
struct node *create1(struct node *start)
{
 struct node *temp,*ptr;
 int count=0;
 temp=(struct node *)malloc(sizeof(struct node));
 if(temp==NULL)
 {
 printf("\nOut of Memory Space:\n");
 exit(0);
 }
 printf("\nEnter the Name :");
 scanf("%s",&temp->name);
 printf("Enter the Expenditure Involved: ");
 scanf("%d",&temp->expenditure);
 temp->next=NULL;
 if(start==NULL)
 {
 start=temp;
 }
 else
 {
 ptr=start;
 while(ptr->next!=NULL)
 {
 ptr=ptr->next;
 }
 ptr->next=temp;
 }
 return(start);
}
void display(struct node *start)
{
 struct node *ptr;
int count=1;
 if(start==NULL)
 {
 printf("\nList is empty:\n");
 return;
 }
 else
 {
 ptr=start;
 while(ptr!=NULL)
 {
 printf("%d %s[ %d]\n",count,ptr->name,ptr->expenditure );
 ptr=ptr->next ;
 count++;
 }
 }
}
struct node *delete_func(struct node *start)
{
 int i,pos;
 struct node *temp,*ptr;
 if(start==NULL)
 {
 printf("\nThe List is Empty:\n");
 }
 else
 {
 display(start);
 printf("\nEnter the Serial Number to be deleted:\t");
 scanf("%d",&pos);
 if(pos==1)
 {
 ptr=start;
 start=start->next ;
 free(ptr);
 }
 else
 {
 ptr=start;
 for(i=2;i<=pos;i++)
 {
 temp=ptr;
 ptr=ptr->next ;
 if(ptr==NULL)
 {
 printf("\nSerial Number not Found:\n");
 return(start);
 }
 }
 temp->next =ptr->next ;
 free(ptr);
 }
 }
 return(start);
}
