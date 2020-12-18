#include <iostream>
#include <conio.h>
#include <fstream>
#include<iomanip>
#include <string>
#include <stdlib.h>
#include<cmath>
#include <ctime>
using namespace std ;
void background();
void butta();
void add_doc_info();
void modify_doctor(int n);
void delete_doctor();
void display_doctor();
void add_pat_info();
void modify_patient(int n);
void delete_patient();
void display_patient();	
int reportsearch(int n);
int billsearch(int n);
int dispat(int n);
class startFront 
{
	private:
		int id,id1,charg,med;
		char paswd, adm[20],firstname[20],lastname[20],special[20],exp[20],aiv[10],dep[10],
		patfirstname[20],patlastname[20],age[20],dis[20],room[20],sym[20],con[20],date[20] ;
	
	public:
		void style();
		void admin() ;
		void welcome() ;
		int getdata();
		int patdata();
		int showinfo();
		int showdata();
		int retid();
		int retid1();
		int report();
		int bill();
		int discharge();
};

void time()																	//generates the time and date automatically
{
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
 	cout << " Current Date: " << (tPtr->tm_year)+1900 << "/" << (tPtr->tm_mon)+1 << "/" << (tPtr->tm_mday) << endl;
    cout << " Current Time: " << (tPtr->tm_hour)<<":"<< (tPtr->tm_min) << endl; 
    cout << endl;
}

void butta()
{
	cout<<setw(60)<< "-------------------------------------\n" ;
	cout<<setw(55)<< "HOSPITAL MANAGEMENT SYSTEM\n" ;
	cout<<setw(60)<< "-------------------------------------\n\n" ;
}

void startFront :: style()
{
	for (int i = 1; i <= 79 ; i++ )
	{
		cout <<	"_" ;
	}
	cout << endl ;
}

void startFront :: admin()
{
	system("cls");
	butta() ;
	time() ;
	cout <<setw(60)<< "LOGIN TO OUR HOSPITAL MANAGEMENT SYSTEM\n" ;
	style() ;
	cout << "    ADMIN     :     " ;
	cin >> adm ;
	string pass ="" ;
    cout << "    PASSWORD  :     " ;
    paswd = _getch() ;
    while(paswd != 13)
    {                     
    	pass.push_back(paswd) ; 
    	cout << '*' ;
    	paswd = _getch() ;
    }
   	if(pass == "hospital")
	{
    	cout << "\nAccess granted....\n" ;
    	welcome() ;
    }
	else
	{
    	cout << "\n\nAccess aborted....\n" ;
    	getch() ;
    	admin();
    }
}

void startFront :: welcome()
{
	xyz:
		system("cls");
		butta();
		int n;
		cout << "  1.  MAIN MENU\n\n" ;
		cout << "  2.  EXIT\n\n  " ;
		enum choice { Menu , Exit } ;
		cout << "Enter your choice <1/2>:  " ;
		cin >> n ;
		switch (n)
		{
			case 1: 
				system("CLS") ;
				background();
				break;
			case 2: 
				exit (0) ;
		}
}


