#include"Packet.h"
class Game
{
private:
    int InitMoney;
    int MaxPeole;
    int PacketMoney;
    int PacketQuota;
    double* Money;
public:
    Game(int,int,int,int);
    void Start(int);
    void Print();
};
Game::Game(int IM,int MP,int PM,int PQ)
{
    InitMoney=IM;
    MaxPeole=MP;
    PacketMoney=PM;
    PacketQuota=PQ;
    Money=new double[MaxPeole+1];
    for(int i=1;i<=MaxPeole;i++)
        Money[i]=InitMoney;
}
void Game::Start(int Round)
{
    int Count[110];
    double Sum[110];
    memset(Sum,0,sizeof(Sum));
    memset(Count,0,sizeof(Count));
    for(int i=1;i<=Round;i++)
    {
        double Max=0;
        int Luck=0;
        Packet RedPacket(PacketMoney,PacketQuota);
        for(int j=1;j<=MaxPeole;j++)
        {
            double Get=RedPacket.GetMoney();
            if(Get>Max)
            {
                Max=Get;
                Luck=j;
            }
            Money[j]+=Get;
            Sum[j]+=Get;
        }
        Money[Luck]-=PacketMoney;
        Count[Luck]++;
    }
    for(int i=1;i<=10;i++)
        cout<<"第"<<i<<"个人运气王次数："<<Count[i]<<"次"<<endl;
    for(int i=1;i<=10;i++)
        cout<<"第"<<i<<"个人抢的金额为:"<<Sum[i]<<"元"<<endl;
}
void Game::Print()
{
    for(int i=1;i<=MaxPeole;i++)
        cout<<"第"<<i<<"个人还有"<<Money[i]<<"元"<<endl;
}
int main()
{
    Game Solitaire(100,10,10,10);
    Solitaire.Start(1000);
    Solitaire.Print();
}
