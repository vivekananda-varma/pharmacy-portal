#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<windows.h>
#include<string.h>
using namespace std;

#define MONTH 4
#define YEAR 2019

class medicine{
  public:
  	void take_order();
  	void order_not_avail();
  	void add_stock();
  	void modifystock();
  	void searchmedicine();
  	void expiredlist();
  	void orderslist();
  	void transactionlist();
  	void exit();
  	medicine();
};

medicine::medicine()
{
}

struct mode{
    int medid;
    string medicinename;
    int quantity;
    int manfac_year;
    int manfac_month;
    int expire_year;
    int expire_month;
    double medcost;
    string desc;
  struct mode* next;
}*p,*temp1;

struct node{
    int receipt_no;
    int date;
    int month;
    int year;
    string customer_name;
    int quantityc[10];
    string medicinecname[10];
    int medcid[10];
    double medcost[10];
    double total;
    int amount[10];
    int x;
  struct node* next;
}*q,*temp;
node* head = NULL;
mode* headmed = NULL;
int receipt=0;
int main()
{
    system("color 0");
    medicine med;
    FILE *fp1;
    FILE *fp2;
    int i,n1,n2,j;
    fp1=fopen("Give your path here!!!\medicine.txt","rb");
    fp2=fopen("Give your path here!!!\order.txt","rb");
    fseek(fp1,0,SEEK_END);
    fseek(fp2,0,SEEK_END);
    n1=ftell(fp1)/sizeof(struct mode);
    n2=ftell(fp2)/sizeof(struct node);
    struct mode e;
    struct node f;
    fseek(fp1,0,SEEK_SET);
    fseek(fp2,0,SEEK_SET);
    struct mode* temp;
    for(i=0;i<n1;i++)
    {
    temp=new mode;
      fread(&e,sizeof(e),1,fp1);
      temp->medid=e.medid;
      temp->medicinename=e.medicinename;
      temp->manfac_month=e.manfac_month;
      temp->manfac_year=e.manfac_year;
      temp->expire_month=e.expire_month;
      temp->expire_year=e.expire_year;
      temp->quantity=e.quantity;
      temp->desc=e.desc;
      temp->medcost=e.medcost;
      temp->next=NULL;
      if(headmed==NULL)
      {
        headmed=temp;
      }
      else{
        struct mode* temphead=NULL;
        temphead=headmed;
        while(temphead->next!=NULL)
            temphead=temphead->next;
        temphead->next=temp;
        temphead=NULL;
        }
    }
 struct node* temp1;
    for(i=0;i<n2;i++)
    {
      temp1=new node;
      fread(&f,sizeof(f),1,fp2);
      temp1->receipt_no=f.receipt_no;
      temp1->date=f.date;
      temp1->month=f.month;
      temp1->year=f.year;
      temp1->customer_name=f.customer_name;
      temp1->x=f.x;
      for(j=0;j<(temp1->x);j++)
      {
        temp1->medcid[j]=f.medcid[j];
        temp1->medicinecname[j]=f.medicinecname[j];
        temp1->medcost[j]=f.medcost[j];
        temp1->quantityc[j]=f.quantityc[j];
        temp1->amount[j]=f.amount[j];
      }
      temp1->total=f.total;
      temp1->next=NULL;
      if(head==NULL)
      {
        head=temp1;
      }
      else{
        struct node* temphead=NULL;
        temphead=head;
        while(temphead->next!=NULL)
            temphead=temphead->next;
        temphead->next=temp1;
        temphead=NULL;
        }
    }
    fclose(fp1);
    fclose(fp2);
    int menu;
    do
    {
       system("cls");
       cout<<"\t\t\t    Pharmacy Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Search Medicine \t\t\t ||\n";
		cout<<"\t\t||\t3. Add stocks \t ||\n";
		cout<<"\t\t||\t4. Modify/Delete stocks \t\t ||\n";
		cout<<"\t\t||\t5. Expired stock list\t\t\t\t\t ||\n";
		cout<<"\t\t||\t6. Orders list\t\t\t\t\t ||\n";
		cout<<"\t\t||\t7. Transactionlist\t\t\t\t\t ||\n";
		cout<<"\t\t||\t8. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";
        cin>>menu;
        switch(menu)
        {
           case 1:
                  {
                    med.take_order();
                    break;
                  }
            case 3:
                  {
                    med.add_stock();
                    break;
                  }
            case 4:
                  {
                    med.modifystock();
                    break;
                  }
            case 2:
                  {
                    med.searchmedicine();
                    break;
                  }
            case 5:
                  {
                    med.expiredlist();
                    break;
                  }
            case 6:
                  {
                    med.orderslist();
                    break;
                  }
            case 7:
                  {
                    med.transactionlist();
                    break;
                  }
            case 8:
                  {
                    med.exit();
                    goto a;
                    break;
                  }
            default:
                  {
                     cout<<"You entered invalid input!!\n";
                     cout<<"Re-enter the input!!"<<endl;
                     break;
                  }
              }
        }
        while(menu!=9);
        a:
        cout<<"Thankyou"<<endl;
        system("PAUSE");
        return 0;
  }

