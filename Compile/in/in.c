int glb;
int a[100];

void test{
	glb = 2;
	a[2] = 1;
	printf(a[glb]);
    a[glb] = 3;
    printf(a[2]);

}

void main() 
{
    
    test;
    
}
