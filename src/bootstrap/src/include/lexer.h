/*
 *   Copyright (c) 2020 Clemens Schuetz and Visionizer Technologies
 *   All rights reserved.

 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#ifndef NTN_LEXER_H
#define NTN_LEXER_H
#include "token.h"
#include <stdio.h>

typedef struct LEXER_STRUCT
{
    char *src;
    size_t src_size;
    char c;
    unsigned int i;
} lexer_T;

lexer_T *initLexer(char *src);

void lexerAdvance(lexer_T *lexer);

char lexerPeek(lexer_T *lexer, int offset);

token_T *lexerAdvanceWith(lexer_T *lexer, token_T *token);

token_T *lexerAdvanceCurrent(lexer_T *lexer, int type);

void lexerSkipWhitespace(lexer_T *lexer);

token_T *lexerParseID(lexer_T *lexer);

token_T *lexerParseNumber(lexer_T *lexer);

token_T *lexerNextToken(lexer_T *lexer);
#endif