void background()
{
	xyz:
	int ch2,ch3,ch4;
	system("cls");
	cout<<endl;
	butta();
	cout<<"1. Enter into Doctor’s DataBase"<<endl;
	cout<<"2. Enter into Patient’s DataBase"<<endl;
	cout<<"3. Generate Patient’s Report"<<endl;
	cout<<"4. Generate Patient’s Bill"<<endl;
	cout<<"5. Discharge the Patient"<<endl;
	cout<<"6. EXIT"<<endl;
	cout<<"Please Enter Your choice : ";
	cin>>ch2;
	switch(ch2)
	  	{
	  		case 1:
			{
				xyz2:
				system("cls");
				cout<<endl;
				cout<<"************************************************************************************************************************"<<endl;
				cout<<"\t\t\t\t\t"<<"*** Welcome To Doctor’s DataBase ***"<<endl;
				cout<<"************************************************************************************************************************"<<endl;
				cout<<" 1. Add New Doctor’s Information"<<endl;
				cout<<" 2. Modify Doctor’s Information "<<endl;
				cout<<" 3. Delete Doctor’s Information"<<endl;
				cout<<" 4. Display doctor's information"<<endl;
				cout<<" 5. EXIT "<<endl;
				cout<<" Please Enter your choice :";
				cin>>ch3;
				switch(ch3)
				{
					case 1:
						system("cls");
						add_doc_info();
						goto xyz2;
						break;
					case 2:
						int m;
						system("cls");
						modify_doctor(m);
						goto xyz2;
			  		 	break;
					
					case 3:
						system("cls");
						delete_doctor();
						goto xyz2;
						break;
					case 4:
						system("cls");
						display_doctor();
						goto xyz2;
						break;
					case 5:
						goto xyz;
						break;
					default:
						cout<<"invalid";
				}
				break;
			case 2:
				xyz3:
				system("cls");
				cout<<endl;
				cout<<"************************************************************************************************************************"<<endl;
				cout<<"\t\t\t\t\t"<<"*** Welcome To Patient’s DataBase ***"<<endl;
				cout<<"************************************************************************************************************************"<<endl;
				cout<< "1. Add New Patient’s Information"<<endl;
				cout<< "2. Modify Patient’s Information"<<endl;
				cout<< "3. Delete Patient’s Information"<<endl;
				cout<< "4. Display Patient’s Information "<<endl;
				cout<< "5. EXIT "<<endl;
				cout<<"Please Enter your choice :";
				cin>>ch4;
				switch(ch4)
				{
				case 1:
					system("cls");
					add_pat_info();
					goto xyz3;
					break;
				case 2:
					int m;
					system("cls");
					modify_patient(m);
					goto xyz3;
					break;
				
				case 3:
					system("cls");
					delete_patient();
					goto xyz3;
					break;
				
				case 4:
					system("cls");
					display_patient();
					goto xyz3;
					break;
				
				case 5:
					goto xyz;
					break;
				
				default:
					cout<<"'invalid'";
					break;
				}
				break;
				case 3:
					int m;
					system("cls");
					cout<<"Enter id to generate report: ";
					cin>>m;
					reportsearch(m);
					goto xyz;
					break;
				case 4:
					int l;
					system("cls");
					cout<<"Enter id to generate bill: ";
					cin>>l;
					billsearch(l);
					goto xyz;
					break;
				case 5:
					int k;
					system("cls");
					cout<<"Enter id of Patient to be discharged: ";
					cin>>k;
					dispat(k);
					goto xyz;
					break;
				case 6:
					exit(0);
					break;
				
			}
		}
	}
void add_doc_info()					//add doctor's info
{
	char k;
	FILE *fptr;
	startFront  c1;
 	fptr=fopen("doctor.dat","ab");
 	up: c1.getdata();
    fwrite(&c1,sizeof(c1),1,fptr);
    fclose(fptr);
    cout<<"\n\ndoctor data has been entered "<<endl;
    cout<<"Do you want to continue (y/n)= ";
    cin>>k;
    if(k=='Y'||k=='y')
	{
		goto up; 
	}
	else 
	{
		background();
	}
	
    getch();
}

