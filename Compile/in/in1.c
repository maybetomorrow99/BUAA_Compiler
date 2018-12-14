int add(int a, int b, int c, int d, int e){
	return (a + b + c + d + e);
}

int rc1{
	return (('a'));
} 

char rc2{
	return ('a'); 
}

int rc3{
	return ('a'+'b');	
}

void main(){
    printf(add(--1, 2, 3, add(1, 2, 3, 4, ++5), add(1, 2, 3, 4, 5)));
    printf(rc1);
    printf(rc2);
    printf(rc3);
	return; 
}


