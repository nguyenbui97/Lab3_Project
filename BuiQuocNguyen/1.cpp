include<stdio.h>
#define MAX 20
#define LinkFile "link file "
#define LinkFile1 "link file"
//===========================================================================
// tao STACK
typedef struct STACK {
	int size;
	int b[MAX];
}Stack;

//===========================================================================
//khi bao do thi
typedef struct DoThi {
	int n;
	int a[MAX][MAX];
}DoThi;

//===========================================================================
//khoi tao STACK
void iNit(Stack &s) {
	s.size = 0;
}

//===========================================================================
//doc file
int DocFile(char TenFile[100], DoThi &g) {
	FILE * f = fopen(TenFile,"rt");
	if(f == NULL) {
		printf("khong mo duoc file !");
		return 0;
	}
	fscanf(f,"%d",&g.n);
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			fscanf(f,"%d",&g.a[i][j]);
		}
	}
	fclose(f);
	return 1;
}

//===========================================================================
// day gia tri vao stack
void DayGiaTriVaoStack(Stack &s, int Value) {
	if(s.size + 1 >= MAX) {
		return;
	}	
	s.b[s.size] = Value;
	s.size++;
}


void XuatMaTran(DoThi g) {
	printf("%3d\n",g.n);
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			printf("%3d",g.a[i][j]);
		}
		printf("\n");
	}
}

int main() {
 	DoThi g;
	if(DocFile(LinkFile1,g) == 1) {
		printf("da mo file thanh cong!\n");
		XuatMaTran(g);
	+}
}
