const int a=1;
const int b=2;
const char c='a';

int x;
int y;
int _y1;
char _z1;
int judge;
void init(int m)
{
    x=m;
    return;
}

int add(int m,int n)
{
    return (m+n);
}

int addx
{
    x=x+1;
    if(x!=99)
    {
        return (-100);
    }
    else return (100);
}

int addx1
{
    x=x+1;
    return (0);
}

char tolow(char c)
{
    char d;
    d=c;
    return (d);
}


int fib(int x)
{
    if(x==1) return (1);
    else if(x==2)
    {
        return (1);
    }
    else if(x==-100)
    {
        return (-100);
    }
    else;
    if(x==2) return (1);
    else;
    return (fib(x-1)+fib(x-2));
}


void testif
{
    if(x=='b'-'a')
        y=1;
    else
        y=2;
    if(y!=1) judge=0;else;
    if(x>=1)
        y=3;
    else
        y=4;
    if(y!=3) judge=0;else;
    x=x+1;
    if(x<=1)
        y=5;
    else
        y=6;
    if(y!=6) judge=0;else;
    if(x>1)
        y=7;
    else
        y=8;
    if(y!=7) judge=0;else;
    if(x<0)
        y=9;
    else
        y=10;
    if(y!=10) judge=0;else;
    x=fib(8)-1;
    if(x!=20)
        y=11;
    else
        y=12;
    if(y!=12) judge=0;
    else;
    x=2;
}


int testcase1(int x)
{
    switch(x){
        case 1:return (1);
        case 2:return (2);
        default:return (3);
    }
}
int testcase2(char x)
{
    switch(x){
        case 'a':return (1);
        default:return (2);
    }
}
void test_do_while(int a)
{
    do
        addx1;
    while(x<3+2)
    if(x!=5) 
    {
        printf("wrongwhile1");
        judge=0;
        }
    else;
    y=3;
    do
    {
        x=x+1;
    }while(x<(2*3+2/1))
    if(x!=8) judge=0;else;
    do
    {
        do
        {
            x=x-1;
        }while(x>=(1+(2-3)))
        y=y-1;
    }while(y>=1);
    if(x!=-3) 
    {
        printf("wrongwhile2");
        judge=0;
        }
    else;
    if(y!=0) 
    {
        printf("wrongwhile3");
        judge=0;
        }
    else;
}

void main()
{
    const int t1=1;
    const int t2=2;
    const char t3= 'a';
    const int tt1=+0123;
    const int tt2=-000909;
    
    int t4;
    int t5;
    int aa[100];
    int t6;
    char t7;
    char t8;
    char t9[100];
    
    judge=1;


    t7=t3;
    t9[10]=tolow(t7);
    aa[10]=fib(5);


    t4=fib(3);
    
    if((t9[10]+aa[10]*-1*t4)/(8/4)-'0'+tt1!=--118) 
    {
        printf("wrong1");
        judge=0;
    }
    else if(tt2+tolow('0')!=-861)
    {
        printf("wrong2",tt2+tolow('0'));
        judge=0;
    }else;

    init(2);
    
    if(x!=2) 
    {
        printf("wrong3");
        judge=0;
    }else;
    
    if(add(9/3,aa[10])!=8)
    {
        printf("wrong4");
        judge=0;
    }
    else if(fib(10)!=55)
    {
        printf("wrong5");
        judge=0;
    }
    else;
    x=tolow(t7)+fib(add(-b,4*a));
    if(addx!=++100)
    {
        printf("wrong6");
        judge=0;
    }
    else;

    x=1;
    testif;
    if(testcase1(x)!=2) 
    {
        printf("wrong7");
        judge=0;
    }else;
    
    x=add(fib(3)-testcase1(1),1);
    if(testcase1(x-1)!=-t1+t2) 
    {
        printf("wrong8");
        judge=0;
        }else;
    X=-1;
    if(testcase1(x)!=-aa[10]+fib(6)) 
    {
        printf("wrong9");
        judge=0;
    }else;
    x=0;
    test_do_while(x);

    scanf(t5,t6);
    if(fib(t5-1)+t6!=5) 
    {
        printf("wrong10");
        judge=0;
    }else;
    t8='a';
    if(-testcase2(t8)!=-fib(t6)) 
    {
        printf("wrong11");
        judge=0;
        }else;
    t8='b';
    if(testcase2(t8)!=t6) 
    {
        printf("wrong12");
        judge=0;
    }else;
    scanf(t8,t7);
    if(t8-0!=t7+t3-'a')
    {
        printf("wrongt7t8neq\n\t\r");
    }else;

    if(judge==0) printf("wrong\n");
    else printf("right\n",x);
}
