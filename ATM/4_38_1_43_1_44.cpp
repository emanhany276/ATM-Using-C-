#include<iostream>
#include<limits>
using namespace std;

int accounts_num=0;
class ATM
{
private:
    char account_name[101];
    char card_number[11];
    double amount;

public:
    void create_new_acc();
    void deposit();
    void transfer();
    void withdrawl();
    void print_acc_data();
}*acc_ptr=new ATM[accounts_num];

int main()
{
    ATM used_acc;
    char num_operation[2];
    label:
    cout<<"1----Create new account"<<endl;
    cout<<"2----Deposit"<<endl;
    cout<<"3----Transfer to another account"<<endl;
    cout<<"4----Withdrawal"<<endl;
    cout<<"5----Exit"<<endl;

    cout<<"please enter the number of operation: ";
    cin.getline(num_operation,2);
    if(cin.fail())   {cin.clear();    cin.ignore(numeric_limits<streamsize>::max(),'\n'); cout<<"Longer than expected."<<endl;  goto label;}

     switch(num_operation[0])
{

    case '1':{accounts_num++;
           (acc_ptr+accounts_num-1)->create_new_acc();   goto label;}
    case '2':{used_acc.deposit();
           goto label;}
    case '3':{used_acc.transfer();
           goto label;}
    case '4':{used_acc.withdrawl();
           goto label;}
    case '5': return 0;
    default :{cout<<"Invalid number."<<endl;
              goto label;}
}

}

/*Creation function is used to create new accounts  take the account name which has to be English letters or spaces only it also can't start with space
or be empty. The card number which consists of 10 numbers that can't be the same as any existing card number, can't all be the same number,
and can't be shorter or longer than 10 numbers.*/
void ATM::create_new_acc()
{
    int k;
    label1:
    cout<<"Please enter the account name: ";
    cin.getline(account_name,101);
    if(cin.fail())
      {cin.clear();     cin.ignore(numeric_limits<streamsize>::max(),'\n');  cout<<"Longer than expected."<<endl;  goto label1; }
      if(account_name[0]=='\0')  {cout<<"No name has been entered."<<endl;   goto label1;}
      if(account_name[0]==' ')   {cout<<"The name can't start with space."<<endl;    goto label1;}
    cout<<endl;
     for(int i=0;i<100&&account_name[i]!='\0';i++)
      if(((int(account_name[i])>=97&&int(account_name[i])<=122)||(int(account_name[i])>=65&&int(account_name[i])<=90))!=1&&account_name[i]!=' ')
       {cout<<"Invalid account name, it must consist of letters or spaces only."<<endl;   goto label1;}
       label2:
   cout<<"Please enter the account number(10 numbers): ";
    cin.getline(card_number,11);
     if(cin.fail())
       {cin.clear();    cin.ignore(numeric_limits<streamsize>::max(),'\n');  cout<<"Longer than expected."<<endl;  goto label2;}
      if(int(card_number[9])==0) {cout<<"Shorter than expected"<<endl;    goto label2;}
      for(int i=0,count=0;i<10;i++)
       {if(int(card_number[i])==int(card_number[i+1]))   count++;
    if(count==9)     {cout<<"Invalid as a card number, card number can't all be the same number."<<endl; goto label2;}}
    for(int j=0;j<accounts_num-1;j++)
    {for(k=0;k<10;k++)
        if(card_number[k]!=(acc_ptr+j)->card_number[k]) break;
    if(k==10)
    {cout<<"Invalid account number."<<endl;    goto label2;}}
    for(int i=0; i<10; i++)
            if(!(int(card_number[i])<=57&&int(card_number[i])>=48)||card_number[i]=='o')
             {cout<<"Invalid account number, it should include only numbers."<<endl;    goto label2;}

    amount=0;
    print_acc_data();
}

/*The deposition function is used to deposit any amount of money to the account and adds 1% of the amount added by the user.
It can't be called unless the creation function is called one time at least and makes sure that the entered account does exist.
To leave it without changing any thing just enter zero on asking for the amount.*/
void ATM::deposit()
{
    if(accounts_num==0) cout<<"You have no accounts."<<endl;
    else
    {
    int j,i;
    label3:
    cout<<endl<<"Please enter the account number(10 numbers): ";
    cin.getline(card_number,11);
     if(cin.fail())
       {cin.clear();    cin.ignore(numeric_limits<streamsize>::max(),'\n');      cout<<"Longer than expected.";  goto label3;}
    for(j=0;j<accounts_num;j++)
        {for(i=0; i<10; i++)
    if(card_number[i]!=(acc_ptr+j)->card_number[i]) break;
    if(i==10) break;}
    if(j>=accounts_num)
        {cout<<"That account does not exist."<<endl;   goto label3;}
    else
    {
        label0:
        cout<<endl<<"Please enter the amount to be deposited: ";
        cin>>amount;
        if(cin.fail()||amount<0||(cin.peek()!='\n'))
            {cin.clear();   cin.ignore(numeric_limits<streamsize>::max(),'\n');  cout<<"Invalid as amount."<<endl;    goto label0;}
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
        (acc_ptr+j)->amount+=1.01*amount;
        (acc_ptr+j)->print_acc_data();

    }
    }
}

