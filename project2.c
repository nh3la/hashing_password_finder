#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <openssl/sha.h>
#include <ctype.h>

int check_sha256(char *input_string, char *expected_hash, char *hex_hash){
	unsigned char hash[32];

	SHA256((unsigned char *)input_string, strlen(input_string), hash);

	for (int i = 0; i < 32; i++){
		sprintf(&hex_hash[i * 2], "%02x", hash[i]);
	}
	
	hex_hash[64] = '\0';

	return strcasecmp(hex_hash, expected_hash) == 0;

}

int main(int argc, char *argv[]){
	char given[65] = { '\0' };

	if(argc < 2){
		printf("error\n");
		return 1;
	}

	strcpy(given, argv[1]);
	given[64] = '\0';

	char pass[100];

	int sh = 0;

	while(fgets(pass, sizeof(pass), stdin) != NULL){
		size_t len = strlen(pass);
		if (len > 0 && pass[len - 1] == '\n'){
			pass[len - 1] = '\0';
		}

		len = strlen(pass);

		for(int i = 0; i < len + 1; i++){
        	char num[100];
            strcpy(num, pass);
			char hash1[65];
			if(i == len){
				sh = check_sha256(pass, given, hash1);
				if(sh == 1){
					printf("Found password: SHA256(%s) = %s\n", pass, given);
				}
			}
			else{

			
            if('A' <= pass[i] && 'Z' >= pass[i]){
            	num[i] = pass[i] + 32;
				sh = check_sha256(num, given, hash1);
				if(sh == 1){
					printf("Found password: SHA256(%s) = %s\n", num, given);
				}
            }
            else if('a' <= pass[i] && 'z' >= pass[i]){
            	num[i] = pass[i] - 32;
				sh = check_sha256(num, given, hash1);
				if(sh == 1){
					printf("Found password: SHA256(%s) = %s\n", num, given);			
				}
            }
			}
			
		if(sh == 1){
			break;
		}
		if(sh == 0){
			continue;
		}
		}
		if(sh == 1){
			break;
		}
		}

	return 0;
		
	}

	




