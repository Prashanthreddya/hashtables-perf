#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


struct cd
{
	char cn[10];
	char ci[10];
};


class hash
{
	private:
		#define table_size 10
		struct car
		{
			char id[10];
			char name[10];
			car*next;
		};
		car* hashtable[table_size];
	public:
		hash();
		void linetype(int flag[]);
		int Hash(char id[]);
		void add_car(char id[],char name[]);
		void findname(char id[]);
		void delete_id(char id[],int*,char[]);

};


void insta(hash ca,int index,char cid[],char cname[],int flag[])
{
	setlinestyle(0,1,1);

	int count=0;
	int i=0,j=0,k=0;

	for(i=0,j=0;i<290;i+=29,j+=3)
		rectangle(5,45+i+j,80,65+i+j);

	for(i=1;i<=20;i+=2)
	{
		window(3,i+3,80,25);
		cout<<"Index "<<count++;
	}

	for(i=0,j=0,k=0;i<290,k<10;i+=29,j+=3,k++)
	{
		if(flag[k]==1)
		{
			setlinestyle(1,1,1);
			line(80,55+i+j,120,55+i+j);
		}
		else
		{
			setlinestyle(0,1,1);
			line(80,55+i+j,120,55+i+j);
		}
	}

	setlinestyle(0,1,1);

	for(i=0,j=0,k=0;i<index;i++,j+=3,k+=29);
	rectangle(120,45+k+j,120+120,65+k+j);

	for(i=1;i<=(index*2);i+=2);
	window(17,i+3,80,25);

	cout<<cid<<"/"<<cname;
}

hash::hash()
{
	for(int i=0;i<table_size;i++)
	{
		hashtable[i]=new car;
		strcpy(hashtable[i]->id,"empty");
		strcpy(hashtable[i]->name,"empty");
		hashtable[i]->next=NULL;
	}
}



void hash::linetype(int flag[])
{
	for(int i=0;i<10;i++)
		if((hashtable[i]->next)!=NULL)
			flag[i]=1;
}




int hash::Hash(char id[])
{
	return (((int)id[0]+(int)id[1]+(int)id[2]+(int)id[3]+(int)id[4]+(int)id[5])%table_size);
}


void hash::add_car(char id[],char name[])
{
	int index = Hash(id);
	if(strcmp(hashtable[index]->id,"empty")==0)
	{
		strcpy(hashtable[index]->id,id);
		strcpy(hashtable[index]->name,name);
	}
	else
	{
		car* curt = hashtable[index];
		car*c = new car;
		strcpy(c->id,id);
		strcpy(c->name,name);
		c->next = NULL;
		while(curt->next != NULL)
		{
			if(strcmp(curt->id,id)==0)
			{
				cout<<"Duplication not allowed\n";
				return;
			}
			curt = curt->next;
		}
		if(strcmp(curt->id,id)==0)
		{
			cout<<"Duplication not allowed\n";
			return;
		}
		curt->next = c;
	}
}



void hash::findname(char id[])
{
	int index = Hash(id);
	int found = 0;
	car* curt = hashtable[index];
	char name[10];
	while(curt!=NULL)
	{
		if(strcmp(curt->id,id)==0)
		{
			found = 1;
			strcpy(name,curt->name);
		}
		curt=curt->next;
	}
	if(found==1)
		cout<<id<<" found | "<<"Owner name : "<<name<<endl;
	else
		cout<<id<<" not found"<<endl;
	return;
}





void hash::delete_id(char id[], int *x,char delname[])
{
	int index=Hash(id);
	car *curt_del;
	car *p1,*p2;
	if((strcmp(hashtable[index]->id,"empty")==0)&&(strcmp(hashtable[index]->name,"empty")==0))
	{
		*x=0;
		cout<<endl<<id<<" not found"<<endl;
	}
	else if((strcmp(hashtable[index]->id,id)==0)&&(hashtable[index]->next==NULL))
	{
		cout<<endl<<"\nCar id : "<<id<<endl<<"Owner name : "<<hashtable[index]->name<<endl;
		strcpy(delname,hashtable[index]->name);
		strcpy(hashtable[index]->id,"empty");
		strcpy(hashtable[index]->name,"empty");
	}
	else if(strcmp(hashtable[index]->id,id)==0)
	{
		curt_del=hashtable[index];
		cout<<endl<<"\nCar id : "<<id<<endl<<"Owner name : "<<curt_del->name<<endl;
		strcpy(delname,hashtable[index]->name);
		hashtable[index]=hashtable[index]->next;
		delete curt_del;
	}
	else
	{
		p1=hashtable[index]->next;
		p2=hashtable[index];
		while((p1!=NULL)&&(p1->id!=id))
		{
			p2=p1;
			p1=p1->next;
		}
		if(p1==NULL)
		{       *x=0;
			cout<<endl<<id<<" not found"<<endl;
		}
		else
		{
			curt_del=p1;
			p1=p1->next;
			p2->next=p1;
			cout<<endl<<"\nCar id : "<<id<<endl<<"Owner name : "<<curt_del->name<<endl;
			strcpy(delname,curt_del->name);
			delete curt_del;
		}
	}

}





void initgraph()
{

/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;

/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "");

/* read result of initialization */
	errorcode = graphresult();
	if (errorcode != grOk)  /* an error occurred */
	{
		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1); /* terminate with an error code */
	}
}
int main()
{
	initgraph();
	cleardevice();

	hash ca;
	int ch,x=1,count=0;

	cd dc[10];
	char delname[10];
	strcpy(delname,"empty");

	char cid[10];
	char cname[10];
	char car_del[10];

	int index;
	int flag[10]={0,0,0,0,0,0,0,0,0,0};
	for(;;)
	{
		window(1,1,80,25);
		cout<<"\n\n\n\n1:Insert | 2:Search | 3:Delete | 4:Exit\n";
		cin>>ch;

		switch(ch)
		{

			case 1:  gotoxy(0,0);
				 cout<<"\nCar id: ";
				 cin>>cid;
				 cout<<"Owner name: ";
				 cin>>cname;
				 ca.add_car(cid,cname);
				 ca.linetype(flag);

				 cleardevice();

				 strcpy(dc[count].ci,cid);
				 strcpy(dc[count++].cn,cname);

				 closegraph();
				 initgraph();
				 for(int t=0;t<count;t++)
				 {
					index=ca.Hash(dc[t].ci);
					if(dc[index].ci!=NULL)
						insta(ca,index,dc[t].ci,dc[t].cn,flag);
				 }
				 getch();
				 cleardevice();

				 break;

			case 2:  cout<<"\nCar id = ";
				 cin>>cid;
				 cout<<"\nSearch Results : ";
				 ca.findname(cid);
				 getch();
				 cleardevice();

				 break;

			case 3:  cout<<"\nCar id = ";
				 cin>>car_del;
				 cout<<"\nDelete Results : ";
				 ca.delete_id(car_del,&x,delname);
				 index=ca.Hash(car_del);
				 cleardevice();

				 if(x!=0)
				 {
					for(int i=0;i<10;i++)
					{
						if(strcmp(dc[i].ci,car_del)==0)
						{
							strcpy(dc[i].cn,"DELETED");
							break;
						}
					}
				 }

				 for(int w=0;w<count;w++)
				 {
					index=ca.Hash(dc[w].ci);
					if(dc[index].ci!=NULL)
						insta(ca,index,dc[w].ci,dc[w].cn,flag);
				 }
				 getch();
				 cleardevice();

				 break;

			case 4:  exit(0);
		}
	}
	return 0;

}

