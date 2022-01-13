#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int gcd(int x, int y){
    int r1 = x, r2 = y, t1 = 0, t2 = 1;
    int r,q,t;
    while(r2){
        q = r1/r2;
        r = r1%r2;
        r1 = r2;
        r2 = r;

        t = t1 - (q*t2);
        t1 = t2;
        t2 = t;
    }
    r = r1; t = t1;
    if(r==1){
        if(t < 0){
          t = t+x;
        }
    }
    return t;
}

int n_index_moduler(int g, int k, int p) {
    int r = 1;
    while (k != 0) {
        if (k & 1) {
            r = (r * g) % p;
        }
        g = (g * g) % p;
        k >>= 1;
    }
    return r;
}

void convert_to_two(int M,int i, int pt[]){
  while(1){
    if(M%2 == 1) pt[i] = 1;
    else pt[i] = 0;
    if(M/2 == 0) break;
    M = M/2;
    i--;
  }
}
int convert_to_ten(int arr[8]) {
    int result = 0;
    int j = 0;
    for(int i=7;i>=0;i--){
      if(arr[i]==1){
        result+=1*pow(2,j);
      }
      j++;
    }
    return result;
}
void P_10 (int key[10], int P10[10] )
{
    int p10[10]={key[2],key[4],key[1],key[6],key[3],key[9],key[0],key[8],key[7],key[5]};
    for (int i=0;i<=9;i++) {
        P10[i]=p10[i];
    }
}

void Keys(int P10[10], int K1[8], int K2[8])
{
    int LS_1[10]={P10[1],P10[2],P10[3],P10[4],P10[0],P10[6],P10[7],P10[8],P10[9],P10[5]};
    int k1[8]={LS_1[5],LS_1[2],LS_1[6],LS_1[3],LS_1[7],LS_1[4],LS_1[9],LS_1[8]};
    for (int i=0;i<8;i++) {
        K1[i]=k1[i];
    }
    int LS_2[10]={P10[3],P10[4],P10[0],P10[1],P10[2],P10[8],P10[9],P10[5],P10[6],P10[7]};
    int k2[8]={LS_2[5],LS_2[2],LS_2[6],LS_2[3],LS_2[7],LS_2[4],LS_2[9],LS_2[8]};
    for (int i=0;i<8;i++) {
        K2[i]=k2[i];
    }
}
void IP_Set(int pt[8], int IP[8])
{
    int ip[8]={pt[1],pt[5],pt[2],pt[0],pt[3],pt[7],pt[4],pt[6]};
    for (int i=0;i<8;i++) {
        IP[i]=ip[i];
    }
}
void EP_Set(int IP[8], int EP[8], int IPL[4], int IPR[4])
{
    int ip_L[4]={IP[0],IP[1],IP[2],IP[3]};
    int ip_R[4]={IP[4],IP[5],IP[6],IP[7]};
    for (int i=0;i<4;i++) {
        IPL[i]=ip_L[i];
    }
    for (int i=0;i<4;i++) {
        IPR[i]=ip_R[i];
    }
    int ep[8]={ip_R[3],ip_R[0],ip_R[1],ip_R[2],ip_R[1],ip_R[2],ip_R[3],ip_R[0]};
    for (int i=0;i<8;i++) {
        EP[i]=ep[i];
    }
}
void Sbox_Set(int EK_XOR[8], int SOS1[4]){
    int S0[4][4] = {{0b01,0b00,0b11,0b10},{0b11,0b10,0b01,0b00},{0b00,0b10,0b01,0b11},{0b11,0b01,0b11,0b10}};
    int S1[4][4] = {{0b00,0b01,0b10,0b11},{0b10,0b00,0b01,0b11},{0b11,0b00,0b01,0b00},{0b10,0b01,0b00,0b11}};
    int x=2*EK_XOR[0] + EK_XOR[3];
    int y=2*EK_XOR[1]+EK_XOR[2];
    int z[1][1]={S0[x][y]};
    int x1=2*EK_XOR[4]+EK_XOR[7];
    int y1=2*EK_XOR[5]+EK_XOR[6];
    int z1[1][1]={S1[x1][y1]};
    int A[4]={(z[0][0])/2,(z[0][0])%2,z1[0][0]/2,z1[0][0]%2};
    for (int i=0;i<4;i++) {
        SOS1[i]=A[i];
    }
}
void P4_Set( int P4[4], int S0S1[4])
{
    int p4[4]={S0S1[1],S0S1[3],S0S1[2],S0S1[0]};
    for (int i=0;i<4;i++) {
        P4[i]=p4[i];
    }
}
void SW_Set(int IPR[4], int P4_XOR[8])
{
    for (int i=4;i<8;i++) {
        P4_XOR[i]=IPR[i-4];
    }
}
void SWITCH(int P4_XOR[8], int SW[8])
{
    for (int i=0;i<4;i++) {
        SW[i]=P4_XOR[i+4];
    }
    for (int i=4;i<8;i++) {
        SW[i]=P4_XOR[i-4];
    }
}
void invert_IP(int P4_XOR2[8], int INIP[8])
{
    int inip[8]={P4_XOR2[3],P4_XOR2[0],P4_XOR2[2],P4_XOR2[4],P4_XOR2[6],P4_XOR2[1],P4_XOR2[7],P4_XOR2[5]};
    for (int i=0;i<8;i++) {
        INIP[i]=inip[i];
    }
}

