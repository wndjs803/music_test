#include <malloc.h>
#include <string.h>
#include "linkedlist.h"


int read_command(char* cmd);

static Node* _head = NULL;
static Node* _tail = NULL;
static Node* _cur_node = NULL;

int main() {
    int songNumber=0;
    char* songName;
    int cmdNumber=0;
    char cmd[5];
    Node** musictitle=NULL;



    scanf("%d", &songNumber);
    musictitle = (Node**)malloc(sizeof(Node*) * songNumber);
    for(int i=0; i<songNumber; i++){
        musictitle[i] = (Node*)malloc(sizeof(Node) * 10);
    }
    for(int i=0; i<songNumber; i++){
        scanf("%s", songName);
        if(i==0){
            musictitle[i]->prev = _head;}
        else{
            musictitle[i]->prev = musictitle[i-1];}
        musictitle[i]->data = songName;
        if(i == songNumber-1){
            musictitle[i]->next = _tail;}
        else{
            musictitle[i]->next = musictitle[i+1];
        }
    }
    char* ms;
    int index;
    int i=0;
    _cur_node = musictitle[0];

    scanf("%d", &cmdNumber);
    while (i<cmdNumber){
        i++;
        scanf("%s", cmd);
        switch(read_command(cmd)){
//            case 1:
//                //add
//                scanf("%s", ms);
//                append(strlen(ms), ms);
//                break;
//            case 2:
//                //del
//                scanf("%s", ms);
//                delete(ms);
//                delete_node(_cur_node);
//                break;
//            case 3:
//                //list
//                print();
//                break;
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
                printf("%s is now playing!\n", _cur_node->data);
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