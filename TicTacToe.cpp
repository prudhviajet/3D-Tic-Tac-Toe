#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
class MagicCube
{
	private:
		int mymagiccube [3][3][3]; //Cube follows zero based indexing
		bool total [27]; //Progress of which number got used
		bool magiccubefound;
	public:
		MagicCube()
		{
			memset(mymagiccube, 0, sizeof(mymagiccube));
			memset(total, 0, sizeof(total));
			magiccubefound = 0;
		}
		void generatingmc()
		{
			fillTheNumber(0,0,0);
		}

		void fillTheNumber(int i, int j, int k)
		{
			if(magiccubefound)
				return;
			for(int r=0; r<27; r++)
			{
				if(!total[r])
				{
					mymagiccube[i][j][k]=(r+1);
					total[r]=1;
					bool flag=true;
					if(fullRow(i, j)&&!correctRow(i, j))
					{
						flag=false;
					}
					if(fullColoumn(i, k)&&!correctColoumn(i, k))
					{
						flag=false;
					}
					if(fullPillar(j, k)&&!correctPillar(j, k))
					{
						flag=false;
					}
					if(flag)
					{
						if(completedCube())
						{
							if(correctmc())
							{
								magiccubefound=1;
								return;
							}
						}
						else
						{
							if(i<2)
							{
								if(k==2)
								{
									if(j==2)
									{
										fillTheNumber(i+1, 0, 0);
									}
									else
									{
										fillTheNumber(i, j+1, 0);
									}
								}
								else
								{
									fillTheNumber(i, j, k+1);
								}
							}
							else
							{
								if(k==2)
								{
									if(j==2)
									{
										fillTheNumber(0, 0, 0);

									}
									else
									{
										fillTheNumber(i, j+1, 0);
									}
								}
								else
								{
									fillTheNumber(i, j, k+1);
								}}}}
					if(magiccubefound)
						return;
					mymagiccube[i][j][k]=0;
					total[r]=0;
				}
			}
		}
		bool completedCube()
		{
			bool res=true;
			for(int i=0; i<27; i++)
			{
				if(!total[i])
				{
					res=false;
					break;
				}
			}
			return res;
		}
		bool correctmc()
		{
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					if(!correctRow(i,j)||!correctColoumn(i,j))
					{
						return false;
					}
				}
			}
			for(int j=0; j<3; j++)
			{
				for(int k=0; k<3; k++)
				{
					if(!correctPillar(j,k))
					{
						return false;
					}
				}
			}
			if(!correctDiagonals())
			{
				return false;
			}
			return true;
		}
		bool correctRow(int i, int j)
		{
			if(mymagiccube[i][j][0]+mymagiccube[i][j][1]+mymagiccube[i][j][2]!=42)
				return false;
			return true;
		}
		bool fullRow(int i, int j)
		{
			if(mymagiccube[i][j][0]==0||mymagiccube[i][j][1]==0||mymagiccube[i][j][2]==0)
				return false;
			return true;
		}
		bool correctColoumn(int i, int k)
		{
			if(mymagiccube[i][0][k]+mymagiccube[i][1][k]+mymagiccube[i][2][k]!=42)
				return false;
			return true;
		}
		bool fullColoumn(int i, int k)
		{
			if(mymagiccube[i][0][k]==0||mymagiccube[i][1][k]==0||mymagiccube[i][2][k]==0)
				return false;
			return true;
		}
		bool correctPillar(int j, int k)
		{
			if(mymagiccube[0][j][k]+mymagiccube[1][j][k]+mymagiccube[2][j][k]!=42)
				return false;
			return true;
		}
		bool fullPillar(int j, int k)
		{
			if(mymagiccube[0][j][k]==0||mymagiccube[1][j][k]==0||mymagiccube[2][j][k]==0)
				return false;
			return true;
		}
		bool correctDiagonals()
		{
			if(mymagiccube[0][0][0]+mymagiccube[1][1][1]+mymagiccube[2][2][2]!=42)
				return false;
			if(mymagiccube[0][2][0]+mymagiccube[1][1][1]+mymagiccube[2][0][2]!=42)
				return false;
			if(mymagiccube[0][2][2]+mymagiccube[1][1][1]+mymagiccube[2][0][0]!=42)
				return false;
			if(mymagiccube[0][0][2]+mymagiccube[1][1][1]+mymagiccube[2][2][0]!=42)
				return false;
			return true;
		}
		void printingmc()
		{
			cout<<"Magic Cube:"<<endl;
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					for(int k=0; k<3; k++)
					{
						cout<<mymagiccube[i][j][k]<<" ";
				    }
					cout<<endl;
				}
				cout<<endl;
			}}
		void MCreturn(int returncube [][3][3])
		{
			for(int i=0; i<3; i++)
			{
				for(int j=0; j<3; j++)
				{
					for(int k=0; k<3; k++)
					{
						returncube[i][j][k]=mymagiccube[i][j][k];
					}}}}};

