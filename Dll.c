#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
struct node
{
struct node *prev;
struct node *next;
int data;
};
struct node *head;
void insertion_beginning();
void insertion_last();
void insertion_specified();
void deletion_beginning();
void deletion_last();
void deletion_specified();
void display();
void search();
void main ()
{
int choice =0;
while(choice != 9)
{
printf(&quot;\n*********Main Menu*********\n&quot;);
printf(&quot;\nChoose one option from the following list ...\n&quot;);
printf(&quot;\n===============================================\n&quot;);
printf(&quot;\n1.Insert in begining\n2.Insert at last\n3.Insert at any random
location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the
given data\n7.Search\n8.Show\n9.Exit\n&quot;);
printf(&quot;\nEnter your choice?\n&quot;);
scanf(&quot;\n%d&quot;,&amp;choice);
switch(choice)
{
case 1:
insertion_beginning();
break;
case 2:
insertion_last();
break;
case 3:
insertion_specified();
break;
case 4:
deletion_beginning();
break;
case 5:
deletion_last();
break;
case 6:

deletion_specified();
break;
case 7:
search();
break;
case 8:
display();
break;
case 9:
exit(0);
break;
default:
printf(&quot;Please enter valid choice..&quot;);
}
}
}
void insertion_beginning()
{
struct node *ptr;
int item;
ptr = (struct node *)malloc(sizeof(struct node));
if(ptr == NULL)
{
printf(&quot;\nOVERFLOW&quot;);
}
else
{
printf(&quot;\nEnter Item value&quot;);
scanf(&quot;%d&quot;,&amp;item);
if(head==NULL)
{
ptr-&gt;next = NULL;
ptr-&gt;prev=NULL;
ptr-&gt;data=item;
head=ptr;
}
else
{
ptr-&gt;data=item;
ptr-&gt;prev=NULL;
ptr-&gt;next = head;
head-&gt;prev=ptr;
head=ptr;
}
printf(&quot;\nNode inserted\n&quot;);
}
}
void insertion_last()
{
struct node *ptr,*temp;

int item;
ptr = (struct node *) malloc(sizeof(struct node));
if(ptr == NULL)
{
printf(&quot;\nOVERFLOW&quot;);
}
else
{
printf(&quot;\nEnter value&quot;);
scanf(&quot;%d&quot;,&amp;item);
ptr-&gt;data=item;
if(head == NULL)
{
ptr-&gt;next = NULL;
ptr-&gt;prev = NULL;
head = ptr;
}
else
{
temp = head;
while(temp-&gt;next!=NULL)
{
temp = temp-&gt;next;
}
temp-&gt;next = ptr;
ptr -&gt;prev=temp;
ptr-&gt;next = NULL;
}
}
printf(&quot;\nnode inserted\n&quot;);
}
void insertion_specified()
{
struct node *ptr,*temp;
int item,loc,i;
ptr = (struct node *)malloc(sizeof(struct node));
if(ptr == NULL)
{
printf(&quot;\n OVERFLOW&quot;);
}
else
{
temp=head;
printf(&quot;Enter the location&quot;);
scanf(&quot;%d&quot;,&amp;loc);
for(i=0;i&lt;loc;i++)
{
temp = temp-&gt;next;
if(temp == NULL)
{
printf(&quot;\n There are less than %d elements&quot;, loc);

return;
}
}
printf(&quot;Enter value&quot;);
scanf(&quot;%d&quot;,&amp;item);
ptr-&gt;data = item;
ptr-&gt;next = temp-&gt;next;
ptr -&gt; prev = temp;
temp-&gt;next = ptr;
temp-&gt;next-&gt;prev=ptr;
printf(&quot;\nnode inserted\n&quot;);
}
}
void deletion_beginning()
{
struct node *ptr;
if(head == NULL)
{
printf(&quot;\n UNDERFLOW&quot;);
}
else if(head-&gt;next == NULL)
{
head = NULL;
free(head);
printf(&quot;\nnode deleted\n&quot;);
}
else
{
ptr = head;
head = head -&gt; next;
head -&gt; prev = NULL;
free(ptr);
printf(&quot;\nnode deleted\n&quot;);
}
}
void deletion_last()
{
struct node *ptr;
if(head == NULL)
{
printf(&quot;\n UNDERFLOW&quot;);
}
else if(head-&gt;next == NULL)
{
head = NULL;
free(head);
printf(&quot;\nnode deleted\n&quot;);
}
else
{
ptr = head;

if(ptr-&gt;next != NULL)
{
ptr = ptr -&gt; next;
}
ptr -&gt; prev -&gt; next = NULL;
free(ptr);
printf(&quot;\nnode deleted\n&quot;);
}
}
void deletion_specified()
{
struct node *ptr, *temp;
int val;
printf(&quot;\n Enter the data after which the node is to be deleted : &quot;);
scanf(&quot;%d&quot;, &amp;val);
ptr = head;
while(ptr -&gt; data != val)
ptr = ptr -&gt; next;
if(ptr -&gt; next == NULL)
{
printf(&quot;\nCan&#39;t delete\n&quot;);
}
else if(ptr -&gt; next -&gt; next == NULL)
{
ptr -&gt;next = NULL;
}
else
{
temp = ptr -&gt; next;
ptr -&gt; next = temp -&gt; next;
temp -&gt; next -&gt; prev = ptr;
free(temp);
printf(&quot;\nnode deleted\n&quot;);
}
}
void display()
{
struct node *ptr;
printf(&quot;\n printing values...\n&quot;);
ptr = head;
while(ptr != NULL)
{
printf(&quot;%d\n&quot;,ptr-&gt;data);
ptr=ptr-&gt;next;
}
}
void search()
{
struct node *ptr;
int item,i=0,flag;
ptr = head;
if(ptr == NULL)

{
printf(&quot;\nEmpty List\n&quot;);
}
else
{
printf(&quot;\nEnter item which you want to search?\n&quot;);
scanf(&quot;%d&quot;,&amp;item);
while (ptr!=NULL)
{
if(ptr-&gt;data == item)
{
printf(&quot;\nitem found at location %d &quot;,i+1);
flag=0;
break;
}
else
{
flag=1;
}
i++;
ptr = ptr -&gt; next;
}
if(flag==1)
{
printf(&quot;\nItem not found\n&quot;);
}
}
}