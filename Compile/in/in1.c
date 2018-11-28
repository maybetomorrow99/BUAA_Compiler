const int con_int_1 = 1, con_int_2 = 2; 
const char con_char_1 = 'a', con_char_2 = 'b';

INT var_int_1, var_int_2, var_int_array_1[101]; 
int var_int_array_2[101];
char var_char_1, var_char_array[101];


void test_expression{ 
    int res;
    var_int_array_1[0] = con_int_2 / 1 + 1;
    res = -con_int_1 - var_int_array_1[0] + +005 + 'a'  + -1 * (2 + 1);
    printf("The result is ");  
}

void test_relation(int n){
    if (n < 3)
        n = 1;
    else
		var_int_array_2[0] = 2;
	
	var_int_1 = 3;
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
    
    c = 'a'; 
}

int test_factorial(int n){
    if (n == 0) 
        return (1);
    else
        return (test_factorial(n - 1));
}



void main(){
	int b;
	int n;
	n = 3;
	b = test_factorial(n);
	test_while;
	scanf(b);
	printf("test");
	printf("love");
	printf("test", b);
	printf(n);
	return;
}

