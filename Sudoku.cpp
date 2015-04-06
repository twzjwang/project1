#include "Sudoku.h"
void Sudoku::GiveQuestion(){
	srand((unsigned)time(NULL));
	int p,temp,n=0,e=0;
	
	int my_map[144]=
	   {6, 1, 7, -1, -1, -1, 4, 9, 3, 8, 5, 2,
		5, 3, 9, -1, -1, -1, 8, 7, 2, 6, 4, 1,
		2, 8, 4, -1, -1, -1, 1, 6, 5, 9, 7, 3,
		-1, -1, -1, 1, 5, 3, 6, 8, 9, 4, 2, 7,
		-1, -1, -1, 2, 4, 8, 3, 5, 7, 1, 6, 9,
		-1, -1, -1, 9, 6, 7, 2, 1, 4, 5, 3, 8,
		9, 5, 8, 3, 1, 2, 7, 4, 6, -1, -1, -1,
		7, 4, 3, 8, 9, 6, 5, 2, 1, -1, -1, -1,
		1, 6, 2, 4, 7, 5, 9, 3, 8, -1, -1, -1,
		4, 9, 6, 7, 2, 1, -1, -1, -1, 3, 8, 5,
		3, 7, 5, 6, 8, 9, -1, -1, -1, 2, 1, 4,
		8, 2, 1, 5, 3, 4, -1, -1, -1, 7, 9, 6};
		
	do{
		for(int i=0;i<144;i++)
			map[i]=my_map[i];
		do{
			p=rand()%144;	
		}while(map[p]<=0);
		temp=map[p];
		map[p]=0;
		Solve2();
		if(ans_num==1){
			my_map[p]=0;
			n++;			
		}
		else
			e++;		
	}while(n<50&&e<10000);
	Sudoku::print_map();
	
}

void Sudoku::ReadIn(){
	for(int i=0;i<144;i++)
		cin >> map[i];
	//Sudoku::print_map();	

}

void Sudoku::Solve(){
	int b=0;
	int count=0;
	ans_num=0;

	for(int j=0;j<144;j++){
		if(map[j]==-1)
			count++;
	}
	if(Sudoku::check_map()==0)
		cout << "0" <<endl;

	else if(count!=36)		
		cout << "0" <<endl;
	else{
		Sudoku::test_blank(0);	
		//cout << "ans_num : " << ans_num << endl;		
		for(int j=0;j<144;j++)
			map[j]=ans[j];
				
		for(int j=0;j<144;j++){
			if(map[j]==0)
				b=1;
		}
		if(b==0){
			if(ans_num==1){
 				cout << "1" <<endl;
				Sudoku::print_map();				
			}
			else
				cout << "2" <<endl;
		}
		else if(b==1)
			cout << "1" <<endl;		
	}		
}

void Sudoku::Solve2(){
	int b=0;
	int count=0;
	ans_num=0;

	for(int j=0;j<144;j++){
		if(map[j]==-1)
			count++;
	}
	if(Sudoku::check_map()==0)
		cout << "0" <<endl;

	else if(count!=36)		
		cout << "0" <<endl;
	else{
		Sudoku::test_blank(0);		
	}		
}


void Sudoku::test_blank(int i){
	int temp;
	int b=0;
	//system("CLS");	
	//Sleep(10);
	if(i>=144){
		ans_num++;
		//cout << " i : " << i << "ans_num : " << ans_num << endl;		
		for(int j=0;j<144;j++)
			ans[j]=map[j];				
	}

	else if(map[i]!=0) 
		Sudoku::test_blank(i+1);
	else{

		temp=map[i];		
		for(int j=1;j<=9;j++){
			
			map[i]=j;
			if(Sudoku::check_map()==0)			
				map[i]=temp;
			else {
				//cout << " i : " << i <<" temp : " << temp << " map[i] : " << map[i] << endl;
				//Sudoku::print_map();				
				Sudoku::test_blank(i+1);
				map[i]=temp;				
			}
				
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
	
	//test num
	for(int i=0;i<144;i++){
		if(map[i]>9||map[i]<-1){
			return false;
		}
	}
	
	
	//test column
	for(int i=0;i<12;i++){
		bool num[11]={false};
		for(int j=0+12*i;j<12+12*i;j++){			
			if( num[map[j]+1]==1 && map[j]!=-1 && map[j]!=0 ){
				return false;			
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
				return false;				
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
				return false;				
			}
			else
				num[map[j]+1]=true;
			
			if(j%3==2)
				j+=10;
			else
				j++;
		}
		if( count_n!=9 && count_n!=0 ){
			return false;			
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

