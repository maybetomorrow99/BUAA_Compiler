CONST int max_value_limit = 100, min_value_limit = -100;
const char upper_c = 'C';
const int const_void_index
=
5
;
const char lower_c = 'c';


int error_number;
int void_index;
int i;
int t1,t2
,
t3
;
char Label, Label1, Label2;


void error(int err_typ){
    switch(err_typ){ 
        case 1:{
            printf("Max value limit.");
        }
        case 2:{
            printf("Min value limit.");
        }
        default:{
            switch(err_typ){
                case 3:
                    printf("Invalid Input.");
                default:
                    printf("Error Type Not Define.");
            }
        }
    }
    error_number = error_number + 1;
    return;
}




char output(char input){
    do{
        printf("Letter is ", input);
        return (input);
    }while(1);
}



void test{
    int int_test;
    char char_test;
    int _abcdefghijklmnopqrstuvwxyz0123456789;
    char letters[003];
    int i; 

    char_test = 'A';
    letters[0] = '1'; 
    letters[1] = '2';
    letters[2] = 'a';
    
    i = 10;
    do{
        switch(2 * i / 2 + '0' - 0){
            case 0:
            char_test = 'A';
            case 48:
            char_test = '0';
            default:
            char_test = 'G';
        }
        printf(2 * i / 2 + '0' - 0);
        
        i = i - 1;
    }while(i >= 0)

    output(char_test);

    ;
    {{}{}{;}}
    {}
    {;{;};}

    error(4);
}

void main() 
{
    
    test;
    
}
