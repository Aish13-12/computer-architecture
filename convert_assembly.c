#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
# define MAXNAMELEN2 30


void register_r(char bin_reg[6])
{
	if(strcmp(bin_reg,"00000")==0)
	printf("$zero");
	if(strcmp(bin_reg,"00010")==0)
	printf("$v0");
	if(strcmp(bin_reg,"00011")==0)
	printf("$v1");
	if(strcmp(bin_reg,"00100")==0)
	printf("$a0");
	if(strcmp(bin_reg,"00101")==0)
	printf("$a1");
	if(strcmp(bin_reg,"00110")==0)
	printf("$a2");
	if(strcmp(bin_reg,"00111")==0)
	printf("$a3");
	if(strcmp(bin_reg,"01000")==0)
	printf("$t0");
	if(strcmp(bin_reg,"01001")==0)
	printf("$t1");
	if(strcmp(bin_reg,"01010")==0)
	printf("$t2");
	if(strcmp(bin_reg,"01011")==0)
	printf("$t3");
	if(strcmp(bin_reg,"01100")==0)
	printf("$t4");
	if(strcmp(bin_reg,"01101")==0)
	printf("$t5");
	if(strcmp(bin_reg,"01110")==0)
	printf("$t6");
	if(strcmp(bin_reg,"01111")==0)
	printf("$t7");
	if(strcmp(bin_reg,"10000")==0)
	printf("$s0");
	if(strcmp(bin_reg,"10001")==0)
	printf("$s1");
	if(strcmp(bin_reg,"10010")==0)
	printf("$s2");
	if(strcmp(bin_reg,"10011")==0)
	printf("$s3");
	if(strcmp(bin_reg,"10100")==0)
	printf("$s4");
	if(strcmp(bin_reg,"10101")==0)
	printf("$s5");
	if(strcmp(bin_reg,"10110")==0)
	printf("$s6");
	if(strcmp(bin_reg,"10111")==0)
	printf("$s7");
	if(strcmp(bin_reg,"11000")==0)
	printf("$t8");
	if(strcmp(bin_reg,"11001")==0)
	printf("$t9");
	if(strcmp(bin_reg,"11100")==0)
	printf("$gp");
	if(strcmp(bin_reg,"11101")==0)
	printf("$sp");
	if(strcmp(bin_reg,"11110")==0)
	printf("$fp");
	if(strcmp(bin_reg,"11111")==0)
	printf("$ra");
}	
	
