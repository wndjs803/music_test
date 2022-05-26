#include <malloc.h>
#include <string.h>
#include "linkedlist.h"

int read_command(char* cmd);

int main() {
    int songNumber=0;
    char songName[10];
    int cmdNumber=0;
    char cmd[5];

    Node* cur_node;

    scanf("%d", &songNumber);
    for(int i=0; i<songNumber; i++){
        scanf("%s", songName);
        cur_node=append(strlen(songName), songName);
    }

    int index;
    int i=0;

    scanf("%d", &cmdNumber);
    while (i<cmdNumber){
        i++;
        scanf("%s", cmd);
        switch(read_command(cmd)){
            case 1:
                //add
                scanf("%s", songName);
                cur_node=append(strlen(songName), songName);
                break;
//            case 2:
//                //del
//                scanf("%s", ms);
//                delete(ms);
//                delete_node(_cur_node);
//                break;
            case 3:
                //list
                print();
                break;
//            case 4:
//                //next
//                next();
//                break;
//            case 5:
//                //prev
//                prev();
//                break;
//            case 6:
//                //move
//                scanf("%d", &index);
//                insert_after(index);
//                break;
            case 7:
                //play
                printf("%s is now playing!\n", cur_node->data);
                break;
//            case 8:
//                //clear
//                clear();
//                break;
            case 9:
//                //quit
//                clear();
                return 0;
                break;
//            case 10:
//                //load
//                scanf("%s", ms);
//                break;
//            case 11:
//                //save
//                scanf("%s", ms);
//                break;
        }
    }
}

int read_command(char* cmd){
    if(!strcmp(cmd,"add")) return 1;
    else if(!strcmp(cmd,"del")) return 2;
    else if(!strcmp(cmd,"list")) return 3;
    else if(!strcmp(cmd,"next")) return 4;
    else if(!strcmp(cmd,"prev")) return 5;
    else if(!strcmp(cmd,"move")) return 6;
    else if(!strcmp(cmd,"play")) return 7;
    else if(!strcmp(cmd,"clear")) return 8;
    else if(!strcmp(cmd,"quit")) return 9;
    else if(!strcmp(cmd,"load")) return 10;
    else return 11;
}