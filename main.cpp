  
						                                        //////////////////////////////////
///////////////////////////////////////////////////  Medical Shop Management System  ////////////////////////////////////////////////////////////////
						                                       //////////////////////////////////
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

class Order	//base class
{
public:

    void take_order();
    void delete_order();  
    void modify(); 
    void receipt(); 
    void daily_summary();  
    void modify_order_list();
    void exit();   
    Order(); 

}; 
struct node //constract node
{
	int order_no ;
	string customerName;
	string date;
	int quantity[14];
	string type = {"OTC"};
	int x, menu2[14];
    double amount[14];
    string medicineName[14]={"Vitamin C ","Paracetamol","Acid Free ","Marino Tablet","Amino Zinc ","Biotin","Fabuloss 5","Aciloc","Aspirin","Asthalin","Foracort","Cofsils","Koflet","Penicillin"};
	double Medicine[14] = {50.00,30.00,20.00,10.00,20.00,70.00,80.00,90.00,40.00,100.00,70.00,30.00,110.00,120.00};
	double total;
	node *next;

}*q, *temp;				 

node *start_ptr = NULL;

 Order::Order ( )   //constructor for class CarType
{

}
void Order::modify_order_list( )		 
{
    int c ;
    do
    {
        cout<<"What do you want to modify in the order :\n";
        cout<<" 1. Order Number \n";
        cout<<"2. Customer Name : Press 2\n";
        cout<<"3. Date : Press 3\n";
        cout<<"4. Medicine : Press 4\n";
		cout<<"5. Exit\n";
        cin>>c;
        switch(c)
        {
            case 1 : { cout<<"Enter new Order Number : " ;
                      cin>>temp->order_no ; 
                      break;
                      }
            case 2 : { cout<<"Enter new customer Name : " ;
                          cin>>temp->customerName;
                        break;
                    }
            case 3 : {  cout<<"Enter new Date : " ;
                        cin>> temp->date;
                        break;
                    }
            case 4 : { cout<<"Enter which Medicine you want to modify in list : ";
                        long num2 ;
                        cin>>num2;
                        cout<<"Enter Medicine Name to which medicine will be replaced :\n";
                        cin>>temp->menu2[num2-1];
                        cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[num2]-1]<<endl;
                        cout<<"\n How many new medicines you want :\n";
                        cin>>temp->quantity[num2-1];
                        temp->amount[num2] = temp->quantity[num2] * temp->Medicine[temp->menu2[num2]-1];
                        cout << "The amount You need to pay After Modify  is: " << temp->amount[num2]<<" Rs"<<endl;
                        system("PAUSE");
                        break;
                     }
            case 5 : goto jump;
            default : cout<<"Wrong input\n";
        }
    }while( c != 5);
    jump :   
    temp = temp->next;
     cout<<"RECORD MODIFIED....!"<<endl;
   
    
}

int main()	 
{

	system("COLOR 70");
	Order medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t    Medical Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.take_order();	//function add
				break;
			}	//end case 1
		
		
		case 2:
			{
				medicine.delete_order();	//function delete
				system("PAUSE");
				break;
			}	//end case 2
			
		case 3:
			{
				medicine.modify();	//function modify
				system("PAUSE");
				break;
			}	//end case 3

		case 4:
			{
				medicine.order_list();	//function order
				system("PAUSE");
				break;
			}	//end case 4
		case 5:
			{
				medicine.daily_summary();	//function  summary
				system("PAUSE");
				break;
			}	//end case 5
        case 6:
			{
				medicine.exit();	//function exit
				goto a;
				break;
			}	//end case 6

		
		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}
		}
	}while(menu!=6);//end do
	a://goto
	cout<<"thank you"<<endl;
    system("cls");
	system ("PAUSE");
	return 0;
}//end  main function


void Order:: take_order()	//function to take_order
{
	 
	int i;
    int choice, quantity, price,None;
	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;

		cout <<"**************************************************************************\n";
		cout<<left<<setw(20)<<"Medicine ID"<<left<<setw(20)<<"Medicine TYPE"<<left<<setw(20)<<"Medicine NAME"<<left<<setw(20)<<"Medicine PRICE(Rs)"<<endl;
		cout <<"**************************************************************************\n";
                cout<< left<< setw(20)<< "0001"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< " Vitamin C "<< left<< setw(20)<< "Rs 50"<< endl;
		cout<< left<< setw(20)<< "0002"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Paracetamol"<< left<< setw(20)<< "Rs 30"<< endl;
		cout<< left<< setw(20)<< "0003"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Acid Free C"<< left<< setw(20)<< "Rs 20"<< endl;
		cout<< left<< setw(20)<< "0004"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Marino "<< left<< setw(20)<< "Rs 10"<< endl;
		cout<< left<< setw(20)<< "0005"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Amino Zinc"<< left<< setw(20)<< "Rs 20"<< endl;
		cout<< left<< setw(20)<< "0006"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Biotin"<< left<< setw(20)<< "Rs 70"<< endl;
		cout<< left<< setw(20)<< "0007"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Fabuloss 5"<< left<< setw(20)<< "Rs 80"<< endl;
		cout<< left<< setw(20)<< "0008"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Aspirin"<< left<< setw(20)<< "Rs 90"<< endl;
                cout<< left<< setw(20)<< "0009"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Aciloc"<< left<< setw(20)<< "Rs 40"<< endl;
                cout<< left<< setw(20)<< "0010"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Asthalin"<< left<< setw(20)<< "Rs 100"<< endl;
                cout<< left<< setw(20)<< "0011"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Foracort"<< left<< setw(20)<< "Rs 70"<< endl;
                cout<< left<< setw(20)<< "0012"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Cofsils"<< left<< setw(20)<< "Rs 30"<< endl;
                cout<< left<< setw(20)<< "0013"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Koflet"<< left<< setw(20)<< "Rs 110"<< endl;
                cout<< left<< setw(20)<< "0014"<< left<< setw(20)<<  "OTC"<< left<< setw(20)<< "Penicillin"<< left<< setw(20)<< "Rs 120"<< endl;

                cout<<" "<<endl;
    
	//temp = new node;
	cout << "Type Order no: ";
    cin >> temp->order_no ;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 14  ) \n";
	cout << "  " ;
	cin >> temp->x;
	for( int i = 0 ; i  < 14 ; i++)
		{
			temp->amount[i] = 0 ;
		}
	if (temp->x >14)
	{
		cout << "The medcine order limit is exceeded !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your Medicine Name : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Medicine ID : " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->amount[i]<<" Rs"<<endl;
        system("PAUSE");
                      
	}
	cout<<"==========================================================================="<<endl;
    cout << "Order taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}//End function take_order


