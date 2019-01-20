void test_switch_char(char c){
    switch(c){
        case 'a':{ 
            printf("apple");
            printf("ali");
        }
        case 'a':{ 
            printf("boy");
        }
        
        default : { 
            printf("cat");
        }
    }
}

void test_switch_int(int c){
    switch(c){
        case 'a':{ 
            printf("apple");
            printf("ali");
        }
        case 3:{ 
            printf("boy");
        }
        
    }
}

void main(){
	
	test_switch_char('a');
	test_switch_int(3);
}
