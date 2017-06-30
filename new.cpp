#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include<iostream>

using namespace std;

int nsb,nvb;
int bfinal[100];
int ctra=0;

void flush()
{
ctra=0;
}
int checkcond(int brr[],int n,int z[],int o[])
{
int cur=0;
    int noprev=0;
 
    int ctr=0;
    
    int nsb1=0,nvb1=0;
    for(int i=0;i<n;++i)
    {
        if(brr[i]==0)
        {
             if(noprev==3)
                {noprev=0;
                
                    nsb1++;
                    if(nsb1>nsb)
                    {
                   // cout<<"tampereda";
                    break;
                    }
                }
             else{
             noprev=0;
             cur=z[cur];
                bfinal[ctra]=brr[i];
                ++ctra;
             ++nvb1;
             if(nvb1>nvb)
                    {
                 //   cout<<"tamperedb";
                    break;
                    }
             }
        }

        else{
            /*if (noprev==3){
               // cout<<"tamperedd";
                break;
            }
            else
            {*/
            noprev+=1;
            cur=o[cur];
            bfinal[ctra]=brr[i];
            ++ctra;
            ++nvb1;
             if(nvb1>nvb)
                    {
                    //cout<<"tamperedc";
                    break;
                    }
            //}
            }
    }
    //cout<<nsb1<<endl<<nvb1<<endl;
    if(cur==0&& nvb1==nvb&& nsb1==nsb)
       {
       
       return 1;
       }
    else{
        flush();
        return -1;
        
        }
    
    



}

int combinationUtil(int brr[],int arr[], int data[], int start, int end,
                     int index, int r,int n,int z[],int o[])
{
int crr[100];
for(int i=0;i<n;++i)
    crr[i]=brr[i];
    if (index == r)
    {
        for (int j=0; j<r; j++)
            {
            //printf("%d ", data[j]);
            if(crr[data[j]]==1)
            {
                crr[data[j]]=0;
                
            }
            else
                crr[data[j]]=1;
            }
            int flagy=checkcond(crr,n,z,o);
            if(flagy==1)
            {
            for(int ke=0;ke<ctra;++ke)
            {
            cout<<bfinal[ke];
            }
            return 1;
            
            }        
        //printf("\n");
        return -1;
    }
 
 
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
      int cbr=combinationUtil(brr,arr, data, i+1, end, index+1, r,n,z,o);
      if(cbr==1)
         return 1;
    }
}
  int printCombination(int brr[],int arr[], int n, int r,int z[],int o[])
{

    int data[r];
 

    combinationUtil(brr,arr, data, 0, n-1, 0, r,n,z,o);
}  



int main()
{
struct addrinfo hints, * res;
	int status;
	int socket_id;
	
	//clear hints
	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	status = getaddrinfo("127.0.0.1","8916", &hints, &res);
	if(status != 0)
	{
		fprintf(stderr, "Error getaddrinfo\n");
		exit(1);
	}	 	
	
	socket_id = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	if(socket_id < 0)
	{
		fprintf(stderr, "Error socket \n");
		exit(2);
	}
	
	status = connect(socket_id, res->ai_addr, res->ai_addrlen);
	if(status < 0)
	{
		fprintf(stderr, "Error connect \n");
		exit(3);
	}
	
	int numbytes = 0;
	char buf[100];
	numbytes = recv(socket_id,buf,100,0);
	if(numbytes == -1)
	{
		fprintf(stderr, "Error receive \n");
		exit(4);
	}
	
	int n11,bx[100];
	
	
	
    n11=buf[0]-'A';
    nvb=buf[1]-'A';
    nsb=buf[2]-'A';
	int x;
	cout<<"n="<<n11<<endl<<"nvb"<<nvb<<"nsb"<<nsb;
	for(int i=3;i<n11+3;++i)
	{
        x=buf[i]-'A';
        cout<<x<<endl;
        bx[i-3]=x;
	
	}
	//buf[numbytes] = '\0';
	//printf("Received %s \n", buf);	
	freeaddrinfo(res);
	close(socket_id);	
	


























    cout << "enter the no of bits" << endl;
    int n;
    //cin>>n;
    cout<<"enter the bit sequence"<<endl;
    int a[100];//,bx[100];
    for(int i=0;i<n11;++i)
        cout<<bx[i];
    //trellis code
    int ctx=0;
    for(int i=4;i<n11-4;++i)
        {
        a[i-4]=bx[i];
        //++ctx;
        }
        cout<<endl;
        n=n11-8;
    for(int i=0;i<n;++i)
        cout<<a[i];
    //n=ctx;
    int cur=0;
    int noprev=0;
    int b[100];
    int ctr=0;
    cout<<"enter the no of stuffed bits\n";
    int nsb1=0,nvb1=0;
    //cin>>nsb;
    cout<<"enter the no of valid bits\n";
    //cin>>nvb;
    int z[8],o[8];
    z[0]=0;
    z[1]=2;
    z[2]=4;
    z[3]=6;
    z[4]=3;
    z[5]=1;
    z[6]=7;
    z[7]=5;
    o[0]=1;
    o[1]=3;
    o[2]=5;
    o[3]=7;
    o[4]=2;
    o[5]=0;
    o[6]=6;
    o[7]=4;
    for(int i=0;i<n;++i)
    {
        if(a[i]==0)
        {
             if(noprev==3)
                {noprev=0;
                
                    nsb1++;
                    if(nsb1>nsb)
                    {
                   // cout<<"tampereda";
                    break;
                    }
                }
             else{
             noprev=0;
             cur=z[cur];
             b[ctr]=a[i];
                ++ctr;
             ++nvb1;
             if(nvb1>nvb)
                    {
                 //   cout<<"tamperedb";
                    break;
                    }
             }
        }

        else{
            noprev+=1;
            cur=o[cur];
            b[ctr]=a[i];
                ++ctr;
            ++nvb1;
             if(nvb1>nvb)
                    {
               //     cout<<"tamperedc";
                    break;
                    }
            }
    }
    cout<<nsb1<<endl<<nvb1<<endl;
    if(cur==0&& nvb1==nvb&& nsb1==nsb)
       {
       for(int i=0;i<ctr;++i)
       cout<<b[i];
       cout<<"\nvalid";
       }
    else{
        int flag=0;
        cout<<"tampered";
        int brr[100];
        for(int i=0;i<n;++i)
        brr[i]=a[i];
        int xrr[100];
        for(int i=0;i<n;++i)
        xrr[i]=i;
        for(int i=0;i<4;++i)
        {
        
        if(printCombination(brr,xrr,n, i,z,o)==1)
            {
            cout<<"no of tampered bits="<<i;
            flag=1;
            break;
            }
        
        }
        if(flag==1)
        {
        cout<<"valid found\n";
        }
        else
        cout<<"cannot repair\n";
    
        }
    return 0;
}
