#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
struct tnode *talloc(void);

char *strdup(char *);

void treeprint(struct tnode *);
int getword(char *, int);

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int main() 
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}

int getword(char *word, int lim) 
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch())) {
        ;
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

void treeprint(struct tnode *p) 
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

// left off here 142 
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup(char *s) // duplicate 'S'
{   
    char *p;

    p = (char *) malloc(strlen(s)+1); 

    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
} 