struct coordinate
{
	int i, j, k;
};

//to find computers next move if it does not have a possibility to form a collinear line or block the human
int make_2(bool totalMoves[], int Cube[][3][3]) 
{
	if(totalMoves[Cube[1][1][1]]==0)
		return Cube[1][1][1];
	else
	if(totalMoves[Cube[0][0][0]]==0)
		return Cube[0][0][0];
	else
	if(totalMoves[Cube[0][0][2]]==0)
		return Cube[0][0][2];
	else
	if(totalMoves[Cube[0][2][2]]==0)
		return Cube[0][2][2];
	else
	if(totalMoves[Cube[0][2][0]]==0)
		return Cube[0][2][0];
	else
	if(totalMoves[Cube[2][0][0]]==0)
		return Cube[2][0][0];
	else
	if(totalMoves[Cube[2][0][2]]==0)
		return Cube[2][0][2];
	else
	if(totalMoves[Cube[2][2][2]]==0)
		return Cube[2][2][2];
	else
	if(totalMoves[Cube[2][2][0]]==0)
		return Cube[2][2][0];
	else
	if(totalMoves[Cube[0][1][1]]==0)
		return Cube[0][1][1];
	else
	if(totalMoves[Cube[2][1][1]]==0)
		return Cube[2][1][1];
	else
	if(totalMoves[Cube[1][0][1]]==0)
		return Cube[1][0][1];
	else
	if(totalMoves[Cube[1][1][0]]==0)
		return Cube[1][1][0];
	else
	if(totalMoves[Cube[1][2][1]]==0)
		return Cube[1][2][1];
	else
	if(totalMoves[Cube[1][1][2]]==0)
		return Cube[1][1][2];
	else
	if(totalMoves[Cube[0][0][1]]==0)
		return Cube[0][0][1];
	else
	if(totalMoves[Cube[0][1][0]]==0)
		return Cube[0][1][0];
	else
	if(totalMoves[Cube[0][2][1]]==0)
		return Cube[0][2][1];
	else
	if(totalMoves[Cube[0][1][2]]==0)
		return Cube[0][1][2];
	else
	if(totalMoves[Cube[2][0][1]]==0)
		return Cube[2][0][1];
	else
	if(totalMoves[Cube[2][1][0]]==0)
		return Cube[2][1][0];
	else
	if(totalMoves[Cube[2][2][1]]==0)
		return Cube[2][2][1];
	else
	if(totalMoves[Cube[2][1][2]]==0)
		return Cube[2][1][2];
	else
	{
		while(true)
		{
			int move = rand()%27+1;
			if(totalMoves[move]==0)
				return move;
		}
	}
}

//to check if 3 points are collinear
bool collinearitycheck(coordinate A, coordinate B, coordinate C) 
{

	coordinate AB, AC;
	AB.i = B.i-A.i, AB.j = B.j-A.j, AB.k = B.k-A.k;
	AC.i = C.i-A.i, AC.j = C.j-A.j, AC.k = C.k-A.k;
	double val = pow((AB.i*AC.i+AB.j*AC.j+AB.k*AC.k),2)/((1.0)*(AB.i*AB.i+AB.j*AB.j+AB.k*AB.k)*(AC.i*AC.i+AC.j*AC.j+AC.k*AC.k));
	if(val==1)
		return true;
	else
		return false;
}