void fun_r(char bin_fun[7],char opcode[6])
{
	if(strcmp(bin_fun,"100000")==0&&strcmp(opcode,"000000")==0)
	printf("add");
	if(strcmp(bin_fun,"100001")==0)
	printf("addu");
	if(strcmp(bin_fun,"001000")==0&&strcmp(opcode,"000000")==1)
	printf("addi");
	if(strcmp(bin_fun,"001001")==0)
	printf("addiu");
	if(strcmp(bin_fun,"001001")==0)
	printf("addiu");
	if(strcmp(bin_fun,"001100")==0)
	printf("andi");
	if(strcmp(bin_fun,"011010")==0)
	printf("div");
	if(strcmp(bin_fun,"011011")==0)
	printf("divu");
	if(strcmp(bin_fun,"011000")==0)
	printf("mult");
	if(strcmp(bin_fun,"011001")==0)
	printf("multu");
	if(strcmp(bin_fun,"100111")==0)
	printf("nor");
	if(strcmp(bin_fun,"100101")==0)
	printf("or");
	if(strcmp(bin_fun,"001101")==0)
	printf("ori");
	if(strcmp(bin_fun,"000000")==0)
	printf("sll");
	if(strcmp(bin_fun,"000100")==0&&strcmp(opcode,"000000")==0)
	printf("sllv");
	if(strcmp(bin_fun,"000011")==0)
	printf("sra");
	if(strcmp(bin_fun,"000111")==0)
	printf("srav");
	if(strcmp(bin_fun,"000010")==0&&strcmp(opcode,"000000")==0)
	printf("srl");
	if(strcmp(bin_fun,"000110")==0)
	printf("srlv");
	if(strcmp(bin_fun,"100010")==0)
	printf("sub");
	if(strcmp(bin_fun,"100011")==0&&strcmp(opcode,"000000")==0)
	printf("subu");
	if(strcmp(bin_fun,"100110")==0)
	printf("xor");
	if(strcmp(bin_fun,"001110")==0)
	printf("xori");
	if(strcmp(bin_fun,"101010")==0)
	printf("slt");
	if(strcmp(bin_fun,"101001")==0)
	printf("sltu");
	if(strcmp(bin_fun,"001010")==0)
	printf("slti");
	if(strcmp(bin_fun,"001001")==0)
	printf("sltiu");
	if(strcmp(bin_fun,"000100")==0)
	printf("beq");
	if(strcmp(bin_fun,"000101")==0)
	printf("bne");
	if(strcmp(bin_fun,"000010")==0&&strcmp(opcode,"000000")==1)
	printf("j");
	if(strcmp(bin_fun,"000011")==0)
	printf("jal");
	if(strcmp(bin_fun,"001000")==0&&strcmp(opcode,"000000")==0)
	printf("jr");
	if(strcmp(bin_fun,"100000")==0&&strcmp(opcode,"000000")==1)
	printf("lb");
	if(strcmp(bin_fun,"100011")==0)
	printf("lw");
	if(strcmp(bin_fun,"101000")==0)
	printf("sb");
	if(strcmp(bin_fun,"101011")==0)
	printf("sw");
	if(strcmp(bin_fun,"010000")==0)
	printf("mfhi");
	if(strcmp(bin_fun,"010010")==0)
	printf("mflo");
	if(strcmp(bin_fun,"010001")==0)
	printf("mthi");
	if(strcmp(bin_fun,"010011")==0)
	printf("mtlo");
	
}	
	
int r_inst_d(char bin_str[33])
{
	char opcode[]="000000";
	char funcode[7];
	char rs[6];
	char rt[6];
	char rd[6];
	char shift[6];
	memset(funcode,'\0',7);
	memset(rs,'\0',6);
	memset(rt,'\0',6);
	memset(rd,'\0',6);
	memset(shift,'\0',6);
	strncpy(rs,bin_str+6,5);	
	strncpy(rt,bin_str+11,5);
	strncpy(rd,bin_str+16,5);
	strncpy(shift,bin_str+21,5);
	strncpy(funcode,bin_str+26,6);
	if(strncmp(funcode,"0110",4)==0)
	{
		fun_r(funcode,opcode);
		printf("  ");
		register_r(rs);
		printf(", ");
		register_r(rt);
		return 0;
	}
	if(strncmp(funcode,"0000",4)==0)
	{
		fun_r(funcode,opcode);
		printf("  ");
		register_r(rd);
		printf(", ");
		register_r(rt);
		printf(", ");
		printf("%ld",strtol(shift,NULL,2));
		return 0;
	}
	if(((strcmp(funcode,"001000")&&strcmp(funcode,"010001"))&&strcmp(funcode,"010011"))==0)
	{
		fun_r(funcode,opcode);
		printf("  ");
		register_r(rs);
		return 0;
	}
	if(strcmp(funcode,"010000")&&strcmp(funcode,"010010")==0)
	{
		fun_r(funcode,opcode);
		printf("  ");
		register_r(rd);
		return 0;
	}
	fun_r(funcode,opcode);
	printf("  ");
	register_r(rd);
	printf(", ");
	register_r(rs);
	printf(", ");
	register_r(rt);
	return 0;
}				 	

