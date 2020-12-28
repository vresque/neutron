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

#include "include/lexer.h"
#include "include/macros.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

lexer_T *initLexer(char *src)
{
    lexer_T *lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->src = src;
    lexer->src_size = strlen(src);
    lexer->i = 0;
    lexer->c = src[lexer->i];

    return lexer;
}

void lexerAdvance(lexer_T *lexer)
{
    if (lexer->i < lexer->src_size && lexer->c != '\0')
    {
        lexer->i += 1;
        lexer->c = lexer->src[lexer->i];
    }
}

char lexerPeek(lexer_T *lexer, int offset)
{
    return lexer->src[MIN(lexer->i + offset, lexer->src_size)];
}

token_T *lexerAdvanceWith(lexer_T *lexer, token_T *token)
{
    lexerAdvance(lexer);
    return token;
}

token_T *lexerAdvanceCurrent(lexer_T *lexer, int type)
{
    char *value = calloc(2, sizeof(char));
    value[0] = lexer->c;
    value[1] = '\0';

    token_T *token = initToken(value, type);
    lexerAdvance(lexer);

    return token;
}

void lexerSkipWhitespace(lexer_T *lexer)
{
    while (lexer->c == 13 || lexer->c == 10 || lexer->c == ' ' || lexer->c == '\t')
        lexerAdvance(lexer);
}

token_T *lexerParseID(lexer_T *lexer)
{

    char *value = calloc(1, sizeof(char));

    while (isalpha(lexer->c))
    {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char[]){lexer->c, 0});
        lexerAdvance(lexer);
    }

    return initToken(value, TOKEN_ID);
}

token_T *lexerParseNumber(lexer_T *lexer)
{
    char *value = calloc(1, sizeof(char));

    while (isdigit(lexer->c))
    {
        value = realloc(value, (strlen(value) + 2) * sizeof(char));
        strcat(value, (char[]){lexer->c, 0});
        lexerAdvance(lexer);
    }

    return initToken(value, TOKEN_INT);
}

token_T *lexerNextToken(lexer_T *lexer)
{
    while (lexer->c != '\0')
    {
        lexerSkipWhitespace(lexer);
        if (isalpha(lexer->c))
            return lexerAdvanceWith(lexer, lexerParseID(lexer));

        if (isdigit(lexer->c))
            return lexerAdvanceWith(lexer, lexerParseNumber(lexer));

        switch (lexer->c)
        {
        case '-':
        {
            if (lexerPeek(lexer, 1) == '>')
                return lexerAdvanceWith(lexer, lexerAdvanceWith(lexer, initToken("->", TOKEN_ARROW_RIGHT)));
            return lexerAdvanceWith(lexer, initToken("-", TOKEN_HYPHEN));
        }
        break;

            //		case 'comp': {
            //			// Component names can never be empty
            //			if (lexerPeek(lexer, 2) != ' ') return lexerAdvanceWith(lexer, lexerAdvanceWith(lexer, initToken("comp", TOKEN_COMP)));
            //		} break;

        case '=':
            return lexerAdvanceCurrent(lexer, TOKEN_EQUALS);
        //		case '::': return lexerAdvanceCurrent(lexer, TOKEN_DOUBLECOLON);
        case '(':
            return lexerAdvanceCurrent(lexer, TOKEN_LPAREN);
        case ')':
            return lexerAdvanceCurrent(lexer, TOKEN_RPAREN);
        case '{':
            return lexerAdvanceCurrent(lexer, TOKEN_LBRACE);
        case '}':
            return lexerAdvanceCurrent(lexer, TOKEN_RBRACE);
        case '[':
            return lexerAdvanceCurrent(lexer, TOKEN_LBRACE);
        case ']':
            return lexerAdvanceCurrent(lexer, TOKEN_RBRACE);
        case ':':
            return lexerAdvanceCurrent(lexer, TOKEN_COLON);
        case ',':
            return lexerAdvanceCurrent(lexer, TOKEN_COMMA);
        case '<':
            return lexerAdvanceCurrent(lexer, TOKEN_LT);
        case '>':
            return lexerAdvanceCurrent(lexer, TOKEN_GT);
        case ';':
            return lexerAdvanceCurrent(lexer, TOKEN_SEMI);
        case 'comp':
            return lexerAdvanceCurrent(lexer, TOKEN_COMP);
        case '\0':
            break;
        default:
            printf("[Lexer, Bootstrap]: Unexpected character `%c`\n", lexer->c);
            exit(1);
            break;
        }
    }

    return initToken(0, TOKEN_EOF);
}