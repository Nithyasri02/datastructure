#include&lt;stdio.h&gt;
 int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
    //clrscr();
    top=-1;
    printf(&quot;\n Enter the size of STACK[MAX=100]:&quot;);
    scanf(&quot;%d&quot;,&amp;n);
    printf(&quot;\n\t STACK OPERATIONS USING ARRAY&quot;);
    printf(&quot;\n\t--------------------------------&quot;);
    printf(&quot;\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT&quot;);
    do
    {
        printf(&quot;\n Enter the Choice:&quot;);
        scanf(&quot;%d&quot;,&amp;choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
  break;
            }
            case 3:
{
                display();
                break;
            }
            case 4:
            {
                printf(&quot;\n\t EXIT POINT &quot;);
                break;
            }
            default:

            {
                printf (&quot;\n\t Please Enter a Valid Choice(1/2/3/4)&quot;);
            }
                 
        }
    }
    while(choice!=4);
    return 0;
}
void push()
{
    if(top&gt;=n-1)
    {
        printf(&quot;\n\tSTACK is over flow&quot;);
         
    }
    else
    {
        printf(&quot; Enter a value to be pushed:&quot;);
        scanf(&quot;%d&quot;,&amp;x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top&lt;=-1)
    {
        printf(&quot;\n\t Stack is under flow&quot;);
    }
    else
    {
        printf(&quot;\n\t The popped elements is %d&quot;,stack[top]);
        top--;
    }
}
void display()
{
    if(top&gt;=0)
    {
        printf(&quot;\n The elements in STACK \n&quot;);
        for(i=top; i&gt;=0; i--)
            printf(&quot;\n%d&quot;,stack[i]);
        printf(&quot;\n Press Next Choice&quot;);
    }
    else
    {
        printf(&quot;\n The STACK is empty&quot;);
    }
    
}