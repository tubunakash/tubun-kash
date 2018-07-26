//Operation of stack using Java

class Stack
{
int st[]; //array to implement stack
int size; //maximum size of the stack
int top; //indrx of topmost element(stack pointer)
Stack() //default constructor
{
size=0;
top=0;
}
Stack(int cap) //parameterised constructor
{
size=cap;
st=new int[size];
top=-1; //initialising top with -1
}
void push(int n) //function to insert element in stack
{
if(top==size-1) //condition for overflow
{
System.out.println("overflow");
}
else
{
top=top+1;
st[top]=n; //storing value in stack
}
}
int pop() //function to delete element from stack
{
if(top==-1) //condition for underflow
{
System.out.println("underflow");
return -999;
}
else
{
int val=st[top]; //storing the element which will be removed
top=top-1;
return val;
}
}
void display()
{
if(top==-1)
{
System.out.println("the stack is empty");
}
else
{
System.out.println("the elements in the stack are : ");
for(int i=top;i>=0;i--)
{
System.out.println(st[i]);
}
}
}
}