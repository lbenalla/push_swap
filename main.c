#include <stdlib.h>
#include <stdio.h>
int main()
{
   char *s;

   if(!(s = malloc(sizeof(char) * -1)))
      printf("khasak talga 7al");
   else
      printf("ghi kamal");
   return 0;
}

/*#include <stdio.h>
void quicksort_method (int [], int, int);


int main()
{
int element_list[50],count, counter;
*//*printf("Please enter the total count of the elements that you want to sort: ");
scanf("%d", &count);
printf("Please input the elements that has to be sorted:\n");
for (counter = 0; counter < count; counter++)
{
scanf("%d", &element_list[counter]);
}*/
/*count = 5;
element_list[0] = 0;
element_list[1] = 4;
element_list[2] = -3;
element_list[3] = 2;
element_list[4] = 1;

quicksort_method(element_list, 0, count - 1);
printf("Output generated after using quick sort\n");
for (counter = 0; counter < count; counter++)
{
printf("%d ", element_list[counter]);
}
printf("\n");
return 0;
}


void quicksort_method(int element_list[], int low, int high)
{
int pivot, value1, value2, temp;
if (low < high)
   {
   pivot = low;
   value1 = low;
   value2 = high;
      while (value1 < value2)
      {
         while (element_list[value1] <= element_list[pivot] && value1 <= high)
         {
         value1++;
         }
         while (element_list[value2] > element_list[pivot] && value2 >= low)
         {
         value2--;
         }
         if (value1 < value2)
         {
         temp = element_list[value1];
         element_list[value1] = element_list[value2];
         element_list[value2] = temp;
         }
      }

   temp = element_list[value2];
   element_list[value2] = element_list[pivot];
   element_list[pivot] = temp;
   quicksort_method(element_list, low, value2 - 1);
   quicksort_method(element_list, value2 + 1, high);
   }
}*/


/*#include <stdio.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isempty() 
{

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() 
{

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int peek() 
{
   return stack[top];
}

int  pop() 
{
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
	  return -1;
   }
}

void push(int data) 
{

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main() {
   // push items on to the stack 
   push(3);
   push(5);
   push(9);
   push(1);
   push(12);
   push(15);

   printf("Element at top of the stack: %d\n" ,peek());
   printf("Elements: \n");

   // print stack data 
   while(!isempty()) {
      int data = pop();
      printf("%d\n",data);
   }

   printf("Stack full: %s\n" , isfull()?"true":"false");
   printf("Stack empty: %s\n" , isempty()?"true":"false");
   
   return 0;
}*/