void medicine::add_stock()
{
    system("cls");
    int i;
    cout<<"Add stock details! "<<endl;
    struct mode* temp;
    temp=new mode;
    cout<<"Enter Medicine ID: ";
    cin>>temp->medid;
    cout<<"Enter medicine name: ";
    cin>>temp->medicinename;
    cout<<"Enter medicine description: ";
    cin>>temp->desc;
     cout<<"Enter manfacturing month: ";
    cin>>temp->manfac_month;
    cout<<"Enter manfacturing year: ";
    cin>>temp->manfac_year;
     cout<<"Enter expiry month: ";
    cin>>temp->expire_month;
    cout<<"Enter expiry year: ";
    cin>>temp->expire_year;
    cout<<"Enter qunatity: ";
    cin>>temp->quantity;
    cout<<"Enter each Medicine Cost: ";
    cin>>temp->medcost;
    temp->next=NULL;
    if(headmed==NULL)
    {
       headmed=temp;
       return;
    }
    else{
        struct mode* temphead=NULL;
        temphead=headmed;
        while(temphead->next!=NULL)
            temphead=temphead->next;
        temphead->next=temp;
        temphead=NULL;
        return;
     }
}

void medicine::take_order(){
 system("cls");
 struct node* temp;
 temp=new node;
 struct mode* temp1;
 int x,i;
 cout<<"Enter no. of medicines required: ";
 cin>>temp->x;
 int totalc=0;
 receipt++;
 temp->receipt_no = receipt;
 cout<<"Enter dd mm yyyy : ";
 cin>>temp->date;
 cin>>temp->month;
 cin>>temp->year;
 cout<<"Enter customer name: ";
 cin>>temp->customer_name;
 for(i=0;i<temp->x;i++){
 temp1=headmed;
 cout<<"Enter medicine id: ";
 cin>> temp->medcid[i];
 while(temp1!=NULL && (temp1->medid!=temp->medcid[i]))
    temp1=temp1->next;
 temp->medicinecname[i]=temp1->medicinename;
 temp->medcost[i]=temp1->medcost;
 cout<<"Enter quantity: ";
 cin>>temp->quantityc[i];
 temp1->quantity=(temp1->quantity)-(temp->quantityc[i]);
 temp->medcost[i]=temp1->medcost;
 temp->amount[i]=(temp->medcost[i])*(temp->quantityc[i]);
 totalc=totalc+(temp->amount[i]);
 }
temp->total=totalc;
cout<<endl;
cout<<"REVIEW ORDER!!!";
cout<<endl;
cout<<"Receipt number is: "<<temp->receipt_no<<endl;
cout<<"Customer name is: "<<temp->customer_name<<endl;
cout<<"Date is dd/mm/yyyy: "<<temp->date<<"/"<<temp->month<<"/"<<temp->year<<endl;
cout<<"medicine ID | medicine name | Quantity | cost | amount |"<<endl;
for(i=0;i<temp->x;i++)
    cout<<temp->medcid[i]<<" "<<temp->medicinecname[i]<<" "<<temp->quantityc[i]<<" "<<temp->medcost[i]<<" "<<temp->amount[i]<<endl;
cout<<"//////////////////////////"<<endl;
cout<<"TOTAL AMOUNT TO BE PAID : "<<temp->total<<endl;
cout<<"//////////////////////////"<<endl;
system("PAUSE");
temp->next=NULL;
if(head==NULL)
    {
       head=temp;
       return;
    }
    else{
        struct node* temphead=NULL;
        temphead=head;
        while(temphead->next!=NULL)
            temphead=temphead->next;
        temphead->next=temp;
        temphead=NULL;
        return;
     }
}

void medicine::modifystock(){
  system("cls");
  cout<<"MODIFY STOCK DETAILS!"<<endl;
  struct mode* temp;
  temp=headmed;
  int id;
  cout<<"Enter medicine ID to modify: ";
  cin>>id;
  while(temp != NULL && temp->medid != id)
      temp=temp->next;
   if(temp==NULL)
   {
     cout<<"Medicine details not found!!!";
     return;
   }
   else{
      cout<<"modifying medicine name is: "<<temp->medicinename<<endl;
      cout<<"Enter new manfacture month: ";
      cin>>temp->manfac_month;
      cout<<"Enter new manfacture year: ";
      cin>>temp->manfac_year;
      cout<<"Enter new expiry month: ";
      cin>>temp->manfac_month;
      cout<<"Enter new expiry year: ";
      cin>>temp->expire_year;
      cout<<"Enter new quantity: ";
      cin>>temp->quantity;
    return;
   }
}

