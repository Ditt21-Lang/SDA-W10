#include "BinSTree.h"
#include "stdlib.h"
#include "queue.h"

address AlokasiTree (infotype X){
    address newNode;
    newNode = (address)malloc(sizeof(Node));
    newNode->info = X;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

BinTree Tree (infotype Akar, BinTree L, BinTree R){
    address root = AlokasiTree(Akar);
    root->left = L;
    root->right = R;
    return root;
}

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P){
    *P = Tree(Akar, L, R);
}

boolean IsEmpty (BinTree P){
    if(P == Nil){
        return true;
    } else {
        return false;
    }
}

void PreOrder (BinTree P){
    if(IsEmpty(P)){
        return;
    } else {
        printf("%c", P->info);
        PreOrder(P->left);
        PreOrder(P->right);
    }
}

    
void InOrder (BinTree P){
    if(IsEmpty(P)){
        return;
    } else {
        InOrder(P->left);
        printf("%c", P->info);
        InOrder(P->right);
    }
}

void PostOrder (BinTree P){
    if(IsEmpty(P)){
        return;
    } else {
        PostOrder(P->left);
        PostOrder(P->right);
        printf("%c", P->info);
    }
}

void LevelOrder(BinTree P, int maks_level) {
    if (P == NULL) {
        return;
    }

    int level_skrng = 0;
    Queue q1, q2, temp;
    BinTree cursor, cursor2, cursor3;

    CreateQueue(&q1);
    CreateQueue(&q2);
    EnQueue(&q1, P);

    while (!is_Empty(q1) && level_skrng <= maks_level) {
        while (!is_Empty(q1)){
            deQueue(&q1, &cursor);
            printf("%c ", cursor->info);

            if (cursor->left != Nil) {
                EnQueue(&q2, cursor->left);
            }

            if (cursor->right != Nil) {
                EnQueue(&q2, cursor->right);
            }
        }
        temp = q1;
        q1 = q2;
        q2 = temp;
        level_skrng++;
    }
    printf("\n");
}

void PrintTree (BinTree P, int h){
    if(IsEmpty(P)){
        return;
    } else {
        PrintTree(P->left, h + 4);
        int i = 0;
		for ( i; i < h; i++){
            printf(" ");
        }
        printf("%c\n", P->info);
		PrintTree(P->right, h + 4);
    }   
}

boolean Search (BinTree P, infotype X){
    if(IsEmpty(P)){
        return false;
    } else {
        if(P->info == X){
            return true;
        } else {
            return Search(P->left, X) || Search(P->right, X);
        }
    }
}

int nbDaun (BinTree P){
    if(P == Nil){
        return 0;
    } else {
        if (P->left == Nil && P->right == Nil ){
            return 1;
        } else {
            return nbDaun(P->left) + nbDaun(P->right);
        }
    }
}

int Depth (BinTree P){
    if(P == Nil){
        return 0;
    } else {
        return 1 + Max(Depth(P->left), Depth(P->right));
    }
}

int Max (infotype Data1, infotype Data2){
    if (Data1 > Data2){
        return Data1;
    } else {
        return Data2;
    }
}

address EitherNotNil(address node1, address node2){
    if (node1 != Nil){
        return node1;
    } else {
        return node2;
    }
}

void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri){
    address node =  BinSearch(*P, X);
    if (node == Nil){
        return;
    } else {
        address newNode = AlokasiTree(Y);
        if (Kiri){
            node->left = newNode;
        } else {
            node->right = newNode;
        }
    }
}

address BinSearch (BinTree P, infotype X){
    if(IsEmpty(P)){
        return Nil;
    } else {
        if(P->info == X){
            return P;
        } else {
            return EitherNotNil(BinSearch(P->left, X), BinSearch(P->right, X));
        }
    }
}

void DestroyTree (BinTree *P){
    if(*P == Nil){
        return;
    } else {
        DestroyTree(&(*P)->left);
        DestroyTree(&(*P)->right);
        DeAlokasiTree(*P);
    }
}

void DeAlokasiTree (address P){
    free(P);
}
