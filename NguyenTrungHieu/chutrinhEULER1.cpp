#include<conio.h>
#include<stdio.h>

#define MAX 100


typedef struct GRAPH
{	int n;
	int a[MAX][MAX];
}DOTHI;
typedef struct STACK 
{
	int size;
	int b[MAX];
}Stack;
void KhoiTaoStack(Stack&stack)
{
	stack.size=0;
}

//==============================================================
int DocMaTranKe(const char* TenFile,DOTHI &g)
{	FILE* f;
	f = fopen(TenFile,"rt");
	if(f==NULL)
	{
		printf("Khong mo duoc file\n");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i=0;i<g.n;i++)
		for(int j=0;j<g.n;j++)
			fscanf(f,"%d",&g.a[i][j]);
	fclose(f);
	return 1;
}
//==============================================================
void XuatMaTranKe(DOTHI g)
{	printf("So dinh cua do thi = %d\n",g.n);
	printf("Ma tran ke cua do thi la:\n");
	for(int i=0;i<g.n;i++)
	{	for(int j=0;j<g.n;j++)
			printf("%4d",g.a[i][j]);
		printf("\n");
	}
}
//========================================================
void DayGiaTriVaoStack(Stack&stack, int value)
{
	if(stack.size+1>=100)
		return;
	stack.b[stack.size]=value;
	stack.size++;
}
//==================================================
void TimDuongDi(int i, DOTHI &g, Stack &stack) {
	for(int j = 0 ; j < g.n ; j ++) {
		if(g.a[i][j] != 0) {
			g.a[i][j] = g.a[j][i] = 0;
			TimDuongDi(j,g,stack);
		}
	}
	DayGiaTriVaoStack(stack,i);
}
//=======================================================

//==============================================================
int main()
{
	char inputfile[100];
	char ch;
	DOTHI g;
	int u,v;
	do
	{
		fflush(stdin);
		printf("\nNhap ten file do thi: ");
		gets(inputfile);
		if(DocMaTranKe(inputfile, g)==1) //doc file duoc
		{
			printf("Da lay thong tin do thi tu file thanh cong.\n\n");
			XuatMaTranKe(g);
		}
		printf("\n============================\n");
		printf("\nTiep tuc hay khong[Y/N]: ");
		
		ch=getch();
	}while(ch=='Y'||ch=='y');
	
	return 0;
}
