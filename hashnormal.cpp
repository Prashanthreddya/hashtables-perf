#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>


using namespace std;


class hash
{
	private:
		static const int table_size=10;
		struct car
		{
			string id;
			string name;
			car*next;
		};
		car* hashtable[table_size];
	public:
		hash();
		int Hash(char a,char b);
		int varianttype(string id,int variant);
		void add_car(string id,string name,int variant);
		void findname(string id,int variant);
		void delete_id(string id,int variant);
		float efficiency();
		int NumberOfElementsInIndex(int index);
};


hash::hash()
{
	for(int i=0;i<table_size;i++)
	{
		hashtable[i]=new car;
		hashtable[i]->id="empty";
		hashtable[i]->name="empty";
		hashtable[i]->next=NULL;
	}
}


int hash::Hash(char a,char b)
{
	int c,d;
	c =(int)a;
	d =(int)b;
	return ((c+d)% table_size);
}


int hash :: varianttype(string id,int variant)
{
	if(variant==1)
	{
		return Hash(id[1],id[2]);
	}
	else if(variant==2)
	{
		return Hash(id[4],id[5]);
	}
	else
	{
		return Hash(id[2],id[5]);
	}
}


int hash::NumberOfElementsInIndex(int index)
{
	int count_ind = 0;
	if(hashtable[index]->id=="empty")
		return count_ind;
	else
	{
		count_ind++;
		car*curt=hashtable[index];
		while(curt->next!=NULL)
		{
			count_ind++;
			curt = curt->next;
		}
	}
	return count_ind;
}


void hash::add_car(string id,string name,int variant)
{
	int index = varianttype(id,variant);
	if(hashtable[index]->id == "empty")
	{
		hashtable[index]->id=id;
		hashtable[index]->name=name;
	}
	else
	{
		car* curt = hashtable[index];
		car*c = new car;
		c->id = id;
		c->name = name;
		c->next = NULL;
		while(curt->next != NULL)
		{
			if(curt->id==id)
			{
				cout<<"Car id "<<curt->id<<" already exists in the directory and its owner is "<<curt->name;
				return;
			}
			curt = curt->next;
		}
		if(curt->id==id)
		{
			cout<<"\nThe car id "<<curt->id<<" already exists in the directory and its owner is "<<curt->name;
			return;
		}
		curt->next = c;
	}
}


float hash::efficiency()
{
	int cluster[table_size],i,zerocount=0;
	float max,temp,indeff[table_size],neteff=0,efficiency;

	for(i=0;i<table_size;i++)
	{
		cluster[i]=NumberOfElementsInIndex(i);
	}
	max = cluster[0];
	for(i=1;i<table_size;i++)
	{
		if(cluster[i]>max)
			max=cluster[i];
	}
	for(i=0;i<table_size;i++)
	{
		temp=1-((cluster[i]-1)/max);
		indeff[i] = temp*100;
	}
	for(i=0;i<table_size;i++)
	{
		if(indeff[i]>100)
			zerocount++;
		else
			neteff=neteff+indeff[i];
	}
	if(zerocount==table_size)
		efficiency = -1;
	else
		efficiency = (neteff/(table_size-zerocount));
	return efficiency;

}


void hash::findname(string id,int variant)
{
    clock_t srt = clock();
	int index = varianttype(id,variant);;
	bool found = false;
	car* curt = hashtable[index];
	string name;
	while(curt!=NULL)
	{
		if(curt->id==id)
		{
			found = true;
			name = curt->name;
		}
		curt=curt->next;
	}
	if(found==true)
		cout<<"Search Successful ! \n"<< "Car id : "<<id<<" $FOUND"<<"\nOwner name : "<<name<<endl;
	else
        {
		cout<<"Search Unsuccessful ! "<<endl;
                return;
        }        
        clock_t stp = clock();
      	double time = (double)(stp-srt)*1000000/CLOCKS_PER_SEC;
        
        cout <<"Search time wrt hashtable "<<variant<<" : "<<time<<" microseconds"<< endl;
    
}


void hash::delete_id(string id,int variant)
{
	int index=varianttype(id,variant);
	car *curt_del;
	car *p1,*p2;
	if((hashtable[index]->id=="empty")&&(hashtable[index]->name=="empty"))
	{
		cout<<endl<<"Delete unsuccessful ! "<<endl;
	}
	else if((hashtable[index]->id==id)&&(hashtable[index]->next==NULL))
	{
		cout<<endl<<"Delete Successful ! \nCar id : "<<id<<" $DELETED"<<endl<<"Owner name : "<<hashtable[index]->name<<endl;
		hashtable[index]->id="empty";
		hashtable[index]->name="empty";
	}
	else if(hashtable[index]->id==id)
	{
		curt_del=hashtable[index];
		cout<<endl<<"Delete Successful ! \nCar id : "<<id<<" $DELETED"<<endl<<"Owner name : "<<curt_del->name<<endl;
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
		{
			cout<<endl<<"Delete unsuccessful ! "<<endl;
		}
		else
		{
			curt_del=p1;
			p1=p1->next;
			p2->next=p1;
			cout<<endl<<"Delete Successful ! \nCar id : "<<id<<" $DELETED"<<endl<<"Owner name : "<<curt_del->name<<endl;
			delete curt_del;
		}
	}
}


int main()
{
	hash ca1,ca2,ca3;
	int ch;
	string cid,cname;
	string car_del;

	for(;;)
	{
		cout<<"\n\n1:Insert new Car | 2:Search for an id | 3:Delete an id | 4:Compute efficiency | 5:Exit\n";
		cin>>ch;

		switch(ch)
		{

			case 1:  cout<<"\nCar id: ";
			         cin>>cid;
			         cout<<"Owner name: ";
			         cin>>cname;

			         ca1.add_car(cid,cname,1);
			         ca2.add_car(cid,cname,2);
			         ca3.add_car(cid,cname,3);

			         break;

			case 2:  cout<<"\nEnter the Search car id = ";
			         cin>>cid;

			         cout<<"\nSearch results wrt hashtable 1 : \n";
			         ca1.findname(cid,1);
			         cout<<"\nSearch results wrt hashtable 2 : \n";
			         ca2.findname(cid,2);
			         cout<<"\nSearch results wrt hashtable 3 : \n";
			         ca3.findname(cid,3);

			         break;

			case 3:  cout<<"\nEnter the Car id to be deleted = ";
			         cin>>car_del;

			         cout<<"\nDelete results wrt hashtable 1 : ";
			         ca1.delete_id(car_del,1);
			         cout<<"\nDelete results wrt hashtable 2 : ";
			         ca2.delete_id(car_del,2);
			         cout<<"\nDelete results wrt hashtable 3 : ";
			         ca3.delete_id(car_del,3);

			         break;


			case 4:  cout<<"Which hashtable ?? 1 or 2 or 3 : ";
				 cin>>ch;
				 float eff;
				 switch(ch)
				 {
				 	case 1: eff = ca1.efficiency();
				 		cout<<"Efficiency of Hashtable 1 is "<<eff<<"%"<<endl;
				 		break;

            				case 2: eff = ca2.efficiency();
				 		cout<<"Efficiency of Hashtable 2 is "<<eff<<"%"<<endl;
				 		break;

				 	case 3: eff = ca3.efficiency();
				 		cout<<"Efficiency of Hashtable 3 is "<<eff<<"%"<<endl;
				 		break;

				 }
				 break;
			case 5:  exit(0);
		}
	}

	return 0;

}





