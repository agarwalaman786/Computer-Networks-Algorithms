#include<bits/stdc++.h>
using namespace std;

//Implementation of the Leaky Bucket Algorithm
void Leaky_Bucket_Algorithm(int *packet_size,int data_packets,int bucket_size, int output_rate){
	int storage = bucket_size;
	int ith= 0;

	//Removing the one packet each time from the queue
	for(int i=0;i<data_packets;i++){
		if(packet_size[i]<bucket_size){
			bucket_size=bucket_size-packet_size[i];
		}
		else{
			while(bucket_size<packet_size[i]){
				bucket_size+=output_rate;
				cout<<"At "<<++ith<<" second receiving at the packet_size of "<<output_rate<<" bucket size is "<<bucket_size<<endl;
			}
			bucket_size=bucket_size-packet_size[i];
		}
	}
	//Overflow
	while(bucket_size<storage && (bucket_size+output_rate)<storage){
		bucket_size+=output_rate;
		cout<<"At "<<++ith<<" second receiving at the packet_size of "<<output_rate<<" bucket size is "<<bucket_size<<endl;
	}		
	if(bucket_size!=storage){
		int temp = storage-bucket_size;
		bucket_size+=(storage-bucket_size);
		cout<<"At "<<++ith<<" second receiving at the packet_size of "<<(temp)<<" bucket size is "<<bucket_size<<endl;
	}
}

int main(){

	//Taking the input of the required variables
	
	//Bucket_size maximum capacity of the bucket
	//data_packets in real life are infinite 
	//for the implementation purpose I am taking it from the user
	//Output_rate at which rate data is coming out of the bucket for eg: 2kb/sec

	//Assumption we are taking here is each size of individual packet is less than the
	//Maximum capacity of the bucket

	int bucket_size, data_packets,output_rate;
	cin>>bucket_size>>data_packets;


	//Taking the input for size of the data packet
	int *packet_size = new int[data_packets];
	for(int i=0;i<data_packets;i++){
		cin>>packet_size[i];
	}
	cin>>output_rate;

	//Performing our algorithm here
	Leaky_Bucket_Algorithm(packet_size,data_packets,bucket_size,output_rate);
	return 0;
}