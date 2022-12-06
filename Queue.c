#include&lt;stdio.h&gt;
#include&lt;conio.h&gt;
#define n 5
void main()
{
    int queue[n],ch=1,front=0,rear=0,i,j=1,x=n;
    //clrscr();
    printf(&quot;Queue using Array&quot;);
    printf(&quot;\n1.Insertion \n2.Deletion \n3.Display \n4.Exit&quot;);
    while(ch)
    {        printf(&quot;\nEnter the Choice:&quot;);
        scanf(&quot;%d&quot;,&amp;ch);
        switch(ch)
        {
        case 1:
            if(rear==x)
                printf(&quot;\n Queue is Full&quot;);
            else
            {                printf(&quot;\n Enter no %d:&quot;,j++);
                scanf(&quot;%d&quot;,&amp;queue[rear++]);
            }
            break;
        case 2:
            if(front==rear)
            {                printf(&quot;\n Queue is empty&quot;);
            }
            else
            {                printf(&quot;\n Deleted Element is %d&quot;,queue[front++]);
                x++;
            }
            break;
        case 3:
            printf(&quot;\n Queue Elements are:\n &quot;);
            if(front==rear)
                printf(&quot;\n Queue is Empty&quot;);
            else

            {
                for(i=front; i&lt;rear; i++)
                {
                    printf(&quot;%d&quot;,queue[i]);
                    printf(&quot;\n&quot;);
                }
                break;
            case 4:
                exit(0);
            default:
                printf(&quot;Wrong Choice: please see the options&quot;);
            }
        }
    }
    getch();
}