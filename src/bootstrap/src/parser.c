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

#include "include/parser.h"
#include "include/lexer.h"
#include <stdio.h>
#include <stdlib.h>

parser_T *initParser(lexer_T *lexer)
{
	parser_T *parser = calloc(1, sizeof(struct PARSER_STRUCT));
	parser->lexer = lexer;
	parser->token = lexerNextToken(lexer);

	return parser;
}

token_T *parserEat(parser_T *parser, int type)
{
	if (parser->token->type != type)
	{
		printf("[Parser, Bootstrap] Syntax Error. Unexpected token: '%s', was expecting '%s'. Are you sure that you did not mispell anything? \n", tokenToString(parser->token), tokenTypeToString(type));
		exit(1);
	}

	parser->token = lexerNextToken(parser->lexer);
	return parser->token;
}

AST_T *parserParse(parser_T *parser)
{
	return initAST(AST_NOOP);
}

AST_T *parserParseCompound(parser_T *parser)
{
	// Spelling mistake
	AST_T *compound = initAST(AST_COMPUND);
	while (parser->token->type != TOKEN_EOF)
	{
		/* AST_T* child =*/parserParse(parser);
	}
	return initAST(AST_NOOP);
}