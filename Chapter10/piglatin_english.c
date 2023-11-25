/*
 * File: piglatin_english.c
 * ------------------------
 *  This program uses worddict.h to check every
 *  word in English's pig-latin-converted word
 *  is also an English word.
 *  worddict.h doesn't exist so it's conceptual
 *  programming.
 */

#include "genlib.h"
#include "strlib.h"
#include "worddict.h"

/* Function prototypes */

static void WordPrint(void);
static string TranslateWord(string word);
static int FindFirstVowel(string word);
static bool IsVowel(char ch);

/* Main program */

int main(void)
{
    printf("This program uses \"worddict.h\" to check every\n");
    printf("word in English's pig-latin-converted word\n");
    printf("is also an English word.\n");

    WordPrint();
}

/*
 * Function: WordPrint
 * Usage: WordPrint();
 * -------------------
 *  This function checks every word in English.
 *  If the word's pig-latin-converted word is also
 *  in English dictionary, it prints out the word.
 */

static void WordPrint(void)
{
    string word;

    InitDictionary();
    while(!AtEndOfDictionary())
    {
        word = GetNextDictionaryEntry();
        if(IsEnglishWord(TranslateWord(word))) printf("%s\n", word);
    }
}

/*
 * Function: TranslateWord
 * Usage: word = TranslateWord(word)
 * ---------------------------------
 *  This function translates a word from English to Pig Latin
 *  and returns the translated word.
 */

static string TranslateWord(string word)
{
    int vp;
    string head, tail;

    vp = FindFirstVowel(word);
    if(vp == -1)
    {
        return (word);
    }
    else if(vp == 0)
    {
        return (Concat(word, "way"));
    }
    else
    {
        head = SubString(word, 0, vp - 1);
        tail = SubString(word, vp, StringLength(word) - 1);
        if(isupper(head[0]))
        {
            tail[0] = toupper(tail[0]);
            head[0] = tolower(head[0]);
        }
        return (Concat(tail, Concat(head, "ay")));
    }
}

/*
 * Function: FindFirstVowel
 * Usage: k = FindFirstVowel(word);
 * --------------------------------
 *  FindFirstVowel returns the index position of the first vowel
 *  in word. If word does not contain a vowel, FindFirstVowel
 *  returns -1.
 */

static int FindFirstVowel(string word)
{
    int i;

    for(i = 0; i < StringLength(word); ++i)
    {
        if(IsVowel(IthChar(word, i))) return (i);
    }
    return (-1);
}

/*
 * Function: IsVowel
 * Usage: if(IsVowel(ch))...
 * -------------------------
 *  IsVowel returns TRUE if ch is a vowel. This function
 *  recognizes vowels in either upper or lower case.
 */

static bool IsVowel(char ch)
{
    switch(tolower(ch))
    {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return (TRUE);
        default:
            return (FALSE);
    }
}

