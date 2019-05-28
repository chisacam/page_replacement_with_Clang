#include <stdio.h>
#include <stdlib.h>

char name[][5] = {"NULL", "aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh", "iii", "jjj"};

void push(int * table, int pagenum, int * topp){
    table[++*topp] = pagenum;
}

void insert_page(int * table, int pagenum, int tablesize, int * pagecount, int * topp){
    int check, temp, flag, prev_var;
    for(check = 0; check < tablesize; check++){
        if(table[check] == 0){
            flag = 1;
            break;
        }else if(table[check] == pagenum){
            flag = 2;
            temp = check;
            break;
        }else{
            flag = 3;
        }
    }

    switch(flag){
        case 1:
            push(table, pagenum, topp);
            pagecount[pagenum]++;
            break;
        case 2:
            if(temp == 0){
                table[0] = table[1];
                table[1] = table[2];
                table[2] = pagenum;
                pagecount[pagenum]++;
            }else if(temp == 1){
                table[1] = table[2];
                table[2] = pagenum;
                pagecount[pagenum]++;
            }else if(temp == 2){
                pagecount[pagenum]++;
            }else{
                printf("error!!!\n");
                break;
            }
            break;
        case 3:
            table[0] = table[1];
            table[1] = table[2];
            table[2] = pagenum;
            pagecount[pagenum]++;
            break;
    }
}

void print_table(int * table, int tablesize, int * pagecount){
    int printnum;
    printf("Contain    Pageno    Pagecount\n");
    for(printnum = tablesize - 1; printnum >= 0;printnum--){
        printf("%s        %d         %d\n", name[table[printnum]], table[printnum], pagecount[table[printnum]]);
    }
}

void pageinit(int * pagecount){
    int j;
    for(j = 0;j < 10;j++){
        pagecount[j] = 0;
    }
}

void tableinit(int * table, int tablesize){
    int j;
    for(j = 0;j < tablesize;j++){
        table[j] = 0;
    }
}

int main(){
    int selectmenu, pagenum, tablesize, top = -1;
    int * table = (int *)malloc(sizeof(int));
    int * pagecount = (int *)malloc(sizeof(int));
    int * topp = &top;
    printf("메모리 사이즈를 입력하세요. : ");
    scanf("%d", &tablesize);
    
    tableinit(table, tablesize);
    pageinit(pagecount);

    while(1){
        printf("----------------------- \n");
        printf("1. insert\n");
        printf("2. print\n");
        printf("3. exit\n");
        printf("----------------------- \n");
        printf("메뉴를 선택하세요. : ");
        scanf("%d", &selectmenu);
        if(selectmenu == 3){
            break;
        }
        switch(selectmenu){
            case 1:
                printf("1~10 사이의 페이지 숫자를 입력하세요. : ");
                scanf("%d", &pagenum);
                if(pagenum > 10 || pagenum < 1){
                    printf("숫자는 1~10 사이의 자연수여야만 합니다.\n");
                    continue;
                }
                insert_page(table, pagenum, tablesize, pagecount, topp);
                break;
            case 2:
                print_table(table, tablesize, pagecount);
                break;
            default:
                printf("입력을 다시 확인해주세요.");
                break;
        }
    }
    free(table);
    free(pagecount);
    return 0;
}