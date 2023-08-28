#include <iostream>
#include <string.h>
using namespace std;
struct SinhVien{
	char ms[5], ht[50],qq[20];
	int gt,ns;
	float dtb,hk1,hk2;
}sv[100];
main(){
	int n,d1,d2,dc,dt,demnu=0;
	float hk1,hk2,dtb;
	do{
		cout<<"Nhap vao so luong hoc sinh ";
		cin>>n;
	}while(n<0||n>100);
	for(int i=0;i<n;i++){
		cout<<"Nhap sinh vien thu "<<i+1<<" "<<endl;
		cin.ignore(1);
		do{
			cout<<"Nhap ma so ";
			cin.getline(sv[i].ms,5);
			d1=0;
			for(int j=0;j<1;j++)
				if(isalpha(sv[i].ms[j]))
				d1++;
			d2=0;
			for(int j=1;j<2;j++)
				if(isdigit(sv[i].ms[j]))
				d2++;
		}while(strlen(sv[i].ms)!=2||d1!=1||d2!=1);
		do{
			cout<<"Nhap ho ten ";
			cin.getline(sv[i].ht,50);
			dc=0;
			dt=0;
			for(int j=0;j<strlen(sv[i].ht);j++){
				if(isalpha(sv[i].ht[j])) dc++;
				else if (isspace(sv[i].ht[j]))dt++;
		}
			
		}while(dc+dt!=strlen(sv[i].ht)||dc==0);
		cout<<"Nhap que quan ";
		cin.getline(sv[i].qq,20);
		do{
		
		cout<<"Nhap gioi tinh (Nam:1, Nu:0):";
		cin>>sv[i].gt;
		}while(sv[i].gt!=0&&sv[i].gt!=1);
		do
		{cout<<"Nhap nam sinh:";
		cin>>sv[i].ns;
		}while (sv[i].ns<=0 || sv[i].ns>2023);
		do{
			cout<<"Nhap vao diem hk1 ";
			cin>>sv[i].hk1;
		}while(sv[i].hk1<0||sv[i].hk1>10);
		do{
			cout<<"Nhap vao diem hk2 ";
			cin>>sv[i].hk2;
		}while(sv[i].hk2<0||sv[i].hk2>10);
		
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Thong tin hoc sinh thu "<<i+1<<" la "<<endl;
		cout<<"Ma so: "<<sv[i].ms<<endl;
		cout<<"Ho ten: "<<sv[i].ht<<endl;
		cout<<"Nam sinh: "<<sv[i].ns<<endl;
		cout<<"Gioi tinh la: ";
		if(sv[i].gt==0) cout<<"Nu"<<endl;
		else cout<<"Nam "<<endl;
		cout<<"Diem ca nam: "<<(sv[i].hk1+sv[i].hk2)/2<<endl;
		
	}
	for(int i=0;i<n;i++)
	{
		if(sv[i].gt==0)
			demnu++;
	}
	cout<<"Co "<<demnu<<" hoc sinh nu"<<endl;
	int maxns, minns;
	for(int i=0;i<n;i++){
		maxns = sv[i].ns;
		minns = sv[i].ns;
			for( i=1; i<n; i++)
			{
				if( maxns < sv[i].ns )
				{
					maxns = sv[i].ns;
				}
				if( minns > sv[i].ns )
				{
					minns = sv[i].ns;
				}
	}
	cout<<"Tuoi lon nhat trong lop la: "<<2023-minns<<endl;
	cout<<"Tuoi nho nhat trong lop la: "<<2023-maxns<<endl;
	cout<<endl;
	
	}
	float maxdiemcanam = (sv[0].hk1+sv[0].hk2)/2;
	for( int i=1; i<n; i++)
	{
		if(maxdiemcanam < (sv[i].hk1 + sv[i].hk2)/2)
		{
			maxdiemcanam = (sv[i].hk1 + sv[i].hk2)/2;
		}
	}
	cout<<"Danh sach hoc sinh co diem ca nam cao nhat lop la: ";
	for( int i=1; i<n; i++)
	{
		if((sv[i].hk1 + sv[i].hk2)/2 == maxdiemcanam)
		{
			cout<<sv[i].ht<<endl;
		}
	}
	cout<<endl;
	SinhVien tam;
	for(int i=0; i<n-1 ; i++)
	{
		for( int j=0; j<n; j++)
		{
			if((((sv[i].hk1 + sv[i].hk2)/2) < (sv[j].hk1 + sv[j].hk2)/2) ||
			  (((sv[i].hk1 + sv[i].hk2)/2) == (sv[j].hk1 + sv[j].hk2)/2) &&
			  (sv[i].hk2 < sv[j].hk2))
			{
				tam = sv[i];
				sv[i] = sv[j];
				sv[j] = tam;
			}
		}
	}
	
	//IN RA DANH SACH SAU KHISAP XEP
	cout<<"Danh sach hoc sinh sau khi duoc sap giam dan la: "<<endl;
	for (int i=0; i<n; i++)
	{
		cout<<"Thong tin cua thu sinh thu "<<i+1<<" la: "<<endl;
		cout<<"Ho va Ten: "<<sv[i].ht<<endl;
		cout<<"Nam sinh: "<<sv[i].ns<<endl;
		cout<<"Diem ca nam: "<<(sv[i].hk1 + sv[i].hk2)/2 <<endl; 
		cout<<endl;
	}
}