void modify_doctor(int n)			//modify the info of Doctor
{
	int no,found=0;
    system("cls");
    FILE *fptr;
    startFront c;
    cout<<"********************************************************************************"<<endl;
    cout<<setw(50)<<"MODIFICATION OF DOCTORS DETAIL"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<("\n\n\tPlease Enter The ID Of the Doctor:");
    cin>>no;
    fptr=fopen("doctor.dat","rb+");
    while((fread(&c,sizeof(c),1,fptr))>0 && found==0)
    {
    	if(c.retid()==no)
    	{
            c.showinfo();
            fseek(fptr,-(long)sizeof(c),1);
            fwrite(&c,sizeof(c),1,fptr);
            cout<<"\n\n\t Record Updated";
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}

void delete_doctor()					//delete the existing data of doctor
{
	int no;
    FILE *fptr2;
    FILE *fptr;
    startFront c;
    system("cls");
    cout<<"************************************************************************************************************************"<<endl;
    cout<<"\t\t\t\t\t"<<"RECORD TO BE DELETED"<<endl;
    cout<<"\n\nPlease Enter The id number of doctor You Want To Delete: ";
    cin>>no;
    fptr=fopen("doctor.dat","rb");
    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&c,sizeof(c),1,fptr))>0)
    {
    	if(c.retid()!=no)
    	{
    		fwrite(&c,sizeof(c),1,fptr2);
        }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("doctor.dat");
    rename("Temp.dat","doctor.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
}

void display_doctor()								//display the record of doctors
{
	system("cls");
	FILE *fptr;
	startFront c;
	cout<<"************************************************************************************************************************"<<endl;
    cout<<"\t\t\t\t\t "<<"DISPLAY ALL DETAIL OF DOCTORS !!!"<<endl;
    cout<<"************************************************************************************************************************"<<endl;
    cout<<setw(5)<<setiosflags(ios::left)<<"ID"<<setw(20)<<setiosflags(ios::left)<<"Name"<<setw(20)<<setiosflags(ios::left)<<"Specialization"<<setw(15)<<setiosflags(ios::left)<<"Experience"<<setw(15)<<setiosflags(ios::left)<<"Arrival time"<<setw(15)<<setiosflags(ios::left)<<"Departure time"<<endl;
    fptr=fopen("doctor.dat","rb");
    while((fread(&c,sizeof(c),1,fptr))>0)
    {
    	c.showinfo();
    }
    fclose(fptr);
    getch();
}

int startFront::getdata()					//enter the info regarding doctor
{
	cout<<"Enter Doctor’s ID :";
	cin>>id;
	cout<<"Enter Doctor’s First Name :";
	cin>>firstname;
	cout<<"Enter Doctor’s last Name :";
	cin>>lastname;
	cout<<"Enter Doctor’s Specialization :";
	cin>>special;
	cout<<"Enter Doctor’s Experience :";
	cin>>exp;
	cout<<"Enter Doctor's arrival time:";
	cin>>aiv;
	cout<<"Enter Doctor's departure time:";
	cin>>dep;
}


int startFront::showinfo()				//snowinfo in detail of doctor
{
	cout<<id<<"\t\t"<<firstname<<" "<<lastname<<"\t\t\t"<<special<<"\t\t\t"<<exp<<"\t\t"<<aiv<<"\t\t"<<dep<<endl;
}
			
int startFront::retid()					//return the id number of doctor
{
	return id;
}


void add_pat_info()					//add information of patients
{
	char k;
	FILE *fptr1;
	startFront c1;
 	fptr1=fopen("patient.dat","ab");
 	up: c1.patdata();
    fwrite(&c1,sizeof(c1),1,fptr1);
    fclose(fptr1);
    cout<<"\n\nPatient information has been entered "<<endl;
    cout<<"Do you want to continue (y/n)= ";
    cin>>k;
    if(k=='Y'||k=='y')
	{
		goto up; 
	}
	else 
	{
		background();
	}
    getch();
}

void modify_patient(int n)							//modify the data of the patient
{
	int no,found=0;
    system("cls");
    FILE *fptr;
    startFront c;
    cout<<("\n\n\tTo Modify ");
    cout<<("\n\n\tPlease Enter The id number of patient");
    cin>>no;
    fptr=fopen("patient.dat","rb+");
    while((fread(&c,sizeof(c),1,fptr))>0 && found==0)
    {
    	if(c.retid1()==no)
    	{
            c.patdata();
            fseek(fptr,-(long)sizeof(c),1);
            fwrite(&c,sizeof(c),1,fptr);
            cout<<"\n\n\t Record Updated";
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}


void delete_patient()						//delete the data of existing information of the patient
{
	int no;
    FILE *fptr2;
    FILE *fptr;
    startFront c;
    system("cls");
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nPlease Enter The id number of Patient You Want To Delete: ";
    cin>>no;
    fptr=fopen("patient.dat","rb");
    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&c,sizeof(c),1,fptr))>0)
    {
    	if(c.retid1()!=no)
    	{
    		fwrite(&c,sizeof(c),1,fptr2);
        }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("patient.dat");
    rename("Temp.dat","patient.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
}

void display_patient()									//display the detail of patient in detail
{
	system("cls");
	FILE *fptr;
	startFront c;
    cout<<"************************************************************************************************************************"<<endl;
	cout<<"\t \t \t\t\t" <<"Details Of All The Pateint In The Hospital "<<endl;
	cout<<"************************************************************************************************************************"<<endl;
	cout<<setw(5)<<setiosflags(ios::left)<<"ID"<<setw(20)<<setiosflags(ios::left)<<"Name"<<setw(15)<<setiosflags(ios::left)<<"illness"<<setw(15)<<setiosflags(ios::left)<<"ADMITTED Date"<<setw(5)<<setiosflags(ios::left)<<"age";
	cout<<endl;
    fptr=fopen("patient.dat","rb");
    while((fread(&c,sizeof(c),1,fptr))>0)
    {
    	c.showdata();
      	getch();
    }
    fclose(fptr);
    getch();
}

int startFront::patdata()					//enter the info regarding doctor
{
	cout<<"1.Enter Patient’s ID :";
	cin>>id1;
	cout<<"2. Enter patient’s First Name :";
	cin>>patfirstname;
	cout<<"2. Enter patient’s last Name :";
	cin>>patlastname;
	cout<<"3. Enter patient’s Age :";
	cin>>age;
	cout<<"4. Enter patient’s Disease :";
	cin>>dis;
	cout<<"5. Enter patient’s Symptoms :";
	cin>>sym;
	cout<<"6. Enter Patient’s Room No. :";
	cin>>room;
	cout<<"7. Enter Patient’s condition Before discharge :";
	cin>>con;
	cout<<"8. Enter Patient’s ADMIT Date :";
	cin>>date;
	cout<<"9. Enter Patient’s Room Charge :";
	cin>>charg;
	cout<<"10. Enter Patient’s Medicine charge :";
	cin>>med;
}	
	
int  startFront::retid1()					//the id number of patient
{
 	return id1;
}

int startFront::showdata()				//show the data in detail of patient
{
	cout<<id1<<"\t\t"<<patfirstname <<patlastname<<"\t\t"<<dis<<"\t\t\t"<<date<<"\t\t\t"<<age<<endl;
}

int startFront::report()					//shows the report of the patient
{
	cout<<"************************************************************************************************************************"<<endl;
	cout<<"\t\t\t\t\t\t"<<"*** Patient’s Report ***"<<endl;
	cout<<"************************************************************************************************************************"<<endl;
	cout<< "1. Patient’s Name:"<<"\t"<<patfirstname <<patlastname<<endl;
	cout<< "2. Patient’s Age:"<<"\t"<<age<<endl;
	cout<< "3. Patient symptoms:"<<"\t"<<sym<<endl;
	cout<< "4. Patient Disease:"<<"\t"<<dis<<endl;
	cout<< "5. Patient Admit Date:"<<"\t"<<date<<endl;
	cout<< "6. Patient condition At The Time Of Discharge:"<<"\t"<<con<<endl;
	cout<<"Press Any Key To Go Back…";
}

int startFront::bill()					//shows the bill of the patient
{
	cout<<"************************************************************************************************************************"<<endl;
	cout<<"\t \t \t\t\t "<<"*** Patient’s Bill ***"<<endl;
	cout<<"************************************************************************************************************************"<<endl;
	cout<<"1. Patient’s Medicine Charge:"<<"\t"<<med<<endl;
	cout<< "2. Patient’s Room Charge:"<<"\t"<<charg<<endl;
	cout<<"Press Any Key To Go Back….";
}

int startFront::discharge()
{
	cout<<"Discharge Patient"<<endl;
	cout<<"1.Enter Patient’s ID :"<<id1<<endl;
	cout<<"2. Enter patient’s First Name :"<<patfirstname<<endl;
	cout<<"2. Enter patient’s last Name :"<<patlastname<<endl;
	cout<<"3. Enter patient’s Age :"<<age<<endl;
	cout<<"4. Enter patient’s Disease :"<<dis<<endl;
	cout<<"5. Enter patient’s Symptoms :"<<sym<<endl;
	cout<<"6. Enter Patient’s Room No. :"<<room<<endl;
	cout<<"7. Enter Patient’s condition Before Admit :"<<con<<endl;
	cout<<"8. Enter Patient’s ADMIT Date :"<<date<<endl;
	cout<<"9. Enter Patient’s Room Charge :"<<charg<<endl;
	cout<<"10. Enter Patient’s Medicine charge :"<<med<<endl;
}
int reportsearch(int n)
{
	int flag=0;
	FILE *fptr;
	startFront c;
    fptr=fopen("patient.dat","rb");
    while((fread(&c,sizeof(c),1,fptr))>0)
    {
    	if(c.retid1()==n)
        {
        	system("cls");
            c.report();
         	flag=1;
        }
    }
    fclose(fptr);
	if(flag==0)
	{
		cout<<"\n\nrecord not exist";
	}
    getch();
} 

int billsearch(int n)
{
	int flag=0;
	FILE *fptr;
	startFront c;
    fptr=fopen("patient.dat","rb");
    while((fread(&c,sizeof(c),1,fptr))>0)
    {
    	if(c.retid1()==n)
        {
        	system("cls");
            c.bill();
         	flag=1;
        }
    }
    fclose(fptr);
	if(flag==0)
	{
		cout<<"\n\nrecord not exist";
	}
    getch();
} 

int dispat(int n)
{
	int flag=0;
	char q;
	FILE *fptr;
	FILE *fptr2;
	startFront c;
    fptr=fopen("patient.dat","rb");
    while((fread(&c,sizeof(c),1,fptr))>0)
    {
    	if(c.retid1()==n)
        {
        	system("cls");
            c.discharge();
            fclose(fptr);
            cout<<"Do you want to delete the detail of the Patient (y/n)= ";
		    cin>>q;
		    if(q=='Y'||q=='y')
			{
				FILE *fptr;
				FILE *fptr2;
				startFront c;
				int no;
				cout<<"enter the id number of patient to confirm:"<<endl;
				cin>>no;
				fptr=fopen("patient.dat","rb");
			    fptr2=fopen("Temp.dat","wb");
			    rewind(fptr);
			    while((fread(&c,sizeof(c),1,fptr))>0)
			    {
			    	if(c.retid1()!=no)
			    	{
			    		fwrite(&c,sizeof(c),1,fptr2);
			        }
			    }
			    fclose(fptr2);
			    fclose(fptr);
			    remove("patient.dat");
			    rename("Temp.dat","patient.dat");
			    cout<<"\n\n\tRecord Deleted .."; 
			}
		         	flag=1;
		        }
		    }
	    
		if(flag==0)
		{
			cout<<"\n\nrecord not exist";
		}
	getch();	
}
int main()
{
	startFront sf ;
	sf.admin() ;
	return 0;
}
