#include<stdio.h>
#include<string.h>
int main(){
    //打开文件
    FILE*file=fopen("C:\\Users\\Nonep\\Desktop\\input.txt","r");
    //读取文件
    char str[1024];
    int n;
    int line=0;
    int is_line_valid=0;//0表示不合法
    char word[1024][100];
    char temp[1024];
    int len=0;
    int index=0;//总单词数
    int word_counts[1024]={0};
    int is_repeat=0;
    while((n=fread(str,1,1024,file))!=0){
		for(int i=0;i<n;i++){
		    if(str[i]!='\n'&&str[i]!=' '&&str[i]!='\t'){
		    	 is_line_valid=1;
			}
			if(str[i]=='\n'){
				if(is_line_valid){
					line++;
					is_line_valid=0;
				}
			}//求总行数
			if(str[i]>='A'&&str[i]<='Z'){
				str[i]=str[i]+32;//都转为小写
		    }
		    //printf("%c",str[i]);//如果放在for循环里面就太窄
		    if(str[i]>='a'&&str[i]<='z'){
				temp[len]=str[i];
				len++;
			}
			if(str[i]==' '||str[i]==','||str[i]=='.'||str[i]=='?'||str[i]=='!'||str[i]==':'||str[i]=='\n'||str[i]=='\"'||str[i]==';'){
				if(len>0){
					temp[len]='\0';
					//len>0表示前面已经有一个单词
					//判断是否重复，分两种情况讨论
					//遍历比较
					//重复：
					for(int j=0;j<index;j++){
						if(strcmp(word[j],temp)==0){//相同返回0
							word_counts[j]++;
							is_repeat=1;
							break;
						}
					}
					if(is_repeat==0){//没有重复
						//将temp复制过去
						strcpy(word[index],temp);
						word_counts[index]=1;
						index++;
					}
				}
				len=0;
				is_repeat=0;
			}
	    }
	if(is_line_valid){
				line++;
					}
	for(int i=0;i<index-1;i++){
		for(int j=i+1;j<index;j++){
			if(word_counts[i]<word_counts[j]){
			    int temp1=word_counts[i];
				word_counts[i]=word_counts[j];
				word_counts[j]=temp1;
				
				char temp_str[100];
				char*temp2=word[i];
				char*temp3=word[j];
				strcpy(temp_str,temp2);
				strcpy(temp2,temp3);
				strcpy(temp3,temp_str);
						}
					}
				}
    }
	//关闭文件
	fclose(file);
	printf("总行数:%d\n",line);
	printf("总单词数:%d\n",index);
	printf("高频单词Top5:");
	printf("\n");
	for(int i=0;i<5;i++){
			printf("%s:%d\n",word[i],word_counts[i]);
		}
}