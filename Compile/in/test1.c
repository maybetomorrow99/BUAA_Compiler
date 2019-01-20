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


void main(){
    const int con_int_3 = 003, con_int_4 = +44, con_int_5 = -555; 
    int var_int_res;
    char var_char_res;
    int var_int_3, var_int_4;
    int op;
    
    var_int_1 = 04;

    printf("test_if\n");
    var_char_res = test_if(con_int_5, con_int_3);
    printf(var_char_res);
    var_char_res = test_if(con_int_4, con_int_3);
    printf(var_char_res);

    printf("test_factorial");
    var_int_res = test_factorial(var_int_1);
    printf(var_int_res);   
	         
    return;
}
