#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

struct car
{
	string id;
	string name;
};

void randomid(long size,car obj[])
{
    const char* const a_to_z = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    const char* const zero_to_nine = "0123456789";
    string strid[100000];
    string strname[100000];
    fill_n(strid, 100000,"EMP000" );
    fill_n(strname, 100000,"NONE" );
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<=2;j++)
            strid[i].at(j)=a_to_z[rand()%26];
        for(int k=3;k<=5;k++)
            strid[i].at(k)=zero_to_nine[rand()%10];
        obj[i].id=strid[i];
        for(int l=0;l<=3;l++)
            strname[i].at(l)=a_to_z[rand()%26];
        obj[i].name=strname[i];
        
        cout<<strid[i]<<"  ";
        
    }
}

void findname(string cid,long n,car obj[])
{
	clock_t start = clock();
	for(long i =0;i<n;i++)
	{
		if(obj[i].id == cid)
		{
			cout<<"Id found ";
			break;
		}
	}
	clock_t end = clock();
	cout<<endl<<(double)(end-start)*1000000/CLOCKS_PER_SEC<<endl;
}

int main()
{
	car obj[100000];

	int ch;

	string cid;

	for(;;)
	{
		cout<<"\n\nKindly Enter your choice\n1:Create array with random entries\n2:Search for a Car id\n3:Exit\n";
		cin>>ch;

		switch(ch)
		{

                        case 1:  long size;
                                 cout<<"Enter the number of random details u wanna enter : ";
                                 cin>>size;
                                 randomid(size,obj);   

			         break;

                        case 2:  long n;
                        	 cout<<"Reenter array size : ";
                                 cin>>n;
                        	 cout<<"\nPlease Enter the car id = ";
			         cin>>cid;
			         findname(cid,n,obj);
			         break;
			         
			case 3:  exit(0);
		}
	}

	return 0;

}



	

