const int con_int_1 = 1, con_int_2 = 2; 
const char con_char_1 = 'a', con_char_2 = 'b';

INT var_int_1, var_int_2, var_int_array_1[101]; 
int var_int_array_2[101];
char var_char_1, var_char_array[101];


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


void main(){
    const int con_int_3 = 003, con_int_4 = +44, con_int_5 = -555; 
    int var_int_res;
    char var_char_res;
    int var_int_3, var_int_4;
    int op;
    
    var_int_1 = 04;

    printf("test_while");
    var_int_res = test_while;
    printf(var_int_res);            

    printf("test_switch_char");
    test_switch_char(con_char_1);
    test_switch_char(con_char_2);
    test_switch_char('c');            

    return;
}
