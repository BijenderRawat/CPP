#include <stdio.h>
void insert_end(int arr[],int n,int x){
 printf("Enter the element to be inserted");
 scanf("%d",&x);
 int position=n+1;
 for(int i=n-1;i>=position-1;i--)
 arr[i+1]=arr[i];
 arr[position-1]=x;

 printf("\n\n Array after inserting %d at the end is: ",x);

 for(int i=0;i<=n;i++){
 printf("%d ",arr[i]);
 }
}
void insert_pos(int arr[],int n,int x,int pos){
 printf("Enter the element to be inserted\n");
 scanf("%d",&x);
 printf("Enter the position to be inserted\n");
 scanf("%d",&pos);
 for(int i=n-1;i>=pos-1;i--)
 arr[i+1]=arr[i];
 arr[pos-1]=x;
 printf("\n\n The array after the insertion at %d pos ",pos);
 for(int i=0;i<=n;i++){
 printf("%d ",arr[i]);
 }
}
void delete_pos(int arr[],int n,int pos)
{
 printf("\n\n Enter the position from which element to be deleted")
;
 scanf("%d",&pos);
 if(pos>=n+1){
 printf("\nDeletion at this position not available");
 }
 else{
 for(int i=pos-1;i<n-1;i++){
 arr[i]=arr[i+1];
 }
 }
 printf("\n The array after deletion at position %d \n",pos);
 for(int i=0;i<n-1;i++){
 printf("%d ",arr[i]);
 }
}
void delete_element(int arr[],int n,int x){
 printf("\n\n Enter the element to be deleted:");
 scanf("%d",&x);
 int found=0;
 int position=0;
 for(int i=0;i<n;i++){
 if(arr[i]==x){
 found=1;
 position=i;
 break;
 }
 }
 if(found==1){
 for(int i=position;i<n-1;i++){
 arr[i]=arr[i+1];
 }
 }
 else{
 printf("\n Element %d is not found in the array",x);
 }
 printf("\n\nThe array after this operation is:");
 for(int i=0;i<n-1;i++){
 printf("%d ",arr[i]);
 }
}
void searching(int arr[],int n,int x){
 int i;
 printf("\nEnter the element to be searched");
 scanf("%d",&x);
 int found=0;
 for(i=0;i<n;i++){
 if(x==arr[i]){
 found=1;
 break;
 }
 }
 if(found==1){
 printf("\n\n Element is present in the array at position %d",i
+1);
 }
 else{
 printf("Element is not present in the array\n");
 }
}
void display(int arr[],int n){
 printf("\n\nThe resultant array is: ");
 for(int i=0;i<n;i++){
 printf("%d ",arr[i]);
 }
}
int main() {
 int choice,i,x,pos,n;
 int arr[100];
 char ch;
 printf("\n Enter how many elements in an array");
 scanf("%d",&n);
 printf("\n Enter the %d elements \n",n);
 for(i=0;i<n;i++){
 scanf("%d",&arr[i]);
 }
 do
 {
 printf("---MENU DRIVEN PROGRAMME---\n");
 printf("1. Insert the element at the end\n");
 printf("2. Insert the element at a given position\n");
 printf("3. Delete the element at given position\n");
 printf("4. Delete the given element\n");
 printf("5. Find the location of a given element\n");
 printf("6. Display the elements of linear array\n");
 printf("Enter your choice");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: insert_end(arr,n,x);
 break;
 case 2: insert_pos(arr,n,x,pos);
 break;
 case 3: delete_pos(arr,n,pos);
 break;
 case 4: delete_element(arr,n,x);
 break;
 case 5: searching(arr,n,x);
 break;
 case 6: display(arr,n);
 break;
 default: printf("Wrong choice. Enter again\n");
 break;
 }
 printf ("\nDo you want to continue: y/n");
 ch = getchar();
 getchar();
 } while(ch == 'y');
 }