//to find whether if a win is possible or not
int possWin(vector<int> &Moves, bool invalidTuples[][28][28], coordinate M[], bool totalMoves[]) 
{
	int N,i,j;
	N = Moves.size();
	if(N<2)//If no.of moves<2, no possibility for Win
	{
	    return 0;
	}
	for(i=0; i<N; i++)
	{
		for(j=i+1; j<N; j++)
		{
		    int newmove;
			newmove=42-Moves[i]-Moves[j];
			if(newmove<=27&&newmove!=Moves[i]&&newmove!=Moves[j])
			{
				if(!totalMoves[newmove])
				{
					int num1,num2,num3;
					num1=min(Moves[i],min(Moves[j],newmove));
					num3=max(Moves[i],max(Moves[j],newmove));
					num2=42-num1-num3;
					if(!invalidTuples[num1][num2][num3])
					{
						coordinate P=M[num1], Q=M[num2], R=M[num3];
						if(collinearitycheck(P,Q,R)==1)
						{
							return newmove;
						}
						}}}}}
	return 0;
}

//to check if the human is able to score a point
bool scoredPoint(vector<int> &Moves, bool covered[][28][28], coordinate M[], bool invalidTuples[][28][28]) 
{
	int N,i,j,k;
	N=Moves.size();
	if(N<3)
		return 0;
	for(i=0; i<N; i++)
	{
		for(j=i+1; j<N; j++)
		{
			for(k=j+1; k<N; k++)
			{
				if(Moves[i]+Moves[j]+Moves[k]==42)
				{
					int num1,num2,num3;
					num1=min(Moves[i],min(Moves[j],Moves[k]));
					num3=max(Moves[i],max(Moves[j],Moves[k]));
					num2=42-num1-num3;
					if(!invalidTuples[num1][num2][num3])
					{
						coordinate P=M[num1], Q=M[num2], R=M[num3];
						if(collinearitycheck(P,Q,R)==1&&!covered[num1][num2][num3])
						{
							covered[num1][num2][num3]=1;
							return 1;
						}}}}}}
	return 0;
}

//if human makes the first move
void humanfirst(vector<int> &HMoves, vector<int> &CMoves, int Cube[][3][3], bool invalidTuples[][28][28], coordinate M[])
{
	int Hscore,Cscore,i;
	Hscore=0;
	Cscore=0;
	bool totalMoves[28]={};
	bool covered[28][28][28]={};
	int move;
	for(i=1; i<=27; i++)
	{
		if(i%2==1)
		{
			cout<<"It's your turn: ";
			cin>>move;
			while(totalMoves[move])
			{
				cout<<"It's already selected, try again: ";
				cin>>move;
			}
			HMoves.push_back(move);
			totalMoves[move]=1;
			if(scoredPoint(HMoves, covered, M, invalidTuples))
			{
				Hscore++;
			}
		}
		else
		{
			if(i/2<2)
			{
				int move;
				move=make_2(totalMoves, Cube); //Make a move
				CMoves.push_back(move); //Store the move
				totalMoves[move]=1; //Move marked
			}
			else
			{
				int win;
				win=possWin(CMoves, invalidTuples, M, totalMoves);
				if(win>0&&!totalMoves[win]) //If winning move for computer exists, and that move hasn't been made yet
				{
					CMoves.push_back(win); //Make that move and score the point
					totalMoves[win]=1; //Move marked
					scoredPoint(CMoves, covered, M, invalidTuples);
					Cscore++;
				}
				else
				{
					win=possWin(HMoves, invalidTuples, M, totalMoves);
					if(win&&!totalMoves[win])
					{
						CMoves.push_back(win);
						totalMoves[win]=1;
					}
					else
					{
						move=make_2(totalMoves, Cube);
						CMoves.push_back(move);
						totalMoves[move]=1;
					}}}

			cout<<"Your Moves: [ ";
			int k;
			for(k=0; k<HMoves.size(); k++)
			{
				cout<<HMoves[k]<<", ";
			}
			cout<<"]"<<endl;
			cout<<"System Moves: [ ";
			for(k=0; k<CMoves.size(); k++)
			{
				cout<<CMoves[k]<<", ";
			}
			cout<<"]"<<endl;
		}
	}
	cout<<"Game Over"<<endl;
    cout<<"Your Score : "<<Hscore<<" System score : "<<Cscore<<endl;
	if(Hscore == 10)
		cout<<"Congratulations...You WON..."<<endl;
        else if(Cscore == 10)
		cout<<"Hard Luck...Better Luck Next time...System won"<<endl;
	else
		cout<<"A tie!"<<endl;
}

