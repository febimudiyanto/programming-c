#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
}*head,*ptr;

// prototipe
void insert(int n, int d);
void append(int d);
void show();
void delete_end();


int main(){
	head=NULL;
	append(13);
	append(14);
	append(12);
	// 13 --> 14 --> 12 -->
	insert(2,30);
	// 13 --> 30 --> 14 --> 12 -->
	delete_end();
	// 13 --> 30 --> 14	
	show();

}





void delete_end(){
	struct node *p,*temp;
	p = head;

	// cari 2 terakhir
	while (p->link->link != NULL){
		p=p->link;
	}
	// simpan node terakhir ke temp
	temp = p->link;
	// ganti link milik node 2 terakhir dengan NULL
	p->link = NULL;
	// hapus temp dan listnya
	free(temp);

}
void show(){
	struct node*p;
	p=head;
	// print data, sambil travel ke bagian akhir
	while(p!=NULL){
		printf("%d --> ",p->data);
		p=p->link;
	}
}


void append(int d){
	// cek apakah head kosong
	if (head == NULL){
		// masukkan sebagai elemet pertama
		ptr = malloc(sizeof(struct node));
		ptr->data = d;
		ptr->link = NULL;
		head = ptr;
	}else{
		// simpan data ke  p
		struct node *p=malloc(sizeof(struct node));
		p->data = d;
		p->link = NULL;
		
		// travel ke bagian akhir dari linked list
		ptr=head;
		while (ptr->link != NULL){
			ptr = ptr->link;
		}
		// sambungkan p ke ujung link list
		ptr->link = p;
	}
}

void insert(int n,int d){
	// karena insert akan memasukkan di tengah list, maka kita akan melakukan pemotongan
	// deklarasikan kanan untuk menyimpan bagian sebelah kanan
	// p untuk menyimpan bagian sebelah kiri
	struct node *kanan,*p;
	int count=0;
	
	p=head;
	// indeks dimulai dari 1 (element ke 1) 
	// jika indeks tidak di dapatkan maka akan di tempatkan di akhir atau saat p = NULL
	while (p != NULL && count < n-2){
		p=p->link;
		count++;
	}
	
	// bagian sebelah kanan disimpan
	kanan = p->link;
	// bagian sebelah kiri diputus dengan cara link = NULL
	p->link = NULL;
	// data di simpan ke temp
	struct node* temp = malloc(sizeof(struct node));
	temp->data = d;
	temp->link = kanan; // temp di sambungkan dengan sebelah kanan
	p->link = temp; // sebelah kiri yang tadi NULL di sambungkan ke temp

}

