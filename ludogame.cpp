#include<iostream>
#include<conio.h>
#include<stdlib.h>
class ludo{
	private:
		std::string arr[100]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98","99","100"};
	std::string arr2[100]={"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60","61","62","63","64","65","66","67","68","69","70","71","72","73","74","75","76","77","78","79","80","81","82","83","84","85","86","87","88","89","90","91","92","93","94","95","96","97","98","99","100"};
        char turn;
		int player1;
		int player2;
		std::string sub;
		int randomNumber;
		int player1_dice;
		int player2_dice;
		bool status;
		static int srand_Number;
		static int srand_Number2;
    public:
      ludo();
      ~ludo();
	  void board();
      void snake();
      void win();
      void reset();
      void player();
      void run();
      void ladder();
};
int ludo::srand_Number=3;
int ludo::srand_Number2=4;

ludo::ludo()
{
	this->status=false;
	this->turn='X';
	this->player1_dice=0;
	this->player2_dice=0;
}
ludo::~ludo()
{
	this->srand_Number++;
	this->srand_Number2++;
}
void ludo::board()
{
	std::cout<<"ladder Numbers = [15,35,50,66,80] "<<std::endl;
	std::cout<<"Snake Numbers = [26,45,58,74,87,99] "<<std::endl<<std::endl;
	std::cout<<"\t__________________________________________________"<<std::endl;
std::cout<<"\t| "<<this->arr[90]<<" | "<<this->arr[91]<<" | "<<this->arr[92]<<" | "<<this->arr[93]<<" | "<<arr[94]<<" | "<<arr[95]<<" | "<<arr[96]<<" |"<<arr[97]<<"  | "<<arr[98]<<" | "<<arr[99]<<"|"<<std::endl;
   std::cout<<"\t|____|____|____|____|____|____|____|____|____|____|"<<std::endl;
std::cout<<"\t| "<<arr[80]<<" | "<<arr[81]<<" | "<<arr[82]<<" | "<<arr[83]<<" | "<<arr[84]<<" | "<<arr[85]<<" | "<<arr[86]<<" |"<<arr[87]<<"  | "<<arr[88]<<" | "<<arr[89]<<" |"<<std::endl;
   std::cout<<"\t|____|____|____|____|____|____|____|____|____|____|"<<std::endl;
std::cout<<"\t| "<<arr[70]<<" | "<<arr[71]<<" | "<<arr[72]<<" | "<<arr[73]<<" | "<<arr[74]<<" | "<<arr[75]<<" | "<<arr[76]<<" |"<<arr[77]<<"  | "<<arr[78]<<" | "<<arr[79]<<" |"<<std::endl;
   std::cout<<"\t|____|____|____|____|____|____|____|____|____|____|"<<std::endl;
std::cout<<"\t| "<<arr[60]<<" | "<<arr[61]<<" | "<<arr[62]<<" | "<<arr[63]<<" | "<<arr[64]<<" | "<<arr[65]<<" | "<<arr[66]<<" |"<<arr[67]<<"  | "<<arr[68]<<" | "<<arr[69]<<" |"<<std::endl;
   std::cout<<"\t|____|____|____|____|____|____|____|____|____|____|"<<std::endl;
std::cout<<"\t| "<<arr[50]<<" | "<<arr[51]<<" | "<<arr[52]<<" | "<<arr[53]<<" | "<<arr[54]<<" | "<<arr[55]<<" | "<<arr[56]<<" |"<<arr[57]<<"  | "<<arr[58]<<" | "<<arr[59]<<" |"<<std::endl;
   std::cout<<"\t|____|____|____|____| ___|____|____|____|____|____|"<<std::endl;
std::cout<<"\t| "<<arr[40]<<" | "<<arr[41]<<" | "<<arr[42]<<" | "<<arr[43]<<" | "<<arr[44]<<" | "<<arr[45]<<" | "<<arr[46]<<" |"<<arr[47]<<"  | "<<arr[48]<<" | "<<arr[49]<<" |"<<std::endl;
   std::cout<<"\t|____|____|____|____|____|____|____|____|____|____|"<<std::endl;
std::cout<<"\t| "<<arr[30]<<" | "<<arr[31]<<" | "<<arr[32]<<" | "<<arr[33]<<" | "<<arr[34]<<" | "<<arr[35]<<" | "<<arr[36]<<" |"<<arr[37]<<"  | "<<arr[38]<<" | "<<arr[39]<<" |"<<std::endl;
   std::cout<<"\t|____|____|____|____|____|____|____|____|____|____|"<<std::endl;
std::cout<<"\t| "<<arr[20]<<" | "<<arr[21]<<" | "<<arr[22]<<" | "<<arr[23]<<" | "<<arr[24]<<" | "<<arr[25]<<" | "<<arr[26]<<" |"<<arr[27]<<"  | "<<arr[28]<<" | "<<arr[29]<<" |"<<std::endl;
   std::cout<<"\t|____|____|____|____|____|____|____|____|____|____|"<<std::endl;
std::cout<<"\t| "<<arr[10]<<" | "<<arr[11]<<" | "<<arr[12]<<" | "<<arr[13]<<" | "<<arr[14]<<" | "<<arr[15]<<" | "<<arr[16]<<" |"<<arr[17]<<"  | "<<arr[18]<<" | "<<arr[19]<<" |"<<std::endl;
   std::cout<<"\t|____|____|____|____|____|____|____|____|____|____|"<<std::endl;
   std::cout<<"\t| "<<arr[0]<<"  | "<<arr[1]<<"  | "<<arr[2]<<"  | "<<arr[3]<<"  | "<<arr[4]<<"  | "<<arr[5]<<"  | "<<arr[6]<<"  |  "<<arr[7]<<" | "<<arr[8]<<"  | "<<arr[9]<<" |"<<std::endl;
   std::cout<<"\t ____|____|____|____|____|____|____|____|____|____|"<<std::endl;
}

