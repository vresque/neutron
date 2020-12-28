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

#ifndef NTN_TOKEN_H
#define NTN_TOKEN_H
typedef struct TOKEN_STRUCT
{
    char *value;
    enum
    {
        TOKEN_ID,          // ?,
        TOKEN_DOUBLECOLON, // ::,
        TOKEN_COLON,       // :,
        TOKEN_COMMA,       // ,,
        TOKEN_EQUALS,      // =,
        TOKEN_HYPHEN,      // -,
        TOKEN_LT,          // <,
        TOKEN_GT,          // >,
        TOKEN_ARROW_RIGHT, // ->,
        TOKEN_RBRACE,      // },
        TOKEN_LBRACE,      // {,
        TOKEN_LPAREN,      // ),
        TOKEN_RPAREN,      // (,
        TOKEN_COMP,        // comp (function),
        TOKEN_INT,         // int
        TOKEN_SEMI,        // ;
        TOKEN_EOF,         // End of file,
    } type;
} token_T;

token_T *initToken(char *value, int type);

const char *tokenTypeToString(int type);

char *tokenToString(token_T *token);

#endif