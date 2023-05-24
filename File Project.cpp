#include<iostream>
#include<string>
#include<fstream>
void info()
{
    int number,age;
    std::string name,birthdate,cnic,gender,filename;
    double amount;
    std::cout<<"Enter Number to Assign to Account:"<<std::endl;
    std::cin>>number;
    std::cin.ignore();
    std::cout<<"Enter Name:"<<std::endl;
    getline(std::cin,name);
    std::cin.ignore();
    std::cout<<"Enter Age:"<<std::endl;
    std::cin>>age;
    std::cout<<"Enter Date of Birth(day/month/year):"<<std::endl;
    std::cin>>birthdate;
    std::cout<<"Enter CNIC:"<<std::endl;
    std::cin>>cnic;
    std::cout<<"Enter Gender:"<<std::endl;
    std::cin>>gender;
    std::cout<<"Enter Amount to deposit:"<<std::endl;
    std::cin>>amount;
    std::cout<<"Enter FileName to Save in:"<<std::endl;
    std::cin>>filename;
    std::ofstream fileholder(filename.c_str());
    fileholder<<"Account Number = "<<number<<std::endl;
    fileholder<<"Customer Name = "<<name<<std::endl;
    fileholder<<"Customer Age = "<<age<<std::endl;
    fileholder<<"Customer Date of Birth = "<<birthdate<<std::endl;
    fileholder<<"Customer Gender = "<<gender<<std::endl;
    fileholder<<"Customer CNIC = "<<cnic<<std::endl;
    fileholder<<"Balance = "<<amount<<std::endl;
    fileholder.close();
    std::ofstream fileholder3("FileNames.txt",std::ios::app);
    fileholder3<<filename<<std::endl;
    fileholder3.close();
}
void displayCustomers()
{
    std::string sub,sub2;
    std::ifstream fileholder("FileNames.txt");
    while(getline(fileholder,sub))
    {
    	std::ifstream fileholder2(sub.c_str());
    	while(getline(fileholder2,sub2))
    	{
    		std::cout<<sub2<<std::endl;
		}
		std::cout<<std::endl;
		fileholder2.close();
	}
	fileholder.close();
}

