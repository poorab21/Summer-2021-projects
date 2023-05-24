#include<iostream>
#include<fstream>
#include<string.h>
#include<math.h>
#include<time.h>
int choice=0;
void Display_Log(std::string email)
{
	system("cls");
	std::string log = email+"_Log.txt";
	std::ifstream fileholder(log);
	std::string value;
	std::cout<<"\t\t\t____NOTEBOOK____"<<std::endl;
	while(getline(fileholder,value))
	{
		std::cout<<"\t\t\t ___________________"<<std::endl;
		std::cout<<"\t\t\t "<<value<<"        "<<std::endl;
		std::cout<<"\t\t\t ___________________"<<std::endl;
	}
	fileholder.close();
}
bool Exists_In_Log(std::string email,std::string email2)
{
	std::string log = email+"_Log.txt";
	std::ifstream fileholder(log.c_str());
	std::string value;
	while(getline(fileholder,value))
	{
		if(value==email2)
		{
			return true;
		}
	}
	return false;
	fileholder.close();
}
void Insert_Notebook(std::string email,std::string email2)
{
	int answer;
	if(Exists_In_Log(email,email2)==false)
	{
		std::cout<<"Would you like to Save this Email Account to your Personal Log:"<<std::endl;
		std::cout<<" ______              _____"<<std::endl;
		std::cout<<"|1.YES |            |2.NO |"<<std::endl;
		std::cout<<"|______|            |_____|"<<std::endl;
		std::cout<<"\n";
		std::cout<<"Enter Choice:";
		std::cin>>answer;
		if(answer==1)
		{
			std::string log = email+"_Log.txt";
			std::ofstream fileholder(log.c_str(),std::ios::app);
			fileholder<<email2<<std::endl;
			fileholder.close();
		}
	}
}
void Display_Messages(std::string email)
{
	system("cls");
	std::string file = email+".txt";
	std::ifstream fileholder(file.c_str());
	std::string value;
	while(getline(fileholder,value))
	{
		std::cout<<value<<std::endl;
	}
	std::cout<<"\n";
	fileholder.close();
}
void Start_Menu()
{
	std::cout<<"\t\t\t____________________________________"<<std::endl;
	std::cout<<"\t\t\t|  1) Create Email Account          |"<<std::endl;
	std::cout<<"\t\t\t|  2) Send Email                    |"<<std::endl;
	std::cout<<"\t\t\t|  3) Display Accounts              |"<<std::endl;
	std::cout<<"\t\t\t|  4) Delete Email Account          |"<<std::endl;
	std::cout<<"\t\t\t|  5) Display Notebook              |"<<std::endl;
	std::cout<<"\t\t\t|  6) Show Specific Messages        |"<<std::endl;
	std::cout<<"\t\t\t|  7) Exit                          |"<<std::endl;
	std::cout<<"\t\t\t|___________________________________|"<<std::endl;
	std::cout<<"\n\t\t\t\tChoose:";
	std::cin>>choice;
}
std::string Current_Time()
{
	time_t t;
	time(&t);
	std::string time = ctime(&t);
	time[time.length()-1] = '\0';
	return time;
}
void Send_Messages(std::string source_email,std::string destination_email)
{
	std::string message;
	std::string sub = source_email+".txt";
	std::string sub2 = destination_email+".txt";
	std::cin.ignore();
	while(message != "-1")
	{	
		Display_Messages(source_email);
		std::cout<<"Enter Message( or -1 to exit):";
		getline(std::cin,message);
		if(message != "-1")
		{	
			std::ofstream destination(sub2.c_str(),std::ios::app);
			destination<<"\t\t\t\t"<<source_email<<" TO YOU:"<<std::endl;
			destination<<message<<". ("<<Current_Time()<<")"<<std::endl;
			destination<<"\n";
			destination.close();
	
			std::ofstream source(sub.c_str(),std::ios::app);
			source<<"\t\t\t\t"<<"You TO ("<<destination_email<<"):"<<std::endl;
			source<<message<<". ("<<Current_Time()<<")"<<std::endl;
			source<<"\n";
			source.close();
		}
	}
	system("cls");
}
bool Check_Account(std::string email)
{
	std::ifstream fileholder("Email_Accounts.txt");
	std::string value;
	while(getline(fileholder,value))
	{
		if(value==email)
		{
			return true;
		}
	}
	return false;
}
void Delete_Password(std::string email)
{
	std::ifstream fileholder("Passwords.txt");
	std::ofstream fileholder2("NewFile2.txt");
	std::string value;
	while(getline(fileholder,value))
	{
		if(strstr(value.c_str(),email.c_str()))
		{
			continue;
		}
		else
		{
			fileholder2<<value<<std::endl;
		}
	}
	fileholder.close();
	fileholder2.close();
	std::ofstream file("Passwords.txt");
	std::ifstream file2("NewFile2.txt");
	value="";
	while(getline(file2,value))
	{
		file<<value<<std::endl;
	}
	file.close();
	file2.close();
	remove("NewFile2.txt");
}
bool CheckPassword(std::string email,std::string password)
{
	std::ifstream fileholder("Passwords.txt");
	std::string value;
	while(getline(fileholder,value))
	{
		if(strstr(value.c_str(),email.c_str()))
		{
			int i;
			for(i=value.length()-1;value[i] != 32;i--){}
			std::string password_value="";
			for(int j=i+1;value[j] != '\0';j++)
			{
				password_value+=value[j];
			}
			if(password_value==password)
			{
				return true;
			}
		}
	}
	fileholder.close();
	return false;
}
int findNumber(std::string input)
{
	std::string num = "";
	for(int i=0;i<input.length();i++)
	{
		if(isdigit(input[i]))
		{
			num+=input[i];
		}
	}
	return stoi(num);
}
int Total_Accounts()
{
	int count=0;
	std::ifstream fileholder("Email_Accounts.txt");
	std::string email;
	while(fileholder>>email)
	{
		count++;
	}
	fileholder.close();
	return count;
}
bool Verfication_Email(std::string email)
{
	bool at = false;
	bool dot = false;
	for(int i=0;i<email.length();i++)
	{
		if(email[i]=='@' && dot==false)
		{
			at=true;
		}
		else if(email[i]=='.' && at==true)
		{
			dot=true;
		}
	}
	if(dot==true && at==true)
	{
		return true;
	}
	return false;
}
void Create_Account()
{
	std::string first_name,middle_name,last_name,gender;
	std::string account_name,password,confirm_password;
	int age;
	std::cout<<"Enter First-Name:";
	std::cin>>first_name;
	std::cout<<"Enter Middle-Name:";
	std::cin>>middle_name;
	std::cout<<"Enter Last-Name:";
	std::cin>>last_name;	
	std::cout<<"Enter Age:";
	std::cin>>age;
	std::cout<<"Enter Gender:";
	std::cin>>gender;
	std::cout<<"Enter Email Account Name:";
	std::cin>>account_name;
	if(Verfication_Email(account_name)==false || Check_Account(account_name)==true)
	{
		while(Verfication_Email(account_name)==false || Check_Account(account_name)==true)
		{
			std::cout<<"__________________________________"<<std::endl;
			std::cout<<"|   Error in Email Name Format    |"<<std::endl;
			std::cout<<"|             OR                  |"<<std::endl;
			std::cout<<"|Account with Similar Name Exists |"<<std::endl;
			std::cout<<"|_________________________________|"<<std::endl<<std::endl;
			std::cout<<"Enter Email Account Name:";
			std::cin>>account_name;
		}
	}
	std::cout<<"Enter Password:";
	std::cin>>password;
	std::cout<<"Confirm Password:";
	std::cin>>confirm_password;
	if(confirm_password != password)
	{
		while(confirm_password != password)
		{
			std::cout<<"________________________________"<<std::endl;
			std::cout<<"|Error in Password Confirmation|"<<std::endl;
			std::cout<<"|______________________________|"<<std::endl<<std::endl;
			std::cout<<"Enter Password:";
			std::cin>>password;
			std::cout<<"Confirm Password:";
			std::cin>>confirm_password;
		}
	}
	int option;
	std::cout<<" ____________________________"<<std::endl;
	std::cout<<"|Create Account -> Press 1   |"<<std::endl;
	std::cout<<"|Undo All -> Press 0         |"<<std::endl;
	std::cout<<"|____________________________|"<<std::endl;
	std::cout<<"Your Choice:";
	std::cin>>option;
	if(option==1)
	{
		std::ofstream fileholder("Account_Holders.txt",std::ios::app);
		fileholder<<"\nAccount-Number "<<Total_Accounts()+1<<std::endl;
		fileholder<<"_________________________"<<std::endl;
		fileholder<<"| First-Name = "<<first_name<<std::endl;
		fileholder<<"| Middle-Name = "<<middle_name<<std::endl;
		fileholder<<"| Last-Name = "<<last_name<<std::endl;
		fileholder<<"| Age = "<<age<<std::endl;
		fileholder<<"| Gender = "<<gender<<std::endl;
		fileholder<<"| Email Account = "<<account_name<<std::endl;
		fileholder<<"|_________________________"<<std::endl;
		fileholder.close();
		
		std::ofstream fileholder2("Email_Accounts.txt",std::ios::app);
		fileholder2<<account_name<<std::endl;
		fileholder2.close();
		
		std::ofstream password_file("Passwords.txt",std::ios::app);
		password_file<<account_name<<" -> "<<password<<std::endl;
		password_file.close();
	}
	
}
void Delete_Data(std::string email)
{
	int line = 0,start_line = 0;
	std::string notebook = email + "_Log.txt";
	std::string message_log = email + ".txt";
	std::ifstream fileholder("Account_Holders.txt");
	std::string value,check_value="Account-Number";
	while(getline(fileholder,value))
	{
		if(strstr(value.c_str(),check_value.c_str()))
		{
			start_line = line;
			remove(notebook.c_str());
			remove(message_log.c_str());
		}
		if(strstr(value.c_str(),email.c_str()))
		{
			int start = start_line,end = line+2,line_number = 0;
			std::ifstream fileholder2("Account_Holders.txt");
			std::ofstream fileholder3("Sub.txt");
			std::string line_content;
			while(getline(fileholder2,line_content))
			{
				if(line_number>=start && line_number<=end)
				{
					line_number++;
					continue;
				}
				else
				{
					if(strstr(line_content.c_str(),check_value.c_str()) && line_number>end)
					{
						fileholder3<<"Account-Number "<<findNumber(line_content)-1<<std::endl;
					}
					else
					{
						fileholder3<<line_content<<std::endl;
					}
				}
				line_number++;
			}
			fileholder2.close();
			fileholder3.close();
			
			std::ofstream accounts("Account_Holders.txt");
			std::ifstream sub("Sub.txt");
			std::string content;
			while(getline(sub,content))
			{
				accounts<<content<<std::endl;
			}
			accounts.close();
			sub.close();
			break;
		}
		line++;
	}
	remove("Sub.txt");
	fileholder.close();
}
void Delete_Account(std::string email,std::string password)
{
	if(CheckPassword(email,password))
	{
		std::ifstream fileholder("Email_Accounts.txt");
		std::ofstream newfile("newfile.txt");
		std::string value;
		while(getline(fileholder,value))
		{
			if(email==value)
			{
				Delete_Data(email);
			}
			else
			{
				newfile<<value<<std::endl;
			}
		}
		newfile.close();
		fileholder.close();
		std::ofstream file("Email_Accounts.txt");
		std::ifstream file2("newfile.txt");
		value="";
		while(getline(file2,value))
		{
			file<<value<<std::endl;
		}
		file.close();
		file2.close();
		remove("newfile.txt");
		Delete_Password(email);
	}
	else
	{
		std::cout<<"Error in Password or Account Name"<<std::endl;
	}
}
void Message(std::string source_email,std::string destination_email)
{
	std::string password;
	std::cout<<"Enter Your Account Password:";
	std::cin>>password;
	if(Check_Account(source_email)==false)
	{
		std::cout<<"Source Email Account is Invalid"<<std::endl;
	}
	if(Check_Account(destination_email)==false)
	{
		std::cout<<"Destination Email Account is Invalid or deleted"<<std::endl;
	}
	if(CheckPassword(source_email,password)==false)
	{
		std::cout<<"Password is Invalid"<<std::endl;
	}
	if(Check_Account(source_email)==true && Check_Account(destination_email)==true && CheckPassword(source_email,password)==true)
	{
		Insert_Notebook(source_email,destination_email);
		Send_Messages(source_email,destination_email);
	}
}
void Display_Accounts()
{
	std::ifstream fileholder("Account_Holders.txt");
	std::string value;
	while(getline(fileholder,value))
	{
		std::cout<<value<<std::endl;
	}
	fileholder.close();
}
void Display_Messages2(std::string source,std::string target)
{
	bool allow = false;
	std::string source_file = source + ".txt";
	std::ifstream fileholder(source_file.c_str());
	std::string value;
	while(getline(fileholder,value))
	{
		if(strstr(value.c_str(),target.c_str()))
		{
			std::cout<<value<<std::endl;
			allow = true;
		}
		else if(allow==true && value=="")
		{
			std::cout<<std::endl;
			allow = false;
		}
		else if(allow==true)
		{
			std::cout<<value<<std::endl;
		}
	}
	fileholder.close();
}
int main()
{
	std::string source_email,destination_email,password;
	while(1)
	{
		Start_Menu();
		system("cls");
		switch(choice)
		{
			case 1:
				Create_Account();
				break;
			case 2:
				std::cout<<"Enter your Email Account:";
				std::cin>>source_email;
				std::cout<<"Enter Target Email Account:";
				std::cin>>destination_email;
				Message(source_email,destination_email);
				break;
			case 3:
				Display_Accounts();
				break;
			case 4:
				std::cout<<"Enter Email Account:";
				std::cin>>source_email;
				std::cout<<"Enter Password:";
				std::cin>>password;
				Delete_Account(source_email,password);
				break;
			case 5:
				std::cout<<"Enter Email Account:";
				std::cin>>source_email;
				Display_Log(source_email.c_str());
				break;
			case 6:
				std::cout<<"Enter Email Account:";
				std::cin>>source_email;
				std::cout<<"Enter Target Email Account:";
				std::cin>>destination_email;
				Display_Messages2(source_email,destination_email);
				break;
			case 7:
				return 0;
		}
	}	
}	
