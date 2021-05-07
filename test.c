#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
	if( argc == 3 ){
        char data;
        FILE *fp = fopen(argv[2],"r");
        if(!fp){
			printf("错误：文件读取失败\n");
            return -1;
        }            
        if( !strcmp(argv[1],"-c") ){
			char temp;
            int num = 0;
            temp = fgetc(fp);
			while( temp != EOF ){
                temp = fgetc(fp);
                num++;
			}
            printf("该文本文件的字符数为：%d\n",num);    
        }
        else if( !strcmp(argv[1],"-w") ){
			int w = 0;
            char a = fgetc(fp);
            while( a != EOF){
                if( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') ){
                    while( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') )
                        a =fgetc(fp);
                    w++;
                    a =fgetc(fp);    
                }
                else
                    a =fgetc(fp);
            }
            printf("该文本文件的单词数为：%d\n",w);   
        }
        else if( !strcmp(argv[1],"-l") ){
			char temp;
			int num = 1;
            temp = fgetc(fp);
			while( temp != EOF ){
                if(temp == '\n'){
					num++;
                }
                temp = fgetc(fp);  
			}
            printf("该文本文件的行数为：%d\n",num);
        }
        else{
			printf("错误：参数超出范围！\n");
            printf("允许参数：-c，-w，-l\n");
        }
        int n=fclose(fp);
    }
    else{
		printf("错误：运行参数必须要3个\n");
		printf("用法：wc.exe [parameter] [file_name]\n");
    }
	system("pause");
	return 0;
}
