#include"Packet.h"
class Analysis
{
private:
    int MaxPeole;
    double* Sum;
    int* Luck;
    double* PreMoney;
public:
    Analysis(int M,int I);
    ~Analysis();
    void Print();
    int Statistics(double*,int);
};
Analysis::Analysis(int M,int I)
{
    MaxPeole=M;
    Sum=new double[MaxPeole+1];
    Luck=new int[MaxPeole+1];
    PreMoney=new double[MaxPeole+1];
    for(int i=1;i<=MaxPeole;i++)
        PreMoney[i]=I;
    memset(Sum,0,sizeof(double)*(MaxPeole+1));
    memset(Luck,0,sizeof(int)*(MaxPeole+1));
}
Analysis::~Analysis()
{
    if(Sum!=NULL)
        delete Sum;
    if(Luck!=NULL)
        delete Luck;
    if(PreMoney!=NULL)
        delete PreMoney;
}
void Analysis::Print()
{
    for(int i=1;i<=MaxPeole;i++)
        cout<<"第"<<i<<"个人运气王次数："<<Luck[i]<<"次"<<endl;
    for(int i=1;i<=MaxPeole;i++)
        cout<<"第"<<i<<"个人抢得金额为:"<<Sum[i]<<"元"<<endl;
}
int  Analysis::Statistics(double* Money,int PacketMoney)
{
    double Max=0;
    int ID=0;
    for(int i=1;i<=MaxPeole;i++)
    {
        double Get=Money[i]-PreMoney[i];
        Sum[i]+=Get;
        if(Get>Max)
        {
            Max=Get;
            ID=i;
        }
        PreMoney[i]=Money[i];
    }
    Luck[ID]++;
    PreMoney[ID]-=PacketMoney;
    return ID;
}
class Game
{
private:
    int InitMoney;
    int MaxPeole;
    int PacketMoney;
    int PacketQuota;
    double* Money;
    int *Order;
public:
    Analysis Debug;
    Game(int,int,int,int);
    ~Game();
    void Start(int);
    void Print();
    void GetOrder();
};
Game::Game(int IM,int MP,int PM,int PQ):Debug(MP,IM)
{
    InitMoney=IM;
    MaxPeole=MP;
    PacketMoney=PM;
    PacketQuota=PQ;
    Money=new double[MaxPeole+1];
    Order=new int[MaxPeole+1];
    for(int i=1;i<=MaxPeole;i++)
        Money[i]=InitMoney;
}
Game::~Game()
{
    if(Money!=NULL)
        delete Money;
    if(Order!=NULL)
        delete Order;
}
void Game::GetOrder()
{
    for(int i=1;i<=MaxPeole;i++)
        Order[i]=i;
    srand(GetTime());
    for(int i=1;i<=(MaxPeole*4);i++)
    {
        int Left=rand()%MaxPeole+1;
        int Right=rand()%MaxPeole+1;
        swap(Order[Left],Order[Right]);
    }
    /*
    for(int i=1;i<=MaxPeole;i++)
    {
        cout<<Order[i];
        if(i==MaxPeole)
            cout<<endl;
        else 
            cout<<"  ";
    }*/
}
void Game::Start(int Round)
{
    for(int i=1;i<=Round;i++)
    {
        double Max=0;
        int Luck=0;
        Packet RedPacket(PacketMoney,PacketQuota);
        GetOrder();
        for(int j=1;j<=PacketQuota;j++)
        {
            double Get=RedPacket.GetMoney();
            int Index=Order[j];
            Money[Index]+=Get;
        }
        Luck=Debug.Statistics(Money,PacketMoney);
        Money[Luck]-=PacketMoney;
    }    
}
void Game::Print()
{
    for(int i=1;i<=MaxPeole;i++)
        cout<<"第"<<i<<"个人还有"<<Money[i]<<"元"<<endl;
}
int main()
{
    Game Solitaire(100,10,10,10);
    Solitaire.Start(20);
    Solitaire.Debug.Print();
    Solitaire.Print();
}

