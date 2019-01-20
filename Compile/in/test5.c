const int a = 10;
const char  b = 'b';
const int c = 5;

int d;
int e;

void testLocal(int a){
	int b, c, d, e;
	b = 1;
	c = 2;
	d = 3;
	e = 4;
	printf(a + b + c + d + e);
}


void main(){
	d = 10;
	e = 5;
	
	testLocal(5);

	return;
}

