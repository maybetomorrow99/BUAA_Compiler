cOnst int A1 = -10, B1 = 5;
const Char C1 = '8', D1 = '-', D2 = 'A';
int i,j,k, intarray[10];
char op, chararray[11]; 

int add(int A1, int b, int c, int d, char k){
    return (a1+b+c+d+k);
}

char get{
    const int A1 = 100;
    const char A2 ='c';
    return (chararray[-k+2*k]);
}

int return_3{
    return (3);
}

int fib(int n){
    if(n<0){
        return (0);
    }else
    if(n)
        return (fib(n-1) + fib(n-2));
    else 
        return (1);
}

void testexpr{
    printf("test expr\n");
    intarray[0] = add(A1*B1,A1/B1,B1/A1,(D1),D2);
    intarray[1] = 1+2+2*(3+C1/(2*(add(1,return_3,intarray[0],-('A'),'A')-40-k)));
    intarray[2] = fib(k);
    j = 0;
    do{
        printf(intarray[j]);
        j=j+1;
    }while(j<=2);
    return;
}

void testempty{
    {
        {
            ;
        }
        {
        
        }
    }
}

void main(){
    const int max=10;
    int x,y,z;
    char tem;
    i = 0;
    k = 0;
    z = max;
    chararray[0] = 'h';
    chararray[1] = 'e';
    chararray[+2] = 'l';
    chararray[3] = 'l';
    chararray[4] = 'o';
    chararray[5] = '_';
    chararray[6] = 'w';
    chararray[7] = 'o';
    chararray[8] = 'r';
    chararray[9] = 'l';
    chararray[10] = 'd';
    scanf(x,y,op); 
    
    switch(op){
        case '+' : {
            z = x+y;
            switch(z){
                case 1: k = k + 1; 
                case 2: k = k + 2; 
                default: k = k + 3; 
            } 
            
        }                            
        case '-' : {
            z = x-y; 
            if(z == 0){
                k = k + 4;
            }else k = k + 5;
            
        }
        default : {
            z = x*y;
             if(z>=0) k = k + 6;
            else k = k + 7;
            
        } 
    }
    tem = get;
    if((tem) != ('_')){
        printf("print string and expr, got char: ",tem);
    } 
    else{
        printf(" !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    }
    testexpr;
    testempty;
    return ;
}
