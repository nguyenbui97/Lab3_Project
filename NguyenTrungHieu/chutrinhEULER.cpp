#include<stdio.h>
#define MAX 20
#define LinkFile "D:\TAM2.txt"
//#define LinkFile1 "link file"
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
//===========================================================================
//tim duong di
void TimDuongDi(int i, DoThi &g, Stack &s) {
	for(int j = 0 ; j < g.n ; j ++) {
		if(g.a[i][j] != 0) {
			g.a[i][j] = g.a[j][i] = 0;
			TimDuongDi(j,g,s);                                         
		}
	}
	DayGiaTriVaoStack(s,i);
}

//===========================================================================
//Diem bat dau
int DiemBatDau(DoThi g) {
	int Rank;
	for(int i = 0 ; i < g.n ; i++) {
		Rank = 0;
		for(int j = 0 ; j < g.n ; j++) {
			if(g.a[i][j] != 0) {
				Rank++;
			}
		}
		if(Rank%2 != 0) {
			return -1;
		}
	}
	for(int i = 0 ; i < g.n ; i++) {
		for(int j = 0 ; j < g.n ; j++) {
			if(g.a[i][j] != 0) {
				return i;
			}
		}
	}
return -1;	
}
//===========================================================================
//kiem tra chu trinh
int KiemTraChuTrinEuler(DoThi g) {
	DoThi Temp = g;
	Stack s;
	iNit(s);
	int x = DiemBatDau(Temp);
	if(x == -1)
		return 0;
	TimDuongDi(0, Temp, s);
	
	for(int i = 0 ; i < Temp.n ; i++) {
		for(int j = 0 ; j < Temp.n ; j++) {
			if(Temp.a[i][j] != 0) {
				return 0;
			}
		}
	}
	
	if(s.b[0] != s.b[s.size-1]) {
		return 0;
	}
	
	printf("Euler:\n");
	printf(" %2c ",s.b[s.size - 1] + 'A');	
	for(int i = s.size - 2 ; i >= 0 ; i--) {
		printf("->%2c ",s.b[i] + 'A');
	}
return 1;
}

//===========================================================================
//===========================================================================
//===========================================================================


int main() {
 	DoThi g;
	if(DocFile(LinkFile,g) == 1) {
		printf("da mo file thanh cong!\n");
		XuatMaTran(g);
		if(KiemTraChuTrinEuler(g) != 1) {
			printf("khong co chu trinh trong do thi cua ban!\n");
		}
	}	
	return 0;
}















//===========================================
// main
		//	if(KiemTraDuongDiEuler(g)!=1) {
		//		printf("khong co duong di Euler");
		//	}

//===========================================================================
//===========================================================================
//===========================================================================

/*

// tim dinh le de bat dau tim chu trinh euler
int TimDinhLe(DoThi g) {
	int Rank, Count = 0;
	for(int i = 0 ; i < g.n ; i++) {
		Rank = 0;
		for(int j = 0 ; j < g.n ;j++) {
			if(g.a[i][j] != 0) {
				Rank++;
			}	
		}
		if(Rank%2 != 0) {
			Count++;
		}
		if(Count == 2) {
			return i; 
		} 
	}
return -1;
}
// kiem tra duong di Eulerway
int KiemTraDuongDiEuler(DoThi g) {
	DoThi Temp = g;
	Stack s;
	iNit(s);
	int x = TimDinhLe(Temp);
	if(x == -1) 
		return 0;
	TimDuongDi(0,Temp,s);
	
	for(int i = 0 ; i < Temp.n ; i++) {
		for(int j = 0 ; j < Temp.n ; j++) {
			if(Temp.a[i][j] != 0) {
				return 0;
			}
		}
	}
	
	if(s.b[0] == s.b[s.size-1]) {
		return 0;
	}
	printf("Duong di Euler:\n");
	printf("%3c ",s.b[s.size - 1]+'A');
	for(int i = s.size - 2 ; i >= 0 ; i--) {
		printf(" ->%3c",s.b[i]+'A');
	}
return 1;
}
*/
