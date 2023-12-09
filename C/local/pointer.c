#include <stdio.h>
#include <stdlib.h>
void exchange(void);
void const_array(const int * a, int n);
void const_pointer(void);
void pointer_to_pointer(void);
void multi_dimensional_array_pointer(void);

int main() 
{
    /**/
    // example : change value of a and b using pointer
    printf("Example: exchange()\n");
    exchange();

    // example : constant array
    printf("Example: const_pointer()\n");
    const int a[5] = {1,3,5,7,9};
    const_array(a,5);

    // example : pointer to pointer
    printf("Example: pointer_to_pointer()\n");
    pointer_to_pointer();

    // example : constant pointer
    printf("Example: const_pointer()\n");
    const_pointer();

    // example : multi-dimensional array pointer
    printf("Example: multi_dimensional_array_pointer()\n");
    multi_dimensional_array_pointer();


    return 0;
}

void multi_dimensional_array_pointer(void)
{
    int a[2][2][2] = {{{1,2},{3,4}},{{5,6},{7,8}}};
    int (* pta)[2][2] = a;
    printf("***a = %d\n",***a);
    printf("pta[0][0][0] = %d\n",pta[0][0][0]);
    int * ptb = a[0][0];
    printf("ptb[0] = %d\n",ptb[0]);
    int * ptc [2][2] = {a[0][0],a[0][1],a[1][0],a[1][1]};
    printf("*ptc[0][0] = %d\n",*ptc[0][0]);
}

void exchange(void)
{
    int a = 0, b = 1;
    printf("Original: %d, %d\n",a,b);
    int * pta = &a, * ptb = &b;
    int temp;
    temp = *pta;
    *pta = *ptb;
    *ptb = temp;
    printf("Exchanged: %d, %d\n",a,b);
}

void const_array(const int * a, int n)
{
    n = 5;
    printf("the array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(a+i));
        //printf("%d ",a[i]); // same as *(a+i)
    }
    //*a = 100; // can't change value of a
    a = a + 1; // can change address of a
    printf("\n*a = %d\n",*a);
}

void const_pointer(void)
{
    // example : pta address can be changed but value can't be changed
    int a[5] = {1,3,5,7,9};
    const int * pta = a; // consider pta as a pointer to constant, but not a constant pointer
    pta = a + 1;
    printf("a = %d; ",*pta);

    // example : ptb value can be changed but address can't be changed
    int b[5] = {2,4,6,8,10};
    int * const ptb = b; // consider ptb as a constant pointer, but not a pointer to constant
    *ptb = *ptb - 1;
    printf("b = %d; ",*ptb);

    // example : ptc address or value can't be changed
    int c[5] = {1,3,5,7,9};
    const int * const ptc = c;
    // ptc = c + 1; // error
    // *ptc = *ptc - 1; // error
    printf("c = %d; \n",*ptc);
}

void pointer_to_pointer(void)
{
    int a = 1;
    int * pta = &a;
    int ** ppta = &pta;
    printf("a = %d\n",**ppta);
}