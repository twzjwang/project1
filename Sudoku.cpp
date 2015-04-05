#include "Sudoku.h"
void Sudoku::GiveQuestion(){
	srand( (unsigned)time(NULL) );
	//歸零
	int r[4]={0};
	int x;
	for(int i=3;i>=0;i--){
		x=rand()%4;
		if(r[x]==0)
			r[x]=i+1;
		else 
			i++;
	}
	//cout << r[0] << r[1] << r[2] << r[3] <<endl;
	for(int j=0;j<4;j++){
		for(int i=j*36;i<j*36+36;i++){
			if((i%12)/3==(r[j]-1))
				map[i]=-1;
			else 
				map[i]=0;
		}		
	}

	//Sudoku::print_map();
	
	//出題 
	
	int p=0;
	int n=0;
	do{
		do{
			p+=rand()%144;
			while(p>=144)
				p=p-144;
			//cout << p <<endl;			
		}while(map[p]!=0);
		
		//cout << n << " " << p <<endl;
		map[p]=rand()%9+1;	
		
		if(Sudoku::Solve_2()!=1)
			map[p]=0;
		//Sudoku::print_map();
		else 		
			n++;
	}while(n<50/*&&Sudoku::Solve_2()==1*/); // 1:multiple 0:only one
	//cout <<endl;
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

int Sudoku::Solve_2(){
	int b=0;
	for(int j=0;j<144;j++){
		for_test[j]=map[j];
	}	
	Sudoku::test_blank_2(0);		
	for(int j=0;j<144;j++){
		if(for_test[j]==0)
			b=1;
	}
	return b;
}		


void Sudoku::test_blank(int i){
	int temp;
	int b=0;
	//system("CLS");
	Sudoku::print_map();
	//Sleep(10);
	if(i==144)
		return;
	else if(map[i]!=0) 
		Sudoku::test_blank(i+1);
	else{
		temp=map[i];
		for(int j=1;j<=9;j++){
			//temp=map[i];
			map[i]=j;
			cout << " i : " << i <<" temp : " << temp << " map[i] : " << map[i] << endl;
			if(Sudoku::check_map()==0)			
				map[i]=temp;
			else if(Sudoku::check_map()==1)
				Sudoku::test_blank(i+1);
		}		
	}
}

void Sudoku::test_blank_2(int i){
	int temp;
	int b=0;
	//system("CLS");
	//Sudoku::print_map();
	//Sleep(10);
	if(i==144)
		return;
	else if(for_test[i]!=0) 
		Sudoku::test_blank_2(i+1);
	else{
		temp=for_test[i];
		for(int j=1;j<=9;j++){
			//temp=for_test[i];
			for_test[i]=j;
			//cout << " i : " << i <<" temp : " << temp << " map[i] : " << map[i] << endl;
			if(Sudoku::check_map_2()==0)			
				for_test[i]=temp;
			else if(Sudoku::check_map_2()==1)
				Sudoku::test_blank_2(i+1);
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
	int bn=0;
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
	for(int i=0;i++;i<144){
		bool num[11]={false};
		if(map[i]==0){
			for(int j=i/12;j<i/12+12;j++){
				if( num[map[j]+1]==1);
                else
  	                num[map[j]+1]=true;
			}
			for(int j=i%12;j<i%12+132;j){
	                if( num[map[j]+1]==10){
	                }
	                else
	                     num[map[j]+1]=true;
			}
			for(int j=((i/12)/3*3)*12;j<((i/12)/3*3)*12+27;j){
				if( num[map[j]+1]==1);
            	else
                	 num[map[j]+1]=true;
				if(i/3==2)
					j+=10;
				else 
					j++;
			}
			for(int j=2;j<10;j++){
				if(num[j]==false)
					bn=1;
			}
			if(bn==0)
				return false;
		}
	}
	
	if(b==0)	//correct 
		return true;
	else 		//incorrect
		return false;
}

bool Sudoku::check_map_2(){
	int b=0;
	int bn=0;
	int count_n;
	
	//test num
	for(int i=0;i<144;i++){
		if(for_test[i]>9||for_test[i]<-1){
			return false;
		}
	}
	
	
	//test column
	for(int i=0;i<12;i++){
		bool num[11]={false};
		for(int j=0+12*i;j<12+12*i;j++){			
			if( num[for_test[j]+1]==1 && for_test[j]!=-1 && for_test[j]!=0 ){
				return false;			
			}
			else
				num[for_test[j]+1]=true;
		}
	}	
		
	//test row
	for(int i=0;i<12;i++){
		bool num[11]={false};		
		for(int j=i;j<=i+132;j){			
			if( num[for_test[j]+1]==1 && for_test[j]!=-1 && for_test[j]!=0){
				return false;				
			}
			else
				num[for_test[j]+1]=true;
			j+=12;
		}		
	}

	//test block
	for(int i=0;i<144;i){
		count_n=0;
		bool num[11]={false};
		for(int j=i;j<i+27;j){
			if(for_test[j]==-1)
				count_n++;			
			else if( num[for_test[j]+1]==1 && for_test[j]!=0){
				return false;				
			}
			else
				num[for_test[j]+1]=true;
			
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

     for(int i=0;i++;i<144){
         bool num[11]={false};
         if(map[i]==0){
             for(int j=i/12;j<i/12+12;j++){
                 if( num[map[j]+1]==1);
                 else
                     num[map[j]+1]=true;
             }
             for(int j=i%12;j<i%12+132;j){
                     if( num[map[j]+1]==1){
                     }
                     else
                          num[map[j]+1]=true;
             }
             for(int j=((i/12)/3*3)*12;j<((i/12)/3*3)*12+27;j){
                 if( num[map[j]+1]==1);
                 else
                      num[map[j]+1]=true;
                 if(i/3==2)
                     j+=10;
                 else
                     j++;
             }
             for(int j=2;j<10;j++){
                 if(num[j]==false)
                     bn=1;
             }
             if(bn==0)
                 return false;
			
         }
     }
    if(b==0)    //correct
         return true;
     else        //incorrect
         return false;

}
