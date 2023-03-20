#include<stdio.h>
#include<string.h>

int main(){
	char ans[100];

	while(1){
		printf("SSAFY_ECHOBOT >> ");
		scanf("%s", ans);
		printf("%s\n",ans);

		int a=0;
		while(ans[a]){
			if(ans[a]>=65&&ans[a]<=90) ans[a]+=32; //소문자로 바꾸기
			a++;
		}
		if(strcmp(ans,"exit")==0||strcmp(ans,"bye")==0){
			return 0;
		}
	}
}
