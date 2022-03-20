#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>

void changeqty(int );
void writedealer();
void dispdealer();
void stockmodify(int ,char[]);
void printbill();
void searchbill();
void modifybill();
void modifydealer();
void searchdealer();
int random(int );
void add();
void disp();
void del();
void modify();
void search();
void writefiletransac();

struct date
{
unsigned int dd,mm,yy;
};

class shop
{
date manu,exp;
long int id;
short int no;
unsigned long int price;
char name[50],comp[50];
public:
void get();
void disp();
char *  get_name()
	{
	return name;
	}
long int get_id()
	{
	return id;
	}
int get_price()
{
return price;
}
void changeqty(int y)
{
no=no+y;
}
};

class transac
{
char name[50],gender;
unsigned int cost[10],no[10],bill,nomed,g;
char medname[10][50];
unsigned long int id[10];
char docname[50];
public:
void get();
void disp();
int billreturn()
{
return(bill);
}
};


void shop::get()
{
int f=0;
cout<<"\nENTER THE NAME OF THE MEDICINE: ";
gets(name);
cout<<"\nENTER THE ID OF THE MEDICINE: ";
cin>>id;
do
{
cout<<"\nENTER MANUFACTURE DATE: ";
cout<<"\nDAY: \tMONTH: \tYEAR: ";
cin>>manu.dd>>manu.mm>>manu.yy;
if(manu.dd>31||manu.mm>12||manu.yy>2015)
{
cout<<"\nSorry the respective parameters are invalid"
<<" please see that the day no. don't exceed 31 or 30 and 28"
<<" for respective months, please try again...";
f=1;
}
}while(f==1);
do
{
cout<<"\nENTER EXPIRY DATE: ";
cout<<"\nDAY: \tMONTH: \tYEAR: ";
cin>>exp.dd>>exp.mm>>exp.yy;
if(exp.dd>31||exp.mm>12||exp.yy<2015)
{
cout<<"\nSorry the respective parameters are invalid"
<<" please see that the day no. don't exceed 31 or 30 and 28"
<<" for respective months, please try again...";
f=1;
}
}while(f==1);
cout<<"\nENTER THE NAME OF THE COMPANY: ";
gets(comp);
cout<<"\nENTER THE PRICE OF THE MEDICINE: ";
cin>>price;
cout<<"\nHOW MANY OF THIS MEDICINE: ";
cin>>no;
}

void shop::disp()
{
cout<<"\nDISPLAYING THE RECORDS .....";
cout<<"\nNAME: "<<name
<<"\nID: "<<id
<<"\nMANUFACTURE DATE: ";
cout<<manu.dd<<" \ "<<manu.mm<<" \ "<<manu.yy;
cout<<"\nEXPIRY DATE: ";
cout<<exp.dd<<" \ "<<manu.mm<<" \ "<<manu.yy;
cout<<"\nNAME OF THE COMPANY: "<<comp
<<"\nPRICE : "<<price
<<"\nNUBER OF MEDICINE: "<<no;
}

