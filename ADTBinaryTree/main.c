#include <stdio.h>
#include "BinSTree.h"


void menu() {
    printf("1. Insert Node\n");
    printf("2. Print Tree\n");
    printf("3. Traversal PreOrder\n");
    printf("4. Traversal InOrder\n");
    printf("5. Traversal PostOrder\n");
    printf("6. Traversal LevelOrder\n");
    printf("7. Search node Tree\n");
    printf("8. Jumlah Daun/Leaf\n");
    printf("9. Kedalaman Tree\n");
    printf("10. Membandingkan 2 Node Tree\n");
    printf("11. Exit\n");
    printf("Pilih menu: ");
}

int main(){

    BinTree bintree;
    address node;
    boolean is_found;
    boolean exit = false;
    int menu_select;
    int arg_int; 
    char arg_char1, arg_char2;

    while(!exit) {
        menu();
        scanf(" %d", &menu_select);
        getchar();

        switch (menu_select)
        {
        case 1:
            printf("Root untuk di-insert: ");
            scanf("%c", &arg_char1);
            if (arg_char1 == '\n'){
                printf("Masukkan infonya di root: ");
                scanf("%c", &arg_char1);
                MakeTree(arg_char1, Nil, Nil, &bintree);
            } else {
                node = BinSearch(bintree, arg_char1);
                if (node == Nil){
                    printf("Node tidak ditemukan mff.\n");
                    break;
                } else {
                    printf("Pilih tirai 1 (kiri) atau tirai 2 (kanan): ");
                    scanf("%d", &arg_int);
                    getchar();
                    printf("Masukkan infonya: ");
                    scanf(" %c", &arg_char2);
                    if (arg_int == 1){
                        if (node->left == Nil){
                            AddDaun(&bintree, arg_char1, arg_char2, true);
                        } else {
                            printf("Sudah ada Brook");
                        }
                    } else if (arg_int == 2){
                        if (node->right == Nil){
                            AddDaun(&bintree, arg_char1, arg_char2, false);
                        } else {
                            printf("Usdah ada brok");
                        }
                    }
                    
                }
            }
            break;
        case 2:
            printf("Seluruh node pada binary tree\n");
            PrintTree(bintree,1);
            printf("\n");
            break;
        case 3:
            printf("Tree dengan pre order\n");
            PreOrder(bintree);
            printf("\n");
			break;
        case 4:
            printf("Tree dengan in order\n");
            InOrder(bintree);
            printf("\n");
			break;
        case 5:
            printf("Tree dengan post order\n");
            PostOrder(bintree);
            printf("\n");
			break;
        case 6:
            printf("Masukkan berapa level yang ingin diprint: ");
            scanf("%d", &arg_int);
            printf("Tree dengan Level Order\n");
            LevelOrder(bintree, arg_int);
            printf("\n");
			break;
        case 7:
            printf("Node yang ingin dicari: ");
            scanf(" %c", &arg_char1);
            if(Search(bintree, arg_char1) == true) {
                printf("node dengan info %c ditemukan\n", arg_char1);
            }else {
                printf("node dengan info %c tidak ditemukan\n", arg_char1);
            }
            break;
        case 8:
            arg_int = nbDaun(bintree);
            printf("Banyak leaf adalah: %d\n", arg_int);
            break;
        case 9:
            printf("Kedalaman tree adalah %d\n", Depth(bintree));
            break;
        case 10:
            printf("Node yang ingin pilih: ");
            scanf(" %c", &arg_char1);
            printf("Node yang ingin dibandingkan: ");
            scanf(" %c", &arg_char2);
            if(Search(bintree, arg_char1) == false){
                printf("Node dengan info %c tidak ditemukan\n", arg_char1);
                break;
            }
            if(Search(bintree, arg_char2) == false) {
                printf("Node dengan info %c tidak ditemukan\n", arg_char1);
                break;
            }
            arg_char1 = Max(arg_char1, arg_char2);
            printf("Yang paling besar adalah %c\n", arg_char1);
            break;
        case 11:
            exit = true;
            break;
        default:
            printf("Pilihan tidak valid\n");
            break;
        }

        if(!exit) {
            printf("Klik apapun untuk melanjutkan\n");
            getchar();
            getchar();
        }
    }
}
