const int zero = 0,neg = -1,pos = +1;
const char c = 'c',CC = 'C',Plus = '+',_Plus = '-',Mul = '*',_Mul = '/',n_u_m_0='0';
int a1var,a2var,arrayintVar[10];
char c1var,c2var,arraycharVar[10];

void testIO{
    const int iiii = 10;
    int i,iarray[10];
    char ch,charray[10];
    
    printf("");
    printf(" !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    scanf(i,ch);
    iarray[0] = i;
    charray[0] = ch;
    printf("IO i:",i);
    printf(ch);
    printf(charray[0]);
    printf(neg+ch);
    printf(charray[0]*(pos-neg));
    
    return;
}

void testIf(int a,char ch){
    int ch2;
    ch2 = ch+ch;
    if(a==10){
        printf("beq10");
        return;
    }
    else{
        if(a>=1) printf("bge1");
        else{
            if(a<=-1)    printf("ble-1");
            else{
                if(a>1) printf("bgt1");
                else{
                    if(a<-1) printf("blt1");
                    else{
                        if(a!=0) printf("bne0");
                        else{
                            if(ch2>126){
                                if(a)
                                    printf("beq0bgt?");
                                else
                                    printf("beq0bgt?");
                            }
                            else
                                printf("ble?");
                        }
                    }
                }
            }
        }
    }
}

void testDoWhile{
    int n;
    n=1;
    do n=n*2; while(n<20)
    do{
        n=n-1;
        if(n/1>=1) ;
        else printf(n);
    }while(n)
}

void testSwitch{
    int x,y;
    char ch;
    y=3;
    scanf(x);
    switch(x+x-x){
        case 0: ch='+';
        case +1: ch='-';
        case -1: ch='*';
        default: ch='_';
    }
    switch(ch){
        case '+': a2var=100;
        case '-': a2var=50;
        case '*': a2var=25;
        case '/': a2var=10;
        case '_': {
            x=x*x;
            if(x-y==0)
                a2var=9;
            else
                a2var=5;
        }
        default:{
            y=y*y;
            if(x/y==0)
                a2var=8;
            else
                a2var=4;
        }
    }
}

int itrue{
    return (1);
}
char chtrue{
    return ('a');
}

void empty{;{};{;};;;}

void testExpression{
    int i,array[10],result;
    i=a2var;
    array[1] = 10;
    result = -neg+i/2-i*zero;
    result = pos*array[itrue]*3*c*(i*(pos+pos)+itrue)*result;
    printf("result",result);
}

int fibo(int n){
    if(n==0) return (0);
    else{
        if(n==1) return (1);
        else return (fibo(n-1)+fibo(n-2));
    }
}

void main(){
    int fn;
    testIO;
    scanf(a1var);
    c1var = 'h';
    testIf(a1var,'h');
    testDoWhile;
    testSwitch;
    itrue;
    chtrue;
    empty;
    testExpression;
    scanf(fn);
    printf("fibo(fn):",fibo(fn));
}
