#include <stdio.h>
int main(){
int r,c;
printf("enter the row and cokumn");
scanf("%d%d",&r,&c);
int a[r][c],b[r][c];
printf("Enter mat a\n");
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
scanf("%d",&a[i][j]);
}
}
printf("Matrix\n");
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("Matrix B");
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
scanf("%d",&b[i][j]);
}
}
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
printf("%d\t",b[i][j]);
}
printf("\n");
}
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
a[i][j]+=b[i][j];
printf("%d\t",a[i][j]);
}
printf("\n");
}
int sparse[100][3],count=0;
sparse[0][0]=r;
sparse[0][1]=c;
for(int i=0;i<r;i++){
for(int j=0;j<c;j++){
if(a[i][j]!=0){
count++;
sparse[count][0]=i;
sparse[count][1]=j;
sparse[count][2]=a[i][j];
}
}
}
sparse[0][2]=count;
printf("Row\tColumn\tvalue\n");
for(int i=0;i<=count;i++){
for(int j=0;j<3;j++){
printf("%d\t",sparse[i][j]);
}
printf("\n");
}
return 0;
}