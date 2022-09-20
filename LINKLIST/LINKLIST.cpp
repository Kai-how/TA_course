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
		
	//架構 
	Node *current= NULL;              //讓 current為 Node指標，負責指向 linklist的最後一個 Node
	Node **Array = new Node*[row];   //讓 Array[i]為 Node指標，負責指向 linklist的第一個 Node	
	//node *Array[row];              //讓 Array[i]為 Node指標(這樣也行) 

	for(int i =0 ;i < row; i++)
	{	 	
		Array[i] = NULL;             //對新的 row初始化，將 Array[i]和 current設為 NULL 
		current = NULL;		
	 	bool loop = true;
	 	while(loop == true)
		{			
			int y;	 
		 	cin >> y;		 	
		 	if(y!=0){                   //輸入的 y不為 0時，第 i列的 linklist就要多一個 Node		 		
		 		int d;						 					 	
		 		cin >> d;		 		
				if(Array[i] == NULL && current == NULL){	 // 當 Array[i]和 current都沒有指向的 Node時，表示 linklist目前為空，因此準備加入第一個 Node
					Array[i] = new Node();         //重要：加入第一個 Node，並令 Array[i]指向它 
					Array[i]->y = y;			   //設定 Array[i]所指向 Node的 y
					Array[i]->d = d;			   //設定 Array[i]所指向 Node的 y
	 				Array[i]->next = NULL;         //設定 Array[i]所指向 Node的 next，令其為 NULL       	
					current =Array[i];	           //因為目前 linklist中只有一個 Node，所以頭尾相同
				}
				else{					           //當 Array[i]或 current有指向的 Node時，表示 linklist不為空，因此要在尾部加入另一個 Node
		 			current->next = new Node();    //重要：讓目前 linklist的最後一個 Node指向一個新生成的 Node(因為linklist要多一個 Node)，所以目前 current是指向新linklist的倒數第二個 Node(即下面的 過渡期)
					current = current->next;	   //讓current指向新linklist的最後一個 Node，即新linklist倒數第二個 Node所指向的 Node			 		
			 		current->y = y;				   //設定新 linklist的最後一個 Node的 y
					current->d = d;	  			   //設定新 linklist的最後一個 Node的 d
					current->next = NULL;          //設定新 linklist的最後一個 Node的 next(此時就變成下面的 加入Node後: )
				}					
		 	}
		 	else{		 		
			 loop = false;
			}			 	
		}
	}
	/*                                                                             
		Array[i]和 current均為 Node指標，是一種只能指向 Node型態的指標。若 Array[i]和 current沒有指向的 Node，便不能對其進行操作
		讓 Array[i]指向 linklist的第一個 Node，current指向 linklist的最後一個 Node
	
		以下 linklist中有兩個 Node時，Array[i]指向第一個 Node，current則指向第二個 Node
	    Array[i]           current
	     _      _ _ _      _ _ _    
	    |_|--> |_|_|_|--> |_|_|_|--> NULL
	              1          2 
	              
	    然後對 linklist加入 Node
	    過渡期： 
	    Array[i]           current
	     _      _ _ _      _ _ _      _ _ _ 
	    |_|--> |_|_|_|--> |_|_|_|--> |_|_|_|
	              1          2          3  	
				      
	    加入 Node後: 
	    Array[i]指向第一個 Node，current則指向第三個 Node(因為 linklist中變成三個 Node) 
	    
	    Array[i]                      current
	     _      _ _ _      _ _ _      _ _ _ 
	    |_|--> |_|_|_|--> |_|_|_|--> |_|_|_|--> NULL 	
		          1          2          3   	  
	*/
	cout << endl;
	
	//列印成矩陣 
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
