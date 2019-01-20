
void func1{
	printf("func1");
	return (1);	
}

void func2{
	printf("func2");
	return;	
}

void func3(int a, int b, char c){
	printf(a + b + c);
}
void main(){
	int a;
	func1;
	
	a = func2;
	
	func3(1, 2, 3);
	func3(1, 2);
}
