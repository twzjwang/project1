#include "Sudoku.h"
void Sudoku::GiveQuestion(){
	srand((unsigned)time(NULL));
	int p,temp,n=0,e=0;
	int r;
	int my_map[144]={0};

	char temp_map[144]=
	   {'f', 'a', 'g', 'o', 'o', 'o', 'd', 'i', 'c', 'h', 'e', 'b',
		'e', 'c', 'i', 'o', 'o', 'o', 'h', 'g', 'b', 'f', 'd', 'a',
		'b', 'h', 'd', 'o', 'o', 'o', 'a', 'f', 'e', 'i', 'g', 'c',
		'o', 'o', 'o', 'a', 'e', 'c', 'f', 'h', 'i', 'd', 'b', 'g',
		'o', 'o', 'o', 'b', 'd', 'h', 'c', 'e', 'g', 'a', 'f', 'i',
		'o', 'o', 'o', 'i', 'f', 'g', 'b', 'a', 'd', 'e', 'c', 'h',
		'i', 'e', 'h', 'c', 'a', 'b', 'g', 'd', 'f', 'o', 'o', 'o',
		'g', 'd', 'c', 'h', 'i', 'f', 'e', 'b', 'a', 'o', 'o', 'o',
		'a', 'f', 'b', 'd', 'g', 'e', 'i', 'c', 'h', 'o', 'o', 'o',
		'd', 'i', 'f', 'g', 'b', 'a', 'o', 'o', 'o', 'c', 'h', 'e',
		'c', 'g', 'e', 'f', 'h', 'i', 'o', 'o', 'o', 'b', 'a', 'd',
		'h', 'b', 'a', 'e', 'c', 'd', 'o', 'o', 'o', 'g', 'i', 'f'};
	
	int replace_num[9]={0};
	bool num[9]={0};
	
	for(int i=0;i<9;i++){
		do{
			r=rand()%9;
			//cout << r <<endl;
		}while(num[r]==1);
		num[r]=1;	
		replace_num[i]=r;
		//cout << "i="<< i << " " <<replace_num[i] <<endl;
	}
	
	//replaced with random number
	for(int i=0;i<144;i++){
		if(temp_map[i]=='a')my_map[i]=replace_num[0]+1;
		else if(temp_map[i]=='b')my_map[i]=replace_num[1]+1;
		else if(temp_map[i]=='c')my_map[i]=replace_num[2]+1;
		else if(temp_map[i]=='d')my_map[i]=replace_num[3]+1;		
		else if(temp_map[i]=='e')my_map[i]=replace_num[4]+1;		
		else if(temp_map[i]=='f')my_map[i]=replace_num[5]+1;		
		else if(temp_map[i]=='g')my_map[i]=replace_num[6]+1;		
		else if(temp_map[i]=='h')my_map[i]=replace_num[7]+1;		
		else if(temp_map[i]=='i')my_map[i]=replace_num[8]+1;		
		else if(temp_map[i]=='o')my_map[i]=-1;		
	}


	//choose blank	
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
	}while(n<60&&e<10000);
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
	bool num[9]={0};
	int count2=0;

	for(int j=0;j<144;j++){
		if(map[j]>0)
			num[map[j]]=1;
		if(map[j]==-1)
			count++;
	}
	
	for(int j=0;j<9;j++){
		if(num[j]==0)
			count2++;
	}
	
		
	if(Sudoku::check_map()==0)
		cout << "0" <<endl;	
	else if(count!=36)		
		cout << "0" <<endl;
	else if(count2>=2)
		cout << "2" <<endl;		
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
			cout << "0" <<endl;		
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