void main()
{
int c=0;
transac t;
dealer d;
clrscr();

	do
	{


	cout<<"\n\t\t\t\t MEDICAL STORE\t::::---"
	<<"\n\n\t\t\t*************************"
	<<"\n\t\t\t-->\t 1)NEW MEDICINE"
	<<"\n\t\t\t-->\t 2)SEARCH AND DISPLAY A SPECIFIC MEDICINE"
	<<"\n\t\t\t-->\t 3)MODIFY A MEDICINE'S RECORD"
	<<"\n\t\t\t-->\t 4)DELETE A MEDICINE'S RECORD"
	<<"\n\t\t\t-->\t 5)DISPLAY ALL MEDICINE"
	<<"\n\t\t\t-->\t 6)TRANSACTION OF MEDICINE"
	<<"\n\t\t\t-->\t 7)PRINT BILL"
	<<"\n\t\t\t-->\t 8)MODIFY BILL"
	<<"\n\t\t\t-->\t 9)SEARCH BILL"
	<<"\n\t\t\t-->\t 10)ADD DEALER"
	<<"\n\t\t\t-->\t 11)DISP DEALER"
	<<"\n\t\t\t-->\t 12)MODIFY DEALER"
	<<"\n\t\t\t-->\t 13)EXIT"
	<<"\nENTER CHOICE :--> ";
	fflush(stdin);
	cin>>c;
	switch(c)
		{
		case 1:
		add();
		break;
		case 2:
		search();
		break;
		case 3:
		modify();
		break;
		case 4:
		del();
		break;
		case 5:
		disp();
		break;
		case 6:
		writefiletransac();
		break;
		case 7:
		t.disp();
		break;
		case 13:
		cout<<"\nEnd of your working session"
		<<"\n BYE";
		break;
		case 8:
		modifybill();
		break;
		case 9:
		searchbill();
		break;
		case 10:
		d.get();
		break;
		case 11:
		dispdealer();
		break;
		case 12:
		modifydealer();
		break;
		default:
		cout<<"\nSorry wrong input tyr again...";
		getch();
		}
	}while(c!=6);
}

void add()
	{
	shop s;
	ofstream fout("store.dat",ios::binary,ios::app);
	if(!fout)
	cout<<"\nsorry file handling error";
		else
		{
		char cho;

			do
			{
			s.get();
			fout.write((char *)&s,sizeof(s));
			cout<<"\nDo you want to enter any more records??(y/n) ";
			cin>>cho;
			}while(cho=='y');
		}
	clrscr();
	fout.close();
	}


void search()
{
int op;
shop s;
ifstream fin("store.dat",ios::binary);
if(!fin)
cout<<"\nFile handling error ";

else
{
cout<<"\nEnter by what method do you want to search: 1)name/2)id:  ";
cin>>op;
int flag=0;
	if(op==1)
	  {
	   char name[50];
	   cout<<"\nEnter name of the medicine: ";
	   fflush(stdin);
	   gets(name);
		while(fin.read((char *)&s, sizeof(s)))
		if(strcmp(s.get_name(),name)==0)
		{

		flag=1;
		cout<<"\nRECORD FOUND.........do you want to display the"
		<<" data of the medicine:::  (y/n)";
		char d;
		cin>>d;
		if(d=='y')
		s.disp();
		else
		cout<<"\nok returning to main menu....";
		}


		if(flag==0)
		cout<<"\nSorry no record of the given name is found";


	   }
	   else  //else of op==1
	   if(op==2)
	   {

		cout<<"\nEnter the id of medicine: ";
		long int id;
		cin>>id;
		while(fin.read((char *)&s, sizeof(s)))
		if(s.get_id()==id)
		{
		flag=1;
		cout<<"\nRECORD FOUND.........do you want to display the"
		<<" data of the medicine:::  (y/n)";
		char d;
		cin>>d;
		if(d=='y')
		s.disp();
		else
		cout<<"\nok returning to main menu....";

		}
		if(flag==0)
		cout<<"\nSorry no record of given id found";

	   }
		else         //else of op==2
		cout<<"\nWrong input please try again";

	}
	fin.close();
}



