/* Nama File : BinSTree.h 	*/
/* Deskripsi : File header untuk ADT Binary Tree Dinamis */
/* Dibuat oleh : Ade Chandra Nugraha */
/* Tanggal     : 22-11-2001 */

#ifndef _BINTREE_H
#define _BINTREE_H
#include <stdio.h>
#include "linked.h"
#define true 1
#define false 0
#define boolean unsigned char
#define Left(T) (T)->left
#define Right(T) (T)->right
#define InfoList(L) (L)->info
#define Next(L) (L)->next

typedef char infotype;
typedef struct tElmtTree *address;
typedef struct tElmtTree {
	infotype info;
	address left, right;
} Node;	

typedef struct tElmtL *address1;
typedef struct tElmtL {
	infotype info;
	address1 next;
} ElmtL;	

typedef address BinTree;
typedef address1 ListOfNode;


/* Konstruktor */
address AlokasiTree (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika Alokasi berhasil, maka address != Nil dan Info (P) = X */

BinTree Tree (infotype Akar, BinTree L, BinTree R);
/* Menghasilkan sebuah pohon biner dari A, L dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void MakeTree (infotype Akar, BinTree L, BinTree R, BinTree *P);
/* IS : BinTree Sembarang */
/* FS : Menghasilkan sebuah BinTree */
/* Menghasilkan sebuah pohon biner dari A, L dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */

void BuildTree (BinTree *P);
/* Membentuk sebuah BinTree P dari pita karakter yang dibaca */
/* IS : Pita berisi "konstanta" pohon dalam bentuk prefix. Memori pasti cukup */
/*      Alokasi pasti berhasil */
/* FS : P dibentuk dari ekspresi dalam pita */

/**** Predikat Penting *****/
boolean IsEmpty (BinTree P);
/* Mengirimkan true jika BinTree KOSONG */

/***** Traversal *****/
void PreOrder (BinTree P);
/* Traversal PreOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara PreOrder : Akar, Kiri, Kanan */
void InOrder (BinTree P);
/* Traversal InOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara InOrder : Kiri, Akar, Kanan */
void PostOrder (BinTree P);
/* Traversal PostOrder menggunakan Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah diproses secara PostOrder :  Kiri, Kanan, Akar */

void LevelOrder (BinTree P, int maks_level);

void PrintTree (BinTree P, int h);
/* IS : P terdefinisi, h adalah jarak indentasi */
/* FS : Semua simpul P sudah ditulis dengan indentasi */

/***** Search *****/
boolean Search (BinTree P, infotype X);
/* Mengirimkan true jika ada node dari P yang bernilai X */

/***** Fungsi Lain *****/
int nbDaun (BinTree P);
/* Mengirimkan banyak daun (node) pohon biner P */

int Depth (BinTree P);
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */
/* Rekurens : 1 + maksimal (Depth (Anak Kiri), Depth  (Anak Kanan)) */

address EitherNotNil(address node1, address node2);

int Max (infotype Data1, infotype Data2);
/* Mengirimkan Nilai terbesar dari dua data */
  
/***** Operasi Lain *****/
void AddDaun (BinTree *P, infotype X, infotype Y, boolean Kiri);
/* IS : P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* FS : P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri) */
/*      atau sebagai anak Kanan X (jika NOT Kiri) */

/***** Manipulasi LIST OF NODE *****/
ListOfNode MakeListDaun (BinTree P);
/* Jika P adalah Pohon Kosong, maka menghasilkan List Kosong */
/* Jika P bukan Pohon Kosong, menghasilkan List yang elemennya adalah semua */
/*        daun pohon P, jika semua alokasi berhasil */
/*       		menghasilkan list kosong jika ada alokasi yang gagal */
ListOfNode MakeListPreOrder (BinTree P);
/* Jika P adalah Pohon Kosong, maka menghasilkan List Kosong */
/* Jika P bukan Pohon Kosong, menghasilkan List yang elemennya adalah semua */
/*        elemen pohon P dengan urutan PreOrder, jika semua alokasi berhasil */
/*       		menghasilkan list kosong jika ada alokasi yang gagal */
ListOfNode MakeListLevel (BinTree P, int N);
/* Jika P adalah Pohon Kosong, maka menghasilkan List Kosong */
/* Jika P bukan Pohon Kosong, menghasilkan List yang elemennya adalah semua */
/*        elemen pohon P yang levelnya = N, jika semua alokasi berhasil */
/*       		menghasilkan list kosong jika ada alokasi yang gagal */

address BinSearch (BinTree P, infotype X);
/* Mengirimkan alamat Node jika ada node dari P yang bernilai X */
/* Mengirimkan Nil jika tidak ditemukan */

/***** Operasi untuk Binary Search Tree *****/
void InsSearch (BinTree *P, infotype X);
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. */
/* Belum ada simpul P yang bernilai X */

void DestroyTree (BinTree *P);
/* Menghapus seluruh elemen Tree secara Rekursif */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah dihapus secara PostOrder :  Kiri, Kanan, Akar */

void DelNode (BinTree *P);
/* IS : P adalah pohon biner TIDAK kosong */
/* FS : Q berisi salinan nilai daun terkanan */

void DeAlokasiTree (address P);
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */

#endif