int H(int M){
  int plaintext[8] = {0};
  int key[10] = {0};
  convert_to_two(M,7,plaintext);convert_to_two(815,9,key);
  int P10[10] = {key[2],key[4],key[1],key[6],key[3],key[9],key[0],key[8],key[7],key[5]};
  int K1[8],K2[8],IP[8],EP[8],IPL[4],IPR[4],S0S1[4],P4[4],EK_XOR[8],EK2_XOR[8],P4_XOR[8],SW[8];
  int IPL2[4],IPR2[4],S0S1_2[4],P4_2[4],P4_XOR2[8],INIP[8];
  Keys(P10,K1,K2);
  IP_Set(plaintext,IP);
  EP_Set(IP,EP,IPL,IPR);
  for(int i=0;i<8;i++){
    EK_XOR[i] = EP[i]^K1[i];
    EK2_XOR[i] = EP[i]^K2[i];
  }
  Sbox_Set(EK_XOR,S0S1);
  P4_Set(P4,S0S1);
  for(int i=0;i<4;i++){
    P4_XOR[i] = P4[i]^IPL[i];
  }
  SW_Set(IPR,P4_XOR);
  SWITCH(P4_XOR,SW);
  EP_Set(SW,EP,IPL2,IPR2);
  Sbox_Set(EK2_XOR,S0S1_2);
  P4_Set(P4_2,S0S1_2);
  for (int i=0;i<4;i++) {
        P4_XOR2[i]=P4_2[i]^IPL2[i];
  }
  SW_Set(IPR2,P4_XOR2);
  invert_IP(P4_XOR2,INIP);

  return convert_to_ten(INIP);
}

int main(){
  int g,x,M,k,p,q,s,r;
  printf("g,x,M,k,p,q의 값을 차례대로 입력하시오\n");
  scanf("%d %d %d %d %d %d",&g,&x,&M,&k,&p,&q);
  int y = n_index_moduler(g,x,p);
  r = n_index_moduler(g,k,p)%q;
  s = ((H(M)+(x*r))*gcd(q,k))%q;
  int w = gcd(q,s) % q;
  int u1 = (H(M)*w)%q;
  int u2 = (r*w)%q;
  int v = ((n_index_moduler(g,u1,p)*n_index_moduler(y,u2,p))%p)%q;
  printf("y의 값 : %d \n", y);
  printf("r의 값 : %d \n",r);
  printf("s의 값 : %d \n",s);
  printf("H(M)의 값 : %d \n",H(M));
  printf("w의 값 : %d \n",w);
  printf("u1 u2의 값 : %d %d \n",u1,u2);
  printf("v의 값 : %d \n",v);

  if(v==r) printf("v와 r이 같습니다<인증에 성공했습니다>\n");
  else printf("v와 r이 다릅니다<인증에 실패하셧습니다>\n");
}