void del()
{
int flag=0;
shop s;
int op;
ifstream fin("store.dat",ios::binary);
ofstream fout,fout1;
fout1.open("temp.dat",ios::binary);
fout.open("store.dat",ios::binary);

	if(!fin||!fout||!fout1)
	cout<<"\nFile handling error";
		else
		{
		cout<<"\nEnter by what method do you want to search for deletion: 1)name/2)id:  ";
		cin>>op;
			if(op==1)
			{
			char name[50];
			cout<<"\nEnter name of the medicine: ";
			gets(name);
				while(fin.read((char *)&s,sizeof(s)))
				{
				if(s.get_name()==name)
				flag=1;
				else
				fout1.write((char *)&s,sizeof(s));
				}  //while ends here
			if(flag==1)
			{
			cout<<"\nRECORD HAS BEEN DELETED....";
			remove("store.dat");
			rename("temp.dat","store.dat");
			}
			else
			{
			remove("temp.dat");
			cout<<"\nSorry no record have been found...";
			}
			} //if ends of op==1

			else //of if op==1
			if(op==2)
				{
				cout<<"\nEnter the id of medicine: ";
				long int id;
				cin>>id;
				while(fin.read((char *)&s,sizeof(s)))
					{
					if(s.get_id()==id)
					flag=1;
					else
					fout1.write((char *)&s,sizeof(s));
					} //while
				if(flag==1)
				{
				cout<<"\nRECORD HAS BEEN MODIFIED....";
				remove("store.dat");
				rename("temp.dat","store.dat");
				}
				else
				{
				remove("temp.dat");
				cout<<"\nSorry no record have been found...";
				}
				} //op==2
				else //of op==2
				cout<<"\nSorry wrong option try again";
	} //largest else
	getch();
	clrscr();
}


void disp()
{
shop s;
ifstream fin("store.dat",ios::binary);
//ofstream fout("store.dat",ios::binary);
	if(!fin)//||!fout)
	cout<<"\nSorry file handling error";
	else
		{
		cout<<"\nwhat do you want to disp. only the record of a specific medicine"
		<<" or the whole record of the store: 1)for the first option and 2)for "
		<<"the second option: ";
		int i=0;
		cin>>i;
			if(i==1)
			{
			char name[20];
			cout<<"\nEnter the name of the medicine of which you want to display "
			<<" the record: ";
			gets(name);
			int flag=0;
				while(fin.read((char *)&s,sizeof(s)))
				{
					if(strcmp(s.get_name(),name)==0)
					{
					s.disp();
					flag=1;
					}//small if
				}//while

				if(flag==0)
				cout<<"\nSorry no medicine of given name is found sorry";
			}//i==1

			else  //of i==1
				if(i==2)
				{

				cout<<"\nDISPLAYING ALL RECORDS OF ALL MEDICINE IN THE STORE...";


					while(!fin.eof())
					{
					fin.read((char*)&s,sizeof(s));
					s.disp();
					}

				}//i=2


	} //largest else
	getch();
	      clrscr();
}

void modify()
{
ifstream fin("store.dat",ios::binary);
ofstream fout("temp.dat",ios::binary);
shop s;
	if(!fin||!fout)
	cout<<"\nFile handling error";
	else
	{
	long int id;
	int flag=0;
	char name[20];
	int a;
	cout<<"\nEnter the method by which you want to modify the record 1)name/2)id";
	cin>>a;
		if(a==1)
		{
		cout<<"\nEnter the name of the medicine: ";
		cin>>name;
			while(fin.read((char *)&s,sizeof(s)))
			{
				if(strcmp(s.get_name(),name)==0)
				{
				cout<<"\nEnter the new records of the medicine: ";
				s.get();
				flag=1;
				} //if
				fout.write((char *)&s,sizeof(s));
			}
			if(flag==1)
			{
			cout<<"\nModified...";
			remove("store.dat");
			rename("temp.dat","store.dat");
			}
			else
			{
			cout<<"\nSorry not modified as no record is found...";
			remove("temp.dat");
			}
			}
		else
		if(a==2)
			{
			cout<<"\nEnter the id of the medicine: ";
			cin>>id;
				while(fin.read((char *)&s,sizeof(s)))
				{
					if(s.get_id()==id)
					{
					flag=1;
					cout<<"\nEnter the new records of the medicine: ";
					s.get();

					} //if
				fout.write((char *)&s,sizeof(s));
				}//while

			if(flag==1)
			{
			cout<<"\nModified...";
			remove("store.dat");
			rename("temp.dat","store.dat");
			}
			else
			{
			cout<<"\nSorry not modified as no record is found...";
			remove("temp.dat");
			}
		}//else
		else
		cout<<"\nSorry wrong option try again";


	}//else largest
fin.close();
fout.close();
clrscr();

}

