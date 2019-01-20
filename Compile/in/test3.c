const int con_int_1 = 1, con_int_2 = 2; 
const char con_char_1 = 'a', con_char_2 = 'b';

INT var_int_1, var_int_2, var_int_array_1[101]; 
int var_int_array_2[101];
char var_char_1, var_char_array[101];


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
    var_int_2 = con_char_1 + 1;
    printf(var_int_2);
}


void main(){
    const int con_int_3 = 003, con_int_4 = +44, con_int_5 = -555; 
    int var_int_res;
    char var_char_res;
    int var_int_3, var_int_4;
    int op;
    
    var_int_1 = 04;


    printf("test_relation");
    scanf(var_int_1);
    test_relation(con_int_1);
    scanf(var_int_1);
    test_relation(8); 
    
    printf("test_expression");
    test_expression;
       
    return;
}
