#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX 100



int main(){
  // deklarasi awal
  FILE * fp1;
  FILE * fp2;
  char file1[MAX], file2[MAX];
 
  // input nama file
  printf ("===== Membandingkan 2 file =====\n\n");
  printf ("Masukkan file 1 lengkap dengan tipenya : ");
  scanf ("%s", file1);
  printf ("Masukkan file 2 lengkap dengan tipenya : ");
  scanf ("%s", file2);
 
  // buka nama file
  fp1 = fopen (file1, "r");         
  fp2 = fopen (file2, "r");

  // cek ketersediaan file
  if (fp1 == NULL || fp2 == NULL){
          printf("file tidak ada");
  }

  // deklarasi untuk array
  char line_arr[10][2][MAX];
  
  char text[MAX];
  int i= 0,n1=0,n2=0;
  while ((fgets(text,sizeof(text)/sizeof(text[0]),fp1)) != NULL){
    
   // memasukkan setiap baris ke array colom 0
    char *tx = strtok(text, "\n");
    strcpy(line_arr[i][0],tx);
    i++;n1++;
    
  }
  fclose(fp1);
  
  i=0;
  while ((fgets(text,sizeof(text)/sizeof(text[0]),fp2)) != NULL){

    // memasukkan setiap baris ke array colom 1
    char *tx = strtok(text, "\n");
    strcpy(line_arr[i][1],tx);
    i++;n2++;
  }
  fclose(fp2);


  // cek kesamaan, kemudian cetak yang sama..
  for (i=0;i<n2;i++){
    for (int j=0;j<n1;j++){
      if(strcmp(line_arr[i][0],line_arr[j][1])==0){
        printf("%s \n",line_arr[i][0]);
      }
    }
  }

}
