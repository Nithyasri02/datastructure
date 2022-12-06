#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#include&lt;stdlib.h&gt;
void insertAtBeginning(int);
void insertAtEnd(int);
void insertBetween(int,int,int);
void display();
void removeBeginning();
void removeEnd();
void removeSpecific(int);
struct Node
{ int data;
struct Node *next;
}*head = NULL;
void main()
{ int choice,value,choice1,loc1,loc2;
clrscr();
while(1){
mainMenu: printf(&quot;\n\n********* MENU ************\n1. Insert\n2. Display\n3. Delete\n4.
Exit\nEnter your choice: &quot;);
scanf(&quot;%d&quot;,&amp;choice);
switch(choice)
{ case 1: printf(&quot;Enter the value to be insert: &quot;);

scanf(&quot;%d&quot;,&amp;value);
while(1){
printf(&quot;Where you want to insert: \n1. At Beginning\n2. At End\n3.

Between\nEnter your choice: &quot;);
scanf(&quot;%d&quot;,&amp;choice1);
switch(choice1)
{ case 1: insertAtBeginning(value);

break;

case 2: insertAtEnd(value);

break;

case 3: printf(&quot;Enter the two values where you wanto insert: &quot;);

scanf(&quot;%d%d&quot;,&amp;loc1,&amp;loc2);
insertBetween(value,loc1,loc2);
break;

default: printf(&quot;\nWrong Input!! Try again!!!\n\n&quot;);

goto mainMenu;

}
goto subMenuEnd;
}
subMenuEnd:
break;
case 2: display();
break;

case 3: printf(&quot;How do you want to Delete: \n1. From Beginning\n2. From
End\n3. Spesific\nEnter your choice: &quot;);
scanf(&quot;%d&quot;,&amp;choice1);

switch(choice1)
{
case 1: removeBeginning();

break;

case 2: removeEnd(value);

break;

case 3: printf(&quot;Enter the value which you wanto delete: &quot;);

scanf(&quot;%d&quot;,&amp;loc2);
removeSpecific(loc2);
break;

default: printf(&quot;\nWrong Input!! Try again!!!\n\n&quot;);
goto mainMenu;
}
break;
case 4: exit(0);
default: printf(&quot;\nWrong input!!! Try again!!\n\n&quot;);
}
}
}
void insertAtBeginning(int value)
{
struct Node *newNode;
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode-&gt;data = value;
if(head == NULL)
{
newNode-&gt;next = NULL;
head = newNode;
}
else
{
newNode-&gt;next = head;
head = newNode;
}
printf(&quot;\nOne node inserted!!!\n&quot;);
}
void insertAtEnd(int value)
{
struct Node *newNode;
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode-&gt;data = value;
newNode-&gt;next = NULL;
if(head == NULL)
head = newNode;
else
{
struct Node *temp = head;
while(temp-&gt;next != NULL)
temp = temp-&gt;next;
temp-&gt;next = newNode;
}

printf(&quot;\nOne node inserted!!!\n&quot;);
}
void insertBetween(int value, int loc1, int loc2)
{
struct Node *newNode;
newNode = (struct Node*)malloc(sizeof(struct Node));
newNode-&gt;data = value;
if(head == NULL)
{
newNode-&gt;next = NULL;
head = newNode;
}
else
{
struct Node *temp = head;
while(temp-&gt;data != loc1 &amp;&amp; temp-&gt;data != loc2)
temp = temp-&gt;next;
newNode-&gt;next = temp-&gt;next;
temp-&gt;next = newNode;
}
printf(&quot;\nOne node inserted!!!\n&quot;);
}
void removeBeginning()
{
if(head == NULL)
printf(&quot;\n\nList is Empty!!!&quot;);
else
{
struct Node *temp = head;
if(head-&gt;next == NULL)
{
head = NULL;
free(temp);
}
else
{
head = temp-&gt;next;
free(temp);
printf(&quot;\nOne node deleted!!!\n\n&quot;);
}
}
}
void removeEnd()
{
if(head == NULL)
{
printf(&quot;\nList is Empty!!!\n&quot;);
}
else
{
struct Node *temp1 = head,*temp2;

if(head-&gt;next == NULL)
head = NULL;
else
{
while(temp1-&gt;next != NULL)
{
temp2 = temp1;
temp1 = temp1-&gt;next;
}
temp2-&gt;next = NULL;
}
free(temp1);
printf(&quot;\nOne node deleted!!!\n\n&quot;);
}
}
void removeSpecific(int delValue)
{
struct Node *temp1 = head, *temp2;
while(temp1-&gt;data != delValue)
{
if(temp1 -&gt; next == NULL){
printf(&quot;\nGiven node not found in the list!!!&quot;);
goto functionEnd;
}
temp2 = temp1;
temp1 = temp1 -&gt; next;
}
temp2 -&gt; next = temp1 -&gt; next;
free(temp1);
printf(&quot;\nOne node deleted!!!\n\n&quot;);
functionEnd:
}
void display()
{
if(head == NULL)
{
printf(&quot;\nList is Empty\n&quot;);
}
else
{
struct Node *temp = head;
printf(&quot;\n\nList elements are - \n&quot;);
while(temp-&gt;next != NULL)
{
printf(&quot;%d ---&gt;&quot;,temp-&gt;data);
temp = temp-&gt;next;
}
printf(&quot;%d ---&gt;NULL&quot;,temp-&gt;data);
}
}