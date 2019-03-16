
// Chi ap dung voi Do thi Hop le, vo huong, trong so

#include<stdio.h>
#include<conio.h>

#define MAX 20	//max so dinh cua do thi
#define MAXSTACK 100	//max SATCK

typedef struct GRAPH
{ 	int n;
	int a[MAX][MAX];
}DOTHI;

struct STACK
{	int array[MAXSTACK];
	int size;
};
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
//==============================================================
int KiemTraMaTranKeHopLe(DOTHI g)
{
	for(int i=0;i<g.n;i++)
		if(g.a[i][i] != 0)
			return 0;
	return 1;
}
//==============================================================
void DiTimCacDinhLienThong(DOTHI g, int Nhan[], int i)
{
	for(int j=0;j<g.n;j++)
	{
		if(g.a[i][j] !=0 && Nhan[j] != Nhan[i])
		{
			Nhan[j] = Nhan[i];
			DiTimCacDinhLienThong(g, Nhan, j);
		}
	}
}
//==============================================================
int XetLienThong(DOTHI g)
{
	int Nhan[MAX];
	
	for(int i=0;i<g.n;i++)
		Nhan[i] = 0;
	
	int SoThanhPhanLT = 0;
	
	for(int i=0;i<g.n;i++)
	{
		if(Nhan[i] ==0)
		{
			SoThanhPhanLT++;
			Nhan[i] = SoThanhPhanLT;
			DiTimCacDinhLienThong(g, Nhan, i);
		}
	}
	if(SoThanhPhanLT == 1) // Do thi lien thong
		return 1;
	return 0;
}
//==============================================================
void KhoiTaoStack(STACK &stack) // InitStack
{	stack.size =0;
}
//==============================================================
void DayGiaTriVaoStack(STACK &stack, int value) //Push
{	if(stack.size+1 >= MAXSTACK) return; // IsFull
	stack.array[stack.size] = value;
	stack.size++;
}
//==============================================================
void TimDuongDi(int i, DOTHI &g, STACK &stack)
{
	for(int j=0;j<g.n;j++)
	{	if(g.a[i][j] !=0)
		{	g.a[i][j]=g.a[j][i] =0; // xoa canh
			TimDuongDi(j, g, stack);
		}
	}
	DayGiaTriVaoStack(stack,i); //Push
}
//==============================================================
int KiemTraChuTrinhEuler(int x,DOTHI g)
{
	
	DOTHI temp = g;//thong qua do thi trung gian
	
	STACK stack;
	KhoiTaoStack(stack);
	TimDuongDi(x,temp,stack);
	
	// CODE: con canh ke == Do thi khong lien thong
	for(int i=0;i<g.n;i++)
		for(int j=0;j<g.n;j++)
			if(temp.a[i][j] !=0)
				return 0;
				
	for(int i=stack.size-1; i>0; i--)
		if(g.a[stack.array[i]][stack.array[i-1]] ==0) // Khong ke nhau
			return 0;
 	// CODE
	if(stack.array[stack.size-1] != stack.array[0])
		return 0;

	printf("\n Chu Trinh Euler :\n"); 
	// CODE 
	for(int i=stack.size-1; i>=0; i--)
		printf(" %d->", stack.array[i]);

	return 1;
}
//==============================================================
int KiemTraDuongDiEuler (int x,DOTHI g) 
{ 
	
	DOTHI temp = g;//thong qua do thi trung gian
	STACK stack;
	KhoiTaoStack(stack); // ban dau stack chua có gi nên phai khoi tao stack. 
	
	TimDuongDi(x,temp, stack);  
  
	for(int i=0;i<g.n;i++)
		for(int j=0;j<g.n;j++)
			if(temp.a[i][j] !=0)
				return 0;
 	//CODE
 	for(int i=stack.size-1; i>0; i--)
		if(g.a[stack.array[i]][stack.array[i-1]] ==0) // Khong ke nhau
			return 0;
 	//CODE
	if(stack.array[stack.size-1] == stack.array[0])
		return 0; 
		
	printf("\nDuong di Euler :\n"); 
	//CODE
	for(int i=stack.size-1; i>=0; i--)
		printf(" %d->", stack.array[i]);
	printf(" %d.", stack.array[0]);
	return 1; 
} 
//==============================================================
int main()
{
	DOTHI g;
		
	char inputfile[100];
	char ch;
	do
	{
		printf("\n\nNhap ten file do thi: ");
		gets(inputfile);
		if(DocMaTranKe(inputfile, g)==1) 
		{
			printf("Da lay thong tin do thi tu file thanh cong.\n\n");
			XuatMaTranKe(g);
		
			if( ! KiemTraChuTrinhEuler( 0,g ))
			{
				printf("Khong co chu trinh Euler \n");
		 		if( ! KiemTraDuongDiEuler(0, g ))
					printf("Khong co duong di Euler \n ");
			}
		}
		printf("\n\n-----------------------\n");
		printf("Ban tiep tuc nua khong[Y/N]: ");
		ch=getche();
	}while(ch=='Y'||ch=='y');
	return 0;
}

