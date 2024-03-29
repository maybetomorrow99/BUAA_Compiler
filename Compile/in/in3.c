const int zero = 0,neg = -1,pos = +1;
const char c = 'c',CC = 'C',Plus = '+',_Plus = '-',Mul = '*',_Mul = '/',n_u_m_0='0';
int a1var,a2var,arrayintVar[10];
char c1var,c2var,arraycharVar[10];

void testIO{
    int i,iarray[10];
    char ch,charray[10];
    
    printf("");
    printf(" !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    scanf(i,ch);
    iarray[0] = i;
    charray[0] = ch;
    printf("IO i:",i);
    printf("IO ch:",ch);
    printf("IO iarray[0]:",iarray[0]);
    printf("IO charray[0]:",charray[0]);
    printf("IO neg+ch:",neg+ch);
    printf("IO charray[0]*(pos-neg):");
    printf(charray[0]*(pos-neg));
    
    return;
}

void testIf(int a,char ch){
    int ch2;
    ch2 = ch+ch;
    if(a==10){
        printf("If a==10");
        return;
    }
    else{
        if(a>=1) printf("If a>=1");
        else{
            if(a<=-1)    printf("If a<=-1");
            else{
                if(a>1) printf("If a>1");
                else{
                    if(a<-1) printf("If a<-1");
                    else{
                        if(a!=0) printf("If a!=0");
                        else{
                            if(ch2>126){
                                if(a)
                                    printf("If a!=0,ch>?");
                                else
                                    printf("If a==0,ch>?");
                            }
                            else
                                printf("If ch<=?");
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
        if(n/3>=3) printf("DW n/3>=3,n=",n);
        else printf("DW n/3<3,n=",n);
    }while(n)
}

void testSwitch{
    int x,y;
    char ch;
    scanf(x,y);
    switch(x){
        case 0: printf("Switch x==0");
        case +1: printf("Switch x==1");
        case -1: printf("Switch x==-1");
        default: printf("Switch x!=0,+1,-1");
    }
    scanf(ch);
    switch(ch){
        case '+': printf("Switch x+y=",x+y);
        case '-': printf("Switch x-y=",x-y);
        case '*': printf("Switch x*y=",x*y);
        case '/': printf("Switch x/y=",x/y);
        case '_': {
            x=x*x;
            if(x-y==0)
                printf("Switch x*x-y==0");
            else
                printf("Switch x*x-y!=0");
        }
        default:{
            y=y*y;
            if(x/y==0)
                printf("Switch x/(y*y)==0");
            else
                printf("Switch x/(y*y)!=0");
        }
    }
}

int itrue{
    return (1);
}
char chtrue{
    return ('a');
}

void empty{;}

void testExpression{
    int i,array[10],result;
    i=5;
    array[1] = 10;
    result = -neg+i/2-i*zero;
    printf("Exp -neg+i/2-i*zero=",result);
    result = pos*array[itrue]*3*c*(i*(pos+pos)+itrue);
    printf("Exp pos*array[itrue]*3*c*(i*(pos+pos)+itrue)=",result);
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
    testIf(a1var,c1var);
    testDoWhile;
    testSwitch;
    itrue;
    chtrue;
    empty;
    testExpression;
    scanf(fn);
    printf("fibo(fn):",fibo(fn));
}
