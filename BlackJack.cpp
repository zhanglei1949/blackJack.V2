//Game 21.
#include <iostream>
#include <string>
#include <sstream>//For the use of lib of string.
#include <ctime> 
#include <cstdlib>
#include <cmath> 
using namespace std;
string cor(int n); 
void sort(int poker[52]);//Sort out the cards.
float calcu(int a);//calculate the value of certain card.
int man(float sum1,string inf1);//The period for human player.
void com(float sum1,float sum2,string inf2);//The period for computer player.  
int poker[52];//To build up a global array functioning as 52 cards of poker;
int j=2,count1=2,count2=2;
float sum1,sum2;//five global varibles.
int main(){
	srand(time(NULL));
	string inf1;
	string inf2;
	int i;
	while (true){//Use while to make the game repeatable.
		char jud;
		for (i=0;i<52;++i){
         	poker[i]=i;
        }//initialize the array.
	    sort(poker);
	    inf1=cor(poker[0]);
	    sum1+=calcu(poker[0]);
	    inf1+=cor(poker[1]);//record the cards.
	    sum1+=calcu(poker[1]);//first give human player two cards.
	    cout<<"For human players:"<<endl; 
	    cout<<"You got:"<<inf1<<endl; 
        sum1=man(sum1,inf1);//return the sum of human players' cards.
	    if (sum1>0){//willn't be executed if human player has already lose the game,
    	   cout<<"sum1 "<<sum1<<endl;
    	   for (i=0;i<2;++i){
    	     	++j;
                inf2+=cor(poker[j]);
                sum2+=calcu(poker[j]);
		   }
		   cout<<"For comouter player:"<<endl;
           cout<<"Computer got:"<<inf2<<endl;
    	   com (sum1,sum2,inf2);
       }
       cout<<"cout1 "<<count1<<" count2 "<<count2<<endl;
	   cout<<"Do you want to continer?(Y/N)"<<endl;//interaction.
	   cin>>jud;
	   while ((jud!='Y'&&jud!='N')||(cin.fail())){//examine the input.
	   	   cout<<"Please enter Y or N!"<<endl;
	   	   cin>>jud;
	   }
	   if (jud=='Y') {
	   cout<<"Another round"<<endl;//determine whether to continue or not.
       }
	   if (jud=='N') {
	   cout<<"Game over"<<endl;break;
	   }
   
   }
    return 0;
}
string cor(int n){//return the corresponding string of cards.
	string inf;
	stringstream ss;
	switch (n/13){
		case 0: inf+="\t Spade "; break; 
		case 1: inf+="\t Heart "; break;
		case 2: inf+="\t Club ";  break;
		case 3: inf+="\t Diamond ";  break;
	}
	switch (n%13){
		case 0 : inf+="A"; break;
		case 10: inf+="J"; break; 
		case 11: inf+="Q"; break;
		case 12: inf+="K";  break;	
	}
	if ((n%13)>0&&(n%13)<10){
		ss<< (n+1)%13 ;
		inf += ss.str();
	}
	return (inf); 
}
void sort(int poker[52]){//sor the carrds ranomly.
	int k,l,m;
	srand(time(NULL));
	for (k=51;k>0;--k){
		l=rand()%k+0;
		m=poker[k];
		poker[k]=poker[l];
		poker[l]=m;
	}
}
float calcu(int a){//calculate the value of certain card.
	float num;
    if (a%13==10||a%13==11||a%13==12) num=0.5; 
    else if(a%13>=0&&a%13<=9) num=(a%13)+1; 
    return num;
}
int man(float sum1,string inf1){
	char jud;
	while (true){	
		cout<<"Do you want one more card?(Y/N)"<<endl;
		cin>>jud;
		while ((jud!='Y'&&jud!='N')||cin.fail()){
			cout<<"Please enter Y or N:"<<endl;
			cin>>jud;
		}
		if (jud=='N') {
			break;
		} 
		else if (jud=='Y'){ 
		  ++j;
		  ++count1;
		  inf1+=cor(poker[j]);
	      sum1+=calcu(poker[j]);
		  cout<<"You now have:"<<inf1<<endl;
		}
		if (sum1>21){
			sum1=-1;
			cout<<sum1<<endl;
			cout<<"You lose!"<<endl;
			break;
		} 
	}
	cout<<"sum1 is"<<sum1<<endl;
	return sum1;
}
void com(float sum1,float sum2,string inf2){
	++j;
	while (true){
		if (fabs(sum2-21)<0.01&&fabs(sum1-21)>0.01){
			cout<<"You lose!"<<endl;
			break;
		}
		if(fabs(sum2-21)<0.01&&fabs(sum1-21)<0.01){
			if (count1>count2) {
				cout<<"you lose!" ;break;
			}
			else if (count1==count2) {
				cout <<"No winner this round";break;
			}
			else if (count1<count2) cout <<"you win!";break;
		}
		if (sum2>21){
			cout<<"you win!"<<endl;break;
		}
		if (sum2<21){
			if (sum2>sum1) {
				cout<<sum2<<" "<<sum1<<endl;
				cout<<"You lose!"<<endl;break;
			}
			else if (sum2<sum1){
				++j;
				++count2;
				inf2+=cor(poker[j]);
				sum2+=calcu(poker[j]);
				cout<<"Computer now have:"<<inf2<<endl; 
			}
			else if (sum2>sum1){
				if (count1>count2) {
					cout<<"you lose!"<<endl;break;
				}
				else {
					j++;
					++count2;
					inf2+=cor(poker[j]);
				    sum2+=calcu(poker[j]);
					cout<<"computer now have:"<<inf2<<endl; 
				}
			}
		}
	cout<<"sum2 "<<sum2<<" "<<j<<endl;	
	}
	cout<<"count1"<<count1<<"count2"<<count2<<endl;

}