void medicine::searchmedicine(){
 system("cls");
 struct mode* temp;
 temp=headmed;
 int id;
 cout<<"Enter ID to search: "<<endl;
 cin>>id;
 cout<<"MedicineID|medicine_name|manfacture_year|expiry_year|quantity|cost(RS/-)|"<<endl;
 while(temp!=NULL && temp->medid==id){
    cout<<temp->medid<<"  ";
    cout<<temp->medicinename<<"  ";
    cout<<temp->manfac_month<<"/";
    cout<<temp->manfac_year<<"  ";
    cout<<temp->expire_month<<"/";
    cout<<temp->expire_year<<"  ";
    cout<<temp->quantity<<"  ";
    cout<<temp->medcost<<"  ";
    temp=temp->next;
    cout<<endl;
  }
  system("PAUSE");
  return;
}

void medicine::expiredlist(){
  system("cls");
  cout<<"EXPIRED MEDICINE LIST"<<endl;
  struct mode* temp;
  temp=headmed;
  cout<<"MedicineID|expiry_month|expiry_year|quantity|"<<endl;
  while(temp!=NULL && (temp->expire_month <= MONTH) && (temp->expire_year <= YEAR))
  {
    cout<<temp->medid<<"  ";
    cout<<temp->expire_month<<"  ";
    cout<<temp->expire_year<<"  ";
    cout<<temp->quantity<<"  ";
    temp=temp->next;
    cout<<endl;
  }
  system("PAUSE");
  return;
}

void medicine::orderslist(){
 int dd,mm,yy;
 struct node* temp;
 temp=head;
 int i;
 cout<<"Enter date dd/mm/yyyy: ";
 cin>>dd>>mm>>yy;
 while(temp!=NULL && (temp->date==dd) && (temp->month==mm) && (temp->year==yy)){
    int y=temp->x;
    cout<<"Receipt no: "<<temp->receipt_no<<endl;
    cout<<"customer name: "<<temp->customer_name<<endl;
    cout<<"Total items: "<<temp->x<<endl;
    cout<<"medicine ID | medicine name | Quantity | cost | amount |"<<endl;
    for(i=0;i<temp->x;i++)
    {
    cout<<temp->medcid[i]<<" "<<temp->medicinecname[i]<<" "<<temp->quantityc[i]<<" "<<temp->medcost[i]<<" "<<temp->amount[i]<<endl;
    }
    cout<<"Total amount paid is: "<<temp->total<<endl;
    temp=temp->next;
 }
 system("PAUSE");
 return;
}

void medicine::transactionlist(){
 int dd,mm,yy;
 struct node* temp;
 temp=head;
 cout<<"Enter date dd/mm/yyyy: ";
 cin>>dd>>mm>>yy;
 cout<<"Receipt_No | Total_items | Total_Amount"<<endl;
 while(temp!=NULL && (temp->date==dd) && (temp->month==mm) && (temp->year==yy)){
    cout<<temp->receipt_no<<"   "<<temp->x<<"   "<<temp->total<<endl;
    temp=temp->next;
 }
 system("PAUSE");
 return;
}

void medicine::exit(){
 system("cls");
 cout<<"SAVING DATA........"<<endl;
 FILE* fp1;
 fp1=fopen("C:\\Users\\saripella vivekanand\\Desktop\\medicine.txt","wb");
 struct mode e;
 struct mode* temp1;
 temp1=headmed;
 while(temp1!=NULL)
 {
   e.medid=temp1->medid;
   e.medicinename=temp1->medicinename;
   e.manfac_month=temp1->manfac_month;
   e.manfac_year=temp1->manfac_year;
   e.expire_month=temp1->expire_month;
   e.expire_year=temp1->expire_year;
   e.quantity=temp1->quantity;
   e.desc=temp1->desc;
   e.medcost=temp1->medcost;
   temp1=temp1->next;
   fwrite(&e,sizeof(e),1,fp1);
   fclose(fp1);
 }
FILE* fp2;
 fp2=fopen("C:\\Users\\saripella vivekanand\\Desktop\\order.txt","wb");
 struct node f;
 struct node* temp2;
 temp2=head;
 int i,k;
 while(temp2!=NULL)
 {
  f.receipt_no=temp2->receipt_no;
  f.date=temp2->date;
  f.month=temp2->month;
  f.year=temp2->year;
  f.customer_name=temp2->customer_name;
  f.x=temp2->x;
  for(i=0;i<(temp2->x);i++)
  {
    f.medcid[i]=temp2->medcid[i];
    f.medicinecname[i]=temp2->medicinecname[i];
    f.quantityc[i]=temp2->quantityc[i];
    f.medcost[i]=temp2->medcost[i];
    f.amount[i]=temp2->amount[i];
  }
  f.total = temp2->total;
  temp2=temp2->next;
  fwrite(&f,sizeof(f),1,fp2);
  fclose(fp2);
 }
cout<<"DATA SAVED SUCCESSFULLY!!!";
  return;
}

