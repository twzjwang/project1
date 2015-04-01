#include "Sudoku.h"
void Sudoku::GiveQuestion(){
	
}

void Sudoku::ReadIn(){
	for(int i=0;i<144;i++)
		cin >> map[i];
	//Sudoku::print_map();	

}

void Sudoku::Solve(){
	int b=0;
	if(Sudoku::check_map()==0)
		cout << "0" <<endl;
	else{
		Sudoku::test_blank(0);		
		for(int j=0;j<144;j++){
			if(map[j]==0)
				b=1;
		}
		if(b==0){
 			cout << "1" <<endl;
			Sudoku::print_map();			
		}
		else if(b==1)
			cout << "2" <<endl;		
	}		
}

void Sudoku::test_blank(int i){
	int temp;
	int b=0;
	//Sudoku::print_map();
	if(i==144)
		return;
	else if(map[i]!=0)
		Sudoku::test_blank(i+1);
	else{
		for(int j=1;j<=9;j++){
			temp=map[i];
			map[i]=j;
			//cout << " i : " << i <<" temp : " << temp << " map[i] : " << map[i] << endl;
			if(Sudoku::check_map()==0)			
				map[i]=temp;
			else if(Sudoku::check_map()==1)
				Sudoku::test_blank(i+1);
		}		
	}
}

//print current map
void Sudoku::print_map(){
	for(int i=0;i<144;i++){
		if(i%12==0&&i!=0)
			cout << endl;			
		cout << map[i] << " ";
	}
	cout << endl;		
}

//check : correct or not
bool Sudoku::check_map(){
	int b=0;
	int count_n;
	
	//test column
	for(int i=0;i<12;i++){
		bool num[11]={false};
		for(int j=0+12*i;j<12+12*i;j++){			
			if( num[map[j]+1]==1 && map[j]!=-1 && map[j]!=0 ){
				b=1;
				break;				
			}
			else
				num[map[j]+1]=true;
		}
	}	
		
	//test row
	for(int i=0;i<12;i++){
		bool num[11]={false};		
		for(int j=i;j<=i+132;j){			
			if( num[map[j]+1]==1 && map[j]!=-1 && map[j]!=0){
				b=1;
				break;				
			}
			else
				num[map[j]+1]=true;
			j+=12;
		}		
	}

	//test block
	for(int i=0;i<144;i){
		count_n=0;
		bool num[11]={false};
		for(int j=i;j<i+27;j){
			if(map[j]==-1)
				count_n++;			
			else if( num[map[j]+1]==1 && map[j]!=0){
				b=1;
				break;				
			}
			else
				num[map[j]+1]=true;
			
			if(j%3==2)
				j+=10;
			else
				j++;
		}
		if( count_n!=9 && count_n!=0 ){
			b=1;
			break;			
		}			
		if( (i/3+1)%4==0 )
			i+=27;
		else
			i+=3;
	}
	
	if(b==0)	//correct 
		return true;
	else 		//incorrect
		return false;
}
