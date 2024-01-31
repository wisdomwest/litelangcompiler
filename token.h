#ifndef TOKEN_H
#define TOKEN_H

typedef enum
{
	SEMI,
	OPEN_PAREN,
	CLOSE_PAREN,
} TypeSeparator;

typedef enum
{
	EXIT,
} TypeKeyword;

typedef enum
{
	INT,
} TypeLiteral;

typedef struct
{
	TypeKeyword type;
} TokenKeyword;

typedef struct
{
	TypeSeparator type;
} TokenSeparator;

typedef struct
{
	TypeLiteral type;
	int value;
} TokenLiteral;

#endif
