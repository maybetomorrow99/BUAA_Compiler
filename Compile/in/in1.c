const int con_int_1 = 1, con_int_2 = 2; 
const char con_char_1 = 'a', con_char_2 = 'b';

INT var_int_1, var_int_2, var_int_array_1[101]; 
int var_int_array_2[101];
char var_char_1, var_char_array[101];

int test_if(int a, int b){ 
    if (a >= b)
        return (97);
    else
        return (98);
}


void main(){
    const int con_int_3 = 003, con_int_4 = +44, con_int_5 = -555; 
    int var_int_res;

    var_int_res = test_if(2, 2);
    printf(var_int_res);
    var_int_res = test_if(2, 1);
    printf(var_int_res);
    return;
}