void stockmodify(int x,char namemed[])
{
shop s;
ofstream fout("store.dat",ios::binary|ios::app);
ifstream fin("store.dat",ios::binary|ios::app);
if(!fout||!fin)
cout<<"\nSorry file handling error ";
else
{
while(fin.read((char *)&s,sizeof(s)))
if(strcmp(s.get_name(),namemed)==0)
{
int f=-x;
s.changeqty(f);
}
else
cout<<"\nSorry no medicine of this name has been found...";
}
}


void transac::get()
{
int nomed=0,no=0;
cout<<"\nEnter your name: ";
fflush(stdin);
cout<<"\nEnter your gender m/f: ";
cin>>gender;
gets(name);
cout<<"\nEnter the doctors name from whom prescription is taken: ";
fflush(stdin);
gets(docname);
cout<<"\nHow many different types of medicine: ";
cin>>nomed;
int g=0;
for(int i=0;i<nomed;i++)
{
cout<<"\nEnter the name of medicine number "<<i+1<<" which you have taken: ";
fflush(stdin);
gets(medname[i][]);
cout<<"\nHow many of this medicine have you taken?? ";
cin>>no;
stockmodify(no,medname[50]);

g=i+1;
}
getch();
}

void transac::disp()
{
shop s;
bill=random(100);
cout<<"\nName: "<<name;
cout<<"\nGender: "<<gender;
cout<<"\nOn "<<docname<<" prescription";
for(int i=0;i<g-1;i++)
{
cout<<"\nMedicine number: "<<i<<"\nMedicine name: "<<medname[i][50];
cout<<"\nNumber of this medicine taken: "<<no;
int v=s.get_price();
int w;
w=no*v;
cout<<"\nTotal cost is "<<w;

}

getch();
}

void writefiletransac()
{
ofstream fout("transaction.dat",ios::binary,ios::app);
transac t;
if(!fout)
cout<<"\nSorry file handling error ";
else
{
cout<<"\nWelcome to the transaction part...";
cout<<"\nPlease enter the following details..";
t.get();
fout.write((char *)&t,sizeof(t));
getch();

}
}


void searchbill()
{

unsigned int bill;
transac t;
ifstream fin("transaction.dat",ios::binary);
if(!fin)
cout<<"\nFile handling error..";
else
{
cout<<"\nEnter the bill number: ";
cin>>bill;
while(fin.read((char *)&t,sizeof(t)))
if(t.billreturn()==bill)
t.disp();
else
cout<<"\nSorry no record of this bill number is found...";
}
}

class dealer
{
date manu,exp;
char name[50],comp[50],medname[50];
unsigned long int qty,cost,id;
public:
char * nameret()
{
return (name);
}
void get();
void put();

};

void dealer::get()
{
int f=0;
cout<<"\nEnter your (dealers) name: ";
fflush(stdin);
gets(name);
cout<<"\nEnter the name of the company: ";
fflush(stdin);
gets(comp);
cout<<"\nEnter the name of medicine supplied: ";
fflush(stdin);
gets(medname);
cout<<"\nEnter the id of the medicine: ";
cin>>id;
cout<<"\nEnter the cost of each medicine: ";
cin>>cost;
do
{
cout<<"\nENTER MANUFACTURE DATE: ";
cout<<"\nDAY: \tMONTH: \tYEAR: ";
cin>>manu.dd>>manu.mm>>manu.yy;
if(manu.dd>31||manu.mm>12||manu.yy>2015)
{
cout<<"\nSorry the respective parameters are invalid"
<<" please see that the day no. don't exceed 31 or 30 and 28"
<<" for respective months, please try again...";
f=1;
}
}while(f==1);
do
{
cout<<"\nENTER EXPIRY DATE: ";
cout<<"\nDAY: \tMONTH: \tYEAR: ";
cin>>exp.dd>>exp.mm>>exp.yy;
if(exp.dd>31||exp.mm>12||exp.yy<2015)
{
cout<<"\nSorry the respective parameters are invalid"
<<" please see that the day no. don't exceed 31 or 30 and 28"
<<" for respective months, please try again...";
f=1;
}
}while(f==1);
}

