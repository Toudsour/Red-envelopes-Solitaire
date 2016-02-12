#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<sys/time.h>
using namespace std;
int GetTime();
class Packet
{
private:
    double Money;
    int Quota;
public:
    Packet(double  M,int Q);
    void SendPacket(int M,int Q);
    double GetMoney();
    double GetPrecent();
};
Packet::Packet(double M,int Q)
{
    Money=M;
    Quota=Q;
    srand(GetTime());
}
void Packet::SendPacket(int M,int Q)
{
    Money=M;
    Quota=Q;
    srand(GetTime());
}
double Packet::GetMoney()
{
    double Ans=0;
    if(Quota<=0)
        return Ans;
    if(Quota==1)
    {
        Quota--;
        Ans=Money;
        Money-=Ans;
        return Ans;
    }
    double Max=Money/Quota*2;
    double Min=0.01;
    Ans=Max*GetPrecent();
    Ans=((double)((int)(Ans*100)))/100;
    Ans=max(Ans,Min);
    Money-=Ans;
    Quota--;
    return Ans;
}
double Packet::GetPrecent()
{
    int Max=10000;
    int Rand=(unsigned)rand();
    Rand=Rand%Max;
    return (double)Rand/Max;
}
int GetTime()
{
    struct timeval Now;
    gettimeofday(&Now,NULL);
    return 1000000*Now.tv_sec+Now.tv_usec;
}
