#include<stdio.h>
#include<mpi.h>
#define BUFFER_SIZE 32
int main(int argc,char*argv[]){
	int MyRank,Numprocs,Destination,iproc;
	int tag=0;
	int Root=0,temp=1;
	char Message[BUFFER_SIZE];
	MPI_Init(&argc,&argv);
	MPI_Status status;
	MPI_Comm_rank(MPI_COMM_WORLD,&MyRank);
	MPI_Comm_size(MPI_COMM_WORLD,&Numprocs);
	if(MyRank==0){
		system("hostname");
		
		for(temp=1;temp<Numprocs;temp++)
		{
			MPI_Recv(Message,BUFFER_SIZE,MPI_CHAR,temp,tag,MPI_COMM_WORLD,&status);
	printf("\n%s in process with rank %d from Process with rank %d\n",Message,temp,Root);
		}
	}
	else{
	system("hostname");
	strcpy(Message,"Hello India");
	MPI_Send(Message,BUFFER_SIZE,MPI_CHAR,Root,tag,MPI_COMM_WORLD);
	}
	MPI_Finalize();
}