void writedealer()
{

//use copy constructor and equate s and dealer and then call
//writing in file of store class and add a medicine into the account.
}

void dealer::put()
{
cout<<"\nDealers name: "<<name;
cout<<"\nCompany: "<<comp;
cout<<"\nMedicine: "<<medname;
cout<<"\nQuantity: "<<qty;
cout<<"\nCost of each medicine: "<<cost;
cout<<"\nTotal cost: "<<cost*qty;
cout<<"\nManufacture date: "<<manu.dd<<" / "<<manu.mm<<" / "<<manu.yy;
cout<<"\nManufacture date: "<<exp.dd<<" / "<<exp.mm<<" / "<<exp.yy;
cout<<"\nID of the medicine: "<<id;
}

void dispdealer()
{
dealer d;
ifstream fin("dealer.dat",ios::binary);
if(!fin)
cout<<"\n file handling error";
else
{
int sun=0;
char deal_name[50];
cout<<"1) specific dealer\n2)all dealers : ";
cin>>sun;
if(sun==1)
{
cout<<"\n enter the name of dealer:";
fflush(stdin);
gets(deal_name);
while(fin.read((char *)&d,sizeof(d)))
if(strcmp(deal_name,d.nameret())==0)
{
cout<<"\n record found:";
d.put();
}
else
cout<<"\n sorry no record found";
}
else
if(sun==2)
{
while(fin.read((char *)&d,sizeof(d)))
d.put();
}
getch();
}
}

void searchdealer()
{
dealer d;
ifstream fin("dealer.dat",ios::binary);
if(!fin)
cout<<"\nFile handling error...";
else
{
char dealername[50];
cout<<"\n enter the name of dealer:";
fflush(stdin);
gets(dealername);
while(fin.read((char *)&d,sizeof(d)))
if(strcmp(dealername,d.nameret())==0)
{
cout<<"\n record found....";
cout<<"\nDo you want to display the record of the dealer: (y/n): ";
char op;
cin>>op;
if(op=='y')
d.put();
else
cout<<"\nOk returning to the main menu...";
getch();
}
fin.close();
}

void modifydealer()
{
ifstream fin("dealer.dat",ios::binary);
ofstream fout("temp.dat",ios::binary|ios::out);
if(!fin||!fout)
cout<<"\nSorry file handling error...";
else
{
dealer d;
int flag=0;
char name[50];
cout<<"\nENter the name of the dealer of whose record you want to modify: ";
fflush(stdin);
gets(name);
while(fin.read((char *)&d,sizeof(d)))
{
if(strcmp(name,d.nameret())==0)
{
cout<<"\nRecord found please enter the modified value...";
d.get();
flag=1;
}
fout.write((char *)&d,sizeof(d));
}
if(flag==1)
{
cout<<"\nRecord has been modified...";
remove("dealer.dat");
rename("temp.dat","dealer.dat");
}
else
if(flag==0)
{
cout<<"\nSorry no record is found so no modification can be done..";
remove("temp.dat");
}
}
fout.close();
fin.close();
getch();
}


void modifybill()
{
ifstream fin("transaction.dat",ios::binary);
ofstream fout("temp.dat");
transac t;
if(!fin||!fout)
cout<<"\nSorry file handling error...";
else
{
int bill,flag=0;
cout<<"\nEnter the bill number for modification: ";
cin>>bill;
while(fin.read((char *)&t,sizeof(t)))
{
if(t.billreturn()==bill)
{
cout<<"\nRecord found please enter the modified values...";
t.get();
flg=1;
}
fout.write((char *)&t,sizeof(t));
}

if(flg==1)
{
cout<<"\nRecord modified...";
remove("transaction.dat");
rename("transaction.dat","temp.dat");
}
else
{
cout<<"\nSorry no record hs been found...";
remove("temp.dat");
}
}
}
