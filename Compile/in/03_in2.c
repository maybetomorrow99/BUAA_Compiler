const int con_int_1 = 1, con_int_2 = 2; 
const char con_char_1 = 'a', con_char_2 = 'b';

INT var_int_1, var_int_2, var_int_array_1[101]; 
int var_int_array_2[101];
char var_char_1, var_char_array[101];

int _abcdefghigklmnopqrstuvwxyz;
int ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890;

char test_if(int a, int b){ 
    if (a >= b)
        return ('a');
    else
        return ('b');
}

int factorial(int n){
    if (n == 0) 
        return (1);
    else
        return (factorial(n - 1));
}

int test_while{
    int n = 3;
    do{ 
        n = n - 1;
        printf(n);
    }while(n) 
    return (666);
}

void test_switch_char(char c){
    switch(c){
        case 'a':{ 
            printf("apple");
            printf("ali");
        }
        case 'b':{ 
            printf("boy");
        }
        case 'c':{
            printf("cat");
        }
        default : { 
            printf("dog");
        }
    }
}

void test_switch_int(int x){
    switch(x){
        case 1:{ 
            printf(111);
        }
        case 2:{
            printf(222);
        }
        default: {
            printf(333);
        }
    }
}


void test_relation(int n){
    if (n < 3)
        printf("<");
    else;

    if (n <= 4)
        printf("<=");
    else;

    if (n > 5)
        printf(">");
    else;

    if (n >= 6)
        printf(">=");
    else;

    if (n != 7)
        printf("!=");
    else;

    if (n == 8)
        printf("==");
    else;
}



void test_print{ 
    printf(" !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    printf("The result is ", 1);
    printf(2333333);
}


void main(){
    const int con_int_3 = 003, con_int_4 = +44, con_int_5 = -555; 
    
    int var_int_res;
    char var_char_res;
    int var_int_3, var_int_4;
    int op;

    scanf(op, var_int_1, var_int_2, var_int_3, var_int_4);
    scanf(var_char_1);

    if (op == 0){
        printf("test_if");
        var_char_res = test_if(var_int_1, var_int_2);
        printf(var_char_res);

        printf("factorial");
        var_int_res = factorial(var_int_3);
        printf(var_int_res);

        printf("test_while");
        var_int_res = test_while;
        printf(var_int_res);

        printf("test_print");
        test_print;

        printf("var_int_res");
        var_int_res = -var_int_1 - var_int_array_1[0] + +5 + 'a' + factorial(var_int_3) + -1 * ( 2 + 1);
        printf(var_int_res);

        printf("var_int_res[]");
        var_int_array_1[0] = var_int_res / 1 + 1;
        printf(var_int_array_1[0]);
    }
    else {
        printf("test_relation");
        test_relation(var_int_4);
        
        printf("test_switch_int");
        test_switch_int(var_int_1);

        printf("test_switch_char");
        test_switch_char(var_char_1);
    }
    return;
}

@
"sdfsf"fdsaflj"233
123
!abc
'abc'123
'@'2333
