// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
// Node*mergeLL(Node*l1,Node*l2){
//     Node*t1=l1;
//     Node*t2=l2;
//     Node*dummy=new Node(-1);
//     Node*tail=dummy;
//     while(t1&&t2){
//         if(t1->data<=t2->data){
//             tail->next=t1;
//             tail=t1;
//             Node*down=t1->bottom;
//             t1->bottom=NULL;
//             t1=down;
//         }
//         else{
//             tail->next=t2;
//             tail=t2;
//             Node*down=t2->bottom;
//             t2->bottom=NULL;
//             t2=down;
//         }
//     }
//     while(t1){
//         tail->next=t1;
//         tail=t1;
//         Node*down=t1->bottom;
//         t1->bottom=NULL;
//         t1=down;
//     }
//     while(t2){
//         tail->next=t2;
//         tail=t2;
//         Node*down=t2->bottom;
//         t2->bottom=NULL;
//         t2=down;
//     }
//     return dummy->next;
// }
Node*mergeLL(Node*l1,Node*l2){
    Node*t1=l1;
    Node*t2=l2;
    Node*dummy=new Node(-1);
    Node*tail=dummy;
    while(t1&&t2){
        if(t1->data<=t2->data){
            tail->bottom=t1;
            tail=t1;
            t1=t1->bottom;
        }
        else{
            tail->bottom=t2;
            tail=t2;
            t2=t2->bottom;
        }
    }
    if(t1)tail->bottom=t1;
    if(t2)tail->bottom=t2;
    return dummy->bottom;
}
Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL||root->next==NULL)return root;
   Node*temp=root;
   Node*nxt=root->next;
   root->next=NULL;
   Node*cur=nxt;
   while(cur){
       cur=nxt;
       if(nxt){
       nxt=nxt->next;
       cur->next=NULL;
       }
       temp=mergeLL(temp,cur);
   }
   return temp;
   
}

