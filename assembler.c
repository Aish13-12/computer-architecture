#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXNAMELEN 20



int registerno(char reg[6]);
long long int convert(int n);



long long int convert(int n) {
    long long int bin = 0;
    int rem, i = 1;
    while (n != 0) {
        rem = n % 2;
        
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

void bintohex(char bin_val[33])
{
	int i;
	char piece[6];
	for(i=0;i<32;)
	{
		
		memset(piece,'\0',sizeof(piece));
		
		strncpy(piece,bin_val+i,4);
		piece[4]='\0';
		//printf("%s",bin_val+i);
		int out=strtol(piece,NULL,2);
		switch(out)
		{
			case 10:
			printf("a");
			break;
		    case 11:
		    printf("b");
		    break;
		    case 12:
		    printf("c");
		    break;
		    case 13:
		    printf("d");
		    break;
		    case 14:
		    printf("e");
		    break;
		    case 15:
		    printf("f"); 
		    break;
		    default:printf("%d",out);
		}
		i=i+4;
		
	}
}		
	
int registerno(char reg[6])
{
	if(strcmp(reg,"$zero")==0)
	return 0;
	if (strcmp(reg,"$v0")==0)
	return 2;
	if (strcmp(reg,"$v1")==0)
	return 3;
	if (strcmp(reg,"$s0")==0)
	return 16;
	if (strcmp(reg,"$s1")==0)
	return 17;
	if (strcmp(reg,"$s2")==0)
	return 18;
	if (strcmp(reg,"$s3")==0)
	return 19;
	if (strcmp(reg,"$s4")==0)
	return 20;
	if (strcmp(reg,"$s5")==0)
	return 21;
	if (strcmp(reg,"$s6")==0)
	return 22;
	if (strcmp(reg,"$s7")==0)
	return 23;
	if (strcmp(reg,"$fp")==0)
	return 30;
	if (strcmp(reg,"$ra")==0)
	return 31;
	if (strcmp(reg,"$a0")==0)
	return 4;
	if (strcmp(reg,"$a1")==0)
	return 5;
	if (strcmp(reg,"$a2")==0)
	return 6;
	if (strcmp(reg,"$a3")==0)
	return 7;
	if (strcmp(reg,"$t0")==0)
	return 8;
	if (strcmp(reg,"$t1")==0)
	return 9;
	if (strcmp(reg,"$t2")==0)
	return 10;
	if (strcmp(reg,"$t3")==0)
	return 11;
	if (strcmp(reg,"$t4")==0)
	return 12;
	if (strcmp(reg,"$t5")==0)
	return 13;
	if (strcmp(reg,"$t6")==0)
	return 14;
	if (strcmp(reg,"$t7")==0)
	return 15;
	if (strcmp(reg,"$t8")==0)
	return 24;
	if (strcmp(reg,"$t9")==0)
	return 25;
	if (strcmp(reg,"$gp")==0)
	return 28;
	if (strcmp(reg,"$sp")==0)
	return 29;
	else
	exit(1);
}

void r_inst(char function[5],char funcode[7],FILE*fp)
{
	
	char reg_out[7];
	char reg_in1[7];
	char reg_in2[7];
	memset(reg_out, '\0', 7);
	memset(reg_in1, '\0', 7);
	memset(reg_in2, '\0', 7);
	fscanf(fp,"%s",reg_out);
	
	fscanf(fp,"%s",reg_in1);
	fscanf(fp,"%s",reg_in2);
	
	int k_1=strlen(reg_out);
	
	int k_2=strlen(reg_in1);
	reg_out[k_1-1]='\0';
	reg_in1[k_2-1]='\0';
	char opcode[7]="000000";
	printf("%s",opcode);
	char rs[6];
	if((strcmp(funcode,"000000")&&strcmp(funcode,"000010"))&&strcmp(funcode,"000011"))
	{
		
		sprintf(rs,"%05lld",convert(registerno(reg_in1)));
		printf("%s",rs);
	}	
	else
	{
		strcpy(rs,"00000");
		printf("%s",rs);
	}	
	char rt[6];
	if((strcmp(funcode,"000000")&&strcmp(funcode,"000010"))&&strcmp(funcode,"000011"))
	{
		sprintf(rt,"%05lld",convert(registerno(reg_in2)));
		printf("%s",rt);
	}	
	else
	{
		sprintf(rt,"%05lld",convert(registerno(reg_in1)));
		printf("%s",rt);
	}
	char rd[6];
	sprintf(rd,"%05lld",convert(registerno(reg_out)));
	printf("%s",rd);
	char shift[6];
	if((strcmp(funcode,"000000")&&strcmp(funcode,"000010"))&&strcmp(funcode,"000011"))
	{
		strcpy(shift,"00000");
	    printf("%s",shift);
	 } 
	else
	{
	    sprintf(shift,"%05lld",convert(atoi(reg_in2)));
	    printf("%s",shift);
	 }   
	
	printf("%s",funcode);
	char bin_str[33];
	snprintf(bin_str,sizeof(bin_str),"%s%s%s%s%s%s",opcode,rs,rt,rd,shift,funcode);
	printf(" (");
	bintohex(bin_str);
	printf(", %s %s, %s, %s)\n",function,reg_out,reg_in1,reg_in2);
	

    
}
void r_inst2(char function[5],char funcode[7],FILE*fp)
{
	char reg_in1[7];
	char reg_in2[7];
	memset(reg_in1, '\0', 7);
	memset(reg_in2, '\0', 7);
	fscanf(fp,"%s",reg_in1);
	fscanf(fp,"%s",reg_in2);
	int k=strlen(reg_in1);
	reg_in1[k-1]='\0';
	char opcode[7]="000000";
	printf("%s",opcode);
	char rs[6];
	sprintf(rs,"%05lld",convert(registerno(reg_in1)));
	printf("%s",rs);
	char rt[6];
	sprintf(rt,"%05lld",convert(registerno(reg_in2)));
	printf("%s",rt);
	char rd[6]="00000";
	printf("%s",rd);
	char shift[6]="00000";
	printf("%s",shift);
	printf("%s",funcode);
	char bin_str[33];
	snprintf(bin_str,sizeof(bin_str),"%s%s%s%s%s%s",opcode,rs,rt,rd,shift,funcode);
	printf(" (");
	bintohex(bin_str);
	printf(", %s %s, %s)\n",function,reg_in1,reg_in2);
}	

void r_inst1(char function[5],char funcode[7],FILE*fp)
{
	
	char reg_in[7];
	memset(reg_in, '\0', 7);
	fscanf(fp,"%s",reg_in);
	char opcode[7]="000000";
	printf("%s",opcode);
	char rs[6];
	sprintf(rs,"%05lld",convert(registerno(reg_in)));
	printf("%s",rs);
	char rt[6];
	strcpy(rt,"00000");
	printf("%s",rt);
	char rd[]="00000";
	printf("%s",rd);
	char shift[]="00000";
	printf("%s",shift);
	printf("%s",funcode);
	char bin_str[33];
	snprintf(bin_str,sizeof(bin_str),"%s%s%s%s%s%s",opcode,rs,rt,rd,shift,funcode);
	printf(" (");
	bintohex(bin_str);
	printf(", %s %s)\n",function,reg_in);
	
}	
void r_instm(char function[5],char funcode[7],FILE*fp)
{
    char reg_in[7];
	memset(reg_in, '\0', 7);
	fscanf(fp,"%s",reg_in);
	char opcode[6]="000000";
	printf("%s",opcode);
	char rs[6];
	if(strcmp(funcode,"010001")&&strcmp(funcode,"010011"))
	{
		strcpy(rs,"00000");
		printf("%s",rs);
	}	
	else
	{
		sprintf(rs,"%05lld",convert(registerno(reg_in)));
		printf("%s",rs);
	}
	char rt[6]="00000";	
	printf("%s",rt);
	char rd[6];
	if(strcmp(funcode,"010000")&&strcmp(funcode,"010010"))
	{
		sprintf(rd,"%05lld",convert(registerno(reg_in)));
		printf("%s",rd);
	}	
	else
	{
        strcpy(rd,"00000");
		printf("%s",rd);
	}
	char shift[6]="00000";	
	printf("%s",shift);
	printf("%s",funcode);
	char bin_str[33];
	snprintf(bin_str,sizeof(bin_str),"%s%s%s%s%s%s",opcode,rs,rt,rd,shift,funcode);
	printf(" (");
	bintohex(bin_str);
	printf(", %s %s)\n",function,reg_in);
}
	
	
void i_inst(char function[5],char funcode[7],FILE*fp)
{
	char reg_in[7];
	char reg_out[7];
	int constant;
	memset(reg_out, '\0', 7);
	memset(reg_in, '\0', 7);
	fscanf(fp,"%s",reg_out);
	fscanf(fp,"%s",reg_in);
	fscanf(fp,"%d",&constant);
	int k_1=strlen(reg_out);
	int k_2=strlen(reg_in);
	reg_out[k_1-1]='\0';
	reg_in[k_2-1]='\0';
	printf("%s",funcode);
	char rs[6];
	char rt[6];
	if(strcmp(funcode,"000100")&&strcmp(funcode,"000101"))
	{
		sprintf(rs,"%05lld",convert(registerno(reg_in)));
	    sprintf(rt,"%05lld",convert(registerno(reg_out)));
	    printf("%s",rs);
	    printf("%s",rt);
	 }
	 else
	 {
		sprintf(rs,"%05lld",convert(registerno(reg_out))); 
	    sprintf(rt,"%05lld",convert(registerno(reg_in)));
	    printf("%s",rs);
	    printf("%s",rt);
	 }
	char addr[17];   
	sprintf(addr,"%016lld",convert(constant));
	printf("%s",addr);
	
	char bin_str[33];
	snprintf(bin_str,sizeof(bin_str),"%s%s%s%s",funcode,rs,rt,addr);
	printf(" (");
	bintohex(bin_str);
	printf(", %s %s, %s, %d)\n",function,reg_out,reg_in,constant);
}	
void i_instw(char function[5],char funcode[7],FILE*fp)
{
	char rs[7];
	char rt[7];
	char constant[7];
	memset(rs,'\0',7);
	memset(rt,'\0',7);
	fscanf(fp,"%s",rt);
	fscanf(fp,"%[^(]s",constant);
	fscanf(fp,"%s",rs);
	int k_1=strlen(rt);
	int k_2=strlen(rs);
	rt[k_1-1]='\0';
	rs[k_2-1]='\0';
	printf("%s",funcode);
	char rs1[6];
	char rt1[6];
	sprintf(rs1,"%05lld",convert(registerno(rs+1)));
	printf("%s",rs1);
	sprintf(rt1,"%05lld",convert(registerno(rt)));
	printf("%s",rt1);
	char addr[17];
	sprintf(addr,"%016lld",convert(atoi(constant)));
	printf("%s",addr);
	char bin_str[33];
	snprintf(bin_str,sizeof(bin_str),"%s%s%s%s",funcode,rs1,rt1,addr);
	printf(" (");
	bintohex(bin_str);
	printf(", %s %s, %s%s))\n",function,rt,constant,rs);
}	
	

void j_inst(char function[5],char funcode[7],FILE*fp)
{
	int constant;
	fscanf(fp,"%d",&constant);
	printf("%s",funcode);
	constant=constant>>2;
	char con[27];
	sprintf(con,"%026lld",convert(constant));
	printf("%s",con);
	char bin_str[33];
	snprintf(bin_str,sizeof(bin_str),"%s%s",funcode,con);
	printf(" (");
	bintohex(bin_str);
	printf(", %s %d)\n",function,constant*2);
	
}	
	

int main()
{
	char filename[MAXNAMELEN];
	memset( filename, '\0', MAXNAMELEN );
	printf("Enter the code file name with extension:");
	 
	scanf("%s",filename);
	if(strlen(filename)>MAXNAMELEN)
	{
		printf("\nFile name has exceeded the maximum length");
		exit(1);
	}	
	
	int i=0;
	while(filename[i]!='.')
	{
		i++;
		if(i==MAXNAMELEN)
		break;
	}
	if(i<=MAXNAMELEN-4)
	{
		if(filename[i+1]!='a')
		{
			printf("\nInvalid file extension");
			exit(1);
		}
		else
		{
			if(filename[i+2]!='s')	
			{
				printf("\nInvalid file extension");
			    exit(1);
			 }
			 else
			 {
				 if(filename[i+3]!='m')	
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
	char strn[MAXNAMELEN];
	strncpy(strn,filename,5);
	strn[5]='\0';
	strcat(strn,"bin.txt");
	freopen(strn,"w",stdout);
	fp=fopen(filename,"r");
	char function[5];
	memset( function, '\0', 5 );
	
	while(fscanf(fp,"%s",function)==1)
	{
		
		
		if(strcmp(function,"#")==0)
		continue;
		if(strcmp(function,"add")==0)
	    r_inst("add","100000",fp);
	    if(strcmp(function,"addi")==0)
	    i_inst("addi","001000",fp);
	    if(strcmp(function,"addu")==0)
	    r_inst("addu","100001",fp);
	    if(strcmp(function,"and")==0)
	    r_inst("and","100100",fp);
	    if(strcmp(function,"nor")==0)
	    r_inst("nor","100111",fp);
	    if(strcmp(function,"or")==0)
	    r_inst("or","100101",fp);
	    if(strcmp(function,"sub")==0)
	    r_inst("sub","100010",fp);
	    if(strcmp(function,"subu")==0)
	    r_inst("subu","100011",fp);
	    if(strcmp(function,"xor")==0)
	    r_inst("xor","100110",fp);
	    if(strcmp(function,"addiu")==0)
	    i_inst("addiu","001001",fp);
	    if(strcmp(function,"andi")==0)
	    i_inst("andi","001100",fp);
	    if(strcmp(function,"ori")==0)
	    i_inst("ori","001101",fp);
	    if(strcmp(function,"xori")==0)
	    i_inst("xori","001110",fp);
	    if(strcmp(function,"slti")==0)
	    i_inst("slti","001010",fp);
	    if(strcmp(function,"sltiu")==0)
	    i_inst("sltiu","001001",fp);
	    if(strcmp(function,"sll")==0)
	    r_inst("sll","000000",fp);
	    if(strcmp(function,"srl")==0)
	    r_inst("srl","000010",fp);
	    if(strcmp(function,"sra")==0)
	    r_inst("sra","000011",fp);
	    if(strcmp(function,"sllv")==0)
	    r_inst("sllv","000100",fp);
	    if(strcmp(function,"srav")==0)
	    r_inst("srav","000111",fp);
	    if(strcmp(function,"srlv")==0)
	    r_inst("srlv","000110",fp);
	    if(strcmp(function,"mult")==0)
	    r_inst2("mult","011000",fp);
	    if(strcmp(function,"multu")==0)
	    r_inst2("multu","011001",fp);
	    if(strcmp(function,"div")==0)
	    r_inst2("div","011010",fp);
	    if(strcmp(function,"divu")==0)
	    r_inst2("divu","011011",fp);
	    if(strcmp(function,"j")==0)
	    j_inst("j","000010",fp);
	    if(strcmp(function,"jal")==0)
	    j_inst("jal","000011",fp);
	    if(strcmp(function,"jr")==0)
	    r_inst1("jr","001000",fp);
	    if(strcmp(function,"mfhi")==0)
	    r_instm("mfhi","010000",fp);
	    if(strcmp(function,"mflo")==0)
        r_instm("mflo","010010",fp);
	    if(strcmp(function,"mthi")==0)
	    r_instm("mthi","010001",fp);
	    if(strcmp(function,"mtlo")==0)
	    r_instm("mtlo","010011",fp);
	    if(strcmp(function,"slt")==0)
	    r_inst("slt","101010",fp);
	    if(strcmp(function,"sltu")==0)
	    r_inst("sltu","101001",fp);
	    if(strcmp(function,"beq")==0)
	    i_inst("beq","000100",fp);
	    if(strcmp(function,"bne")==0)
	    i_inst("bne","000101",fp);
	    if(strcmp(function,"lw")==0)
	    i_instw("lw","100011",fp);
	    if(strcmp(function,"sw")==0)
	    i_instw("sw","101011",fp);
	    if(strcmp(function,"lb")==0)
	    i_instw("lb","100000",fp);
	    if(strcmp(function,"sb")==0)
	    i_instw("sb","101000",fp);
	    }    
	fclose(fp);
return 0;		
}	
