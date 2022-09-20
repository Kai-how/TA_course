#include <iostream>
using namespace std;

int main()
{
	struct Node{
		int y,d;
		Node *next; 
	};
	
	int row,col;
	cin >> row >> col;
		
	//�[�c 
	Node *current= NULL;              //�� current�� Node���СA�t�d���V linklist���̫�@�� Node
	Node **Array = new Node*[row];   //�� Array[i]�� Node���СA�t�d���V linklist���Ĥ@�� Node	
	//node *Array[row];              //�� Array[i]�� Node����(�o�ˤ]��) 

	for(int i =0 ;i < row; i++)
	{	 	
		Array[i] = NULL;             //��s�� row��l�ơA�N Array[i]�M current�]�� NULL 
		current = NULL;		
	 	bool loop = true;
	 	while(loop == true)
		{			
			int y;	 
		 	cin >> y;		 	
		 	if(y!=0){                   //��J�� y���� 0�ɡA�� i�C�� linklist�N�n�h�@�� Node		 		
		 		int d;						 					 	
		 		cin >> d;		 		
				if(Array[i] == NULL && current == NULL){	 // �� Array[i]�M current���S�����V�� Node�ɡA��� linklist�ثe���šA�]���ǳƥ[�J�Ĥ@�� Node
					Array[i] = new Node();         //���n�G�[�J�Ĥ@�� Node�A�åO Array[i]���V�� 
					Array[i]->y = y;			   //�]�w Array[i]�ҫ��V Node�� y
					Array[i]->d = d;			   //�]�w Array[i]�ҫ��V Node�� y
	 				Array[i]->next = NULL;         //�]�w Array[i]�ҫ��V Node�� next�A�O�䬰 NULL       	
					current =Array[i];	           //�]���ثe linklist���u���@�� Node�A�ҥH�Y���ۦP
				}
				else{					           //�� Array[i]�� current�����V�� Node�ɡA��� linklist�����šA�]���n�b�����[�J�t�@�� Node
		 			current->next = new Node();    //���n�G���ثe linklist���̫�@�� Node���V�@�ӷs�ͦ��� Node(�]��linklist�n�h�@�� Node)�A�ҥH�ثe current�O���V�slinklist���˼ƲĤG�� Node(�Y�U���� �L���)
					current = current->next;	   //��current���V�slinklist���̫�@�� Node�A�Y�slinklist�˼ƲĤG�� Node�ҫ��V�� Node			 		
			 		current->y = y;				   //�]�w�s linklist���̫�@�� Node�� y
					current->d = d;	  			   //�]�w�s linklist���̫�@�� Node�� d
					current->next = NULL;          //�]�w�s linklist���̫�@�� Node�� next(���ɴN�ܦ��U���� �[�JNode��: )
				}					
		 	}
		 	else{		 		
			 loop = false;
			}			 	
		}
	}
	/*                                                                             
		Array[i]�M current���� Node���СA�O�@�إu����V Node���A�����СC�Y Array[i]�M current�S�����V�� Node�A�K������i��ާ@
		�� Array[i]���V linklist���Ĥ@�� Node�Acurrent���V linklist���̫�@�� Node
	
		�H�U linklist������� Node�ɡAArray[i]���V�Ĥ@�� Node�Acurrent�h���V�ĤG�� Node
	    Array[i]           current
	     _      _ _ _      _ _ _    
	    |_|--> |_|_|_|--> |_|_|_|--> NULL
	              1          2 
	              
	    �M��� linklist�[�J Node
	    �L����G 
	    Array[i]           current
	     _      _ _ _      _ _ _      _ _ _ 
	    |_|--> |_|_|_|--> |_|_|_|--> |_|_|_|
	              1          2          3  	
				      
	    �[�J Node��: 
	    Array[i]���V�Ĥ@�� Node�Acurrent�h���V�ĤT�� Node(�]�� linklist���ܦ��T�� Node) 
	    
	    Array[i]                      current
	     _      _ _ _      _ _ _      _ _ _ 
	    |_|--> |_|_|_|--> |_|_|_|--> |_|_|_|--> NULL 	
		          1          2          3   	  
	*/
	cout << endl;
	
	//�C�L���x�} 
	for(int i =0 ;i < row; i++)
	{
		current = Array[i];	
		if(current == NULL)
		{			
			for(int j =0 ;j < col; j++)
			{
				cout << "0" << " " ;
			}
		}	
		else
		{				
			int start = 0;
			int end;		
			while(current->next != NULL)
			{			
				end = current->y;													
				for(int j =start + 1; j < end ; j++)
				{
					cout << "0" << " " ;
				}	
				cout << current->d << " ";	
				start = current->y;	
				current = current->next;											
			}	
			
			end = current->y;
			for(int j = start + 1; j < end; j++)
			{				
				cout << "0" << " " ;
			}		
			cout << current->d << " ";			
			for(int j = end + 1;j < col + 1; j++)
			{				
			cout << "0" << " " ;
			}	
		}	
		cout << endl;
	}
}