//if Computer makes the first move
void systemfirst(vector<int> &HMoves, vector<int> &CMoves, int Cube[][3][3], bool invalidTuples[][28][28], coordinate M[])
{
	int movesH,movesC,i;
	movesH=0, movesC=0;
	bool totalMoves[28]={};
	bool covered[28][28][28]={};
	int move;
	for(i=1; i<=27; i++)
	{
		if(i%2==0)//Human move
		{
            cout<<"Moves made by Computer: [ ";
            int k;
            for(k=0; k<CMoves.size(); k++)
            {
                cout<<CMoves[k]<<", ";
            }
            cout<<"]"<<endl;
			cout<<"It's your turn: ";
			cin>>move;
			while(totalMoves[move])
			{
				cout<<"It's already selected, try again: ";
				cin>>move;
			}
			HMoves.push_back(move);
			totalMoves[move]=1;
			if(scoredPoint(HMoves, covered, M, invalidTuples))
			{
				movesH++;
			}
			cout<<"Moves made by you: [ ";
			for(k=0; k<HMoves.size(); k++)
			{
				cout<<HMoves[k]<<", ";
			}
			cout<<"]"<<endl;
		}
		else //Computer Move
		{
			if(i/2<2)
			{
                int move;
				move=make_2(totalMoves, Cube);
				CMoves.push_back(move);
				totalMoves[move]=1;
			}
			else
			{
				int win;
				win=possWin(CMoves, invalidTuples, M, totalMoves);
				if(win>0&&!totalMoves[win])
				{
					CMoves.push_back(win);
					totalMoves[win]=1;
					scoredPoint(CMoves, covered, M, invalidTuples);
					movesC++;
				}
				else
				{
					win=possWin(HMoves, invalidTuples, M, totalMoves);
					if(win&&!totalMoves[win])
					{
						CMoves.push_back(win);
						totalMoves[win]=1;
					}
					else
					{
						move=make_2(totalMoves, Cube);
						CMoves.push_back(move);
						totalMoves[move]=1;
					}}}}}
	cout<<"Game Over"<<endl;
	cout<<"Your score: "<<movesH<<" and Computer score: "<<movesC<<endl;
	if(movesH == 10)
		cout<<"Hurrayyy...You WON "<<endl;
	else
	if(movesC == 10)
		cout<<"System won : Better Luck Next time"<<endl;
	else
		cout<<"It's a TIE!"<<endl;
}

//main function
int main()
{
	int Cube[3][3][3], option;
	option=1;
	if(option==1)
	{
		MagicCube M;
		M.generatingmc();
		M.printingmc();
		M.MCreturn(Cube);
	}
	coordinate M[28]; //Stores the coordinates corresponding to a number in [1,27]
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			for(int k=0; k<3; k++)
			{
				coordinate P;
				P.i=i, P.j=j, P.k=k;
				M[Cube[i][j][k]]=P;//Storing coordinates
			}
		}
	}
	bool check[28][28][28]={};
	bool invalidTuples[28][28][28]={};
	for(int a=1; a<=27; a++)
	{
		for(int b=a+1; b<=27; b++)
		{
			int c=42-a-b;
			if(c>0&&c<=27&&c!=a&&c!=b) //Generating valid no's (a,b,c),denotes tuple.
			{
				int num1=min(a,min(b,c)), num3=max(a,max(b,c));
				int num2=42-num1-num3;
				if(!check[num1][num2][num3]) //If tuple isn't checked
				{
					check[num1][num2][num3]=1;
					coordinate P = M[num1], Q=M[num2], R=M[num3];
					if(!collinearitycheck(P,Q,R)) //Non collinear
					{
						invalidTuples[num1][num2][num3]=1; //Progress of non collinear valid tuples
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	char player1;
	cout<<"Enter 'H' for Human first or 'S' for System first: ";
	vector<int> HMoves, CMoves;
	cin>>player1;
	if(player1=='H'||player1=='h')
	{
		humanfirst(HMoves, CMoves, Cube, invalidTuples, M);
	}
	else
	if(player1=='S'||player1=='s')
	{
		systemfirst(HMoves, CMoves, Cube, invalidTuples, M);
	}
	else
	{
		cout<<"The input entered is incorrect ...Restart the game if u want to play again..."<<endl;
	}
}