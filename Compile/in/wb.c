const int con_Int = 10;const int con_int1 = 11;
const char con_Char = 'x';
char b, char_array[10];
int int_array[100];
int _, _a, _b, _z, _c, _a1__1__, _1, a1_22, A_1, Z_11, Z11, z0, z_0;

int fib(int x)
{
    if(x == 1)
        return (1);
    else
    {
        if(x==0)
            return (0);
        else 
        {
            return (fib(x-1)+fib(x-2));
            ;
            ;
            ;
            ;
            ;
        }
    }
}

void test_array
{
    int a[100];
    int b[100];
    int i;
    i = 0;
    
    do
    {
        a[i] = i;
        b[i] = i;
        i = i+1;
    }while(i<100);

    i=a[b[a[a[b[a[16]]]]]] * a[b[a[b[a[b[a[a[11]]]]]]]];
    printf(i);
    return;
}


int cal
{
    int result;
    int h1, h2, h3, h4, h5, i;
    int a[5];
    h1 = 0;
    h2 = 0;
    h3 = 0;
    h4 = 0;
    h5 = 0;
    i = 0;
    result = 0;
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;

    h1 = h2*h3;
    h1 = a[4]/a[2];
    h2 = -h1*h3+h1-(a[4]+a[2])+fib(10)--4;
    return (h2);
}

int test_case(int c, char _c, int d)
{
    int flag;
    flag = -1;
    switch (c)
    {
        case 1:
        {
            flag = 1;
        }
        case 15:
        {
            if(d == 1)
                flag = -15;
            else
                flag = 15;
        }
        default:
        {
            switch (_c)
            {
                case 'a':
                {
                    flag = 97;
                }
                case 'b':
                {
                    flag = 98;
                }
                default:
                {
                    flag = 0;
                }
            }
        }
    }
    return (flag);
}


char ret_char(char x)
{
    char p;
    p = x;
    return (p);
}

int test_if(int a, int b, int mod)
{
    if(mod == 1)
    {
        if(a<b)    return (1);
        else ;
        if(a<=b)    return (2);
        else ;
        if(a == b)    return (3);
        else ;
        if(a>b)    return (4);
        else ;
        if(a>=b)    return (5);
        else return (0);
    }
    else
    {
        if(a!=b)    return (6);
        else return (0);
    }
}    

int test_can(int a, int b, int c, int d, int e)
{
    int ha;
    ha = a+b+c+d+e;
    return (ha);
}

void test_tao(int a, char b)
{
    if(a)
    {
        switch(b)
        {
            case 'x':
                printf('x');
            case 'y':
                printf(('y'));
            default:
                printf("default");
        }
    }
    else
    {
        return;
    }
}

void main()
{
    const int c1 = 1;
    const char c_c = 'z';
    char hahahaha;
    int re;
    int i, a[100];
    int j;
    int result;
    int k1, k2;
    char read_in,b[100];
    i = 0;
    j = 0;
    a[1] = 2;
    do
    {
        int_array[i] = i;
        i = i+1;
    }while(i<10)

    test_array;

    i=cal;
    printf(i);

    scanf(read_in);
    scanf(j);
    printf(test_case(j, read_in, 1));

    
    b[1] = read_in;
    hahahaha = ret_char(b[1]);
    printf(hahahaha);

    scanf(j);
    k1 = test_if(1, j, 1);
    k2 = test_if(1, j, 0);
    printf(k1+k2);
    printf("This is A String ! #$%&'()*+,-./0123456789:<^_~|`");

    scanf(j, read_in);
    test_tao(j, read_in);
    printf(test_can(1, 2, 3, test_can(1, 2, 3, 4, 5), 4));
                    
}