/*Transformation function is used to transfer amount of money from the sending account to the receiving account and deducing 1.5% from both accounts,
it can't be called unless the creation function is called 2 times at least,it makes sure that enter card numbers do really exist, if the user entered amount
larger than that can be transfered from his account it tells him the largest amount can be transfered, user can go out from it without changing any thing
by entering zero when asked about the amount.*/
void ATM::transfer()
{
    int j,k,i;
    if(accounts_num<2)   cout<<"You must create at least 2 accounts."<<endl;
    else
    {
        label4:
    cout<<"Please enter the number of the sending account(10 numbers): ";
    cin.getline(card_number,11);
     if(cin.fail())
       {cin.clear();       cin.ignore(numeric_limits<streamsize>::max(),'\n');  cout<<"Longer than expected.";  goto label4;}
    for(j=0;j<accounts_num;j++)
        {for(i=0; i<10; i++)
    if(card_number[i]!=(acc_ptr+j)->card_number[i]) break;
    if(i==10) break;}
    if(j>=accounts_num) {cout<<"That account does not exist."<<endl;   goto label4;}
    else
    {
        label5:
        cout<<endl<<"Please enter the number of the receiving account(10 numbers): ";
        cin.getline(card_number,11);
     if(cin.fail())
       {cin.clear();       cin.ignore(numeric_limits<streamsize>::max(),'\n');   cout<<"Longer than expected.";  goto label5;}
        for(k=0;k<accounts_num;k++)
        {for(i=0; i<10; i++)
    if(card_number[i]!=(acc_ptr+k)->card_number[i]) break;
    if(i==10) break;}
        if(k>=accounts_num) {cout<<endl<<"That account does not exist."<<endl;    goto label5;}
        else
        {
            if(k==j)   {cout<<"Can't transfer to the same account."<<endl;    goto label5;}
            label0:
            cout<<"Please enter the amount to be transferred: ";
            cin>>amount;
            if(cin.fail()||amount<0||(cin.peek()!='\n'))
                {cin.clear();   cin.ignore(numeric_limits<streamsize>::max(),'\n'); cout<<"Invalid as amount."<<endl;   goto label0;}
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if(amount*1.015>(acc_ptr+j)->amount)
                {cout<<"Invalid amount."<<endl;     cout<<"The largest amount you can withdraw = "<< int((acc_ptr+j)->amount/1.015)<<endl;   goto label0;}
            else
            {
                (acc_ptr+j)->amount-=amount*1.015;
                (acc_ptr+k)->amount+=amount*0.985;
                cout<<endl<<"Sending account:"<<endl;
                (acc_ptr+j)->print_acc_data();
                cout<<endl<<"Receiving account:"<<endl;
                (acc_ptr+k)->print_acc_data();
            }
            }
    }
    }
}

/*Withdrawal function is used to withdraw money from some account, it deduces extra 3% from the amount withdrawn from the account, it can't be called unless
the creation function is called one time at least, it makes sure that the entered card number does really exist, if the user entered amount largest that can
be withdrawn it tells him the largest amount can be withdrawn, user can go out from it without changing any thing by entering zero when asked for the amount.*/
void ATM::withdrawl()
{
    if(accounts_num==0) cout<<"You have no accounts."<<endl;
    else
    {
    int j,i;
    label6:
    cout<<"Please enter the number of the sending account(10 numbers): ";
    cin.getline(card_number,11);
     if(cin.fail())
       {cin.clear();     cin.ignore(numeric_limits<streamsize>::max(),'\n');     cout<<"Longer than expected.";  goto label6;}
    for(j=0;j<accounts_num;j++)
        {for(i=0; i<10; i++)
    if(card_number[i]!=(acc_ptr+j)->card_number[i]) break;
    if(i==10) break;}
    if(j>=accounts_num)    {cout<<"That account does not exist."<<endl;  goto label6;}
    else
    {
        label0:
        cout<<endl<<"Please enter the amount to be withdrawn: ";
        cin>>amount;
        if(cin.fail()||amount<0||(cin.peek()!='\n'))
            {cin.clear();    cout<<"Invalid as amount."<<endl;   cin.ignore(numeric_limits<streamsize>::max(),'\n');   goto label0;}
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if(amount*1.03>(acc_ptr+j)->amount)
            {cout<<endl<<"Invalid amount."<<endl;   cout<<"The largest amount you can withdraw = "<< int((acc_ptr+j)->amount/1.03)<<endl; goto label0;}
        else
        {
            (acc_ptr+j)->amount-=amount*1.03;
            (acc_ptr+j)->print_acc_data();
        }
    }
    }
}

//Print function is called at the end of each of the other functions to give the information of the accounts changed inside the functions.
void ATM::print_acc_data()
{
    cout<<endl<<"Name: "<<account_name<<endl;
    cout<<"Card number: ";
    for(int i=0; i<10; i++) cout<<card_number[i];
    cout<<endl<<"Amount: "<<amount<<endl;
}
