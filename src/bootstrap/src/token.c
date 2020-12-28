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

#include "include/token.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

token_T *initToken(char *value, int type)
{
    token_T *token = calloc(1, sizeof(struct TOKEN_STRUCT));
    token->value = value;
    token->type = type;

    return token;
}

const char *tokenTypeToString(int type)
{
    switch (type)
    {
    case TOKEN_ID:
        return "TOKEN_ID";
    case TOKEN_DOUBLECOLON:
        return "TOKEN_DOUBLECOLON";
    case TOKEN_COLON:
        return "TOKEN_COLON";
    case TOKEN_COMMA:
        return "TOKEN_COMMA";
    case TOKEN_EQUALS:
        return "TOKEN_EQUALS";
    case TOKEN_HYPHEN:
        return "TOKEN_HYPHEN";
    case TOKEN_LT:
        return "TOKEN_LT";
    case TOKEN_GT:
        return "TOKEN_GT";
    case TOKEN_ARROW_RIGHT:
        return "TOKEN_ARROW_RIGHT";
    case TOKEN_RBRACE:
        return "TOKEN_RBRACE";
    case TOKEN_LBRACE:
        return "TOKEN_LBRACE";
    case TOKEN_LPAREN:
        return "TOKEN_LPAREN";
    case TOKEN_RPAREN:
        return "TOKEN_RPAREN";
    case TOKEN_COMP:
        return "TOKEN_COMP";
    case TOKEN_INT:
        return "TOKEN_INT";
    case TOKEN_SEMI:
        return "TOKEN_SEMI";
    case TOKEN_EOF:
        return "TOKEN_EOF";
    }

    return "not_stringable";
}

char *tokenToString(token_T *token)
{
    const char *typeString = tokenTypeToString(token->type);
    const char *template = "<type='%s', intType='%d', value='%s'>";

    char *string = calloc(strlen(typeString) + strlen(template) + 8, sizeof(char));
    sprintf(string, template, typeString, token->type, token->value);
    return string;
}