void Order::order_list()		//Function to display receipt
{
	int i, num, num2;	
	bool found;			//variable to search 
	node *temp;

	temp=start_ptr;
	found = false;
	cout<<" Enter the Order Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\tHere is the Order list\n"; 
	cout<<"==========================================================================="<<endl;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->order_no ==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
		cout <<"Reciept Number : "<<temp->order_no ;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;
				
		cout<<"Order Date : "<<temp->date<<endl;
				
		cout<<"_____________________________________________________________________________"<<endl;
			
		 cout << "===============================================================================" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" Rs"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}
		for( int i = 0 ; i < 14 ; i++)
        {
            temp->total += temp->amount[i];
        }

		cout<<"Total Bill is : "<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;
		cout <<"\n";
		cout <<"\n";
		if(num >= temp->total)
		{
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}
		else
		{
			cout<<"You have paid : "<<num<<endl;
			cout<<"Pending amount to pay : "<<temp->total - num<<endl;
		    


		}
		}


}
}	//End functionreceipt


void Order::delete_order()	//function to delete_order
{
	system("cls");
	int i, num ;
    cout<<"Enter the Order Number you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->order_no  == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->order_no  != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				delete q;
				cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		} 
}	//End function delete_order



void Order::modify()		//function to modify order
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->order_no ==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)
        {
                int c ;
                cout<<left<<setw(50)<<"If you want to modify whole order : Press 1 \n";
                cout<<left<<setw(50)<<"Otherwise : Press 2\n";
                cin>>c ;
                if( c != 1)
                {
                      modify_order_list( );
                }
                else{
	            cout << "Change  Order Number: ";
                 cin >> temp->order_no ;
	            cout<< "Change Customer Name: ";
	            cin>> temp->customerName;
	            cout<<"Change Date : ";
	            cin>>temp->date;
	            cout << "How many New Medicine would you like to Change:"<< endl;
	            cout<<"( Maximum is 14 order for each transaction ) \n";
	            cout << "  " ;
	            cin >> temp->x;
	                if (temp->x >14)
	                {
		                cout << "The Medicine you order is exceed the maximum amount of order !";
		                system("pause");
	                }
	                else
                    {
	                    for (i=0; i<temp->x; i++)
	                    {
		
		                    cout << "Please enter your Medicine to Change: "<<endl;
		                    cin>> temp->menu2[i];
                            cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
                            cout << "How many New medicine do you want: ";
                            cin >> temp->quantity[i];
                            temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
                            cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" Rs"<<endl;
                            system("PAUSE");
	                    }
                    }
                
	temp = temp->next;
    cout<<"RECORD MODIFIED....!"<<endl;
	system("PAUSE");
                }
    
        
    }

    }


 	if(temp != NULL && temp->order_no  != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }

}
	//End modify function



void Order::daily_summary()		//Function to display Daily Summary
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;
        double total = 0 ;
		while(temp!=NULL)
		{
		
				cout <<"Reciept Number : "<<temp->order_no ;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->customerName<<endl;
				
				cout<<"Order Date : "<<temp->date<<endl;
				
				cout<<"____________________________________________________________________________"<<endl;
			
				cout << "==========================================================================" << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" Rs"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}
            for( int i = 0 ; i < 14 ; i++)
            {
                temp->total += temp->amount[i];
            }
		    total += temp->total ;
			cout<<"Total Bill is : "<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";
				
			temp=temp->next;
		}
        cout<<"Total Sale : "<<total<<endl;
	}
}		//End daily summary
void Order::exit() //Function to exit
{
	cout<<"\nYou choose to exit.\n"<<endl;
}	 

						      	    ///////////////////////
///////////////////////////////////////////////////////////  THE END OF PROGRAM  ////////////////////////////////////////////////////////////////////
						          ///////////////////////	 
 /* Created by Rakshit Upadhyay*/
 
