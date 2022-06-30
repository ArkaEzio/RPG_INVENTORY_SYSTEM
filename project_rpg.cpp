#include<fstream>
#include<iostream>
#include<iomanip>
#include<unordered_map>
using namespace std;
typedef struct Questequipment {
	string id;
	string type;
	string name;
}questequipment;
typedef struct Weapons {
	string id;
	string type;
	string subcategory;
	string name;
	int damage;
}weapons;
typedef struct Armors {
	string id;
	string type;
	string subcategory;
	string name;
	int damageprotect;
}armors;
typedef struct Food {
	string id;
	string type;
	string name;
	int health;
	int sp;
}food;
typedef struct Junk {
	string id;
	string type;
	string name;
	int sp;
	int quantity;
}junk;
typedef struct Crafting {
	string id;
	string type;
	string name;
	int sp;
	int quantity;
}crafting;

class Character {
		public:
		weapons *primaryweapon;
		weapons *secondaryweapon;		
		armors *head;
		armors *legs;
		armors *torso;
		armors *hands;
		food *food;
		questequipment *questitem;
		Character(){
			primaryweapon=NULL;
			secondaryweapon=NULL;
			head=NULL;
			legs=NULL;
			torso=NULL;
			hands=NULL;
			food=NULL;
			questitem=NULL;
		}
};
Character chara;
unordered_map<string,questequipment> questeq; 
unordered_map<string,questequipment> :: iterator questeqr; 
unordered_map<string,weapons> wep;
unordered_map<string,weapons> :: iterator wepr;
unordered_map<string,armors> ar;
unordered_map<string,armors> :: iterator arr;
unordered_map<string,food> fo;
unordered_map<string,food> :: iterator itr;
unordered_map<string,junk> ju;
unordered_map<string,junk> :: iterator jur;
unordered_map<string,crafting> craft;
unordered_map<string,crafting> :: iterator craftr;
//weapons *primaryweapons,*secondaryweapons;


void input() {
	ifstream file("project_rpg.csv");
	string str;
	int i=25;
	if(!file)  {
		cout<<"cannot open file";
	}
	else {
		getline(file,str,'\n');
		while(file) {
			getline(file,str,',');
			if(str=="Quest Equipment") {
				questequipment qe;
				qe.type=str;
			//	cout<<left<<setw(19);
				getline(file,qe.id,',');
			//	cout<<left<<setw(19);
				getline(file,qe.name,',');
			//	cout<<left<<setw(12)<<endl;
				questeq[qe.id]=qe;
				getline(file,str,'\n');
			}
			else if (str=="Weapons") {
				weapons f;
				f.type=str;
				getline(file,f.id,',');
				getline(file,f.subcategory,',');
				getline(file,f.name,',');
				getline(file,str,'\n');
				f.damage=stoi(str);
				wep[f.id]=f;
			}
			else if (str=="Armors") {
				armors f;
				f.type=str;
				getline(file,f.id,',');
				getline(file,f.subcategory,',');
				getline(file,f.name,',');
				getline(file,str,'\n');
				f.damageprotect=stoi(str);
				ar[f.id]=f;
				//cout<<f.id<<endl;
			}
			else if (str=="Food") {
				food f;
				f.type=str;
				getline(file,f.id,',');
				getline(file,f.name,',');
				getline(file,str,',');
				f.health=stoi(str);
				getline(file,str,'\n');
				f.sp=stoi(str);
				fo[f.id]=f;
				//cout<<f.id<<endl;
			}
			else if (str=="Junk") {
				junk f;
				f.type=str;
				getline(file,f.id,',');
				getline(file,f.name,',');
				getline(file,str,',');
				f.sp=stoi(str);
				getline(file,str,'\n');
				f.quantity=stoi(str);
				ju[f.id]=f;
				//cout<<f.id<<endl;
			}
			else if (str=="Crafting") {
				crafting f;
				f.type=str;
				getline(file,f.id,',');
				getline(file,f.name,',');
				getline(file,str,',');
				f.sp=stoi(str);
				getline(file,str,'\n');
				f.quantity=stoi(str);
				craft[f.id]=f;
			}
		}
	}
}
void removechar()
 {
 	string str;
 	fflush(stdin);
 	cout<<"Select what you want to remove: ";
 	fflush(stdin);
	getline(cin,str);
 	if(str=="Primary Weapon")
 	chara.primaryweapon=NULL;
 	if(str=="Secondary Weapon")
	chara.secondaryweapon=NULL;
	if(str=="Head Armor")
	chara.head=NULL;
	if(str=="Legs Armor")
	chara.legs=NULL;
	if(str=="Torso Armor")
	chara.torso=NULL;
	if(str=="Hands Armor")
	chara.hands=NULL;
	if(str=="Food")
	chara.food=NULL;
	if(str=="Quest Mat")
	chara.questitem=NULL;
 }
 void chngquest(string str) {
 	if(questeq.count(str)) {
	   	chara.questitem=&questeq[str];
	   	cout<<(*(chara.questitem)).name;
	   }
   else
   cout<<"Item not found.";	
 }