void ludo::snake()
{
	switch(this->player1_dice)
	{
		case 26:
			this->player1_dice-=10;
			break;
		case 45:
			this->player1_dice-=10;
			break;
		case 58:
			this->player1_dice-=10;
			break;
		case 74:
			this->player1_dice-=10;
			break;
		case 87:
			this->player1_dice-=10;
			break;
		case 99:
			this->player1_dice-=70;
			break;
	}
	switch(this->player2_dice)
	{
		case 26:
			this->player2_dice-=10;
			break;
		case 45:
			this->player2_dice-=10;
			break;
		case 58:
			this->player2_dice-=10;
			break;
		case 74:
			this->player2_dice-=10;
			break;
		case 87:
			this->player2_dice-=10;
			break;
		case 99:
			this->player2_dice-=70;
			break;
	}
}
void ludo::ladder()
{
		switch(this->player1_dice)
	{
		case 15:
			this->player1_dice+=10;
			break;
		case 35:
			this->player1_dice+=10;
			break;
		case 50:
			this->player1_dice+=10;
			break;
		case 66:
			this->player1_dice+=10;
			break;
		case 80:
			this->player1_dice+=10;
			break;
	}
	switch(this->player2_dice)
	{
		case 15:
			this->player2_dice+=10;
			break;
		case 35:
			this->player2_dice+=10;
			break;
		case 50:
			this->player2_dice+=10;
			break;
		case 66:
			this->player2_dice+=10;
			break;
		case 80:
			this->player2_dice+=10;
			break;
	}
}
void ludo::win()
{
	if(this->arr[99]=="XX")
	{
		this->status=true;
		std::cout<<"Player X wins";
	}
	else if(this->arr[99]=="OO")
	{
		this->status=true;
		std::cout<<"Player O wins";
	}
}
void ludo::reset()
{
	for(int i=0;i<(this->player1_dice-1);i++)
	{
		if(arr[i]=="XX")
		{
			arr[i]=arr2[i];
		}
	}
	for(int i=(this->player1_dice+1);i<100;i++)
	{
		if(arr[i]=="XX")
		{
			arr[i]=arr2[i];
		}
	}
	for(int i=0;i<(this->player2_dice-1);i++)
	{
		if(arr[i]=="OO")
		{
			arr[i]=arr2[i];
		}
	}
	for(int i=(this->player2_dice+1);i<100;i++)
	{
		if(arr[i]=="OO")
		{
			arr[i]=arr2[i];
		}
	}
}
void ludo::player()
{
	if(this->turn=='X')
	{
		srand(this->srand_Number2);
		std::cout<<"Player X turn"<<std::endl;
		std::cout<<"enter any number to roll dice:"<<std::endl;
		std::cin>>this->player1;
		this->randomNumber=(rand()%6)+1;
		this->player1_dice+=this->randomNumber;
		if(this->player1_dice>=100)
		{
			this->status=true;
			system("cls");
			std::cout<<"Player X wins";
			this->srand_Number++;
			this->srand_Number2++;
		}
		snake();
		ladder();
		this->arr[this->player1_dice-1]="XX";
		this->turn='O';
		this->srand_Number2++;
		reset();
	}
	else if(turn=='O')
	{
		srand(this->srand_Number);
		std::cout<<"Player O turn"<<std::endl;
		std::cout<<"enter any number to roll dice:"<<std::endl;
		std::cin>>this->player2;
		this->randomNumber=(rand()%6)+1;
		this->player2_dice+=this->randomNumber;
		if(this->player2_dice>=100)
		{
			this->status=true;
			system("cls");
			std::cout<<"Player O wins";
			this->srand_Number2++;
			this->srand_Number++;
		}
		snake();
		ladder();
		this->arr[this->player2_dice-1]="OO";
		this->turn='X';
		this->srand_Number++;
		reset();
	}
}
void ludo::run()
{
	do
	{
		system("cls");
		board();
		player();
		win();
	}
	while(status==false);
}
int main()
{
	ludo l;
	l.run();
}
