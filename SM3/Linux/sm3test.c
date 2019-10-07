/*************************************************************************
       > File Name: sm3test.c
       > Author:NEWPLAN
       > E-mail:newplan001@163.com
       > Created Time: Thu Apr 13 23:55:50 2017
************************************************************************/
#include <string.h>
#include <stdio.h>
#include "sm3.h"

void test_rotl(int a,int n){
#define  SHL(x,n) (((x) & 0xFFFFFFFF) << n)
#define ROTL(x,n) (SHL((x),n) | ((x) >> (32 - n)))
int b = ROTL(a,n);
printf("%08X\n",b);
}
void dump_sm3_hash(unsigned char output[32]) {
	int i;
	printf("Hash:\n   ");
	for (i = 0; i < 32; i++)
	{
		printf("%02x", output[i]);
		if (((i + 1) % 4 ) == 0) printf(" ");
	}
	printf("\n");
}

int main( int argc, char *argv[] )
{
    /* Attention! Type long is 8 Bytes on Linux 64, 4 Bytes on Linux 32 !
     * We should use unsigned int !                 */
	printf("sizeof(long)=%zu\n",sizeof(long));
	//test_rotl(0b12345678,1);
	test_rotl(0x12345678,4);
	test_rotl(0x12345678,32);
	//test_rotl(0x12345678,-1);
	test_rotl(0x12345678,-32);
        printf("\n---***---***---\n");
	unsigned char *input = (unsigned char*)"abc";
	int ilen = 3;
	unsigned char output[32];
	int i;
	sm3_context ctx;

	printf("Message:\n");
	printf("%s\n", input);
	sm3(input, ilen, output);
        dump_sm3_hash(output);
        
	printf("Message:\n");
	printf("%s\n", output);
	sm3(output, sizeof(output), output);
        dump_sm3_hash(output);
	/*printf("Hash:\n   ");
	for (i = 0; i < 32; i++)
	{
		printf("%02x", output[i]);
		if (((i + 1) % 4 ) == 0) printf(" ");
	}
	printf("\n");*/

	printf("Message:\n");
	for (i = 0; i < 16; i++)
		printf("abcd");
	printf("\n");

	sm3_starts( &ctx );
	for (i = 0; i < 16; i++)
		sm3_update( &ctx, (unsigned char*)"abcd", 4 );
	sm3_finish( &ctx, output );
	memset( &ctx, 0, sizeof( sm3_context ) );

	printf("Hash:\n   ");
	for (i = 0; i < 32; i++)
	{
		printf("%02x", output[i]);
		if (((i + 1) % 4 ) == 0) printf(" ");
	}
	printf("\n");
	return 0;
}