int ij_inst_d(char bin_str[33],char funcode[7])
{
	char rs[6];
	char rt[6];
	char con[17];
	char addr[27];
	memset(rs,'\0',6);
	memset(rt,'\0',6);
	memset(con,'\0',17);
	memset(addr,'\0',17);
	strncpy(rs,bin_str+6,5);
	strncpy(rt,bin_str+11,5);
	strncpy(con,bin_str+16,16);
	strncpy(addr,bin_str+6,26);
	if(strcmp(funcode,"000100")==0||strcmp(funcode,"000101")==0)
	{
		fun_r(funcode,funcode);
		printf("  ");
		register_r(rs);
		printf(", ");
		register_r(rt);
		printf(", ");
		printf("%ld",strtol(con,NULL,2));
		return 0;
	}	
	if(strcmp(funcode,"000010")==0||strcmp(funcode,"000011")==0)
	{
		fun_r(funcode,funcode);
		printf("  ");
		printf("%ld",strtol(addr,NULL,2));
		return 0;
	}	
	if(strcmp(funcode,"100000")==0||strcmp(funcode,"100011")==0)
	{
		fun_r(funcode,funcode);
		printf("  ");
		register_r(rt);
		printf(", ");
		printf("%ld(",strtol(con,NULL,2));
		register_r(rs);
		printf(")");
		return 0;
	}	
	if(strcmp(funcode,"101000")==0||strcmp(funcode,"101011")==0)
	{
		fun_r(funcode,funcode);
		printf("  ");
		register_r(rt);
		printf(", ");
		printf("%ld(",strtol(con,NULL,2));
		register_r(rs);
		printf(")");
		return 0;
	}
	fun_r(funcode,funcode);
	printf("  ");
	register_r(rt);
	printf(", ");
	register_r(rs);
	printf(", ");
	printf("%ld",strtol(con,NULL,2));
	return 0;
}	
	

int main()
{
	char filename[MAXNAMELEN2];
	memset( filename, '\0', MAXNAMELEN2 );
	printf("Enter the code file name with extension:");
	 
	scanf("%s",filename);
	if(strlen(filename)>MAXNAMELEN2)
	{
		printf("\nFile name has exceeded the maximum length");
		exit(1);
	}	
	
	int i=0;
	while(filename[i]!='.')
	{
		i++;
		if(i==MAXNAMELEN2)
		break;
	}
	if(i<=MAXNAMELEN2-4)
	{
		if(filename[i+1]!='t')
		{
			printf("\nInvalid file extension");
			exit(1);
		}
		else
		{
			if(filename[i+2]!='x')	
			{
				printf("\nInvalid file extension");
			    exit(1);
			 }
			 else
			 {
				 if(filename[i+3]!='t')	
				 {
					 printf("\nInvalid file extension");
			         exit(1);   
			      }   
			  }
		}
	}		         
		
	
	else
	{
		printf("\nInvalid file name");
		exit(1);
	}
	FILE*fp;
	fp=fopen(filename,"r");
	char strn[MAXNAMELEN2];
	strncpy(strn,filename+4,4);
	strn[4]='\0';
	strcat(strn,".asm");
	freopen(strn,"w",stdout);
	char bin_str[33];
	memset(bin_str,'\0',33);
	while(fscanf(fp,"%s",bin_str)==1)
	{
		
		int i;
		for(i=0;i<strlen(bin_str);i++)
		{
			if(bin_str[i]=='0'||bin_str[i]=='1')
			continue;
			else
			{
				printf("File does not consist of binary strings");
				exit(1);
			}		
		}
		char opcode[7];
		memset(opcode,'\0',7);
		strncpy(opcode,bin_str,6);
		if(strcmp(opcode,"000000")==0)
		r_inst_d(bin_str);
		else
		ij_inst_d(bin_str,opcode);
		printf("\n");
		char eas[100];
		fscanf(fp,"%[^\n]s",eas);
		//printf("%s",eas);
     }	
	
	return 0;		
				
}	

