#include <stdio.h>
#include "BinSTree.h"
#include <ctype.h>
#include <string.h>

BinTree N(BinTree right, infotype root, BinTree left)
{
    return Tree(root, left, right);
}

void build_morse_code(BinTree *tree)
{
    *tree = N(
        N(
            N(
                N(
                    N(
                        NULL,
                        '_',
                        N(
                            NULL,
                            '9',
                            NULL)),
                    'o',
                    N(
                        NULL,
                        '0',
                        N(
                            NULL,
                            '8',
                            NULL))),
                'm',
                N(
                    N(
                        NULL,
                        'q',
                        NULL),
                    'g',
                    N(
                        NULL,
                        'z',
                        N(
                            NULL,
                            '7',
                            NULL)))),
            't',
            N(
                N(
                    N(
                        NULL,
                        'y',
                        NULL),
                    'k',
                    N(
                        NULL,
                        'c',
                        NULL)),
                'n',
                N(
                    N(
                        NULL,
                        'x',
                        NULL),
                    'd',
                    N(
                        NULL,
                        'b',
                        N(
                            NULL,
                            '6',
                            NULL))))

                ),
        '_',
        N(
            N(
                N(
                    N(
                        N(
                            NULL,
                            '1',
                            NULL),
                        'j',
                        NULL),
                    'w',
                    N(
                        NULL,
                        'p',
                        NULL)),
                'a',
                N(
                    N(
                        NULL,
                        '_',
                        N(
                            NULL,
                            ' ',
                            NULL)),
                    'r',
                    N(
                        NULL,
                        'l',
                        NULL))),
            'e',
            N(
                N(
                    N(
                        N(
                            NULL,
                            '2',
                            NULL),
                        '_',
                        NULL),
                    'u',
                    N(
                        NULL,
                        'f',
                        NULL)),
                'i',
                N(
                    N(
                        N(
                            NULL,
                            '3',
                            NULL),
                        'v',
                        NULL),
                    's',
                    N(
                        N(
                            NULL,
                            '4',
                            NULL),
                        'h',
                        N(
                            NULL,
                            '5',
                            NULL))))));
}

boolean ascii_to_morse_helper(BinTree t, infotype target, char code[], int depth)
{
    if (t == NULL)
    {
        return false;
    }

    if (t->info == target)
    {
        code[depth] = '\0';
        return true;
    }

    code[depth] = '.';
    if (ascii_to_morse_helper(t->left, target, code, depth + 1))
    {
        return true;
    }

    code[depth] = '-';
    if (ascii_to_morse_helper(t->right, target, code, depth + 1))
    {
        return true;
    }

    return false;
}

void ascii_to_morse(BinTree t, infotype target)
{
    char code[100];
    if (ascii_to_morse_helper(t, target, code, 0))
    {
        printf("%s", code);
        return;
    }
    printf("Unknown ascii code : %c", target);
}

char morse_to_ascii(BinTree t, char morse[])
{
    BinTree cursor = t;
    
    for (int i = 0; morse[i] != '\0' && morse[i] != '\n' ; i++)
    {
        if (morse[i] == '.')
        {
            if (cursor->left != NULL)
            {
                cursor = cursor->left;
            }
            else
            {
                printf("Unknown morse: %s", morse);
                return '\0';
            }
        }
        else if (morse[i] == '-')
        {
            if (cursor->right != NULL)
            {

                cursor = cursor->right;
            }
            else
            {
                printf("Unknown morse: %s", morse);
                return '\0';
            }
        }
        else
        {
            printf("Invalid morse sequence %c", morse[i]);
            return '\0';
        }
    }

    if (cursor->info == '_')
    {
        printf("Unknown morse: %s", morse);
        return '\0';
    }

    return cursor->info;
}

int main()
{
    BinTree tree;
    char input[100];
    char *morse;

    build_morse_code(&tree);
    printf("Print secara inorder\n");
    InOrder(tree);
    printf("\n");

    printf("String yang akan dikonversi ke kode morse: ");
    fgets(input, 100, stdin);

    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++)
    {
        ascii_to_morse(tree, tolower(input[i]));
        printf(" ");
    }
    printf("\n");

    printf("String morse yang akan dikonversi ke kalimat: ");
    fgets(input, 100, stdin);

    morse = strtok(input, " ");
    while(morse != NULL) {
        char ascii = morse_to_ascii(tree, morse);
        printf("%c", ascii);
        morse = strtok(NULL, " ");
    }
}