void chngfood(string str) {
	if(fo.count(str)) {
	   	chara.food=&fo[str];
	   }
   else
   cout<<"Item not found.";	
}
void chngweapons(string str) {
	if(wep.count(str)) {
	   	if(wep[str].subcategory=="Primary") {
	   			chara.primaryweapon=&wep[str];
	   			cout<<"Player character is equipped with "<<(*(chara.primaryweapon)).name<<".\n";
		   }
	   	else {
	   			chara.secondaryweapon=&wep[str];
	   			cout<<"Player character is equipped with "<<(*(chara.secondaryweapon)).name<".\n";
		   }
	   }
   else
   cout<<"Item not found.";
}
void chngarmor(string str) {
	if(ar.count(str)) {
	   	if(ar[str].subcategory=="Head") {
	   			chara.head=&ar[str];
	   			cout<<"Player character is equipped with "<<(*(chara.head)).name<<".\n";
		   }
	   	else if(ar[str].subcategory=="Torso") {
	   			chara.torso=&ar[str];
	   			cout<<"Player character is equipped with "<<(*(chara.torso)).name<".\n";
		   }
		else if(ar[str].subcategory=="Legs") {
	   			chara.legs=&ar[str];
	   			cout<<"Player character is equipped with "<<(*(chara.legs)).name<".\n";
		   }	
		   else {
	   			chara.hands=&ar[str];
	   			cout<<"Player character is equipped with "<<(*(chara.hands)).name<".\n";
		   }
	   }
	   else
	   cout<<"Item not found.";
}
void printinve() {
	system("cls");
	for(int i=0;i<90;i++)
	{
		cout<<"?";
	}
	cout<<endl;
	cout<<"?";
	for(int i=0;i<39;i++)
	{
		cout<<" ";
	}
	cout<<"Inventory";
	for(int i=0;i<40;i++)
	{
		cout<<" ";
	}
	cout<<"?";
	cout<<endl;
	for(int i=0;i<90;i++)
	{
		cout<<"?";
	}
	cout<<endl;
	for(int i=0;i<90;i++)
	{
		cout<<" ";
	}
	cout<<endl;
	for(int i=0;i<90;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	cout<<"* "<<left<<setw(15)<<"Quest Mat";
	cout<<left<<setw(15)<<"Weapons";
	cout<<left<<setw(15)<<"Armors";
	cout<<left<<setw(15)<<"Food";
	cout<<left<<setw(15)<<"Junk";
	cout<<left<<setw(12)<<"Crafting";
	cout<<"*"<<endl;
	for(int i=0;i<90;i++)
	{
		cout<<"*";
	}
	cout<<endl;
	for(int i=0;i<90;i++)
	{
		cout<<" ";
	}
}
void printcharac() {
	cout<<"\n";
	for(int i=0;i<90;i++)
	{
		cout<<"?";
	}
	cout<<endl;
	cout<<"?";
	for(int i=0;i<36;i++)
	{
	  	cout<<" ";
	}
	cout<<"Player Character";
	for(int i=0;i<36;i++)
	{
		cout<<" ";
	}
	cout<<"?";
	cout<<endl;
	for(int i=0;i<90;i++)
	{
		cout<<"?";
	}
	cout<<endl;
	if(chara.primaryweapon)
	cout<<left<<setw(25)<<"Primary Weapon"<<(*(chara.primaryweapon)).name<<endl;
	else
	cout<<left<<setw(25)<<"Primary Weapon"<<"None"<<endl;
	if(chara.secondaryweapon)
	cout<<left<<setw(25)<<"Secondary Weapon"<<(*(chara.secondaryweapon)).name<<endl;
	else
	cout<<left<<setw(25)<<"Secondary Weapon"<<"None"<<endl;
	if((chara.head))
	cout<<left<<setw(25)<<"Head Armor"<<(*(chara.head)).name<<endl;
	else
	cout<<left<<setw(25)<<"Head Armor"<<"None"<<endl;
	if((chara.torso))
	cout<<left<<setw(25)<<"Torso Armor"<<(*(chara.torso)).name<<endl;
	else
	cout<<left<<setw(25)<<"Torso Armor"<<"None"<<endl;
	if((chara.legs))
	cout<<left<<setw(25)<<"Legs Armor"<<(*(chara.legs)).name<<endl;
	else
	cout<<left<<setw(25)<<"Legs Armor"<<"None"<<endl;
	if(chara.hands)
	cout<<left<<setw(25)<<"Hands Armor"<<(*(chara.hands)).name<<endl;
	else
	cout<<left<<setw(25)<<"Hands Armor"<<"None"<<endl;
	if(chara.food)
	cout<<left<<setw(25)<<"Food"<<(*(chara.food)).name<<endl;
	else
	cout<<left<<setw(25)<<"Food"<<"None"<<endl;
	if(chara.questitem)
	cout<<left<<setw(25)<<"Quest Mat"<<(*(chara.questitem)).name<<endl;
	else
	cout<<left<<setw(25)<<"Quest Mat"<<"None"<<endl;
}
void printfood() {
	char ch;
	printinve();
	
	cout<<"\nFood"<<endl;
	for(int i=0;i<15;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	cout<<left<<setw(30) <<"Item Name"<<left<<setw(30)<<"Amount of Health restored"<<left<<setw(30)<<"Selling price"<< endl;
	for(int i=0;i<90;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	
	for (itr = fo.begin(); itr != fo.end(); itr++)
    {
        cout<<left<<setw(30) << (itr->second).name<<left<<setw(30)<<(itr->second).health<<left<<setw(30)<<(itr->second).sp<< endl;
    }
    printcharac();
    
    cout<<endl<<"Enter i to change an item of the player character, r to remove a player character item && any other key to view Different slot of the inventory: ";
    cin>>ch;
	if(ch=='i') {
		string str;
		cout<<"Enter item id of the item: "; 
		cin>>str;
		chngfood(str);
		printfood();
	}
	else if(ch=='r') {
		removechar();
		printfood();
	}
}
void printweapons() {
	printinve();
	cout<<"\nWeapons"<<endl;
	for(int i=0;i<15;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	cout <<left<<setw(25)<<"Weapon Name"<<left<<setw(25)<<"Weapon Category"<<left<<setw(25)<<"Damage"<< endl;
	for (wepr = wep.begin(); wepr != wep.end(); wepr++)
    {
        cout <<left<<setw(25)<< (wepr->second).name<<left<<setw(25)<<(wepr->second).subcategory<<left<<setw(25)<< (wepr->second).damage << endl;
    }
    printcharac();
    char ch;
    cout<<endl<<"Enter i to change an item of the player character, r to remove a player character item && any other key to view Different slot of the inventory: ";
    cin>>ch;
	if(ch=='i') {
		string str;
		cout<<"Enter item id of the item: "; 
		cin>>str;
		chngweapons(str);
		printweapons();
	}
	else if(ch=='r') {
		removechar();
		printweapons();
	}
}
void printarmors() {
	char ch;
	printinve();
	
	cout<<"\nArmors"<<endl;
	for(int i=0;i<15;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	cout <<left<<setw(30)<<"Armor Name"<<left<<setw(30)<<"Armor Category"<<left<<setw(30)<<"Damage protection"<< endl;
	for(int i=0;i<90;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	for ( arr= ar.begin(); arr != ar.end(); arr++)
    {
        cout <<left<<setw(30)<< (arr->second).name<<left<<setw(30)<<(arr->second).subcategory<<left<<setw(30)<< (arr->second).damageprotect << endl;
    }
    printcharac();
    cout<<endl<<"Enter i to change an item of the player character, r to remove a player character item && any other key to view Different slot of the inventory: ";
    cin>>ch;
	if(ch=='i') {
		string str;
		cout<<"Enter item id of the item: "; 
		cin>>str;
		chngarmor(str);
		printarmors();
	}
	else if(ch=='r') {
		removechar();
		printarmors();
	}
}
void printcrafting (){
	char ch;
	printinve();
	cout<<"\nCrafting"<<endl;
	for(int i=0;i<15;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	cout<<left<<setw(25) <<"Material Name"<<left<<setw(25)<<"Material Selling price"<<left<<setw(25)<<"No of materials present"<< endl;
	for(int i=0;i<90;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	for (craftr = craft.begin(); craftr!= craft.end(); craftr++)
    {
        cout<<left<<setw(25) << (craftr->second).name<<left<<setw(25)<<(craftr->second).sp<<left<<setw(25)<<(craftr->second).quantity<< endl;
    }
    printcharac();
    cout<<endl<<"Enter r to remove a player character item && any other key to view Different slot of the inventory: ";
    cin>>ch;
	if(ch=='r') {
		removechar();
		printcrafting();
	}
} 
void printjunk (){
	char ch;
	printinve();
	
	cout<<"\nJunk"<<endl;
	for(int i=0;i<15;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	cout<<left<<setw(25) <<"Item Name"<<left<<setw(25)<<"Item Selling price"<<left<<setw(25)<<"No of items present"<< endl;
	for(int i=0;i<90;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	for (jur = ju.begin(); jur!= ju.end(); jur++)
    {
        cout<<left<<setw(25) << (jur->second).name<<left<<setw(25)<<(jur->second).sp<<left<<setw(25)<<(jur->second).quantity<< endl;
    }
    printcharac();
    cout<<endl<<"Enter r to remove a player character item && any other key to view Different slot of the inventory: ";
    cin>>ch;
	if(ch=='r') {
		removechar();
		printjunk();
	}
} 

void printquest() {
	char ch;
	printinve();
	cout<<"\nQuest Mat"<<endl;
	for(int i=0;i<15;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	cout<<left<<setw(25) <<"Item Name"<<endl;
	for(int i=0;i<15;i++)
	{
		cout<<"-";
	}
	cout<<endl;
	for (questeqr = questeq.begin();questeqr!= questeq.end(); questeqr++)
    {
        cout<<left<<setw(25) << (questeqr->second).name<<endl;
    }
    printcharac();
    ch='i';
    cout<<endl<<"Enter i to change an item of the player character, r to remove a player character item && any other key to view Different slot of the inventory: ";
    cin>>ch;
	if(ch=='i') {
		string str;
		cout<<"Enter item id of the item: "; 
		cin>>str;
		chngquest(str);
		printquest();
	}
	else if(ch=='r') {
		removechar();
		printquest();
	}
}

int main() {
	input();
	string str;
	printarmors();
	fflush(stdin);
	cout<<"Select the inventory section: ";
	getline(cin,str);
	while(str!="Exit") {
		if(str=="Food")
	    printfood();
		else if (str=="Junk") 
	    printjunk();
	    else if (str=="Weapons")
	    printweapons();
	    else if (str=="Armors")
	    printarmors();
	    else if (str=="Quest Mat")
	    printquest();
	    else if (str=="Crafting")
	    printcrafting();
	    fflush(stdin);
	    cout<<"Select the inventory section: ";
	    getline(cin,str);
	    fflush(stdin);
	}  
	printcharac();
	return 0;
}
