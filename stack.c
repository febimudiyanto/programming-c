#include<stdio.h>

#define MAX 5




// cek apakah stack kosong
int isEmpty(int top){
        if(top == -1){
                return 1;
        }
        else{
                return 0;
        }
}

// cek apakah stack penuh
int isFull(int top){
        if(top >= MAX){
                return 1;
        }
        else{
                return 0;
        }
}


// push atau menambahkan data ke tumpukan menggunakan address nya
// agar langsung terupdate ke tumpukan dan top
void push(int *Ptumpukan,int *Ptop){
        if(isFull(*Ptop)==0){
		int data;
                printf("masukkan data :");
                scanf("%d",&data);
                *Ptop=*Ptop+1;
                *(Ptumpukan+*Ptop)=data;
        }
        else{
                printf("tidak bisa push, tumpukan PENUH");
        }

}

// pop atau mengeluarkan data dari tumpukan
void pop(int *Ptumpukan,int *Ptop){
        if(isEmpty(*Ptop)==0){
		int data;
                data = *(Ptumpukan+*Ptop);
		*(Ptumpukan + *Ptop)=0;
                *Ptop=*Ptop-1;
                printf("data = %d",data);
        }else{
                printf("tumpukan kosong !!");
        }
}

// menampilkan data dari tumpukan
// urutan penampilan di balik sehingga dapat merepresentasikan 
// tumpukan seperti aslinya
void show(int *Ptumpukan,int *Ptop){
        if(isEmpty(*Ptop)==0){
                for (int i=*Ptop;i>=0;i--){
                        printf("tumpukan ke - %d = %d\n",i+1,*(Ptumpukan+i));
                }
        }else{
                printf("tumpukan kosong !!");
        }                                                                                                                                                                                                                                                                   
}                                                                                                                                                                                                                                                                           
                                                                                                                                                                                                                                                                            
void clear(int *Ptop){                                                                                                                                                                                                                                                               
        *Ptop = -1;                                                                                                                                                                                                                                                           
}               





int main(){
	int tumpukan[MAX];
	int top = -1 ,pil,i;
	while(1){
		printf("\n1. Push \n2.Pop\n3.Show\n4.Clear\n5.Exit\n\nMasukkan Pilihan:");
		scanf("%d",&pil);
		printf("\n-----------------------\n");
		switch(pil){
			case 1:
				push(&tumpukan[0],&top);
				break;
			case 2:
				pop(&tumpukan[0], &top);
				break;
			case 3:
				show(&tumpukan[0],&top);
				break;
			case 4:
				clear(&top);
				break;
			default:
				return 0;
			
		}

	}


}

