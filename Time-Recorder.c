#include<stdio.h>       //Submitted by: Princess Steevelyn T. Mama-o//
#include<stdlib.h>      //BSCS 1-3//
#include<time.h>
#include<string.h>
#include<ctype.h>
    
    int fnOpenFile();
    int fnIDProcess();
    int fnConfirmID();
    int fnLogMode();
    int fnRetry();
    
    FILE*TRLogFile;
    struct tm*dtmCurrent;
    char strFileName[50];
    char strID[32];
    char strBuffer[50];
    char charLetter, charChoice, charConfirmID;
    int  intLength, intNum;
 
    int main(){
		fnOpenFile();
		return 0;
    }

    int fnOpenFile(){ 
        time_t dtmSystem;
        time(&dtmSystem);
        dtmCurrent=localtime(&dtmSystem);
        sprintf(strFileName,"TR%d%02d%02d.txt",dtmCurrent-> tm_year+1900,dtmCurrent->tm_mon+1,dtmCurrent->tm_mday);
        printf("\t\t\t\tTIME RECORDER\n");
        TRLogFile= fopen(strFileName,"a+");
        printf("\n\n\t\t     TO ACCESS AN ACCOUNT,ENTER ID NUMBER:\n\t\t->");
        fnIDProcess();
    }
 
    int fnIDProcess(){

        do{
           gets(strID); 
           intLength= strlen(strID); 
           system("cls");
           if(intLength>=10&&intLength<=32){
           		for(intNum=0;intNum<strlen(strID);intNum++){
           			if(isalnum(strID[intNum])==0){
           				printf("\n\n\t\tRemove Special Characters");
           				printf("\n\n\t\tEnter ID NUMBER->");
           				fnIDProcess();
           			}
        		}           
          }
           else
           printf("\n\n\t\tENTER ID AGAIN\n\t\t(Minimum of 10 and Maximum of 32)\n\t\t->");                     
           }while(intLength<10||intLength>32);
           system("cls");
           fnConfirmID();        
	}
                
    int fnConfirmID(){
        do{
           printf("\n\n\t\tPress [C] to Continue\n\t\tPress [A] to Change ID\n\t\t->");
           scanf(" %c",&charConfirmID);
           if(charConfirmID=='C'||charConfirmID=='c'){
           system("cls");
           fnLogMode();
                            }
           else if (charConfirmID=='A'||charConfirmID=='a')
           fnIDProcess();
           else
           printf("\n\t\tInvalid");
           system("cls");
        }while(charConfirmID!='C'&&charConfirmID!='c'&&charConfirmID!='A'&&charConfirmID!='a');
    }

    int fnLogMode(){
        do{ 
    
           printf("\n\n\t\tCHOOSE LOG MODE:\n\t\tEnter I or O:\n\t\t->");
           scanf(" %c",&charLetter);
           strftime(strBuffer,50,"%Y%m%d%H%M",dtmCurrent);
           if(charLetter=='I'||charLetter=='i'){
           		fprintf(TRLogFile,"\n%s%s",strID,strBuffer);
           		putc('I',TRLogFile);
           		printf("\n\n\t\t\t\tDone Recording!");
           		system("cls");
          }
           else if(charLetter=='O'||charLetter=='o'){
           		fprintf(TRLogFile,"\n%s%s",strID,strBuffer);
           		putc('O',TRLogFile);
           		printf("\n\n\t\t\t\tDone Recording!");
           		system("cls");  
          }
           else{
           		system("cls");
           		printf("\n\n\t\tInvalid LOG MODE\n\t\tI or O ONLY\n");
          }
          }while(charLetter!='i'&&charLetter!='o'&&charLetter!='I'&&charLetter!='O');
           fnRetry();
          }          
            
    int fnRetry(){
           printf("\n\n\t\t     Press C: To use the program AGAIN\n\t\t     Press any KEY to exit\n\t\t->");
           scanf(" %c",&charChoice);
           system("cls");
           
           if(charChoice=='C'||charChoice=='c'){
           		printf("\n\n\t\t       TO ACCESS AN ACCOUNT,ENTER ID NUMBER:\n\t\t->");
           		gets(strID);
           		fnIDProcess();
          }
           else{
           		printf("\n\n\t\t\t\tTHANK YOU\n");
                fclose(TRLogFile);
                exit(0);
          }
    }
