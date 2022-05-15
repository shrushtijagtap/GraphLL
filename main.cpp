#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node
{
	int name;
	node *next;
};

class graph
{
int city_no;
node *head[10];
public:
graph()
{
	cout<<"Enter number of cities"<<endl;
	cin>>city_no;
}
void create()
{
char c;
	for(int i=0;i<city_no;i++)
	{
		node *t=new node();
		cout<<"Enter name of city "<<endl;
		cin>>t->name;
		t->next=NULL;
		head[i]=t;
		while(1)
		{
			node *temp=new node();
			cout<<"Enter name adjacent of city "<<endl;
			cin>>temp->name;
			temp->next=NULL;
					while(t->next!=NULL)
					{
						t=t->next;
					}
					t->next=temp;
					t=temp;
		cout<<"Is there another flyover to any city ? y or n"<<endl;
		cin>>c;
			if(c=='n')
			break;
		};
	}
}
void display()
{
	node *temp;
	for(int i=0;i<city_no;i++)
	{
		temp=head[i];
		cout<<temp->name<<"\t";
		temp=temp->next;
			while(temp!=NULL)
				{
					cout<<temp->name<<"\t";
					temp=temp->next;
				}
		cout<<endl;
	}
}
void bfs()
{
cout<<"BFS"<<endl;
queue <int> que;
int sv,visited[city_no],i;
node *t;
for(int j=0;j<city_no;j++)
	visited[j]=0;
cout<<"Enter starting city"<<endl;
cin>>sv;
que.push(sv);
	while(!que.empty())
	{
		i=que.front();
		que.pop();
		if(visited[i]==0)
		{
			cout<<i<<"\t";
			visited[i]=1;
		}
		t=head[i];
		while(t!=NULL)
		{
			if(visited[t->name]==0)
				que.push(t->name);
			t=t->next;
		}
	}
}
void dfs()
{
cout<<"DFS"<<endl;
stack <int> s;
int sv,visited[city_no],i;
node *t;
for(int j=0;j<city_no;j++)
	visited[j]=0;
cout<<"Enter starting city"<<endl;
cin>>sv;
s.push(sv);
	while(!s.empty())
	{
		i=s.top();
		s.pop();
		if(visited[i]==0)
		{
			cout<<i<<"\t";
			visited[i]=1;
		}
		t=head[i];
		while(t!=NULL)
		{
			if(visited[t->name]==0)
				s.push(t->name);
			t=t->next;
		}
	}
}
};

int main()
{
int choice;
char ch;
graph g;
while(1)
{
	cout<<"Enter your choice \n1.Create  2.Display  3.Bfs,Dfs   4.Exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:g.create();break;
		case 2:g.display();break;
		case 3:g.bfs();cout<<endl;g.dfs();break;
		case 4:break;
		default:cout<<"Wrong choice"<<endl;break;
	}
	cout<<"Do you want to continue ?"<<endl;
	cin>>ch;
	if(ch=='n')
		break;
};
return 0;
}
