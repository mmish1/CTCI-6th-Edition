/*Q1.7) Rotate Matrix: Given an image represented by an NxN matrix, where each 
		pixel in the image is 4 bytes, write a method to rotate the image by 
		90 degrees. Can you do this in place? */


#include<iostream>

using namespace std;

void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

/*In place solution*/
void rotateMatrix(int **arr,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			swap(arr[i][j],arr[j][i]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++){
			swap(arr[i][j],arr[i][n-1-j]);
		}
	}
}

void display(int **arr,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

void createMatrix(int **x, int n, int a){
	for(int i=0;i<n;i++){
		x[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			x[i][j]=a++;
		}
	}
}

main(){
	int a=1,n=4;
	int **x=new int*[n];
	createMatrix(x,n,a);
	cout<<"Original matrix: "<<endl;
	display(x,n);
	rotateMatrix(x,n);
	cout<<"Rotated matrix: "<<endl;
	display(x,n);
	
	a=1;
	n=5;

	createMatrix(x,n,a);
	cout<<"Original matrix: "<<endl;
	display(x,n);
	rotateMatrix(x,n);
	cout<<"Rotated matrix: "<<endl;
	display(x,n);
	
	return 0;
}
