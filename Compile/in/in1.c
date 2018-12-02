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
        return (n* test_factorial(n - 1));
}



int test_while{
    int var_int_1;
    var_int_1 = 3;
    do{ 
        var_int_1 = var_int_1 - 1;
        printf(var_int_1);
    }while(var_int_1) 
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


int test_para(int a, int b, int c, int con_int_1, int con_int_2){
    return (a + b + c + con_int_1 + con_int_2);
}

void test_expression{ 
    var_int_array_1[1] = con_int_2 / 1 + 1 + test_para(1, 2, 3, 4, 5);
    printf("The result is ", -con_int_1 - var_int_array_1[1] + +005 + 'a' + test_factorial(3) + -1 * (2 + 1));
}


void main(){
    const int con_int_3 = 003, con_int_4 = +44, con_int_5 = -555; 
    int var_int_res;
    char var_char_res;
    int var_int_3, var_int_4;
    int op;
    
    var_int_1 = 04;

    scanf(op);
    switch(op){
        case 1:{
            printf("test_if");
            var_char_res = test_if(con_int_5, con_int_3);
            printf(var_char_res);
            var_char_res = test_if(con_int_4, con_int_3);
            printf(var_char_res);

            printf("test_factorial");
            var_int_res = test_factorial(var_int_1);
            printf(var_int_res);            
        }
        case 2:{
            printf("test_while");
            var_int_res = test_while;
            printf(var_int_res);            

            printf("test_switch_char");
            test_switch_char(con_char_1);
            test_switch_char(con_char_2);
            test_switch_char('c');            
        }
        case 3:{
            printf("test_relation");
            scanf(var_int_1);
            test_relation(con_int_1);
            scanf(var_int_1);
            test_relation(8); 
            
            printf("test_expression");
            test_expression;
        }
        default:{
            printf("Please input 1~6");
        }
    }
    return;
}
