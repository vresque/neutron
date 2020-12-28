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

#include "include/neutron.h"
#include "include/lexer.h"
#include "include/io.h"
#include "include/parser.h"
#include <stdlib.h>
#include "include/token.h"

void neutronCompile(char *src)
{
    lexer_T *lexer = initLexer(src);
    parser_T *parser = initParser(lexer);
    AST_T *root = parserParse(parser);
    printf("%p\n", root);
    token_T *tok = 0;

    // As long as token is not end of file we will compile :)
    while ((tok = lexerNextToken(lexer))->type != TOKEN_EOF)
    {
        printf("%s\n", tokenToString(tok));
    }
}

void neutronCompileFile(const char *filename)
{
    char *src = neutronReadFile(filename);
    neutronCompile(src);
    free(src);
}