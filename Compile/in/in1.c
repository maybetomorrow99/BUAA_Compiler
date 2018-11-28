const int con_int_1 = 1, con_int_2 = 2; 
const char con_char_1 = 'a', con_char_2 = 'b';

INT var_int_1, var_int_2, var_int_array_1[101]; 
int var_int_array_2[101];
char var_char_1, var_char_array[101];


char test_if(int a, int b){ 
    if (a >= b)
        return ('a');
    else
        return ('b');
}

int test_factorial(int n){
    if (n == 0) 
        return (1);
    else
        return (factorial(n - 1));
}


int test_while{
    int n;
    n = 3;
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
        default : { 
            printf("cat");
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


void test_expression{ 
    int res;
    var_int_array_1[0] = con_int_2 / 1 + 1;
    res = -con_int_1 - var_int_array_1[0] + +005 + 'a' + test_factorial(3) + -1 * (2 + 1);
    printf("The result is ", res);
    printf(" !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
}


void main(){
	return;
}