void RemainingDelete2(const std::string filename)
{
	std::ifstream fileholder("FileNames.txt");
	std::ofstream fileholder2("Sub2file.txt");
	std::string sub;
	while(getline(fileholder,sub))
	{
		if(filename != sub)
		{
			fileholder2<<sub<<std::endl;
		}
	}
	fileholder.close();
	fileholder2.close();
	std::ifstream fileholder3("Sub2file.txt");
	std::ofstream fileholder4("FileNames.txt");
	sub="";
	while(getline(fileholder3,sub))
	{
		fileholder4<<sub<<std::endl;
	}
	fileholder3.close();
	fileholder4.close();
	std::remove("Sub2file.txt");
}
void DeleteAccount()
{
	std::string sub,sub2,number,number2,filename;
	int confirm=0;
	std::cout<<"Enter Account Number:"<<std::endl;
	std::cin>>number;
	number2=number;
	number="Account Number = "+number;
	std::ifstream fileholder("FileNames.txt");
	while(getline(fileholder,sub))
	{
		std::ifstream fileholder2(sub.c_str());
		while(getline(fileholder2,sub2))
		{
			if(sub2.compare(number)==0)
			{
				confirm=1;
			}
		}
		sub2="";
		fileholder2.close();
		if(confirm==1)
		{
		filename=sub;
		std::remove(sub.c_str());
		confirm=0;	
		}
	}
	RemainingDelete2(filename);
	fileholder.close();
}
void UpdateBalance()
{
	std::string sub,number,CurrentAmount,sub2,filename,sub3;
	int confirm=0,location=0,deposit,amount=0,proceed=0;
	std::cout<<"Enter Account Number:"<<std::endl;
	std::cin>>number;
	number="Account Number = "+number;
	std::ifstream fileholder("FileNames.txt");
	while(getline(fileholder,sub))
	{
		std::ifstream fileholder1(sub.c_str());
		while(getline(fileholder1,sub3))
		{
			if(sub3==number)
			{
				filename=sub;
				break;
			}
		}
	}
	std::ifstream fileholder2(filename.c_str());
	std::ofstream fileholder3("financeSub.txt");
	std::cout<<"Enter Amount to Deposit:"<<std::endl;
	std::cin>>deposit;
	while(getline(fileholder2,sub))
	{
		if(sub==number)
		{
			confirm=1;
		}
		if(confirm==1 && sub.find("Balance")==std::string::npos)
		{
			fileholder3<<sub<<std::endl;
		}
		else if(confirm==1 && sub.find("Balance") != std::string::npos)
		{
			for(int i=0;i<sub.length();i++)
			{
				if(sub[i]=='0' || sub[i]=='1' || sub[i]=='2' || sub[i]=='3' || sub[i]=='4' || sub[i]=='5' || sub[i]=='6' || sub[i]=='7' || sub[i]=='8' || sub[i]=='9')
				{
					CurrentAmount+=sub[i];
				}                   
			}
			for(int i=0;i<CurrentAmount.length();i++)
			{
				if(CurrentAmount[i]=='0')
				{
					amount=(amount*10)+0;
				}
				else if(CurrentAmount[i]=='1')
				{
					amount=(amount*10)+1;
				}
				else if(CurrentAmount[i]=='2')
				{
					amount=(amount*10)+2;
				}
				else if(CurrentAmount[i]=='3')
				{
					amount=(amount*10)+3;
				}
				else if(CurrentAmount[i]=='4')
				{
					amount=(amount*10)+4;
				}
				else if(CurrentAmount[i]=='5')
				{
					amount=(amount*10)+5;
				}
				else if(CurrentAmount[i]=='6')
				{
					amount=(amount*10)+6;
				}
				else if(CurrentAmount[i]=='7')
				{
					amount=(amount*10)+7;
				}
				else if(CurrentAmount[i]=='8')
				{
					amount=(amount*10)+8;
				}
				else if(CurrentAmount[i]=='9')
				{
					amount=(amount*10)+9;
				}
			}
			amount+=deposit;
			fileholder3<<"Balance = "<<amount<<std::endl;
			confirm=0;
			proceed=1;
		}
	}
	fileholder2.close();
	fileholder3.close();
	if(proceed==1)
	{
	std::ofstream fileholder4(filename.c_str());
	std::ifstream fileholder5("financeSub.txt");
	while(getline(fileholder5,sub2))
	{
		fileholder4<<sub2<<std::endl;
	}
	fileholder4.close();
	fileholder5.close();
	}
	std::remove("financeSub.txt");
}
void UpdateBalance2()
{
	std::string sub,number,CurrentAmount,sub2,filename,sub3;
	int confirm=0,location=0,withdraw,amount=0,proceed=0;
	std::cout<<"Enter Account Number:"<<std::endl;
	std::cin>>number;
	number="Account Number = "+number;
	std::ifstream fileholder("FileNames.txt");
	while(getline(fileholder,sub))
	{
		std::ifstream fileholder1(sub.c_str());
		while(getline(fileholder1,sub3))
		{
			if(sub3==number)
			{
				filename=sub;
				break;
			}
		}
	}
	std::ifstream fileholder2(filename.c_str());
	std::ofstream fileholder3("financeSub.txt");
	std::cout<<"Enter Amount to Withdraw:"<<std::endl;
	std::cin>>withdraw;
	while(getline(fileholder2,sub))
	{
		if(sub==number)
		{
			confirm=1;
		}
		if(confirm==1 && sub.find("Balance")==std::string::npos)
		{
			fileholder3<<sub<<std::endl;
		}
		else if(confirm==1 && sub.find("Balance") != std::string::npos)
		{
			for(int i=0;i<sub.length();i++)
			{
				if(sub[i]=='0' || sub[i]=='1' || sub[i]=='2' || sub[i]=='3' || sub[i]=='4' || sub[i]=='5' || sub[i]=='6' || sub[i]=='7' || sub[i]=='8' || sub[i]=='9')
				{
					CurrentAmount+=sub[i];
				}                   
			}
			for(int i=0;i<CurrentAmount.length();i++)
			{
				if(CurrentAmount[i]=='0')
				{
					amount=(amount*10)+0;
				}
				else if(CurrentAmount[i]=='1')
				{
					amount=(amount*10)+1;
				}
				else if(CurrentAmount[i]=='2')
				{
					amount=(amount*10)+2;
				}
				else if(CurrentAmount[i]=='3')
				{
					amount=(amount*10)+3;
				}
				else if(CurrentAmount[i]=='4')
				{
					amount=(amount*10)+4;
				}
				else if(CurrentAmount[i]=='5')
				{
					amount=(amount*10)+5;
				}
				else if(CurrentAmount[i]=='6')
				{
					amount=(amount*10)+6;
				}
				else if(CurrentAmount[i]=='7')
				{
					amount=(amount*10)+7;
				}
				else if(CurrentAmount[i]=='8')
				{
					amount=(amount*10)+8;
				}
				else if(CurrentAmount[i]=='9')
				{
					amount=(amount*10)+9;
				}
			}
			if(withdraw>amount)
			{
				std::cout<<"Withdraw Amount Exceeds Balance"<<std::endl;
				proceed=0;
			}
			else if(withdraw<=amount)
			{
				proceed=1;
				amount-=withdraw;
				fileholder3<<"Balance = "<<amount<<std::endl;
			}
			confirm=0;
		}
	}
	fileholder2.close();
	fileholder3.close();
	if(proceed==1)
	{
	std::ofstream fileholder4(filename.c_str());
	std::ifstream fileholder5("financeSub.txt");
	while(getline(fileholder5,sub2))
	{
		fileholder4<<sub2<<std::endl;
	}
	fileholder4.close();
	fileholder5.close();
	}
	std::remove("financeSub.txt");
}
void Display()
{
	std::string number,sub,sub2,filename,sub3;
	int breaker=0;
	std::ifstream fileholder("FileNames.txt");
	std::cout<<"Enter Account Number:"<<std::endl;
	std::cin>>number;
	number="Account Number = "+number;
	while(getline(fileholder,sub))
	{
		std::ifstream fileholder2(sub.c_str());
		while(getline(fileholder2,sub2))
		{
			if(sub2==number)
			{
				filename=sub;
				breaker=1;
				break;
			}
		}
		if(breaker==1)
		{
			break;
		}
		fileholder2.close();
	}
	fileholder.close();
	std::ifstream fileholder3(filename.c_str());
	while(getline(fileholder3,sub3))
	{
		std::cout<<sub3<<std::endl;
	}
}
void UpdateInfo()
{
	std::string number,sub,sub2,filename;
	int breaker=0;
	std::cout<<"Enter Account Number:"<<std::endl;
	std::cin>>number;
	number="Account Number = "+number;
	std::ifstream fileholder("FileNames.txt");
	while(getline(fileholder,sub))
	{
		std::ifstream fileholder2(sub.c_str());
		while(getline(fileholder2,sub2))
		{
			if(sub2==number)
			{
				filename=sub;
				breaker=1;
			}
		}
		if(breaker==1)
		{
			break;
		}
		fileholder2.close();
	}
	fileholder.close();
	system("cls");
	int choice;
	std::cout<<"1.Customer Name"<<std::endl;
	std::cout<<"2.Customer Age"<<std::endl;
	std::cout<<"3.Customer Gender"<<std::endl;
	std::cout<<"4.Customer CNIC"<<std::endl;
	std::cout<<"5.Balance"<<std::endl;
	std::cout<<"Choose what you wish to update:"<<std::endl;
	std::cin>>choice;
	if(choice==1)
	{
		std::string n,sub3,sub4;
		std::cin.ignore();
		std::cout<<"Enter New Name:"<<std::endl;
		getline(std::cin,n);
		std::ifstream fileholder3(filename.c_str());
		std::ofstream fileholder4("sub.txt");
		while(getline(fileholder3,sub3))
		{
			if(sub3.find("Customer Name") != std::string::npos)
			{
				fileholder4<<"Customer Name = "<<n<<std::endl;
			}
			else
			{
				fileholder4<<sub3<<std::endl;
			}
		}
		fileholder4.close();
		fileholder3.close();
		std::ifstream fileholder5("sub.txt");
		std::ofstream fileholder6(filename.c_str());
		while(getline(fileholder5,sub4))
		{
			fileholder6<<sub4<<std::endl;
		}
		fileholder6.close();
		fileholder5.close();
		std::remove("sub.txt");
	}
	else if(choice==2)
	{
		std::string n,sub3,sub4;
		std::cout<<"Enter New Age:"<<std::endl;
		std::cin>>n;
		std::ifstream fileholder3(filename.c_str());
		std::ofstream fileholder4("sub.txt");
		while(getline(fileholder3,sub3))
		{
			if(sub3.find("Customer Age") != std::string::npos)
			{
				fileholder4<<"Customer Age = "<<n<<std::endl;
			}
			else
			{
				fileholder4<<sub3<<std::endl;
			}
		}
		fileholder4.close();
		fileholder3.close();
		std::ifstream fileholder5("sub.txt");
		std::ofstream fileholder6(filename.c_str());
		while(getline(fileholder5,sub4))
		{
			fileholder6<<sub4<<std::endl;
		}
		fileholder6.close();
		fileholder5.close();
		std::remove("sub.txt");
	}
	else if(choice==3)
	{
		std::string n,sub3,sub4;
		std::cout<<"Enter New gender:"<<std::endl;
		std::cin>>n;
		std::ifstream fileholder3(filename.c_str());
		std::ofstream fileholder4("sub.txt");
		while(getline(fileholder3,sub3))
		{
			if(sub3.find("Customer Gender") != std::string::npos)
			{
				fileholder4<<"Customer Gender = "<<n<<std::endl;
			}
			else
			{
				fileholder4<<sub3<<std::endl;
			}
		}
		fileholder4.close();
		fileholder3.close();
		std::ifstream fileholder5("sub.txt");
		std::ofstream fileholder6(filename.c_str());
		while(getline(fileholder5,sub4))
		{
			fileholder6<<sub4<<std::endl;
		}
		fileholder6.close();
		fileholder5.close();
		std::remove("sub.txt");
	}
	else if(choice==4)
	{
		std::string n,sub3,sub4;
		std::cout<<"Enter New CNIC:"<<std::endl;
		std::cin>>n;
		std::ifstream fileholder3(filename.c_str());
		std::ofstream fileholder4("sub.txt");
		while(getline(fileholder3,sub3))
		{
			if(sub3.find("Customer CNIC") != std::string::npos)
			{
				fileholder4<<"Customer CNIC = "<<n<<std::endl;
			}
			else
			{
				fileholder4<<sub3<<std::endl;
			}
		}
		fileholder4.close();
		fileholder3.close();
		std::ifstream fileholder5("sub.txt");
		std::ofstream fileholder6(filename.c_str());
		while(getline(fileholder5,sub4))
		{
			fileholder6<<sub4<<std::endl;
		}
		fileholder6.close();
		fileholder5.close();
		std::remove("sub.txt");
	}
	else if(choice==5)
	{
		std::string n,sub3,sub4;
		std::cout<<"Enter New Balance:"<<std::endl;
		std::cin>>n;
		std::ifstream fileholder3(filename.c_str());
		std::ofstream fileholder4("sub.txt");
		while(getline(fileholder3,sub3))
		{
			if(sub3.find("Balance") != std::string::npos)
			{
				fileholder4<<"Balance = "<<n<<std::endl;
			}
			else
			{
				fileholder4<<sub3<<std::endl;
			}
		}
		fileholder4.close();
		fileholder3.close();
		std::ifstream fileholder5("sub.txt");
		std::ofstream fileholder6(filename.c_str());
		while(getline(fileholder5,sub4))
		{
			fileholder6<<sub4<<std::endl;
		}
		fileholder6.close();
		fileholder5.close();
		std::remove("sub.txt");
	}
}
void Transaction()
{
	std::string number1,number2,file,file2,filename,file1,file3,filename2;
	int breaker=0,count1=0,count2=0;
	std::cout<<"Enter Account Number(Sender):"<<std::endl;
	std::cin>>number1;
	std::cout<<"Enter Account Number to which you want to send Money:"<<std::endl;
	std::cin>>number2;
	if(number1==number2)
	{
		std::cout<<"Same Account Error"<<std::endl;
	}
	else if(number1 !=number2)
	{
	std::ifstream fileholder("FileNames.txt");
	number1="Account Number = "+number1;
	number2="Account Number = "+number2;
	while(getline(fileholder,file))
	{
		std::ifstream fileholder1(file.c_str());
		while(getline(fileholder1,file2))
		{
			if(file2==number1)
			{
				filename=file;
				count1=1;
				breaker=1;
			}
		}
		if(breaker==1)
		{
			breaker=0;
			break;
		}
		fileholder1.close();
	}
	fileholder.close();
	std::ifstream fileholder2("FileNames.txt");
	while(getline(fileholder2,file1))
	{
		std::ifstream fileholder3(file1.c_str());
		while(getline(fileholder3,file3))
		{
			if(number2==file3)
			{
				filename2=file1;
				count2=1;
				breaker=1;
			}
		}
		if(breaker==1)
		{
			breaker=0;
			break;
		}
		fileholder3.close();
	}
	fileholder2.close();
	if(count1==1 && count2==1)
	{
	std::string sub,sub2,sub3,sub4;
	int amount,balance1=0,balance2=0,confirm=0;
	std::cout<<"Enter Amount to Transfer:"<<std::endl;
	std::cin>>amount;
	std::ifstream fileholder11(filename.c_str());
	std::ofstream fileholder4("sub1.txt");
	while(getline(fileholder11,sub))
	{
		if(sub.find("Balance") != std::string::npos)
		{
			for(int i=0;i<sub.length();i++)
			{
				if(sub[i]=='0')
				{
					balance1=(balance1*10)+0;
				}
				else if(sub[i]=='1')
				{
					balance1=(balance1*10)+1;
				}
				else if(sub[i]=='2')
				{
					balance1=(balance1*10)+2;
				}
				else if(sub[i]=='3')
				{
					balance1=(balance1*10)+3;
				}
				else if(sub[i]=='4')
				{
					balance1=(balance1*10)+4;
				}
				else if(sub[i]=='5')
				{
					balance1=(balance1*10)+5;
				}
				else if(sub[i]=='6')
				{
					balance1=(balance1*10)+6;
				}
				else if(sub[i]=='7')
				{
					balance1=(balance1*10)+7;
				}
				else if(sub[i]=='8')
				{
					balance1=(balance1*10)+8;
				}
				else if(sub[i]=='9')
				{
					balance1=(balance1*10)+9;
				}
			}
			if(balance1<amount)
			{
				std::cout<<"Withdraw Amount Exceeds Balance"<<std::endl;
				fileholder4<<sub<<std::endl;
				confirm=1;
			}
			else if(balance1>=amount)
			{
			balance1-=amount;
			fileholder4<<"Balance = "<<balance1<<std::endl;
			}
		}
		else
		{
			fileholder4<<sub<<std::endl;
		}
	}
	fileholder11.close();
	fileholder4.close();
	std::ifstream fileholder5("sub1.txt");
	std::ofstream fileholder6(filename.c_str());
	while(getline(fileholder5,sub2))
	{
		fileholder6<<sub2<<std::endl;
	}
	fileholder5.close();
	fileholder6.close();
	std::remove("sub1.txt");
	std::ifstream fileholder7(filename2.c_str());
	std::ofstream fileholder8("sub2.txt");
	while(getline(fileholder7,sub3))
	{
		if(sub3.find("Balance") != std::string::npos)
		{
			for(int i=0;i<sub3.length();i++)
			{
				if(sub3[i]=='0')
				{
					balance2=(balance2*10)+0;
				}
				else if(sub3[i]=='1')
				{
					balance2=(balance2*10)+1;
				}
				else if(sub3[i]=='2')
				{
					balance2=(balance2*10)+2;
				}
				else if(sub3[i]=='3')
				{
					balance2=(balance2*10)+3;
				}
				else if(sub3[i]=='4')
				{
					balance2=(balance2*10)+4;
				}
				else if(sub3[i]=='5')
				{
					balance2=(balance2*10)+5;
				}
				else if(sub3[i]=='6')
				{
					balance2=(balance2*10)+6;
				}
				else if(sub3[i]=='7')
				{
					balance2=(balance2*10)+7;
				}
				else if(sub3[i]=='8')
				{
					balance2=(balance2*10)+8;
				}
				else if(sub3[i]=='9')
				{
					balance2=(balance2*10)+9;
				}
			}
			if(confirm==0)
			{
			balance2+=amount;
			fileholder8<<"Balance = "<<balance2<<std::endl;
			}
			else if(confirm==1)
			{
				fileholder8<<sub3<<std::endl;
				confirm=0;
			}
		}
		else
		{
			fileholder8<<sub3<<std::endl;
		}
	}
	fileholder7.close();
	fileholder8.close();
	std::ifstream fileholder9("sub2.txt");
	std::ofstream fileholder10(filename2.c_str());
	while(getline(fileholder9,sub4))
	{
		fileholder10<<sub4<<std::endl;
	}
	fileholder9.close();
	fileholder10.close();
	std::remove("sub2.txt");
	count1=0;
	count2=0;
}
else 
{
	std::cout<<"Error! One of the Account is not Actual"<<std::endl;
}
}
}
int main()
{
    int choice;
while(1)
{
	std::cout<<"1.NEW ACCOUNT"<<std::endl;
	std::cout<<"2.DELETE ACCOUNT"<<std::endl;
	std::cout<<"3.CUSTOMERS LIST"<<std::endl;
	std::cout<<"4.DEPOSIT AMOUNT TO ACCOUNT"<<std::endl;
	std::cout<<"5.WITHDRAW AMOUNT FROM ACCOUNT"<<std::endl;
	std::cout<<"6.ACCOUNT DISPLAY"<<std::endl;
	std::cout<<"7.MODIFY ACCOUNT"<<std::endl;
	std::cout<<"8.MONEY TRANSACTION"<<std::endl;
	std::cout<<"9.EXIT"<<std::endl;
    std::cout<<"Enter Choice:"<<std::endl;
    std::cin>>choice;
    switch(choice)
    {
        case 1:system("cls");
			info();
        	break;
        case 2:system("cls");
			DeleteAccount();
        	break;
        case 3:system("cls");
			displayCustomers();
        	break;
        case 4:system("cls");
			UpdateBalance();
        	break;
        case 5:system("cls");
			UpdateBalance2();
        	break;
        case 6:system("cls");
			Display();
        	break;
        case 7:system("cls");
			UpdateInfo();
        	break;
        case 8:system("cls");
			Transaction();
        	break;
        case 9:return 0;
        break;
    }
}
}
